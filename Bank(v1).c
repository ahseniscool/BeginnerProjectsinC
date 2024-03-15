#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct Bank_Account {
    char name[16];
    char Username[16];
    char Password[16];
    double Amount;
} Bank_Account;
/*************************************************************************/

void startscreen(Bank_Account[],int);
void login(Bank_Account[],int y,int x);
void printline(void);
void loggedin(Bank_Account[],int);
void Deposit(Bank_Account[],int);
void withdraw (Bank_Account[],int);
void createaccount(Bank_Account[],int);
/*************************************************************************/

int
main(int argc, char *argv[]) {

    int n = 3;
    Bank_Account TestAccount1 = {"Gaeti", "Crazycookies1000" ,"FluffySmokey",100.25};
    Bank_Account TestAccount2 = {"Ahsen", "Garymeister" ,"Kirbysayshi",1000000};
    Bank_Account TestAccount3;
    Bank_Account accounts[] = {TestAccount1,TestAccount2,TestAccount3};

    startscreen(accounts,n);
}

/*************************************************************************/

void 
startscreen(Bank_Account accounts[],int n) { 

int userinput = 0;
printline();
printf("Welcome to Bank of Ahsen\nEnter 1 to Login\nEnter 2 to Create an account\nEnter anything else to exit\n");

scanf ("%d", &userinput); 
    if ( userinput == 1) {
        login(accounts,n,5); // 5 maximum login attempts
    } else if (userinput == 2) {
        createaccount(accounts,n);
    } else {
        printf("Exiting\n");
        exit(0);
    }

}
/*************************************************************************/

void 
login(Bank_Account accounts[], int n, int attempts) {


    if ( attempts <= 0 ) {
        printf("maximum login attempts exceeded, exiting program\n");
        return;
    }

    char username[16];
    char password[16];

    printline();
    printf("Please Enter Your Username\n");
    scanf(" %s", username);
    printf("Please Enter Your Password\n");        
    scanf(" %s", password);

    for ( int i = 0; i < n; i++ ) {
        if ( !strcmp(username,accounts[i].Username) && !strcmp(password,accounts[i].Password) ) {
            loggedin(accounts,i);
            return;
            }
    }

    printf("Incorrect Credtintials, please try login again\n");
    login(accounts,n, attempts-1) ;

}

/*************************************************************************/
// shows options an dwhat you can do once actually logged in 
// n in this case is the number in the accounts array which has been accessed 
void
loggedin (Bank_Account accounts[], int n) {
    int userinput = 0;
    printline();
    printf("Hello %s\n",accounts[n].name);    
    printf("To withdraw money, enter 1\nTo Deposit Money, enter 2\nTo Cease operations, enter 3\n");
    scanf(" %d", &userinput);
    if (userinput == 1 ) {
        Deposit(accounts,n);
        loggedin(accounts,n);
    } else if ( userinput == 2) {
        withdraw (accounts,n);
        loggedin(accounts,n);
    } else if (userinput == 3 ) {
        exit(0);
    } else {
        printf("Invalid input, try again\n");
        loggedin(accounts,n);
    }
}
/*************************************************************************/
void 
withdraw (Bank_Account accounts[], int n) {
    double drawn = 0;
    printf("You have %f$ in your account\n How muuch Would you like to widthdraw ?\n",accounts[n].Amount);

        scanf(" %lf", &drawn);
        if ( drawn > accounts[n].Amount || drawn < 0 ) {
            printf("Insufficient funds\n");
        } else {
            accounts[n].Amount -= drawn;
            printf("%f$ Deposited\n Current Balance is %f$ \n ",drawn,accounts[n].Amount);
        }
        loggedin(accounts,n);
}
/*************************************************************************/

void 
Deposit(Bank_Account accounts[], int n) {
    double drawn = 0;
    printf("You have %f$ in your account\n How muuch Would you like to widthdraw ?\n",accounts[n].Amount);
    scanf(" %lf", &drawn);
    accounts[n].Amount += drawn;
    printf("%f$ Drawn\n Current Balance is %f$ \n ",drawn,accounts[n].Amount);
    loggedin(accounts,n);
}
/*************************************************************************/
void 
createaccount( Bank_Account accounts[],int n) {

    char username[16];
    char password[16];
    printline();

    printf("Please enter A usernamme between 0-16 characters long\nEnter ""EXIT to quit""\n");
    scanf("%s", username);

    if ( !strcmp(username,"EXIT") ) {
           startscreen(accounts,n);
        }
    for ( int i = 0 ; i < n; i++ ) {
        if ( !strcmp(username,accounts[i].Username) ) {
            printf("This username already exists, please try again\n");
            createaccount(accounts,n);
        } 
    }

    strcpy(accounts[n-1].Username,username);
    printf("Please enter A password between 0-16 characters long\n");
    scanf("%s", password);

    for ( int i = 0 ; i < n; i++ ) {
        if ( !strcmp(password,accounts[i].Password ) ) {
            printf("This password already exists, please try again\n");
            createaccount(accounts,n);
        } 
    }

    strcpy(accounts[n-1].Password,password); 

    printf("Account with username %s Created\n", username);
    login(accounts,n,5);
}
/*************************************************************************/
void 
printline(){
printf("\n--------------------------------------------------------\n--------------------------------------------------------\n\n");
/*************************************************************************/
}