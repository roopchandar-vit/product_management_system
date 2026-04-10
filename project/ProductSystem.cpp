#include <iostream>
#include <climits>
#include "ProductSystem.h"
using namespace std;

void ProductSystem::addProduct(int id, string name, double price) {
    if (productMap.count(id)) {
        cout << "Product ID exists!\n";
        return;
    }
    productMap[id] = {id, name, price};
    priceSet.insert({price, id});
}

void ProductSystem::removeProduct(int id) {
    if (!productMap.count(id)) return;

    auto p = productMap[id];
    priceSet.erase({p.price, id});
    productMap.erase(id);
}

void ProductSystem::updatePrice(int id, double newPrice) {
    if (!productMap.count(id)) return;

    auto &p = productMap[id];
    priceSet.erase({p.price, id});
    p.price = newPrice;
    priceSet.insert({newPrice, id});
}

void ProductSystem::searchProduct(int id) {
    if (!productMap.count(id)) {
        cout << "Not found\n";
        return;
    }

    auto p = productMap[id];
    cout << p.id << " " << p.name << " " << p.price << endl;
}

void ProductSystem::displayAll() {
    for (auto &x : priceSet) {
        auto p = productMap[x.second];
        cout << p.id << " " << p.name << " " << p.price << endl;
    }
}

void ProductSystem::rangeQuery(double minPrice, double maxPrice) {
    auto low = priceSet.lower_bound({minPrice, -1});
    auto high = priceSet.upper_bound({maxPrice, INT_MAX});

    for (auto it = low; it != high; ++it) {
        auto p = productMap[it->second];
        cout << p.id << " " << p.name << " " << p.price << endl;
    }
}