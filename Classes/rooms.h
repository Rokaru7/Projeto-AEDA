
#ifndef PROJETO_AEDA_ROOMS_H
#define PROJETO_AEDA_ROOMS_H

#include <string>
using namespace std;

class Room {
    string type;
    int number, floor, price, capacity;
    bool free = true;
public:
    /**
     * Creates an object room.
     * @param type
     * @param floor
     * @param number
     * @param price
     * @param capacity
     * @param free
     */
    Room(string t, int f, int n, int p, int c, bool fr);
    /**
     * Returns the type of room.
     * @return type
     */
    string getType();
    /**
     * Returns the number of the room.
     * @return number
     */
    int getNumber();
    /**
     * Returns the floor of the room.
     * @return floor
     */
    int getFloor();
    /**
     * Returns the price of the room.
     * @return price
     */
    int getPrice();
    /**
     * Returns the capacity of the room.
     * @return room
     */
    int getCapacity();
    /**
     * Returns if the room is free or not.
     * @return free
     */
    bool getFree();
    /**
     * Makes the room not free if possible.
     * @return possible
     */
    bool enter();
    /**
     * Makes the room free if possible
     * @return possible
     */
    bool leave();
    /**
     * Displays info about the room in a human friendly way.
     */
    virtual void info() const;
    virtual void info(ostream &o) const;
};


#endif //PROJETO_AEDA_ROOMS_H
