#include <iostream>
using namespace std;
#include <vector>

class Product {
public:
    string brand_name;
    string model_name;
    string size;
    string color;
    double price;
    int quantity;
};




class ListOfProducts {
public:
    void add_product(Product& product);
    void list_of_products() ;
    void edit_product(int i);
    void remove_product(int i);

private:
    vector<Product> products;
};




void ListOfProducts::add_product(Product& product){
    products.push_back(product);

}


void ListOfProducts::list_of_products(){

    if (products.size()==0){

        cout << "No products available." << endl;
        return;
    
    }

    for (int i =0 ; i < products.size();++i){

        cout << "Product Number: " << i+1 << endl;
        cout << "Brand: " << products[i].brand_name << endl;
        cout << "Model: " << products[i].model_name << endl;
        cout << "Size: " << products[i].size << endl;
        cout << "Color: " << products[i].color << endl;
        cout << "Price: " << products[i].price << endl;
        cout << "Quantity: " << products[i].quantity << endl;
        cout << "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/* " << endl;


    }
}



void ListOfProducts::remove_product(int i){
    if (i < 1 || i > products.size()) {

        cout << "Invalid product number." << endl;
        return;
    }
    products.erase(products.begin() + (i - 1));

    cout << "Product removed successfully." << endl;
}

void ListOfProducts::edit_product(int i){
    if (i < 1 || i > products.size()) {

        cout << "Invalid product number." << endl;
        return;
    }

    Product& product = products[i - 1];

    cout << "Editing product number " << i << endl;

    cout << "Enter new brand name: " << product.brand_name << endl;
    cin.ignore();
    getline(cin, product.brand_name);

    cout << "Enter new model name: " << product.model_name << endl;
    getline(cin, product.model_name);

    cout << "Enter new size: " << product.size << endl;
    getline(cin, product.size);

    cout << "Enter new color: " << product.color << endl;
    getline(cin, product.color);

    cout << "Enter new quantity: " << product.quantity << endl;
    cin >> product.quantity;

    cout << "Enter new price: "<< product.price << endl;
    cin >> product.price;

    cout << "Product edited successfully." << endl;
}

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
    void list_of_products() ;

private:

    ListOfProducts product_list;
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
        cout << "4. List of products" << endl;
        cout << "5. Return to Main Menu" << endl;
        cout << "6. Exit" << endl;
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
                list_of_products();
        case 5:
                return;
        case 6:
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

    product_list.add_product(product);


    cout << "Product added successfully" <<endl;

}

void Management::list_of_products() {

    product_list.list_of_products();
}

void Management::edit_product(){
    int i;
    cout << "Enter the product number to edit: ";
    cin >> i;
    product_list.edit_product(i);
}

void Management::remove_product(){
    int i;
    cout << "Enter the product number to remove: ";
    cin >> i;
    product_list.remove_product(i);
}





int main() {
    ProductStore store;
    store.show_main_page();
    return 0;
}
