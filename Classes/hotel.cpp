
#include "hotel.h"

void hotel::addWorker(Worker w) {
    workers.push_back(w);
}

vector<Worker> hotel::getWorkers() {
    return workers;
}

void hotel::removeWorker(string n) {
    for (vector<Worker>::iterator it = workers.begin(); it != workers.end(); it++){
        if (it->getName() == n) {
            workers.erase(it);
            break;
        }
    }
    throw WorkerDoesNotExist(n);
}

void hotel::addProvider(Provider p) {
    providers.push_back(p);
}

void hotel::removeProvider(string n) {
    for (vector<Provider>::iterator it = providers.begin(); it != providers.end(); it++){
        if (it->getName() == n) {
            providers.erase(it);
            break;
        }
    }
    throw ProviderDoesNotExist(n);
}

int hotel::getProductsprice() const {
    return totalproducts;
}

void hotel::buyProduct(Product *p) {
    boughtproducts.push_back(p);
    totalproducts += p->getPrice();
}

void hotel::removeProduct(Product *p) {
    for (vector<Product *>::iterator it = boughtproducts.begin(); it != boughtproducts.end(); it++){
        if ((*it) == p) {
            boughtproducts.erase(it);
            totalproducts-= p->getPrice();
            break;
        }
    }
    throw ProductDoesNotExist();
}
