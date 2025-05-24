#include "patients.h"
#include"treatment.h"
#include<iostream>
using namespace std;

ostream& operator<<(ostream& os, const patients& p) {
    os << ", Status: " << p.getpatientstatus()
        << "Patient ID: " << p.getpt()
        << ", Arrival Time: " << p.getvt()
        << ", Assignment Time: " << p.getst();
        //<< ", Finish Time: " << p.getft();
        
    return os;
}

int patients::getNextTreatmentDuration()
{
    treatment* next = nullptr;
    if (tlist.peek(next)) {
        int treatmentDuration = next->GetDuration(); // Rename variable for clarity
        setCurrentTreatmentDuration(treatmentDuration); // Set the member variable
        return treatmentDuration; // Return the duration
    }
    return 0;
}
