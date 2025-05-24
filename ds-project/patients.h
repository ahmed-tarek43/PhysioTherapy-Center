#pragma once
#include "linkedqueue.h"


#include <iostream>
using namespace std;
class treatment;
class patients
{
protected:
    linkedqueue <treatment*> tlist;
    int id;   // Unique patient ID
    //  char type; // 'e' for early, 'l'for late, 'o' for ordinary
    int pt;  // appointemnt time
    int vt;    // Arrival time of the patient
    int st;    // assignment time
    int tw; // total waiting time
    int tt; // total treatement time
    int ft; // finsih time
    int nt; //no. of treatments
    string patientstatus; // n: normal patient, r: recovering patinet
    int penalty;
    int currentTreatmentDuration;


public:
    patients(int pt, int vt, int nt, string patientstatus)
    {
       
        // type='o';
       this->currentTreatmentDuration = 0;
       this-> pt = pt;
       this->vt = vt;
       this->st = pt + penalty;
       this->tw = 0;
       this->tt = 0;
       this->ft = vt + tw + tt;
       this->nt = nt;
       this->patientstatus = patientstatus;
        if (vt > pt)
            penalty = (vt - pt) / 2;
        else
            penalty = 0;
        
    }
 
    int getst()const { return st; }
    int getvt()const { return vt; }
    int getpt()const { return pt; }
    int getft()const { return ft; }
    void setpt(int s) { pt = s; }
    void setvt(int v) { vt = v; }
    string getpatientstatus()const { return patientstatus; }
    //bool LastTreatmentisx() const {
    //    if (!tlist.isEmpty()) {
    //        treatment* lastTreatment;
    //        tlist.peek(lastTreatment);  // Get the first element
    //          
    //        }
    //    return false;
    //    }
    //
    treatment* getCurrentTreatment() const {
        treatment* t = nullptr;
        tlist.peek(t);
        return t;
    }
    void addtreatment(treatment*t)
    {

        tlist.enqueue(t);
    }
    treatment* gettreatmenttype()
    {
        if (tlist.isEmpty())
        {
           
            return 0;
        }
        else
        {
            treatment* type=nullptr;
            tlist.dequeue(type);
            return type;
        }
    }
    int getNextTreatmentDuration();
    int getFT() const { return ft; }
    void setFT(int finishTime) { ft = finishTime; }

    void setCurrentTreatmentDuration(int duration) { currentTreatmentDuration = duration; }
    int getCurrentTreatmentDuration() const { return currentTreatmentDuration; }
    
    friend ostream& operator<<(ostream& os, const patients& p);
        
    
};


