#include "schedular.h"
#include"treatment.h"
#include"xwaitlist.h"
#include"euwaitlist.h"
#include<iostream>
using namespace std;


schedular::schedular()
{
	timestep = 0;
	NumPatients = 0;
	NumLate = 0;
	NumEarly = 0;
	NumEwaiting = 0;
	NumUwaiting = 0;
	NumXwaiting = 0;

}

void schedular::increasets()
{
	timestep++;
	
	
}

void schedular::addtowait(patients* p)
{
	char P =p->gettreatmenttype()->GetType(p);
	if ( P == 'X')
	{
		Xwaitingpatients.enqueue(p);
		return;
	}
	if ( P=='U')
	{
		Uwaitingpatients.enqueue(p);
		return;
	}
	if ( P=='E')
	{
		Ewaitingpatients.enqueue(p);
		return;
	}
	else {
		cout << "Warning: Patient has no treatment assigned!" << endl;
	}
}
void schedular::RPHandling(patients* p)
{
	euwaitlist* calcTL = nullptr;
	if (p->getpatientstatus() == "RP")
	{
		int TLu = calcTL->calctreatmentlatency();
		int TLe = calcTL->calctreatmentlatency();
		int TLx = calcTL->calctreatmentlatency();
		int min = std::min({ TLu,TLe,TLx });
		if (min == TLu)
		{
			Uwaitingpatients.enqueue(p);
		}
		else if (min == TLe)
		{
			Ewaitingpatients.enqueue(p);
		}
		else if (min == TLx)
		{
			Xwaitingpatients.enqueue(p);
		}

	}
	
	
}
void schedular::UpdateQueues() 
{
	for (int i=0 ; i<NumPatients ;i++)
	{
		if (!Apatients.isEmpty())
		{
			patients* p = nullptr;
			Apatients.dequeue(p);
			
				if (p->getvt() == timestep)
				{

					if (p->getvt() < p->getpt() )
					{
						Epatients.enqueue(p, p->getst());
						NumEarly++;
					}
					else if (p->getvt() > p->getpt())
					{
						Lpatients.enqueue(p, p->getst());
						NumLate++;
					}
					else
					{
						treatment* nextTreatment = p->gettreatmenttype();
						if (nextTreatment != nullptr)
						{
							char type = nextTreatment->GetType(p);
							if (type == 'X')
							{
								Xwaitingpatients.enqueue(p);
								NumXwaiting++;
							}
							else if (type == 'E')
							{
								Uwaitingpatients.enqueue(p);
								NumEwaiting++;
							}
							else if (type == 'U')
							{
								Uwaitingpatients.enqueue(p);
								NumUwaiting++;
							}

						}

					}
				}
			
		}
		 
	}
	

}
void schedular::updateLateEarly()
{
	for (int i = 0; i < NumEarly; i++)
	{
		if (!Epatients.isEmpty())
		{
			patients* pE = nullptr;
			int priE;
			Epatients.peek(pE, priE);
			if (timestep == pE->getst())
			{
				Epatients.dequeue(pE, priE);
				treatment* nextT = pE->gettreatmenttype();
				if (nextT != nullptr)
				{
					char type = nextT->GetType(pE);
					if (type == 'X')
					{
						Xwaitingpatients.enqueue(pE);
						NumXwaiting++;
					}
					else if (type == 'E')
					{
						Uwaitingpatients.enqueue(pE);
						NumEwaiting++;
					}
					else if (type == 'U')
					{
						Uwaitingpatients.enqueue(pE);
						NumUwaiting++;
					}
				}
			}
		} 
		for (int i=0;i<NumLate;i++)
		{ 
			if (!Lpatients.isEmpty())
			{
				patients* pL = nullptr;
				int priL;
				Lpatients.dequeue(pL, priL);
				if (timestep == pL->getst())
				{
					treatment* nextT = pL->gettreatmenttype();
					if (nextT != nullptr)
					{
						char type = nextT->GetType(pL);
						if (type == 'X')
						{
							Xwaitingpatients.enqueue(pL);
							NumXwaiting++;
						}
						else if (type == 'E')
						{
							Uwaitingpatients.enqueue(pL);
							NumEwaiting++;
						}
						else if (type == 'U')
						{
							Uwaitingpatients.enqueue(pL);
							NumUwaiting++;
						}
					}
				}
			}

		}
		
    }

}


bool schedular::simulate()
{
		patients* p;
		while (Apatients.peek(p))
		{
			Apatients.dequeue(p);
			if (p->getvt() < p->getpt())
				Epatients.enqueue(p, p->getst());
			else if (p->getvt() > p->getpt())
				Lpatients.enqueue(p, p->getst());
			else
			{
				int N = rand() % 100;
				//int N = 2;
				if (N < 33)
					Ewaitingpatients.enqueue(p);
				else if (N < 66)
					Uwaitingpatients.enqueue(p);
				else
					Xwaitingpatients.enqueue(p);
			}
		}
		
			int X = rand() % 80;
			{
			//int X = 2;
			if (X < 10) {
				// Move from Early to RandomWaiting
				patients* early = nullptr;
				int epr;
				if (Epatients.dequeue(early, epr))
				{
					int N = rand() % 100;
					if (N < 33) Ewaitingpatients.enqueue(early);
					else if (N < 66) Uwaitingpatients.enqueue(early);
					else Xwaitingpatients.enqueue(early);
				}
			}
			else if (10 <= X < 20)
			{
				// Move from Late to RandomWaiting with penalty
				patients* late;
				int lpr;
				if (Lpatients.dequeue(late, lpr))
				{
					late->getst();
					int N = rand() % 100;
					if (N < 33) Ewaitingpatients.enqueue(late);
					else if (N < 66) Uwaitingpatients.enqueue(late);
					else Xwaitingpatients.enqueue(late);
				}
			}
		  }
			 if (20 <= X < 40)
			{
				patients* random=nullptr;
				int N = rand() % 100;
				//for (int i = 0; i < 2; i++)
				{
					if (!Ewaitingpatients.isEmpty()) {
						if (N < 33) 
							Ewaitingpatients.dequeue(random);
						
					}
					if (!Uwaitingpatients.isEmpty()) {
					 if (N < 66) 
						 Uwaitingpatients.dequeue(random);
					 
					}
					if (!Xwaitingpatients.isEmpty()) {
					  if 
						  (Xwaitingpatients.dequeue(random));
					  
					}
					if (random) {
						Intreatment.enqueue(random, random->getft());
					}
				}

			  if (50 <= X < 60)
			 {
				 // Move from InTreatment to Finish
				 patients* treat2 = nullptr;
				 int tpr2 = 0;
				 if (!Intreatment.isEmpty())
				 {
					 Intreatment.dequeue(treat2, tpr2);

					 Fpatients.push(treat2);
				 }
			 }
			}
			else if (40 <= X < 50)
			{
				// Move from InTreatment to RandomWaiting
				patients* treat;
				int tpr;
				if (Intreatment.dequeue(treat, tpr))
				{
					int N = rand() % 100;
					if (!Ewaitingpatients.isEmpty())
					{
						if (N < 33) Ewaitingpatients.enqueue(treat);
					}
					if (!Uwaitingpatients.isEmpty()) {
					 if (N < 66) Uwaitingpatients.enqueue(treat);
					}
					if (!Xwaitingpatients.isEmpty()) {
					 Xwaitingpatients.enqueue(treat); 
					}
				}
			}
			else if (50 <= X < 60)
			{
				// Move from InTreatment to Finish
				patients* treat2=nullptr;
				int tpr2=0;
				if (!Intreatment.isEmpty()) 
				{
					Intreatment.dequeue(treat2, tpr2);
			
					Fpatients.push(treat2);
				}
			}
			else if (60 <= X < 70)
			{
				// Cancel: move from XWaiting to Finish
				patients* p2;
				if (!Xwaitingpatients.isEmpty())
				{
					Xwaitingpatients.dequeue(p2);
					Fpatients.push(p2);
				}
			}
			else if (70 <= X < 80)
			{
				// Reschedule from Early
				patients* early2 = nullptr;
				int epr2;
				int r = rand() % 100;
				Epatients.reschedule(early2, r);
				if (!Epatients.isEmpty())
				{
					Epatients.dequeue(early2, epr2);
					int N = rand() % 100;
					if (N < 33) Ewaitingpatients.enqueue(early2);
					else if (N < 66) Uwaitingpatients.enqueue(early2);
					else Xwaitingpatients.enqueue(early2);

				}
				
			}

		
	
	return true;
}
void schedular::print() const { 
	cout << "***** Current Time Step *****"<<timestep<<endl;
	
	cout << "---- All Patients ----\n";
	Apatients.print();
	cout << "---- Early Patients ----\n";
	Epatients.print();
	cout << "\n---- Late Patients ----\n";
	Lpatients.print();
	cout << "\n---- U Waiting Patients ----\n";
	Uwaitingpatients.print();
	cout << "\n---- X Waiting Patients ----\n";
	Xwaitingpatients.print();
	cout << "\n---- E Waiting Patients ----\n";
	Ewaitingpatients.print();
	cout << "\n---- In Treatment Patients ----\n";
	Intreatment.print();
	cout << "\n---- Finished Patients ----\n";
	Fpatients.print();
}
//int schedular::getCount() const {
	//return NumPatients;




	

