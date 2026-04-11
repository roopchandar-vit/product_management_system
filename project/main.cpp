#include <iostream>
#include "ProductSystem.h"
using namespace std;

int main() {
    ProductSystem ps;
    int choice;

    while (true) {
        cout << "1.Add \n2.Remove \n3.Update \n4.Search \n5.Display \n6.Range 7.Exit\n";
        cin >> choice;

        if (choice == 7) break;

        int id;
        string name;
        double price, minP, maxP;

        switch (choice) {
            case 1:
                cout<<"Enter product id, name and price\n";
                cin >> id >> name >> price;
                ps.addProduct(id, name, price);
                break;

            case 2:
                cout<<"Enter product id\n ";
                cin >> id;
                ps.removeProduct(id);
                break;

            case 3:
                cout<<"Enter product id and price\n";
                cin >> id >> price;
                ps.updatePrice(id, price);
                break;

            case 4:
                cout<<"Enter product id\n";
                cin >> id;
                ps.searchProduct(id);
                break;

            case 5:
                ps.displayAll();
                break;

            case 6:
                cout<<"Enter Minimum price and Maximum price\n";
                cin >> minP >> maxP;
                ps.rangeQuery(minP, maxP);
                break;
        }
    }
}