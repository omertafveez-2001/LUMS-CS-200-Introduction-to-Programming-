#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
    protected:
        bool checkout;
        string unique_id;
        string name;
        string author;
        int issue;
        string *listid;
        string *names;
        string *authors;
        int *issues;
        bool *checkouts;
        int size;
        int count = 0;
        string *checkitems;
        int checkoutcount = 0;

    public:
        LibraryItem();
        LibraryItem(string u, string n, string a, int i);
        LibraryItem(const LibraryItem &rhs);
        virtual void checkOut() = 0;
        virtual void checkIn() = 0;
        void displayItemInfo();
        virtual void createItem();
        ~LibraryItem();
        virtual void searchItem(string a) = 0;
};

LibraryItem::~LibraryItem()
{
    delete [] listid;
    delete [] issues;
    delete [] authors;
    delete [] names;
    delete [] checkouts;
    delete [] checkitems;
}

void LibraryItem::displayItemInfo()
{
    for(int i = 0; i <count; i++)
    {
        cout << "Name: " << names[i] << endl;
        cout << "Author: " << authors[i] << endl;
        cout << "Unique ID: " << listid[i] << endl;
    }
}

void LibraryItem::createItem()
{
    string unique_input;
    bool unique_id = false;
    cout << "Enter the name: ";
    string name_input;
    cin.clear();
    cin.ignore();
    getline(cin,name_input);
    cout << "Enter the author: ";
    string author_input;
    getline(cin, author_input);
    while(!unique_id)
    {
        cout << "Unique ID: ";
        cin >> unique_input;
        for(int i = 0; i < size;i++)
        {
            if (listid[i]==unique_input)
            {
                unique_id = false;
                cout << "ID Already Exists/Invalid ID" << endl;
                break;
            }
            if(unique_input.length()!=6)
            {
                unique_id=false;
                cout << "ID Length should be of 6 characters, 2 letters followed by 4 digits." << endl;
                break;
            }
            unique_id = true;
        }
    }
    listid[count] = unique_input;
    names[count] = name_input;
    authors[count] = author_input;
    count++;
}

LibraryItem::LibraryItem()
{
    unique_id = "";
    name = "";
    author = "";
    issue = 0;
    size = 500;
    listid = new string [size];
    names = new string [size];
    authors = new string [size];
    issues = new int [size];
    checkouts = new bool [size];
    checkitems = new string [size];
    for(int i = 0; i<500;i++)  //initialising each issue as 0.
    {
        issues[i] = 0;
        checkouts[i] = false;
    }
}

LibraryItem::LibraryItem(string u, string n, string a, int i)
{
    unique_id = u;
    name = n;
    author = a;
    issue = i;
}

LibraryItem::LibraryItem(const LibraryItem &rhs)
{
    unique_id = rhs.unique_id;
    name = rhs.name;
    author = rhs.author;
    issue = rhs.issue;
}


class Book: public LibraryItem
{
    private:
        int book_pages;
        int year;
        int *bookpages;
        int *years;
        int book_size;
        int bookcount;
    public:
        Book();
        Book(int np, int y, string u, string n, string a, int i);
        Book(const Book &rhs);
        void checkOut();
        void checkIn();
        void displayItemInfo();
        void createItem();
        ~Book();
        void searchItem(string a);
        void showCheckOut();
};

void Book::showCheckOut()
{
    for(int i = 0; i<checkoutcount;i++)
    {
        cout << "Checked Out Item: " << checkitems[i] << endl;
    }
}

void Book::searchItem(string a)
{
    for(int i = 0;i<count;i++)
    {
        if (a == authors[i])
        {
            cout << "Name: " << names[i] << endl;
            cout << "Author: " << authors[i] << endl;
            cout << "Unique ID: " << listid[i] << endl;
            cout << "Book Pages: " << bookpages[i] << endl;
            cout << "Year: " << years[i] << endl;
        }
    }
}

Book::~Book()
{
    delete [] bookpages;
    delete [] years;
}

void Book::displayItemInfo()
{
    LibraryItem::displayItemInfo();
    for(int i = 0; i<bookcount;i++)
    {
        cout << "Book Pages: " << bookpages[i] << endl;
        cout << "Year: " << years[i] << endl;
    }
}

void Book::createItem()
{
    LibraryItem::createItem();
    cout << "Entering Book's detail: " << endl;
    int pages_input;
    cout << "Enter Book's pages: ";
    cin >> pages_input;
    cout << "Enter the year the book was published: ";
    int year_input;
    cin >> year_input;
    years[count-1] = year_input;
    bookpages[count-1] = pages_input;
    bookcount++;
}

Book::Book():LibraryItem()
{
    book_pages = 0;
    year = 0;
    years = new int [size];
    bookpages = new int [size];
    bookcount = 0;
}

Book::Book(int np, int y, string u, string n, string a , int i):LibraryItem(u,n,a,i)
{
    book_pages = np;
    year = y;
}

Book::Book(const Book &rhs):LibraryItem(rhs)
{
    book_pages = rhs.book_pages;
    year = rhs.year;
}

void Book::checkOut()
{
    bool found = false;
    cout << "Enter the Book's name: " << endl;
    string name_checkin;
    cin.clear();
    cin.ignore();
    getline(cin, name_checkin);
    for(int i = 0; i<count;i++)
    {
        if(name_checkin==names[i] && checkouts[i]==false)
        {
            cout << "Book Found" << endl;
            cout << "Book Issued" << endl;
            issues[i]++;
            checkouts[i] = true;
            checkitems[checkoutcount] = names[i];
            checkoutcount++;
            found = true;
        }
    }

    if(found == false)
    {
        cout << "Book not found/Book is not available right now." << endl;
    }
}

void Book::checkIn()
{
    bool foundin = false;
    cout << "Enter the name of the book you want to checkin: ";
    string input;
    cin.clear();
    cin.ignore();
    getline(cin, input);
    for(int i = 0; i<count;i++)
    {
        if(input==names[i])
        {
            cout << "Book Checked In" << endl;
            checkouts[i] = false;
            for(int i = 0; i<checkoutcount;i++)
            {
                if(input==checkitems[i])
                {
                    for(int j=i;j<checkoutcount-1;j++)
                    {
                        checkitems[j] = checkitems[j+1];
                    }
                    i--;
                    checkoutcount--;
                }
            }
            foundin = true;
        }
    }

    if(foundin==false)
    {
        cout << "Book you are trying to submit does not belong to this library" << endl;
    }
}


class Magazine: public LibraryItem
{
    private:
        int mag_pages;
        string mag_genre;
        int *magpages;
        string *magenres;
        int magcount;

    public:
        Magazine();
        Magazine(int np, string g, string u, string n, string a, int i);
        Magazine(const Magazine &rhs);
        void checkOut();
        void checkIn();
        void displayItemInfo();
        void createItem();
        ~Magazine();
        void searchItem(string a);
};



void Magazine::searchItem(string a)
{
    for(int i = 0; i<count; i++)
    {
        if (a==authors[i])
        {
            cout << "Name: " << names[i] << endl;
            cout << "Author: " << authors[i] << endl;
            cout << "Unique ID: " << listid[i] << endl;
            cout << "Magazine Pages: " << magpages[i] << endl;
            cout << "Genre: " << magenres[i] << endl;
            
        }
    }
}

Magazine::~Magazine()
{
    delete [] magpages;
    delete [] magenres;
}

void Magazine::checkOut()
{
    bool foundmag = false;
    cout << "Enter the Magazine's name: ";
    string magazine_input;
    cin.clear();
    cin.ignore();
    getline(cin, magazine_input);
    for(int i = 0; i<count;i++)
    {
        if(magazine_input==names[i] && checkouts[i]==false)
        {
            cout << "Magazine Found" << endl;
            cout << "Magazine Issued" << endl;
            issues[i]++;
            checkouts[i] = true;
            checkitems[checkoutcount] = names[i];
            checkoutcount++;
            foundmag = true;
        }
    }
    if(foundmag == false)
    {
        cout << "Magazine not available." << endl;
    }
}

void Magazine::checkIn()
{
    bool foundmagin = false;
    cout << "Enter the name of the magazine you want to checkin: ";
    string input;
    cin.clear();
    cin.ignore();
    getline(cin, input);
    for(int i = 0; i<count;i++)
    {
        if(input==names[i])
        {
            cout << "Magazine Checked In" << endl;
            checkouts[i] = false;
            for(int i = 0; i<checkoutcount;i++)
            {
                if(input==checkitems[i])
                {
                    for(int j=i;j<checkoutcount-1;j++)
                    {
                        checkitems[j] = checkitems[j+1];
                    }
                    i--;
                    checkoutcount--;
                }
            }
            foundmagin = true;        
        }
    }

    if(foundmagin == false)
    {
        cout << "Magazine you are trying to submit does not belong to this library" << endl;

    }
}

void Magazine::createItem()
{
   LibraryItem::createItem();
   cout << "Entering Magazine's details..." << endl;
   int pages;
   cout << "Enter Pages: ";
   cin >> pages;
   cout << "Enter Genre: ";
   string genre; 
   cin >> genre;
   magpages[count-1] = pages;
   magenres[count-1] = genre;
   magcount++;

}

void Magazine::displayItemInfo()
{
    LibraryItem::displayItemInfo();
    for(int i = 0; i<magcount;i++)
    {
        cout << "Magazine Pages: " << magpages[i] << endl;
        cout << "Genre: " << magenres[i] << endl;
    }   
}

Magazine::Magazine():LibraryItem()
{
    mag_pages = 0;
    mag_genre = "";
    magpages = new int[size];
    magenres = new string [size];
    magcount = 0;
}

Magazine::Magazine(int mp, string g, string u, string n, string a, int i):LibraryItem(u,n,a,i)
{
    mag_pages = mp;
    mag_genre = g;
}

Magazine::Magazine(const Magazine &rhs):LibraryItem(rhs)
{
    mag_pages = rhs.mag_pages;
    mag_genre = rhs.mag_genre;
}


class Movie: public LibraryItem
{
    private:
        int running_time;
        string mov_genre;
        int mov_year;
        int *runningtimes;
        string *movgenres;
        int *movyears;
        int movcount;
    public:
        Movie();
        Movie(int rt, string mg, int my, string u, string n, string a, int i);
        Movie(const Movie &rhs);
        void checkOut();
        void checkIn();
        void displayItemInfo();
        void createItem();
        ~Movie();
        void searchItem(string a);
};

void Movie::searchItem(string a)
{
    for(int i = 0; i<count; i++)
    {
        if (a==authors[i])
        {
            cout << "Name: " << names[i] << endl;
            cout << "Author: " << authors[i] << endl;
            cout << "Unique ID: " << listid[i] << endl;
            cout << "Running Time: " << runningtimes[i] << endl;
            cout << "Genre: " << movgenres[i] << endl;
            cout << "Released Year: " << movyears[i] << endl;
        }
    }
}

Movie::~Movie()
{
    delete [] runningtimes;
    delete [] movgenres;
    delete [] movyears;
}

void Movie::displayItemInfo()
{
    LibraryItem::displayItemInfo();
    for(int i = 0; i<movcount;i++)
    {
        cout << "Running Time: " << runningtimes[i] << endl;
        cout << "Genre: " << movgenres[i] << endl;
        cout << "Released Year: " << movyears[i] << endl;
    }   
}

void Movie::checkIn()
{
    bool foundmovin = false;
    cout << "Enter the name of the movie you want to checkin: ";
    string movie_input;
    cin.clear();
    cin.ignore();
    getline(cin, movie_input);
    for(int i = 0; i<count;i++)
    {
        if(movie_input==names[i])
        {
            cout << "Movie Checked In" << endl;
            checkouts[i] = false;
             for(int i = 0; i<checkoutcount;i++)
            {
                if(movie_input==checkitems[i])
                {
                    for(int j=i;j<checkoutcount-1;j++)
                    {
                        checkitems[j] = checkitems[j+1];
                    }
                    i--;
                    checkoutcount--;
                }
            }
            foundmovin = true;
        }
    }
    if(foundmovin == false)
    {
        cout << "Movie you are trying to submit does not belong to this library" << endl;
    }
}

void Movie::checkOut()
{
    bool foundmov = false;
    cout << "Enter the Movie's name: ";
    string movie_input;
    cin.clear();
    cin.ignore();
    getline(cin, movie_input);
    for(int i = 0; i<count;i++)
    {
        if(movie_input==names[i] && checkouts[i]==false)
        {
            cout << "Movie Found" << endl;
            cout << "Movie Issued" << endl;
            issues[i]++;
            checkouts[i] = true;
            checkitems[checkoutcount] = names[i];
            checkoutcount++;
            foundmov = true;
        }
    }
    if(foundmov == false)
    {
        cout << "Movie not found" << endl;
    }
}

void Movie::createItem()
{
    LibraryItem::createItem();
   cout << "Entering Movie's details..." << endl;
   int time;
   cout << "Enter time: ";
   cin >> time;
   cout << "Enter Genre: ";
   string genre; 
   cin >> genre;
   cout << "Enter the released year: ";
   int year;
   cin >> year;
   runningtimes[count-1] = time;
   movgenres[count-1] = genre;
   movyears[count-1] = year;
   movcount++;

}

Movie::Movie():LibraryItem()
{
    running_time = 0;
    mov_genre = "";
    mov_year = 0;
    runningtimes = new int [size];
    movgenres = new string [size];
    movyears = new int [size];
    movcount = 0;

}

Movie::Movie(int rt, string mg, int my, string u, string n, string a, int i):LibraryItem(u,n,a,i)
{
    running_time = rt;
    mov_genre = mg;
    mov_year = my;
}

Movie::Movie(const Movie &rhs):LibraryItem(rhs)
{
    running_time = rhs.running_time;
    mov_genre = rhs.mov_genre;
    mov_year = rhs.mov_year;
}

int main()
{
    Movie m2;
    Book b1;
    Magazine m1;
    string author;
    int menu;

    cout << "Welcome to the Library Management System" << endl;
    while(menu!=7)
    {
        cout << endl;
        cout << "\tMENU\t" << endl;
        cout << "1.Add New Item.\n2.View Items by Author.\n3.Check In Item.\n4.Check Out Item.\n5.View all items.\n6.View Checked Out Items.\n7.Exit" << endl;
        cout << "Input: ";
        cin >> menu;
        switch(menu)
        {
            case 1:
                cout << endl;
                cout << "\tADDING ITEMS\t" << endl;
                cout << "1.Book.\n2.Magazine\n3.Movie" << endl;
                int menu2;
                cin >> menu2;
                switch(menu2)
                {
                    case 1:
                        b1.createItem();
                        break;
                    case 2:
                        m1.createItem();
                        break;
                    case 3:
                        m2.createItem();
                        break;
                    default:
                        cout << "Choose an option" << endl;
                        break;
                }
                break;
            case 2:
                cout << endl;
                cout << "\tSEARCH BY AUTHOR\t" << endl;
                cout << "Enter the author's name: ";
                cin.clear();
                cin.ignore();
                getline(cin,author);
                b1.searchItem(author);
                m1.searchItem(author);
                m2.searchItem(author);
                break;
            case 3:
                cout << endl;
                cout << "\tCHECK-IN\t" << endl;
                cout << "1.Book.\n2.Magazine\n3.Movie" << endl;
                int menu4;
                cin >> menu4;
                switch(menu4)
                {
                    case 1:
                        b1.checkIn();
                        break;
                    case 2:
                        m1.checkIn();
                        break;
                    case 3:
                        m2.checkIn();
                        break;
                }
                break;
            case 4:
                cout << endl;
                cout << "\tCHECK-OUT\t" << endl;
                cout << "1.Book.\n2.Magazine\n3.Movie" << endl;
                int menu3;
                cin >> menu3;
                switch(menu3)
                {
                    case 1:
                        b1.checkOut();
                        break;
                    case 2:
                        m1.checkOut();
                        break;
                    case 3:
                        m2.checkOut();
                }
                break;
            case 5:
                cout << endl << endl;
                cout << "\tDISPLAYING ITEMS\t" << endl;
                b1.displayItemInfo();
                m1.displayItemInfo();
                m2.displayItemInfo();
                break;
            case 6:
                cout << endl;
                cout << endl;
                cout << "\tDISPLAYING CHECKED OUT ITEMS\t" << endl;
                b1.showCheckOut();
        }
        cout << endl;
    }
}





