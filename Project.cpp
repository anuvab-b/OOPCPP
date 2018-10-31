#include<iostream>
#include<cstring>
using namespace std;
class MovieTicket
{
	
	//TODO:
	//Add multiple hall shows
	//Add show timings
	//Try adding printed ticket option
	private:
		int i,j;
		string contact[12][30];
		string name[12][30];
		int stat[12][30];
    public:
    	void displayMenu()
    	{
    		cout<<"\t\t\t\t\t\t\tWelcome to CINEPLEX\nToday's show is Newton(U/A)\t\t\t\nTicket Price: INR 120/-\n"<<endl;
    		cout<<"1.Check Availability"<<endl;
    		cout<<"2.Book Tickets"<<endl;
    		cout<<"3.Cancel Tickets"<<endl;
    		cout<<"4.Check Booking"<<endl;
    		cout<<"5.Exit system"<<endl;
    		choice();
		}
		void choice()
		{
			int choice;
	        cin>>choice;
	        switch(choice)
	        {
		        case 1:displayHall();
		        break;
		        case 2:doBooking();
		        break;
		        case 3:cancelBooking();
		        break;
		        case 4:viewBooking();
		        break;
		        case 5:cout<<"SESSION TERMINATED.THANK YOU."<<endl;
		        break;
		        default:cout<<"Incorrect selection of choice. Try again correctly!"<<endl;
		        displayMenu();
            }
		}
    	void createHall()
    	{
    		for(i=0;i<12;i++)
    		{
    			for(j=0;j<30;j++)
    		    stat[i][j]=0;
			}
			stat[2][21]=1;
		}
		void displayHall()
		{
			for(i=0;i<12;i++)
			{
				for(j=0;j<30;j++)
				{
					if(j==0)
					cout<<(char)(64+i)<<" ";
					else if(j==4||j==5||j==25||j==26)
					cout<<"  ";
					else if(i==0)
					{
					if(j<=9)
					cout<<"(0"<<j<<") ";
					else
					cout<<"("<<j<<") ";
				    }
					else if(i!=0)
					{
					if(stat[i][j]==0)
					cout<<"["<<"av"<<"] ";
					else if(stat[i][j]==1)
					cout<<"["<<"XX"<<"] ";
				    }
				}
				cout<<"\n\n";
			}
			cout<<"av-Available seats"<<endl;
			cout<<"XX-Occupied seats"<<endl;
			cout<<"\n\t\t\t\t\t\t\tSCREEN IS HERE"<<endl;
			char ch;
			cout<<endl<<"Do you wish to continue(Y/N)?"<<endl;
			cin>>ch;
			if(ch=='Y')
			displayMenu();
			else
			cout<<"Thanks for visiting Cineplex!See you again soon"<<endl;
		}
		void doBooking()
		{
			string nam,num;
			int i,t;
			int price=120;
			cout<<"Enter no. of tickets to be booked:"<<endl;
			cin>>t;
			if(t>10)
			{
				cout<<"Sorry,you can't book more than 10 seats together.Try again"<<endl;
				doBooking();
			}
			for(i=1;i<=t;i++)
			{
			char row;int col;
			cout<<"Enter Row and Column"<<endl;
			cin>>row>>col;
			while(row>'K'||col>=30)
			{
				cout<<"Enter Valid Seat number:"<<endl;
				cin>>row>>col;
			}
			//cout<<row<<endl<<col<<endl;
			//cout<<(int)(row-64)<<endl;
			//cout<<stat[(int)(row-64)][col]<<endl;
			if(stat[(int)(row-64)][col]==1)
			{
			    cout<<"This seat is already booked.Please select another seat."<<endl;
			    doBooking();
		    }
		    else
		    {
		        cout<<"Enter Name"<<endl;
				cin>>nam;
				name[(int)(row-64)][col]=nam;	
				cout<<"Enter Contact Number"<<endl;
				cin>>num;
				while(num.length()!=10)
				{
				cout<<"Enter valid contact number:"<<endl;
				cin>>num;	
				contact[(int)(row-64)][col]=num;
			    }
			    contact[(int)(row-64)][col]=num;
				stat[(int)(row-64)][col]=1;
				cout<<"Your booked seat is:"<<row<<col<<endl;
			}
		    }
		    cout<<"Amount to be paid is: INR "<<t*price<<endl;
			char ch;
			cout<<endl<<"Do you wish to continue(Y/N)?"<<endl;
			cin>>ch;
			if(ch=='Y')
			displayMenu();
			else
			cout<<"Thanks for visiting Cineplex!See you again soon"<<endl;
		}
		void cancelBooking()
		{
			char row;int col;
			string nam, num;
			cout<<"Enter Name"<<endl;
			cin>>nam;
		    //cin>>name[(int)(row-64)][col];	
		    cout<<"Enter Contact Number"<<endl;
		    cin>>num;
	    	//cin>>contact[(int)(row-64)][col];
	    	cout<<"Enter Row and Column";
			cin>>row>>col;
			int i,j,flag=0;
			for(i=0;i<12;i++)
			{
				for(j=0;j<30;j++)
				{
					if((name[i][j].compare(nam)==0)&&(contact[i][j].compare(num)==0))
					{
						flag++;
						name[i][j]="";
						contact[i][j]="";
						stat[i][j]=0;
						cout<<"\nBooking cancelled successfully"<<endl<<"Your money will be refunded"<<endl;
						break;
					}
				}
			}
			if(flag==0)
			cout<<"There wasn't any match.Please try again by providing correct information."<<endl;
			flag=0;
			//stat[(int)(row-64)][col]=1;
			//if(stat[(int)(row-64)][col]==1)
			//stat[(int)(row-64)][col]=0;
			char ch;
			cout<<endl<<"Do you wish to continue(Y/N)?"<<endl;
			cin>>ch;
			if(ch=='Y')
			displayMenu();
			else
			cout<<"Thanks for visiting Cineplex!See you again soon"<<endl;
		}
		void viewBooking()
		{
			string nam,num;
			cout<<"Enter Name"<<endl;
		    cin>>nam;	
		    cout<<"Enter Contact Number"<<endl;
		    cin>>num;
		    int flag=0;
		    for(i=0;i<12;i++)
		    {
				for(j=0;j<30;j++)
				{
					if((name[i][j].compare(nam)==0)&&(contact[i][j].compare(num)==0))
					{
						flag++;
		                cout<<"Your booked Seat Number is:"<<(char)(i+64)<<j<<endl;
		                break;
		            }
		        }
		    }
		    if(flag==0)
		    cout<<"Incorrect information provided.Try again later"<<endl;
		    flag=0;
		    char ch;
			cout<<endl<<"Do you wish to continue(Y/N)?"<<endl;
			cin>>ch;
			if(ch=='Y')
			displayMenu();
			else
			cout<<"Thanks for visiting Cineplex!See you again soon"<<endl;
		}	
};
int main()
{
	MovieTicket m;
	m.createHall();
	m.displayMenu();
	return 0;
}
