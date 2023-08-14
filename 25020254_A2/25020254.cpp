#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Student
{
    private:
        string rollnumber;
        string name;
        int coursesnumber;
        string *coursecodes;
        char *coursegrades;
        int size;
        
    public:
        //constructor and destructor
        Student();
        ~Student();
        Student(string rn, string n, int cn, string cc[], char cg[]);

        //setters
        void setRollNumber(string n);
        void setName(string n);
        void setCourseNumber(int n);
        void setCourseCode(string a[], int n);
        void setCourseGrade(char g[], int n);

        //getter
        string getRolln();
        string getName();
        int getCourseNumber();
        string* getCodes();
        char* getGrades();

        //helper function
        bool checkRollNumber(string a);
        bool verifyRollNumber(Student rhs[], int n);
        void setData(string r, string n, int cn, string co[], char gr[]);
        
        //overloading << operator
};

//Constructor
Student::Student()
{
    rollnumber = "\0";
    name = "\0";
    coursesnumber = 0;
    size=100;
    coursecodes = new string [size];
    coursegrades = new char [size];
}

//parameterized constructors
Student::Student(string n, string a, int cn, string cc[], char cg[])
{
    rollnumber = n;
    name = a;
    coursesnumber = cn;
    for(int i = 0; i < cn; i++)
    {
        coursecodes[i] = cc[i];
        coursegrades[i] = cg[i];
    }
}


//destructor
Student::~Student()
{
   delete [] coursecodes;
   delete [] coursegrades;
}

//setting roll number
void Student::setRollNumber(string a)
{
    bool check = checkRollNumber(a);
    if(check==true)
    {
        rollnumber = a;
    }
    else
    {
        cout << "Wrong Number Format." << endl;
    }
}

// setting the number of courses.
void Student::setCourseNumber(int a)
{
    coursesnumber = a;
}

//setting name of the student
void Student::setName(string na)
{
    name = na;
}

//setting the courses' codes
void Student::setCourseCode(string c[], int n)
{
    for(int i = 0; i < n; i++)
    {
        coursecodes[i] = c[i];
    }
}

//setting the course's grades.
void Student::setCourseGrade(char c[], int n)
{
    for(int i = 0; i<n; i++)
    {
        coursegrades[i] = c[i];
    }
}

//getting name
string Student::getName()
{
    return name;
}

//getting roll number
string Student::getRolln()
{
    return rollnumber;
}

//getting course numbers
int Student::getCourseNumber()
{
    return coursesnumber;
}

//getting course grades.
char* Student::getGrades()
{
    return coursegrades;
}

//getting codes.
string* Student::getCodes()
{
    return coursecodes;
}

//checking the rollnumber (boolean)
bool Student::checkRollNumber(string a)
{
    if(a.length()==8)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Student::verifyRollNumber(Student rhs[], int n)
{
    for(int i = 0; i<n;i++)
    {
        if(rollnumber==rhs[i].rollnumber)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

//setting data in one function
void Student::setData(string r, string na, int cn, string co[], char gr[])
{
    setRollNumber(r);
    setName(na);
    setCourseNumber(cn);
    for(int i=0; i<cn;i++)
    {
        setCourseCode(co, cn);
        setCourseGrade(gr, cn);
    }

}

//Database Class
class Database
{
    private:
        Student *students;
        int size;
        int counting = 0;
    public:
        Database();
        ~Database();

        //helper function
        void add(Student object);
        void remove(string roll);
        void update(string id, string code, char grade);
        void dump(string filename);
        int getCount();
        Student& operator [](const string& rolln);

};
Student& Database :: operator [](const string& rollnumber)
{
    bool check = false;
    for(int i = 0; i<counting;i++)
    {
        if(students[i].getRolln()==rollnumber)
        {
            cout << students[i].getRolln() << endl;
            cout << students[i].getName() << endl;
            cout << students[i].getCourseNumber() << endl;
            char* a = students[i].getGrades();
            string *b = students[i].getCodes();
            for(int j = 0; j<students[i].getCourseNumber()-1;j++)
            {
                cout << b[j] << ", ";
            }
            cout << b[students[i].getCourseNumber()-1] << endl;
            for(int j = 0; j<students[i].getCourseNumber()-1;j++)
            {
                cout << a[j] << ", ";
            }
            cout << a[students[i].getCourseNumber()-1] << endl;
            check = true;
        }
    }
    if(!check)
    {
        cout << "Student not found" << endl;
    }
}

void Database::update(string id, string code, char grade)
{
    bool check = false;
    for(int i = 0; i<counting;i++)
    {
        if(students[i].getRolln()==id)
        {
            students[i].setCourseNumber(students[i].getCourseNumber()+1);
            int coursenumber = students[i].getCourseNumber();
            string *codes = new string [coursenumber];
            codes = students[i].getCodes();
            char * grades = new char [coursenumber];
            grades = students[i].getGrades();
            codes[coursenumber-1] = code;
            grades[coursenumber-1] = grade;
            students[i].setCourseCode(codes, coursenumber);
            students[i].setCourseGrade(grades, coursenumber);
            check = true;
        }
    }
    if(!check)
    {
        cout << "Student not found" << endl;
    }
}

int Database::getCount()
{
    return counting;
}

void Database::remove(string roll)
{
    bool check = false;
    for(int i = 0;i<counting;i++)
    {
        if(students[i].getRolln()==roll)
        {
            counting= counting - 1;
            if(i!=counting)
            {
                for (int j=i; j<counting; j++)
                {
                    students[j].setData(students[j+1].getRolln(), students[j+1].getName(), students[j+1].getCourseNumber(),
                    students[j+1].getCodes(), students[j+1].getGrades());
                    check = true;
                }
            }
            else
            {
                check = true;
            }
        }
    }
    if(!check)
    {
        cout << "Student not found" << endl;
    }
}
void Database::dump(string filename)
{
    ofstream outputfile(filename);
    for(int i = 0; i<counting;i++)
    {
        outputfile << students[i].getRolln() << endl;
        outputfile << students[i].getName() << endl;
        outputfile << students[i].getCourseNumber() << endl;
        char* a = students[i].getGrades();
        string *b = students[i].getCodes();
        for(int j = 0; j<students[i].getCourseNumber()-1;j++)
        {
            outputfile << b[j] << ", ";
        }
        outputfile << b[students[i].getCourseNumber()-1] << endl;
        for(int j = 0; j<students[i].getCourseNumber()-1;j++)
        {
            outputfile << a[j] << ", ";
        }
        outputfile << a[students[i].getCourseNumber()-1] << endl;
    }
}


Database::Database()
{
    size = 100;
    students = new Student [size];
}

Database::~Database()
{
    delete [] students;
}

//adding data
void Database::add(Student object)
{
    students[counting].setData(object.getRolln(),object.getName(), object.getCourseNumber(), object.getCodes(), object.getGrades());
    counting++;
}

int main()
{
   
    //initialising objects of the classes
    Database d1;
    Student s1;

    //reading file
    fstream file;
    string word,filename, first, second, third;
 
    // filename of the file
    filename = "commands.txt";
 
    // opening file
    file.open(filename.c_str());
 
    // extracting words from the file
    while (file >> word)
    {
        if(word=="INSERT")
        {
           file>>first;
           file>>second;
           s1.setData(first, second, 0, 0, 0);
           d1.add(s1);
          
        }
        else if(word=="DELETE")
        {
            file>>first;
            d1.remove(first);
        }
        else if(word=="UPDATE")
        {
            file>>first;
            file>>second;
            file>>third;
            char grade = third[0];
            d1.update(first, second, grade);
        }
        else if(word=="DUMP")
        {
            file>>first;
            d1.dump(first);

        }
    }
}