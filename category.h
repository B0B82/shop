#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <set>
#include "item.h"

class Item;

class Category {
    private:
        std::string title;
        std::set<Item*> items;
        static std::set<Category*> categories;
        
    public:
        Category(const std::string& title);
        Category(const Category& originalCategory);
        ~Category();

        const std::string& getTitle() const;
        const std::set<Item*>& getItems() const;
        static const std::set<Category*>& getCategories();
        
        void addItem(Item* item);
        void removeItem(Item* item);
};

std::ostream& operator<<(std::ostream& out, const Category& category);

#endif // CATEGORY_H
