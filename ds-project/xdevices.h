#pragma once
#include "treatment.h"
class xdevices : public treatment
{

protected:
	int duration;
	int assigntime;
	resources* assignedresource;
public:
	xdevices(int dur,int at ) : treatment  (dur,at){}
	virtual char GetType(patients* patienttype) ;
	virtual bool CanAssign(schedular* scheduler) 
	{
		return true;
	}
	virtual void MovetoWait(schedular* scheduler, patients* patient);

};

