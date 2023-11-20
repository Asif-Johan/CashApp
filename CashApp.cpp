#include <iostream>

#include <vector>  //to create a vector of objects made with class
#include <conio.h> //to use the _getch() function to hold screen
#include <time.h>
using namespace std;


int main();
string mob;
int pp, nn;

class Transaction {
    private: 
    int amount;
    string num;
    // int id = 0;
    string type;

    public:
     int args;
    Transaction(int a, string c, string b): amount(a), num(b), type(c){args = 3;}
    Transaction(int a, string c): amount(a), type(c){args = 2;}
    
    int getAmount(){return amount;}
    // int getID(){return id;}
    string getNum(){return num;}
    string getType(){return type;}



};

class History{
    private:
    vector<Transaction>Transactions;
    public:
    int TransactionID =0;

    void addTransaction (Transaction T){
     Transactions.push_back(T);
    }
            
    
    
    void showTransaction (){
        cout <<".......Transaction Details......."<<endl<<endl;
        for (Transaction T : Transactions){
// cout<<"Transaction ID: "<< T.getID() << " Transaction Type: "<< T.getType()<< " Ammount: "<<T.getAmount()<<endl;

if (T.args ==3){
cout<<"Transaction ID:"<< ++TransactionID << "  Type:"<< T.getType()<< T.getNum()<<"  Ammount:"<<T.getAmount()<<" tk"<<endl;
}
else {
    cout<<"Transaction ID:"<< ++TransactionID << "  Type:"<< T.getType()<<"  Ammount:"<<T.getAmount()<<" tk"<<endl;

}
        }
    }




};


class Member
{

private:
    string mobile;
    string name;
    int pin;
   
    float amount=0;

public: 

History H;
    // constructor
    Member(string mobileC, string nameC,  int pinC)
    {
        mobile = mobileC;
        name = nameC;
        pin = pinC;
    };

    // setter method
    void setNum(int NUMBER)
    {
        mobile = NUMBER;
    }

    void setName(string NAME)
    {
        name = NAME;
    }
    void setAmount(float a)
    {
        amount = a;
    }

    void addAmount(float a){
        amount+=a;
    }
    void setPIN(int PIN)
    {
        pin = PIN;
    }

    void setHistory(History a){H=a;}

    // getter method
    string getNum()
    {
        return mobile;
    }
    int getPIN()
    {
        return pin;
    }
    float getAmount()
    {
        return amount;
    }
    string getName()
    {
        return name;
    }
};


int Search(string m, vector<Member> &members)
{
    int i = 0;
    int place = -1;
    for (i = 0; i < members.size(); i++)
    {

        if (m == members[i].getNum())
        {
            place = i;
            break;
        }
    }
    return place;
}

int getPin()
{
    string pass = "";
    string pass1 = "";
    char ch, ch1;
    ch = getch();
    while (ch != 13)
    {
        pass.push_back(ch);
        cout << "*";
        ch = getch();
    }
    cout << endl
         << "Confirm Pin: ";
    ch1 = getch();
    while (ch1 != 13)
    {
        pass1.push_back(ch1);
        cout << "#";
        ch1 = getch();
    }

    if (pass1 == pass)
    {
        return (stoi(pass));
    }
    else
    {
        cout << "Recheck Password..." << endl;
        getPin();
    }
}

// registration
void Reg(vector<Member> &members)
{

    string m, n;
    int p, q;
    int x, o;
    srand(time(0));

    cout << "Enter Mobile Number:" << endl;
    cin >> m;
    q = Search(m, members);
    // cout << q;

    if (q < 0)
    {
        cout << "Enter your Name:";
        cin >> n;
        cout << "Enter your Pin:";
        //  cin>>p;

        p = getPin();
      
        x = 1000 + rand() % 9000; // 1000+ 0 to 8999
        cout << "\nYour OTP:" << x << endl;
        cout << "Enter your OTP:";
        cin >> o;
        if (x == o)
        {
        
            members.push_back(Member(m, n, p));
            cout << "......Registration Successful....." << endl;
            cout << endl;
            cout << "Mobile=" << m << endl;
            cout << "Name=" << n << endl;
            cout << "pin=" << p << endl;
        }
        else
            cout << "Invalid OTP..." << endl;
    }
    else
        cout << "Sorry, Member already exists..." << endl;
    getch();
}

// update function
void update(vector<Member> &members)
{
    int PIN;
    string n;
    int op;
    // cout << "Update construction " << endl;
    cout << "What Do you want to update?" << endl;
    cout << "1. Update Name" << endl;
    cout << "2. Update PIN" << endl;

    cin >> op;
    switch (op)
    {
    case 1:
        cout << "Confirm PIN: ";
        cin >> PIN;
        if (PIN == pp)
        {
            cout << "Enter New Name: ";
            cin >> n;
        }
        else
        {
            cout << "Please Give Correct PIN" << endl;
            getch();
            break;
        }
        members[nn].setName(n);
        cout << endl
             << "Name Has been changed Successfully" << endl;
        cout << "New Name: " << members[nn].getName();

        break;

    case 2:
        cout << "Confirm PIN: ";
        cin >> PIN;
        if (PIN == pp)
        {
            cout << "Enter Your New PIN:";
            PIN = getPin();
        }
        else
        {
            cout << "Please Give Correct PIN" << endl;
            getch();
            break;
        }

        members[nn].setPIN(PIN);
        cout << "PIN Has been changed Successfully" << endl;
        cout << "New PIN: " << members[nn].getPIN();

        break;

    default:
        cout << "Enter Valid Option" << endl;
        getch();
        break;
    }
}
// Remove function
void Remove(vector<Member> &members)
{
    // int PIN;
    cout<<"Are you sure, you want to remove?(Y/N)"<<endl;
    char a;cin>>a;
    if ((a=='Y')||(a=='y')){
        int flag = Search(members[nn].getNum() , members);
            members.erase(members.begin() + flag);
            cout<<"..............removed successfully...............";
            system("cls"); getch();
            main();
    } else if ((a=='N')||(a=='n'))
    {
        cout<<"go back to menu...press any key";getch();
        
    } else {cout<<"please enter valid responce";}


}
// Send function
void Send(vector<Member> &members)

{
    string Send_number;
    int F, PIN;
    double Amm;
    // cout << "Send construction " << endl;

    cout << "Enter Number to Send to: ";
    cin >> Send_number;
    F = Search(Send_number, members);
    // cout << F << endl;
    if (F < 0)
    {
        cout << "User with number" << Send_number << " does not Exist" << endl;
        return;
    }
    else
    {
        cout << "Enter Amount: ";
        cin >> Amm;
        
        if (members[nn].getAmount() < Amm)
        {
            cout<<nn<<endl;
            cout <<endl<< "Insufficient Balance";
            getch();
            return;
        }
        else
        {

            cout << "PIN: ";
            cin >> PIN;
            if (PIN == members[nn].getPIN())
            {
                members[nn].setAmount((members[nn].getAmount() - Amm));
                members[F].setAmount((members[F].getAmount() + Amm));
cout<<"Money transfer successful..."<<endl;
cout<<"your new balance..."<<members[nn].getAmount();

Transaction T1(Amm, "Send to", members[F].getNum());
Transaction T2(Amm, "Recieved From", members[nn].getNum());
members[nn].H.addTransaction(T1);
members[F].H.addTransaction(T2);


            } else{cout<<endl<<"Wrong PIN"; getch(); return;}
        }
    }
}
// Cin function
void Cin(vector<Member>&members)
{
    cout<<"Enter amount to cash in"<<endl;
   float x;cin>>x;
   members[nn].setAmount(members[nn].getAmount()+x);
   cout<<"Added "<<x <<"Amount to the account \n"<<"new amount= "<<members[nn].getAmount();
   Transaction T1(x, "Cashed In");
   members[nn].H.addTransaction(T1);
  
}
// cout function
void Cout(vector<Member>&members)
{
    int amount;
    // cout << "Cash out construction " << endl;
cout<<"Enter amount to cash out"<<endl;
cin>>amount;

    if (amount > (members[nn].getAmount())){
        cout<<"Insufficient Balance"<<endl; getch();
        return;
    }
    else{
    members[nn].setAmount(members[nn].getAmount()-amount);
    cout<<"New Balance"<<members[nn].getAmount()<<endl;
    Transaction T1(amount, "Cashed Out");
     members[nn].H.addTransaction(T1);
    }

}
// PAy function
void Pay(vector<Member>&members)
{
    cout << "Select Bill " << endl;
    cout << "1. Electricity (100tk)" << endl;
    cout << "2. Wifi (50tk)" << endl;
    cout << "3. Charity (10tk)" << endl;
    int choice;cin>>choice;
   

    switch (choice)
    {
    case 1:
        if (members[nn].getAmount()>=100){
cout<<"Bill payed Successfylly to Electricity";
members[nn].setAmount(members[nn].getAmount()-100);
cout<<"New balance: "<<members[nn].getAmount();
   Transaction T1(100, "Electricity Bill");
     members[nn].H.addTransaction(T1);

        }
        else{
            cout<<"insufficient Balance"<<endl;
        }
        break;
    case 2:
        if (members[nn].getAmount()>=50){
cout<<"Bill payed Successfylly to Wifi";
members[nn].setAmount(members[nn].getAmount()-50);
cout<<"New balance: "<<members[nn].getAmount();
   Transaction T1(50, "Wifi Bill");
     members[nn].H.addTransaction(T1);
        }
        else{
            cout<<"insufficient Balance"<<endl;
        }
        break;
    case 3:
        if (members[nn].getAmount()>=10){
cout<<"Donated successfully to Charity";
members[nn].setAmount(members[nn].getAmount()-10);
cout<<"New balance: "<<members[nn].getAmount();
   Transaction T1(10, "Charity Payed");
     members[nn].H.addTransaction(T1);
        }
        else{
            cout<<"insufficient Balance"<<endl;
        }
        break;  
    default:
    cout<<"Enter valid Choice"<<endl;
        break;
    }
}
// Check Balance
void Check(vector<Member>members)
{
cout<<"Balance= "<<members[nn].getAmount();
}
void His(vector<Member>members)
{
    // cout << "History construction " << endl;
    members[nn].H.showTransaction();
}

    vector<Member> members;
///////////////////MAIN MENU///////////////
main()
{
    int op1;
    int op2;
    do
    {
        system("cls");
        cout << "-----MyCash Login-----" << endl;
        cout << "1.Login" << endl;
        cout << "2.Registration" << endl;
        cout << "3.Exit" << endl;
        cout << "Enter Your Option" << endl;
        cin >> op1;

        switch (op1)
        {
        case 1:
            system("cls");

            cout << "Enter Mobile: ";
            cin >> mob;
            cout << "Enter PIN: ";
            cin >> pp;
            nn = Search(mob, members);
            if (members[nn].getPIN() == pp)
            {

                do
                {
                    system("cls");

                    cout << "********** MyCash Menu ********" << endl;
                    cout << "1. Update Me" << endl;
                    cout << "2. Remove Me" << endl;
                    cout << "3. Send Money" << endl;
                    cout << "4. Cash-in" << endl;
                    cout << "5. Cash-out" << endl;
                    cout << "6. Pay Bill" << endl;
                    cout << "7. Check Balance" << endl;
                    cout << "8. History" << endl;
                    cout << "9. Logout" << endl;
                    cout << "Enter Your Option (1-9):_" << endl;
                    cout << "Members: " << 0 << endl;

                    cin >> op2;

                    switch (op2)
                    {
                    case 0:
                        system("cls");
                        for (int i = 0; i < members.size(); i++)
                        {
                            cout << "Name: " << members[i].getName() << endl;
                            cout << "Number: 0" << members[i].getNum() << endl;
                            cout << "Amount: " << members[i].getAmount() << endl;
                            cout << "PIN: " << members[i].getPIN() << endl;
                        }
                        getch();
                        break;
                    case 1:
                        system("cls");
                        update(members);
                        getch();
                        break;
                    case 2:
                        system("cls");
                        Remove(members);
                        getch();
                        break;
                    case 3:
                        system("cls");
                        Send(members);
                        getch();
                        break;
                    case 4:
                        
                        Cin(members);
                        getch();
                        break;
                    case 5:
                        system("cls");
                        Cout(members);
                        getch();
                        break;
                    case 6:
                        system("cls");
                        Pay(members);
                        getch();
                        break;
                    case 7:
                        system("cls");
                        Check(members);
                        getch();
                        break;
                    case 8:
                        system("cls");
                        His(members);
                        getch();
                        break;
                    case 9:
                        system("cls");
                        main();

                        break;

                    default:
                        system("cls");
                        cout << "Enter Valid Option" << endl;
                        getch();
                        break;
                    }

                } while (1);

                getch();
            }
            else
            {
                cout << "Invalid Number or PIN" << endl;
                getch();
            }
            break;
        case 2:
            system("cls");
            Reg(members);
            break;
        case 3:
            exit(1);
            break;

        default:
            break;
        }

    } while (1);

    return 0;
}