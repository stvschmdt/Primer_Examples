#include <iostream>
#include <cstring>
#include "brass.h"

using std::cout;
using std::endl;
using std::ios_base;

Brass::Brass(const char *s, long an, double bal){
    std::strncpy(fullName, s, MAX-1);
    fullName[MAX-1] = '\0';
    acctNum = an;
    balance = bal;
}



void Brass::Deposit(double amt){
    if (amt < 0){
	cout << "Deposit amount must be positive; " << "Deposit canceled.\n";

    }
    else{
	balance += amt;
    }
}

void Brass::Withdraw(double amt){
    if (amt < 0){
	cout << "Withdrawal amount must be positive; " << "Withdrawal canceled.\n";

    }
    else if(amt<= balance){
	balance-=amt;
    }
    else{
	cout << "Withdrawal amount of $" << amt << " exceeds your balance.\n" << "Withdrawal canceled.\n";
    }
}

double Brass::Balance() const{
    return balance;
}

void Brass::ViewAcct() const{
    ios_base::fmtflags initialState = cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    cout.setf(initialState);

}

BrassPlus::BrassPlus(const char *s, long an, double bal, double ml, double r) : Brass(s, an, bal){
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : Brass(ba){
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const{
    ios_base::fmtflags initialState = cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);
    Brass::ViewAcct();
    cout << "Maximum Loan: $" << maxLoan << endl;
    cout << "Owed to Bank: $" << owesBank << endl;
    cout << "Loan Rate: " << 100*rate << "%\n" <<endl;
    cout.setf(initialState);

}


void BrassPlus::Withdraw(double amt){
    ios_base::fmtflags initialState = cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);
    double bal = Balance();	

    if(amt <= bal){
	Brass::Withdraw(amt);
    }
    else if(amt<=bal + maxLoan - owesBank){
	double advance = amt-bal;
	owesBank+=advance*(1.0 + rate);
	cout<<"Bank advance: $" << advance*rate <<endl;
	Deposit(advance);
	Brass::Withdraw(amt);
    }

    else{
	cout << "Credit limit exceeded. Transaction canceled.\n";
    }
    cout.setf(initialState);
}


