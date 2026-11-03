#include <iostream>
#include <vector>

using namespace std;

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
    double claculateTotal(vector<Product *> products)
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }
};

class ShoppingCartInvoice
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartInvoice(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void printInvoice()
    {
        for (auto p : cart->getProducts())
        {
            cout << p->name << " - $ " << p->price << endl;
        }
        cout << "Total $" << cart->claculateTotal(cart->getProducts()) << endl;
    }
};

// This is violating the open close principle as we are modifying the existing class to add new functionality.

class ShoppingCartStorage
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartStorage(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void saveToDB()
    {
        cout << "Saving to the database...." << endl;
    }
    void saveToMongoDB()
    {
        cout << "Saving to Mongo DB...." << endl;
    }
    void saveToFIle()
    {
        cout << "Saving to File..." << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Product 1", 100));
    cart->addProduct(new Product("Product 2", 200));

    ShoppingCartInvoice *invoice = new ShoppingCartInvoice(cart);
    invoice->printInvoice();

    ShoppingCartStorage *storage = new ShoppingCartStorage(cart);
    storage->saveToDB();
    storage->saveToFIle();
    storage->saveToMongoDB();

    return 0;
}