
#include "products.h"

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

vector<Product *> Provider::getProducts() {
    return products;
}

void Provider::addProduct(Product *p) {
    products.push_back(p);
}

void Provider::removeProduct(Product *p) {
    for (vector<Product *>::iterator it = products.begin(); it != products.end(); it++){
        if ((*it) == p) {
            products.erase(it);
            break;
        }
    }
    throw ProductDoesNotExist();
}

Provider::Provider(string n) {
    name = n;
}

string Provider::getName() const {
    return name;
}
