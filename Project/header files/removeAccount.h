using namespace std;

void removeAccount(){
	FILE *list, *copy, *account;
	char number[13];
	
	cout<<"\n\n\n        **********************************************************";
	cout << endl << "        *\t\t" << "Welcome to Knights' Bank\t\t *";
	cout<<"\n        **********************************************************\n\n";
	
	int read = 0;
	perticulars delete_acc;
	char location[] = "data//Accounts//";
	cout << endl << "Enter Account Number to Removing : ";
	cin.ignore();
	cin.getline(delete_acc.account_number, 13);
	strcat(location, delete_acc.account_number);
	strcat(location, ".txt");
	
	//checking whether account exist or not!!!
	account = fopen(location, "r");
	if(account == NULL){
		cout << endl << "Account does not exist" << endl;
		return;
	}
	fclose(account);
	remove(location);
	
	// if account number matches not copying data and if matches copying data in new file
	
	list = fopen("data//Other//Listed Accounts.txt", "r");
	copy = fopen("data//Other//copy.txt", "w");
	
	while(!feof(list)){
		fscanf(list, "%s", number);
		if(!feof(list)){
			if(strcmp(delete_acc.account_number, number))
				fprintf(copy, "%s\n", number);
		}
	}
	
	fclose(copy);
	fclose(list);
	
	//replacing old file with new file
	
	remove("data//Other//Listed Accounts.txt");
	rename("data//Other//copy.txt", "data//Other//Listed Accounts.txt");
	
	cout << endl << "Account removed successflly" << endl;
}
