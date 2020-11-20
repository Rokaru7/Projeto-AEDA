
#ifndef PROJETO_AEDA_ROOMS_H
#define PROJETO_AEDA_ROOMS_H

#include <string>
using namespace std;

class Room {
    string type;
    int number, floor, price, capacity;
    bool free = true;
public:
    Room(string t, int f, int n, int p, int c);
    string getType();
    int getNumber();
    int getFloor();
    int getPrice();
    int getCapacity();
    bool getFree();
    bool enter();
    bool leave();
    virtual void info() const;
    virtual void info(ostream &o) const;
};


#endif //PROJETO_AEDA_ROOMS_H
