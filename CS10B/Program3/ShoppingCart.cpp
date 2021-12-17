#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(){
    _customerName = "none";
    _currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string _customerName, string _date){
    this -> _customerName = _customerName;
    this -> _currentDate = _date;
}

string ShoppingCart::customerName() const{
    return _customerName;
}

string ShoppingCart::date() const{
    return _currentDate;
}

void ShoppingCart::addItem(const ItemToPurchase& item){
    _cartItems.push_back(item);
}

void ShoppingCart::removeItem(string itemName){
    bool fail = true;
    for(unsigned i = 0; i < _cartItems.size(); ++i){
        if(_cartItems.at(i).name() == itemName){
            _cartItems.erase(_cartItems.begin() + i);
            fail = false;
        }
    }
    if(fail){
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::modifyItem(const ItemToPurchase& item){
    bool fail = true;
    for(unsigned i = 0; i < _cartItems.size(); ++i){
        if(_cartItems.at(i).name() == item.name()){
            fail = false;
            if(item.description() != "none"){
                _cartItems.at(i).setDescription(item.description());
            }
            if(item.quantity() != 0){
                _cartItems.at(i).setQuantity(item.quantity());
            }
            if(item.price() != 0){
                _cartItems.at(i).setPrice(item.price());
            } 
        }
    }
    if(fail){
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

int ShoppingCart::numItemsInCart() const{
    int total = 0;
    for(const ItemToPurchase& i : _cartItems){
        total += i.quantity();
    }
    return total;
}

int ShoppingCart::costOfCart() const{
    int total = 0;
    for(const ItemToPurchase& i : _cartItems){
        total += (i.price() * i.quantity());
    }
    return total;
}

void ShoppingCart::printTotal() const{
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl << endl;
    for(const ItemToPurchase& i : _cartItems){
        i.printItemCost();
    }
    if(numItemsInCart() == 0){
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    cout << endl;
    cout << "Total: $" << costOfCart();
    cout << endl << endl;
}

void ShoppingCart::printDescriptions() const{
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;
    for(const ItemToPurchase& i : _cartItems){
        i.printItemDescription();
    }

}