using namespace std;

void transfer(){
	//Declaring varibales and pointers
	FILE *sender, *receiver, *temp;
	perticulars account;
	char location[] = "data//Accounts//";
	char location_r[] = "data//Accounts//";
	int end_of_line = 0;
	char seeking;
	
	cout<<"\n\n\n        **********************************************************";
	cout << endl << "        *\t\t" << "Welcome to Knights' Bank\t\t *";
	cout<<"\n        **********************************************************\n\n";
	
	//Taking sender and reciever account amount from user
	cout << endl << endl;
	printf("Enter sender account number: ");
	scanf("%s", &account.account_number);
	cout << endl << endl;
	printf("Enter reciever account number: ");
	scanf("%s", &account.recieving_number);
	
	//converting sender account number to it's folder location
	strcat(location, account.account_number);
	strcat(location, ".txt");
	
	//converting reciever account number to it's folder location
	strcat(location_r, account.recieving_number);
	strcat(location_r, ".txt");
	
	//opening both account files for reading account
	sender = fopen(location, "r");
	receiver = fopen(location_r, "r");
	
	//Cheaking whether account exist or not
	if(receiver == NULL){
		cout << endl << "Invalid sender account number" << endl;
		return;
	}
	if(sender == NULL){
		cout << endl << "Invalid sender account number" << endl;
		return;
	}
	
	//reading the current amount from the sender account
	while(end_of_line  < 6){
		fscanf(sender, "%c", &seeking);
		if(seeking == '\n')
			end_of_line++;
	}
	fscanf(sender, "%f\n\n", &account.amount);
	
	am_again:
	
	//Taking transfer amount from user
	printf("Enter transfering amount: Rs. ");
	scanf("%f", &account.transfering_amount);
	
	//Checking whether amount is transferable or not
	if(account.transfering_amount > account.amount || account.transfering_amount <= 0){
		cout << endl << endl;
		cout << "Transaction can not be performed" << endl;
		cout << "Transfering amount is greater than" << endl; 
		cout << "current amount of sender account" << endl;
		cout << "or transfer amount is less than zero" << endl;
		cout<<"Enter amount again\n";
		goto am_again;
	}
	
	//Subtracting the transfering amount from current amount of sender account
	account.amount = account.amount - account.transfering_amount;
	
	//Setting cursor back to initial position	
	fseek(sender, 0, SEEK_SET);
	
	//Creating and opening a new file to record updated data for sender account
	temp = fopen("data//Accounts//temp.txt", "w");
	
	//extra code
	char loc[] = "data//Accounts//";
	strcat(loc, account.account_number);
	strcat(loc, ".txt");
	//solve the isssue
	
	//Writing the updated data of sender account into a new file 
	end_of_line = 0;
	while(end_of_line < 6){
		fscanf(sender, "%c", &seeking);
		fprintf(temp, "%c", seeking);
		if(seeking == '\n')
			end_of_line++;
	}
	fprintf(temp, "%0.2f", account.amount);
	
	//Cloasing both new file and sender account file
	fclose(temp);
	fclose(sender);
	
	//removing the sender account file and renaming the new file with sender account file
	remove(loc);
	rename("data//Accounts//temp.txt", loc);
	
	/*
	
	
	
	Part 2 : Adding amount to recieving account
	
	
	*/
	
	end_of_line = 0;
	
	//reading the current amount from the recieving account number
	while(end_of_line  < 6){
		fscanf(receiver, "%c", &seeking);
		if(seeking == '\n')
			end_of_line++;
	}
	fscanf(receiver, "%f", &account.amount);
	
	//Adding transfering amount to current amount of recieving account
	account.amount = account.transfering_amount + account.amount;
	
	//Setting cursor back to initial position	
	fseek(receiver, 0, SEEK_SET);

	//Creating and opening a new file to write updated data of recieving account
	temp = fopen("data//Accounts//temp.txt", "w");
	
	//extra code
	char loc_r[] = "data//Accounts//";
	strcat(loc_r, account.recieving_number);
	strcat(loc_r, ".txt");
	//solve the isssue
	
	//Writing the updated data into the new file
	end_of_line = 0;
	while(end_of_line < 6){
		fscanf(receiver, "%c", &seeking);
		fprintf(temp, "%c", seeking);
		if(seeking == '\n')
			end_of_line++;
	}
	fprintf(temp, "%0.2f", account.amount);
	
	//Closing the new and receiving account
	fclose(temp);
	fclose(receiver);
	
	//removing the receiving account and renaming the new file with recieving account
	remove(loc_r);
	rename("data//Accounts//temp.txt", loc_r);
	
	cout << endl << "Transaction successfully performed" << endl;
}
