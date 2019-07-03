using namespace std;

void view(){
	//Declaring variables and file pointers
	FILE *profile, *listed;
	perticulars account;
	char printer;
	char location[] = "data//Accounts//";
	int number_of_line = 0;
	
	cout<<"\n\n\n        **********************************************************";
	cout << endl << "        *\t\t" << "Welcome to Knights' Bank\t\t *";
	cout<<"\n        **********************************************************\n\n";
	
	//Asking account number to view
	cout<<"Enter Account Number to view details: ";
	cin>>account.account_number;
	
	//Merging account number to find it's address
	strcat(location, account.account_number);
	strcat(location, ".txt");
	
	cout << endl;
	
	//Opening the file
	profile=fopen(location,"r");
	
	//Checking whether file exist or not
	if(profile == NULL){
		cout << "Account does not exist" << endl;
		return;
	}
	
	cout << "Name:                ";
	
	//Reading the file and printing it
	while(!feof(profile)){
		
		fscanf(profile, "%c", &printer);
		cout << printer;
		
		//Printing tags of information type by checking line numbers and displaying them
		if(printer == '\n'){
			cout << endl;
			number_of_line++;
			if(number_of_line == 1){
				cout << "Address:             ";
			}else if(number_of_line == 2){
				cout << "Date of Birth:       ";
			}else if(number_of_line == 3){
				cout << "ID number:           ";
			}else if(number_of_line == 4){
				cout << "Account Number:      ";
			}else if(number_of_line == 5){
				cout << "Account type:        ";
			}else if(number_of_line == 6){
				cout << "Amount:              Rs. ";
			}
		}	
	}
	
	fclose(profile);
}
