#ifndef PRODUCT_SYSTEM_H
#define PRODUCT_SYSTEM_H

#include <unordered_map>
#include <set>
#include <vector>
#include "Product.h"

class ProductSystem {
private:
    unordered_map<int, Product> productMap;
    set<pair<double, int>> priceSet;

public:
    void addProduct(int id, string name, double price);
    void removeProduct(int id);
    void updatePrice(int id, double newPrice);
    void searchProduct(int id);
    void displayAll();
    void rangeQuery(double minPrice, double maxPrice);
};

#endif