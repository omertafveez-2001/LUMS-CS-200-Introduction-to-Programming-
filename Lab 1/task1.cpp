#include <iostream>
using namespace std;

struct Student 
{
    string name;
    int salary;
    double balance;
};

void getData(Student& account)
{
    cout << "Name";
    cin >> account.name;
    cout << "Salary:";
    cin >> account.salary;
}



int main()
{
    Student s1;
    getData(s1);
}