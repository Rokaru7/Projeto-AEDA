
#include "clients.h"
#include <iostream>
#include <string>

using namespace std;

Clients::Clients(string n, int N, int h, int R) {
    name = n;
    NIF = N;
    history = h;
    reservations = R;
}
string Clients::getName() const
{ return name; }

int Clients::getNIF() const
{ return NIF; }

int Clients::getHistory() const
{ return history; }

vector<Room *> Clients::getRooms() const
{return rooms; };

int Clients::getReservation() const
{ return reservations; }

void Clients::info(ostream &o) {
    o << "Name: " << name << "  NIF: " << NIF << "  Previous reservations: " << history;
    o << " Number of guests: " << reservations << "  Number(s) of the room(s): " << endl;
    inforooms(cout);
    o << endl;
}

void Clients::info(){
    return Clients::info(cout);
}

void Clients::inforooms(ostream &o) {
    if (rooms.empty()) o << "No rooms" << endl;
    else {
        for (int i = 0; i != rooms.size(); i++){
            o << "floor: " << rooms[i]->getFloor() << " Number: " << rooms[i]->getNumber() << endl;
        }
    }
}

void Clients::addRoom(Room *r) {
    rooms.push_back(r);
}

/*if reservations<= //lugares disponiveis
    lugares disponiveis - reservations*/