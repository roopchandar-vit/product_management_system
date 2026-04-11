#include "ProductSystem.h"
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

static string trimLine(const string &s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

// DATA STRUCTURES
unordered_map<int, Product> productMap;   // unique products
set<pair<double, int>> priceSet;          // sorted by price
vector<Product> fullData;                 // FULL dataset

// ================= LOAD CSV =================
void ProductSystem::loadFromCSV(string filename) {
    ifstream file(filename);
    string line;

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    getline(file, line); // skip header

    while (getline(file, line)) {
        if (trimLine(line).empty()) continue;

        stringstream ss(line);
        string temp;

        int product_id;
        string name;
        double price;

        getline(ss, temp, ','); product_id = stoi(temp);
        getline(ss, name, ',');
        getline(ss, temp, ','); price = stod(temp);

        // store FULL dataset
        Product p = {product_id, name, price};
        fullData.push_back(p);

        // store unique products
        if (productMap.find(product_id) == productMap.end()) {
            addProduct(product_id, name, price);
        }
    }

    cout << "Dataset loaded successfully!\n";
}

// ================= DISPLAY FULL DATA =================
void ProductSystem::displayFullData() {
    if (fullData.empty()) {
        cout << "No data available\n";
        return;
    }

    cout << "\n================ FULL DATASET ================\n";
    cout << left << setw(15) << "Product ID"
         << setw(20) << "Product Name"
         << setw(10) << "Price" << endl;

    cout << "---------------------------------------------\n";

    for (auto &p : fullData) {
        cout << left << setw(15) << p.id
             << setw(20) << p.name
             << setw(10) << p.price << endl;
    }

    cout << "=============================================\n";
}

// ================= DISPLAY SORTED =================
void ProductSystem::displayProducts() {
    if (priceSet.empty()) {
        cout << "No products available\n";
        return;
    }

    cout << "\n============== SORTED PRODUCTS ==============\n";
    cout << left << setw(15) << "Product ID"
         << setw(20) << "Product Name"
         << setw(10) << "Price" << endl;

    cout << "---------------------------------------------\n";

    for (auto &entry : priceSet) {
        Product p = productMap[entry.second];

        cout << left << setw(15) << p.id
             << setw(20) << p.name
             << setw(10) << p.price << endl;
    }

    cout << "=============================================\n";
}

// ================= ADD =================
void ProductSystem::addProduct(int id, string name, double price) {
    if (productMap.find(id) != productMap.end()) {
        cout << "Error: A product with ID " << id
             << " already exists. Duplicates are not allowed.\n";
        return;
    }

    Product p = {id, name, price};

    productMap[id] = p;
    priceSet.insert({price, id});
    fullData.push_back(p);

    cout << "Product added successfully!\n";
}

// ================= DELETE =================
void ProductSystem::deleteProduct(int id) {
    if (productMap.find(id) == productMap.end()) {
        cout << "Product not found\n";
        return;
    }

    Product p = productMap[id];
    priceSet.erase({p.price, id});
    productMap.erase(id);

    cout << "Product deleted\n";
}

// ================= UPDATE =================
void ProductSystem::updateProduct(int id, double newPrice) {
    if (productMap.find(id) == productMap.end()) {
        cout << "Product not found\n";
        return;
    }

    Product &p = productMap[id];
    priceSet.erase({p.price, id});
    p.price = newPrice;
    priceSet.insert({newPrice, id});

    cout << "Product updated\n";
}

// ================= SEARCH =================
void ProductSystem::searchProduct(int id) {
    if (productMap.find(id) != productMap.end()) {
        Product p = productMap[id];

        cout << "\nProduct Found:\n";
        cout << left << setw(15) << "Product ID"
             << setw(20) << "Product Name"
             << setw(10) << "Price" << endl;

        cout << "---------------------------------------------\n";

        cout << left << setw(15) << p.id
             << setw(20) << p.name
             << setw(10) << p.price << endl;
    } else {
        cout << "Product not found\n";
    }
}

// ================= RANGE QUERY =================
void ProductSystem::rangeQuery(double minPrice, double maxPrice) {
    cout << "\nProducts in range:\n";

    cout << left << setw(15) << "Product ID"
         << setw(20) << "Product Name"
         << setw(10) << "Price" << endl;

    cout << "---------------------------------------------\n";

    for (auto &entry : priceSet) {
        if (entry.first >= minPrice && entry.first <= maxPrice) {
            Product p = productMap[entry.second];

            cout << left << setw(15) << p.id
                 << setw(20) << p.name
                 << setw(10) << p.price << endl;
        }
    }
}