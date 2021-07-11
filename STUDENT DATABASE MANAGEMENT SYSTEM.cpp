#include<bits/stdc++.h>
#include<fstream>
using namespace std;
void search();
void deleted();
void modify();
void insert();
void show();
int main()
{
    menustart:
	system("color a");
	int choice;
	char x,t;
	do{
		cout<<"-------------------------------------------------------------"<<endl;
	cout<<"          -----     STUDENT MANAGEMENT SYSTEM     -----"<<endl;
	cout<<endl;
	cout<<"                  PRESS 1 FOR INSERTING RECORD"<<endl;
	cout<<"                  PRESS 2 FOR SHOWING RECORD"<<endl;
	cout<<"                  PRESS 3 FOR DELETING RECORD"<<endl;
	cout<<"                  PRESS 4 FOR SEARCHING RECORD"<<endl;
	cout<<"                  PRESS 5 FOR MODIFYING RECORD"<<endl;
	cout<<"                  PRESS 6 FOR EXIT"<<endl;
	cout<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
		do{
			   cout<<"enter records"<<endl;
		       insert();
		       cout<<"do you want to another record(y/n)";
		       cin>>x;
		   }while(x=='y' || x=='Y');
		   break;
		case 2:
		       show();
		       break;
		case 3:
		       deleted();
		       break;
		case 4:
		       search();
		       break;
		case 5:
		       modify();
		       break;
		case 6:
		cout<<"program is exiting"<<endl;
		exit(0);
		default:
			cout<<"invalid choice"<<endl;
		}
			cout<<"do you want to perform more operation (y/n)";
			cin>>t;
	}while(t=='y' || t=='Y');
	goto menustart;
		}
	     struct student
	     {
	     	char name[50];
	     	char course[50];
	     	int roll;
	     	float cgpa;
		 }obj;
		 void insert()
		 {
		 	fstream file;
		 	cout<<"Enter Name=";
		 	cin>>obj.name;
		 	cout<<endl;
		 	cout<<"Enter Course=";
		 	cin>>obj.course;
		 	cout<<endl;
		 	cout<<"Enter Roll Number=";
		 	cin>>obj.roll;
		 	cout<<endl;
		 	cout<<"Enter CGPA=";
		 	cin>>obj.cgpa;
		 	cout<<endl;
		 	file.open("student.txt",ios::app|ios::out);
		 	file<<obj.name<<" "<<obj.course<<" "<<obj.roll<<" "<<obj.cgpa<<endl;
		 	file.close();
		 }
		 void show()
		 {
		 	int i=1;
		 	fstream file;
		 	file.open("student.txt",ios::in);
		 	if(!file.is_open())
		 	cout<<"file is not present"<<endl;
		 	else
		 	{
		 		cout<<"records are:"<<endl;
		 		file>>obj.name>>obj.course>>obj.roll>>obj.cgpa;
			 while(!file.eof())
	 	    {
            cout<<"RECORD OF "<<i<<" STUDENT :"<<endl;
	 	    cout<<"NAME="<<obj.name<<endl<<"COURSE="<<obj.course<<endl<<"ROLL NUMBER="<<obj.roll<<endl<<"CGPA="<<obj.cgpa<<endl;	
			cout<<"--------------------------------------"<<endl;
			file>>obj.name>>obj.course>>obj.roll>>obj.cgpa;
			i++;
			}
			file.close();
		   }
		 }
		 void deleted()
		 {
		 	
            ifstream file;
		    ofstream t;
		    t.open("temp.txt",ios::out);
		 	int sroll;
		 	file.open("student.txt",ios::in);
		 	if(!file.is_open())
		 	cout<<"file is not present"<<endl;
		 	else
		 	{
		 		cout<<"ENTER ROLL NUMBER YOU WANT TO DELETE"<<endl;
		 		cin>>sroll;
		 		file>>obj.name>>obj.course>>obj.roll>>obj.cgpa;
			 while(!file.eof())
	 	    {
            if(sroll!=obj.roll)
            {
	 	    t<<obj.name<<" "<<obj.course<<" "<<obj.roll<<" "<<obj.cgpa<<endl;	
			}
			file>>obj.name>>obj.course>>obj.roll>>obj.cgpa;
		    }
		    t.close();
		file.close();
		remove("student.txt");
		rename("temp.txt","student.txt");
			}
		}
		 void search()
		 {
		 	fstream file;
		 	int sroll,flag=0;
		 	file.open("student.txt",ios::in);
		 	if(!file.is_open())
		 	cout<<"file is not present"<<endl;
		 	else
		 	{
		 		cout<<"ENTER ROLL NUMBER YOU WANT TO SEARCH"<<endl;
		 		cin>>sroll;
		 		file>>obj.name>>obj.course>>obj.roll>>obj.cgpa;
			 while(!file.eof())
	 	    {
            if(sroll==obj.roll)
            {
	 	    cout<<"NAME="<<obj.name<<endl<<"COURSE="<<obj.course<<endl<<"ROLL NUMBER="<<obj.roll<<endl<<"CGPA="<<obj.cgpa<<endl;
			 flag=1;	
			}
			file>>obj.name>>obj.course>>obj.roll>>obj.cgpa;
		    }
		    if(flag==0)
		    cout<<"NOT FOUND STUDENT OF THIS ROLL NUMBER"<<endl;
			file.close();
		   }
		 }
		 void modify()
		 {
            fstream file;
			ofstream t;
		 	int droll,flag;
		 	file.open("student.txt",ios::in);
		 	t.open("temp.txt",ios::out);
		 	if(!file.is_open())
		 	{
		 		cout<<"FILE NOT FOUND"<<endl;
			}
			else
			{
				cout<<"ENTER ROLL NUMBER YOU WANT TO MODIFY"<<endl;
				cin>>droll;
				file>>obj.name>>obj.course>>obj.roll>>obj.cgpa;
				while(!file.eof())
	 	        {
				if(droll==obj.roll)
				{
					cout<<"OLD RECORDS ARE"<<endl;
					cout<<"NAME="<<obj.name<<endl<<"COURSE="<<obj.course<<endl<<"ROLL NUMBER="<<obj.roll<<endl<<"CGPA="<<obj.cgpa<<endl;
					cout<<"enter name=";
					cin>>obj.name;
					cout<<"enter course=";
					cin>>obj.course;
					cout<<"enter cgpa=";
					cin>>obj.cgpa;
					t<<obj.name<<" "<<obj.course<<" "<<obj.roll<<" "<<obj.cgpa<<endl;
                 	}
                 	else
                 {
                 	t<<obj.name<<" "<<obj.course<<" "<<obj.roll<<" "<<obj.cgpa<<endl;
                 }
                 file>>obj.name>>obj.course>>obj.roll>>obj.cgpa;
			   }
            t.close();
			file.close();
			remove("student.txt");
			rename("temp.txt","student.txt");	
				}
		 }
		 
