#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <iostream>
using namespace std;

class ItemToPurchase{

    public:

    ItemToPurchase();
    ItemToPurchase(string _name, int _quantity);
    ItemToPurchase(string _name, string _description, int _price, int _quantity);
    void setName(string _name);
    void setDescription(string _description);
    void setPrice(int _price);
    void setQuantity(int _quantity);
    void printItemCost() const;
    void printItemDescription() const;
    string name() const;
    string description() const;
    int price() const;
    int quantity() const;

    private:

    string _name;
    string _description;
    int _price;
    int _quantity;
    
};


#endif