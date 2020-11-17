
#ifndef PROJETO_AEDA_HOTEL_H
#define PROJETO_AEDA_HOTEL_H

#include <vector>
#include "workers.h"
#include "products.h"
using namespace std;

class hotel {
    vector<Worker *> workers;
    vector<Provider> providers;
    vector<Product *> boughtproducts;
    int totalproducts = 0;
public:
    void addWorker(Worker *w);
    void removeWorker(string n);
    vector<Worker *> getWorkers();
    void addProvider(Provider p);
    void removeProvider(string n);
    int getProductsprice() const;
    void buyProduct(Product *p);
    void removeProduct(int pos);
    void chooseProducts(string type);
    void searchbyRole(string r);
    void searchbyWage(int w);
    void sortbyRole();
    void sortbyWage();

    /*
    -pesquisar funcionarios por cargo e salario
    -filtrar reservas feitas por clientes novos
    -custos e lucro total de funcionamento do hotel
    */
};


#endif //PROJETO_AEDA_HOTEL_H
