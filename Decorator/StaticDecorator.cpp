#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Shape
{
    virtual string str() const = 0;
};


struct Circle : Shape
{
  float radius;

  Circle(){}

  Circle(float radius) : radius(radius){}

  void resize(float factor)
  {
    radius *= factor;
  }

  string str() const override
  {
    ostringstream oss;
    oss << "A circle of radius " << radius;
    return oss.str();
  }
};

struct Square : Shape
{
  float side;

  Square(){}

  Square(float side) : side(side){}

  string str() const override
  {
    ostringstream oss;
    oss << "A square of with side " << side;
    return oss.str();
  }
};

struct ColoredShape : Shape
{
    Shape& shape;
    string color;

    ColoredShape(Shape& shape, const string& color): shape{shape}, color{color}{}

  string str() const override
  {
    ostringstream oss;
    oss << shape.str() << " has the color " << color;
    return oss.str();
  }
};

struct TransparentShape : Shape
{
  Shape& shape;
  uint8_t transparency;


  TransparentShape(Shape& shape, const uint8_t transparency)
    : shape{shape},
      transparency{transparency}
  {
  }

  string str() const override
  {
    ostringstream oss;
    oss << shape.str() << " has "
      << static_cast<float>(transparency) / 255.f*100.f
      << "% transparency";
    return oss.str();
  }
};

template <typename T> struct ColoredShape2 : T
{
    static_assert(is_base_of<Shape, T>::value, "Template argument must be a Shape");
     
    string color;
    ColorShape2() {}

    // TransparentShape2<ColoredShape2<Square>> sq{10, "red", 44}
    template <typename...Args>
    ColoredShape2(const string& color, Args ...args)
     : T(std::forward<Args>(args)...), color{color}{}



    string str() const override
  {
    ostringstream oss;
    oss << T::str() << " has the color "<<color;
    return oss.str();
  }
};

template <typename T> struct TransparentShape2 : T
{
    //簡單的說就是用來檢驗一個statement的值，預期這個值為true，如果不為true則產生runtime error：
    static_assert(is_base_of<Shape, T>::value, "Template argument must be a Shape");
     
    uint8_t transparency;
    ColorShape2() {}

    // TransparentShape2<ColoredShape2<Square>> sq{10, "red", 44}
    template <typename...Args>
    TransparentShape2(const uint8_t transparency, Args ...args)
     : T(std::forward<Args>(args)...), transparency{transparency}{}
     


    string str() const override
  {
    ostringstream oss;
    oss << T::str() << " has "
        << static_cast<float>(transparency) / 255.f*100.f
        << "% transparency";
    return oss.str();
  }
};

int main(){
    ColoredShape2<Circle> green_circle{"green", 5};
    
    cout<< green_circle.str() <<endl;
    TransparentShape2<ColoredShape2<Square>> temp{40,"green", 5};
    cout<< temp.str() <<endl;
    system("pause");
}