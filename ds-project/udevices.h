#pragma once
#include "treatment.h"
class udevices : public treatment
{
protected:
	int duration;
	int assigntime;
	resources* assignedresource;
public:
	udevices(int dur , int at) : treatment(dur,at) {}
	virtual char GetType(patients* patienttype) ;
	virtual bool CanAssign(schedular* scheduler) ;
	virtual void MovetoWait(schedular* scheduler, patients* patient) ;

};

