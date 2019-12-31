#include<iostream.h>
#include<fstream>
#include<iomanip>
using namespace std;
class student
{
int rollno;
char name[50];
int p_mark, c_mark, e_marks, cs_marks;
double per;
char grade;
void calculate();
public:
void getdata();
void showdata() const;
void show_tabular() const;
int retrollno() const;
void student::calculate()
{
per=p_mark+c_marks+m_marks+e_marks+cs_marks)/5,0;
if(per>=60)
grade='a';
else if (per>=50);
grade='b'
else if(per>=33)
grade='c'
esle
grade='f'
}
void student::getdata()
{
cout<<"\nEnter the roll number of student";
cin>>rollno;
cout<<"/n/nEnter the name of student";
cin.ignor();
cin.getline(name,50);
cout<<"/nEnter the mark in physics out of 100:";
cin>>p_marks;
cout<<"\nEnter the marks in maths out of 100:";
cin>>m_marks;
cout<<"\nEnter the marks in english out of 100:";
cin>>e_marks;
cout<<"\nEnter the marks in computer science out of 100:";
cin>>cs_marks;
calculate();
}
void student::showdata() const
{
cout<<"\nRoll number of student : "<<rollno;
cout<<"\nName of student :"<<name;
cout<<"\nMarks in physics :"<<p_marks;
cout<<"\nMarks in chemistry:"<<c_marks;
cout<<"\nMarks in maths:"<<m_marks;
cout<<"\nMarks in english:"<<e_marks;
cout<<"\nMarks in computer science:"<<cs_marks;
cout<<"\nPercentage of student is:"<<per;
cout<<"\nGrade of student is:"<<grade;
}
void student::show_tabular()const
{
cout<<rollno<<setw(6)<<" "<<name<<setw(10)<<p_marks<<setw(4)<<c_marks<<setw(4)<<c_marks<<setw(4)<<m_marks<<setw(4)
<<e_marks<<setw(4)<<cs_marks<<setw(8)<<per<<setw(6)<<grade<<endl;
}
int student::retrollno() const
{
return rollno;
}
void write_student();
void display_all();
void display_sp(int);
void modify_student(int);
void delete_student(int);
void class_result();
void result();
void intro();
void entry_menu();
int main()
{
char ch;
cout.setf(ios::fixed|ios::showpoint);
cout<<setprecision(2);
intro();
do
{
system("cls");
cout<<"\n\n\n\tmain menu";
cout<"<\n\n\to1. result menu";
cout<<"\n\n\to2. entry/edit menu";
cout<<"\n\n\to3. exit";
cout<<"\n\n\tplease select your option (1-3)";
cin>>ch;
switch(ch)
{
case'1': result();
break;
case '2':entry_menu():
break;
case '3':
break;
default :cout<<"\a";
}
}while(ch!='3');
return 0;
}
void write_student()
{
student st;
ofstream outfile;
outfile.open("student.dat",ios::binary|ios::app);
st.getdata();
outfile.close();
cout<<"\n\nstudent record has been creted";
cin.ignore();
cin.get();
}
void display_all()
{
student st;
ifstream infile;
infile.open("student.dat",ios::binary);
if(infile)
{
cout<<"file could not be open !! press any key...";
cin.ignore();
cin.get();
return;
}
cout<<\n\n\n\t\tdisplay all record !!!\n\n";
while(infile.read(reinterpret_cast<char*>(&st),sizeof(student)))
{
st.showdata();
cout<<"/n/n=========================================================\n";
}
infile.close();
cin.ignor();
cin.get();
}
void display_sp(int n)
{
student st;
ifstream infile;
infile.open("student.dat',ios::binary);
if(!infile)
{
cout<<"filecould not be open!! Press any key....";
cin.ignore();
cin.get();
return;
}
bool flag=false;
while(infile.read(reintpret_cast<char *>(&st),sizeof(student)))
{
if(st.retroll()==n)
{
st.showdata();
flag=true;
}
}
infile.close();
if(flag==false)
cout<<"\n\nrecord not exist";
cin.ignore();
cin.get();
}
void modify_student(int n)
{
bool found=false;
student st;
fstream file;
file.open("student.dat", ios:: binary|ios::ios::out);
if(!file)
{
cout<<"file could not be open !! press any key...";
cin.ignor ();
cin.get();
return;
}
while(!file .eof()&& found==false)
{
file.read(reinterpret_cast<char*>(&st);
sizeof(student));
if(st.retrollno()==n)
{
st.showdata();
cout<<"\n\nPlease Enter the new details of
student"<<endl;
st.getdata();
int pos=(-1)*static_cast<int>(sizeof(st));
file.seekp(pos,ios::cur);
file.write(reinterpret_cast<char>*) (&st),
sizeof(student));
cout<<"\n\n\tRecord update";
found=true;
}
}
file.close();
if(found==false)
cout<<"/n/n Record not found";
cin.ignore();
cin.get();
}
void delete_student(int n)
{
student st;
ifstream infile;
infile.open("student,dat",ios::binary);
if(|infile)
{
cout<<"file could not be open|| press any key...";
cin.ignore();
cin.get();
return;
}
ofstream outfile;
outfile.open("temp,dat",ios::out);
infile.seekg(0,ios::beg);
while(infile.read(reinterpret_cast<char*>(&st),
sizeof(student)))
{
if(st.retrollno()!=n)
{
outfile.write(reinterpret_cast<char*> (&St),
sizeof(student)));
}
}
outfile.close();
infile.close();
remove("student.dat");
rename("temp.dat","student.dat");
cout<<"\n\n\trecord deleted..";
cin.ignore();
cin.get();
void class_result()
{
student st;
ifstream infile;
infile.open("student'dat",ios::binary);
if(!infile)
{
cot<<"file could not be open!!press any key....";
cin.ignore():
cin.get();
}
cout<<"\n\n\t\tall student result\n\n"
while(infile.read(reinterpert_cast<char*>(&st),
sizof(student)))
{
st.show_tabular();
}
cin.ignore();
cin.get();
infile.close();
}
void result()
{
char ch ;
int rno;
system("cls");
cout<<"\n\n\n\tresult menu";
cout<<"\n\n\n\t1.class result";
cout<<\n\n\t2.student report card";
cout<<\n\n\t3.back to main menu";
cin>>ch;
system("cls");
switch(ch)
{
case'1':class_result();break;
case'2':\n\n\tenter rollnumber of student:";
cin>>rno;
	  display_sp(rno);break;
case'3':break;
default: cout<<"\a";
}
}
void intro()
{
cout<<"\n\n\n\t\t STUDENT";
cout<<"\n\n\t\tREPORT CARD";
cout<<"\n\n\t\t PROJECT";
cout<<"\n\n\ntMADE BY:SULAB AGRAWAL";
cout<<"\n\tSCHOOL : CAMBRIDGE SCHOOL";
cin.get();
}
void entery_menu()
{
char ch;
int num;
system("cls");
cout<<"\n\n\n\tENTRY MENU";
cout<<"\n\n\t1.CREATE STUDENT RECORD";
cout<<"\n\n\t2.DISPLAY STUDENT RECORDS";
cout<<"\n\n\t3.SEARCH STUDENT RECORD";
cout<<"\n\n\t4.MODIFY STUDENT RECORD";
cout<<"\n\n\t5.DELETE STUDENT RECORD";
cout<<"\n\n\t6.BACK TO MAIN MENU";
cout<<"\n\n\tPLEASE ENTER YOUR CHOICE(1-6)";
cin>>ch;
system("cls");
switch(ch)
{
case '1': write_student();break;
case '2': display_all();break;
case '3': cout<<"\n\n\tplease enter the roll number";
cin>>num;
case '4': cout<<"\n\n\tplease enter the roll number";
cin>>num;
  modify_student(num); break;
case '5': cout<<"\n\n\tplrease enter the roll number";
cin>>num;
case '6': break;
default: cout<<"\a"; entry_menu();
}
}