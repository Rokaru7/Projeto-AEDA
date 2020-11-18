#ifndef PROJETO_AEDA_CLIENTS_H
#define PROJETO_AEDA_CLIENTS_H
#include <string>
using namespace std;

class Clients {
protected:
    string name;
    int NIF, history, reservations;
    int room;
public:
    Clients(string n, int N, int h, int r, int R);
    int getNIF() const;
    string getName() const;
    int getHistory() const;
    int getReservation() const;
    int getRoomNumber() const;
    virtual void info() const;
    virtual void info(ostream &o) const;
};

class ClientDoesNotExist {
    string name;
public:
    ClientDoesNotExist(string n) {name = n;}
    string getName() {return name;}
};

#endif //PROJETO_AEDA_CLIENTS_H


//^^ reservam um ou mais quartos dependendo do numero de lugares pretendidos