# K1616question14
#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int temp;                 //temporary variable
	int n;                   //number of processes
	int p[10];               //process
	int pp[10];              //process priority
	int Btime[10];          //burst time
	int w[10];             //waitimg time
	int t[10];            //turnaroundtime
	int Atime[10];        //arrival time
	int awt,atat,i,tq;    //awt is average waiting time, atat is average turn around time, tq is time quantum
	
	cout<<"enter the number of processes";
	cin>>n;
	cout<<"Enter time quantum";
     cin>>tq;
	 cout<<"\n\t Enter burst time  time priority   Arrival time  \n";
	 cout<<"/n/t enter time priority"
	 cout<<"enter arrival time"
	 for(i=0;i<n;i++)
    {
      cout<<"\nProcess["<<i+1<<"]:";
      cin>>Btime[i]>>pp[i]>>Atime[i];
      p[i]=i+1;
    }

      //sorting done on the basis of priority 
    for(i=0;i<n-1;i++)
     {
      for(int j=i+1;j<n;j++)
      {
       if(pp[i]<pp[j])
       {
     temp=pp[i];
     pp[i]=pp[j];
     pp[j]=temp;
     temp=Btime[i];
     Btime[i]=Btime[j];
     Btime[j]=temp;
     temp=p[i];
     p[i]=p[j];
     p[j]=temp;
      }
   }
}
w[0]=0;
awt=0;
t[0]=Btime[0];
atat=t[0];
for(i=1;i<n;i++)
 {
 	if(tq<n || tq>n) 
	 {
	 
     w[i]=t[i-1];
     awt+=w[i];
     t[i]=w[i]+Btime[i];
     atat+=t[i];
	 }
 }
 for(i=0;i<n;i++)
 {
 	cout<<"P"<<p[i]<<" ";
 }
//to display all the process
 
cout<<"\n\nProcess \t Burst Time \tArrival time  \t Wait Time \t Turn Around Time   Priority \t \n";
for(i=0;i<n;i++)
cout<<"\n   "<<p[i]<<"\t\t   "<<Atime[i]<<"\t\t  "<<Atime[i]<<"\t\t  "<<w[i]<<"\t\t     "<<t[i]<<"\t\t     "<<pp[i]<<"\n";
awt=awt/n;
atat=atat/n;
cout<<"\n Average Waiting Time : "<<awt;
cout<<"\n Average Turn Around Time : "<<atat;
getch();
}

