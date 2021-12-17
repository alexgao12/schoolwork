#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "ItemToPurchase.h"
#include <vector>

class ShoppingCart{

    public:
    ShoppingCart();
    ShoppingCart(string _customerName, string _date);  
    string customerName() const;
    string date() const;
    void addItem(const ItemToPurchase& item);
    void removeItem(string itemName);
    void modifyItem(const ItemToPurchase& item);
    int numItemsInCart() const;
    int costOfCart() const;
    void printTotal() const;
    void printDescriptions() const;


    private:
    string _customerName;
    string _currentDate;
    vector<ItemToPurchase> _cartItems;

};


#endif