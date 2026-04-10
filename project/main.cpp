#include <iostream>
#include "ProductSystem.h"
using namespace std;

int main() {
    ProductSystem ps;
    int choice;

    while (true) {
        cout << "\n1.Add 2.Remove 3.Update 4.Search 5.Display 6.Range 7.Exit\n";
        cin >> choice;

        if (choice == 7) break;

        int id;
        string name;
        double price, minP, maxP;

        switch (choice) {
            case 1:
                cin >> id >> name >> price;
                ps.addProduct(id, name, price);
                break;

            case 2:
                cin >> id;
                ps.removeProduct(id);
                break;

            case 3:
                cin >> id >> price;
                ps.updatePrice(id, price);
                break;

            case 4:
                cin >> id;
                ps.searchProduct(id);
                break;

            case 5:
                ps.displayAll();
                break;

            case 6:
                cin >> minP >> maxP;
                ps.rangeQuery(minP, maxP);
                break;
        }
    }
}