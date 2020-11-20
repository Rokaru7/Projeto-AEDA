
#ifndef PROJETO_AEDA_HOTEL_H
#define PROJETO_AEDA_HOTEL_H

#include <vector>
#include "workers.h"
#include "products.h"
#include "clients.h"
#include "rooms.h"
using namespace std;

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
    void addWorker(Worker *w, bool write);
    void removeWorker(int pos);
    vector<Worker *> getWorkers();
    int getWorkerpos(string name) const;
    void addProvider(Provider *p, bool w);
    void removeProvider(int pos);
    int getProviderpos(string name) const;
    void listProviders();
    void listProducts();
    vector<Provider *> getProviders();
    void buyProduct(Product *p);
    void removeProduct(int pos);
    void chooseProducts(string type);
    void searchbyRole(string r);
    void searchbyWage(int w);
    void sortbyRole();
    void sortbyWage();
    void addClient(Clients *c, bool w);
    void removeClient(int pos);
    vector<Clients *> getClients();
    int getClientspos(string name) const;
    void filterClients();
    void listClients();
    void addRoom(Room *r, bool w);
    void removeRoom(int pos);
    int getRoompos(int f, int n);
    void addIncome(int n);
    void removeIncome(int n);
    vector<Room *> getRooms();
    void listRooms();
    void listfreeRooms();
    int getTotalProducts() const;
    int getTotalWorkers() const;
    int getIncome() const;
    void eraseLine(string eraseLine);


    /*
    -filtrar reservas feitas por clientes novos
    */
};


#endif //PROJETO_AEDA_HOTEL_H
