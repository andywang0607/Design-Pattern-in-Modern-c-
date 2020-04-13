#include <iostream>
#include <algorithm>
using namespace std;


template<typename T> struct Property
{
    T value;

    Property(T value)
    {
        *this = value;
    }
    T operator = (T new_value)
    {
        cout << "Assignment!" << endl;
        return value = new_value;
    }
    friend ostream &operator <<(ostream &os, const Property &property){
        os<<property.value;
        return os;
    }
};
struct Creature
{
    /* Proxy
    int strength{10};
    int agility{5};
    */
   Property<int> strength{10};
   Property<int> agility{5};
};

int main()
{
    Creature c;
    cout<<"strength: "<<c.strength<<endl<<"agility: "<<c.agility<<endl;
    c.strength = 15;
    cout<<"strength: "<<c.strength<<endl<<"agility: "<<c.agility<<endl;
    system("pause");
    return 0;
}