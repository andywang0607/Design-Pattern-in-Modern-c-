#include <iostream>
#include <algorithm>
using namespace std;

struct Pingable
{
    virtual wstring ping(const wstring& message) = 0;
};

struct Pong : Pingable
{
    wstring ping(const wstring& message) override
    {
        return message + L"pong";
    }
};

void tryit(Pingable& pp)
{
    wcout << pp.ping(L""ping) << endl;
}

int main()
{
    return 0;
}