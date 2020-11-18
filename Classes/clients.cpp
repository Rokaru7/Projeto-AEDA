
#include "clients.h"
#include <iostream>
#include <string>

using namespace std;

Clients::Clients(string n, int N, int h, int r, int R) {
    name = n;
    NIF = N;
    history = h;
    room = r;
    reservations = R;
}
string Clients::getName() const
{ return name; }

int Clients::getNIF() const
{ return NIF; }

int Clients::getHistory() const
{ return history; }

int Clients::getRoomNumber() const
{return room; };

int Clients::getReservation() const
{ return reservations; }

void Clients::info(ostream &o) const {
    o << "Name: " << name << "  NIF: " << NIF << "  Previous reservations: " << history;
    o << " Number of guests: " << reservations << "  Number(s) of the room(s): " << room;
    o << endl;
}

void Clients::info() const {
    return Clients::info(cout);
}

/*if reservations<= //lugares disponiveis
    lugares disponiveis - reservations*/