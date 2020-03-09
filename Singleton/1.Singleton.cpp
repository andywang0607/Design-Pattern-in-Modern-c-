#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <memory>
#include <vector>
using namespace std;

class SingletonDatabase{
    SingletonDatabase()
    {
        cout<<"Intializing database"<<endl;
        ifstream ifs("capitals.txt");
        string s, s2;
        while(getline(ifs,s)){
            getline(ifs,s2);
            int pop = stoi(s2);
            capitals[s]=pop;
        }
    }
    map<string,int> capitals;
public:
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator = (SingletonDatabase const&) = delete;

    static SingletonDatabase& get(){
        static SingletonDatabase db;
        return db;
    }
    int get_population(const string& name){
        return capitals[name];
    }
};
int main(){
    //string city = "Tokyo";
    vector <string> city;
    city.push_back("Tokyo");
    city.push_back("New York");
    for(auto cityname : city){
    cout<<cityname<<"has population"<<endl<<
        SingletonDatabase::get().get_population(cityname)<<endl;
    }
        system("pause");
        return 0;
}
