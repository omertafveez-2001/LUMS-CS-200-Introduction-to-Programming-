#include <iostream>
using namespace std;

class Movie
{
    private:
        string title;
        string year;
        string *rating;
    public:
        Movie();
        Movie(string t, string y);

        void setTitle(string a);
        void setYear(string b);
        string getTitle();
};

Movie::Movie()
{
    title="\0";
    year = "\0";
}

Movie::Movie(string t, string y)
{
    title = t;
    year = y;
}

void Movie::setTitle(string a)
{
    title = a;
}

void Movie::setYear(string a)
{
    year = a;
}

string Movie::getTitle()
{
    return title;
}

int main()
{
    Movie *movie[5];
    string movietitle;
    for(int i = 0; i<5; i++)
    {
        cout << "Enter Movie title: ";
        cin >> movietitle;
        movie[i] = new Movie;
        movie[i]->setTitle(movietitle);
        cout << "Movie " << i+1 << " title: " << movie[i]->getTitle() << endl; 
    }
    cout << endl;
    cout << "System Terminated" << endl;
}