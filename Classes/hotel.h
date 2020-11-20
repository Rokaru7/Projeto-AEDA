
#ifndef PROJETO_AEDA_HOTEL_H
#define PROJETO_AEDA_HOTEL_H

#include <vector>
#include "workers.h"
#include "products.h"
#include "clients.h"
#include "rooms.h"
using namespace std;

/**
 * Class hotel that we will build our program around
 */
class hotel {
    vector<Worker *> workers;
    vector<Provider *> providers;
    vector<Product *> boughtproducts;
    vector<Clients *> clients;
    vector<Room *> rooms;
    int totalproducts = 0;
    int totalworkers = 0;
    int income = 0;
public:
    /**Adds the worker w to the vector of workers of the class hotel.
     * Writes to data file if write = true.
     *
     * @param Worker *w
     * @param bool write
     */
    void addWorker(Worker *w, bool write);
    /**Removes the worker from the position pos of the vector.
     * Also deletes the worker from the data file.
     *
     * @param position
     */
    void removeWorker(int pos);
    /**Returns the vector of workers from the class hotel.
     *
     * @return vector<Worker *> workers
     */
    vector<Worker *> getWorkers();
    /**Returns the position of the worker in the vector of the class hotel whose name is given to the function.
     *
     * @param name
     * @return position of the worker whose name = name
     */
    int getWorkerpos(string name) const;
    /**Adds a provider to the vector of providers of the hotel class.
     * Writes to the data file if write = true.
     *
     * @param Provider p
     * @param write
     */
    void addProvider(Provider *p, bool w);
    /**Removes the worker from the position pos of the vector.
     * Also deletes the provider and his products from the data file
     *
     * @param position
     */
    void removeProvider(int pos);
    /**Returns the position of the provider in the vector of the class hotel whose name is given to the function.
     *
     * @param name
     * @return position
     */
    int getProviderpos(string name) const;
    /**
     * Lists the providers in a human friendly way.
     */
    void listProviders();
    /**
     * Lists the products in a human friendly way.
     */
    void listProducts();
    /**Returns the vector of Provider of the class hotel.
     *
     * @return vector<Provider *> providers
     */
    vector<Provider *> getProviders();
    /**Makes the hotel buy a product.
     *
     * @param product
     */
    void buyProduct(Product *p);
    /**Makes the hotel stop buying the product on the position pos of the vector boughtproducts.
     *
     * @param position
     */
    void removeProduct(int pos);
    /**The hotel manager chooses the cheapest product of a certain type for the hotel to buy.
     *
     * @param type
     */
    void chooseProducts(string type);
    /**Searches the workers by role and displays it in a human friendly way.
     *
     * @param role
     */
    void searchbyRole(string r);
    /**
     * Searches the workers by wage and displays it in a human friendly way.
     * @param wage
     */
    void searchbyWage(int w);
    /**
     * Sorts the workers by role and displays it in a human friendly way.

     */
    void sortbyRole();
    /**
     * Sorts the workers by wage and displays it in a human friendly way.
     */
    void sortbyWage();
    /**Adds client c to the vector of clients of the class hotel.
     * Writes to the data file if write = true.
     *
     * @param client
     * @param write
     */
    void addClient(Clients *c, bool w);
    /**
     * Removes client of the position pos of the vector clients of the class hotel.
     * @param position
     */
    void removeClient(int pos);
    /**
     * Returns the vector clients of the class hotel.
     * @return vector<Clients *> clients
     */
    vector<Clients *> getClients();
    /**
     * Returns the position of the client on the vector of clients of the class hotel whose name is given to the function.
     * @param name
     * @return position
     */
    int getClientspos(string name) const;
    /**
     * Displays clients who have been on the hotel before in a human friendly way.
     */
    void filterClients();
    /**
     * Displays all clients in a human friendly way.
     */
    void listClients();
    /**
     * Adds a room to the vector of rooms of the class hotel.
     * Writes to the data file if write = true.
     * @param room
     * @param write
     */
    void addRoom(Room *r, bool w);
    /**
     * Removes the room from the position pos of the vector of rooms of the class hotel.
     * @param position
     */
    void removeRoom(int pos);
    /**
     * Returns the position of the room in the vector of rooms in the class hotel whose floor and number is given to the function.
     * @param floor
     * @param number
     * @return position
     */
    int getRoompos(int f, int n);
    /**
     * Adds income to the hotel.
     * @param number
     */
    void addIncome(int n);
    /**
     * Removes income from the hotel
     * @param number
     */
    void removeIncome(int n);
    /**
     * Returns the vector of rooms from the class hotel.
     * @return vector<Room *> rooms
     */
    vector<Room *> getRooms();
    /**
     * Lists all rooms in a human friendly way.
     */
    void listRooms();
    /**
     * Lists all free rooms in a human friendly way.
     */
    void listfreeRooms();
    /**
     * Returns the total cost of all bought products
     * @return number
     */
    int getTotalProducts() const;
    /**
     * Returns the total cost of all workers
     * @return number
     */
    int getTotalWorkers() const;
    /**
     * Returns the income of the hotel.
     * @return
     */
    int getIncome() const;
    /**
     * Erases the line eraseline from the data file.
     * @param eraseLine
     */
    void eraseLine(string eraseLine);
};


#endif //PROJETO_AEDA_HOTEL_H
