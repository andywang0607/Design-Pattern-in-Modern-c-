#define _USE_MATH_DEFINES //FOR PI
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

class Point{
private:
        float x,y;
public:
    Point(float x, float y) : x(x), y(y){}

    friend ostream &operator<<(ostream &os,const Point p){
        os<<"x: "<<p.x<<"y: "<<p.y<<endl;
        return os;
    }
};
struct PointFactory{
    static Point NewCartesian(float x, float y){
        return {x, y};
    }
    static Point NewPolar(float r, float theta){
        return {r*cos(theta), r*sin(theta)};
    }
};
int main(){
    auto p1 = PointFactory::NewPolar(5,M_PI_4);
    cout<<p1;
    system("pause");
    return 0;
}
