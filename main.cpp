#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Point {
protected:
    int x, y, z;

public:
    Point() : x(0), y(0), z(0) {}

    Point(int xx, int yy, int zz) :x(xx), y(yy), z(zz) {}
    
    int getX() const { return x; }
    int getY() const { return y; }
    int getZ() const { return z; }

    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
    void setZ(int newZ) { z = newZ; }

    void printP() const {
        cout << "x = " << x << "; y = " << y << "; z = " << z << "." << endl;
    }

   

};

class Line : public Point {
private:
 Point p;
 double length;
 
public:
 Line(): Point(), p(0,0,0), length(0) {}
 
 Line(int x1, int y1, int z1, int x2, int y2, int z2): Point(x1,y1,z1), p(x2,y2,z2) {length = sqrt(pow(p.getX() - x, 2) + pow(p.getY() - y, 2) + pow(p.getZ() - z, 2));} 
 
 int getpX() const { return p.getX(); }
 int getpY() const { return p.getY(); }
 int getpZ() const { return p.getZ(); }
 double getLenght() const { return length; }
 
 void updateLength () {
  length = sqrt(pow(p.getX() - x, 2) + pow(p.getY() - y, 2) + pow(p.getZ() - z, 2));
 }
 
 void setpX(int newX) { p.setX(newX); updateLength();}
 void setpY(int newY) { p.setY(newY); updateLength();}
 void setpZ(int newZ) { p.setZ(newZ); updateLength();}

 
 void printL() const {
  cout<< "1st point: "<<x<<", "<<y<<", "<<z<<". 2nd point: "<<p.getX()<<", "<<p.getY()<<", "<<p.getZ()<<". Length: "<<length<<endl;
 }
 
};

int main()
{
 Line line1(1,2,3,4,5,6);
 line1.printL();
    return 0;
}
