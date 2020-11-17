
#ifndef PROJETO_AEDA_HOTEL_H
#define PROJETO_AEDA_HOTEL_H

#include <vector>
#include "workers.h"
#include "products.h"
using namespace std;

class hotel {
    vector<Worker> workers;
    vector<Provider> providers;
    vector<Product *> boughtproducts;
    int totalproducts;
public:
    void addWorker(Worker w);
    void removeWorker(string n);
    vector<Worker> getWorkers();
    void addProvider(Provider p);
    void removeProvider(string n);
    int getProductsprice() const;
    void buyProduct(Product *p);
    void removeProduct(Product *p);

    /*
    -pesquisar funcionarios por cargo e salario
    -filtrar reservas feitas por clientes novos
    -custos e lucro total de funcionamento do hotel
    */
};


#endif //PROJETO_AEDA_HOTEL_H
