#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cstdlib> 


void clear_screen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}


class Product {
public:
    string brand_name;
    string model_name;
    int size;
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


// void ListOfProducts::list_of_products(){

//     if (products.size()==0){

//         cout << "No products available." << endl;
//         cin.ignore();
//         cin.get();
//         return;
    
//     }

//     for (int i =0 ; i < products.size();++i){

//         cout << "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/ " << endl;
//         cout << "Product Number: " << i+1 << endl;
//         cout << "Brand: " << products[i].brand_name << endl;
//         cout << "Model: " << products[i].model_name << endl;
//         cout << "Size: " << products[i].size << endl;
//         cout << "Color: " << products[i].color << endl;
//         cout << "Price: " << products[i].price << " Toman" << endl;
//         cout << "Quantity: " << products[i].quantity << endl;
//         cout << "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/ " << endl;
//         cin.ignore();
//         cin.get();
        


//     }
// }

void ListOfProducts::list_of_products() {
    while (true) {
        clear_screen();

        if (products.empty()) {
            cout << "No products available." << endl;
            cin.ignore();
            cin.get();
            return;
        }

        cout << "Available Products:" << endl;
        for (int i = 0; i < products.size(); ++i) {
            cout << i + 1 << ". " << products[i].brand_name << " - " << products[i].model_name << endl;
        }
        cout << "0. Return to Management Menu" << endl;

        cout << "\nEnter the product number to view details or 0 to return: ";
        int choice;
        cin >> choice;

        if (choice == 0) {
            return;
        }

        if (choice > 0 && choice <= products.size()) {
            while (true) {
                clear_screen();

                cout << "Product Number: " << choice << endl;
                cout << "Brand: " << products[choice - 1].brand_name << endl;
                cout << "Model: " << products[choice - 1].model_name << endl;
                cout << "Size: " << products[choice - 1].size << endl;
                cout << "Color: " << products[choice - 1].color << endl;
                cout << "Price: " << products[choice - 1].price << " Toman" << endl;
                cout << "Quantity: " << products[choice - 1].quantity << endl;

                cout << "\n1. Return to List of Products" << endl;
                cout << "2. Return to Management Menu" << endl;
                cout << "Enter your option: ";
                int detail_choice;
                cin >> detail_choice;

                if (detail_choice == 1) {
                    break;
                } else if (detail_choice == 2) {
                    return;
                } else {
                    cout << "Invalid option, try again." << endl;
                    cin.ignore();
                    cin.get();
                }
            }
        } else {
            cout << "Invalid option, try again." << endl;
            cin.ignore();
            cin.get();
        }
    }
}





void ListOfProducts::remove_product(int i){
    if (i < 1 || i > products.size()) {

        cout << "Invalid product number." << endl;
        return;
    }
    products.erase(products.begin() + (i - 1));        /////////////////////////

    cout << "Product removed successfully." << endl;
}

void ListOfProducts::edit_product(int i) {
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
    cin >> product.size;

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
    bool sign_up(string& username, string& password, string&hotkey);
    bool login(string& username, string& password);
    bool change_pass(string& username, string& old_password, string& new_password);
    
private:
    bool validate_pass(string& password);
    bool validate_username(string& username);

    vector<User> users;
    bool check_hotkey(string& hotkey);
    string valid_hotkey = "123"; 


};

bool UserManager::check_hotkey(string& hotkey) {
    return hotkey == valid_hotkey;
}


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
    
bool UserManager::validate_username(string& username) {
    if (username.length() < 8) {
        return false;
    }
    for (char ch : username) {
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



bool UserManager::sign_up(string& username, string& password, string& hotkey) {
    if (!check_hotkey(hotkey)) {

        cout << "Invalid hot key." << endl;

        return false;
    }

    if (!validate_username(username)) {
        cout << "Username is invalid. It must be at least 8 characters long and include only letters, digits, hyphens, and underscores." << endl;
        return false;
    }

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
    void show_management_page(UserManager& userManager, string& loggedInUser, bool& isUserLoggedIn );
    void add_product();
    void edit_product();
    void remove_product();
    void list_of_products() ;
    void settings(UserManager& userManager, string& loggedInUser, bool& isUserLoggedIn);
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
        clear_screen();
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
                cin.ignore();
                cin.get();
        }
    }
}


void Management::show_management_page(UserManager& userManager, string& loggedInUser,bool& isUserLoggedIn) {

    int option;

    while (true){

        clear_screen();

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
                break;
        case 5:
                settings(userManager,loggedInUser,isUserLoggedIn);
                if (!isUserLoggedIn) return;
                break;
        case 6:
                return;
        case 7:
                exit(0);
        
        default:
            cout << "Invalid option, try again." << endl;
            cin.ignore();
            cin.get();
        }
    
    }
}



void ProductStore::management() {
    int option;
    
    if (!isUserLoggedIn) {

        clear_screen();


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
                managementPage.show_management_page(userManager, loggedInUser,isUserLoggedIn);
            } else {
                cout << "Login failed." << endl;
            }
        } else if (option == 2) {

            cout << "Enter hot key: ";
            string hotkey;
            cin >> hotkey;

            if (userManager.sign_up(loggedInUser, password, hotkey)) {
                isUserLoggedIn = true;
                managementPage.show_management_page(userManager, loggedInUser,isUserLoggedIn);
            } else {
                cout << "Sign up failed." << endl;
            }
        } else {
            cout << "Invalid option, returning to main menu." << endl;
        }
    } else  {
        managementPage.show_management_page(userManager,loggedInUser,isUserLoggedIn );
        cin.ignore();
        cin.get();

    }
}

void ProductStore::customer() {
    cout << "Customer section is under development." << endl;
}


void Management::add_product(){
    clear_screen();

    Product product;


    cout <<  "Enter the brand name:" ;
    cin.ignore();
    getline(cin, product.brand_name);

    cout <<  "Enter the model name:" ;
    getline(cin, product.model_name);

    cout <<  "Enter the size:" ;
    cin >> product.size;
    cin.ignore();
    

    cout <<  "Enter the color:" ;
    getline(cin, product.color);

    cout <<  "Enter the quantity:" ;
    cin >> product.quantity;

    cout <<  "Enter the price:" ;
    cin >> product.price;

    product_list.add_product(product);


    cout << "Product added successfully" <<endl;
    cin.ignore();
    cin.get();

}

void Management::list_of_products() {

    clear_screen();

    product_list.list_of_products();
}

void Management::edit_product(){
    clear_screen();

    int i;
    cout << "Enter the product number to edit: ";
    cin >> i;
    product_list.edit_product(i);
    cin.ignore();
    cin.get();
}

void Management::remove_product(){
    clear_screen();

    int i;
    cout << "Enter the product number to remove: ";
    cin >> i;
    product_list.remove_product(i);
    cin.ignore();
    cin.get();
}

void Management::settings(UserManager& userManager, string& loggedInUser,bool& isUserLoggedIn) {
    int option;

    while (true) {
        clear_screen();

        cout << "****************************************" << endl;
        cout << "*             Settings Menu            *" << endl;
        cout << "****************************************" << endl;
        cout << "****************************************" << endl;
        cout << "* 1. Change Password                   *" << endl;
        cout << "* 2. Return to Management Menu         *" << endl;
        cout << "* 3. Log out                           *" << endl;

        cout << "* Enter your option: ";
        cin >> option;
        cout << "****************************************" << endl;

        switch (option) {
            case 1:
                change_pass(userManager,loggedInUser);
                break;
            case 2:
                return;
            case 3:
                cout << "You have been logged out." << endl;
                isUserLoggedIn = false;                
                return;
            default:
                cout << "Invalid option, try again." << endl;
                cin.ignore();
                cin.get();
        }
    }
}



void Management::change_pass(UserManager& userManager, string& loggedInUser) {
    clear_screen();

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
    cin.ignore();
    cin.get();
}


int main() {
    ProductStore store;
    store.show_main_page();
    return 0;
}
