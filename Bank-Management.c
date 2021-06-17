#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define ADMINNAME 30
#define ADMINPASS 30
#define NAMEUSER 30
#define USERPASS 30


typedef struct admin
{
    char name[ADMINNAME];
    char pass[ADMINPASS];

}admin;


typedef struct user
{
    char username[NAMEUSER];
    char password[USERPASS];

}user;


struct account
{
    int balance;
    int loan;
}s;


void regadmin();
void adminlogin();
void reguser();
void userlogin();


int adminpanel()
{
    printf("\n\n\n\t\t\t\t1.Account Holders: ");
    printf("\n\n\n\t\t\t\t2.Search User Account: ");

}


void loan()
{
    int take;
    system("cls");
    printf("\n\n\n\t\t\t\t||PAGE OF LOAN||");
    printf("\n\t\t\t\t----------------");
    printf("\n\n\t\t\t1.Enter amount of loan: ");
    scanf("%d", &take);
    s.loan=s.loan+take;
    printf("\n\n\t\t\tYou have take loan of %d TK\n", s.loan);
    getch();
    account();

}


void payloan()
{
    int pay;
    system("cls");
    printf("\n\n\n\t\t\t\t||PAGE OF LOAN||");

    if(s.loan==0)
    {
        printf("\n\n\t\t\tCurrently you don't have any due in your bank account.\n");
        getch();
        account();
    }
    else
    {
        printf("\n\n\t\t\tYour Loan is : %d TK\n", s.loan);
        printf("\n\t\t\tEnter amount which you want to pay: ");
        scanf("%d", &pay);
        s.loan=s.loan-pay;
        printf("\n\n\t\t\tYou have paid %d TK, your remaining loan is %d TK\n", pay, s.loan);
        getch();
        account();
    }
}


void account()
{
    int set;


    printf("\n\n\n\t\t\t");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    printf("\n\t\t\t");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");

    printf("\n\n\n\t\t\t");
    printf("^\t1.Deposit Money\t\t  ^");
    printf("\n\n\t\t\t");
    printf("^\t2.Withdraw Money\t  ^");
    printf("\n\n\t\t\t");
    printf("^\t3.View Balance\t\t  ^");
    printf("\n\n\t\t\t");
    printf("^\t4.Take Loan\t\t  ^");
    printf("\n\n\t\t\t");
    printf("^\t5.Pay Loan\t\t  ^");
    printf("\n\n\t\t\t");
    printf("^\t6.Log Out\t\t  ^");

    printf("\n\n\n\t\t\t");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    printf("\n\t\t\t");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    printf("\n\n\t\t\t\t");

    printf("Enter your choice: ");
    scanf("%d", &set);
    switch(set)
    {
    case 1:
        deposit();
        break;
    case 2:
        withdraw();
        break;

    case 3:
        view();
        break;
    case 4:
        loan();
        break;
    case 5:
        payloan();
        break;

    case 6:
        mainmenu();
        break;
    default:
        account();

    }

}


void deposit()
{
    system("cls");
    loading();
    system("cls");
    int amount;
    printf("Enter amount for Deposit: ");
    scanf("%d", &amount);
    s.balance=s.balance+amount;
    printf("After depositing %d TK, your current balance is: %d TK\n", amount, s.balance);
    getch();
    account();
}


void withdraw()
{
    system("cls");
    loading();
    system("cls");
    int money;
    printf("Enter amount for withdraw: ");
    scanf("%d", &money);
    if(money>s.balance)
    {
        printf("Your balance is Insufficient\n");
    }
    else
    {
        s.balance=s.balance-money;
    }

    printf("Your Current Balance is: %d\n", s.balance);

    getch();
    account();
}


void view()
{
    system("cls");
    loading();
    system("cls");
    printf("Your Current Balance is: %d\n", s.balance);
    getch();
    account();
}


void regadmin()
{
    printf("\n\n\t\t\t\t\t||ADMIN REGISTRAION PAGE||\n\n");

    admin n;
    admin file;
    int samename=0;

    FILE *fp;

    printf("Name: ");
    fflush(stdin);
    fgets(n.name, ADMINNAME, stdin);

    printf("Password: ");
    fgets(n.pass, ADMINPASS, stdin);


    fp = fopen("adminregistration.txt","a+");

    if (fp == NULL) {
        fp = fopen("adminregistration.txt","w+");
    }


    while(fread(&file, sizeof(admin), 1, fp)) {

        if (strncmp(file.name, n.name, ADMINNAME) == 0) {

            printf("Name already exists.\n\n");
            regadmin();

            samename = 1;

            break;
        }
    }


    if(samename == 0){

        fwrite(&n, sizeof(admin), 1, fp);
    }


    fclose(fp);

    back();

}


void back()
{
    int choose;

    printf("Press '1' to login or '0' to back in main menu: ");
    scanf("%d", &choose);

    switch(choose)
    {

    case 1:
        system("cls");
        loading();
        adminlogin();
        mainmenu();
        break;

    case 0:
        system("cls");
        mainmenu();
        break;

    default:
        back();
        break;

    }
}


void userback()
{
    int u;

    printf("Press '1' to login or '0' to back in main menu: ");
    scanf("%d", &u);

    switch(u)
    {

    case 1:
        system("cls");
        loading();
        userlogin();
        mainmenu();
        break;

    case 0:
        system("cls");
        mainmenu();
        break;

    default:
        userback();
        break;

    }
}


void adminlogin()
{
    admin n;
    admin file;

    int sameaccount = 0;
    FILE *fp;



    printf("\n\n");
    printf("\xdb\xdb\xdb\xdb Admin Login \xdb\xdb\xdb\xdb");
    printf("\n\n");




    printf("Name: ");
    fflush(stdin);
    fgets(n.name, ADMINNAME, stdin);


    printf("Password: ");
    fgets(n.pass, ADMINPASS, stdin);



    fp = fopen("adminregistration.txt","r");

    while(fread(&file, sizeof(admin), 1, fp)) {

        if (strncmp(file.name, n.name, ADMINNAME) == 0
        && strncmp(file.pass, n.pass, ADMINPASS) == 0) {

            printf("\nLog in successful.\n");


            sameaccount = 1;


            break;
        }
    }


    if(sameaccount == 0) {

        printf("\nLog in not successful.\n");
    }

    fclose(fp);

}


void reguser()
{
    user a;

    user fileuser;

    int sameuser = 0;

    FILE *fu;



    printf("\n\n");
    printf("\xdb\xdb\xdb\xdb Account Creation \xdb\xdb\xdb\xdb");
    printf("\n\n");




    printf("Name: ");
    fflush(stdin);
    fgets(a.username, NAMEUSER, stdin);

    printf("Password: ");
    fgets(a.password, USERPASS, stdin);




    fu = fopen("registrationn.bin","a+");

    if (fu == NULL) {
        fu = fopen("registrationn.bin","w+");
    }


    while(fread(&fileuser, sizeof(user), 1, fu)) {

        if (strncmp(fileuser.username, a.username, NAMEUSER) == 0) {

            printf("Name already exists.");

            sameuser = 1;

            break;
        }
    }


    if(sameuser == 0){

        fwrite(&a, sizeof(user), 1, fu);
    }


    fclose(fu);

    userback();
}


void userlogin()
{
    user a;

    user fileuser;

    int userfound = 0;
    FILE *fu;



    printf("\n\n");
    printf("\xdb\xdb\xdb\xdb User Account Login \xdb\xdb\xdb\xdb");
    printf("\n\n");




    printf("Name: ");
    fflush(stdin);
    fgets(a.username, NAMEUSER, stdin);


    printf("Password: ");
    fgets(a.password, USERPASS, stdin);



    fu = fopen("registrationn.bin","r");

    while(fread(&fileuser, sizeof(user), 1, fu)) {

        if (strncmp(fileuser.username, a.username, NAMEUSER) == 0
        && strncmp(fileuser.password, a.password, USERPASS) == 0) {

            printf("\nLog in successful.");


            userfound = 1;
            account();


            break;
        }
    }


    if(userfound == 0) {

        printf("\nLog in not successful.\n");
        userlogin();
    }

    fclose(fu);
}


void backs()
{
    system("cls");
    loading();
    system("cls");
     printf("\n\n\t\t\tThis Project is made by: ");
    printf("\n\n\t\t\tName: Mahmuda Ferdus");
    printf("\n\t\t\tId: 181-35-2382");
    printf("\n\n\t\t\tStudent of Daffodil International University,\n\t\t\tDepartment of SOFTWARE ENGINEERING");
    printf("\n\n\n\t\t @All the rights reserved to DIU and Author of this project.");
    getch();
}

int contact()
{

    system("cls");
    loading();
    system("cls");

    printf("\n\n\n\t\t\t\t||| Contact List of Management |||");

    printf("\n\n\n\t\t\tChief Financial Officer:-");
    printf("\n\n\t\t\t\tPhone: 01854-******,01555-******");
    printf("\n\t\t\t\tEmail: chiefofficer@abcbank.com");

    printf("\n\n\n\t\t\tAssistant General Manager:-");
    printf("\n\n\t\t\t\tPhone: 01354-******,01854-******");
    printf("\n\t\t\t\tEmail: assistantgeneral@abcbank.com");

    printf("\n\n\n\t\t\tSenior Manager:-");
    printf("\n\n\t\t\t\tPhone: 01744-******,01965-******");
    printf("\n\t\t\t\tEmail: seniormanager@abcbank.com");

    printf("\n\n\n");

    printf("\n\t\t\t\t  |||Visit AbcCityBank.com |||\n\n");

    printf("\n\t\t\t||| Press any key to go back to Home page |||\n\n");
    getch();

    system("cls");
    mainmenu();

}


int info()
{

    system("cls");
    loading();
    system("cls");
    printf("\n\n\t\t\t\t|| INFORMATION ||");
    printf("\n\n\n\t\t\tThe ABC bank is here for your help. And as soon as possible, I hope this \n\t\t\tbank will be a comfort zone of all of yours.Already, this bank is providing \n");
    printf("\t\t\tso many facilities near your door. Such as, you can get free loan for 1 year\n\t\t\tfrom our bank without any interest And you all will be happy to know that we\n\t\t\t give 5% interest early on fixed deposit amount");
    printf("\n\n\t\t\tSo, You all are welcome to visit our Bank as soon as possible. Thanks to all");
    getch();
    mainmenu();

}


int branchatm()
{

    system("cls");
    loading();
    system("cls");

    printf("\n\n\t\t\t1.Agargaon Branch,Dhaka south zone:-");
    printf("\n\n\t\t\t\tAddress: Lions Bhaban (2nd floor), Plot No.23, Block-E, Begum Rokeya Sharani,\n\n\t\t\t\tSher-e-Bangla Nagar, Dhaka-1207.\n\n\t\t\t\tPhone: 9143378-79 Mobile: 01711-69****, 01756-******");

    printf("\n\n\n\t\t\t2.Uttara Branch, Dhaka Central Zone:-");
    printf("\n\n\t\t\t\tAddress: Kushal Centre, Uttara Model Town, Uttara, Dhaka1230 \n\n\t\t\t\tMobile: 01711-693936(GB),01756-******, 01794-550***.");

    printf("\n\n\n\t\t\t3.Panthapath Branch, Dhaka SOuth Zone:-");
    printf("\n\n\t\t\t\tAddress: Tridhara Tower, 67 Lake Circus, West Panthapath, Dhaka\n\n\t\t\t\tMobile: 01711-693936(GB),01998-******, 01765*****.\n\n\n");

    printf("\n\t\t\t\t||| Press any key to go back to Home page |||\n\n");
    getch();

    mainmenu();

}


int registration()
{
    system("cls");
    loading();
    system("cls");

    char uname[30],upass[30],ucpass[30],uemail[50],ucno[20],udob[20],uz[20],up[20],upo[20],uhouse[20];
    int rua;

    printf("\n\n\t\t\t\t\t||REGISTRATION PAGE||");
    printf("\n\n\t\t\t\t1.User");
    printf("\n\t\t\t\t2.Admin");

    printf("\n\n\t\t\tEnter your choice: ");
    scanf("%d", &rua);

    switch (rua)
    {

    case 1:
        system("cls");
        loading();
        system("cls");
        system("COLOR 1a");
        reguser();
        break;

    case 2:
        system("cls");
        loading();
        system("cls");
        system("COLOR 1a");
        regadmin();
        break;

    default:
        registration();

    }

}


int login()
{
    system("cls");
    loading();
    system("cls");
    system("COLOR b5");

    char a[20];
    int p,ua;

    printf("\n\n\t\t\t\t\t||LOGIN PAGE||");
    printf("\n\n\t\t\t\t1.User");
    printf("\n\t\t\t\t2.Admin");
    printf("\n\n\t\t\tEnter Your Choice: ");
    scanf("%d", &ua);

    switch (ua)
    {
        case 1:

            system("cls");
            loading();
            system("cls");

            system("COLOR a1");
            printf("\n\n\t\t\t\t\t||USER LOGIN PAGE||");

            userlogin();
            break;

        case 2:
            system("cls");
            loading();
            system("cls");

            system("COLOR a1");
            printf("\n\n\t\t\t\t\t||ADMIN LOGIN PAGE||");

            adminlogin();
            break;

    default:
        login();

    }
}


int loading()
{
    int l;
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t");
    char loading[50]="Loading.........";

    for(l=0;l<strlen(loading);l++)
    {
        printf("%c", loading[l]);
        Sleep(60);
    }
}


int heading3()
{
    char thirdhead[50]="||WELCOME TO THE MOST SECURED BANKING OF CITY||";
    int k;

    for(k=0;k<strlen(thirdhead);k++)
    {
        printf("%c", thirdhead[k]);
        Sleep(30);
    }

}


int heading2()
{
    int j;
    char secondhead[50]="||We Are Committed To Secure Your Money||";

    for(j=0;j<strlen(secondhead);j++)
    {
        printf("%c", secondhead[j]);
        Sleep(35);
    }
}


int heading()
{
    int h;
    char firsthead[50]="||| ABC CITY BANK LIMITED |||";

    for(h=0;h<strlen(firsthead);h++)
    {
        printf("%c", firsthead[h]);
        Sleep(40);
    }

}


int mainmenu()
{

    int n,p;

    system("COLOR de");
    loading();
    system("cls");

    printf("\n\t\t\t\t\t");
    heading();
    printf("\n\n\t\t\t\t");
    heading2();
    printf("\n\n\t\t\t     ");
    heading3();

    printf("\n\t\t--------------------------------------------------------------------------------");
    printf("\n\t\t--------------------------------------------------------------------------------");

    printf("\n\n\n\n\t\t\t\t\t1.Login\n");
    printf("\n\t\t\t\t\t2.Registration\n");
    printf("\n\t\t\t\t\t3.Branch and ATM lists\n");
    printf("\n\t\t\t\t\t4.Information\n");
    printf("\n\t\t\t\t\t5.Contact Us\n");
    printf("\n\t\t\t\t\t6.Exit\n");
    printf("\n\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &n);

    switch (n)
    {
        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
            branchatm();
            break;

        case 4:
            info();
            break;

        case 5:
            contact();
            break;
        case 6:
            backs();
            break;

    default:
        printf("\n\n\t\t\tThe entered MENU NUMBER is incorrect.\n\n");
        printf("\n\t\t\t||| Press any key to go back to Home page |||\n\n");
        getch();
        mainmenu();

    }
}


int main()
{
    s.balance=0;
    s.loan=0;
    mainmenu();
}

