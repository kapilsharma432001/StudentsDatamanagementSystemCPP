#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<conio.h>
#include<string>
using namespace std;
int temp1=0,temp2=0;
void display_students();
void display_faculty();
class students
{
    public:
    int roll;
    char name[50];
    float osmarks,dbmsmarks,cppmarks,dsmarks;
    students(){};
    void getdata();
    void displaydata();
};
void students::getdata()
{
    cout<<"Enter roll number ";
    cin>>roll;
    cin.ignore();
    cout<<"\nEnter name ";
    cin.getline(name,50);
    cout<<"\n Enter marks in OS: ";
    cin>>osmarks;
    cout<<"\n Enter marks in DBMS: ";
    cin>>dbmsmarks;
    cout<<"\n Enter marks in CPP: ";
    cin>>cppmarks;
    cout<<"\n Enter marks in Data Structure ";
    cin>>dsmarks;
}
void students::displaydata()
{
    cout<<"\n Roll no: "<<roll;
    cout<<"\n Name : "<<name;
    cout<<"\n Operating System marks: "<<osmarks;
    cout<<"\n DBMS marks: "<<dbmsmarks;
    cout<<"\n CPP marks: "<<cppmarks;
    cout<<"\n DS marks: "<<dsmarks<<endl;
}
class faculty
{
public:
    int facultyid;
    char name[50];
    char subject[80];
    void getdata();
    void displaydata();
};
void faculty::getdata()
{
    cout<<"\nEnter faculty id: ";
    cin>>facultyid;
    cout<<"\nEnter Faculty Name: ";
    cin.getline(name,50);
    cout<<"\nEnter the subject faculty teach: ";
    cin.getline(subject,80);
}
void faculty::displaydata()
{
    cout<<"\n Faculty ID: "<<facultyid;
    cout<<"\n Faculty Name: "<<name;
    cout<<"\n Faculty Subject: "<<subject;
}
int main()
{
    system("cls");
    cout<<"\n 1. Admin Login"<<endl;
    cout<<"\n 2. Faculty Login"<<endl;
    cout<<"\n 3. Student Login"<<endl;
    cout<<"\n 4. Exit"<<endl;
    int choice;
    cout<<"\nEnter your choice: ";
    cin>>choice;
    if(choice==4) exit;
    else if(choice==1)
    {
        string pass = "";
        char ch;
        cout<<"Enter admin password ";
        ch = _getch();
        while(ch!=13)
        {
            pass.push_back(ch);
            cout<<"*";
            ch = _getch();
        }
        if(pass=="admin123"){
                system("cls");
            cout<<"\n\nAccess Granted\n";
            cout<<"\n\n WHAT YOU WANT\n";
            cout<<"\n 1. Students List\n";
            cout<<"\n 2.Faculty List\n";
            cout<<"\n 3. Add new students\n";
            cout<<"\n 4. Add new faculty\n";
            cout<<"\n 5. Exit\n";
                int achoice;
                cin>>achoice;
                if(achoice==5) exit(0);
                else if(achoice==3)
                {
                    int n;
                    cout<<"Enter number of students ";
                    cin>>n;
                    students s[n]; //array of n student objects
                    fstream file;
                    file.open("students_DB.txt",ios::out);
                    cout<<"WRITING STUDENT DETAILS TO THE FILE"<<endl;
                    cout<<"Enter "<<n<<" student details"<<endl;
                    temp1+=n;
                    for(int i=0;i<n;i++)
                    {
                     s[i].getdata();
                     //Writing the object to file
                     file.write((char*)&s[i],sizeof(s[i]));
                    }
                    file.close();
                }
                else if(achoice==4)
                {
                 //adding new faculty
                    int nf;
                    cout<<"Enter number of faculties you want to add: ";
                    cin>>nf;
                    temp2+=nf;
                    faculty f[nf];
                    fstream file;
                    file.open("faculty_DB.txt",ios::out);
                    cout<<"\nWRITING FACULTY DETAILS TO THE FILE";
                    cout<<"\nEnter "<<nf<<" details of faculty "<<endl;
                    for(int i=0;i<nf;i++)
                    {
                        f[i].getdata();
                        file.write((char*)&f[i],sizeof(f[i]));
                    }
                    file.close();
                }
                else if(achoice==1)
                {
                    //Displaying students
                   display_students();
                }
                else if(achoice==2)
                {
                   display_faculty();
                }
                else{
                    cout<<"Enter correct choice"<<endl;
                }
        }
        else{
            cout<<"\nAccess Aborted\n";
            exit(0);
        }
    main();
    }
    return 0;
}
void display_students()
{
    students st;
    ifstream inFile;
    inFile.open("students_DB.txt",ios::binary);
    if(!inFile)
    {
        cout<<endl<<"File couldn't be open!!!Press any key"<<endl;
        cin.ignore();
        cin.get();
        return;
    }
    cout<<endl<<"DISPLAYING ALL RECORD"<<endl;
    while(inFile.read(reinterpret_cast<char *>(&st),sizeof(students)))
    {
        st.displaydata();
        cout<<"\n\n============================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}
void display_faculty()
{
    faculty f;
    ifstream inFile;
    inFile.open("faculty_DB.txt",ios::binary);
    if(!inFile)
    {
        cout<<endl<<"Couldn't open file!! Press any key"<<endl;
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"Displaying all record"<<endl;
    while(inFile.read(reinterpret_cast<char *>(&f),sizeof(faculty)))
    {
        f.displaydata();
        cout<<"\n\n============================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}
