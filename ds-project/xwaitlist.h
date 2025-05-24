#pragma once
#include "euwaitlist.h"
class xwaitlist: public euwaitlist
{
	void cancel(int Pcancel, patients*p)
	{
		p = nullptr;
		if (this->isEmpty())
		{
			return;
		}
		int prob = rand() % 101; //prob is random number that will be compared to Pcancel
		if (prob >= Pcancel)
		{
			return;
		}
		int count = this->getcount();
		int random = rand() % count;
		linkedqueue<patients*> temp;
		patients* currentP = nullptr;
		patients* selectedP = nullptr;

		for (int i = 0; i < count; i++)
		{
			this->dequeue(currentP);
			if (i == random)
			{
				if (currentP->getCurrentTreatment())
				{
					selectedP = currentP;
				}
				else
				{
					temp.enqueue(currentP);
				}
			}
			else 
			{
				temp.enqueue(currentP);
			}
		}
		while (!temp.isEmpty())
		{
			temp.dequeue(currentP);
			this->enqueue(currentP);
		}
		if (selectedP != nullptr)
		{
			p = selectedP;
		}
		
	}

};

