#include "clients.h"
#include <iostream>
#include <string>

using namespace std;

Clients::Clients(string n, int N, int h, int r){
    name=n; NIF=N; history=h;reservations=r;
}

string Clients::getName() const
{ return name; };

int Clients::getNIF() const
{ return NIF; };

int Clients::getHistory() const
{ return history; };

int Clients::getReservation() const
{return reservations; };

if reservations<= //lugares disponiveis
    lugares disponiveis - reservations