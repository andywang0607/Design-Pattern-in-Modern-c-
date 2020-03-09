#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

enum class PointType{
    CARTESIAN,
    POLAR,
};

struct Point{
    // Point(float x, float y): x(x), y(y){}
    /* param a is either x or rho
     * param b is either y or theta
    */
    float x,y;
    Point(float a, float b, PointType type){
        switch (type) {
            case PointType::CARTESIAN:
                x=a;
                y=b;
                break;
            case PointType::POLAR:
                x=a*cos(b);
                y=a*sin(b);
                break;
        }
    }
};
int main(){
    Point p1 = Point(1,1,PointType::CARTESIAN);
    Point p2 = Point(2,3.1415926/4,PointType::POLAR);
    cout<<"p1"<<p1.x<<p1.y<<endl;
    cout<<"p2"<<p2.x<<p2.y<<endl;
    system("pause");
    return 0;
}
