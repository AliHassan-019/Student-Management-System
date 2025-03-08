#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class student			//Base class
{
	protected:
		string name,department,reg_no,semester;
		public:
			void get_data() 		//Function to get student information from user
			{
				cout<<"\nEnter Name of Student :	";cin>>name;
				cout<<"\nEnter Registration no of Student :	";cin>>reg_no;
				cout<<"\nEnter Department of Student :	";cin>>department;
				cout<<"\nEnter Semester of the Student :	";cin>>semester;
			}
			void show_data()     //Function to display student information
			{
				cout<<"\nName : "<<name;
				cout<<"\nReg # : "<<reg_no;
				cout<<"\nDepartment : "<<department;
				cout<<"\nSemester : "<<semester;
			}
};
class gpa : public student   //child class publically derived from base class
{
	protected:
		int marks [100],obtained_marks,t_marks;float percentage,cgpa;
		public:
			int i,j;
			gpa()		//default constructor
			{
				t_marks=100;
				obtained_marks = 0;
				percentage=0;
				cgpa = 0;
			}
			void get_data()
			{
				
				student :: get_data();  //function overriding, to access base class function
				cout<<"\nEnter Total Number of Subjects :	";cin>>i;
				t_marks = t_marks*i;
				for(j=0; j<i; j++) //for loop run according to the number of students
				{
					cout<<"\n\nEnter mark in subject "<<j+1<<" out of 100 :	";
					cin>>marks[j];
					obtained_marks=obtained_marks+marks[j];
					percentage = obtained_marks/i;
					cgpa= ((percentage-16)/16)-1;
				}
	 		}
			void show_data()
			{
				if(cgpa>=4) //if,else if statment to display the output if condition satisfies
				{
					cout<<"\n\t"<<name<<"t"<<cgpa<<"\t A+";
				}
				else if(cgpa>=3.7)
				{
					cout<<"\n\t"<<name<<"\t"<<cgpa<<"\t A-";
				}
				else if(cgpa>=3.3)
				{
					cout<<"\n\t"<<name<<"\t"<<cgpa<<"\t B+";
				}
				else if(cgpa>=3.0)
				{
					cout<<"\n\t"<<name<<"\t"<<cgpa<<"\t B";
				}
				else if(cgpa>=2.6)
				{
					cout<<"\n\t"<<name<<"\t"<<cgpa<<"\t B-";
				}
				else if(cgpa>=2.3)
				{
					cout<<"\n\t"<<name<<"\t"<<cgpa<<"\t C+";
				}
				else if(cgpa>=2.0)
				{
					cout<<"\n\t"<<name<<"\t"<<cgpa<<"\t C";
				}
				else if(cgpa>=1.7)
				{
					cout<<"\n\t"<<name<<"\t"<<cgpa<<"\t D";
				}
				else if(cgpa>=1.3)
				{
					cout<<"\n\t"<<name<<"\t"<<cgpa<<"\t E";
				}
				else if(cgpa<1.3)
				{
					cout<<"\n\t   "<<name<<"\t"<<cgpa<<"\t F";
				}
			}	
};
class fees : public student //another child class publically derived from base class
{
	protected:
		int s,semester_fees,transport_fees,hostel_fees;
		public:
			fees()  	//default constructor
			{
				semester_fees = 0;
				transport_fees = 0;
				hostel_fees = 0;
				s = 0;
			}
			char t,h;
		
			void get_data()
			{
				student :: get_data();	//Function to display student information
				cout<<"\nEnter Student Semister Fees :	";cin>>semester_fees;
				cout<<"\nDoes student use transport facility? (y/n) :	";cin>>t;
				if(t=='y') 	//asks user that whether he use transport facility or not
				{
					cout<<"\nEnter Transport Fees :	";cin>>transport_fees;
					s = semester_fees+transport_fees;	//adding fees
				}
				else if(t=='n')
				{
					s = semester_fees+0;
				}
				cout<<"\nDoes Student uses Hostel facility (y/n) :	";cin>>h;
				if(h=='y')	//asks user that whether he use hostel facility or not
				{
					cout<<"\nEnter Hostel Fees :	";cin>>hostel_fees;
					s = semester_fees+transport_fees+hostel_fees;
				}
				else if(h=='n')
				{
					s = semester_fees+transport_fees+0;
				}
				
			}
			void show_data()	//display the output.
			{
				
				cout<<"\n   "<<name<<"\t   "<<semester_fees<<"\t  "<<transport_fees<<"\t\t\t"<<hostel_fees<<"\t    "<<s<<"\n";
			}
};
class attendance : public student //another child class publically derived from base class
{
	protected:
		string attend [100];
		public:
			int a,n,present;
			void get_data()
			{
				student :: get_data(); //asks user that whether he use transport facility or not
				cout<<"\nEnter total number of days that you want to mark attendance :	";cin>>n;
				for(a=0;a<n;a++) //for loop run according to the number of days
				{
					cout<<"\n\nMark the Attendance of Day "<<a+1<<" :	";
					cin>>attend[a];
					
				}
			}
			void show_data() //display the output
			{
				cout<<"    __________________________________________________________\n";
				cout<<"\n\tName\t";
				for(int q=0;q<n;q++)
				{
					cout<<"      Day "<<q+1<<"   ";
				}
				cout<<"\n    __________________________________________________________";
				cout<<"\n\n\t"<<name;
				for(a=0;a<n;a++)
				{
					cout<<"     "<<attend[a];
				}
				cout<<"\n\n   ----------------------------------------------------------";
		    }
};
class course : public student //another child class publically derived from base class
{
	protected:
		string teacher[100],subject[100],code[100];
		public:
			int n,a;
			void get_data()
			{
				student::get_data(); //asks user that whether he use transport facility or not
				cout<<"\nEnter total number of courses that you want to add :	";cin>>n;
				for(a=0;a<n;a++) //for loop run according to the number of courses
				{
					cout<<"\n\nEnter Instructor Name of course "<<a+1<<" :	";cin>>teacher[a];
					cout<<"\nEnter Title of course "<<a+1<<" :	";cin>>subject[a];
					cout<<"\nEnter Code of Course "<<a+1<<":\t  ";cin>>code[a];
					cout<<"____________________________________________________________";
				}
			}
			void show_data() //display the output
			{
				cout<<"\n__________________________________________________________________________\n";
				cout<<"\n   NO:\tINSTRUCTOR\tSUBJECT\t\tCODE";
				cout<<"\n__________________________________________________________________________";
				for(a=0;a<n;a++)
				{
					
					cout<<"\n\n   "<<a+1;
					cout<<"\t"<<teacher[a];
					cout<<"\t"<<subject[a];
					cout<<"\t\t"<<code[a];
					
				}
				cout<<"\n\n________________________________________________________________________";
				
			}
};
int main() //main function
{
	gpa g1[100];	//array of class object
	fees f1[100];	//array of class object
	attendance at;	//object of child class
	course co;		//object of derived class
	int x,student;
	int p;
	string r;
	string  user_name,password;
	do		//do while loop 
	{
		cout<<"\n\n";
		cout<<"\t\t\t\t\t\t   Submit Date: 17th Jan,2022.\n";
		cout<<"--------------------------------------------------------------------------------";
   		cout<<"Project Title:\n\n";
		cout<<"                    STUDENT MANAGEMENT SYSTEM             "<<endl;
    	cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
    	cout<<"GROUP MEMBERS:";
    	cout<<"\n\n\n\t\tAli Hassan(003)\n\n\t\tMamoon Khan(016)\n\n\t\tHassan_Noor(006)\n";
    	cout<<"\n\n\t\t\t\t\t\t   Submit To: Mam Laraib Malik.\n";
    	cout<<"________________________________________________________________________________";
		cout<<"\n\nPress any key to continue : ";cin>>r;
	}while(r ==" ");
	system("cls");
	cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"                       		 FACULTY LOGIN             "<<endl;
    cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
    cout<<"\tUSER NAME:\t";cin>>user_name;
    if(user_name == "fa20-bee") //if stament to check the username
    {
    	cout<<"\n\tPASSWORD:\t";cin>>password;
    	cout<<"\n\t____________________________________________________________";
    	if(password == "comsats")	//if statment to check the password
    	do
		{
		{
			system("cls");
			cout<<"\n\t\t\t\tWELCOME TO MY CODE";
			cout<<"\n\t\t\t     ________________________";
			cout<<"\n\n\tMENU:";	//menu page
			cout<<"\n\t----";
    		cout<<"\n\t\t1. CALACULATE GPA OF STUDENT";
			cout<<"\n\t\t2. MAKE FEE CHALLAN OF STUDENT";
			cout<<"\n\t\t3. MARK THE ATTENDANCE OF STUDENT";
			cout<<"\n\t\t4. ADD COURSES OF THE STUDENT";
			cout<<"\n\t\t5. EXIT THIS PROGRAMME";
			cout<<"\n\t____________________________________________________________";
			cout<<"\n\nEnter your Input : ";cin>>x;
			system("cls");
			if(x==1)
			{
				
				system("cls");
				cout<<"\n\t\t\t  _________________________\n";
				cout<<"\n\t\t\t       CALCULATING GPA     ";
				cout<<"\n\t\t\t  _________________________\n\n";
				cout<<"\nEnter total number of students : ";cin>>student;
				
				for(int a=0;a<student;a++)
				{
					cout<<"\n\n\t\t\t Student "<<a+1<<"\n";
					cout<<"\t\t       ______________\n";
					g1[a].get_data();//calling get data function of gpa class	
				}
				system("cls");
				cout<<"\n\t\t\t  ____________________________\n";
				cout<<"\n\t\t\t       GPA OF STUDENTS     ";
				cout<<"\n\t\t\t  ____________________________\n\n";
				cout<<"\n   ______________________________________________\n";
				cout<<"\n\t Name\t\tGPA\tGRADE";
				cout<<"\n   ______________________________________________\n\n";
				for(int a=0;a<student;a++)
				{
					g1[a].show_data();//calling showdata function of gpa class
					cout<<"\n";
				}
			}
			else if(x==2)
			{
				cout<<"\n\t\t\t  ___________________________\n";
				cout<<"\n\t\t\t       ENTER FEE DETAILS     ";
				cout<<"\n\t\t\t  ___________________________\n\n";
				cout<<"\nEnter total number of students : ";cin>>student;
				for(int a=0;a<student;a++)
				{
					cout<<"\n\n\t\t\t Student "<<a+1<<"\n";
					cout<<"\t\t       ______________\n";
					f1[a].get_data();	//calling get data function of fees class
				}
				system("cls");
				cout<<"\n\t\t\t  ____________________________\n";
				cout<<"\n\t\t\t       STUDENT TOTAL FEES     ";
				cout<<"\n\t\t\t  ____________________________\n\n";
				cout<<"\n________________________________________________________________________________";
				cout<<"\n\n\n   Name\t\tSemester Fees    Transport Fees     Hostel Fees     Total Fees";
				cout<<"\n________________________________________________________________________________";
				for(int a=0;a<student;a++)
				{
					f1[a].show_data();	//calling show data function of fees class
				}
			}
			else if(x==3)
			{
				system("cls");
				cout<<"\n\t\t\t  _________________________\n";
				cout<<"\n\t\t\t       MARK ATTENDANCE     ";
				cout<<"\n\t\t\t  _________________________\n\n";
				cout<<"\nEnter total number of students : ";cin>>student;
				for(int a=0;a<student;a++)
				{
					cout<<"\n\n\t\t\t Student "<<a+1<<"\n";
					cout<<"\t\t       ______________\n";
					at.get_data();	//calling get data function of attendance class
					system("cls");
					cout<<"\n\t\t\t  ____________________________\n";
					cout<<"\n\t\t\t       ATTENDANCE DETAILS     ";
					cout<<"\n\t\t\t  ____________________________\n\n";	
					cout<<"\n\t\t\t Student "<<a+1<<"\n";
					cout<<"\t\t       ______________\n";
					at.show_data();	//calling show data function of attendance class
				}
			}
			else if (x==4)
			{
				system("cls");
				cout<<"\n\t\t\t  _____________________\n";
				cout<<"\n\t\t\t       ADD COURSES     ";
				cout<<"\n\t\t\t  _____________________\n\n";
				cout<<"\nEnter total number of students : ";cin>>student;
				for(int a=0;a<student;a++)
				{
					cout<<"\n\n\t\t\t Student "<<a+1<<"\n";
					cout<<"\t\t       ______________\n";
					co.get_data();	//calling get data function of courses class
					system("cls");
					cout<<"\n\t\t\t  ____________________________\n";
					cout<<"\n\t\t\t       REGISTERED COURSES     ";
					cout<<"\n\t\t\t  ____________________________\n\n";	
					co.show_data();	//calling show data function of courses class
				}
			}
			else if (x==5)
			{
				cout<<"\n\tTHANKS FOR USING OUR CODE!";break;//break statment to exit the programme
			}		
		}
		cout<<"\n________________________________________________________________________________";
		cout<<"\n\t1. GO BACK TO MAIN MENU\n\n\t2. EXIT THIS CODE";
		cout<<"\n________________________________________________________________________________";
		cout<<"\n\nEnter your input : ";cin>>p;
	}while(p==1);
		else
		{
			cout<<"\n\nWarning! INCORRECT PASSWORD";
		}
		
	}
	else
	{
		cout<<"\n\nWarning! INCORRECT USERNAME";
	}

}
