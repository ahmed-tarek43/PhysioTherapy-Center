#pragma once
#include "linkedqueue.h"
#include "priqueue.h"
#include "euwaitlist.h"
#include "xwaitlist.h"
#include"arraystack.h"
#include "resources.h"
#include "earlyplist.h"
class patients;
class treatment;



class schedular
{ 
private:
	linkedqueue<patients*> Apatients;
	earlyplist Epatients;
	priQueue<patients*> Lpatients;
	euwaitlist Uwaitingpatients;
	euwaitlist Ewaitingpatients;
	xwaitlist Xwaitingpatients;
	linkedqueue<resources*> Edevices;
	linkedqueue<resources*> Udevices;
	linkedqueue<resources*> Xrooms;
	priQueue<patients*> Intreatment;
	linkedqueue<treatment*> Rtreatments;
	ArrayStack<patients*> Fpatients;
	int timestep;
	int NumPatients;
	int NumLate;
	int NumEarly;
	int NumEwaiting;
	int NumUwaiting;
	int NumXwaiting;
public:
	schedular();
	
	void increasets();
	void addtowait(patients* p);
	void UpdateQueues();
	void updateLateEarly();
	bool simulate();
	void print() const;
	void RPHandling(patients*p);
	
	const linkedqueue<patients*>& getApatients()const
	{
		return Apatients;
	}
	const earlyplist& getEpatients()const 
	{
		return Epatients;
	}
	const priQueue<patients*>& getLpatients() const 
	{
		return Lpatients;
	}
	const euwaitlist& getUwaitingpatients()const
	{
		return Uwaitingpatients;
	}
	const euwaitlist& getEwaitingpatients()const
	{
		return Ewaitingpatients;
	}
	const xwaitlist& getXwaitingpatients()const
	{
		return Xwaitingpatients;
	}
	const ArrayStack<patients*>& getFpatients() const
	{
		return Fpatients;
	}
	const linkedqueue<resources*>& getEdevices() const { return Edevices; }
	const linkedqueue<resources*>& getUdevices() const { return Udevices; }
	const linkedqueue<resources*>& getXrooms() const { return Xrooms; }
	const priQueue<patients*>& getIntreatment() const { return Intreatment; }
	

	void addPatient(patients* p)
	{
		Apatients.enqueue(p);
		NumPatients++;
	}
	


	

};

