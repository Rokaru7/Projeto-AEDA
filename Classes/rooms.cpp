
#include <iostream>
#include "rooms.h"

Room::Room(string t, int f, int n, int p, int c) {
    type = t; number = n; free = true; floor = f; price = p; capacity = c;
}

string Room::getType() {
    return type;
}

int Room::getNumber() {
    return number;
}

bool Room::getFree() {
    return free;
}

bool Room::enter() {
    if (free){
        free = false;
        return true;
    }
    else {
        return false;
    }
}

bool Room::leave() {
    if (!free){
        free = true;
        return true;
    }
    else {
        return false;
    }
}

int Room::getFloor() {
    return floor;
}

int Room::getPrice() {
    return price;
}

int Room::getCapacity() {
    return capacity;
}

void Room::info() const {
    return Room::info(cout);
}

void Room::info(ostream &o) const {
    o << "Type: " << type << "  Floor: " << floor << "  Number: " << number << "  Capacity: " << capacity << "  Price: " << price;
    o << endl;
}


