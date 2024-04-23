// Q1. Write a C++ program to create a class Item with data members Item_code, Item_name, Item_Price.
// Write member functions to accept and display item information and also display number of objects
// created for a class. (Use Static data member and Static member function)
#include <iostream>
#include <string>

class Item {
private:
    int itemCode;
    std::string itemName;
    double itemPrice;
    static int numOfItems;

public:
    Item(int code, std::string name, double price) {
        itemCode = code;
        itemName = name;
        itemPrice = price;
        numOfItems++;
    }

    static int getCount() {
        return numOfItems;
    }

    void display() const {
        std::cout << "Item Code: " << itemCode << std::endl;
        std::cout << "Item Name: " << itemName << std::endl;
        std::cout << "Item Price: " << itemPrice << std::endl;
    }
};

int Item::numOfItems = 0; // initialize static member

int main() {
    Item item1(1001, "Item 1", 9.99);
    Item item2(1002, "Item 2", 19.99);

    item1.display();
    std::cout << std::endl;
    item2.display();
    std::cout << std::endl;

    std::cout << "Number of items created: " << Item::getCount() << std::endl;

    return 0;
}
