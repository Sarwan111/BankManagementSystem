#include "header files/Structure.h"
#include "header files/createAccount.h"
#include "header files/removeAccount.h"
#include "header files/withdraw.h"
#include "header files/deposit.h"
#include "header files/list.h"
#include "header files/view.h"
#include "header files/transfer.h"
#include "header files/transcation.h"

using namespace std;

void mainscreen(){
	int choice;
	char main;
	system("color a0");
	
	do{
		cout<<"\n\n\n        **********************************************************";
		cout << endl << "        *\t\t" << "Welcome to Knights' Bank\t\t *";
		cout<<"\n        **********************************************************\n\n";
		cout << endl << "\t\t\t" << "||      Main Menu      ||" << endl;
		cout << endl << "\t\t\t" << "1. Create Account" << endl;
		cout << endl << "\t\t\t" << "2. Transaction" << endl;
		cout << endl << "\t\t\t" << "3. View account" << endl;
		cout << endl << "\t\t\t" << "4. View list" << endl;
		cout << endl << "\t\t\t" << "5. Remove Account" << endl;
		cout << endl << "\t\t\t" << "6. Exit" << endl << endl;
		
		cout << "\t\t\t" << "Enter your choice: ";
		cin>>choice;
		system("CLS");
		switch(choice)
		{
			case 1:
				createAccount();
				break;
			case 2:
				transcation();
				break;
			case 3:
				view();
				break;
			case 4: 
				list();
				break;
			case 5: 
				removeAccount();
				break;
			case 6:
				goto exit;
			default:
				cout<<"Invalid Choice !!!";
		}
		
		cout << endl << endl << "Press Any Key to exit or Enter 'Y' to continue to Main Manu: ";
		cin >> main;
		system("CLS");
	}while(main == 'Y' || main == 'y');
	
	exit:
	cout<<"\n\nThanks for visiting us.";
}
