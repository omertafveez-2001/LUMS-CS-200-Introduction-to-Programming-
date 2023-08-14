#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 121;
    string word = to_string(x);
    cout << word<<endl;
    string new_word = "";
    for(int i = word.length()-1; i>=0;i--)
    {
        new_word+=word[i];
    }
    cout << new_word<<endl;
    if(word==new_word)
    {
        cout << "ok";
    }
    else
    {
        cout << "no";
    }
}