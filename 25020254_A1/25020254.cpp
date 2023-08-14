#include <iostream>
using namespace std;


class Users
{
    private:
        int size;
        string username;
        string name; //identifier
        string password;
        string emailaddress;
        string *ptrusername;
        string *ptrname;
        string *ptrpassword;
        string *ptremail;
        int counting = 1;
    public:
        Users(); //default constructor
        ~Users(); //destructor

        // data manipulation
        void storeData(); //storing data
        void setData(); //setting data
        void setUsername(string u);
        void setEmail(string e);
        void setPassword(string p);
        void setIdentifier(string i);

        //checkers
        bool checkPassword(string pw); //checking password
        bool checkUsername(string user); //checking is username already exists
        bool checkEmail(string em); // checking email

        //resize
        void resizeArray(); //
        void encryption(); //
        void decryption(); //

        //getters
        string getName(); // getter name
        string getPw(); //getter password
        string getUserName();
        string getEmail();
        int getCount();

        //overloading
        Users operator=(const Users &rhs); //operator= overloaded
        friend ostream& operator<<(ostream& out, const Users &rhs); //operator<< overloaded

        //friend functions
        friend class LoginAuthentication; //friend class
};

bool Users::checkEmail(string m)
{
    const char validation = '@';
    bool flag = false;
    for(int i = 0; i<m.length(); i++)
    {
        if(m[i]==validation)
        {
            flag = true;
            break;
        }
    }
}

void Users::encryption()
{
    string encrypted_password;
    for(int i = 0; i<counting;i++)
    {
        encrypted_password = ptrpassword[i];
        for(int i = 0; (i < 100 && encrypted_password[i] != '\0'); i++)
        {
            encrypted_password[i] = encrypted_password[i] + 2; //the key for encryption is 3 that is added to ASCII value
        }
        ptrpassword[i] = encrypted_password;
    }
}

void Users::decryption()
{
    string decrypted_password;
    for (int i = 0; i<counting;i++)
    {
        decrypted_password = ptrpassword[i];
        for(int i = 0; (i < 100 && decrypted_password[i] != '\0'); i++)
      {
        decrypted_password[i] = decrypted_password[i] - 2;
      }
      ptrpassword[i] = decrypted_password;
    }
}

void Users::resizeArray()
{
    int current_size = size;
    size*=2;
    string *tempname = new string[size];
    string *temppass = new string[size];
    string *tempemail = new string[size];
    string *tempusername = new string[size];
    for(int i = 0; i<current_size;i++)
    {
        tempname[i] = ptrname[i];
        temppass[i] = ptrpassword[i];
        tempemail[i] = ptremail[i];
        tempusername[i] = ptrusername[i];
    }
    delete [] ptrname;
    delete [] ptrpassword;
    delete [] ptremail;
    delete [] ptrusername;
    ptrname = tempname;
    ptrpassword = temppass;
    ptremail = tempemail;
    ptrusername = tempusername;

}
int Users:: getCount()
{
    return counting;
}
bool Users::checkUsername(string s)
{
    string username = s;
    bool checku = false;
    if(counting == 1)
    {
        checku =true;
    }
    else
    {
        for(int i=0; i<counting-1; i++)
        {
            if(ptrname[i]!=username)
            {
                checku = true;

            }
            else
            {
                checku = false;
            }
        }
    }
    return checku;
}
void Users::setData()
{
    string name1,pw,email1, username1;
    cout << "Sign Up form" << endl;
    cout << "Please enter your name: ";
    cin >> username1;
    username = username1;
    cin.ignore();
    cin.clear();
    cout << "Please enter your email: ";
    cin >> email1;
    bool checkingem = false;
    while(!checkingem)
    {
        checkingem = checkEmail(email1);
        if(checkingem)
        {
            emailaddress = email1;
        }
        else
        {
            cout << "Invalid Email Address. Try Again: " << endl;
            cin.clear();
            cin.ignore();
            cin>>email1;
        }
    }
    cout << "Please Enter Your Username: ";
    cin >> name1;
    bool checkingu = false;
    while(!checkingu)
    {
        checkingu = checkUsername(name1);
        if(checkingu)
        {
            name = name1;
        }
        else
        {
            cout << "The username is already taken.Please Enter username again:" << endl;
            cin.clear();
            cin.ignore();
            cin>>name1;
        }
    }
    cin.clear();
    cin.ignore();
    cout << "Please Enter your Password: ";
    cin >> pw;
    bool checking = false;
    while(!checking)
    {
        checking = checkPassword(pw);
        if(checking)
        {
            password = pw;
        }
        else
        {
            cout << "Please Enter password again:" << endl;
            cin.clear();
            cin.ignore();
            cin>>pw;
        }
    }
    cin.clear();
    cin.ignore();
    storeData();
    counting++;
}
Users Users::operator=(const Users &rhs)
{
    Users t;
    t.size = rhs.size;
    t.ptrname = new string[t.size];
    t.ptrpassword = new string[t.size];
    t.ptremail = new string[t.size];
    for(int i = 0; i<t.size;i++)
    {
        t.ptrname[i] = rhs.ptrname[i];
        t.ptrpassword[i] = rhs.ptrpassword[i];
        t.ptremail[i] = rhs.ptremail[i];
        t.ptrusername[i] = rhs.ptrusername[i];
    }
    return t;
}

ostream& operator<<(ostream& out, const Users &rhs)
{
    for(int i = 0; i < rhs.counting-1 ; i++)
    {
        out << "Name: " << rhs.ptrusername[i] << endl;
        out << "Username: " << rhs.ptrname[i] << endl;
        out << "Password: " << rhs.ptrpassword[i] << endl;
        out << "Email: " << rhs.ptremail[i] << endl;
        out << endl;
    }
    return out;
}

string Users::getName()
{
    return name;
}

string Users::getPw()
{
    return password;
}

Users::~Users()
{
    delete [] ptrname;
    delete [] ptrpassword;
    delete [] ptremail;
    delete [] ptrusername;
}

Users::Users()
{
    size = 20;
    name = "\0";
    password = "\0";
    emailaddress = "\0";
    username = "\0";
    ptrname= new string[size];
    ptrpassword = new string[size];
    ptremail = new string[size];
    ptrusername = new string[size];
}

bool Users::checkPassword(string pass)
{
    bool result = false;
    bool flagcapital = false;
    bool flagnumber = false;
    bool flagspecial = false;
    string special_characters= "&@!#$/*%";
    string capitall = "ABCDEFGHIJKLMNOPQRSTUVQ";
    string numbers = "0123456789";
    for(int i = 0; i<pass.length(); i++)
    {
        for (int j = 0; j<special_characters.length(); j++)
        {
            if(pass[i]==special_characters[j])
            {
                flagspecial=true;
            }
        }
        for(int j = 0; j<capitall.length(); j++)
        {
            if(pass[i]==capitall[j])
            {
                flagcapital = true;
            }
        }
        for(int j = 0; j<numbers.length(); j++)
        {
            if(pass[i]==numbers[j])
            {
                flagnumber = true;
            }
        }
    }
    if(pass.length()>=8 && flagnumber && flagcapital && flagspecial)
    {
        cout << "Strong Password\nRegistered Successfully" << endl;
        result = true;
    }
    else if (pass.length()<8 || !flagcapital || !flagnumber || !flagspecial)
    {
        cout << "Medium Password. Registeration Failed." << endl;
    }
    else if(pass.length()<8 && !flagnumber && !flagcapital && !flagspecial)
    {
        cout << "Weak Password. Registeration Failed." << endl;
    }
    return result;
}

void Users::storeData()
{
    if (counting == 1)
    {
        ptrname[0] = name;
        ptrpassword[0] = password;
        ptremail[0] = emailaddress;
        ptrusername[0] = username;
    }
    else
    {
        ptrname[counting-1] = name;
        ptrpassword[counting-1] = password;
        ptremail[counting-1] = emailaddress;
        ptrusername[counting-1]=username;
    }
}

class LoginAuthentication
{
    private:
        int deletedsize;
        string password;
        string username;
        int count;
        int indexvalue;
        string deletedusers[100];
    public:
        LoginAuthentication();
        LoginAuthentication(string u, string p, const Users &rhs);
        bool loginCheck(const Users &rhs);
        int getCount();
        void loginMenu(Users &rhs);
        void loginStart(Users &rhs);
        void unsubscribe(Users &rhs);
        void loginMenuAdmin(Users &rhs);
};

void LoginAuthentication::loginMenuAdmin(Users &rhs)
{
    int deleteduserindex=0;
    int answer1;
    while(answer1!=6)
    {
        string usernamedeleted;
        cout << "1.Add a User."<< endl;
        cout << "2.Delete a User." << endl;
        cout << "3.Change password of a user." << endl;
        cout << "4.Change email of a given user." << endl;
        cout << "5.Display records and list of deleted users." << endl;
        cout << "6.Logout" << endl;
        cout << "Enter: ";
        cin >> answer1;
        int indexing = 0;
        switch(answer1)
        {
            case 1: 
                rhs.setData();
                break;
            case 2:
                cout << "Enter user's username: " << endl;
                cin >> usernamedeleted;
                for(int i = 0; i<rhs.counting;i++)
                {
                    if(rhs.ptrname[i]==usernamedeleted)
                    {
                        indexing = i;
                        //assuming index < counting;
                        rhs.counting-=1;
                        deletedusers[deleteduserindex] = usernamedeleted;
                        for(int j =indexing; j<rhs.counting;j++)
                        {
                            rhs.ptrname[j] = rhs.ptrname[j+1];
                            rhs.ptrpassword[j] = rhs.ptrpassword[j+1];
                            rhs.ptremail[j] = rhs.ptremail[j+1];
                            rhs.ptrusername[j] = rhs.ptrusername[j+1];
                        }
                        cout << "User Unsubscribed/deleted" << endl;
                        deleteduserindex++;
                        break;
                    }
                    else
                    {
                        cout << "User does not exist" << endl;
                        break;
                    }
                }
                break;
            case 3:
                cout << "Enter user's username: " << endl;
                cin >> usernamedeleted;
                for(int i = 0; i<rhs.counting;i++)
                {
                    if(rhs.ptrname[i]==usernamedeleted)
                    {
                        bool result = false;
                        while(!result)
                        {
                            string newpassword;
                            cout << "Enter new password: ";
                            cin >> newpassword;
                            bool checking = rhs.checkPassword(newpassword);
                            if(checking)
                            {
                                rhs.ptrpassword[i] = newpassword;
                                result = true;
                            }
                            else
                            {
                                cout << "Incorrect Password. Try again" << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "User does not exist" << endl;
                    }
                }
                break;
            case 4:
            cout << "Enter user's username: " << endl;
                cin >> usernamedeleted;
                for(int i = 0; i<rhs.counting;i++)
                {
                    if(rhs.ptrname[i]==usernamedeleted)
                    {
                        string newemail;
                        cout << "Enter new email address: ";
                        cin >> newemail;
                        rhs.ptremail[i] = newemail;
                        break;
                    }
                    else
                    {
                        cout << "User does not exist" << endl;
                    }
                }
                break;
            case 5:
                cout << endl;
                cout << "Displaying Records:" << endl;
                cout << rhs << endl;
                cout << "Displaying Deleted Users: " << endl;
                for(int i = 0 ;i < deleteduserindex; i++)
                {
                    cout << "Username Deleted: " << deletedusers[i] << endl;
                }
                break;
            case 6:
                cout << endl << endl;
                cout << "Logged Out" << endl;
                break;
        }
    }

}

void LoginAuthentication::unsubscribe(Users & rhs)
{
    if (indexvalue < rhs.counting)
    {
        rhs.counting= rhs.counting - 1;
        for (int j=indexvalue; j<rhs.counting; j++)
        {
            rhs.ptrname[j] = rhs.ptrname[j+1];
            rhs.ptrpassword[j] = rhs.ptrpassword[j+1];
            rhs.ptremail[j] = rhs.ptremail[j+1];
            rhs.ptrusername[j] = rhs.ptrusername[j+1];
        }
    }

}

int LoginAuthentication::getCount()
{
    return count;
}

LoginAuthentication::LoginAuthentication()
{
    password = "\0";
    username = "\0";
    count = 0;
    indexvalue = 0;
    deletedsize = 100;
}
LoginAuthentication::LoginAuthentication(string u, string p, const Users &rhs)
{
    password = p;
    username = u;
    count = rhs.counting;
}

void LoginAuthentication::loginStart(Users &rhs)
{
    bool logging = loginCheck(rhs);
    while(logging==false)
    {
        cout << "Login Failed. Try Again" << endl;
        cout << "Login Username: " << endl;
        cin >> username;
        cout << "Login Password: " << endl;
        cin >> password;
        if(username=="Admin")
        {
            logging=true;
        }
        else
        {
            logging = loginCheck(rhs);
        }
    }
    
    if(username=="Admin")
    {
        cout << "Logged in Successfully" << endl;
        loginMenuAdmin(rhs);
    }
    else if(loginCheck(rhs))
    {
        cout << "Logged in successfully" << endl;
        loginMenu(rhs);
    }
}
bool LoginAuthentication::loginCheck(const Users&rhs)
{
    bool flag = false;
    if(username=="Admin")
    {
        flag = true;
    }
    else
    {
        for (int i = 0; i<rhs.counting-1;i++)
        {
            if(rhs.ptrname[i]==username)
            {
                if(rhs.ptrpassword[i]==password)
                {
                    flag = true;
                    indexvalue=i;
                    break;
                }
            }
        }
    }
    
    return flag;
}

void LoginAuthentication::loginMenu(Users &rhs)
{
    int answer;
    while(answer!=4 || answer!=3)
    {
        cout << "1.Change Email Address."<< endl;
        cout << "2.Change Password." << endl;
        cout << "3.Logout" << endl;
        cout << "4.unsubscribe" << endl;
        cout << "Enter: ";
        cin >> answer;
        if(answer == 1)
        {
            cout << "Enter new email address: ";
            string new_email;
            cin>>new_email;
            rhs.ptremail[indexvalue] = new_email;
        }
        else if(answer==2)
        {
            cout << "Enter new password: ";
            string new_pass;
            cin>>new_pass;
            bool checking = false;
            while(!checking)
            {
                checking = rhs.checkPassword(new_pass);
                if(checking)
                {
                    password = new_pass;
                }
                else
                {
                    cout << "Please Enter password again:" << endl;
                    cin.clear();
                    cin.ignore();
                    cin>>new_pass;
                }
            }
            rhs.ptremail[indexvalue] = new_pass;
        }
        else if(answer == 3)
        {
            cout << "Logged out successfully" << endl;
            return;
        }
        else if(answer ==4)
        {
            unsubscribe(rhs);
            cout << "User deleted/unsubsrcibed" << endl;
            return;
        }
        
    }

}

int main()
{
    int signup=1;
    Users t;
    while(signup==1)
    {
        t.setData();
        cout << "1.Go back to sign up form\n2. Go to login form." << endl;
        cin >> signup;
    }
    string username, password;
    cout << "Login Username: " << endl;
    cin >> username;
    cout << "Login Password: " << endl;
    cin >> password;
    LoginAuthentication t1(username, password, t);
    t1.loginStart(t);
}