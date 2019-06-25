#include<iostream>
using namespace  std;

class Convert{
protected:
   double val1;//initial value
   double val2;//converted value
public:
    Convert(double i)
    {
        val1 = i;
    }
    double getconv()
    {
        return val2;
    }
    double getinit()
    {
        return val1;
    }
    virtual void compute() = 0;
};

//Liters to gallon.
class L_To_G : public Convert{
public:
    L_To_G(double i):Convert(i)
    {

    }
    void compute()
    {
        val2 = val1 / 3.7854;
    }
};

//Fahrenheit to Celcius
class F_To_C : public Convert{
public:
    F_To_C(double i):Convert(i)
    {

    }
    void compute()
    {
        val2 = (val1 - 32) / 1.8;
    }
};

int main()
{
    Convert *p; //pointer to Base class

    L_To_G  lgob(4);
    F_To_C  fcob(70);

    //use virtual function mechanism to convert
    p = &lgob;
    cout << p ->getinit() << " liters is ";
    p ->compute();
    cout << p->getconv() << " gallons\n"; // l_to_g

    p = &fcob;
    cout << p->getinit() << " in Fahrenheit is ";
    p->compute();
    cout << p->getconv() << " Celsius\n"; // f_to_c

    return 0;
}

