#include <iostream>
using namespace std;

class ProductStore {
public:

    void show_main_page();
    void management();
    void customer();
};

void ProductStore::show_main_page() {
    int option;

    while (true) {
        cout << "1. Management" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                management();
                break;
            case 2:
                customer();
                break;
            case 3:
                cout << "Exiting the program." << endl;
                return;
            default:
                cout << "Invalid option, please try again." << endl;
        }
    }
}


void ProductStore::management() {
    // 
}


void ProductStore::customer() {
    cout << "Customer section is under development." << endl;
}


int main() {
    ProductStore store;
    store.show_main_page();
    return 0;
}
