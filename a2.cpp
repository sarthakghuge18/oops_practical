/*
Experiment Number 2 : Develop a program in C++ to create a database of
students information system
containing the following information: Name, Roll number, Class, Division,
Date of Birth, Blood group, Contactaddress, Telephone number, Driving license no. and other. 
Construct the database with suitable member functions. 
Make use of constructor, default constructor, copy constructor, 
destructor, static member functions, friend class, this pointer, inline code and 
dynamic memory allocation operators-new and delete as well as exception handling.
*/


#include<iostream>
using namespace std;
class student ; //to make friend class declare first 
class person
{
	private :
		string name,bloodgrp,cadd,tele,dlo,dob;
	public :
		friend class student;
		
//		person(string name)
//		{
//			this->name=name;
//			name="",bloodgrp="",cadd="",tele="",dlo="",dob="";
//		}
		person()
		{
			name="",bloodgrp="",cadd="",tele="",dlo="",dob="";
		}
		person(const person &p)
		{
			name=p.name;
			bloodgrp=p.bloodgrp;
			cadd=p.cadd;
			tele=p.tele;
			dlo=p.dlo;
			dob=p.dob;
		}
};
class student
{
	private:
		int roll;
		string classname;
		char*div;
		char d;
	public :
		static int count;
		student()
		{
			person();
			roll=0;
			classname="";
			div=NULL;
			count++;	
		}
		void accept_student(person &p)
		{
			cout<<"enter name : ";
			cin>>p.name;
			cout<<"enter bloodgroup : ";
			cin>>p.bloodgrp;
			cout<<"enter contact address :";
			cin>>p.cadd;
			cout<<"enter telephone : ";
			cin >>p.tele;
			cout<<"enter driving licence : ";
			cin>>p.dlo;
			cout<<"enter date of birth : ";
			cin>>p.dob;
			cout<<"enter roll no : ";
			cin>>roll;
			cout<<"enter class name ";
			cin>>classname;
			cout<<"enter div :";
			cin>>d;
			div=&d;
		}
		inline void display_student(person &p)
		{
			cout<<"____________________________________________"<<endl;
			cout<<"name : "<<p.name<<endl;
			cout<<"blood group : "<<p.bloodgrp<<endl;
			cout<<"contact address : "<<p.cadd<<endl;
			cout<<"telephone : "<<p.tele<<endl;
			cout<<"driving licence : "<<p.dlo<<endl;
			cout<<"date of birth : "<<p.dob<<endl;
			cout<<"roll no : "<<roll<<endl;
			cout<<"class name : "<<classname<<endl;
			cout<<"div : "<<div<<endl;
			cout<<"____________________________________________"<<endl;
		}
		
		~student()
		{
			delete div;	
		}
		
		static int get()
		{
			return count;	
		}	
};
int student::count=0;
int main ()
{
//	cout<<student::get()<<endl;
//	student s1=student();
//	cout<<student::get()<<endl;
//	student s2=student();
//	cout<<student::get()<<endl;
//	student s3=student();
//	cout<<student::get()<<endl;
	person *p[10];
	student *s[10];
	int f=0;
	while(1)
	{
		int ch;
		cout<<"1.enter student  2.display 0.exit "<<endl;
		cin>>ch;
		if (ch==1)
		{
			s[f]=new student;
			p[f]=new person;
			s[f]->accept_student(*p[f]);
			f++;
		}
		else if (ch==2)
		{
			for (int i=0;i<f;i++)
			{
				s[i]->display_student(*p[i]);	
			}
				
		}
		else if (ch==0)
		{
			cout<<"existed";
			break;
		}
		else 
		{
			cout<<"enter valid number ";
		}
	}
	

	return 0;	
}
