#include "euwaitlist.h"
#include"treatment.h"

int euwaitlist::calctreatmentlatency()
{

    linkedqueue<patients*> tempQueue;
    patients* currentPatient;
    int totalLatency = 0;
    int patientCount = 0;

    // Dequeue all patients, calculate latency, and store in tempQueue
    while (!isEmpty()) {
        dequeue(currentPatient);
        if (!currentPatient->getCurrentTreatment())
        {
            tempQueue.enqueue(currentPatient);
        }
        else
        {
            totalLatency += currentPatient->getCurrentTreatment()->GetDuration();
            tempQueue.enqueue(currentPatient);
            patientCount++;
        }
        // Calculate latency
        //int latency = currentPatient->getst() - currentPatient->getvt();
        //totalLatency += latency;


    }

    // Move all patients back to the original queue
    while (!tempQueue.isEmpty()) {
        tempQueue.dequeue(currentPatient);
        this->enqueue(currentPatient);
    }
    return totalLatency;

    // average latency 
    if (patientCount > 0) {
        double avgLatency = (totalLatency) / patientCount;
        /*cout << "Average Treatment Latency: " << avgLatency << " units." << endl;*/
    }
}

void euwaitlist::insertsorted(patients* p)
{

    linkedqueue<patients*> tempQueue;
    patients* temp;
    bool inserted = false;

    // Step 1: Move from current queue to tempQueue with sorted insertion
    while (!this->isEmpty()) {
        this->dequeue(temp);

        // Check where to insert the newPatient
        if (!inserted && p->getst() < temp->getst()) {
            tempQueue.enqueue(p);
            inserted = true;
        }

        tempQueue.enqueue(temp);
    }


    if (!inserted) {
        tempQueue.enqueue(p);
    }

    //move back to original queue
    while (!tempQueue.isEmpty()) {
        tempQueue.dequeue(temp);
        this->enqueue(temp);
    }
}
