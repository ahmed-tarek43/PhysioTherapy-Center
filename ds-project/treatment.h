#pragma once
#include "schedular.h"
#include "resources.h"
//#include "patients.h"
//class resources;
class schedular;
class patients;
class treatment
{
	
protected:
	int duration;
	int assigntime;
	resources* assignedresource;
public:
	treatment(int dur,int at) : duration(dur), assigntime(-1) {
		if (assignedresource == nullptr)
			return;
	}
	
	virtual char GetType(patients* patienttype)=0 ;
	virtual bool CanAssign(schedular* schedular) =0;
	virtual void MovetoWait(schedular*schedular,patients* patients)=0 ;
	virtual int GetDuration();
	

	//virtual ~treatment() {}
};
