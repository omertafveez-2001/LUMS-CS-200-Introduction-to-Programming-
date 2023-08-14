#include <iostream>
using namespace std;

class Rectangle
{
    private:
        int length;
        int width;
    public:
        void setData(int l, int w);
        void peri();
        void area();
        void rectcheck();
        void print();
};
void Rectangle::setData(int l, int w)
{
    cout << "Enter Length: ";
    cin >> l;
    length = l;
    cout << "Enter Width: ";
    cin >> w;
    width = w;
}
void Rectangle::peri()
{
 cout << 2*(length+width) << endl;
}
void Rectangle::area()
{
    cout << length*width << endl;
}
void Rectangle::rectcheck()
{
    if (width!=length)
    {
        cout << "No! It is not a square" << endl;
    }
    else
    {
        cout << "Yes! It is a square" << endl;
    }
}
void Rectangle::print()
{
    for (int i = 1; i <= width; i++)
    {
        if (i==1 || i==width)
        {
            for (int a = 1; a<=length; a++)
            {
                cout << "*";
            }
            cout << endl;
        }
        else
        {
            cout << "*";
            for (int j = 1; j <= length-2; j++ )
            {
                cout << " ";
            }
            cout << "*" << endl;
        }
    }
}

int main()
{
    int length, width;
    Rectangle rect1;
    rect1.setData(length, width);
    rect1.area();
    rect1.rectcheck();
    rect1.print();
}