#include <iostream>
#include<stdio.h>
using namespace std;
int intro();
struct Entry{
        string name;
        int day,month,year; /* This will hold the details of a person */
        int age;
        string address;
        string come_from;
        string go_to;
        int room_no;
};
struct heavy{
        int status=0;
        struct Entry data;  /* This will contain Status and The Struct Entry(detail). data is a variable whose datatype is 'Struct Entry' */
};
int main()
{   struct heavy room[323]; /* This will contain 323 blocks of type Struct Heavy*/
    int choice=intro(); /* We are calling intro() function and taking input from user about What to do*/
    while(choice!=0){
    if(choice==1){  /* If 1 is selected then this piece of code will be executed */
        int rpt;
        cout<<"Total Entries for today-";
        cin>>rpt;   /* Asking user about how many People to register today*/
        cin.ignore();   /*This is to consume 'Enter' symbol as the getline() function could think 'Enter' as its input*/
        for (int i=0;i<rpt;i++){
            int just=0;
            while(room[just].status==1 && just<323){
                just=just+1;}
            room[just].status=1;    /* If the room is empty then Mark it as 1(occupied) and take his/her details and store them*/
            cout<<"Details of Person Number "<<i+1<<endl;
            cout<<"Name: ";
            getline(cin,room[just].data.name);
            cout<<"Age: ";
            cin>>room[just].data.age;
            cin.ignore();
            cout<<"Address: ";
            getline(cin,room[just].data.address);
            cout<<"Coming From: ";
            getline(cin,room[just].data.come_from);
            cout<<"Going to: ";
            getline(cin,room[just].data.go_to);
            cout<<"Date of Arrival: ";
            cin>>room[just].data.day>>ws>>room[just].data.month>>ws>>room[just].data.year;/* Date format DD MM YYYY*/
            cin.ignore();
            room[just].data.room_no=89+just;
            cout<<"Alloted Room Number-"<<room[just].data.room_no<<endl;
        }
        cout<<endl;
        cout << "Enter the number corresponding to the choice above- " << endl;
        cout << "Enter 0 to stop." << endl;
        cin>>choice; /* After performing the above task, it will ask again What to do next*/
        }
    else if(choice==2){/* If 2 is selected then this piece of code will be executed */
        cout<<"Enter today's date: "<<endl;
        int d1,d2,m1,m2,y1,y2;
        cin>>d1>>ws>>m1>>ws>>y1;/* We will take today's date as an input and with it We will find the date 14 days ago*/
        int ck;
        if(d1-14>0){
            d2=d1-14;
            m2=m1;
            y2=y1;
        }
        else{
            m1=m1-1;
            if(m1==1)
                ck=31;
            else if(m1==2 && y1%4==0)
                ck=29;
            else if(m1==2 && y1%4!=0)
                ck=28;
            else if(m1==3)
                ck=31;
            else if(m1==4)
                ck=30;
            else if(m1==5)
                ck=31;
            else if(m1==6)
                ck=30;
            else if(m1==7)
                ck=31;
            else if(m1==8)
                ck=31;
            else if(m1==9)
                ck=30;
            else if(m1==10)
                ck=31;
            else if(m1==11)
                ck=30;
            else if(m1==12)
                ck=31;
            d2=d1+ck-14;
            m2=m1;
            y2=y1;
        }
            /* Till here we have the date before 14 days from today and we will
            compare that date with the date of arrival of Everyone living right now*/
        for(int i=0;i<323;i++){
        if(room[i].status==1 && room[i].data.day==d2 && room[i].data.month==m2 && room[i].data.year==y2)
            room[i].status=0;}/* If we found a date matching with it then We will mark the status of Room as 0(empty)*/
        cout<<endl;
        cout << "Enter the number corresponding to the choice above- " << endl;
        cout << "Enter 0 to stop." << endl;
        cin>>choice;/* After performing the above task, it will ask again What to do next*/
    }
    else if(choice==4){/* If 4 is selected then this piece of code will be executed */
        cout<<"Occupied Rooms-"<<endl;
        for(int i=0;i<323;i++){
        if(room[i].status==1)
            cout<<89+i<<" | ";  /* It will print the room numbers with status=1 */
            }
        cout<<endl;
        cout << "Enter the number corresponding to the choice above- " << endl;
        cout << "Enter 0 to stop." << endl;
        cin>>choice;/* After performing the above task, it will ask again What to do next*/
    }
    else if(choice==3){/* If 3 is selected then this piece of code will be executed */
        cout<<"Vacant Rooms-"<<endl;
        for(int i=0;i<323;i++){
            if(room[i].status==0)
            cout<<89+i<<" | ";  /* It will print the room numbers with status=0 */
            }
        cout<<endl;
        cout << "Enter the number corresponding to the choice above- " << endl;
        cout << "Enter 0 to stop." << endl;
        cin>>choice;
    }
    else if(choice==5){/* If 5 is selected then this piece of code will be executed */
        cout<<"Room No."<<"  "<<"Name"<<"       "<<"Arrived on"<<endl;
        for(int i=0;i<323;i++){
            if(room[i].status==1){
                cout<<i+89<<"        "<<room[i].data.name<<"        "<<room[i].data.day<<"/"<<room[i].data.month<<"/"<<room[i].data.year<<endl;
            }
        }
        cout<<endl;
        cout << "Enter the number corresponding to the choice above- " << endl;
        cout << "Enter 0 to stop." << endl;
        cin>>choice;/* After performing the above task, it will ask again What to do next*/
    }
    else if(choice==6){/* If 6 is selected then this piece of code will be executed */
        string biglist[323];
        int cnt=0;
        int j=0;
        /* Below we are storing Everyone's name in an array named Biglist*/
        for(int i=0;i<323;i++){
            if(room[i].status==1){
                biglist[j]=room[i].data.name;
                j=j+1;
            }
        }
        string c;
        /* Then we will use Algorithm for Selection sort to Sort Biglist*/
        for(int i=0;i<j-1;i++){
            for(int p=i+1;p<j;p++){
                if(biglist[i]>biglist[p]){
                    c=biglist[i];
                    biglist[i]=biglist[p];
                    biglist[p]=c;
                }

            }
        }
        for(int i=0;i<j;i++){
            cout<<biglist[i]<<endl;
        }
        cout<<endl;
        cout << "Enter the number corresponding to the choice above- " << endl;
        cout << "Enter 0 to stop." << endl;
        cin>>choice;/* After performing the above task, it will ask again What to do next*/
    }
        }}

int intro(){/* The function that appears on executing our program*/
    int choice;
    cout << "---TEZPUR UNIVERSITY QUARANTINE CENTRE---" << endl;
    cout << "1. New Entry" << endl;
    cout << "2. Remove Entry" << endl;
    cout << "3. Vacant Rooms" << endl;
    cout << "4. Occupied Rooms" << endl;
    cout << "5. Record of all the residents" << endl;
    cout << "6. Sorted list of Names presently under quarantined" <<endl;
    cout << "Enter the number corresponding to the choice above- " << endl;
    cout << "Enter 0 to stop." << endl;
    cin>>choice;
    return choice;
}

