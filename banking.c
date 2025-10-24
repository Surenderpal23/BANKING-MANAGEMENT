  #include<stdio.h>
 #include<string.h>

 int   All_Account_Numbers[100];
char   All_Names[100][100]; 
float All_Balances[100];
int Account_Number = 1001;
int Total_Account = 0;

void CreateAccount();
void DepositMoney();
void WithdrawMoney();
void CheckBalance();
void DeleteAccount();
void ViewAllAccounts();

int main(){

    int Choice;

   do {
        printf("=================================================\n");
        printf("         WELCOME TO THE BANKING SYSTEM\n");
        printf("=================================================\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Account Details\n");
        printf("5. Delete Account \n");
        printf("6. View All Accounts\n");
        printf("7. Exit\n");
        printf("-------------------------------------------------\n");
        printf("Enter Your Choice: ");


        if (scanf("%d", &Choice) != 1){
            while (getchar() != '\n');
            printf("Invalid Input. Please Enter a Number.\n\n");
            Choice = 0;
        }

        switch (Choice){
            case 1:
                CreateAccount();
                break;

            case 2:
                DepositMoney();
                break;

            case 3:
                WithdrawMoney();
                break;

            case 4:
                CheckBalance();
                break;

            case 5: 
                DeleteAccount();
                break;

            case 6:
                ViewAllAccounts();
                break;

            case 7:
                printf("THANK YOU FOR BANKING WITH US. GOODBYE!\n");
                break;

            case 0:
                break;

            default:
                printf("INVALID CHOICE. Please select from 1 to 7.\n\n");
                break;
                
        }
        if (Choice != 7){
            printf(" Continue...\n");
            while (getchar() != '\n'); 
            getchar();                  
        }

    }  while (Choice != 7); 
       return 0; 
}


void CreateAccount(){

    char New_Name[100];
    float New_Balance;

    printf("CREATE NEW ACCOUNT \n");

    if(Total_Account>=100){
        printf("SORRY, THE BANK  DOESN'T HAVE ENOUGH SPACE \n\n");
        return;
    }
    
    printf("ENTER NAME (single word only): ");
    scanf("%s",New_Name);
    
    printf("ENTER INITIAL DEPOSIT(minimum 500): ");
    if(scanf("%f", &New_Balance) !=1){
        while (getchar() != '\n');
        printf("Invalid input. Please enter a valid amount.\n\n");
        return;
    }

    if (New_Balance < 500){
        printf("INITIAL DEPOSIT MUST BE ATLEAST 500 \n\n");
        return;
    }

    All_Account_Numbers[Total_Account] = Account_Number;
    strcpy(All_Names[Total_Account],New_Name);
    All_Balances[Total_Account] = New_Balance;

    printf("========================================\n");
    printf("    ACCOUNT CREATED SUCCESSFULLY!\n");
    printf("========================================\n\n");
    printf("YOUR NEW ACCOUNT NUMBER IS:     %d\n", Account_Number);
    printf("HOLDER'S NAME:                  %s\n", New_Name);
    printf("An initial deposit:             %.2f\n\n", New_Balance);

    Account_Number++;
    Total_Account++;
}

void DepositMoney(){

    int Account_Num;
    float Deposit_Amount;
    int Account_Index = -1;

    printf("ENTER ACCOUNT NUMBER: ");
    if (scanf("%d", &Account_Num) != 1){
    while (getchar() != '\n');
    printf("Invalid input. Please enter a valid account number.\n\n");
    return;
}

    for (int i = 0; i < Total_Account; i++){
        if (All_Account_Numbers[i] == Account_Num){
            Account_Index = i;
            break;
        }
    }

    if (Account_Index == -1){
        printf("ACCOUNT NOT FOUND.\n\n");
        return;
    }

    printf("ENTER AMOUNT TO DEPOSIT: ");
    if(scanf("%f", &Deposit_Amount) !=1){
        while (getchar() != '\n');
        printf("Invalid input. Please enter a valid amount.\n\n");
        return;
}

    if (Deposit_Amount <= 0){
        printf("YOU MUST DEPOSIT SOME MONEY.\n\n");
        return;
    }

    All_Balances[Account_Index] += Deposit_Amount;
    printf("SUCCESS! NEW BALANCE IS: %.2f\n\n", All_Balances[Account_Index]);
}


void WithdrawMoney(){

    int Account_Num;
    float Withdraw_Amount;
    int Account_Index = -1;

    printf("ENTER ACCOUNT NUMBER: ");
    if (scanf("%d", &Account_Num) != 1){
        while (getchar() != '\n');
        printf("Invalid input. Please enter a valid account number.\n\n");
        return;
}
    

    for (int i = 0; i < Total_Account; i++){
        if (All_Account_Numbers[i] == Account_Num){
            Account_Index = i;
            break;
        }
    }

    if (Account_Index == -1){
        printf("ACCOUNT NOT FOUND.\n\n");
        return;
    }

    printf("ENTER AMOUNT TO WITHDRAW: ");
    if(scanf("%f", &Withdraw_Amount) != 1){
        while (getchar() != '\n');
        printf("Invalid input. Please enter a valid amount.\n\n");
        return;
}


    if (Withdraw_Amount <= 0){
        printf("INVALID AMOUNT.\n\n");
        return;
    }

    if (All_Balances[Account_Index] - Withdraw_Amount < 500){
        printf("INSUFFICIENT FUNDS.\n");
        printf("A MINIMUM BALANCE OF 500 MUST BE MAINTAINED.\n");
        printf("YOUR CURRENT BALANCE IS: %.2f\n\n", All_Balances[Account_Index]);
        return;
    }

    All_Balances[Account_Index] -= Withdraw_Amount;
    printf("\nSUCCESS! NEW BALANCE IS: %.2f\n\n", All_Balances[Account_Index]);
}


  void CheckBalance(){

    int Account_Num;
    int Account_Index = -1;

    printf("ENTER ACCOUNT NUMBER: ");
    if (scanf("%d", &Account_Num) != 1){
        while (getchar() != '\n');
        printf("Invalid input. Please enter a valid account number.\n\n");
        return;
}

    for (int i = 0; i < Total_Account; i++){
        if (All_Account_Numbers[i] == Account_Num){
            Account_Index = i;
            break;
        }
    }

    if (Account_Index == -1){
        printf("ACCOUNT NOT FOUND.\n\n");
        return;
    }

    printf(" ACCOUNT DETAILS: \n");
    printf("ACCOUNT NUMBER: %d\n", All_Account_Numbers[Account_Index]);
    printf("HOLDER'S NAME : %s\n", All_Names[Account_Index]);
    printf("CURRENT BALANCE: %.2f\n\n", All_Balances[Account_Index]);
}


void ViewAllAccounts(){
    printf("=================================================\n");
    printf("               ALL BANK ACCOUNTS:\n");
    printf("=================================================\n");

    if (Total_Account == 0){
        printf("NO ACCOUNTS HAVE BEEN CREATED YET.\n\n");
        return;
    }

    printf(" %-15s  %-20s  %-10s \n", "ACCOUNT NO.", "NAME", "BALANCE");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < Total_Account; i++){
        printf(" %-15d  %-20s  %-10.2f \n", All_Account_Numbers[i], All_Names[i], All_Balances[i]);
    }
    printf("=================================================\n\n");
}


void DeleteAccount(){
    
  int Account_Num;
  int Account_Index= -1;

  printf("ENTER ACCOUNT NUMBER TO DELETE: ");
  if(scanf("%d",&Account_Num) !=1){
     while(getchar() !='\n');
     printf("INVALID INPUT.PLEASE ENTER A VALID ACCOUNT NUMBER. \n\n");
     return;
  }

  for(int i=0; i<Total_Account; i++){
    if (All_Account_Numbers[i]==Account_Num){
        Account_Index=i;
        break;
    }
  }

  if(Account_Index == -1){
    printf("ACCOUNT NOT FOUND. \n\n");
    return;
  } 

  printf("ARE YOU SURE, YOU WANT TO DELETE ACCOUNT %d of %s (Y/N)?",Account_Num,All_Names[Account_Index]);
  char confirm;
  scanf(" %c",&confirm);
  if(confirm!='Y' && confirm!='y'){
    printf("ACCOUNT DELETION CANCELLED.\n\n");
    return;
  }

  for (int i=Account_Index; i< Total_Account -1; i++){
    All_Account_Numbers[i] = All_Account_Numbers[i+1];
    strcpy(All_Names[i],All_Names[i+1]);
    All_Balances[i] = All_Balances[i+1];
  }

  Total_Account--;

  printf("SUCCESS! ACCOUNT NUMBER %d DELETED.\n\n", Account_Num);
}