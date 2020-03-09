#define _USE_MATH_DEFINES //FOR PI
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

class Point{
private:
        float x,y;
        Point(float x, float y) : x(x), y(y){} ;
public:
    // Inner Factory enable to private constructor
    //Point(float x, float y) : x(x), y(y){}

    friend ostream &operator<<(ostream &os,const Point p){
        os<<"x: "<<p.x<<"y: "<<p.y<<endl;
        return os;
    }
private:
    class PointFactory{
        PointFactory(){}
    public:
        static Point NewCartesian(float x, float y){
            return {x, y};
        }
        static Point NewPolar(float r, float theta){
            return {r*cos(theta), r*sin(theta)};
        }
    };
public:
    static PointFactory Factory;
};

int main(){
    // if PointFactory is public
    // auto p1 = Point::PointFactory::NewPolar(5,M_PI_4);
    // if PointFactory is private -> Need to create a static instance
    auto p1 = Point::Factory.NewPolar(5,M_PI_4);
    cout<<p1;
    system("pause");
    return 0;
}
