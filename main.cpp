#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;
string code,fname, fnumber, date, cause,fslot,d,s;

void searchappointment(string fn1);
bool checkschedule(int ch);
void addappointment();
void scheduledisplay(void);
void deleteappointment();
string history();
void printhistory(string fn1);

int main()
{
	while(true)
	{
		system("cls");
		int choice;
		string username,password,fn;
		cout<<"\n______________________________________________________________________________________________";
		cout<<"\n*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * *  *  *  *  *  *  *  *  *  *  *  ";
		cout<<"\n______________________________________________________________________________________________";
		cout<<"\n\t\tWELCOME TO HAPPY TEETH CLINIC \n";
		cout<<"______________________________________________________________________________________________";
		cout<<"\n*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * *  *  *  *  *  *  *  *  *  *  *  ";
		cout<<"\n______________________________________________________________________________________________";
		cout<<"\n";
		cout<<"\nYou can do the following: \n\n";
		cout<<"1.Book Apointment \n";
		cout<<"2.Cancel a Appointment \n";
		cout<<"3.Check Appointment\n";
		cout<<"4.Doctor's Login \n";
		cout<<"5. Exit";
		cout<<"\n\n ENTER YOUR CHOICE : ";
		cin>>choice;
		switch(choice)
		{
			case 1: addappointment();
			break;
			case 2: deleteappointment();
			break;
			case 3:	cout<<"Enter File number: ";
					cin>>fn;
					searchappointment(fn);
					system("pause");
					system("cls");
			break;
			case 4: int ch; 
					cout<<"Enter User Name: ";
					cin>>username;
					cout<<"Enter Password: ";
					cin>>password;
					if((username=="Kumar")&&(password=="123"))
					{
						cout<<"\nWelcome back Doctor Harish Kumar :\n";
						cout<<"You can do the following: \n";
						cout<<"\n1.Check Schedule for this week ";
						cout<<"\n2.Check Patients History";
						cout<<"\n\n\t Enter your Choice: ";
						cin>>ch;
						switch(ch)
						{
							case 1:scheduledisplay();
									break;
							case 2:cout<<"Enter File Number : ";
							cin>>fn;
							searchappointment(fn);
							printhistory(fn);
							system("pause");
							system("cls");
							break;

						}

					}
				else
				cout<<"Wrong user name or Password ";
				break;
			case 5: break;
			default : cout<<"\nInvalid Entry.\n ";
		}
		if (choice==5)
		break;
	}


}
string history()
{
    string  newfile;
    string c[8];
    fstream file3;
    file3.open("history.txt",ios::app);
	srand((unsigned) time(NULL)); 
	int random = 300 + (rand() % 500);
	newfile="A"+to_string(random);
	cout<<"\nEnter your Date of Birth: ";
	cin>>c[1];
	cout<<"Enter your age : ";
	cin>>c[2];
    cout<<"Choose if you have any problem as per following";
	cout<<"\n1.If you have Diabetes enter yes or no"<<endl;
	cin>>c[3];
    cout<<"2.If you have Hypertension enter yes or no"<<endl;
	cin>>c[4];
	cout<<"3.If you have Atherosclerosis enter yes or no"<<endl;
	cin>>c[5];
	cout<<"4.If you don't have any medical issue enter yes or no"<<endl;
	cin>>c[6];
	file3<<newfile<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4]<<" "<<c[5]<<" "<<c[6]<<endl;
	cout<<"New Record Generated Successfully \n";
	cout<<"Your File number is "<<newfile;
	cout<<endl;
    
	file3.close();
	return newfile;
}

void display()
{
    int n;
    string slot[12]={"17:00","9:00","9:30","10:00","10:30","11:00","11:30","12:00","16:00","16:30"};
    string day[8]={"Monday","Tuesday","Wednessday","Thursday","Friday","Saturday"};
    cout<<"Enter the day of appointment: ";
    for(int i=0;i<6;i++)
    cout<<"\n"<<(i+1)<<". "<<day[i];
    do{
    cout<<"\nEnter the number(1-6) : ";
    cin>>n;
    }
    while(!(n>0&&n<7));
    cout<<"\nTHE APPOINTMENT SLOT AVAILABLE ON "<<day[n-1]<<" IS AS FOLLOW ";
    cout<<"\nTime \t CODE FOR BOOKING";
    for(int i=((n-1)*10+1);i<((n*10)+1);i++)
        cout<<"\n"<<slot[((i%10))]<<"\t"<<i;
}

void addappointment()
{
	string slot[12]={"17:00","9:00","9:30","10:00","10:30","11:00","11:30","12:00","16:00","16:30"};
	int d;
    fstream file;
	fstream file2;
	file2.open("list.txt",ios::app);
    file.open("s.txt",ios::app);
	display();
	do{
		cout<<"\nEnter The code : ";
    	cin>>code;
		d=stoi(code);
		if(checkschedule(d)==true)
		cout<<"THE SLOT IS ALREADY BOOKED CHOOSE ANOTHER.\n ";
	}while(checkschedule(d)==true);
	cout<<"CAUSE OF VISIT (Enter the cause in words as below)\n";
    file<<d<<" ";
	cout<<"1.RECALL"<<endl<<"2. FIRST_VISIT"<<endl<<"3. MONTHLY_CHECKUP"<<endl<<"4. HAVE_AN_ILLNESS \n";
	cin>>cause;
	if(cause=="FIRST_VISIT")
	{
		fnumber=history();

	}
	if(cause!="FIRST_VISIT")
	{
		cout<<"Enter your file number : ";
		cin>>fnumber;
	}
	cout<<"Enter date of appointment :";
	cin>>date;
	cout<<"Enter your name : ";
	cin>>fname;
	fslot=slot[(d%10)];
	file2<<fnumber<<" "<<fname<<" "<<date<<" "<<fslot<<" "<<cause<<" "<<code<<endl;
	cout<<fnumber<<" "<<fname<<" "<<date<<" "<<fslot<<" "<<cause<<" "<<d;
	cout<<"\n\n\t\tAppointment booked successfully !!\n";

    file.close();
	file2.close();
	system("pause");
	system("cls");
}

void deleteschedule(string d2code)
{
	string dcode;
	dcode=d2code;
	
	bool found = false;
	ifstream myfile("s.txt");
	ofstream myfile2("s2.txt", ios::app);
	if ( myfile.is_open() ) {	
	while ( myfile>>code ) {
		if(!(dcode == code))
		{
			myfile2<<code<<" ";
		}
		else if(dcode == code)
		{
			found=true;
		}
		
	}}
	if(found==false)
	cout<<"\nINVALID ENTRY APPOINTMENT NOT FOUND\n";
	cout<<"\n";
	myfile.close();
	myfile2.close();
	char filename[] = "s.txt";
  	// remove the file "program.cpp"
  	remove(filename);
	char oldname[] = "s2.txt";
	char newname[] = "s.txt";
	/*	Deletes the file if exists */
	rename(oldname, newname);
	system("pause");
	system("cls");
}

void deleteappointment()
{
	string fn;
	cout<<"Enter File number: ";
	cin>>fn;
	searchappointment(fn);
	string ddate,dcode,dnumber;
	cout<<"Enter File number, Date and code to delete: ";
	cout<<"\nFile number";
	cin>>dnumber;
	cout<<"\nDate :";
	cin>>ddate;
	cout<<"\ncode:";
	cin>>dcode;
	deleteschedule(dcode);
	bool found = false;
	ifstream myfile("list.txt");
	ofstream myfile2("list2.txt", ios::app);
	if ( myfile.is_open() ) {	
	while ( myfile>>fnumber>>fname>>date>>fslot>>cause>>code ) {
		if(!((fnumber==dnumber) && (dcode == code) && (ddate == date)))
		{
			found=true;
			myfile2<<fnumber<<" "<<fname<<" "<<date<<" "<<fslot<<" "<<cause<<" "<<code<<endl;
		}
		else if((fnumber==dnumber) && (dcode == code) && (ddate == date))
		{
			found=true;
			cout<<"\n\n\t\tTHE APPOINTMENTS HAS SUCCESSFULLY BEEN DELETED :\n\n";
		}
		
	}}
	if(found==false)
	{cout<<"\nINVALID ENTRY APPOINTMENT NOT FOUND\n";}
	cout<<"\n";
	myfile.close();
	myfile2.close();
	char filename[] = "list.txt";
  	// remove the file "program.cpp"
  	remove(filename);
	char oldname[] = "list2.txt";
	char newname[] = "list.txt";
	/*	Deletes the file if exists */
	rename(oldname, newname);
	system("pause");
	system("cls");
}

void searchappointment(string fn1)
{

	bool found = false;
	ifstream myfile("list.txt");
	string keyword=fn1;
	cout<<"\n\n\t\tTHE APPOINTMENTS BOOKED BY YOU ARE AS FOLLOW :\n\n";
	cout<<"FILE_NUMBER\tNAME\tDATE_OF_APPOINTMENT\tTIMING\tCAUSE\t\tCODE_OF_BOOKING\n\n";
	if ( myfile.is_open() ) {	
	while ( myfile>>fnumber>>fname>>date>>fslot>>cause>>code ) {
		if(keyword==fnumber)
		{
			found=true;
			cout<<fnumber<<"\t    "<<fname<<"\t"<<date<<"\t"<<fslot<<"\t"<<cause<<"\t"<<code<<endl;
		}
	}}
	cout<<"\n";
	if(found==false)
	cout<<"\n File Not Found. \n";
    myfile.close();
	
	
}

void scheduledisplay(void)
{
	string slot[12]={"17:00","9:00","9:30","10:00","10:30","11:00","11:30","12:00","16:00","16:30"};
	cout<<"\n\t THE SCHEDULE FOR THIS WEEK \n";
	cout<<"\t MONDAY \t TUESDAY \t WEDNESSDAY \t THURSDAY \t FRIDAY \t SATURDAY \n\n";
	for(int i=1;i<11;i++)
	{
		cout<<slot[(i%10)]<<"\t";
		for(int j=i;j<61;j=j+10)
		{
			if(checkschedule(j)==true)
			cout<<"Booked \t\t";
			else
			cout<<"NAN   \t\t";
		}
		cout<<endl;
	}
	system("pause");
	system("cls");
}

bool checkschedule(int ch)
{
	bool found = false;
	ifstream myfile("s.txt");
	string keyword=to_string(ch);

	while (myfile >> code) {
		if (keyword == code) {
			found = true;
			break;
		}
	}
	return found;
}

void printhistory(string fn1)
{
	bool found = false;
	ifstream myfile("history.txt");
	string keyword=fn1;
	string c[8];
	cout<<"\n\n\t\tPATIENTS HISTORY :\n\n";
	if ( myfile.is_open() ) {	
	while ( myfile>>c[0]>>c[1]>>c[2]>>c[3]>>c[4]>>c[5]>>c[6] ) {
		if(keyword==c[0])
		{
			found=true;
			cout<<"\nPatients Date of Birth: "<<c[1];
			cout<<"\n\nPatient's age: "<<c[2];
    		cout<<"\n\nPatient has the following Medical Condition \n";
			cout<<"\n1.Diabetes : "<<c[3];
    		cout<<"\n2.Hypertension : "<<c[4];
			cout<<"\n3.Atherosclerosis : "<<c[5];
			cout<<"\n4.has no medical issue: "<<c[6];
		}
	}}
	cout<<"\n";
	if(found==false)
	cout<<"\n File Not Found. \n";
    myfile.close();
	
}
