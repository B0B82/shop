#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <set>
#include "order.h"

class Order;

class Customer {
    private:
        std::string title;
        std::set<Order*> orders;
        static std::set<Customer*> customers;
        
    public:
        Customer(const std::string& title);
        Customer(const Customer& originalCustomer);
        ~Customer();

        const std::string& getTitle() const;
        const std::set<Order*>& getOrders() const;
        static const std::set<Customer*>& getCustomers();
        
        void addOrder(Order* newOrder);
        void removeOrder(Order* oldOrder);
        
};

std::ostream& operator<<(std::ostream& out, const Customer& customer);

#endif // CUSTOMER_H
