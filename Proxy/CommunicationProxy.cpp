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

int main()
{
    return 0;
}