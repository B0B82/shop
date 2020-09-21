#include "category.h"

std::set<Category*> Category::categories;

Category::Category(const std::string& title) : title(title) {
    categories.insert(this);
}

Category::Category(const Category& originalCategory) {
    categories.insert(this);
}

Category::~Category() {
    for ( std::set<Item*>::iterator it = items.begin(); it != items.end(); it++ ) {
        Item* item = *it;
        
        items.erase(it);
        delete item;
    }

    categories.erase(this);
}

const std::string& Category::getTitle() const {
    return title;
}

const std::set<Item*>& Category::getItems() const {
    return items;
}

const std::set<Category*>& Category::getCategories() {
    return categories;
}

void Category::addItem(Item* item) {
    items.insert(item);
}

void Category::removeItem(Item* item) {
    items.erase(item);
}

std::ostream& operator<<(std::ostream& out, const Category& category) {
    return out << category.getTitle();
}
