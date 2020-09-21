#include "item.h"

std::set<Item*> Item::items;

Item::Item(const std::string& title, Category* category) : title(title), category(category) {
    category->addItem(this);
    items.insert(this);
}

Item::Item(const Item& originalItem) {
    items.insert(this);
}

Item::~Item() {
    if ( category != NULL ) {
        Category* oldCategory = category;
        
        category = NULL;
        oldCategory->removeItem(this);
    }
    
    for ( std::set<Order*>::iterator it = orders.begin(); it != orders.end(); it++ ) {
        Order* oldOrder = *it;
        
        orders.erase(it);
        oldOrder->removeItem(this);
    }
    items.erase(this);
}

const std::string& Item::getTitle() const {
    return title;
}

const Category* Item::getCategory() const {
    return category;
}

const std::set<Order*>& Item::getOrders() const {
    return orders;
}

const std::set<Item*>& Item::getItems() {
    return items;
}

void Item::setCategory(Category* newCategory) {
    if ( newCategory == NULL ) {
        delete this;
        return;
    }
    
    if ( newCategory != category ) {
        category->removeItem(this);
        category = newCategory;
        category->addItem(this);
    }
}

void Item::addOrder(Order* newOrder) {
    orders.insert(newOrder);
}

void Item::removeOrder(Order* oldOrder) {
    orders.erase(oldOrder);
}

std::ostream& operator<<(std::ostream& out, const Item& item) {
    return out << item.getTitle();
}
