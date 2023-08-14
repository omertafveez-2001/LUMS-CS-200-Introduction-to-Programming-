#include <iostream>
using namespace std;


//counting from n to 0
int reverseCounting(int n)
{
    if(n<0)
    {
        return -1;
    }
    else
    {
        cout << n;
        reverseCounting(n-1);
    }
}

int factorial(int n)
{
    if(n<0)
    {
        return -1;
    }
    else if(n==0 || n==1)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }
}

int fibonnaciNumber(int n)
{
    if(n==0)
    {
       return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return fibonnaciNumber(n-1) + fibonnaciNumber(n-2);
    }
}

void print(char* str)
{
    static int count = 0;
    if(str[count]=='\0')
    {
        return;
    }
    else
    {
        count++;
        print(str);
        cout << str[count];
        count--;
        if(count==0)
        {
            cout << str[count];
        }
    }
}

int sortedAscending(int arr[])
{
    static int count = 0;
    static int maximum = 0;
    
}

/*bool isPalindrome(char* a)
{
    static int count = 0;
    if(a[count]=='\0')
    {
        return;
    }
    else
    {

    }
}*/

int main()
{
    reverseCounting(5);
    cout << endl;
    cout << "Factorial is:" << factorial(4) << endl;
    cout << "The nth term of the fibonacci sequence is: " << fibonnaciNumber(3) << endl;
    char chars [] = "omer";
    print(chars);
}