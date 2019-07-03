using namespace std;

void deposit(){
	//Creating file pointer, file location and struct variable for account	
	FILE *profile, *temp;
	perticulars account;
	char location[] = "data//Accounts//";
	int end_of_line = 0;
	char seeking;
	
	cout<<"\n\n\n        **********************************************************";
	cout << endl << "        *\t\t" << "Welcome to Knights' Bank\t\t *";
	cout<<"\n        **********************************************************\n\n";
	
	//Taking account number and depositing amount
	printf("Enter account number: ");
	scanf("%s", &account.account_number);
	
	//converting account number to it's folder location
	strcat(location, account.account_number);
	strcat(location, ".txt");
	
	//opening account file for reading
	profile = fopen(location, "r");
	
	//Cheaking the validity of account number
	if(profile == NULL){
		cout << "Invalid account number!!" << endl;
		return;
	}
	
	//reading the current amount from the account number and printing it
	while(end_of_line  < 6){
		fscanf(profile, "%c", &seeking);
		if(seeking == '\n')
			end_of_line++;
	}
	fscanf(profile, "%f", &account.amount);
	cout << endl << "Current amount: Rs. " << account.amount << endl << endl;
	
	de_again:
	
	//Asking amount from the user
	printf("Enter depositing amount: Rs. ");
	scanf("%f", &account.depositing_amount);
	
	//Cheaking validity of amount
	if(account.depositing_amount <= 0){
	cout << endl << "Amount can not be deposited" << endl;
		cout << endl << "Depositing amount is greater than current amount" << endl;
		cout << endl << "Or less than zero" << endl;
		goto de_again;
	}
	
	//adding the current and depositing amount
	account.amount = account.depositing_amount + account.amount;
	
	//Setting cursor back to initial position in account file
	fseek(profile, 0, SEEK_SET);

	//Creating and opening new file to write updated data
	temp = fopen("data//Accounts//temp.txt", "w");
	
	//extra code to
	char loc[] = "data//Accounts//";
	strcat(loc, account.account_number);
	strcat(loc, ".txt");
	//solve the isssue
	
	
	//Writing the latest data into new file created
	end_of_line = 0;
	while(end_of_line < 6){
		fscanf(profile, "%c", &seeking);
		fprintf(temp, "%c", seeking);
		if(seeking == '\n')
			end_of_line++;
	}
	fprintf(temp, "%0.2f", account.amount);
	
	//Closing both files
	fclose(temp);
	fclose(profile);
	
	//removing the old file and renaming the new file with old file name
	remove(loc);
	rename("data//Accounts//temp.txt", loc);
	
	cout << endl << "Transaction successfully performed!" << endl;
	cout << endl << "New current amount is: Rs. " << account.amount;
}
