// or  Q2. Create a class String which contains a character pointer (Use new and delete operator). Write a
// C++ program to overload following operators:
// a. < To compare length of two strings
// b. == To check equality of two strings
// c. + To concatenate two strings
#include <iostream>
#include <cstring>
using namespace std;

class String {
   private:
      char *str;

   public:
      String() {
         str = new char[1];
         *str = '\0';
      }

      String(const char *s) {
         str = new char[strlen(s) + 1];
         strcpy(str, s);
      }

      String(const String& s) {
         str = new char[strlen(s.str) + 1];
         strcpy(str, s.str);
      }

      ~String() {
         delete[] str;
      }

      int length() const {
         return strlen(str);
      }

      bool operator<(const String& s) const {
         return strlen(str) < strlen(s.str);
      }

      bool operator==(const String& s) const {
         return strcmp(str, s.str) == 0;
      }

      String operator+(const String& s) const {
         char *temp = new char[strlen(str) + strlen(s.str) + 1];
         strcpy(temp, str);
         strcat(temp, s.str);
         String result(temp);
         delete[] temp;
         return result;
      }

      void display() const {
         cout << str;
      }
};

int main() {
   String s1("Hello"), s2("World"), s3;
   s3 = s1 + s2;

   cout << "s1: ";
   s1.display();
   cout << endl;

   cout << "s2: ";
   s2.display();
   cout << endl;

   cout << "s3: ";
   s3.display();
   cout << endl;

   if (s1 < s2) {
      cout << "s1 is shorter than s2" << endl;
   } else {
      cout << "s1 is not shorter than s2" << endl;
   }

   if (s1 == s2) {
      cout << "s1 is equal to s2" << endl;
   } else {
      cout << "s1 is not equal to s2" << endl;
   }

   if (s1 == String("Hello")) {
      cout << "s1 is equal to \"Hello\"" << endl;
   } else {
      cout << "s1 is not equal to \"Hello\"" << endl;
   }

   return 0;
}
