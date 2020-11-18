
#include "products.h"
#include <iostream>

Product::Product(string t, int p, int q) {
    type = t; price = p; quality = q;
}

string Product::getType() const {
    return type;
}

int Product::getPrice() const {
    return price;
}

int Product::getQuality() const {
    return quality;
}

void Product::info() const {
    cout << "Type: " << type << "    Price: " << price << "    Quality:" << quality << endl;
}

vector<Product *> Provider::getProducts() {
    return products;
}

void Provider::addProduct(Product *p) {
    products.push_back(p);
}

void Provider::removeProduct(int pos) {
    products.erase(products.begin() + pos);
}

Provider::Provider(string n) {
    name = n;
}

string Provider::getName() const {
    return name;
}

int Provider::getProductpos(string n) {
    for(int i = 0; i != products.size(); i++){
        if(products[i]->getType() == name){
            return i;
        }
    }
    throw ProductDoesNotExist();
}
