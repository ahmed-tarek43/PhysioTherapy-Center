#include "xdevices.h"

char xdevices::GetType(patients* patienttype)
{
    return 'X';
}

void xdevices::MovetoWait(schedular* scheduler, patients* patient)
{
    scheduler->addtowait(patient);
}
