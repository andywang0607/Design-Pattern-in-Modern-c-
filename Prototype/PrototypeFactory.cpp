#include <iostream>
#include <cstdio>
#include <tuple>
#include <sstream>
#include <cstdio>
#include <string>
#include <memory>
#include <cmath>

using namespace std;

/*
 * Want to create business card
 * include the following informaton
 * Name, Address, id
 * All information is same exceppt name and id
*/

struct Address
{
    string street;
    string city;
    int id;

    Address(const string& street, const string &city, int id)
    : street(street),
      city(city),
      id(id) {}

    Address(const Address& address)
    : street(address.street),
      city(address.city),
      id(address.id) {}

    friend ostream& operator<<(ostream& os, const Address& obj)
    {
      os << "street: " << obj.street
      << " city: " << obj.city
      << " id: " << obj.id;
        return os;
    }
};


struct Contact
{
    string name;
    Address* address;

    Contact(const string &name, Address* address)
    : name(name), address(address){}

    Contact(const Contact& other)
    : name{other.name}
    , address{ new Address{*other.address} }{

    }

    ~Contact() {delete address;}

    friend ostream& operator<<(ostream& os, const Contact& obj)
    {
      os << "name: " << obj.name
      << " address " << *obj.address; // note the star here
    return os;
    }
};

struct EmployeeFactory
{
    static unique_ptr<Contact> new_main_office_employee(const string& name, const int id)
    {
        static Contact p{"", new Address{"Easr Road", "London", 0}};
        return new_employee(name, id, p);
    }
private:
    static unique_ptr<Contact> new_employee(const string &name, const int id, const Contact& prototype)
    {
        auto result = make_unique<Contact>(prototype);
        result->name = name;
        result->address->id = id;
        return result;
    }
};

int main()
{
    auto john = EmployeeFactory::new_main_office_employee("John",1);
    auto jane = EmployeeFactory::new_main_office_employee("Jane",2);
    cout<<*john <<endl <<*jane<<endl;
    system("pause");
}