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
    /**
     * Creates a object client.
     * @param name
     * @param NIF
     * @param history
     * @param Reservation
     */
    Clients(string name, int NIF, int history, int R);
    /**
     * Returns the NIF of the client
     * @return NIF
     */
    int getNIF() const;
    /**
     * Returns the name of the client.
     * @return name
     */
    string getName() const;
    /**
     * Returns the amount of times a client has been on the hotel.
     * @return history
     */
    int getHistory() const;
    /**
     * Returns the amount of guests of the client.
     * @return guests
     */
    int getReservation() const;
    /**
     * Adds a room to the vector of rooms of the class client
     * @param room
     */
    void addRoom(Room *r);
    /**
     * Returns the vector of rooms of the class client.
     * @return vector<Room *> rooms
     */
    vector<Room *> getRooms() const;
    /**
     * Displays the info about the clients rooms in a human friendly way.
     * @param o
     */
    void inforooms(ostream &o);
    /**
     * Displays the info of the client in a human friendly way.
     */
    virtual void info();
    virtual void info(ostream &o);
};

class ClientDoesNotExist {
    string name;
public:
    /**
     * Exception when client of name n does not exist.
     * @param n
     */
    ClientDoesNotExist(string n) {name = n;}
    string getName() {return name;}
};

#endif //PROJETO_AEDA_CLIENTS_H
