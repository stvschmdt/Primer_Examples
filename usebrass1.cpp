#include <iostream>
#include "brass.h"

int main(){
	using std::cout;	
	using std::endl;

	Brass Piggy("Porcelaine Pigg", 381299, 4000.00);
	BrassPlus Huggy("Horatio Hugg", 382288, 3000.00);
	Piggy.ViewAcct();	
	cout << endl;
	Huggy.ViewAcct();	
	cout << endl;
	cout << "Depositing $1000 into the Hugg Account:\n";
	Huggy.Deposit(1000.00);
	cout << "New balance: $: " << Huggy.Balance() << endl;
	cout << "Withdrawing $4200 from the Pigg Account:\n";
	Piggy.Withdraw(4200.00);
	cout << "Pigg account balance: $" << Piggy.Balance() << endl;
	cout << "Withdrawing $4200 from the Hogg account:\n";
	Huggy.Withdraw(4200.00);
	Huggy.ViewAcct();


return 0;
}
