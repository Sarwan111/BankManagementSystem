using namespace std;

void createAccount(){
	
	//Declaring variables and pointers needed
	FILE *profile, *listed;
	perticulars account;
	char location[] = "data//Accounts//";
	char compare[30];
	char test[10];
	
	cout<<"\n\n\n        **********************************************************";
	cout << endl << "        *\t\t" << "Welcome to Knights' Bank\t\t *";
	cout<<"\n        **********************************************************\n\n";
	
	cin.getline(test, 10);
	
	//Taking perticlulars of for accont with input
	cout << "\t\t\t||   Creat Account Menu   ||" << endl << endl;
	cout << endl << "\t\tName: ";
	cin.getline(account.Name, 30);
	cout << endl << "\t\tAddress: ";
	cin.getline(account.Address, 100);
	cout << endl << "\t\tDate of Birth: ";
	cin.getline(account.DOB, 11);
	cout << endl << "\t\tID number: ";
	cin.getline(account.ID_number, 30);
	account_again:
	
	cout << endl << "\t\tChoose Account Type\n\n\t\tSaving or Current\n\n\t\tAccount type: ";
	cin.getline(account.account_type, 13);
	
	if(strcmp(account.account_type,"Saving")==0||strcmp(account.account_type,"Current")==0||strcmp(account.account_type,"saving")==0||strcmp(account.account_type,"SAVING")==0||strcmp(account.account_type,"current")==0||strcmp(account.account_type,"CURRENT")==0){
		
		goto cont;
		
	}
	else {cout<<"\t\tInvailed Account Type!!\n\t\tIt Should be Saving or Current";
		 goto account_again;};
	cont:
	
	cout << endl << "\t\tAccount Number: ";

label:
	cin.getline(account.account_number, 13);
	
	//Cheacking whether account number is available
	listed	= fopen("data//Other//Listed Accounts.txt", "r");
	while(!feof(listed)){
		fscanf(listed, "%s", compare);
		if(strcmp(compare, account.account_number) == 0){
			cout << "This account number is already in use!" << endl;
			cout << "Please enter another account number: ";
			goto label;
		}
	}
	fclose(listed);
	
	i_again:
	
	cout << endl << "\t\tInitial amount: Rs. ";
	cin >> account.amount;
	
	if(account.amount < 0){
		cout << endl << "\t\tAmount can not be Initialized." << endl;
		cout << endl << "\t\tInitial amount is less than Rs. 0.00" << endl;
		cout << endl << "\t\tIt should be greater than or equal to Rs. 0.00" << endl;
		goto i_again;
	}
	
	
	//Marging account number to .txt and address to create file name
	strcat(location, account.account_number);
	strcat(location, ".txt");
	
	//Creating and opening account file
	profile = fopen(location, "w");
	
	//saving account number in record file
	listed	= fopen("data//Other//Listed Accounts.txt", "a");
	fprintf(listed, "%s\n", account.account_number);
	fclose(listed);
	
	//Recording information to account file
	fprintf(profile, "%s\n", account.Name);
	fprintf(profile, "%s\n", account.Address);
	fprintf(profile, "%s\n", account.DOB);
	fprintf(profile, "%s\n", account.ID_number);
	fprintf(profile, "%s\n", account.account_number);
	fprintf(profile, "%s\n", account.account_type);
	fprintf(profile, "%0.2f\n", account.amount);
	
	fclose(profile);
	
	cout << endl << "\n\t\tAccount created successfully!";
}
