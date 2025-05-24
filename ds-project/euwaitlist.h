#pragma once
#include "patients.h"
#include "linkedqueue.h"
class treatment;
class euwaitlist: public linkedqueue<patients*>
{
public:
    void insertsorted(patients* p);
	
	
    int calctreatmentlatency();
    
};

