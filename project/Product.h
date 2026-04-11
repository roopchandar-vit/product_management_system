#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


//  PRODUCT STRUCT

struct Product {
    int    product_id;
    string product_name;
    double price;

    void print() const {
        cout << left
             << setw(12) << product_id
             << setw(30) << product_name
             << "Rs." << setw(10) << fixed << setprecision(2) << price << "\n";
    }

    string toCSV() const {
        return to_string(product_id) + "," +
               product_name + "," +
               to_string(price);
    }
};


//  PRINT TABLE HEADER

inline void printHeader() {
    cout << "\n" << string(60, '-') << "\n";
    cout << left
         << setw(12) << "ProductID"
         << setw(30) << "Name"
         << setw(13) << "Price\n"
         << string(60, '-') << "\n";
}


//  CSV UTILITIES
inline string trim(const string &s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end   = s.find_last_not_of(" \t\r\n");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

inline vector<Product> loadCSV(const string &filename) {
    vector<Product> products;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "[INFO] '" << filename << "' not found. Starting fresh.\n";
        return products;
    }

    string line;
    getline(file, line); 

    int lineNum = 1;
    while (getline(file, line)) {
        lineNum++;
        if (trim(line).empty()) continue;

        stringstream ss(line);
        string token;
        Product p;

        try {
            getline(ss, token, ','); p.product_id   = stoi(trim(token));
            getline(ss, token, ','); p.product_name = trim(token);
            getline(ss, token, ','); p.price        = stod(trim(token));
            products.push_back(p);
        } catch (...) {
            cout << "[WARN] Skipping bad row at line " << lineNum << "\n";
        }
    }

    file.close();
    cout << "[INFO] Loaded " << products.size() << " products from " << filename << "\n";
    return products;
}

inline void saveCSV(const string &filename, const vector<Product> &products) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "[ERROR] Cannot write to " << filename << "\n";
        return;
    }
    file << "product_id,product_name,price\n";
    for (const auto &p : products)
        file << p.toCSV() << "\n";
    file.close();
    cout << "[INFO] Saved " << products.size() << " products to " << filename << "\n";
}

#endif 
