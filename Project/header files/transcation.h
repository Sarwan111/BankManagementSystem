using namespace std;

void transcation(){
	
	int choice;	
	
	cout<<"\n\n\n        **********************************************************";
	cout << endl << "        *\t\t" << "Welcome to Knights' Bank\t\t *";
	cout<<"\n        **********************************************************\n\n";
	cout << endl << "\t\t" << "||      Transcation Menu      ||" << endl;
	
	cout << endl << endl; 
	cout << "1. Deposit" << endl << endl;
	cout << "2. Withdraw" << endl << endl;
	cout << "3. Transfer" << endl << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	
	system("CLS");
	
	if(choice == 1){
		deposit();
	}else if(choice == 2){
		withdraw();
	}else if(choice == 3){
		transfer();
	}
}
