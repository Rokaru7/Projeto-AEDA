
#ifndef PROJETO_AEDA_PRODUCTS_H
#define PROJETO_AEDA_PRODUCTS_H

#include <string>
#include <vector>
using namespace std;

class Product {
    string type;
    int price, quality;
public:
    Product(string t, int p, int q);
    string getType() const;
    int getPrice() const;
    int getQuality() const;
    void info() const;
};

class ProductDoesNotExist {
public:
    ProductDoesNotExist() {};
};

class Provider {
    string name;
    vector<Product *> products;
public:
    Provider(string n);
    string getName() const;
    vector<Product *> getProducts();
    void addProduct(Product *p);
    void removeProduct(int pos);
    int getProductpos(string n);
};

class ProviderDoesNotExist {
    string name;
public:
    ProviderDoesNotExist(string n) {name = n;}
    string getName() {return name;}
};

#endif //PROJETO_AEDA_PRODUCTS_H
