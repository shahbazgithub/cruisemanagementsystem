#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<windows.h>
using namespace std;

class person
{
	char name[50],sex[20],address[90],phone[15];
	int age;
	
	public:
		person()
		{
			strcpy(name,"Null");
			strcpy(sex,"Null");
			strcpy(address,"Null");
			strcpy(phone,"Null");
			age=0;	
		}
		person(char nm[],char sx[],char addr[],char ph[],int ag)
		{
			strcpy(name,nm);
			strcpy(sex,sx);
			strcpy(address,addr);
			strcpy(phone,ph);
			age=ag;
		}
		char* returnname(){return name;}
		void enter();
		void show();
};

class journey
{
	char source[50],destination[50],date[30];
	int duration;
	
	public:
		journey()
		{
			strcpy(source,"Undefined");
			strcpy(destination,"Undefined");
			strcpy(date,"Undefined");
			duration=0;	
		}
		journey(char src[],char dest[],char dt[],int dur)
		{
			strcpy(source,src);
			strcpy(destination,dest);
			strcpy(date,dt);
			duration=dur;
		}
		void enter();
		int Duration(){return duration;}
		void show();
};

class food
{
	int chinese,indian,mexican,continental;
	char extra[50];
	
	public:
		food()
		{
			chinese=0;
			indian=0;
			mexican=0;
			continental=0;
			strcpy(extra,"None");
		}
		food(int chi,int ind,int mex,int con,char ext[])
		{
			chinese=chi;
			indian=ind;
			mexican=mex;
			continental=con;
			strcpy(extra,ext);
		}
		int calcFood();
		void enter();
		void show();
};

class activities
{
	int sightseeing,citytour;
	
	public:
		activities(int sight=0,int city=0)
		{
			sightseeing=sight;
			citytour=city;
		}
		int calcAct();
		void enter();
		void show();
};

class Access
{
	int pool,casino,theatre;
	
	public:
		Access(int pl=0,int cas=0,int the=0)
		{
			pool=pl;
			casino=cas;
			theatre=the;
		}
		int calcAccess();
		void enter();
		void show();
};

class package:public person,public journey,public food,public activities,public Access
{
	int totalprice;
	public:
		static long ticketnum;
		package(int tprice=0)
		{
			totalprice=tprice;
		}
		void calcprice();
		void show();
};

long package::ticketnum=11600000;

class Manager
{
	string uid,pass;
	public :
		Manager()
		{
			uid="admin";
			pass="admin";
		}
		void MLogin(string,string);
		void managerPortal();
		void registeredUser();
		void ShipInfo();
};

class Users:public package
{
	long userid;
	public:
		void add(int);
		long returnuser(){return userid;}
		void edit();
		void display();
};

//----------------------------------------------------------------------------------------------------Global Variables.

Users u[10000];
int reg;

//-------------------------------------------------------------------------------------------Main Function Starts Here.

main()
{
	void LoadData();
	LoadData();
	int opt;
	cout<<"\n\n\t   -+-+-+-+-+-+-+ Cruise Management System +-+-+-+-+-+-+-\n\n\n";
	cout<<"\n\n\t\t1.Manager Login\n\n\t\t2.New User Registration\n\n\t\t3.Existing Customer Login\n\n\t\t4.Exit\n\n";
	cout<<"\n\n\n\tEnter your option>> ";
	cin>>opt;
	switch(opt)
	{
		case 1 :	void manager();
					manager();
					break;
		case 2 :	void newuser();
					newuser();
					break;
		case 3 :	void customer(int);
					customer(-1);
					break;
		case 4 :	void StoreData();
					StoreData();
					exit(0);
					break;
		default:	getch();
					system("cls");
					cout<<"*Enter Again.\n";
					main();
					break;
	}
}

//-------------------------------------------------------------------------------------------Store and Read Data.

void StoreData()
{
	fstream file("UsersReport.txt",ios::out);
	file<<reg;
	for(int i=0;i<reg;i++)
	{
		file.write((char*)&u[i],sizeof(u[i]));
	}
	file.close();
}

void LoadData()
{
	fstream filein("UsersReport.txt",ios::in);
	filein>>reg;
	for(int i=0;i<reg;i++)
	{
		filein.read((char*)&u[i],sizeof(u[i]));
	}
	filein.close();
}

//------------------------------------------------------------------------------------------------Manager Portal.

void manager()
{
	Manager m1;
	string uid,pass="";
	system("cls");
	cout<<"\n\n\t-------------- Manager Login --------------\n";
	cout<<"\n\t    ......Please Login to continue......";
	cout<<"\n\n\n\n\n\tUser ID :- \t";
	getline(cin,uid);
	getline(cin,uid);
	cout<<"\n\tPassword :- \t";
	char c;
	c=getch();
	while(c!=13)
	{
		if(c!=8)
		{
			pass+=c;
			cout<<"*";
		}
		else
		{
			cout<<"\b \b";
		}
		c=getch();
	}
	m1.MLogin(uid,pass);
	main();
}

void Manager::MLogin(string id,string password)
{
	if(id==uid&&password==pass)
	{
		managerPortal();
	}
	else
	{
		cout<<"\n\nInvalid Credentials.";
		getch();
		system("cls");	
	}
}

void Manager::managerPortal()
{
	system("cls");
	int n;
	cout<<"\n\n\t\t\t******* Welcome Manager *******\n\n\n";
	cout<<"\n\t\t1.Ship Information\n\t\t2.Registered Users\n\t\t3.Logout\n\n\n\n\t\tEnter your choice>> ";
	cin>>n;
	switch(n)
	{
		case 1 : system("cls");
				 ShipInfo();
				 getch();
				 managerPortal();
				 break;
		case 2 : registeredUser();
				 break;
		case 3 : system("cls");
				 cout<<"Successfully Logged Out as Manager.\n\n";
				 break;
		default :cout<<"Please Select a Valid Choice.";
				 getch();
				 managerPortal();
	}
}

void Manager::ShipInfo()
{
	
	system("cls");
	cout<<"\n\t    --------------- CONQUEROR ATLANTIS ---------------\t\n\n\n";	
	cout<<"\n\tConqueror Atlantis is the Asia's Largest cruise Ship till";
	cout<<"\n\tPresent Date.\n";
	cout<<"\n\tIt has the capacity of 15000 People including All Staff,";
	cout<<"\n\tCaptain and Guests.\n";
	cout<<"\n\tIt has 10 Levels out of which, 5 Levels Comprises of rooms";
	cout<<"\n\tand the rest are For Entertainment, Luxury and Experience.";
	cout<<"\n\n\tThe Staff here Knows multiple Languages, and are very";
	cout<<"\n\tHelping.\n";
	cout<<"\n\tThe Ship Begins its Journey in the 6th month every year.";
	cout<<"\n\n\tRegistrations Starts in 1st Month of the Year.\n\n\nRegister Yourself Fast.\n\n";
}

void Manager::registeredUser()
{
	system("cls");
	cout<<"\nRegistered Users\n";
	for(int i=0;i<reg;i++)
	{
		cout<<u[i].returnuser()<<" :-  "<<u[i].returnname()<<endl;
	}
	long n;
	cout<<"\n\nEnter a userid to view full details (enter 0 to exit) :- ";
	cin>>n;
	if(n==0)
	{
		managerPortal();
	}
	else
	{
		int f=0;
		for(int i=0;i<reg;i++)
		{
			if(n==u[i].returnuser())
			{
				n=i;
				f++;
			}
		}
		if(f!=0)
		{
			u[n].display();
			getch();
			managerPortal();
		}
		else
		{
			cout<<"\nUser Not Found.";
			getch();
			registeredUser();
		}
	}
}

//------------------------------------------------------------------------------------------------------New User.

void newuser()
{
	system("cls");
	cout<<"Welcome,\n";
	cout<<"Please Fill in a few details to Register yourself.";
	cout<<"\n\n\n";
	u[reg].add(reg);
	getch();
	reg++;
	StoreData();
	system("cls");
	main();
	main();
}

void person::enter()
{
	cout<<"\nEnter Name: ";
	cin.getline(name,50);
	cin.getline(name,50);
	cout<<"\nEnter Age: ";
	cin>>age;
	cout<<"\nEnter Sex: ";
	cin.getline(sex,20);
	cin.getline(sex,20);
	cout<<"\nEnter Address: ";
	cin.getline(address,90);
	cout<<"\nEnter Phone Number: ";
	cin.getline(phone,15);
}
		
void journey::enter()
{
	cout<<"\nEnter Source: ";
	cin.getline(source,50);
	cout<<"\nEnter Destination: ";
	cin.getline(destination,50);
	cout<<"\nEnter Start Date: ";
	cin.getline(date,30);
	cout<<"\nEnter Duration (in days): ";
	cin>>duration;
}

void food::enter()
{
	cout<<"\n\nEnter Food Choice (1 or 0) ->";
	cout<<"\nChinese? ";
	cin>>chinese;
	cout<<"\nIndian? ";
	cin>>indian;
	cout<<"\nMexican? ";
	cin>>mexican;
	cout<<"\nContinental? ";
	cin>>continental;
	cout<<"\nExtra Food Preferences:- ";
	cin.getline(extra,50);
	cin.getline(extra,50);
}

void activities::enter()
{
	cout<<"\n\nEnter Activities Opted (1 or 0) ->";
	cout<<"\nSightSeeing Tour: ";
	cin>>sightseeing;
 	cout<<"\nCity Tour: ";
	cin>>citytour;
}
		
void Access::enter()
{
	cout<<"\nManage Your Accessibilty (1 or 0).";
	cout<<"\nSwimming Pool? ";
	cin>>pool;
	cout<<"\nCasino? ";
	cin>>casino;
	cout<<"\nTheatre? ";
	cin>>theatre;
}

void Users::add(int reg)
{
	person::enter();
	journey::enter();
	food::enter();
	activities::enter();
	Access::enter();
	userid=(ticketnum)+(1000*(reg+1))+(reg+1);
	ticketnum=userid;
	getch();
	cout<<"\n\nPlease Note Your Registration ID for future References.";
	cout<<"\nYour Registration ID is :- "<<ticketnum<<endl;
}
		
//--------------------------------------------------------------------------------------------Existing Customers.

void customer(int loginid=-1)
{
	long userid;
	int flag=0;
	if(loginid==-1)
	{
		system("cls");
		cout<<"\n\n\t\t\t******* Customer Login *******\n";
		cout<<"\n\n\n\n\tPlease Enter your User ID: ";
		cin>>userid;
		for(int i=0;i<reg;i++)
		{
			if(userid==u[i].returnuser())
			{
				flag++;
				loginid=i;
				customer(loginid);
			}
		}
		if(flag==0)
		{
			cout<<"\n\nSorry, Invalid User ID.";
			getch();
			system("cls");
			main();
		}
	}
	else if(loginid!=-1)
	{
		int opt;
		system("cls");
		cout<<"\n\n\t\t=+=+=+=+=+=+=+ Customer Portal +=+=+=+=+=+=+=\n\n";
		cout<<"\n\n\t\tWelcome "<<u[loginid].returnname()<<",\n";
		cout<<"\n\n\t\t\t\t1.View Details\n\n\t\t\t\t2.Edit Details\n\n\t\t\t\t3.Estimated Cost\n\n\t\t\t\t4.Logout\n\n\n";
		cout<<"\n\t\tEnter your Option:- ";
		cin>>opt;
		switch(opt)
		{
			case 1	:	u[loginid].display();
						getch();
						customer(loginid);
						break;
			case 2 	:	u[loginid].edit();
						customer(loginid);
						break;
			case 3	:	u[loginid].package::show();
						getch();
						customer(loginid);
						break;
			case 4	:	system("cls");
						cout<<"Successfully Logged out.\n";
						main();
						break;
			default	:	system("cls");
						cout<<"\n\nInvalid Choice.";
						customer(loginid);
						break;
		}
	}
}

void person::show()
{
	cout<<"\n\n";
	cout<<"Name: "<<name<<endl;
	cout<<"Age: "<<age<<endl;
	cout<<"Sex: "<<sex<<endl;
	cout<<"Address: "<<address<<endl;
	cout<<"Phone: "<<phone<<endl;
}

void journey::show()
{
	cout<<"Source: "<<source<<endl;
	cout<<"Destination: "<<destination<<endl;
	cout<<"Journey Date: "<<date<<endl;
	cout<<"Duration: "<<duration<<endl;
}

void food::show()
{
	cout<<"\n\nFood Opted:";
	if(chinese!=0)
	{
		cout<<"\n# Chinese";
	}
	if(indian!=0)
	{
		cout<<"\n# Indian";
	}
	if(mexican!=0)
	{
		cout<<"\n# Mexican";
	}
	if(continental!=0)
	{
		cout<<"\n# Continental";
	}
	cout<<"\nExtra Food Preferences :-  "<<extra;
}

void activities::show()
{
	cout<<"\n\n\nActivities Opted.";
	if(sightseeing!=0)
	{
		cout<<"\n# Sight Seeing.";
	}
	if(citytour!=0)
	{
		cout<<"\n# City Tour.";
	}
}

void Access::show()
{
	cout<<"\n\nAccess:\n";
	if(pool!=0)
	{
		cout<<"\n@Swimming Pool.";
	}
	if(casino!=0)
	{
		cout<<"\n@Casino.";
	}
	if(theatre!=0)
	{
		cout<<"\n@Theatre.";
	}
}

void Users::edit()
{
	int opt;
	system("cls");
	cout<<"\n1.Personal Details:";
	person::show();
	cout<<"\n2.Journey Details:";
	journey::show();
	cout<<"\n3.Food Details:";
	food::show();
	cout<<"\n4.Activities Opted:";
	activities::show();
	cout<<"\n5.Special Access:";
	Access::show();
	cout<<"\n\n\nSelect the Part You want to Edit (1-5): ";
	cin>>opt;
	switch(opt)
	{
		case 1	:	person::enter();
					break;
		case 2	:	journey::enter();
					break;
		case 3 	:	food::enter();
					break;
		case 4 	:	activities::enter();
					break;
		case 5 	:	Access::enter();
					break;
		default :	cout<<"Enter A Valid Choice.";
					
	}
}

void Users::display()
{
	cout<<userid<<endl;
	person::show();
	journey::show();
	food::show();
	activities::show();
	Access::show();
}

//----------------------------------------------------------------------------------Calculate Total Bill of The Cruise.

int food::calcFood()
{
	int sum=0;
	if(chinese==1)
	{
		sum=sum+1250;
	}
	if(indian==1)
	{
		sum=sum+2300;
	}
	if(mexican==1)
	{
		sum=sum+2000;
	}
	if(continental==1)
	{
		sum=sum+2500;
	}
	if(strcmp(extra,"None")!=0)
	{
		sum=sum+5000;
	}
	return sum;
}

int activities::calcAct()
{
	int sum=0;
	if(sightseeing==1)
	{
		sum=sum+5000;
	}
	if(citytour==1)
	{
		sum=sum+4500;
	}
	return sum;
}

int Access::calcAccess()
{
	int sum=0;
	if(pool==1)
	{
		sum=sum+4000;
	}
	if(casino==1)
	{
		sum=sum+5500;
	}
	if(theatre==1)
	{
		sum=sum+6000;
	}
	return sum;
}

void package::calcprice()
{
	totalprice=0;
	int dur=journey::Duration();
	int meal=food::calcFood();
	totalprice=6000*dur;
	totalprice=totalprice+(dur*meal);
	int activ=activities::calcAct();
	totalprice+=activ;
	int itin=Access::calcAccess();
	totalprice+=itin;
}

void package::show()
{
	cout<<"\n\n\n\n\t\tEstimated Cost of Cruise:\n\n";
	cout<<"\n\t\tBasic Cost: "<<journey::Duration()*6000;
	cout<<"\n\t\tMeals: "<<food::calcFood()*journey::Duration();
	cout<<"\n\t\tActivities: "<<activities::calcAct();
	cout<<"\n\t\tPrivate Access: "<<Access::calcAccess();
	calcprice();
	cout<<"\n\n\t\tTotal Bill = "<<totalprice;
}

//-----------------------------------------------------------------------------------------------------End of Program.
