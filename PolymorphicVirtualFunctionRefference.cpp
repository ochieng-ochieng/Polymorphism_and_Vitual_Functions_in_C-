
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

//use a Base class reference parameter
void f(Base &r)
{
    r.vfunc();
}

int main()
{
   Base b;
   Derived1 d1;
   Derived2 d2;

   f(b);//pass a Base object to f()
   f(d1);//pass a Derived1 object to f()
   f(d2);//pass a Derived2 object to f()

    return 0;
}
