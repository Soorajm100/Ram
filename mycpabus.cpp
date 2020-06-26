#include <conio.h>

#include <cstdio>

#include <iostream>

#include <string.h>

#include <cstdlib>

#include<stdbool.h>

using namespace std;

static int p = 0;

class busy

{

  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];

public:

  void setup();

  void distribution();

  void emp();

  void show();

  void ready();

  void current(int i);
  
  

}

bus[10];

void kal()
{
        int r, h, n;

    n=10;

    for(r=n/2; r<=n; r+=2)
    {
        for(h=1; h<n-r; h+=2)
        {
            cout<<" ";
        }

        for(h=1; h<=r; h++)
        {
            cout<<"*";
        }

        for(h=1; h<=n-r; h++)
        {
            cout<<" ";
        }

        for(h=1; h<=r; h++)
        {
            cout<<"*";
        }

        cout<<"\n";
    }

    for(r=n; r>=1; r--)
    {
        for(h=r; h<n; h++)
        {
            cout<<" ";
        }

        for(h=1; h<=(r*2)-1; h++)
        {
            cout<<"*";
        }

        cout<<"\n";
}
}
void vline(char ch)

{

  for (int i=80;i>0;i--)

  cout<<ch;

}

void busy::setup()

{
 system("cls");
 cout<<"WELCOME TO THE BUS INFO ZONE";
  cout<<"\nEnter bus no: ";

  cin>>bus[p].busn;

  cout<<"\nEnter Driver's  name: ";

  cin>>bus[p].driver;

  cout<<"\nArrival time: ";

  cin>>bus[p].arrival;

  cout<<"\nDeparture: ";

  cin>>bus[p].depart;

  cout<<"\nFrom: \t\t\t";

  cin>>bus[p].from;

  cout<<"\nTo: \t\t\t";

  cin>>bus[p].to;

  bus[p].emp();

  p++;

}

void busy::distribution()

{

  int seat;

  char number[5];

  fall:

  cout<<"\nBus no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>32)

    {

      cout<<"\nThere are only 32 seats available in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"Enter your or passengers name: ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];

        break;

      }

    else

      cout<<"The seat  was reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct bus no.\n";

      goto fall;

    }

  }


void busy::emp()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}

void busy::show()

{

  int n;

  char nu[5];

  cout<<"\nEnter bus no: ";

  cin>>nu;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, nu)==0)

    break;

  }

while(n<=p)

{

  vline('*');

  cout<<"Bus no: \t"<<bus[n].busn

  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"

  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart

  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<

  bus[n].to<<"\n";

  vline('*');

  bus[0].current(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"\nEnter correct bus no:\n ";

}

void busy::current(int l)

{

  int s=0,p=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          p++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;

  }

void busy::ready()

{


  for(int n=0;n<p;n++)

  {

    vline('*');

    cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver

    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"

    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"

    <<bus[n].to<<"\n";

    vline('*');

    vline('_');

  }

}

int main()

{

system("cls");
 system("Color 7C");

int w;
bool s=true;


cout<<"\n\t\tWELCOME TO THE BUS RESERVATION SYSTEM \n\n\n";
   
   vline('*');
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   kal();

while(s)

{


  cout<<"\n\n\n\n\n";
  vline('*');

  cout<<"\n\n\t\t\tEnter 1 To establish the seat \n\t\t\t";

cout <<"Enter 2 To reserve the seat\n\t\t\t";

  cout<<"Enter 3 for Showing the data of seats\n\t\t\t";

  cout<<"Enter  4 for checking the Bus availabilty. \n\t\t\t";

 cout <<"Eter 5 for Terminating";

  cout<<"\n\t\t\tEnter your number for choice= ";

  cin>>w;
  

  switch(w)

  {

    case 1:  bus[p].setup();

      break;

    case 2:  bus[p].distribution();

      break;

    case 3:  bus[0].show();

      break;

    case 4:  bus[0].ready();

      break;

    case 5:  exit(0);

  }
    vline('*');

}

return 0;

}
