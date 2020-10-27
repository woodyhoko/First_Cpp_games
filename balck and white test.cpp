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

bool gameover4,leave,backtomain,backtomainmenu=0;
string board[10][10],backup[10][10];
int pointer[2],bla=1,pla;
int xbb=pointer[0],ybb=pointer[1],testx,testy,countb,countw,first,chcb[2],blackscore,whitescore,win,mode,comskip=0;
int aix[64],aiy[64],ais[64];

void reset()
{
	gameover4=0;
	pointer[0]=pointer[1]=first=1;
	for(int n=-1;n++<9;)
	board[0][n]=board[n][0]=board[9][n]=board[n][9]="X";
	for(int a=0;a++<8;)
	{
		for(int b=0;b++<8;)
		{
			board[b][a]="□";
		}
	}
	board[4][4]=board[5][5]="●";
	board[4][5]=board[5][4]="○";
}

void draw()
{
	system("cls");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	for(int a=0;a++<8;)
	{
		cout<<"                        ";
		for(int b=0;b++<8;)
		{
			if(b==pointer[0]&&a==pointer[1])
			cout<<"╳";
			else
			cout<<board[b][a];
		}
		if(a==4)
		cout<<"      黑棋有 "<<blackscore<<" 顆";
		if(a==6)
		cout<<"      白棋有 "<<whitescore<<" 顆";
		cout<<endl;
	}
		cout<<"\n  ";
		if(first==1&&bla==1)
		cout<<"                        黑棋先開始";
		else if(first==1&&bla==0)
		cout<<"                        白棋先開始";
		else if(bla==1)
		cout<<"                        換黑棋下";
		else
		cout<<"                        換白棋下"; 
}

void control()
{
	pla=0;
		switch(_getch())
		{
			case 'w':
				if(pointer[1]>1)
				pointer[1]--;
				break;
			case 's':
				if(pointer[1]<8)
				pointer[1]++;
				break;
			case 'a':
				if(pointer[0]>1)
				pointer[0]--;
				break;
			case 'd':
				if(pointer[0]<8)
				pointer[0]++;
				break;
			case ' ':
				if(first==1)
				first=0;
				if(bla==1&&board[pointer[0]][pointer[1]]=="□")
				{
					board[pointer[0]][pointer[1]]="○";
					bla=0;
					pla=1;
				}
				else if(board[pointer[0]][pointer[1]]=="□")
				{
					board[pointer[0]][pointer[1]]="●";
					bla=1;
					pla=1;
				}
				else
				control();
				break;
			case 'p':
				leave=1;
				break;
			case 'b':
				leave=1;
				backtomain=1;
				break;
			case 'e':
				leave=1;
				backtomain=1;
				backtomainmenu=1;
				break;
			case 'h':
				mode=1;
				break;
			case 'c':
				mode=2;
				break;
		}
}

void check()
{
	xbb=pointer[0];
	ybb=pointer[1];
	if(bla==0)
	{
	countb=0;
	testx=xbb;
	while(1)
	{
		testx++;
		if(board[testx][pointer[1]]=="●")
		{
			board[testx][pointer[1]]="○";
			countb++;
		}
		else if(board[testx][pointer[1]]=="○")
		break;
		if(board[testx][pointer[1]]=="□"||board[testx][pointer[1]]=="X")
		{
			for(int k=xbb;k++<testx-1;)
			{
				board[k][pointer[1]]="●";
				countb--;
			}
			break;
		}
	}
	testx=xbb;
	while(1)
	{
		testx--;
		if(board[testx][pointer[1]]=="●")
		{
			board[testx][pointer[1]]="○";
			countb++;
		}
		else if(board[testx][pointer[1]]=="○")
		break;
		if(board[testx][pointer[1]]=="□"||board[testx][pointer[1]]=="X")
		{
			for(int k=xbb;k-->testx+1;)
			{
				board[k][pointer[1]]="●";
				countb--;
			}
			break;
		}
	}
	testy=ybb;
	while(1)
	{
		testy++;
		if(board[pointer[0]][testy]=="●")
		{
			board[pointer[0]][testy]="○";
			countb++;
		}
		else if(board[pointer[0]][testy]=="○")
		break;
		if(board[pointer[0]][testy]=="□"||board[pointer[0]][testy]=="X")
		{
			for(int k=ybb;k++<testy-1;)
			{
				board[pointer[0]][k]="●";
				countb--;
			}
			break;
		}
	}
	testy=ybb;
	while(1)
	{
		testy--;
		if(board[pointer[0]][testy]=="●")
		{
			board[pointer[0]][testy]="○";
			countb++;
		}
		else if(board[pointer[0]][testy]=="○")
		break;
		if(board[pointer[0]][testy]=="□"||board[pointer[0]][testy]=="X")
		{
			for(int k=ybb;k-->testy+1;)
			{
				board[pointer[0]][k]="●";
				countb--;
			}
			break;
		}
	}
	testx=xbb;
	testy=ybb;
	while(1)
	{
		testx++;
		testy++;
		if(board[testx][testy]=="●")
		{
			board[testx][testy]="○";
			countb++;
		}
		else if(board[testx][testy]=="○")
		break;
		if(board[testx][testy]=="□"||board[testx][testy]=="X")
		{
			for(int k=ybb+1,m=xbb+1;k<=testy-1;k++,m++)
			{
					board[m][k]="●";
					countb--;
			}
			break;
		}
	}
	testx=xbb;
	testy=ybb;
	while(1)
	{
		testx++;
		testy--;
		if(board[testx][testy]=="●")
		{
			board[testx][testy]="○";
			countb++;
		}
		else if(board[testx][testy]=="○")
		break;
		if(board[testx][testy]=="□"||board[testx][testy]=="X")
		{
			for(int k=ybb-1,m=xbb+1;k>=testy+1;k--,m++)
			{
					board[m][k]="●";
					countb--;
			}
			break;
		}
	}
	testx=xbb;
	testy=ybb;
	while(1)
	{
		testx--;
		testy++;
		if(board[testx][testy]=="●")
		{
			board[testx][testy]="○";
			countb++;
		}
		else if(board[testx][testy]=="○")
		break;
		if(board[testx][testy]=="□"||board[testx][testy]=="X")
		{
			for(int k=ybb+1,m=xbb-1;k<=testy-1;k++,m--)
			{
					board[m][k]="●";
					countb--;
			}
			break;
		}
	}
	testx=xbb;
	testy=ybb;
	while(1)
	{
		testx--;
		testy--;
		if(board[testx][testy]=="●")
		{
			board[testx][testy]="○";
			countb++;
		}
		else if(board[testx][testy]=="○")
		break;
		if(board[testx][testy]=="□"||board[testx][testy]=="X")
		{
			for(int k=ybb-1,m=xbb-1;k>=testy+1;k--,m--)
			{
					board[m][k]="●";
					countb--;
			}
			break;
		}
	}
	if(countb==0)
	{
		bla=1;
		board[xbb][ybb]="□";
	}
	}
	else if(bla==1)
	{
	countw=0;
	testx=xbb;
	while(1)
	{
		testx++;
		if(board[testx][pointer[1]]=="○")
		{
			board[testx][pointer[1]]="●";
			countw++;
		}
		else if(board[testx][pointer[1]]=="●")
		break;
		if(board[testx][pointer[1]]=="□"||board[testx][pointer[1]]=="X")
		{
			for(int k=xbb;k++<testx-1;)
			{
				board[k][pointer[1]]="○";
				countw--;
			}
			break;
		}
	}
	testx=xbb;
	while(1)
	{
		testx--;
		if(board[testx][pointer[1]]=="○")
		{
			board[testx][pointer[1]]="●";
			countw++;
		}
		else if(board[testx][pointer[1]]=="●")
		break;
		if(board[testx][pointer[1]]=="□"||board[testx][pointer[1]]=="X")
		{
			for(int k=xbb;k-->testx+1;)
			{
				board[k][pointer[1]]="○";
				countw--;
			}
			break;
		}
	}
	testy=ybb;
	while(1)
	{
		testy++;
		if(board[pointer[0]][testy]=="○")
		{
			board[pointer[0]][testy]="●";
			countw++;
		}
		else if(board[pointer[0]][testy]=="●")
		break;
		if(board[pointer[0]][testy]=="□"||board[pointer[0]][testy]=="X")
		{                
			for(int k=ybb;k++<testy-1;)
			{
				board[pointer[0]][k]="○";
				countw--;
			}
			break;
		}
	}
	testy=ybb;
	while(1)
	{
		testy--;
		if(board[pointer[0]][testy]=="○")
		{
			board[pointer[0]][testy]="●";
			countw++;
		}
		else if(board[pointer[0]][testy]=="●")
		break;
		if(board[pointer[0]][testy]=="□"||board[pointer[0]][testy]=="X")
		{
			for(int k=ybb;k-->testy+1;)
			{
				board[pointer[0]][k]="○";
				countw--;
			}
			break;
		}
	}
	testx=xbb;
	testy=ybb;
	while(1)
	{
		testx++;
		testy++;
		if(board[testx][testy]=="○")
		{
			board[testx][testy]="●";
			countw++;
		}
		else if(board[testx][testy]=="●")
		break;
		if(board[testx][testy]=="□"||board[testx][testy]=="X")
		{
			for(int k=ybb+1,m=xbb+1;k<=testy-1;k++,m++)
			{
					board[m][k]="○";
					countw--;
			}
			break;
		}
	}
	testx=xbb;
	testy=ybb;
	while(1)
	{
		testx++;
		testy--;
		if(board[testx][testy]=="○")
		{
			board[testx][testy]="●";
			countw++;
		}
		else if(board[testx][testy]=="●")
		break;
		if(board[testx][testy]=="□"||board[testx][testy]=="X")
		{
			for(int k=ybb-1,m=xbb+1;k>=testy+1;k--,m++)
			{
					board[m][k]="○";
					countw--;
			}
			break;
		}
	}
	testx=xbb;
	testy=ybb;
	while(1)
	{
		testx--;
		testy++;
		if(board[testx][testy]=="○")
		{
			board[testx][testy]="●";
			countw++;
		}
		else if(board[testx][testy]=="●")
		break;
		if(board[testx][testy]=="□"||board[testx][testy]=="X")
		{
			for(int k=ybb+1,m=xbb-1;k<=testy-1;k++,m--)
			{
					board[m][k]="○";
					countw--;
			}
			break;
		}
	}
	testx=xbb;
	testy=ybb;
	while(1)
	{
		testx--;
		testy--;
		if(board[testx][testy]=="○")
		{
			board[testx][testy]="●";
			countw++;
		}
		else if(board[testx][testy]=="●")
		break;
		if(board[testx][testy]=="□"||board[testx][testy]=="X")
		{
			for(int k=ybb-1,m=xbb-1;k>=testy+1;k--,m--)
			{
					board[m][k]="○";
					countw--;
			}
			break;
		}
	}
	if(countw==0)
	{
		bla=0;
		board[xbb][ybb]="□";
	}
	}
}

void turncheck()
{
	bla=1-bla;
	int skip=1;
	countb=countw=0;
	for(int a=-1;a++<9;)
	{
		for(int b=-1;b++<9;)
		backup[b][a]=board[b][a];
	}
	chcb[0]=pointer[0];
	chcb[1]=pointer[1];
	for(int a=0;a++<8;)
	{
		for(int b=0;b++<8;)
		{
			pointer[0]=b;
			pointer[1]=a;
			if(board[b][a]=="□")
			{
				if(bla==1)
				board[b][a]="●";
				if(bla==0)
				board[b][a]="○";
				check();
				if(board[b][a]!="□")
				skip=0;
				else
				bla=1-bla;
				for(int c=-1;c++<9;)
				{
					for(int d=-1;d++<9;)
					board[d][c]=backup[d][c];
				}
			}
		}
	}
	if(skip==1)
	bla=1-bla;
	for(int a=-1;a++<9;)
	{
		for(int b=-1;b++<9;)
		board[b][a]=backup[b][a];
	}
	pointer[0]=chcb[0];
	pointer[1]=chcb[1];
	bla=1-bla;
}

void score()
{
	blackscore=whitescore=0;
	for(int a=0;a++<8;)
	{
		for(int b=0;b++<8;)
		{
			if(board[b][a]=="●")
			whitescore++;
			if(board[b][a]=="○")
			blackscore++;
		}
	}
	if(whitescore==0||blackscore==0||(whitescore+blackscore==64))
	{
		gameover4=1;
		if(whitescore>blackscore)
		win=0;
		if(blackscore>whitescore)
		win=1;
		if(whitescore==blackscore)
		win=2;
	}
}

void rule()
{
	if(pla==1)
	{ 
		check();
		turncheck();
	}
}

void replay()
{
system("cls");
cout<<endl;
cout<<"   _____                                          \n";
cout<<"  |  __ \\                                         \n";
cout<<"  | |  \\/ __ _ _ __ ___   ___  _____   _____ _ __ \n";
cout<<"  | | __ / _` | '_ ` _ \\ / _ \\/ _ \\ \\ / / _ \\ '__|\n";
cout<<"  | |_\\ \\ (_| | | | | | |  __/ (_) \\ V /  __/ |   \n";
cout<<"   \\____/\\__,_|_| |_| |_|\\___|\\___/ \\_/ \\___|_|   \n\n\n";
if(win==0)
cout<<"                white won\n\n";
if(win==1)
cout<<"                black won\n\n";
if(win==2)
cout<<"                It's a tie\n\n";
cout<<"                Play again? (press p)\n\n";
cout<<"                Back to menu?(press b)\n\n";
cout<<"                Exit?(press e)";
control();
}

void menu()
{
system("cls");
cout<<endl;
cout<<"  ______ _            _          _    _ _     _ _       \n";
cout<<"  | ___ | |          | |   ___  | |  | | |   (_| |      \n";
cout<<"  | |_/ | | __ _  ___| | _( _ ) | |  | | |__  _| |_ ___ \n";
cout<<"  | ___ | |/ _` |/ __| |/ / _ \\/| |/\\| | '_ \\| | __/ _ \\ "<<endl;
cout<<"  | |_/ | | (_| | (__|   | (_>  \\  /\\  | | | | | ||  __/\n";
cout<<"  \\____/|_|\\__,_|\\___|_|\\_\\___/\\/\\/  \\/|_| |_|_|\\__\\___|\n";
cout<<endl<<endl<<endl;
cout<<"                Human vs Human (press h)\n\n";
cout<<"                Human vs Computer (press c)\n                computer is using color white\n\n";
cout<<"                Exit? (press e)";
control();
}

void compu()
{
	int num=0;
	bla=1;
	countw=0;
	for(int cl=-1;cl++<63;)
	ais[cl]=aix[cl]=aiy[cl]=0;
	for(int a=-1;a++<9;)
	{
		for(int b=-1;b++<9;)
		backup[b][a]=board[b][a];
	}
	chcb[0]=pointer[0];
	chcb[1]=pointer[1];
	for(int k=1;k<9;k+=2)
	{
		if(k==5)
		k++;
		for(int m=1;m<9;m+=2)
		{
			if(m==5)
			m++;
			pointer[0]=m;
			pointer[1]=k;
			if(board[m][k]=="□")
			{
				board[m][k]="●";
				check();
				if(board[m][k]=="□")
				bla=1-bla;
				ais[num]=countw;
				aix[num]=m;
				aiy[num]=k;
				for(int c=-1;c++<9;)
				{
					for(int d=-1;d++<9;)
					board[d][c]=backup[d][c];
				}
			}
			num++;
		}
	}
	for(int k=3;k++<5;)
	{
		for(int m=0;m++<8;)
		{
			pointer[0]=m;
			pointer[1]=k;
			if(board[m][k]=="□")
			{
				board[m][k]="●";
				check();
				if(board[m][k]=="□")
				bla=1-bla;
				ais[num]=countw;
				aix[num]=m;
				aiy[num]=k;
				for(int c=-1;c++<9;)
				{
					for(int d=-1;d++<9;)
					board[d][c]=backup[d][c];
				}
			}
			num++;
		}
	}
	for(int k=0;k++<8;)
	{
		for(int m=3;m++<5;)
		{
			if(k!=4&&k!=5)
			{
			pointer[0]=m;
			pointer[1]=k;
			if(board[m][k]=="□")
			{
				board[m][k]="●";
				check();
				if(board[m][k]=="□")
				bla=1-bla;
				ais[num]=countw;
				aix[num]=m;
				aiy[num]=k;
				for(int c=-1;c++<9;)
				{
					for(int d=-1;d++<9;)
					board[d][c]=backup[d][c];
				}
			}
			num++;
			}
		}
	}
	for(int k=2;k<8;k+=5)
	{
		for(int m=0;m++<8;)
		{
			if(m!=4&&m!=5)
			{
			pointer[0]=m;
			pointer[1]=k;
			if(board[m][k]=="□")
			{
				board[m][k]="●";
				check();
				if(board[m][k]=="□")
				bla=1-bla;
				ais[num]=countw;
				aix[num]=m;
				aiy[num]=k;
				for(int c=-1;c++<9;)
				{
					for(int d=-1;d++<9;)
					board[d][c]=backup[d][c];
				}
			}
			num++;
			}
		}
	}
	for(int k=0;k++<8;)
	{
		for(int m=2;m<8;m+=5)
		{
			if(k!=4&&k!=5&&k!=2&&k!=7)
			{
			pointer[0]=m;
			pointer[1]=k;
			if(board[m][k]=="□")
			{
				board[m][k]="●";
				check();
				if(board[m][k]=="□")
				bla=1-bla;
				ais[num]=countw;
				aix[num]=m;
				aiy[num]=k;
				for(int c=-1;c++<9;)
				{
					for(int d=-1;d++<9;)
					board[d][c]=backup[d][c];
				}
			}
			num++;
			}
		}
	}
	for(int a=-1;a++<9;)
	{
		for(int b=-1;b++<9;)
		board[b][a]=backup[b][a];
	}
	pointer[0]=chcb[0];
	pointer[1]=chcb[1];
}

void sorting()
{
	int desi[3]={0,0,0},clas=1,ran;
	srand(time(0));
	for(int n=-1;n++<15;)
	{
		ran=rand()%3;
		if(ais[n]>desi[0])
		{
			desi[0]=ais[n];
			desi[1]=aix[n];
			desi[2]=aiy[n];
			clas=1;
		}
		else if(ais[n]==desi[0]&&ran!=2&&clas==1)
		{
			desi[0]=ais[n];
			desi[1]=aix[n];
			desi[2]=aiy[n];
		}
	}
	if(desi[0]==0)
	{
		for(int n=15;n++<43;)
		{
			ran=rand()%3;
			if(ais[n]>desi[0])
			{
				desi[0]=ais[n];
				desi[1]=aix[n];
				desi[2]=aiy[n];
				clas=2;
			}
			else if(ais[n]==desi[0]&&ran!=2&&clas==2)
			{
				desi[0]=ais[n];
				desi[1]=aix[n];
				desi[2]=aiy[n];
			}
		}
	}
	if(desi[0]==0)
	{
		for(int n=43;n++<63;)
		{
			ran=rand()%3;
			if(ais[n]>desi[0])
			{
				desi[0]=ais[n];
				desi[1]=aix[n];
				desi[2]=aiy[n];
				clas=3;
			}
			else if(ais[n]==desi[0]&&ran!=2&&clas==3)
			{
				desi[0]=ais[n];
				desi[1]=aix[n];
				desi[2]=aiy[n];
			}
		}
	}
	if(desi[0]==0)
	{
		bla=1;
		comskip=1;
	}
	else
	{
	pointer[0]=desi[1];
	pointer[1]=desi[2];
	pla=1;
	bla=1;
	board[pointer[0]][pointer[1]]="●";
	}
}

int mainpro_bnw()
{
	while(1)
	{
	menu();
	if(backtomainmenu==1)
	break;
	while(mode==1)
	{
		reset();
		while(!gameover4)
		{
			rule();
			score();
			draw();
			control();
		}
		do
		{
			leave=0;
			replay();
		}while(leave==0);
		if(backtomain==1)
		break;
	}
	while(mode==2)
	{
		reset();
		while(!gameover4)
		{
			if(comskip==0)
			{
			rule();
			score();
			}
			draw();
			if(bla==1)
			control();
			else if(bla==0)
			{
				comskip=0;
				compu();
				sorting();
				Sleep(1000);
			}
		}
		do
		{
			leave=0;
			replay();
		}while(leave==0);
		if(backtomain==1)
		break;
	}
	if(backtomainmenu==1)
	break;
	}
}

