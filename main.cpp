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
 
 Line(int x1, int y1, int z1, int x2, int y2, int z2): Point(x1,y1,z1), p(x2,y2,z2) { updateLength(); } 
 
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

class Rectangle: public Line {
private:
    Point p3, p4;
    double area;
public:
    Rectangle(): Line(), p3(0,0,0), p4(0,0,0), area(0) {}

    Rectangle(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4): Line(x1, y1, z1, x2, y2, z2), p3(x3, y3, z3), p4(x4, y4, z4) { updateArea();}
    
    int getP3X() const { return p3.getX(); }
    int getP3Y() const { return p3.getY(); }
    int getP3Z() const { return p3.getZ(); }
    
    int getP4X() const { return p4.getX(); }
    int getP4Y() const { return p4.getY(); }
    int getP4Z() const { return p4.getZ(); }

    void setP3X(int newX) { p3.setX(newX); updateArea(); }
    void setP3Y(int newY) { p3.setY(newY); updateArea(); }
    void setP3Z(int newZ) { p3.setZ(newZ); updateArea(); }
    
    void setP4X(int newX) { p4.setX(newX); updateArea(); }
    void setP4Y(int newY) { p4.setY(newY); updateArea(); }
    void setP4Z(int newZ) { p4.setZ(newZ); updateArea(); }

    double getArea() const { return area; }
    void updateArea() {
        // Координаты всех точек прямоугольника
        int Ax = getX(), Ay = getY(), Az = getZ();
        int Bx = getpX(), By = getpY(), Bz = getpZ();
        int Cx = p3.getX(), Cy = p3.getY(), Cz = p3.getZ();
        int Dx = p4.getX(), Dy = p4.getY(), Dz = p4.getZ();
    
        // Векторы AB и BC (стороны прямоугольника)
        int ABx = Bx - Ax, ABy = By - Ay;
        int BCx = Cx - Bx, BCy = Cy - By;
    
        // Проверка условий:
        // 1. Все точки в одной плоскости (Z одинаковы)
        bool isFlat = (Az == Bz) && (Bz == Cz) && (Cz == Dz);
        
        // 2. Стороны AB и BC перпендикулярны (скалярное произведение = 0)
        bool isPerpendicular = (ABx * BCx + ABy * BCy) == 0;
    
        if (isFlat && isPerpendicular) {
            double lengthAB = sqrt(ABx*ABx + ABy*ABy);
            double lengthBC = sqrt(BCx*BCx + BCy*BCy);
            area = lengthAB * lengthBC;
        } else {
            area = -1; // криво
        }
    }


};

class Parallelepiped: public Rectangle {

};

int main() {
    Rectangle rect1(0,0,0, 2,0,0, 3,3,0, 1,3,0);
    cout << "Area 1: " << rect1.getArea() << endl;  

    Rectangle rect2(1,1,1, 4,1,1, 4,5,1, 1,5,1);
    cout << "Area 5: " << rect2.getArea() << endl; 

    return 0;
}
