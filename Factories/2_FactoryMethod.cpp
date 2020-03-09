#define _USE_MATH_DEFINES //FOR PI
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>


using namespace std;

enum class PointType{
    CARTESIAN,
    POLAR,
};

class Point{
private:
        float x,y;
public:
    Point(float x, float y) : x(x), y(y){}
    static Point NewCartesian(float x, float y){
        return {x, y};
    }
    static Point NewPolar(float r, float theta){
        return {r*cos(theta), r*sin(theta)};
    }
    friend ostream &operator<<(ostream &os,const Point p){
        os<<"x: "<<p.x<<"y: "<<p.y<<endl;
        return os;
    }
};
int main(){
    auto p1 = Point::NewPolar(5,M_PI_4);
    auto p2 = Point::NewCartesian(5,5);
    cout<<p1;
    cout<<p2;
    system("pause");
    return 0;
}
