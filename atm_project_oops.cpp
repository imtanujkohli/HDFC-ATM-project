#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

// min-project ATM
//     ->check balance
//     ->cash withdraw
//     ->user details
//     ->update mobile no.

class ATM
{
private:
    long int account_number;
    string name;
    int pin;
    double balance;
    string mobile_number;

public:
    // assining the data to private member variable
    void setData(long int account_number_a, string name_a, int pin_a, double balance_a, string mobile_number_a)
    {
        // assining the formal arugment to private member variable
        account_number = account_number_a;
        name = name_a;
        pin = pin_a;
        balance = balance_a;
        mobile_number = mobile_number_a;
    }

    // returning the user data
    long int get_account_no()
    {
        return account_number;
    }

    string get_name()
    {
        return name;
    }

    int get_pin()
    {
        return pin;
    }

    double get_balance()
    {
        return balance;
    }

    string get_mobile()
    {
        return mobile_number;
    }

    // updating the user mobile number
    void set_mobile(string mobile_prev, string mobile_new)
    {
        if (mobile_prev == mobile_number) // will check old mobile number
        {
            mobile_number = mobile_new; // update with new if old matches
            cout << "mobile number change successfully  ";
            _getch(); // will hold the screen untill user enter any key
        }
        else
        {
            cout << "incorrect mobile number  ";
            _getch();
        }
    }

    // withdraw money from ATM
    void cash_withdraw(int amount_a)
    {
        if (amount_a > 0 && amount_a < balance) // checking account avaibility
        {
            balance = balance - amount_a; // updating balance
            cout << "please collect your cash  ";
            cout << "now account balance is : " << balance;
            _getch();
        }
        else
        {
            cout << "invalid input or insufficient balance  ";
            _getch();
        }
    }
};

int main()
{

    int choice = 0;
    int Enter_pin;                 // for user verification
    long int enter_account_number; // for user verification

    system("cls"); // clearing the screen

    // creating a user (object)
    ATM user1;

    // set data user (into objects)         (default data)
    user1.setData(1234567, "Tim", 1111, 45000.34, "9266565558");

    do
    {
        system("cls");

        cout << "*****Welcome To HDFC ATM*****" << endl;
        cout << "enter your account number : ";
        cin >> enter_account_number;

        cout << endl<< "enter ATM PIN : ";
        cin >> Enter_pin;

        // check whether the entered details is equal to default details
        if ((enter_account_number == user1.get_account_no()) && (Enter_pin == user1.get_pin()))
        {
            do
            {
                int amount = 0;
                string old_mobile_no, new_mobile_no;

                system("cls");

                // user interface

                cout << endl<< "*****Welcome To SBI ATM*****";
                cout << endl<< "select option";
                cout << endl<< "1. check balance : ";
                cout << endl<< "2. cash withdrwal : ";
                cout << endl<< "3. show user details : ";
                cout << endl<< "4. update user mobile number : ";
                cout << endl<< "5.exit"<<endl;
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "your bank balance is : " << user1.get_balance();
                    _getch();
                    break;

                case 2:
                    cout << "enter amount : ";
                    cin >> amount;
                    user1.cash_withdraw(amount);
                    break;

                case 3:
                    cout << "*****User Details*****" << endl;
                    cout << "-> Account number : " << user1.get_account_no() << endl;
                    cout << "-> Name : " << user1.get_name() << endl;
                    cout << "-> Balance : " << user1.get_balance() << endl;
                    cout << "-> mobile number : " << user1.get_mobile() << endl;
                    _getch();
                    break;

                case 4:

                    cout<<"enter old mobile number : ";
                    cin>>old_mobile_no;

                    cout<<"enter new mobile number : ";
                    cin>>new_mobile_no;

                    user1.set_mobile(old_mobile_no , new_mobile_no);
                    _getch();
                    break;

                case 5:

                    exit(0);

                default:
                    cout<<"enter vaild data "<<endl;
                }
            } while (1);
        }

    } while (1); // for running this loop infinite time untill user press exit

    return 0;
}