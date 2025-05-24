#pragma once
#include <fstream>
#include "patients.h"
#include "treatment.h"
#include "schedular.h"
#include "edevice.h"
#include "udevices.h"
#include "xdevices.h"



using namespace std;

class UI {
public:
    void infile(const string& filename, schedular& sch) {
        ifstream infile(filename);

        int numPatients;
        infile >> numPatients;

        for (int i = 0; i < numPatients; ++i) {
            string status;
            int pt, vt, nt;

            infile >> status >> pt >> vt >> nt;

            patients* p = new patients(pt, vt, nt, status);

            for (int z = 0; z < nt; z++)
            {
                char type;
                int duration;
               /* while (infile >> type) {
                    if (!(infile >> duration)) {
                        break;
                    }*/
                infile >> type >> duration;

                    treatment* t = nullptr;
                    if (type == 'U')
                    {
                        t = new udevices(duration, 0);
                    }
                    else if (type == 'E')
                    {
                        t= new edevice(duration, 0);
                    }
                    else if (type == 'X')
                    {
                        t=new xdevices(duration, 0);
                    }
                    if (t)
                    {
                        p->addtreatment(t);
                    }
                
            }
            // Add patient directly to the scheduler
            sch.addPatient(p);
        }

        infile.close();
    }
};