#include "ItemToPurchase.h"
using namespace std;

ItemToPurchase::ItemToPurchase(){
    _name = "none";
    _description = "none";
    _quantity = 0;
    _price = 0;
}

ItemToPurchase::ItemToPurchase(string _name, string _description, int _price, int _quantity){
    this -> _name = _name;
    this -> _description = _description;
    this -> _price = _price;
    this -> _quantity = _quantity;
}

ItemToPurchase::ItemToPurchase(string _name, int _quantity){
    this -> _name = _name;
    this -> _description = "none";
    this -> _price = 0;
    this -> _quantity = _quantity;
} 

void ItemToPurchase::setName(string _name){
    this -> _name = _name;
}

void ItemToPurchase::setDescription(string _description){
    this -> _description = _description;
}

void ItemToPurchase::setQuantity(int _quantity){
    this -> _quantity = _quantity;
}

void ItemToPurchase::setPrice(int _price){
    this -> _price = _price;
}

string ItemToPurchase::name() const{
    return _name;
}

string ItemToPurchase::description() const{
    return _description;
}

int ItemToPurchase::price() const{
    return _price;
}

int ItemToPurchase::quantity() const{
    return _quantity;
}

void ItemToPurchase::printItemCost() const{
    cout << _name << " " << _quantity << " @ $" << _price << " = $" << _quantity * _price << endl;
}
void ItemToPurchase::printItemDescription() const{
    cout << _name << ": " << _description << endl;
}

