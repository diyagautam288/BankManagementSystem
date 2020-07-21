//Bank Management System
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<process.h>
int mainExit;
typedef struct Date
{
	int day,month,year;
}Date;
struct info
{
	char name[60];
	Date dob;
	char citizenshipNo[15];
	char address[60];
	double phone;
	float amt;
	int acc_no,age;
	char acc_type[10];
	Date deposit;
	Date withdaw;	
}add,upd,tran,check,rem;
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
void newAcc()
{
	FILE *f;
	f=fopen("BMS.txt","a+");
    AccNo:
		system("cls");
		printf("\n\t\t\t\xB2\xB2\xB2\xB2 ADD Record \xB2\xB2\xB2\xB2\t\t\t\n");
		printf("\n\n\nEnter today's date(dd/mm/yyyy):");
    	scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
		printf("\n\nEnter the Account number: ");
		scanf("%d",&check.acc_no);
		while(fscanf(f,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.citizenshipNo,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
		{
			if(check.acc_no==add.acc_no)
			{
				printf("\nThis account number is already used choose other...");
				fordelay(1000000000);
				goto AccNo;	
			}	
		}
		add.acc_no=check.acc_no;
        printf("\nEnter the name:");
	    scanf("%s",add.name);
	    printf("\nEnter the date of birth(mm/dd/yyyy):");
	    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
	    printf("\nEnter the age:");
	    scanf("%d",&add.age);
	    printf("\nEnter the address:");
	    scanf("%s",add.address);
	    printf("\nEnter the citizenship number:");
	    scanf("%s",add.citizenshipNo);
	    printf("\nEnter the phone number: ");
	    scanf("%lf",&add.phone);
	    printf("\nEnter the amount to deposit:$");
	    scanf("%f",&add.amt);
	    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
	    scanf("%s",add.acc_type);
		fprintf(f,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenshipNo,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
		fclose(f);
		printf("\nAccount is successfully created");
		AccCreated:
			printf("\n\n\t\tEnter 1 to go to main menu or 0 to exit");
			scanf("%d",&mainExit);
			system("cls");
			if(mainExit==1)
				menu();		
			else if(mainExit==0)
				close();
			else
			{
				printf("\nInvalid choice");
				fordelay(100000000);
				goto AccCreated;
			}
}
void edit()
{
	int choice,test=0;
	FILE *oldf=fopen("BMS.txt","r");
	FILE *newf=fopen("temp.txt","w");
	printf("\n\tPlease enter the account number whose info you want to change: ");
	scanf("%d",&upd.acc_no);
	while(fscanf(oldf,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.citizenshipNo,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {
    	if(add.acc_no==upd.acc_no)
    	{
    		test=1;
    		printf("\n\tWhich information you want to change:\n\t1.Address\n\t2.Phone Number\n\tPlease enter your choice: ");
    		scanf("%d",&choice);
    		system("cls");
    		switch(choice)
    		{
    			case 1:
    				printf("\n\tPlease enter your new address: ");
    				scanf("%s",upd.address);
    				fprintf(newf,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,upd.address,add.citizenshipNo,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
					system("cls");
					printf("Changes Saved!!");
					break;
				case 2:
					printf("\n\tPlease enter your new phone number: ");
    				scanf("%lf",&upd.phone);
    				fprintf(newf,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenshipNo,upd.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
					system("cls");
					printf("Changes Saved!!");
					break;
				default:
					printf("\n\tYou entered Invalid choice!!");
					break;
			}
		}
		else
			fprintf(newf,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenshipNo,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
    }
    fclose(oldf);
    fclose(newf);
    remove("BMS.txt");
    rename("temp.txt","BMS.txt");
    if(test!=1)
    {
    	system("cls");
    	printf("\n\tThis account is not found!!");
    	editAcc:
    		printf("\n\tPlease enter 0 to Try Again or 1 to go to main menu or 2 to exit: ");
    		scanf("%d",&mainExit);
    		system("cls");
    		if(mainExit==0)
    			edit();
    		else if(mainExit==1)
    			menu();
    		else if(mainExit==2)
    			close();
    		else
    		{
    			printf("Invalid choice!!");
    			goto editAcc;
			}
	}
	else
	{
		printf("\n\tPlease enter 1 to go to main menu or 2 to exit: ");
    	scanf("%d",&mainExit);
    	system("cls");
		if(mainExit==1)
    		menu();
    	else if(mainExit==2)
    		close();
	}
}
void transact()
{
	int choice,test=0;
	FILE *oldf=fopen("BMS.txt","r");
	FILE *newf=fopen("temp.txt","w");
	printf("\n\tPlease enter the account number of customer: ");
	scanf("%d",&tran.acc_no);
	while(fscanf(oldf,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.citizenshipNo,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {
    	if(add.acc_no==tran.acc_no)
    	{
    		test=1;
    		if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
    		{
    			printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                fordelay(1000000000);
                system("cls");
                menu();
			}
    		printf("\n\tDo you want to\n\t1.Deposit\n\t2.Withdraw\n\tPlease enter your choice: ");
    		scanf("%d",&choice);
    		system("cls");
    		switch(choice)
    		{
    			case 1:
    				printf("\n\tPlease enter the amount you to deopist: ");
    				scanf("%f",&tran.amt);
    				add.amt+=tran.amt;
    				fprintf(newf,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenshipNo,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
					system("cls");
					printf("Deposit successfully!!");
					break;
				case 2:
					printf("\n\tPlease enter the amount you to withdraw: ");
    				scanf("%f",&tran.amt);
    				add.amt-=tran.amt;
    				fprintf(newf,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenshipNo,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
					system("cls");
					printf("Withdraw successfully!!");
					break;
				default:
					printf("\n\tYou entered Invalid choice!!");
					break;
			}
		}
		else
			fprintf(newf,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenshipNo,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
    }
    fclose(oldf);
    fclose(newf);
    remove("BMS.txt");
    rename("temp.txt","BMS.txt");
    if(test!=1)
    {
    	system("cls");
    	printf("\n\tThis account is not found!!");
    	tranAcc:
    		printf("\n\tPlease enter 0 to Try Again or 1 to go to main menu or 2 to exit: ");
    		scanf("%d",&mainExit);
    		system("cls");
    		if(mainExit==0)
    			transact();
    		else if(mainExit==1)
    			menu();
    		else if(mainExit==2)
    			close();
    		else
    		{
    			printf("Invalid choice!!");
    			goto tranAcc;
			}
	}
	else
	{
		printf("\n\tPlease enter 1 to go to main menu or 2 to exit: ");
    	scanf("%d",&mainExit);
    	system("cls");
		if(mainExit==1)
    		menu();
    	else if(mainExit==2)
    		close();
	}
}
void viewList()
{
	FILE *file;
	int test=0;
	file=fopen("BMS.txt","r");
	printf("\nACC. no.\tName\t\t\tAddress\t\t\tPhoneNumber");
	while(fscanf(file,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.citizenshipNo,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
	{
		printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
		test++;
	}
	fclose(file);
	if(test==0)
	{
		system("cls");
    	printf("\n\tNO FOUND!!");
	}
    viewAcc:
    	printf("\n\tPlease enter 1 to go to main menu or 2 to exit: ");
    	scanf("%d",&mainExit);
    	system("cls");
		if(mainExit==1)
    		menu();
    	else if(mainExit==2)
    		close();
    	else
    	{
    		printf("Invalid choice!!");
    		goto viewAcc;
		}	
}
void erase()
{
	FILE *newf;
	FILE *oldf;
	oldf=fopen("BMS.txt","r");
	newf=fopen("temp.txt","w");
	int test=0;
	printf("\n\tPlease enter the account number you want to delete: ");
	scanf("%d",&rem.acc_no);
	while(fscanf(oldf,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.citizenshipNo,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
	{
		if(rem.acc_no!=add.acc_no)
			fprintf(newf,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenshipNo,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
		else
		{
			test++;
			printf("\n\tAccount deleted successfully");				
		}	
	} 
	fclose(oldf);
    fclose(newf);
    remove("BMS.txt");
    rename("temp.txt","BMS.txt");
    if(test==0)
    {
    	system("cls");
    	printf("\n\tThis account is not found!!");
    	removeAcc:
    		printf("\n\tPlease enter 0 to Try Again or 1 to go to main menu or 2 to exit: ");
    		scanf("%d",&mainExit);
    		system("cls");
    		if(mainExit==0)
    			erase();
    		else if(mainExit==1)
    			menu();
    		else if(mainExit==2)
    			close();
    		else
    		{
    			printf("Invalid choice!!");
    			goto removeAcc;
			}
	}
	else
	{
		printf("\n\tPlease enter 1 to go to main menu or 2 to exit: ");
    	scanf("%d",&mainExit);
    	system("cls");
		if(mainExit==1)
    		menu();
    	else if(mainExit==2)
    		close();
	}
}
void see()
{
	FILE *file;
	file=fopen("BMS.txt","r");
	int test=0,rate;
    int choice;
    float time;
    float intrst;
    printf("\n\tPlease enter the account number: ");
    scanf("%d",&check.acc_no);
    while(fscanf(file,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.citizenshipNo,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {
    	if(check.acc_no==add.acc_no)
    	{
    		test=1;
    		system("cls");
    		printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenshipNo,add.phone,
                add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
            if(strcmpi(add.acc_type,"fixed1")==0)
            {
            	time=1.0;
            	rate=8;
            	intrst=interest(time,add.amt,rate);
	        	printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+2);
			}
			else if(strcmpi(add.acc_type,"fixed2")==0)
            {
            	time=2.0;
            	rate=10;
            	intrst=interest(time,add.amt,rate);
	        	printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+2);
			} 
			else if(strcmpi(add.acc_type,"fixed3")==0)
            {
            	time=3.0;
            	rate=12;
            	intrst=interest(time,add.amt,rate);
	        	printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+2);
			}
			else if(strcmpi(add.acc_type,"saving")==0)
            {
            	time=(1.0/12.0);
            	rate=7;
            	intrst=interest(time,add.amt,rate);
	        	printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+2);
			} 
			else if(strcmpi(add.acc_type,"current")==0)
            {
                printf("\n\nYou will get no interest\a\a");
            }
		}
	}
	if(test!=1)
    {
    	system("cls");
    	printf("\n\tThis account is not found!!");
    	seeAcc:
    		printf("\n\tPlease enter 0 to Try Again or 1 to go to main menu or 2 to exit: ");
    		scanf("%d",&mainExit);
    		system("cls");
    		if(mainExit==0)
    			erase();
    		else if(mainExit==1)
    			menu();
    		else if(mainExit==2)
    			close();
    		else
    		{
    			printf("Invalid choice!!");
    			goto seeAcc;
			}
	}
	else
	{
		printf("\n\tPlease enter 1 to go to main menu or 2 to exit: ");
    	scanf("%d",&mainExit);
    	system("cls");
		if(mainExit==1)
    		menu();
    	else if(mainExit==2)
    		close();
	}
}
void menu()
{
	int choice;
	system("cls");
	printf("\n\n\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice: ");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
    	case 1:
    		newAcc();
    		break;
    	case 2:
    		edit();
    		break;
    	case 3:
    		transact();
    		break;
    	case 4:
    		viewList();
    		break;
    	case 5:
    		erase();
    		break;
    	case 6:
    		see();
    		break;
    	case 7:
    		exit(0);
	}
	
}
void close()
{
	printf("\n\n\n\tThis project is developed by Diya Gautam");
}

int main()
{
	char pass[7],password[7]="BMSP2034";
	int i=0,compare=1;
	printf("\n\t\tEnter the Password:\t");
	while (i!=8)
    {
    	pass[i]=getch();
        printf("*");
        i++;
    }
    for(i=0;i<7;i++)
    {
    	if(pass[i]!=password[i])
    	{
    		compare=0;
    		break;
		}
	}
	if(compare==1)
	{
		printf("\n\nPassword Match!\nLoading");
		for(i=0;i<6;i++)
		{
			fordelay(100000000);
			printf(".");
		}
		system("cls");
		menu();
	}
	else
	{
		printf("\n\nPassword is incorrect");
		tryAgain:
			printf("\n\nEnter 1 to try again or 0 to exit: ");
			scanf("%d",&mainExit);
			if(mainExit==1)
			{
				system("cls");
				main();	
			}	
			else if(mainExit==0)
			{
				system("cls");
				close();
			}
			else
			{
				printf("\nInvalid choice");
				fordelay(100000000);
				goto tryAgain;
			}
	}
	return 0;
}










