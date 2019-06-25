#include<iostream>
using namespace  std;

//This is an Abstract class ,an abstract class contains
//at least one or more pure functions.
//You cannot create objects of an abstract class, you can
//create pointers and references to an abstract class.

class Number{
protected:
    int val;
public:
    void setVal(int i)
    {
        val = i;
    }
    //show() is a pure virtual function
    virtual void show() = 0;
};

class HexType : public Number{
public:
    void show()
    {
        cout << hex << val << endl;
    }
};

class DecType : public Number{
public:
    void show()
    {
        cout << val << endl;
    }
};

class OctType : public Number{
public:
    void show()
    {
        cout << oct << val << endl;
    }
};

int main()
{
    DecType d;
    HexType h;
    OctType o;

    d.setVal(20);
    d.show();//displays 20 decimal

    h.setVal(20);
    h.show();//displays 14

    o.setVal(20);
    o.show();//displays 24

    return 0;
}
