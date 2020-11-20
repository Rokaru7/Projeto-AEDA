
#ifndef PROJETO_AEDA_PRODUCTS_H
#define PROJETO_AEDA_PRODUCTS_H

#include <string>
#include <vector>
using namespace std;

class Product {
    string type;
    int price, quality;
public:
    /**
     * Creates an object Product
     * @param type
     * @param price
     * @param quality
     */
    Product(string t, int p, int q);
    /**
     * Returns the type of the product.
     * @return type
     */
    string getType() const;
    /**
     * Returns the price of the product.
     * @return price
     */
    int getPrice() const;
    /**
     * Returns the quality of the product.
     * @return
     */
    int getQuality() const;
    /**
     * Displays info of the product in a human friendly way.
     */
    void info() const;
};

class ProductDoesNotExist {
public:
    /**
     * Exception when the product does not exist.
     */
    ProductDoesNotExist() {};
};

class Provider {
    string name;
    vector<Product *> products;
public:
    /**
     * Creates an object provider.
     * @param name
     */
    Provider(string n);
    /**
     * Returns the name of the provider
     * @return name
     */
    string getName() const;
    /**
     * Returns the vector of the products from the class provider.
     * @return vector<Products *> products
     */
    vector<Product *> getProducts();
    /**
     * Adds a product to the vector of products of the class provider
     * Writes to the data file if write = true.
     * @param provider
     * @param write
     */
    void addProduct(Product *p, bool w);
    /**
     * Removes the product from the position pos from the vector of products of the provider class
     * @param position
     */
    void removeProduct(int pos);
    /**
     * Returns the position of the product on the vector of products of the provider class whose name is given to the function.
     * @param name
     * @return position
     */
    int getProductpos(string n);
};

class ProviderDoesNotExist {
    string name;
public:
    /**
     * Exception when the provider does not exist
     * @param name
     */
    ProviderDoesNotExist(string n) {name = n;}
    string getName() {return name;}
};

#endif //PROJETO_AEDA_PRODUCTS_H
