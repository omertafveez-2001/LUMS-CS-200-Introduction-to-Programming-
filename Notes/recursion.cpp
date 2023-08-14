#include <iostream>
using namespace std;

int recursive(int n)
{
    if (n<0)
    {
        return -1;
    }
    else if(n==0)
    {
        return 1;
    }
    else
    {
        return n*recursive(n-1);
    }
}

int main()
{
    int a = 4;
    cout << recursive(a);
}