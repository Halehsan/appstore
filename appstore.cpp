#include <iostream>
using namespace std;
#include <string>
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

        cout << "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/ " << endl;
        cout << "Product Number: " << i+1 << endl;
        cout << "Brand: " << products[i].brand_name << endl;
        cout << "Model: " << products[i].model_name << endl;
        cout << "Size: " << products[i].size << endl;
        cout << "Color: " << products[i].color << endl;
        cout << "Price:   Toman" << products[i].price << endl;
        cout << "Quantity: " << products[i].quantity << endl;
        cout << "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/ " << endl;


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
    cout << "Enter new brand name: ";
    cin.ignore();

    getline(cin, product.brand_name);
    cout << "Enter new model name: ";
    getline(cin, product.model_name);

    cout << "Enter new size: ";
    getline(cin, product.size);

    cout << "Enter new color: ";
    getline(cin, product.color);

    cout << "Enter new quantity: ";
    cin >> product.quantity;

    cout << "Enter new price: ";
    cin >> product.price;
    cout << "Product edited successfully." << endl;
}


class User {
public:
    string username;
    string password;
};

class UserManager{
public:
    bool sign_up(string& username, string& password);
    bool login(string& username, string& password);
    bool change_pass(string& username, string& old_password, string& new_password);
    
private:
    bool validate_pass(string& password);

    vector<User> users;

};

bool UserManager::validate_pass(string& password) {

    if (password.length() < 8) {
        return false;
    }
    for (char ch : password) {

        if (!((ch >= 'A' && ch <= 'Z') ||
              (ch >= 'a' && ch <= 'z') || 
              (ch >= '0' && ch <= '9') || 
               ch == '-' ||                 
               ch == '_')) {                

            return false;
        }
    }
    return true;
}
    


bool UserManager::sign_up(string& username, string& password) {

    if (!validate_pass(password)) {
        cout << "Password is invalid. It must be at least 8 characters long and include only letters, digits, hyphens, and underscores." << endl;

        return false;
    }


    User newUser;
    newUser.username = username;
    newUser.password = password;
    users.push_back(newUser);
    cout << "Sign up successful!" << endl;
    return true;
}


bool UserManager::login(string& username, string& password) {
    for (auto& user : users) {

        if (user.username == username && user.password == password) {
            cout << "Login successful." << endl;
            return true;
        }
    }
    cout << "Invalid username or password. Try again." << endl;
    return false;
}


bool UserManager::change_pass(string& username, string& old_password, string& new_password) {
    for (auto& user : users) {
        if (user.username == username && user.password == old_password) {
            if (!validate_pass(new_password)) {
                cout << "Password is invalid." << endl;
                return false;
            }
            user.password = new_password;
            cout << "Password changed successfully." << endl;
            return true;
        }
    }
    cout << "Invalid username or old password." << endl;
    return false;
}



class Management {
public:
    void show_management_page(UserManager& userManager, string& loggedInUser);
    void add_product();
    void edit_product();
    void remove_product();
    void list_of_products() ;
    void settings(UserManager& userManager, string& loggedInUser);
    void change_pass(UserManager& userManager,  string& loggedInUser);


private:

    ListOfProducts product_list;
};


class ProductStore {
public:

    void show_main_page();
    void management();
    void customer();

private:

    UserManager userManager;
    string loggedInUser;
    bool isUserLoggedIn = false;
    Management managementPage;
};

void ProductStore::show_main_page() {
    int option;

    while (true) {
        cout << "****************************************" << endl;
        cout << "*              Main Menu               *" << endl;
        cout << "****************************************" << endl;
        cout << "****************************************" << endl;
        cout << "*  1. Management                       *" << endl;
        cout << "*  2. Customer                         *" << endl;
        cout << "*  3. Exit                             *" << endl;
        cout << "* Enter your option: ";
        cin >> option;
        cout << "****************************************" << endl;

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


void Management::show_management_page(UserManager& userManager, string& loggedInUser) {

    int option;

    while (true){

        cout << "****************************************" << endl;
        cout << "*           Management Menu            *" << endl;
        cout << "****************************************" << endl;
        cout << "****************************************" << endl;
        cout << "*  1. Add Product                      *" << endl;
        cout << "*  2. Edit Product                     *" << endl;
        cout << "*  3. Remove Product                   *" << endl;
        cout << "*  4. List of Products                 *" << endl;
        cout << "*  5. Settings                         *" << endl;
        cout << "*  6. Return to Main Menu              *" << endl;
        cout << "*  7. Exit                             *" << endl;
        cout << "* Enter your option: ";
        cin >> option;
        cout << "****************************************" << endl;

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
                settings(userManager,loggedInUser);
        case 6:
                return;
        case 7:
                exit(0);
        
        default:
            cout << "Invalid option, try again." << endl;
        }
    
    }
}



void ProductStore::management() {
    int option;
    
    if (!isUserLoggedIn) {

        cout << "****************************************" << endl;
        cout << "*           Management Login           *" << endl;
        cout << "****************************************" << endl;
        cout << "****************************************" << endl;
        cout << "* 1. Login                             *" << endl;
        cout << "* 2. Sign Up                           *" << endl;
        cout << "* Enter your option: ";
        cin >> option;
        cout << "****************************************" << endl;

        cout << "Enter username: ";
        cin >> loggedInUser;
        cout << "Enter password: ";

        string password;
        cin >> password;

        if (option == 1) {
            if (userManager.login(loggedInUser, password)) {
                isUserLoggedIn = true;
                managementPage.show_management_page(userManager, loggedInUser);
            } else {
                cout << "Login failed." << endl;
            }
        } else if (option == 2) {
            if (userManager.sign_up(loggedInUser, password)) {
                isUserLoggedIn = true;
                managementPage.show_management_page(userManager, loggedInUser);
            } else {
                cout << "Sign up failed." << endl;
            }
        } else {
            cout << "Invalid option, returning to main menu." << endl;
        }
    } else {
        managementPage.show_management_page(userManager, loggedInUser);
    }
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

    cout <<  "Enter the price:" ;
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

void Management::settings(UserManager& userManager,  string& loggedInUser) {
    int option;

    while (true) {

        cout << "****************************************" << endl;
        cout << "*             Settings Menu            *" << endl;
        cout << "****************************************" << endl;
        cout << "****************************************" << endl;
        cout << "* 1. Change Password                   *" << endl;
        cout << "* 2. Return to Management Menu         *" << endl;
        cout << "* Enter your option: ";
        cin >> option;
        cout << "****************************************" << endl;

        switch (option) {
            case 1:
                change_pass(userManager,loggedInUser);
                break;
            case 2:
                return;
            default:
                cout << "Invalid option, try again." << endl;
        }
    }
}



void Management::change_pass(UserManager& userManager, string& loggedInUser) {
    string old_password, new_password;

    cout << "Enter old password: ";
    cin >> old_password;

    cout << "Enter new password: ";
    cin >> new_password;

    if (userManager.change_pass(loggedInUser, old_password, new_password)) {
        cout << "Password changed successfully." << endl;
    } else {
        cout << "Failed to change password." << endl;
    }
}


int main() {
    ProductStore store;
    store.show_main_page();
    return 0;
}
