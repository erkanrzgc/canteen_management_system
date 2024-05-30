#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Product class
class Product {
protected:
    string name;
    float price;

public:
    Product();
    Product(string name, float price);
    virtual void print();
    virtual void save(ofstream& file);
    string getName();
    float getPrice();
    virtual ~Product();
};

// Beverage class (inheritance from Product class)
class Beverage : public Product {
private:
    float volume;

public:
    Beverage(string name, float price, float volume);
    void print() override;
    void save(ofstream& file) override;
};

// Food class (inheritance from Product class)
class Food : public Product {
private:
    string type;

public:
    Food(string name, float price, string type);
    void print() override;
    void save(ofstream& file) override;
};

// Canteen class
class Canteen {
private:
    vector<Product*> products;

public:
    void addProduct(Product* product);
    void listBeverages();
    void listFoods();
    Product* getProduct(int index);
    void saveProducts(string fileName);
    ~Canteen();
};

#endif // PRODUCT_H
