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

    // Calculate total price of cart
    double calculateTotal()
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
        cout << "Total $" << cart->calculateTotal() << endl;
    }
};

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
        cout << "Saving cart to database...." << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Ghee", 25));
    cart->addProduct(new Product("Rice", 20));

    ShoppingCartInvoice *printer = new ShoppingCartInvoice(cart);
    printer->printInvoice();

    ShoppingCartStorage *storage = new ShoppingCartStorage(cart);
    storage->saveToDB();

    return 0;
}