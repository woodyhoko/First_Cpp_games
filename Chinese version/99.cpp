#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<ctype.h>
#include<string>
#include<conio.h>
#include<windows.h>

using namespace std;

bool gameover=0,rota;;
int players,player[4][2][5],order[4],cardused[52],turn,table,lose[4];//player[who][shapeornumber][no.]
int desi=-1,minuscase=0;
string name[4];

void main99()
{
	system("cls");
	cout<<endl;
cout<<"   ______/\\\\\\\\\\\\\\\\\\_________/\\\\\\\\\\\\\\\\\\____        \n";
cout<<"    ____/\\\\\\///////\\\\\\_____/\\\\\\///////\\\\\\__       \n";
cout<<"     ___/\\\\\\______\\//\\\\\\___/\\\\\\______\\//\\\\\\_      \n";
cout<<"      __\\//\\\\\\_____/\\\\\\\\\\__\\//\\\\\\_____/\\\\\\\\\\_     \n";
cout<<"       ___\\///\\\\\\\\\\\\\\\\/\\\\\\___\\///\\\\\\\\\\\\\\\\/\\\\\\_    \n";
cout<<"        _____\\////////\\/\\\\\\_____\\////////\\/\\\\\\_   \n";
cout<<"         ___/\\\\________/\\\\\\____/\\\\________/\\\\\\__  \n";
cout<<"          __\\//\\\\\\\\\\\\\\\\\\\\\\/____\\//\\\\\\\\\\\\\\\\\\\\\\/___ \n";
cout<<"           ___\\///////////_______\\///////////_____\n\n\n";
cout<<"                    press anykey to start\n\n";
while(1)
{
	if(_getch())
	break;
}
}

void askname()
{
	srand(time(0));
	for(int k=-1;k++<3;)
	order[k]=-1;
	players=2;
	do
	{
	if(players<2||players>4)
	cout<<"請輸入2~4個玩家數目\n" ;
	cout<<"玩家數目：";
	cin>>players;
	}while(players<2||players>4);
	cout<<"你的名稱為：";
	cin>>name[0];
	cout<<"玩家一名稱為：";
	cin>>name[1];
	if(players>2)
	{
		cout<<"玩家二名稱為：";
		cin>>name[2]; 
	}
	if(players>3)
	{
		cout<<"玩家三名稱為：";
		cin>>name[3]; 
	}
	order[0]=rand()%players;
	do
	{
		order[1]=rand()%players;
	}while(order[1]==order[0]);
	if(players>2)
	{
		do
		{
			order[2]=rand()%players;
		}while(order[2]==order[1]||order[2]==order[0]);
	}
	if(players>3)
	{
		do
		{
			order[3]=rand()%players;
		}while(order[3]==order[2]||order[3]==order[1]||order[3]==order[0]);
	}
	cout<<"出牌順序："<<name[order[0]]<<"→"<<name[order[1]];
	if(players>2)
	cout<<"→"<<name[order[2]];
	if(players>3)
	cout<<"→"<<name[order[3]];
	cout<<endl;
}

void reset_99()
{
	cout<<"遊戲開始，請發牌！\n";
	turn=table=minuscase=rota=0;
	for(int d=-1;d++<3;)
	lose[4]=0;
	for(int d=-1;d++<51;)
	cardused[d]=0;
//	for(int n=-1;n++<3;)
//	{
//		for(int m=-1;m++<4;)
//		{
//			for(int o=-1;o++<4;)
//			player[n][m][o]=0;
//		}
//	}
	for(int l=-1;l++<3;)
	{
		for(int m=-1;m++<4;)
		{

			{
				for(int s=-1;s++<1;)
				{
					if(s==0)
					player[l][s][m]=rand()%4+1;
					else
					player[l][s][m]=rand()%13+1;
				}
				if(cardused[(player[l][0][m]-1)*13+player[l][1][m]-1]==1)
				m--;
				else
				cardused[(player[l][0][m]-1)*13+player[l][1][m]-1]=1;
			}
		}
	}
}

void showcard()
{
	cout<<name[0]<<"：  ";
	for(int nc=-1;nc++<4;)
	{
	if(player[0][0][nc]!=-1)
	{
		if(player[0][0][nc]==1)
		cout<<"s:";
		if(player[0][0][nc]==2)
		cout<<"h:";
		if(player[0][0][nc]==3)
		cout<<"c:";
		if(player[0][0][nc]==4)
		cout<<"d:";
		if(player[0][1][nc]!=0)
		cout<<player[0][1][nc]<<"  ";
	}
	}
	cout<<endl;
}

void showtable()
{
	cout<<"目前檯面數值為："<<table<<endl<<endl;
}

void taketurn()
{
	int kind=0;
	desi=-1;
	cout<<"出牌者："<<name[order[turn]];
	if(order[turn]==0)
	{
		cout<<"\n輪到你出牌了(第幾張)：";
		cin>>desi;
		desi--;
		cout<<"你出的牌為：  ";
		if(player[0][0][desi]==1)
		cout<<"s:";
		if(player[0][0][desi]==2)
		cout<<"h:";
		if(player[0][0][desi]==3)
		cout<<"c:";
		if(player[0][0][desi]==4)
		cout<<"d:";
		if(player[0][1][desi]!=0)
		cout<<player[0][1][desi]<<endl;
		if(player[0][1][desi]==10||player[0][1][desi]==12)
		{
			cout<<"正還是負？(正請輸入0,負請輸入1)：";
			cin>>minuscase;
		}
		else if(player[0][1][desi]==1)
		{
			cout<<"你要指定誰？(";
			for(int na=0;na++<players-1;)
			cout<<name[na]<<"請輸入"<<na<<"  ";
			cout<<"如果要歸零，請輸入9)：";
			cin>>minuscase;
		}
		else if(player[0][1][desi]==5)
		{
			cout<<"你要指定誰？(";
			for(int na=0;na++<players-1;)
			cout<<name[na]<<"請輸入"<<na<<"  ";
			cout<<")：";
			cin>>minuscase;
		}
		
	}
	else
	{
		cout<<"：  ";
		for(int u=-1;u++<4;)
		{
			if(player[order[turn]][1][u]+table<100&&(player[order[turn]][1][u]>player[order[turn]][1][desi]||desi==-1))
			{desi=u;kind=8;}
			else if(player[order[turn]][1][u]==10&&table+10>95&&table+10<100&&kind<8)
			{desi=u;kind=7;}
			else if(player[order[turn]][1][u]==12&&table+20>95&&table+20<100&&kind<7)
			{desi=u;kind=6;}
			else if(player[order[turn]][1][u]==13&&kind<6)
			{desi=u;kind=5;}
			else if(player[order[turn]][1][u]==10&&table>89&&kind<5)
			{
				desi=u;
				minuscase=1;
				kind=4;
			}
			else if(player[order[turn]][1][u]==12&&table>89&&kind<4)
			{
				desi=u;
				minuscase=1;
				kind=3;
			}
			else if(player[order[turn]][1][u]==1&&kind<3)
			{desi=u;kind=2;minuscase=9;}
			else if(player[order[turn]][1][u]==1&&kind<2)
			{
				desi=u;
				minuscase=rand()%players;
				kind=1;
			}
			else if(kind==0)
			{
				desi=rand()%5;
			}
		}
		if(player[order[turn]][0][desi]==1)
		cout<<"s:";
		if(player[order[turn]][0][desi]==2)
		cout<<"h:";
		if(player[order[turn]][0][desi]==3)
		cout<<"c:";
		if(player[order[turn]][0][desi]==4)
		cout<<"d:";
		cout<<player[order[turn]][1][desi]<<endl;
	}
}

void rule_99()
{
	if(order[turn]==0)
	{
		if(player[0][1][desi]!=10&&player[0][1][desi]!=12&&player[0][1][desi]!=5&&player[0][1][desi]!=1&&player[0][1][desi]!=4&&player[0][1][desi]!=13)
		table+=player[0][1][desi];
		if(player[0][1][desi]==10&&minuscase==0)
		table+=10;
		if(player[0][1][desi]==10&&minuscase==1)
		table-=10;
		if(player[0][1][desi]==12&&minuscase==0)
		table+=20;
		if(player[0][1][desi]==12&&minuscase==1)
		table-=20;
		if(player[0][1][desi]==13)
		table=99;
		if(player[0][1][desi]==11);
		if(player[0][1][desi]==5)
		{
			table+=5;
			turn=minuscase;
		}
		if(player[0][1][desi]==4)
		{
			table+=4;
			rota=1-rota;
		}
		if(player[0][1][desi]==1&&minuscase==9)
		table=0;
		if(player[0][1][desi]==1&&minuscase!=9)
		{
			for(int pk=-1;pk++<4;)
			{
				player[0][0][pk]=player[minuscase-1][0][pk]+player[0][0][pk];
				player[minuscase-1][0][pk]=player[0][0][pk]-player[minuscase-1][0][pk];
				player[0][0][pk]=player[0][0][pk]-player[minuscase-1][0][pk];
				player[0][1][pk]=player[minuscase-1][1][pk]+player[0][1][pk];
				player[minuscase-1][1][pk]=player[0][1][pk]-player[minuscase-1][1][pk];
				player[0][1][pk]=player[0][1][pk]-player[minuscase-1][1][pk];
			}
			player[0][0][desi]=player[minuscase-1][0][desi]+player[0][0][desi];
			player[minuscase-1][0][desi]=player[0][0][desi]-player[minuscase-1][0][desi];
			player[0][0][desi]=player[0][0][desi]-player[minuscase-1][0][desi];
			player[0][1][desi]=player[minuscase-1][1][desi]+player[0][1][desi];
			player[minuscase-1][1][desi]=player[0][1][desi]-player[minuscase-1][1][desi];
			player[0][1][desi]=player[0][1][desi]-player[minuscase-1][1][desi];
			table+=7;
		}
	}
	else
	{
		if(player[order[turn]][1][desi]!=10&&player[order[turn]][1][desi]!=12&&player[order[turn]][1][desi]!=5&&player[order[turn]][1][desi]!=1&&player[order[turn]][1][desi]!=4&&player[order[turn]][1][desi]!=13)
		table+=player[order[turn]][1][desi];
		if(player[order[turn]][1][desi]==10&&minuscase==0)
		table+=10;
		if(player[order[turn]][1][desi]==10&&minuscase==1)
		table-=10;
		if(player[order[turn]][1][desi]==12&&minuscase==0)
		table+=20;
		if(player[order[turn]][1][desi]==12&&minuscase==1)
		table-=20;
		if(player[order[turn]][1][desi]==13)
		table=99;
		if(player[order[turn]][1][desi]==11);
		if(player[order[turn]][1][desi]==5)
		{
			table+=5;
			turn=minuscase;
		}
		if(player[order[turn]][1][desi]==4)
		{
			table+=4;
			rota=1-rota;
		}
		if(player[order[turn]][1][desi]==1&&minuscase==9)
		table=0;
		if(player[order[turn]][1][desi]==1&&minuscase!=9)
		{
			table+=7;
			for(int pk=-1;pk++<4;)
			{
				player[order[turn]][0][pk]=player[minuscase-1][0][pk]+player[order[turn]][0][pk];
				player[minuscase-1][0][pk]=player[order[turn]][0][pk]-player[minuscase-1][0][pk];
				player[order[turn]][0][pk]=player[order[turn]][0][pk]-player[minuscase-1][0][pk];
				player[order[turn]][1][pk]=player[minuscase-1][1][pk]+player[order[turn]][1][pk];
				player[minuscase-1][1][pk]=player[order[turn]][1][pk]-player[minuscase-1][1][pk];
				player[order[turn]][1][pk]=player[order[turn]][1][pk]-player[minuscase-1][1][pk];
			}
			player[order[turn]][0][desi]=player[minuscase-1][0][desi]+player[order[turn]][0][desi];
			player[minuscase-1][0][desi]=player[order[turn]][0][desi]-player[minuscase-1][0][desi];
			player[order[turn]][0][desi]=player[order[turn]][0][desi]-player[minuscase-1][0][desi];
			player[order[turn]][1][desi]=player[minuscase-1][1][desi]+player[order[turn]][1][desi];
			player[minuscase-1][1][desi]=player[order[turn]][1][desi]-player[minuscase-1][1][desi];
			player[order[turn]][1][desi]=player[order[turn]][1][desi]-player[minuscase-1][1][desi];
			table+=7;
		}
	}

}

void getcard()
{
	int time=300,yes=0;
	for(int numcard=desi-1;numcard++<4;)
	{
		player[order[turn]][0][numcard]=player[order[turn]][0][numcard+1];
		player[order[turn]][1][numcard]=player[order[turn]][1][numcard+1];
	}
	player[order[turn]][0][4]=player[order[turn]][1][4]=0;
	if(order[turn]==0)
	cout<<"抽排請按o：";
	while(time>0)
	{
		if(order[turn]!=0)
		yes=1;
		if(_kbhit())
		{
			if(_getch()=='o')
			{
			cout<<"o \n";
			yes=1;
			break;
			}
		}
		if(yes==1)
		break;
		Sleep(10);
		time--;
	}
	if(time<=0)
	cout<<"你太晚了，錯過機會\n";
	if(time>0)
	{
		do
		{
			for(int s=-1;s++<1;)
			{
				if(s==0)
				player[order[turn]][s][4]=rand()%4+1;
				else
				player[order[turn]][s][4]=rand()%13+1;
			}
			if(cardused[(player[order[turn]][0][4]-1)*13+player[order[turn]][1][4]-1]==1)
			yes=1;
			else
			{
				cardused[(player[order[turn]][0][4]-1)*13+player[order[turn]][1][4]-1]=1;
				yes=0;
			}
		}while(yes==1);
		for(int numc=-1;numc++<4;)
		{
			if(player[order[turn]][0][numc]==0&&player[order[turn]][0][numc+1]!=0)
			{
				player[order[turn]][0][numc]=player[order[turn]][0][numc+1];
				player[order[turn]][1][numc]=player[order[turn]][1][numc+1];
			}
		}
	}
}

void check_99()
{
	int loses=0,cardf=0;
	if (table>=100)
	{
		cout<<endl<<name[order[turn]]<<"輸了\n";
		lose[order[turn]]=1;
		table=0;
	}
	for(int ch=-1;ch++<51;)
	{
		if(cardused[ch]==1)
		cardf++;
	}
	if(cardf==52)
	{
		cout<<"開啟另一副牌\n";
		for(int ch=-1;ch++<51;)
		{
			cardused[ch]=0;
		}
	}
	for(int lo=-1;lo++<players-1;)
	loses=lose[lo]+loses;
	if(loses==players-1)
	{
		gameover=1;
		for(int lo=-1;lo++<players-1;)
		{
			if(lose[lo]!=1)
			cout<<name[lo]<<"贏了！";
		}
	}
	if(rota==0)
	{do{
		if(++turn>players-1)
		turn=0;
		}while(lose[turn]==1);
	}
	if(rota==1)
	{do{
		if(--turn<0)
		turn=players-1;
		}while(lose[turn]==1);
	}
}

void mainpro_99()
{	
	char exitse=0;
	while(1)
	{
		main99();
		system("cls");
	askname();
	reset_99();
	while(!gameover)
	{
		showcard();
		Sleep(300);
		showtable();
		Sleep(300);
		taketurn();
		Sleep(300);
		rule_99();
		getcard();
		Sleep(300);
		check_99();
		Sleep(300);
	}
	cout<<"如果要離開請輸入1，不然自動重來";
	cin>>exitse;
	if(exitse=='1')
	break;
	}
}
