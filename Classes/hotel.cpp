#include <iostream>
#include <algorithm>
#include "hotel.h"

void hotel::addWorker(Worker *w) {
    workers.push_back(w);
}

vector<Worker *> hotel::getWorkers() {
    return workers;
}

void hotel::removeWorker(string n) {
    for (vector<Worker *>::iterator it = workers.begin(); it != workers.end(); it++){
        if ((*it)->getName() == n) {
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

void hotel::removeProduct(int pos) {
    totalproducts -= boughtproducts[pos]->getPrice();
    boughtproducts.erase(boughtproducts.begin() + pos);
}

void hotel::searchbyRole(string r) {
    if (!workers.empty()) {
        vector<Worker *> temp;
        for (vector<Worker *>::iterator it = workers.begin(); it != workers.end(); it++) {
            if ((*it)->getRole() == r) {
                temp.push_back(*it);
            }
        }
        for (int i = 0; i != temp.size(); i++){
            temp[i]->info();
        }
        temp.clear();
    }
}

void hotel::searchbyWage(int w) {
    if (!workers.empty()) {
        vector<Worker *> temp;
        for (vector<Worker *>::iterator it = workers.begin(); it != workers.end(); it++) {
            if ((*it)->getWage() == w) {
                temp.push_back(*it);
            }
        }
        for (int i = 0; i != temp.size(); i++){
            temp[i]->info();
        }
        temp.clear();
    }
}

bool compRole(Worker *w1, Worker *w2){
    if (w1->getRole() < w2->getRole()) return true;
    else if (w1->getRole() > w2->getRole()) return false;
    else if (w1->getName() < w2->getName()) return true;
    else return false;
}

void hotel::sortbyRole() {
    sort(workers.begin(), workers.end(), compRole);
    for (int i = 0; i != workers.size(); i++){
        workers[i]->info();
    }
}

bool compWage(Worker *w1, Worker *w2){
    if (w1->getWage() < w2->getWage()) return true;
    else if (w1->getWage() > w2->getWage()) return false;
    else if (w1->getName() < w2->getName()) return true;
    else return false;
}

void hotel::sortbyWage() {
    sort(workers.begin(), workers.end(), compWage);
    for (int i = 0; i != workers.size(); i++){
        workers[i]->info();
    }
}

void hotel::chooseProducts(string type) {
    bool lower, found;
    int pos;
    for(int i = 0; i != providers.size(); i++){
        for(int j = 0; j != providers[i].getProducts().size(); j++){
            if (providers[i].getProducts()[j]->getType() == type){
                if (boughtproducts.empty()){
                    buyProduct(providers[i].getProducts()[j]);
                }
                else {
                    lower = false;
                    found = false;
                    for(int k = 0; k != boughtproducts.size(); k++){
                        if(boughtproducts[k]->getType() == type){
                            found = true;
                            if(providers[i].getProducts()[j]->getPrice() < boughtproducts[k]->getPrice()){
                                lower = true;
                                pos = k;
                            }
                            break;
                        }
                    }
                    if (lower){
                        removeProduct(pos);
                        buyProduct(providers[i].getProducts()[j]);
                    }
                    else if (!found){
                        buyProduct(providers[i].getProducts()[j]);
                    }
                }
            }
        }
    }
}


