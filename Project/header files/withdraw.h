using namespace std;

void withdraw(){
	//Creating file pointer, file location and struct variable for account	
	FILE *profile, *temp;
	perticulars account;
	char location[] = "data//Accounts//";
	int end_of_line = 0;
	char seeking;
	
	cout<<"\n\n\n        **********************************************************";
	cout << endl << "        *\t\t" << "Welcome to Knights' Bank\t\t *";
	cout<<"\n        **********************************************************\n\n";
	
	//Taking account number and withdraw amount
	
	printf("Enter account number: ");
	scanf("%s", &account.account_number);
	
	//converting account number to it's folder location
	strcat(location, account.account_number);
	strcat(location, ".txt");
	
	//opening account file for reading
	profile = fopen(location, "r");
	
	//Cheaking the validity of account number and amount
	if(profile == NULL){
		cout << "Invalid account number." << endl;
		return;
		
		
	}
	
	//reading the current amount from the account number
	while(end_of_line  < 6){
		fscanf(profile, "%c", &seeking);
		if(seeking == '\n')
			end_of_line++;
	}
	fscanf(profile, "%f", &account.amount);
	cout << endl;
	cout << "Current Amount: Rs. " << account.amount << endl << endl;
	
	w_again:
	
	//Taking withdraw amount from user
	printf("Enter withdraw amount: Rs. ");
	scanf("%f", &account.withdraw_amount);
	
	//Cheaking Validity of amount
	if(account.withdraw_amount > account.amount || account.withdraw_amount < 0){
		cout << endl << "Amount can not be withdrawn" << endl;
		cout << endl << "Withdrawn amount is greater than current amount" << endl;
		cout << endl << "Or less than zero" << endl;
		goto w_again;
	}
	
//	adding the current and withdraw amount
	account.amount = account.amount - account.withdraw_amount;
	
	//Setting cursor back to initial position	
	fseek(profile, 0, SEEK_SET);

	//Creating and opening a new file, where new data will be updated
	temp = fopen("data//Accounts//temp.txt", "w");
	
	//extra code
	char loc[] = "data//Accounts//";
	strcat(loc, account.account_number);
	strcat(loc, ".txt");
	//solve the isssue
	
	//Writing the latest data into new file
	end_of_line = 0;
	while(end_of_line < 6){
		fscanf(profile, "%c", &seeking);
		fprintf(temp, "%c", seeking);
		if(seeking == '\n')
			end_of_line++;
	}
	fprintf(temp, "%0.2f", account.amount);
	
	//cloasing both new and account file
	fclose(temp);
	fclose(profile);
	
	//removing the account file and renaming the new file with old file name
	remove(loc);
	rename("data//Accounts//temp.txt", loc);
	
	cout << endl << "Transaction successfully performed!" << endl;
	cout << endl << "New Current amount is: Rs. " << account.amount;
}
