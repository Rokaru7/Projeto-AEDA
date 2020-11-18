#include <iostream>
#include <algorithm>
#include "hotel.h"

void hotel::addWorker(Worker *w) {
    totalworkers += w->getWage();
    workers.push_back(w);
}

vector<Worker *> hotel::getWorkers() {
    return workers;
}

void hotel::removeWorker(int pos) {
    totalworkers -= workers[pos]->getWage();
    workers.erase(workers.begin() + pos);
}

void hotel::addProvider(Provider *p) {
    providers.push_back(p);
}

void hotel::removeProvider(int pos) {
    providers.erase(providers.begin() + pos);
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
        for (vector<Worker *>::iterator it = workers.begin(); it != workers.end(); it++) {
            if ((*it)->getRole() == r) {
                (*it)->info();
            }
        }
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
        for(int j = 0; j != providers[i]->getProducts().size(); j++){
            if (providers[i]->getProducts()[j]->getType() == type){
                if (boughtproducts.empty()){
                    cout << "Buying: " << providers[i]->getName() << "  ";
                    providers[i]->getProducts()[j]->info();
                    buyProduct(providers[i]->getProducts()[j]);
                }
                else {
                    lower = false;
                    found = false;
                    for(int k = 0; k != boughtproducts.size(); k++){
                        if(boughtproducts[k]->getType() == type){
                            found = true;
                            if(providers[i]->getProducts()[j]->getPrice() < boughtproducts[k]->getPrice()){
                                lower = true;
                                pos = k;
                            }
                            break;
                        }
                    }
                    if (lower){
                        removeProduct(pos);
                        cout << "Buying: " << providers[i]->getName() << "  ";
                        providers[i]->getProducts()[j]->info();
                        buyProduct(providers[i]->getProducts()[j]);
                    }
                    else if (!found){
                        cout << "Buying: " << providers[i]->getName() << "  ";
                        providers[i]->getProducts()[j]->info();
                        buyProduct(providers[i]->getProducts()[j]);
                    }
                }
            }
        }
    }
}

int hotel::getWorkerpos(string name) const {
    for(int i = 0; i != workers.size(); i++){
        if(workers[i]->getName() == name){
            return i;
        }
    }
    throw WorkerDoesNotExist(name);
}

int hotel::getTotalProducts() const {
    return totalproducts;
}

int hotel::getTotalWorkers() const {
    return totalworkers;
}

int hotel::getIncome() const {
    return income;
}

int hotel::getProviderpos(string name) const {
    for(int i = 0; i != providers.size(); i++){
        if(providers[i]->getName() == name){
            return i;
        }
    }
    throw ProviderDoesNotExist(name);
}

void hotel::listProviders() {
    if (providers.empty()) cout << "No providers" << endl;
    else{
        for(vector<Provider *>::iterator it = providers.begin(); it != providers.end(); it++){
            cout << (*it)->getName() << endl;
        }
    }
}

vector<Provider *> hotel::getProviders() {
    return providers;
}

void hotel::listProducts() {
    if (providers.empty()) cout << "No providers" << endl;
    else{
        for(int i = 0; i != providers.size(); i++){
            for(int j = 0; j != providers[i]->getProducts().size(); j++){
                cout << providers[i]->getName() << "    ";
                providers[i]->getProducts()[j]->info();
            }
        }
    }
}

void hotel::addClient(Clients *c) {
    clients.push_back(c);
}

void hotel::removeClient(int pos) {
    clients.erase(clients.begin() + pos);
}

vector<Clients *> hotel::getClients() {
    return clients;
}

int hotel::getClientspos(string name) const {
    for(int i = 0; i != clients.size(); i++){
        if(clients[i]->getName() == name){
            return i;
        }
    }
    throw ClientDoesNotExist(name);
}

void hotel::listClients() {
    if (clients.empty()) cout << "No clients" << endl;
    else{
        for(vector<Clients *>::iterator it = clients.begin(); it != clients.end(); it++){
            (*it)->info();
        }
    }
}
