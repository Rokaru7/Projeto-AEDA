#ifndef PROJETO_AEDA_CLIENTS_H
#define PROJETO_AEDA_CLIENTS_H
#include "rooms.h"
#include <string>
#include <vector>
using namespace std;

class Clients {
    string name;
    int NIF, history, reservations;
    int nroom = 0;
    vector<Room *> rooms;
public:
    Clients(string name, int NIF, int history, int R);
    int getNIF() const;
    string getName() const;
    int getHistory() const;
    int getReservation() const;
    void addRoom(Room *r);
    int getNroom();
    vector<Room *> getRooms() const;
    void inforooms(ostream &o);
    virtual void info();
    virtual void info(ostream &o);
};

class ClientDoesNotExist {
    string name;
public:
    ClientDoesNotExist(string n) {name = n;}
    string getName() {return name;}
};

#endif //PROJETO_AEDA_CLIENTS_H


//^^ reservam um ou mais quartos dependendo do numero de lugares pretendidos