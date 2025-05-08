#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Product class to represent individual product data
class Product {
public:
    string name;
    int quantity;
    float price;

    Product(string n, int q, float p) : name(n), quantity(q), price(p) {}

    void displayProduct() const {
        cout << "Product: " << name << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }
};

// Inventory class to manage product collection and file operations
class Inventory {
private:
    vector<Product> products;

    // Private method to load products from file into vector
    void loadFromFile() {
        ifstream file("inventory.txt");
        string name;
        int qty;
        float price;

        while (file >> name >> qty >> price) {
            products.push_back(Product(name, qty, price));
        }
        file.close();
    }

    // Private method to save products to file
    void saveToFile() {
        ofstream file("inventory.txt", ios::trunc); // Open file in overwrite mode
        for (const auto& product : products) {
            file << product.name << " " << product.quantity << " " << product.price << endl;
        }
        file.close();
    }

public:
    Inventory() {
        loadFromFile();  // Load inventory from file on object creation
    }

    // Method to add a new product to the inventory
    void addProduct() {
        string name;
        int qty;
        float price;

        cout << "Enter product name: ";
        cin >> name;
        cout << "Enter quantity: ";
        cin >> qty;
        cout << "Enter price: ";
        cin >> price;

        Product newProduct(name, qty, price);
        products.push_back(newProduct);
        saveToFile(); // Save updated inventory to file
    }

    // Method to display all products in inventory
    void viewInventory() const {
        if (products.empty()) {
            cout << "Inventory is empty!" << endl;
        } else {
            for (const auto& product : products) {
                product.displayProduct();
            }
        }
    }
};

// Main function to drive the inventory system
int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "\n1. Add Product\n2. View Inventory\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            inventory.addProduct();
        } 
        else if (choice == 2) {
            inventory.viewInventory();
        }

    } while (choice != 3);

    return 0;
}