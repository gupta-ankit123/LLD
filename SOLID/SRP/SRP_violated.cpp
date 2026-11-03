#include <iostream>
#include <vector>

using namespace std;

// Product class representing item of any ECommerce:

class Product
{
public:
    string name;
    double price;

    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

// Violating SRP (Shopping Cart class handling many responsibilities)

class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addProduct(Product *p)
    {
        products.push_back(p);
    }

    const vector<Product *> &getProducts()
    {
        return products;
    }

    // 1. Calculate total price of the cart
    double calculateTotal()
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }

    // 2. print invoice (Violating SRP it should be a separate class)
    void printInvoice()
    {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : products)
        {
            cout << p->name << " - $ " << p->price << endl;
        }
        cout << "Total $" << calculateTotal() << endl;
    }

    // 3. Saving to the DB(again violating the SRP)
    void saveToDB()
    {
        cout << "Saving to the Database....." << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 15000));
    cart->addProduct(new Product("Tablet", 25000));

    cart->printInvoice();
    cart->saveToDB();
    return 0;
}