#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <set>
#include "item.h"
#include "customer.h"

class Item;
class Customer;

class Order {
    private:
        std::string title;
        Customer* customer;
        std::set<Item*> items;
        static std::set<Order*> orders;
        
    public:
        Order(const std::string& title, Customer* customer, Item* initialItem);
        Order(const Order& originalOrder);
        ~Order();

        const std::string& getTitle() const;
        const Customer* getCustomer() const;
        const std::set<Item*>& getItems() const;
        static const std::set<Order*>& getOrders();
        
        void addItem(Item* item);
        void removeItem(Item* item);
        
};

std::ostream& operator<<(std::ostream& out, const Order& order);

#endif // ORDER_H
