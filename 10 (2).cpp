// Q2. Design a base class Product(Product _Id, Product _Name, Price). Derive a class Discount
// (Discount_In_Percentage) from Product. A customer buys n Products. Calculate total price,
// total discount and display bill using appropriate manipulators.//error in program 
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Product {
   protected:
      int productId;
      string productName;
      float price;

   public:
      Product(int id, string name, float p) {
         productId = id;
         productName = name;
         price = p;
      }
};

class Discount : public Product {
   private:
      float discountPercentage;

   public:
      Discount(int id, string name, float p, float d) : Product(id, name, p) {
         discountPercentage = d;
      }

      float getDiscountedPrice() {
         return price - price * (discountPercentage / 100);
      }

      float getDiscountAmount() {
         return price * (discountPercentage / 100);
      }
};

int main() {
   vector<Discount> purchases;
   int n;

   cout << "Enter the number of products: ";
   cin >> n;

   for (int i = 0; i < n; i++) {
      int id;
      string name;
      float price, discount;

      cout << "Enter product ID: ";
      cin >> id;

      cout << "Enter product name: ";
      cin >> name;

      cout << "Enter price: ";
      cin >> price;

      cout << "Enter discount percentage: ";
      cin >> discount;

      Discount d(id, name, price, discount);
      purchases.push_back(d);
   }

   float totalPrice = 0;
   float totalDiscount = 0;

   cout << setw(10) << "Product ID" << setw(20) << "Product Name" << setw(10) << "Price" << setw(15) << "Discounted Price" << endl;
   cout << setfill('-') << setw(55) << "" << endl;
   cout << setfill(' ');

   for (int i = 0; i < purchases.size(); i++) {
      float discountedPrice = purchases[i].getDiscountedPrice();
      float discountAmount = purchases[i].getDiscountAmount();

      totalPrice += discountedPrice;
      totalDiscount += discountAmount;

      cout << setw(10) << purchases[i].productId << setw(20) << purchases[i].productName << setw(10) << purchases[i].price << setw(15) << discountedPrice << endl;
   }

   cout << setfill('-') << setw(55) << "" << endl;
   cout << setfill(' ');
   cout << setw(30) << "Total Price: " << setw(10) << totalPrice << endl;
   cout << setw(30) << "Total Discount: " << setw(10) << totalDiscount << endl;
   cout << setw(30) << "Amount Payable: " << setw(10) << totalPrice - totalDiscount << endl;

   return 0;
}
