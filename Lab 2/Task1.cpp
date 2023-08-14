#include <iostream>
#include <string>
using namespace std;

class Student
{
    private:
        string name;
        int rollnumber;
        string major;
    
    public:
        Student();
        void setName(string s);
        void setRollNum(int r);
        void setMajor(string m);
        void getName();
        void getRollnum();
        void getMajor();
        void print();
        Student(string s, int r, string m);
};

Student::Student()
{
    name = "\0";
    rollnumber = 0;
    major = "\0";
}
Student::Student(string s, int r, string m)
{
    name = s;
    rollnumber = r;
    major = m;
}
void Student:: setName(string s)
{
    cout << "Name: ";
    getline(cin, s);
    name = s;
}
void Student:: setRollNum(int r)
{
    cout << "RollNumber: ";
    cin >> r;
    rollnumber = r;
}
void Student:: setMajor(string m)
{
    cout << "Major: ";
    cin.clear();
    cin.ignore();
    getline(cin, m);
    major = m;
}
void Student:: getName()
{
    cout << name << endl;
}
void Student:: getRollnum()
{
    cout << rollnumber << endl;
}
void Student:: getMajor()
{
    cout << major << endl;
}
void Student:: print()
{
    cout << "Name: " << name << endl;
    cout << "Roll Number: " << rollnumber << endl;
    cout << "Major: " << major << endl; 
}

int main()
{
    /*string studentname, studentmajor, studentname2, studentmajor2;
    int studentrollnum, studentrollnum2;*/
    Student s1;
    s1.print();
    /*Student s2;
    s1.setName(studentname);
    s1.setRollNum(studentrollnum);
    s1.setMajor(studentmajor);
    cout << endl;
    s2.setName(studentname2);
    s2.setRollNum(studentrollnum2);
    s2.setMajor(studentmajor2);
    s1.print();
    s2.print();*/
}