#include "edevice.h"

char edevice::GetType(patients* patienttype)
{
    return 'E';
}

bool edevice::CanAssign(schedular* scheduler)
{
    return false;
}


void edevice::MovetoWait(schedular* scheduler, patients* patient)
{
    scheduler->addtowait(patient);
        
}
