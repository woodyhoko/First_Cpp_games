#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<ctype.h>
#include<string>
#include<conio.h>
#include<windows.h>

void shape(int,int);
using namespace std;

bool gameover3=0,fail,endg,rright=0,showtime;
int selected[8],randed[17],backur[17],rbackur[17],backt,timet,aaa,bbb,hard,tem,times;

void mainmg()
{
	system("cls");
	cout<<endl;
cout<<"   __   __  _______  __   __  _______  ______    __   __ \n";
cout<<"  |  |_|  ||       ||  |_|  ||       ||    _ |  |  | |  |\n";
cout<<"  |       ||    ___||       ||   _   ||   | ||  |  |_|  |\n";
cout<<"  |       ||   |___ |       ||  | |  ||   |_||_ |       |\n";
cout<<"  |       ||    ___||       ||  |_|  ||    __  ||_     _|\n";
cout<<"  | ||_|| ||   |___ | ||_|| ||       ||   |  | |  |   |  \n";
cout<<"  |_|   |_||_______||_|   |_||_______||___|  |_|  |___|  \n";
cout<<"            _______  _______  __   __  _______                    \n";
cout<<"           |       ||   _   ||  |_|  ||       |                   \n";
cout<<"           |    ___||  |_|  ||       ||    ___|                   \n";
cout<<"           |   | __ |       ||       ||   |___                    \n";
cout<<"           |   ||  ||       ||       ||    ___|                   \n";
cout<<"           |   |_| ||   _   || ||_|| ||   |___                    \n";
cout<<"           |_______||__| |__||_|   |_||_______|\n\n\n";
cout<<"                press anykey to get started\n\n";
while(1)
{
	if(_getch())
	break;
}
}

void shape(int bbb,int aaa)
{
	if(bbb==1)
	{
	if(aaa==1)
	cout<<"11111111";
	if(aaa==2)
	cout<<"11111111";
	if(aaa==3)
	cout<<"11111111";
	if(aaa==4)
	cout<<"11111111";
	if(aaa==5)
	cout<<"11111111";
	}
	
	if(bbb==2)
	{
	if(aaa==1)
	cout<<"22222222";
	if(aaa==2)
	cout<<"22222222";
	if(aaa==3)
	cout<<"22222222";
	if(aaa==4)
	cout<<"22222222";
	if(aaa==5)
	cout<<"22222222";
	}
	
	if(bbb==3)
	{
	if(aaa==1)
	cout<<"########";
	if(aaa==2)
	cout<<"########";
	if(aaa==3)
	cout<<"########";
	if(aaa==4)
	cout<<"########";
	if(aaa==5)
	cout<<"########";
	}
	
	if(bbb==4)
	{
	if(aaa==1)
	cout<<"@@@@@@@@";
	if(aaa==2)
	cout<<"@@@@@@@@";
	if(aaa==3)
	cout<<"@@@@@@@@";
	if(aaa==4)
	cout<<"@@@@@@@@";
	if(aaa==5)
	cout<<"@@@@@@@@";
	}
	
	if(bbb==5)
	{
	if(aaa==1)
	cout<<"&&&&&&&&";
	if(aaa==2)
	cout<<"&&&&&&&&";
	if(aaa==3)
	cout<<"&&&&&&&&";
	if(aaa==4)
	cout<<"&&&&&&&&";
	if(aaa==5)
	cout<<"&&&&&&&&";
	}
	
	if(bbb==6)
	{
	if(aaa==1)
	cout<<"%%%%%%%%";
	if(aaa==2)
	cout<<"%%%%%%%%";
	if(aaa==3)
	cout<<"%%%%%%%%";
	if(aaa==4)
	cout<<"%%%%%%%%";
	if(aaa==5)
	cout<<"%%%%%%%%";
	}
	
	if(bbb==7)
	{
	if(aaa==1)
	cout<<"$$$$$$$$";
	if(aaa==2)
	cout<<"$$$$$$$$";
	if(aaa==3)
	cout<<"$$$$$$$$";
	if(aaa==4)
	cout<<"$$$$$$$$";
	if(aaa==5)
	cout<<"$$$$$$$$";
	}
	
	if(bbb==8)
	{
	if(aaa==1)
	cout<<"********";
	if(aaa==2)
	cout<<"********";
	if(aaa==3)
	cout<<"********";
	if(aaa==4)
	cout<<"********";
	if(aaa==5)
	cout<<"********";
	}
	
	if(bbb==9)
	{
	if(aaa==1)
	cout<<"^^^^^^^^";
	if(aaa==2)
	cout<<"^^^^^^^^";
	if(aaa==3)
	cout<<"^^^^^^^^";
	if(aaa==4)
	cout<<"^^^^^^^^";
	if(aaa==5)
	cout<<"^^^^^^^^";
	}
	
	if(bbb==10)
	{
	if(aaa==1)
	cout<<"!!!!!!!!";
	if(aaa==2)
	cout<<"!!!!!!!!";
	if(aaa==3)
	cout<<"!!!!!!!!";
	if(aaa==4)
	cout<<"!!!!!!!!";
	if(aaa==5)
	cout<<"!!!!!!!!";
	}
	
	if(bbb==11)
	{
	if(aaa==1)
	cout<<"????????";
	if(aaa==2)
	cout<<"????????";
	if(aaa==3)
	cout<<"????????";
	if(aaa==4)
	cout<<"????????";
	if(aaa==5)
	cout<<"????????";
	}
	
	if(bbb==12)
	{
	if(aaa==1)
	cout<<"~~~~~~~~";
	if(aaa==2)
	cout<<"~~~~~~~~";
	if(aaa==3)
	cout<<"~~~~~~~~";
	if(aaa==4)
	cout<<"~~~~~~~~";
	if(aaa==5)
	cout<<"~~~~~~~~";
	}
	
	if(bbb==13)
	{
	if(aaa==1)
	cout<<"<<<<<<<<";
	if(aaa==2)
	cout<<">>>>>>>>";
	if(aaa==3)
	cout<<"<<<<<<<<";
	if(aaa==4)
	cout<<">>>>>>>>";
	if(aaa==5)
	cout<<"<<<<<<<<";
	}
	
	if(bbb==14)
	{
	if(aaa==1)
	cout<<"++++++++";
	if(aaa==2)
	cout<<"++++++++";
	if(aaa==3)
	cout<<"++++++++";
	if(aaa==4)
	cout<<"++++++++";
	if(aaa==5)
	cout<<"++++++++";
	}
	
	if(bbb==15)
	{
	if(aaa==1)
	cout<<"--------";
	if(aaa==2)
	cout<<"--------";
	if(aaa==3)
	cout<<"--------";
	if(aaa==4)
	cout<<"--------";
	if(aaa==5)
	cout<<"--------";
	}
	
	if(bbb==16)
	{
	if(aaa==1)
	cout<<"========";
	if(aaa==2)
	cout<<"========";
	if(aaa==3)
	cout<<"========";
	if(aaa==4)
	cout<<"========";
	if(aaa==5)
	cout<<"========";
	}
	
	if(bbb==17)
	{
	if(aaa==1)
	cout<<"        ";
	if(aaa==2)
	cout<<"        ";
	if(aaa==3)
	cout<<"        ";
	if(aaa==4)
	cout<<"        ";
	if(aaa==5)
	cout<<"        ";
	}
}

void print1()
{
	system("cls");
	int n=1,m=1;
	cout<<endl;
	cout<<"  1           2           3           4           \n";
	cout<<"  +--------++--------++--------++--------+\n";
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=1;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=1;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=1;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=1;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=5;m=1;
	cout<<"  +--------++--------++--------++--------+\n\n";
	cout<<"  5           6           7           8           \n";
	cout<<"  +--------++--------++--------++--------+\n";
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=5;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=5;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=5;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=5;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=9;m=1;
	cout<<"  +--------++--------++--------++--------+\n\n";
	cout<<"  9           10          11          12          \n";
	cout<<"  +--------++--------++--------++--------+\n";
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=9;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=9;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=9;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=9;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=13;m=1;
	cout<<"  +--------++--------++--------++--------+\n\n";
	cout<<"  13          14          15          16          \n";
	cout<<"  +--------++--------++--------++--------+\n";
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=13;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=13;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=13;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";n=13;
	cout<<"  |";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m);cout<<"||";shape(n++,m++);cout<<"|\n";
	cout<<"  +--------++--------++--------++--------+\n";
}

void pick()
{
	int randm,reading;
	times=0;
	showtime=1;
	srand(time(0));
	cout<<"Please select difficulty(Hard(1), Normal(2), Easy(3)):";
	cin>>reading;
	timet=reading*5;
	hard=reading;
	cout<<"Which 8 patterns do you want to pick?";
	for(int k=0;k++<8;)
	{
		cin>>selected[k];
		if(selected[k]>16||selected[k]<1)
		{
			cout<<"Please don't enter nonsense!\n";
			k--;
		}
		for(int n=0;n++<k-1;)
		{
			if(selected[n]==selected[k])
			{
				cout<<"Don't repeat the pattern, please re-enter:\n";
				k--;
			}
		}
	}
	for(int k=0;k++<8;)
	{
		for(int t=0;t++<2;)
		{
			while(1)
			{
				randm=rand()%16+1;
				if(randed[randm]==0)
				{
					randed[randm]=rbackur[randm]=selected[k];
					break;
				}
			}	
		}
	}
//	for(int c=0;c++<16;)
//	backur[n]=0;
}

void realprinting()
{
	system("cls");
	int n=1,m=1;
	cout<<endl;
	cout<<"  1           2           3           4           \n";
	cout<<"  +--------++--------++--------++--------+\n";
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=1;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=1;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=1;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=1;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=5;m=1;
	cout<<"  +--------++--------++--------++--------+\n\n";
	cout<<"  5           6           7           8           \n";
	cout<<"  +--------++--------++--------++--------+\n";
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=5;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=5;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=5;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=5;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|";n=9;m=1;if(showtime==1){
	cout<<"Remaining Time"<<timet<<"second";}cout<<endl;
	cout<<"  +--------++--------++--------++--------+\n\n";
	cout<<"  9           10          11          12          \n";
	cout<<"  +--------++--------++--------++--------+\n";
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=9;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=9;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=9;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=9;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=13;m=1;
	cout<<"  +--------++--------++--------++--------+\n\n";
	cout<<"  13          14          15          16          \n";
	cout<<"  +--------++--------++--------++--------+\n";
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=13;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=13;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=13;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";n=13;
	cout<<"  |";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m);cout<<"||";shape(randed[n++],m++);cout<<"|\n";
	cout<<"  +--------++--------++--------++--------+\n";
}

void guess()
{
	aaa=bbb=0;
	fail=0;
	rright=0;
	cout<<"Please enter the ID of the pair of identical cards:";
	cin>>aaa>>bbb;
	times++;
	while(aaa==bbb||aaa>16||aaa<1||bbb>16||bbb<1||randed[aaa]!=17||randed[bbb]!=17)
	{
		cout<<"Don't enter nonsense!";
		cin>>aaa>>bbb;
		times++;
	}
	if(rbackur[aaa]==rbackur[bbb])
	{
		rright=1;
		randed[aaa]=randed[bbb]=rbackur[aaa];
	}
	else
	{

		randed[aaa]=rbackur[aaa];
		randed[bbb]=rbackur[bbb];
		fail=1;
	} 
}

void startg()
{
	for(int gg=0;gg++<16;)
	randed[gg]=17;
	endg=0;
}

void check3()
{
	int checking;
	for(int f=0;f++<16;)
	{
		if(randed[f]==rbackur[f])
		checking++;
	}
	if(checking>15)
	endg=1;
}

int mainpro_flip()
{
	while(!gameover3)
	{
		mainmg();
		int time1;
		int time2;
		char tempe;
		time_t timer;
		print1();
		pick();
		while(timet-->0)
		{
			realprinting();
			Sleep(1000);
		}
		showtime=0;
		startg();
		time1=time(&timer);
		while(!endg)
		{
			realprinting();
			if(rright==1)
			cout<<"Congrat!!";
			Sleep(1000);
			guess();
			tem=hard;
			if(fail==1)
			{
				while(tem-->0)
				{
					realprinting();
					cout<<"Game over, you lose :(";
					Sleep(1000);
				}
				randed[aaa]=randed[bbb]=17;
				fail=0;
			}
			check3();
		}
		time2=time(&timer);
cout<<" _______  _______  __   __  _______  _______  __   __  _______  ______   \n";
cout<<"|       ||   _   ||  |_|  ||       ||       ||  | |  ||       ||    _ |  \n";
cout<<"|    ___||  |_|  ||       ||    ___||   _   ||  |_|  ||    ___||   | ||  \n";
cout<<"|   | __ |       ||       ||   |___ |  | |  ||       ||   |___ |   |_||_ \n";
cout<<"|   ||  ||       ||       ||    ___||  |_|  ||       ||    ___||    __  |\n";
cout<<"|   |_| ||   _   || ||_|| ||   |___ |       | |     | |   |___ |   |  | |\n";
cout<<"|_______||__| |__||_|   |_||_______||_______|  |___|  |_______||___|  |_|\n\n\n";
cout<<"                        You spent"<<time2-time1<<"second\n\n"; 
cout<<"                          TYou flipped"<<times<<"times\n\n";
cout<<"                  press any key to continue\n                           press 0 to leave\n";
cin>>tempe;
		if(tempe=='0')
		break;
	} 
}
