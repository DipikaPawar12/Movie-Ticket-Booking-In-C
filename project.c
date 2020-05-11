#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

COORD c={0,0};
void gotoxy(int x,int y)
{
	 c.X=x; c.Y=y; // Set X and Y coordinates
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void main_page();
void password();
void admin_menu();


void movie_details();
void gen_movie();
void user();
void seats();
void print();
void border();
void border1();
void bill(float);

struct movie
{
	char code[5];
	char name[30];
	char actors[2][30];
	char genre[20];
	char language[10];
	char description[40];
	char ratings[5];
	char screen[2];
}M;
struct movie add_movie();
struct movie delete_movie();
struct movie show_movie();
struct movie movie_des();
FILE *fp,*fp1,*fp2;

int main()
{
	//system("color A1");
	main_page();	
	return 0;
}

void main_page()
{		
	system("color C0");
	int choice;

	system("cls");
	border();
	gotoxy(25,25);
	printf("\t\t   !!! REJOICE CINEMAS !!!");
	gotoxy(40,45);
	printf("Press any key to continue...");
	getch();
	
	loop:
	system("cls");

	border();
	gotoxy(25,25);
	printf("\t\t   Continue as.....\n\n\n\n\t\t\t1.) Admin\n\n\t\t\t2.) User\n\n\t\t\t3.) Exit\n\n\n\n\n\t\t\t\tEnter your Choice : ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:password();
			   admin_menu();
			   break;
		case 2:user();
			   break;
		case 3:gotoxy(60,52);
			   exit(0);
		default:goto loop;
	}
	
	gotoxy(60,52);
}

void password()
{	
	system("color A0");
	char password[20],ch;
	int i;
	
	system("cls");
	border();
	gotoxy(35,15);
	loop:
	printf("\n\t\tEnter your password : ");
	
	for(i=0;i<10;i++)
	{
	    ch=getch();
	
	    if(ch!=13)      //13 is ASCII of Enter key
	    {
	    	password[i]=ch;
	    	printf("*");
	    } 
	    if(ch==13||ch==8)
	       break;
	}
	
	password[i]='\0';
	
	if(strcmp(password,"guest")==0)
	{
		system("cls");
		border();
		gotoxy(45,15);
		printf("Login Successful !!!!");
		printf("\n\t\t\tPress any key to continue...");
		getch();
	}
	else if(strcmp(password,"guest")!=0)
	{
		system("cls");
		border();
		gotoxy(25,15);
		printf("\n\n\t\t\tLogin Failed !!!! Try again !!!!");
		goto loop;
	}
}

void border()
{
	int i;
	
	//Top border line...
	gotoxy(10,5);
	for(i=0;i<91;i++)
		printf("\xB2");
	
	//Bottom border line...
	gotoxy(10,51);
	for(i=0;i<91;i++)
		printf("\xB2");
		
	for(i=0;i<47;i++)
	{
		gotoxy(10,5+i);
		printf("\xB2");
		
		gotoxy(100,5+i);
		printf("\xB2");
	}
}
void border1()
{
	int i;
	
	//Top border line...
	gotoxy(30,10);
	for(i=0;i<45;i++)
		printf("#");
	
	//Bottom border line...
	gotoxy(30,25);
	for(i=0;i<45;i++)
		printf("#");
		
	for(i=0;i<15;i++)
	{
		gotoxy(30,10+i);
		printf("#");
		
		gotoxy(75,10+i);
		printf("#");
	}
}

void admin_menu()
{
	system("color A0");
	int ch;
	system("cls");
	border();
	gotoxy(30,15);
	printf("WELCOME ADMIN...");
	gotoxy(30,17);
	printf("ADMIN MENU:");
	gotoxy(34,19);
	printf("1)Add New Movie");
	gotoxy(34,20);
	printf("2)Delete Off-screened Movie");
	gotoxy(34,21);
	printf("3)Generate Movie Popularity Report");
	gotoxy(34,22);
	printf("4)Logout");
	gotoxy(30,24);
	printf("Enter Your Choice :");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:add_movie();
			   break;
		case 2:delete_movie();
			   break;
		case 3:gen_movie();
			   break;
		case 4:gotoxy(34,42);
			   printf("logging out....");
			   Sleep(2000);
			   main_page();
			   break;
	}
}

struct movie add_movie()
{
	char ch;
	int a;
	system("cls");
	border();
	movie_details();
	MOVIE:
	system("cls");
	border();
	gotoxy(30,15);
	printf("Want to add more movie!!(y/n) : ");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
	{
		system("cls");
		movie_details();
		goto MOVIE;
	}
	else if(ch=='n'||ch=='N')
	{
		gotoxy(33,25);
		printf("Movie(s) added in list...");
		gotoxy(60,52);
	}
	admin_menu();
}

void movie_details()
{
	system("cls");
	border();
	
	fp=fopen("pro2.txt","a");
	
	int i,j;
	
	gotoxy(32,15);
	printf("Enter Show ID : ");
	scanf("%s",&M.code);
	gotoxy(32,16);
	printf("Enter Movie Name : ");
	fflush(stdin);
	gets(M.name);
	gotoxy(32,17);
	printf("Enter Lead Actors Name : ");
	for(i=0;i<2;i++)
	{
		gets(M.actors[i]);
		gotoxy(57,18);
	}
	gotoxy(32,19);
	printf("Enter Genre : ");
	gets(M.genre);
	gotoxy(32,20);
	printf("Enter Language : ");
	gets(M.language);
	gotoxy(32,21);
	printf("Enter Description : ");
	gets(M.description);
	gotoxy(32,22);
	printf("Enter Ratings out of five : ");
	gets(M.ratings);
	//if(M.)
	fflush(stdin);
	gotoxy(32,23);
	printf("Enter Screen Number : ");
	scanf("%c",&M.screen[0]);
	M.screen[1]='\0';

	fwrite(&M,sizeof(M),1,fp);
//	fprintf(fp,"\n");
	fclose(fp);
	fclose(fp1);
}

struct movie delete_movie()
{
	int i=0;
	system("cls");
	border();
	gotoxy(20,15);
	show_movie();
	fp=fopen("pro2.txt","r");
	fp1=fopen("pro4.txt","w");
	char id[5],c;//,found='f',ans;
	gotoxy(31,25);
	printf("Enter the Code of the Movie you want to delete : ");
	scanf("%s",&id);
	fflush(stdin);
	gotoxy(31,27);
	printf("Are you sure?");
	scanf("%c",&c);
	if(c=='y'||c=='Y')
	{
		while(fread(&M,sizeof(M),1,fp)>0)
		{
			if(strcmp(id,M.code)!=0)
				fwrite(&M,sizeof(M),1,fp1);
			else 
				i++;
		}
		if(i!=0)
		{
			gotoxy(45,30);
			printf("Film deleted from the list...");
		}
		else
		{
			gotoxy(45,30);
			printf("Such movie not found!!");
		}
		 	
		
		fclose(fp);
		fclose(fp1);
		
		remove("pro2.txt");
		rename("pro4.txt","pro2.txt");
		getch();
	}
	if (c=='n'||c=='N')
	{
		delete_movie();
	}
//	main_page();
		admin_menu();
}

void gen_movie()
{
	system("cls");
	border();
	gotoxy(15,29);
	int j;
	float r,r1,r2,r3,r4;
	printf("Enter five movie rates:");
	scanf("%f ",&r);
	gotoxy(15,30);
	scanf("%f",&r1);
	gotoxy(15,31);
	scanf("%f",&r2);
	gotoxy(15,32);
	scanf("%f",&r3);
	gotoxy(15,33);
	scanf("%f",&r4);
	system("cls");
	printf("Movie Popularity Report :");
	gotoxy(25,5);
	for(j=5; j<16; j++)
	{
		printf("\xb2");
		gotoxy(25,j);
	}
	
	for(j=15-r*2; j<15; j++)
	{
		gotoxy(28,16);
		printf("M001 ");
		gotoxy(28,j);
		printf("\xb2");
	}
	for(j=15-r1*2; j<15; j++)
	{
		gotoxy(33,16);
		printf("M002 ");
		gotoxy(33,j);
		printf("\xb2");
	}
	for(j=15-r2*2; j<15; j++)
	{
		gotoxy(38,16);
		printf("M003 ");
		gotoxy(38,j);
		printf("\xb2");
	}
	for(j=15-r3*2; j<15; j++)
	{
		gotoxy(43,16);
		printf("M004 ");
		gotoxy(43,j);
		printf("\xb2");
	}
	for(j=15-r4*2; j<15; j++)
	{
		gotoxy(48,16);
		printf("M005 ");
		gotoxy(48,j);
		printf("\xb2");
	}
	
	gotoxy(25,15);
	for(j=0; j<50; j++)
	{
		printf("\xb2");
	}
	
	getch();
	admin_menu();
	//main_page();
}

struct movie show_movie()
{
	system("cls");
	//border();
	int i=0;
	fp1=fopen("pro2.txt","r");
	
	gotoxy(20,7);
	printf(":CODE:  :NAME:\n");
	fflush(stdin);
	while(fread(&M,sizeof(M),1,fp1)>0)
	{
		gotoxy(20,i+15);
		printf("%s    %s\n",M.code,M.name);
		i++;
	}
	fclose(fp1);
	
}
struct movie movie_des()
{
	FILE *fp1;
	char id[5],c;
	int i=0;
	printf("\n\n\t\t\tEnter the Movie code of your choice : ");
	fflush(stdin);
	gets(id);
	system("cls");
	border();
	fp1=fopen("pro2.txt","r");
	gotoxy(20,14);
	fflush(stdin);
	while(fread(&M,sizeof(M),1,fp1)>0)
	{
		if(strcmp(id,M.code)==0)
		{
			gotoxy(35,15);
			printf("Movie code:%s\n\t\t\tMovie name:%s\n\t\t\tMovie genre:%s\n\t\t\tlanguage:%s\n\t\t\tDescription:%s\n\t\t\tRatings:%s\n\t\t\tScreen:%s\n",M.code,M.name,M.genre,M.language,M.description,M.ratings,M.screen);
		}
		
	}		
	gotoxy(35,35);
	printf("Proceed to select seats ? (y/n) ");
	scanf("%c",&c);
	if(c=='y'||c=='Y')
	{
		fclose(fp1);
		seats();
	}
	
	else
	{
		fclose(fp1);
		movie_des();	
	}
}
int nos=0;
void seats()
{
	fp=fopen("seats.txt","r+");
	
	int ch,n,i,d,s,k=28,t,total,S,f;
	
	system("cls");
	border();
	gotoxy(15,9);
	printf("\n\t\tEnter the number of seats you wish to book : ");
	scanf("%d",&s);
	nos+=s;
	gotoxy(15,12);
	printf("Enter the type of seat you want : ");
	gotoxy(15,14);
	printf("1) ROYAL");
	gotoxy(15,15);
	printf("2) EXECUTIVE");
	gotoxy(15,16);
	printf("3) CLUB");
	gotoxy(15,18);
	printf("Enter your choice (1/2/3) : ");
	scanf("%d",&t);
	switch(t)
	{
		case 1:total=30.00;break;
		case 2:total=20.00;break;
		case 3:total=0.00;break;
		//default:goto loop;
	}
	
	system("cls");
	border();
	gotoxy(15,9);
	printf("SEATS....\n\t\tThe first 3 rows are 'ROYAL', next 3 are 'CLUB', and last 3 are 'EXECUTIVE'...\n\n\t");
	print();
	printf("\n\n\t\tUnoccupied seats are represented by '_' and occupied seats are represented by '%c'",220);	
	printf("\n\n\t\tEnter row and column number of the seat(s) you wish to book :\n");
	for(i=0;i<s;i++)
	{
		gotoxy(77,k++);
		scanf("%d %d",&n,&d);
		fseek(fp,n*6-6,SEEK_SET);
		fseek(fp,d-1,SEEK_CUR);
		ch=1;
		fprintf(fp,"%d",ch);
	}
	system("cls");
	border();
	gotoxy(15,9);
	printf("Your Seat(s) is(are) Booked....\n\t\tStatus of seats....\n\n\t");
	rewind(fp);
	print();
	printf("\n\n\n\t\tPress any key to proceed....");
	getch();
	system("cls");
	border();
	fflush(stdin);	
	gotoxy(35,15);
	printf("SELECT YOUR TIME SLOT");
	gotoxy(23,18);
	printf("TIME SLOT\t\t\t\tPRICE FOR CLUB TICKET");
	gotoxy(23,20);
	printf("1) 09:30\t\t\t\t\t100.00");
	gotoxy(23,21);
	printf("2) 12:45\t\t\t\t\t110.00");
	gotoxy(23,22);
	printf("3) 15:00\t\t\t\t\t120.00");
	gotoxy(23,23);
	printf("4) 18:15\t\t\t\t\t150.00");
	gotoxy(23,24);
	printf("5) 21:30\t\t\t\t\t180.00");
	
	gotoxy(23,26);
	printf("If you have selected EXECUTIVE then Rs.20 extra.");
	gotoxy(23,27);
	printf("If you have selected ROYAL then Rs.30 extra.");
	gotoxy(23,29);
	printf("Enter the slot of your choice : ");
	scanf("%d",&S);
	switch(S)
	{
		case 1:total+=100.00;break;
		case 2:total+=110.00;break;
		case 3:total+=120.00;break;
		case 4:total+=150.00;break;
		case 5:total+=180.00;break;
	}
	total=nos*total;
	system("cls");
	border();
	gotoxy(25,15);
	printf("Do you Want to pre-order your Refreshments ?! (y/n) ");
	fflush(stdin);
	scanf("%c",&ch);
	
	while(ch=='y'||ch=='Y')
	{
		system("cls");
		border();
		gotoxy(35,15);
		printf("REFRESHMENTS....");
		gotoxy(23,18);
		printf("FOOD ITEM\t\t\t\t\t\t\tPRICE");
		gotoxy(23,20);
		printf("1) Salted Popcorn and Coke Combo\t\t\t\t\t115.00");
		gotoxy(23,21);
		printf("2) Cheese Popcorn and Coke Combo\t\t\t\t\t150.00");
		gotoxy(23,22);
		printf("3) Chilli Popcorn and Coke Combo\t\t\t\t\t170.00");
		gotoxy(23,23);
		printf("4) French Fries and Coke Combo\t\t\t\t\t200.00");
		gotoxy(23,24);
		printf("5) Masala French Fries and Coke Combo\t\t\t\t210.00");
		gotoxy(23,25);
		printf("6) Peri-Peri French Fries and Coke Combo\t\t\t\t250.00");
		gotoxy(23,26);
		printf("7) Cheese Popcorn, Peri-Peri French Fries and Coke Combo\t\t310.00");
		
		gotoxy(23,29);
		printf("Enter your choice : ");
		scanf("%d",&f);
		switch(f)
		{
			case 1:total+=115.00;break;
			case 2:total+=150.00;break;
			case 3:total+=170.00;break;
			case 4:total+=200.00;break;
			case 5:total+=210.00;break;
			case 6:total+=250.00;break;
			case 7:total+=310.00;break;
		}

		gotoxy(23,31);
		printf("Do you want to add more to the list...?! (y/n) ");
		fflush(stdin);
		scanf("%c",&ch);
		
		if(ch=='n'||ch=='N')
		{
			gotoxy(23,33);
			printf("Preparing your bill. Wait a minute....");
		}
	}
	
	bill(total);
	
	fclose(fp);
	gotoxy(60,52);
}

void bill(float total)
{
	system("cls");
	
	border();
	gotoxy(35,15);
	
	char name[30];
	int enrol;
	
	fflush(stdin);
	
	printf("Enter your name : ");
	gets(name);
	
	srand(time (0));
	enrol=rand()%1000000+100000;
	
	gotoxy(35,18);
	printf("Generating bill.... Wait a minute...");
	
	
	system("cls");
	
	border();
	border1();
	
	gotoxy(40,12);
	printf("YOUR E-TICKET");
	gotoxy(35,17);
	printf("NAME : ");
	puts(name);
	gotoxy(35,19);
	printf("TICKET CODE : %d",enrol);
	gotoxy(35,21);
	printf("YOUR BILL IS : Rs.%5.2f",total);
}

void print()
{
	int c=0,ch=getc(fp),col,i,j=14,k=15,l=20;
	
	gotoxy(18,12);
	for(i=1;i<=6;i++)
		printf("\t%d",i);
		
	gotoxy(20,14);
	while(ch!=EOF)
	{
		if(ch=='0')
		{
			ch=95;
			printf("\t%c",ch);
			c++;
		}
		else if(ch=='1')
		{
			ch=220;
			printf("\t%c",ch);
			c++;
		}
		
		if(c%6==0)
			gotoxy(20,k++);
		
		ch=getc(fp);
	}
	
	for(col=1;col<=9;col++)
	{
		gotoxy(16,j++);
		printf("%d\n",col);
	}
	printf("\n\t\t\t  ALL EYES TOWARDS THE SCREEN PLEASE");
}

void user()
{
	system("color B0");
	int choice;
	char id[5];
	system("cls");
	border();
	gotoxy(35,15);
	printf("WELCOME USER.....\n\n\t\t1) Book Movie Tickets\n\n\t\t2) Exit user menu");
	printf("\n\n\n\t\t\tEnter your choice : ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:show_movie();
				movie_des();
			   break;
		case 2:main_page();
			   break;
		default:user();			   
	}
}
