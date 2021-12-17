#include "ShoppingCart.h"

void printMenu();
void c(ShoppingCart&);

int main(){
    string name;
    string itemname;
    string date;
    string input;
    string desc;
    int price;
    int quant;
    cout << "Enter customer's name: ";
    getline(cin, name);
    cout << endl;
    cout << "Enter today's date: ";
    getline(cin, date);
    ShoppingCart cart = ShoppingCart(name, date);
    cout << endl << endl;
    cout << "Customer name: " << cart.customerName() << endl;
    cout << "Today's date: " << cart.date() << endl << endl;
    printMenu();

    while(true){
        cout << "Choose an option: ";
        cin >> input;
        cout << endl;

        if(input == "a"){
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name: " ;
            getline(cin, itemname);
            getline(cin, itemname);
            cout << endl;
            cout << "Enter the item description: ";
            getline(cin, desc);
            cout << endl;
            cout << "Enter the item price: ";
            cin >> price;
            cout << endl;
            cout << "Enter the item quantity: ";
            cin >> quant;
            cout << endl << endl;
            
            cart.addItem(ItemToPurchase(itemname, desc, price, quant));
            printMenu();
        }
        if(input == "o"){
            
            cout << endl << "OUTPUT SHOPPING CART" << endl; 
            cart.printTotal();
            printMenu();
        }
        if(input == "i"){
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            cart.printDescriptions();
            cout << endl;
            printMenu();
        }
        if(input == "d"){
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove: ";
            getline(cin, itemname);
            getline(cin, itemname);
            cout << endl;
            cart.removeItem(itemname);
            cout << endl; 
            printMenu();
        }
        if(input == "q"){
            return 0;
        }
        if(input == "c"){
            c(cart);
        }
    }

}

void printMenu(){
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl << endl;
}

void c(ShoppingCart& cart){
    string itemname;
    int quant;
    ItemToPurchase modify;
    cout << "CHANGE ITEM QUANTITY" << endl;
    cout << "Enter the item name: ";
    getline(cin, itemname);
    getline(cin, itemname);
    cout << endl;
    cout << "Enter the new quantity: ";
    cin >> quant;
    cout << endl;
    modify = ItemToPurchase(itemname, quant);
    cart.modifyItem(modify);
    cout << endl;
    printMenu();
    
}