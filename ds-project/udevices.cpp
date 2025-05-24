#include "udevices.h"

char udevices::GetType(patients* patienttype)
{
    return 'U';
}

bool udevices::CanAssign(schedular* scheduler)
{
    return false;
}

void udevices::MovetoWait(schedular* scheduler, patients* patient)
{
    scheduler->addtowait(patient);
}
