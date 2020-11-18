
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
    int totalproducts = 0;
    int totalworkers = 0;
    int income = 0;
public:
    void addWorker(Worker *w);
    void removeWorker(int pos);
    vector<Worker *> getWorkers();
    int getWorkerpos(string name) const;
    void addProvider(Provider *p);
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
    void addClient(Clients *c);
    void removeClient(int pos);
    vector<Clients *> getClients();
    int getClientspos(string name) const;
    void sortClients();
    void listClients();
    int getTotalProducts() const;
    int getTotalWorkers() const;
    int getIncome() const;


    /*
    -pesquisar funcionarios por cargo e salario
    -filtrar reservas feitas por clientes novos
    -custos e lucro total de funcionamento do hotel
    */
};


#endif //PROJETO_AEDA_HOTEL_H
