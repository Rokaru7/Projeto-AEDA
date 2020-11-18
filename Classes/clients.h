#ifndef PROJETO_AEDA_CLIENTS_H
#define PROJETO_AEDA_CLIENTS_H
#include <string>
using namespace std;

class Clients {
protected:
    string name;
    int NIF;
    int history;
    int reservations;
public:
    Clients(string n, int N);
    int getNIF() const ;
    string getName() const;
    int getHistory() const ;
    int getReservation() const;
};


#endif //PROJETO_AEDA_CLIENTS_H


//^^ reservam um ou mais quartos dependendo do numero de lugares pretendidos