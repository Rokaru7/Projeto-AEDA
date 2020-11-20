#include <iostream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "hotel.h"

void hotel::addWorker(Worker *w, bool write) {
    totalworkers += w->getWage();
    workers.push_back(w);
    if (write){
        ofstream data;
        data.open ("data.txt", fstream::app);
        data << w->getRole() << " " << w->getName() << " " << w->getNIF() << " " << w->getWage() << " " << w->getYears();
        if (w->getRole() == "Cleaning"){
            data << " " << w->getShift() << endl;
        }
        else if (w->getRole() == "Responsible"){
            data << " " << w->getFloor() << endl;
        }
        else if (w->getRole() == "Manager"){
            data << " " << w->getEvaluation() << endl;
        }
        data.close();
    }
}

vector<Worker *> hotel::getWorkers() {
    return workers;
}

void hotel::eraseLine(string eraseLine) {
    string path = "data.txt";
    string line;
    ifstream data;
    data.open("data.txt");
    ofstream temp;
    temp.open("temp.txt");

    while (getline(data, line)) {
        if (line != eraseLine)
            temp << line << std::endl;
    }

    temp.close();
    data.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");
}

void hotel::removeWorker(int pos) {
    string eraseline = workers[pos]->getRole() + " " + workers[pos]->getName() + " " + to_string(workers[pos]->getNIF()) + " " + to_string(workers[pos]->getWage()) + " " + to_string(workers[pos]->getYears());
    if (workers[pos]->getRole() == "Cleaning") eraseline += " " + workers[pos]->getShift();
    else if (workers[pos]->getRole() == "Responsible") eraseline += " " + to_string(workers[pos]->getFloor());
    else if (workers[pos]->getRole() == "Manager") eraseline += " " + to_string(workers[pos]->getEvaluation());
    eraseLine(eraseline);

    totalworkers -= workers[pos]->getWage();
    workers.erase(workers.begin() + pos);
}

void hotel::addProvider(Provider *p, bool w) {
    providers.push_back(p);
    if (w){
        ofstream data;
        data.open ("data.txt", fstream::app);
        data << "Provider " << p->getName() << endl;
        data.close();
    }
}

void hotel::removeProvider(int pos) {
    string eraseline = "Provider " + providers[pos]->getName();
    eraseLine(eraseline);
    for (int i = 0; i != providers[pos]->getProducts().size(); i++){
        eraseline = "Product " + providers[pos]->getName() + " " + providers[pos]->getProducts()[i]->getType() + " " + to_string(providers[pos]->getProducts()[i]->getPrice()) + " " + to_string(providers[pos]->getProducts()[i]->getQuality());
        eraseLine(eraseline);
    }
    providers[pos]->getProducts().clear();
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

void hotel::addClient(Clients *c, bool w) {
    clients.push_back(c);
    if (w){
        ofstream data;
        data.open ("data.txt", fstream::app);
        data << "Client " << c->getName() << " " << c->getNIF() << " " << c->getHistory() << " " << c->getReservation() << endl;
        data.close();
    }
}

void hotel::removeClient(int pos) {
    string eraseline = "Client " + clients[pos]->getName() + " " + to_string(clients[pos]->getNIF()) + " " + to_string(clients[pos]->getHistory()) + " " + to_string(clients[pos]->getReservation());
    eraseLine(eraseline);

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

void hotel::filterClients() {
    if (clients.empty()) cout << "No clients" << endl;
    else{
        for(vector<Clients *>::iterator it = clients.begin(); it != clients.end(); it++){
            if((*it)->getHistory() != 0){
                (*it)->info();
            }
        }
    }
}

void hotel::addRoom(Room *r, bool w) {
    rooms.push_back(r);
    if (w){
        ofstream data;
        data.open ("data.txt", fstream::app);
        data << "Room " << r->getType() << " " << r->getFloor() << " " << r->getNumber() << " " << r->getPrice() << " " << r->getCapacity() << " " << r->getFree() << endl;
        data.close();
    }
}

int hotel::getRoompos(int f, int n) {
    for(int i = 0; i != rooms.size(); i++){
        if(rooms[i]->getFloor() == f && rooms[i]->getNumber() == n){
            return i;
        }
    }
    return 0;
}

void hotel::removeRoom(int pos) {
    if (rooms[pos]->getFree()){
        string eraseline = "Room " + rooms[pos]->getType() + " " + to_string(rooms[pos]->getFloor()) + " " + to_string(rooms[pos]->getNumber()) + " " + to_string(rooms[pos]->getPrice()) + " " + to_string(rooms[pos]->getCapacity()) + " " + to_string(rooms[pos]->getFree());
        eraseLine(eraseline);
        rooms.erase(rooms.begin() + pos);
    }
    else cout << "Room is occupied, so cant be removed" << endl;
}

vector<Room *> hotel::getRooms() {
    return rooms;
}

void hotel::listRooms() {
    if (rooms.empty()) cout << "No clients" << endl;
    else{
        for(vector<Room *>::iterator it = rooms.begin(); it != rooms.end(); it++){
            (*it)->info();
        }
    }
}

void hotel::listfreeRooms() {
    if (rooms.empty()) cout << "No clients" << endl;
    else{
        for(vector<Room *>::iterator it = rooms.begin(); it != rooms.end(); it++){
            if ((*it)->getFree()) (*it)->info();
        }
    }
}

void hotel::addIncome(int n) {
    income += n;
}

void hotel::removeIncome(int n) {
    income -= n;
}


