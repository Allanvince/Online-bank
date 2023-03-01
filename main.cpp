#include <iostream>
#include <string>
#include <map>

using namespace std;

class Account{
    int accountNumber, accountNum;
    string password, pass;
    string name;
    int initialDepo = 1000;
    double depositAmt;
    int withdrawAmt;
    string choice;
    string type;
    double balance;

public:
    void create_account();
    void login_account();
    void modify_account();
    void withdraw();
    void deposit();
    static void view_miniStatement();
    void introduction();

    //getter and setter functions
    void setBalance(double b){
         balance = b;
    }
    double getBalance(){
        return balance;
    }
};
void Account::introduction(){
    cout << "HELLO THERE, WELCOME TO ONLINE BANK SERVICES!!" <<endl
         << "Enter your name: " <<endl;
    cin >> name;
    cout << "Greetings: " << name << ".Do you have an existing account ('yes or no')" <<endl;
    cin >> choice;

    if (choice == "yes")
    {
        cout <<"Function not yet implemented"<<endl;
    }
    else if (choice == "no"){
        this->create_account();
    }
    else{
        int count = 1;
        while (count > 0)
        {
            cout << "Invalid choice" <<endl;
            count -= 1;
        }
        if (count ==0)
        {
            exit(0);
        }
    }

}
void Account::create_account(){
    cout << "Enter type of account" << endl;
    cin >> type;

    cout << "Enter your account number" << endl;
    cin >> accountNumber;
    cout << "Confirm your account number" << endl;
    cin >> accountNum;

    cout <<"Enter your password" << endl;
    cin >> password;
    cout << "Confirm your password" << endl;
    cin >> pass;

    if ((accountNumber==accountNum) and (password == pass))
    {
        cout << "Details match :)" << endl;

        cout << "Enter amount to deposit to account (minimum amount is 1000)" <<endl;
        cin >> depositAmt;
        if (depositAmt < initialDepo)
        {
            cout << "The minimum amount to deposit is 1000. Try again!" <<endl;
            cin >> depositAmt;
        }
        else{
            map <double, string> myMap;
            myMap.insert(pair<double,string>(depositAmt, "was deposited"));
            setBalance(balance += depositAmt);

            cout << depositAmt << " was deposited" << endl;
            cout << "Account created successfully" <<endl;

        }

    }
    else {
        cout << "Details mismatch!!!!";
        exit(0);
    }

}
void Account::modify_account(){
    cout << "Account number" <<accountNumber <<endl;
    cout << "Modify account type: " <<endl;
    cin.ignore();
    cin >> type;
}
void Account::deposit() {
    cout << "Enter the amount you want to deposit: ";
    cin >> depositAmt;
    setBalance(getBalance() + depositAmt);

    map <double,string> myMap;
    myMap.insert(pair<double,string>(depositAmt, " was deposited"));
    cout << "Amount deposited: " <<depositAmt <<endl;
    cout << "Account Balance: " << getBalance() <<endl;
}
void Account::withdraw() {
    cout << "Enter the amount you wish to withdraw: ";
    cin >> withdrawAmt;

    if (withdrawAmt > getBalance()){
        cout << "Insufficient amount in account" <<endl;
        cout << "Your balance is: " << getBalance() <<endl;
        cout << "Enter amount to withdraw based on your balance: ";
        cin >> withdrawAmt;
    }
    else{
        setBalance(getBalance() - withdrawAmt);

        map<double, string> myMap;
        myMap.insert(pair<double, string>(withdrawAmt, " was withdrawn"));

        cout << withdrawAmt << " has been withdrawn." << endl;
        cout << "Account balance: " << getBalance() <<endl;
    }
}
void Account::view_miniStatement() {

    map<double, string> myMap;
    map<double,string> :: iterator itr;
    for (itr = myMap.begin(); itr != myMap.end(); ++itr) {
        cout << " " << itr->first << " " << itr->second << endl;
    }
}
int main(){
    Account acc;
    acc.introduction();
    string answer;
    int choice;
    cout << "Do you want to continue to main menu?('yes or no'): ";
    cin >> answer;

    if (answer == "yes"){
        while (true){
            cout << "1.Deposit money" <<endl;
            cout << "2.Withdraw money" <<endl;
            cout << "3.Modify account" <<endl;
            cout << "4.View mini-statement" <<endl;
            cout << "5.Exit" <<endl;

            cout << "Select your option: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    acc.deposit();
                    break;
                case 2:
                    acc.withdraw();
                    break;
                case 3:
                    break;
                case 4:
                    acc.view_miniStatement();
                    break;
                case 5:
                    cout << "THANK YOU AND WELCOME BACK :)";
                    exit(0);
                default:
                    break;
            }
        }
    }
    else{
        cout << "Thank you but you would have seen more :)";
    }
    return 0;
}