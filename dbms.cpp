#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include<string>
#include<windows.h>
#include<dos.h>   
#include<time.h>
using namespace std;

void add();
void dele();  
void view();
void modify();
int isdelete();
int ram();
void SetColor(int ForgC);
int static l=0;
int static b=0;
int static g;
int static q;

struct student{
    char id[4],name[30],section[10],course[30];
    
}w[1000];
struct st{
    char id7[4],name7[30],section7[10],course7[30];
    
}v[1000];
void SetColor(int ForgC)
{
     WORD wColor;               
     
     
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;   

             
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
int main()
{

    SetColor(34); 

    cout<<"\n\t\t\t\t*******************************************************WELCOME TO MYCAPTAIN SERVER*******************************************\n\n\n\n";
        cout<<"\n\n\t\t\t\t-------------------------------        \n";
    cout<< "                               |                              |\n";
    cout<< "                               |   WELCOME TO LOG IN ZONE     | \n";
    cout<<"                               --------------------------------     \n ";
    char username[10]="Adhar";
    char password[5]="123";
    char username1[10];
    char password1[5];
    bool p;
    char c;
    p=true;
    int s=0;
    

    while(p)
    {
       cout<<"\n\n\n\nEnter the username=";
       fflush(stdin);
       gets(username1);
       cout<<"\n\nEnter the password=";
       fflush(stdin);
        while((c=getch())!=13)
              {   
                  if(c==8)
                                      
                {
                    if(s!=0)
                        {s--;
                                      cout<<"\b";
                                      cout<<" \b";
                                      }}
                                    else{
                                password1[s++]=c;
                            
                             cout<<"*";}
                                }

       if(strcmp(username,username1)==0&&strcmp(password1,password)==0)
       {
           cout<<"\n..........................WELCOME SUCCESSFULLY LOGGED IN SIR!!!!...........................\n";
           Sleep(3*1000);
           cout<<"\n\n\n\nLoading................................\n\n\n";
           cout<<"\n...............................You can access the server.....................................\n";
           Sleep(2*1000);
           system("cls");
           ram();

       }
       else
       {
           cout<<"\n..........................WRONG PASSWORD OR USERNAME..................................."<<endl;
           cout<<"\nTry again"<<endl;

       }
    }
       




    
}
int ram()

{
    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t*******************************************((((STUDENT DBMS SYSTEM))))*************************************";
    char choice;
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t>Enter 1 for adding student record";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t>Enter 2 for deleting the record";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t>Enter 3 for viewing the record";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t>Enter 4 for modifying the record";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t>Enter 5 for terminating the program";
     cin>>choice;
     switch(choice)
     {
         case '1':add();
                 ram();
                  break;
        case '2':dele();
                 ram();
                   break;
        case '3':view();
                  ram();
                 break;
        case '4':modify();
                 ram();
                  break;
        case '5':system("cls");
                  cout<<"\t\t\t\t\t\t\t\t\t..........................................THANK FOR USING THIS SYSTEM VISIT AGAIN..............................";
                  exit(0);

                  break;
     }
    return 0;

}
int isdelete()
{
    
    
    if(q>g){
        return 1;

    }
    else{
        return 0;
    }

}
void add()
{   

    cout<<"\n\nLoading..................................\n";
    Sleep(3*100);
    system("cls");
    FILE *f1;
    char id1[4],na[30],sec[10],cour[30];
    cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tYOU HAVE ENTERED THE INFO ZONE\n\n\n\n";
    f1=fopen("students.txt","ab+");
    cout<<"\nEnter the id of the student= ";
    fflush(stdin);
    gets(id1);
    cout<<"\nEnter the name of the student=";
    fflush(stdin);
    gets(na);
    cout<<"\nEnter the section of the student=";
    fflush(stdin);
    gets(sec);                                             
    cout<<"\nEnter the course of the student=";
    fflush(stdin);
    gets(cour);

    strcpy(w[l].id,id1);
    strcpy(w[l].name,na);                                        
    strcpy(w[l].section,sec);
    strcpy(w[l].course,cour);
 
    fseek(f1,0L,2);
   fwrite(&w[l],sizeof(w[l]),1,f1);
   q=sizeof(w)/sizeof(w[0]);
   fclose(f1);
   cout<<l;
    l++;                                                                                  

}
void dele()
{   
       cout<<"\n\nLoading..................................\n";
    Sleep(3*100);
    system("cls");
   FILE *f2,*f3;
    char id4[5];
    int j=0;
    int c=0;
    cout<<"\n\n\n\nYOU HAVE ENTERED THE DELETION ZONE\n\n\n\n\n";
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\nEnter the students id you want to delete";
    fflush(stdin);
    gets(id4);
    
    if((f2=fopen("students.txt","ab+"))!=NULL)
    {
        while(fread(&w[j],sizeof(w[j]),1,f2))
        {
           if(strcmp(w[j].id,id4)!=0)
           {
              strcpy(v[c].id7,w[j].id);
              strcpy(v[c].name7,w[j].name);
              strcpy(v[c].course7,w[j].course);
              strcpy(v[c].section7,w[j].section);


              c++;

           }

          j++;
         


        }
    }

    fclose(f2);
f3=fopen("van.txt","wb+");
int y=0;
fseek(f3,0L,0);
while(y<=c)
{
    fwrite(&v[y],sizeof(v[y]),1,f3);
    y++;

}
fclose(f3);
  remove("students.txt");
 rename("van.txt","students.txt");





}

void  view()
{   
       cout<<"\n\nLoading..................................\n";
    Sleep(3*100);
    system("cls");
    cout<<"\n\n\n\n\nYOU HAVE ENTERED THE RECORD ZONE\n\n\n\n";
    int k=0;
  int f;
  f=l;
                        FILE *f3;
                      if((f3=fopen("students.txt","rb+"))!=NULL)
                      {
cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                     fseek(f3,0L,0);
                     if(isdelete())

                     {
                        f--;
                     }
                  
                    while(fread(&w[k],sizeof(w[k]),1,f3))
                    {     if(feof(f3))
                        {   
                            fclose(f3);
                            break;
                        }
                        
                        if(strcmp(w[k].id,"")!=0)
                        {
                       
                        cout<<"The id of the student is="<<w[k].id<<endl;
                        cout<<"The name of the student is="<<w[k].name<<endl;
                        cout<<"The section of the student is="<<w[k].section<<endl;
                        cout<<"The course of the student is="<<w[k].course<<endl;

                        if(feof(f3))
                        {   fclose(f3);
                            break;
                        }
                        


                        k++;
cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                        }        
                    }
                     
                     
                            }
                        fclose(f3);
                      }
                    
                        

void modify()
{   
       cout<<"\n\nLoading..................................\n";
    Sleep(3*100);
    system("cls");
    char id8[5];
    char nid[5],nname[10],ncourse[25],nsection[15];
    cout<<"\n\n\n\n******************************************************YOU HAVE ENTERED THE MODIFICATION ZONE***********************************************************************\n";
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"Enter the student id for modification=";
    cin>>id8;
    FILE *f8,*f6;
    int e=0;
if(f8=fopen("students.txt","ab+"))
{
    while(fread(&w[e],sizeof(w[e]),1,f8))
    {    
        if(strcmp(w[e].id,id8)==0){
        cout << "Enter new  Name : ";
         fflush(stdin);
         gets(nname);
         cout<<"Enter the new id:";
         fflush(stdin);
        gets(nid);
        cout<< "Enter new the Course    : ";
        fflush(stdin);
        gets(ncourse);
        cout << "Enter new the Section   : ";
        fflush(stdin);
        gets( nsection);
        }
        e++;
    }
    e=0;
    f6=fopen("ran.txt","wb+");

      fseek(f8,0L,0);
     while(fread(&w[e],sizeof(w[e]),1,f8)){
        if(strcmp(w[e].id,id8)==0){
         strcpy(w[e].id,nid);
          strcpy(w[e].name,nname);
           strcpy(w[e].course,ncourse);
            strcpy(w[e].section,nsection);
        }
        fwrite(&w[e],sizeof(w[e]),1,f6);
        
    
        e++;
        
}

    fclose(f8);
    fclose(f6);
    remove("students.txt");
    rename("ran.txt","students.txt");
}
}


