#include<iostream>
using namespace  std;

//This is an Abstract base class due to having a pure virtual function.
class CPolygon{
protected:
    float height, width;

public:
    void setWidth(float w)
    {
        width = w;
    }
    float getWidth()
    {
        return width;
    }

    void setHeight(float h)
    {
        height = h;
    }
    float getHeight()
    {
        return height;
    }
    virtual float area() = 0;
};

//Below is another Abstract base class due to having a pure virtual function.
class Volume{
protected:
    float radius;

public:
    static float PI;
    void setRadius(float r)
    {
        radius = r;
    }
    float getRadius()
    {
        return radius;
    }
    virtual float volume() = 0;
};

float Volume::PI = (22/7);

//Below is a blue print of calculating the area of a rectangle
class AreaRectangle: public CPolygon{
public:
    float area()
    {
        return (height * width);//These fields will have different  values
    }
};

//Below is a blue print of calculating the area of a triangle
class AreaTriangle: public CPolygon{
public:
    float area()
    {
        return (1 / 2.0 * height * width);
    }
};

//Below is a blue print of calculating the area of a square
class AreaSquare: public CPolygon{
public:
    float area()
    {
        return (height * width);//These fields will have the same  values
    }
};

//Below is a blue print of calculating the area of a cylinder
class AreaCylinder: public CPolygon, public Volume{
public:
    float area()
    {
        return (2 * PI * radius * height);
    }
    float volume()
    {
        return 0;
    }
};

//Below is a blue print of calculating the volume of a cylinder
class VolumeCylinder: public CPolygon, public Volume{
public:
    float volume()
    {
        return (PI * radius * radius * height);
    }
    float area()
    {
        return 0;
    }
};

//Below is a blue print of calculating the volume of a sphere
class VolumeSphere: public Volume{
public:
    float volume()
    {
        return (4 / 3.0 * PI * radius * radius * radius);
    }
};

int main()
{
    CPolygon *pa;
    Volume   *pv;

    AreaRectangle rectangle1;
    AreaTriangle  triangle1;
    AreaSquare    square1;
    AreaCylinder a_cylinder1;

    VolumeCylinder v_cylinder1;
    VolumeSphere v_sphere1;

    pa = &rectangle1;
    pa ->setHeight(4);
    pa ->setWidth(6);

    cout << "RECTANGLE"  << endl;
    cout << "HEIGHT IS " << pa ->getHeight() << endl;
    cout << "WIDTH IS "  << pa ->getWidth() << endl;
    cout << "AREA IS "   << pa ->area() << endl << endl;

    pa = &triangle1;
    pa ->setHeight(8);
    pa ->setWidth(9);

    cout << "TRIANGLE" << endl;
    cout << "HEIGHT IS " << pa ->getHeight() << endl;
    cout << "BASE IS "   << pa ->getWidth() << endl;
    cout << "AREA IS "   << pa ->area() << endl << endl;

    pa = &square1;
    pa ->setHeight(10);
    pa ->setWidth(10);

    cout << "SQUARE" << endl;
    cout << "SIDE1 IS " << pa ->getHeight() << endl;
    cout << "SIDE2 IS " << pa ->getWidth() << endl;
    cout << "AREA IS "  << pa ->area() << endl << endl;

    pa = &a_cylinder1;
    pv = &a_cylinder1;

    pv ->setRadius(12);
    pa ->setHeight(5);

    cout << "AREA CYLINDER" << endl;
    cout << "RADIUS IS " << pv ->getRadius() << endl;
    cout << "HEIGHT IS " << pa ->getHeight() << endl;
    cout << "AREA IS "   << pa ->area() << endl << endl;

    pa = &v_cylinder1;
    pv = &v_cylinder1;

    pv ->setRadius(14);
    pa ->setHeight(15);

    cout << "VOLUME  CYLINDER" << endl;
    cout << "RADIUS IS " << pv ->getRadius() << endl;
    cout << "HEIGHT IS " << pa ->getHeight() << endl;
    cout << "VOLUME IS " << pv ->volume() << endl << endl;


    pv = &v_sphere1;
    pv ->setRadius(16);



    cout << "VOLUME SPHERE" << endl;
    cout << "RADIUS IS "  << pv ->getRadius() << endl;
    cout << "VOLUME  IS " << pv ->volume() << endl << endl;





    return 0;
}

