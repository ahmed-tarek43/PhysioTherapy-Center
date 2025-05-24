#include <iostream>
#include "schedular.h"
#include "UI.h"
#include "Treatment.h"
#include "edevice.h"
#include "xdevices.h"
#include <conio.h>  // for _getch()
#include <stdlib.h> // for system()
/////////////////////////////////////////////////////////////////////////////////////////////////
//TO BE DONE: X-Latency , INCREMENT TS() removed form update All patiend(Shoof hatet7at feen) ,
//ADDtowait3 El Dequeue lazm yetshal
/////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
int main()
{
	// Common initialization code
	//ETherapy* E = new ETherapy(1, 2);
	//XTherapy* X = new XTherapy(2, 3);

	//UTherapy* U = new UTherapy(3, 4);
	//Resource* Eresource = new Resource(1, 'E');
	//Resource* Xresource = new Resource(1, 'X');
	//Xresource->SetCapaicty(2);
	//Resource* Uresource = new Resource(1, 'U');

	schedular TEST;
	//TEST.AddEResourcetest(Eresource);
	// Patient p3 related code
	patients* p3 = new patients(4,1,1,"RP");
	treatment* X = new xdevices(1, 'X');
	p3->addtreatment(X);
	TEST.addPatient(p3);

	//// Patient p4 related code
	//Patient* p4 = new Patient("NP", 5, 4, 1, 123);
	//p4->AddTreatment(E);
	//TEST.AddPatient(p4);

	//// Patient p5 related code
	//Patient* p5 = new Patient("NP", 5, 5, 1, 123);
	//p5->AddTreatment(U);
	//TEST.AddPatient(p5);

	//// Patient p6 related code
	//Patient* p6 = new Patient("NP", 5, 6, 1, 123);
	//p6->AddTreatment(X);
	//TEST.AddPatient(p6);



	for (int i = 0; i < 20; i++)
	{

		patients* temp = nullptr;
		system("cls");
		cout << "Press any key" << endl;
		
		//TEST.AssignX(temp);
		//TEST.();
		TEST.print();
		
		TEST.increasets();
		TEST.UpdateQueues();
		TEST.updateLateEarly();
		if (_getch() == 'q') break;
	}
	
}
//El treatment beyetemelha dequeu