#pragma once

#include"priqueue.h"
#include"patients.h"
#include <iostream>
using namespace std;

class earlyplist : public priQueue<patients*>
{

public:
	void reschedule(patients* p,int presc)
	{
		if (this->isEmpty())
		{
			return;
		}
		int prob = rand() % 101;
		if (prob >= presc)
		{
			return;
		}
		int count = this->getcount();
		int random = rand() % count;
		priQueue<patients*> temp;
		patients* currentP = nullptr;
		patients* selectedP = nullptr;
		int pri;

		for (int i = 0; i < count; i++)
		{
			this->dequeue(currentP, pri);
			if (i == random)
			{
				int oldPT = currentP->getpt();
				int newPT = oldPT + (rand() % 5);
				currentP->setpt(newPT);
				selectedP = currentP;
			}
			else
			{
				temp.enqueue(currentP, currentP->getpt());
			}
		}
		while (!temp.isEmpty())
		{
			temp.dequeue(currentP, pri);
			this->enqueue(currentP, currentP->getpt());
		}
		//if (selectedP)
		//{
		//	int arrived = selectedP->getvt();
		//	int appointed = selectedP->getpt();
		//	if (arrived > appointed)
		//	{
		//		//Lpatients.enqueue(selectedP,pri);
		//		//NumLate++;
		//	}
		//	else if (arrived < appointed)
		//	{
		//		this->enqueue(selectedP, selectedP->getpt());
		//	}
		//	else
		//	{
		//		treatment* nextTreatment = p->gettreatmenttype();
		//		if (nextTreatment != nullptr)
		//		{
		//			/*char type = nextTreatment->GetType(p);
		//			if (type == 'X')
		//			{
		//				Xwaitingpatients.enqueue(p);
		//				NumXwaiting++;
		//			}
		//			else if (type == 'E')
		//			{
		//				Uwaitingpatients.enqueue(p);
		//				NumEwaiting++;
		//			}
		//			else if (type == 'U')
		//			{
		//				Uwaitingpatients.enqueue(p);
		//				NumUwaiting++;
		//			}*/
		//		}
		//	}
		

	}
	
};

