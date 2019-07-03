using namespace std;

void list(){
	FILE *list, *profile;
	perticulars account;
	char printer;
	int line;
	int space;
	int SR = 0;
	
	cout<<"\n\n\n        **********************************************************";
	cout << endl << "        *\t\t" << "Welcome to Knights' Bank\t\t *";
	cout<<"\n        **********************************************************\n\n";	
	
	list = fopen("data//Other//Listed Accounts.txt", "r");
	
	cout << "SR     ";
	cout << "Ac# Number   ";
	cout << "Title";
	// creating spaces to display data properly
	for(int i = 0; i < 20; i++)
		cout << " ";
	cout << "Current Amount" << endl << endl;
	
	if(list == NULL)
		return;
	
	while(!feof(list)){
		char address[] = "data//Accounts//";
		fscanf(list, "%s", account.account_number);
		if(!feof(list)){
			
			//displaying serial number and account number
			strcat(address, account.account_number);
			strcat(address, ".txt");
			
			SR++;
			if(SR < 10){
				cout << "0" << SR << "     ";
			}else{
				cout << SR << "     ";
			}
			
			space = 0;
			cout << account.account_number;
			for(int i = 0; i < 13-(strlen(account.account_number)); i++){
				cout << " ";
			}
			
			// displaying data from file
			line = 0;
			space = 0;
			profile = fopen(address, "r");
			while(!feof(profile)){
				fscanf(profile, "%c", &printer);
				if(printer == '\n'){
					line++;
					printer = ' ';
					if(line == 6)
						for(int i = 0; i < (25-space); i++){
							cout << " ";
						}
				}
				if(line == 0){
					cout << printer;
					space++;
				}else if(line == 6){
					fscanf(profile, "%f", &account.amount);
					printf("Rs. %.2f", account.amount);
				}
			}
			cout << endl << endl;
			fclose(profile);
		}
	}
	
	fclose(list);
}
	
