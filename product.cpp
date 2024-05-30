#include "Product.h"

// Product class implementation
Product::Product() {}
Product::Product(string name, float price) : name(name), price(price) {}
void Product::print() {
    cout << "Name: " << name << ", Price: " << price << " TL" << endl;
}
void Product::save(ofstream& file) {
    file << name << " " << price << endl;
}
string Product::getName() {
    return name;
}
float Product::getPrice() {
    return price;
}
Product::~Product() {}

// Beverage class implementation
Beverage::Beverage(string name, float price, float volume) : Product(name, price), volume(volume) {}
void Beverage::print() {
    cout << "Beverage - ";
    Product::print();
    cout << "Volume: " << volume << " mL" << endl;
}
void Beverage::save(ofstream& file) {
    file << "Beverage " << name << " " << price << " " << volume << endl;
}

// Food class implementation
Food::Food(string name, float price, string type) : Product(name, price), type(type) {}
void Food::print() {
    cout << "Food - ";
    Product::print();
    cout << "Type: " << type << endl;
}
void Food::save(ofstream& file) {
    file << "Food " << name << " " << price << " " << type << endl;
}

// Canteen class implementation
void Canteen::addProduct(Product* product) {
    products.push_back(product);
}
void Canteen::listBeverages() {
    cout << "Beverages in the canteen:" << endl;
    for (size_t i = 0; i < products.size(); ++i) {
        if (dynamic_cast<Beverage*>(products[i])) {
            cout << i + 1 << ". ";
            products[i]->print();
        }
    }
}
void Canteen::listFoods() {
    cout << "Foods in the canteen:" << endl;
    for (size_t i = 0; i < products.size(); ++i) {
        if (dynamic_cast<Food*>(products[i])) {
            cout << i + 1 << ". ";
            products[i]->print();
        }
    }
}
Product* Canteen::getProduct(int index) {
    if (index >= 0 && index < products.size()) {
        return products[index];
    }
    return nullptr;
}
void Canteen::saveProducts(string fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        for (const auto& product : products) {
            product->save(file);
        }
        file.close();
        cout << "Products have been saved to the file." << endl;
    } else {
        cout << "File could not be opened: " << fileName << endl;
    }
}
Canteen::~Canteen() {
    for (auto product : products) {
        delete product;
    }
}
