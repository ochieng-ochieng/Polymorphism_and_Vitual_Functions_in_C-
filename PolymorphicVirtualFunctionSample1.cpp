#include<iostream>
using namespace  std;

class Base{
public:
   virtual  void vfunc()
   {
       cout << "This is a Base vfunc().\n";
   }
};

class Derived1 : public Base{
public:
    virtual  void vfunc()
   {
       cout << "This is Derived1 vfunc().\n";
   }
};

class Derived2 : public Base{
public:
    virtual  void vfunc()
   {
       cout << "This is Derived2 vfunc().\n";
   }
};

int main()
{
   Base *p, b;
   Derived1 d1;
   Derived2 d2;

   //point to Base
   p = &b;
   p -> vfunc(); //access Base's vfunc()

   //point to Derived1
   p = &d1;
   p ->vfunc();//access Derived1 vfunc()

   //point to Derived2
   p = &d2;
   p ->vfunc();//access Derived1 vfunc()

    return 0;
}
