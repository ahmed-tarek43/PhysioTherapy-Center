#include<iostream> 
#pragma once
class resources
{
private:
    char rtype;
    int rid;
    int capacity; // For X-rooms
    int currentOccupancy; // Current patients in the room

public:
    // Constructor (for X-rooms)
    resources(int id, char t, int cap)
        : rid(id), rtype(t), capacity(cap), currentOccupancy(0) {
    }

    // Constructor for E/U devices (capacity = 1)
    resources(int id, char t)
        : rid(id), rtype(t), capacity(1), currentOccupancy(0) {
    }

    // Getters
    char getRType() const { return rtype; } // Corrected to getRType()
    int getId() const { return rid; }
    int getCapacity() const { return capacity; }
    int getCurrentOccupancy() const { return currentOccupancy; }

    // Setters
    void setCurrentOccupancy(int occ) {
        currentOccupancy = (occ > capacity) ? capacity : occ;
    }
    void incrementOccupancy() {
        if (currentOccupancy < capacity) currentOccupancy++;
    }
    void decrementOccupancy() {
        if (currentOccupancy > 0) currentOccupancy--;
    }
    ~resources() {}
};

