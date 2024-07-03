#include <iostream>
using namespace std;

class Product {
public:
    string brand_name;
    string model_name;
    string size;
    string color;
    double price;
    int quantity;
};


class ProductStore {
public:

    void show_main_page();
    void management();
    void customer();
};


class Management {
public:
    void show_management_page();
    void add_product();
    void edit_product();
    void remove_product();
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


void Management::show_management_page() {

    int option;

    while (true){

        cout << "Management Section" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Edit Product" << endl;
        cout <<"3. REmove Product" << endl;
        cout << "4. Return to Main Menu" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option)
        {
            case 1:
                add_product();
                break;

            case 2:
                edit_product();
                break;
        case 3:
                remove_product();
                break;
        case 4:
                return;
        case 5:
                exit(0);
        
        default:
            cout << "Invalid option, try again." << endl;
        }
    
    }
}


void ProductStore::management() {
    Management managementPage;
    managementPage.show_management_page();
}

void ProductStore::customer() {
    cout << "Customer section is under development." << endl;
}


void Management::add_product(){
    Product product;


    cout <<  "Enter the brand name:" ;
    cin.ignore();
    getline(cin, product.brand_name);

    cout <<  "Enter the model name:" ;
    getline(cin, product.model_name);

    cout <<  "Enter the size:" ;
    getline(cin, product.size);

    cout <<  "Enter the color:" ;
    getline(cin, product.color);

    cout <<  "Enter the quantity:" ;
    cin >> product.quantity;

    cout <<  "Enter the price::" ;
    cin >> product.price;

    cout << "Product added successfully" <<endl;

}

void Management::edit_product(){
    ///
}

void Management::remove_product(){
    ///
}





int main() {
    ProductStore store;
    store.show_main_page();
    return 0;
}
