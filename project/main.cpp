#include "ProductSystem.h"
#include <iostream>

using namespace std;

int main() {
    ProductSystem ps;

    ps.loadFromCSV("dataset.csv");

    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Display FULL Dataset\n";
        cout << "2. Display Sorted Products\n";
        cout << "3. Add Product\n";
        cout << "4. Delete Product\n";
        cout << "5. Modify Product\n";
        cout << "6. Search Product\n";
        cout << "7. Range Query\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) ps.displayFullData();
        else if (choice == 2) ps.displayProducts();

        else if (choice == 3) {
            int id;
            string name;
            double price;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Price: "; cin >> price;
            ps.addProduct(id, name, price);
        }

        else if (choice == 4) {
            int id;
            cout << "Enter ID: "; cin >> id;
            ps.deleteProduct(id);
        }

        else if (choice == 5) {
            int id;
            double price;
            cout << "Enter ID: "; cin >> id;
            cout << "New Price: "; cin >> price;
            ps.updateProduct(id, price);
        }

        else if (choice == 6) {
            int id;
            cout << "Enter ID: "; cin >> id;
            ps.searchProduct(id);
        }

        else if (choice == 7) {
            double minP, maxP;
            cout << "Min Price: "; cin >> minP;
            cout << "Max Price: "; cin >> maxP;
            ps.rangeQuery(minP, maxP);
        }

    } while (choice != 8);

    return 0;
}