#include <iostream>
#include <string>
using namespace std;

int accNumGenerator = 1001;
int accountCount = 0;

// CLASS 
class BankAccount {
    private:
     string username;
     int accountNumber;
     double balance;
    
    public:
    // CONSTRUCTORS
    BankAccount(){
        balance = 0;
    }
    
    BankAccount(string username,int  accountNumber, double balance){
        this->username = username;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }
    
    // MEMBER FUNCTIONS
     double depositMoney(double money){
        balance = balance + money;
        return balance;
     }
     
     double withdrawMoney(double money){
         if(balance >= money){
            balance = balance - money;    
            return balance;
         } else {
             return 0;
         }
     }
     
    void showDetails(){
        cout << "Account Holder : " << username << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance : " << balance << endl;
    }
     
    // GETTER FUNCTION
    int getAccountNumber(){
        return accountNumber;
    }
    
    double checkBalance(){
        return balance;
    }
     
};


// NORMAL FUNCTION
BankAccount createAccount();

// MAIN FUNCTION
int main()
{
    BankAccount accounts[10];
    
    // ENTERING USER OPERATION TYPE
    int firstChoice;
    
do{
    int selectedIndex = -1;
    int enteredAccNum;
    cout << "*************** Welcome to Our Bank Service *************\n";
    cout << "Choose Your Operation : \n";
    cout << "1. Create a new Account\n2. Access Account\n";
    cout << "3. Exit\n";
    cin >> firstChoice;
    
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
    }
    
    if(firstChoice == 1){
        accounts[accountCount] = createAccount();
        selectedIndex = accountCount;
        cout << "Account Created Succesfully :) \n";
        accountCount++;
    }
    
    if(firstChoice == 2){
        cout << "Enter Your Account Number : \n";
        cin >> enteredAccNum;
        for(int i = 0; i < accountCount; i++){
            if(enteredAccNum == accounts[i].getAccountNumber()){
                selectedIndex = i;
                break;
            } 
        }
        if(selectedIndex == -1){
                cout << "No Account Found With ENtered Account Number :(\n";
                continue;
        }
    }
    
    // MENU BAR
    int secondChoice;  
    if(selectedIndex != -1){
        int temp;
        int returnValue;
        do{
            cout << "************** Choose Your Choice: ******************\n\n";
            cout << "1. Deposit Money \n2. Withdraw Money\n3. Check Balance\n";
            cout << "4. Show Bank Details\n5. Exit\n";
            cin >> secondChoice;
            
            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
            }
            switch(secondChoice)  {
                    case 1 : cout << "Enter Money To Deposit : \n";
                             cin >> temp;
                             returnValue = accounts[selectedIndex].depositMoney(temp);
                             cout << "Money Depsoited Succesfully\n";
                             break;
                             
                    case 2 : cout << "Enter Money To withdraw : \n";
                             cin >> temp;
                             returnValue = accounts[selectedIndex].withdrawMoney(temp);    
                             if(returnValue == 0){
                                 cout <<  "Not Enough Balance Try Again Later :( \n";
                             } else {
                                cout << "Money withDrawed Succesfully\n";    
                             }
                             break;
                             
                    case 3 : returnValue = accounts[selectedIndex].checkBalance();
                             cout << "Balance is : " << returnValue << endl;;
                             break;
                             
                    case 4 : accounts[selectedIndex].showDetails();
                             break;
                             
                    case 5 : cout << "Thank You for visiting :)\n";
                             break;
            } 
        }while(secondChoice != 5);
    }
    
} while(firstChoice != 3);
    
    cout << "Thnak You For Visiting Our Service ;) \n";
    return 0;
}


BankAccount createAccount(){
    string name;
    int initialDeposit;
    cout << "Create Your Bank Account Easily :) \n";
    cin.ignore(); // <-- clear newline left in buffer
    
    cout << "Enter Your Full Name : \n";
    getline(cin, name);
    
    cout << "Enter Your account You want to Deposit Initially :\n";
    cin >> initialDeposit;
    
    BankAccount newAcc(name, accNumGenerator, initialDeposit);
    accNumGenerator++;
    
    return newAcc;
   
}



