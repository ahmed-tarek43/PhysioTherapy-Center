#pragma once
#include "treatment.h"

class edevice : public treatment
{
protected:
	int duration;
	int assigntime;
	resources* assignedresource;
public:
	edevice(int dur, int at) : treatment(dur, at) {}
	virtual char GetType(patients* patienttype);
	virtual bool CanAssign(schedular* scheduler);
	virtual void MovetoWait(schedular* scheduler, patients* patient);

};

