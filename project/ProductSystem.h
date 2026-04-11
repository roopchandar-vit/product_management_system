#ifndef PRODUCTSYSTEM_H
#define PRODUCTSYSTEM_H

#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    double price;
};

class ProductSystem {
public:
    void loadFromCSV(string filename);

    void displayFullData(); 
    void displayProducts();

    void addProduct(int id, string name, double price);
    void deleteProduct(int id);
    void updateProduct(int id, double newPrice);
    void searchProduct(int id);
    void rangeQuery(double minPrice, double maxPrice);
};

#endif