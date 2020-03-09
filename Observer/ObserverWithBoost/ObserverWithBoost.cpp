#include <string>
#include <iostream>

using namespace std;

#include "boost/signals2.hpp"
using namespace boost;
using namespace boost::signals2;
template <typename T>
struct Observable2
{
    // Signal
    signal<void(T&, const string&)> field_changed;

};
class Person2 :public Observable2<Person2>
{
    int age;
public:
    int get_age() const {
        return age;
    }
    void set_age(int age) {
        if (this->age == age) return;
        this->age = age;
        field_changed(*this, "age");
    }
};
/* the argument need to be same as field_changed
void slot_function(Person2& p, const string& field_name) {
    cout << "has changed to" << p.get_age() << endl;
}
*/
int main() {
    Person2 p2;
    auto conn = p2.field_changed.connect(
        // create lambda function for slot function
        [](Person2& p, const string& field_name) {
        cout << field_name << "has changed to"<<p.get_age()<<"\n";
    }
    );
    // auto conn = p2.field_changed.connect(slot_function);
    p2.set_age(20);
    conn.disconnect();
    system("pause");
    return 0;
}
