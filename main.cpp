#include "Product.h"

int main() {
    // Create a canteen object
    Canteen canteen;

    // Create products
    Product* water = new Beverage("Water", 2.0, 500);
    Product* lemonade = new Beverage("Lemonade", 4.0, 300);
    Product* coffee = new Beverage("Coffee", 6.0, 250);
    Product* tea = new Beverage("Tea", 3.0, 200);
    Product* mixedJuice = new Beverage("Mixed Juice", 5.0, 350);

    Product* chips = new Food("Chips", 3.5, "Plain");
    Product* sandwich = new Food("Sandwich", 5.0, "Chicken");
    Product* toast = new Food("Toast", 4.0, "Cheese");
    Product* chocolate = new Food("Chocolate", 2.5, "Dark");
    Product* biscuit = new Food("Biscuit", 2.0, "Butter");
    Product* pastry = new Food("Pastry", 3.0, "Plain");

    // Add products to the canteen
    canteen.addProduct(water);
    canteen.addProduct(lemonade);
    canteen.addProduct(coffee);
    canteen.addProduct(tea);
    canteen.addProduct(mixedJuice);
    canteen.addProduct(chips);
    canteen.addProduct(sandwich);
    canteen.addProduct(toast);
    canteen.addProduct(chocolate);
    canteen.addProduct(biscuit);
    canteen.addProduct(pastry);

    // Save products to a file
    canteen.saveProducts("products.txt");

    vector<Product*> selectedProducts;

    // Menu for user to select
    int mainChoice, productChoice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. List Beverages\n";
        cout << "2. List Foods\n";
        cout << "0. Exit and Show Selected Products\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;
        cout << endl;

        if (mainChoice == 1) {
            while (true) {
                canteen.listBeverages();
                cout << "Enter the number of the beverage to select it (0 to go back): ";
                cin >> productChoice;
                cout << endl;
                if (productChoice == 0) break;
                // Check if the selected index is a beverage
                if (Product* selectedProduct = canteen.getProduct(productChoice - 1)) {
                    if (dynamic_cast<Beverage*>(selectedProduct)) {
                        selectedProducts.push_back(selectedProduct);
                        cout << selectedProduct->getName() << " has been selected." << endl;
                    } else {
                        cout << "Invalid choice. Please select a beverage." << endl;
                    }
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
                cout << endl;
            }
        } else if (mainChoice == 2) {
            while (true) {
                canteen.listFoods();
                cout << "Enter the number of the food to select it (0 to go back): ";
                cin >> productChoice;
                cout << endl;
                if (productChoice == 0) break;
                // Check if the selected index is a food
                if (Product* selectedProduct = canteen.getProduct(productChoice - 1)) {
                    if (dynamic_cast<Food*>(selectedProduct)) {
                        selectedProducts.push_back(selectedProduct);
                        cout << selectedProduct->getName() << " has been selected." << endl;
                    } else {
                        cout << "Invalid choice. Please select a food." << endl;
                    }
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
                cout << endl;
            }
        } else if (mainChoice == 0) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    // Show selected products and calculate total price
    float totalPrice = 0.0;
    cout << "\nSelected Products:\n";
    for (const auto& product : selectedProducts) {
        product->print();
        totalPrice += product->getPrice();
    }

    cout << "Total Price: " << totalPrice << " TL" << endl;

    return 0;
}
