#include<iomanip>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<vector>
#include<string>

using namespace std;

void defineRule();
void hole(int);
void turnintomoney(int);
void printGame();
void press();
void resetmm();

int lives = 5;
int money = 0;
string s[9];
int a[9];
int b[9];
int c[9];
int mousetime[9];
int moneytime[9];
int pressMouse;
int timetime=50;

void mainmole()
{
system("cls");
cout<<endl;
cout<<"   __      __.__                   __    \n";
cout<<"  /  \\    /  \\  |__ _____    ____ |  | __\n";
cout<<"  \\   \\/\\/   /  |  \\\\__  \\ _/ ___\\|  |/ /\n";
cout<<"   \\        /|   Y  \\/ __ \\\\  \\___|    < \n";
cout<<"    \\__/\\  / |___|  (____  /\\___  >__|_ \\\n";
cout<<"         \\/       \\/     \\/     \\/     \\/\n";
cout<<"             __  .__                      \n";
cout<<"           _/  |_|  |__   ____            \n";
cout<<"           \\   __\\  |  \\_/ __ \\           \n";
cout<<"            |  | |   Y  \\  ___/           \n";
cout<<"            |__| |___|  /\\___  >          \n";
cout<<"                      \\/     \\/           \n";
cout<<"        _____         .__                   \n";
cout<<"       /     \\   ____ |  |   ____           \n";
cout<<"      /  \\ /  \\ /  _ \\|  | _/ __ \\          \n";
cout<<"     /    Y    (  <_> )  |_\\  ___/          \n";
cout<<"     \\____|__  /\\____/|____/\\___  >         \n";
cout<<"             \\/                 \\/      \n\n\n";
cout<<"          press any key to start";
while(1)
{
	if(_getch())
	break;
}
}

int mainpro_mole()
{
	int out5=1;
	while(1)
	{
		mainmole();
		system("cls");
		defineRule();
		srand(time(0));
		for(int gameTime = 0; gameTime <= 1200; gameTime++)
		{
		press();
		for(int k=-1;k++<8;)
		hole(k);
		printGame();
		Sleep(100);
		system("cls");
		if(money>=10)
		timetime=30;
		if(lives <= 0)
		break;
		}
		cout<<endl;
cout<<"     _____                                          \n";
cout<<"    / ____|                                         \n";
cout<<"   | |  __  __ _ _ __ ___   ___  _____   _____ _ __ \n";
cout<<"   | | |_ |/ _` | '_ ` _ \\ / _ \\/ _ \\ \\ / / _ \\ '__|\n";
cout<<"   | |__| | (_| | | | | | |  __/ (_) \\ V /  __/ |   \n";
cout<<"    \\_____|\\__,_|_| |_| |_|\\___|\\___/ \\_/ \\___|_| \n\n\n";
cout <<"                    your money is: "<<money<<endl<<endl;
cout<<"         if you want to get back to main menu\n                       enter 0\n";
		cin>>out5;
		if(out5==0)
		break;
		resetmm();
	}
}

void resetmm()
{
	lives = 5;
	money = 0;
	for(int xxx=-1;xxx++<8;)
	s[xxx]="  ";
	for(int yyy=-1;yyy++<8;){
	a[yyy]=0;
	b[yyy]=0;
	c[yyy]=0;
	mousetime[yyy]=0;
	moneytime[yyy]=0;}
	timetime=50;
}

void defineRule()
{
	int startGame;
	cout<<endl;
	cout << "   HP : ¡¹¡¹¡¹¡¹¡¹" << endl;
	cout << "   ¢C : 000" << endl<<endl;
	cout << "  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i" << endl;
	cout << "  ¢i      ¢i      ¢i      ¢i" << endl;
	cout << "  ¢i  ¢ß  ¢i  ¢å  ¢i  ¢Ó  ¢i" << endl;
	cout << "  ¢i      ¢i      ¢i      ¢i" << endl;
	cout << "  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i" << endl;
	cout << "  ¢i      ¢i      ¢i      ¢i" << endl;
	cout << "  ¢i  ¢Ï  ¢i  ¢á  ¢i  ¢Ò  ¢i" << endl;
	cout << "  ¢i      ¢i      ¢i      ¢i" << endl;
	cout << "  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i" << endl;
	cout << "  ¢i      ¢i      ¢i      ¢i" << endl;
	cout << "  ¢i  ¢è  ¢i  ¢æ  ¢i  ¢Ñ  ¢i" << endl;
	cout << "  ¢i      ¢i      ¢i      ¢i" << endl;
	cout << "  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i" << endl;
	cout << endl;
	cout << "      Press 0 to start." << endl;
	for(;;)
	{
		startGame = _getch();
		if(startGame == '0')
		{
			break;
		}
	}
	system("cls");
}

void hole(int n)
{
	int miss=1;
	int r;
	if(s[n]=="¢C")
	{
		if(moneytime[n]++>=timetime)
		{
			s[n]="  ";
			moneytime[n]=0;
		}
	}
	else if(b[n]==1)
	{
		b[n]=0;
		do{
		r=rand()%9;
		for(int i=-1;i++<8;)
		{
			if(r==i&&a[i]==0&&s[i]!="¢C"&&s[i]!="¢I")
			{
				s[i]="¢C";
				miss=0;
			}
		}}while(miss!=0);
	}
	else if(a[n]==1&&s[n]!="¢C"&&s[n]!="¢I")
	{
		s[n]="¹«";
		if(mousetime[n]++>=timetime)
		{
			a[n]=0;
			mousetime[n]=0;
			lives--;
		}
	}
	else if(c[n]>0&&s[n]!="¢C"&&s[n]!="¹«")
	{
		s[n]="¢I";
		if(mousetime[n]++>=timetime)
		{
			mousetime[n]=0;
			lives--;
		}
	}
	else
	{
		r=rand()%150;
		s[n]="  ";
		if(r==0||r==1||r==2)
		a[n]=1;
		if(r==3)
		c[n]=2;
	}
}

void printGame()
{
	cout<<endl;
	cout << " HP : ";
	for(int i = 1; i <= lives; i++)
	cout << "¡¹";
	cout << endl;
	cout << " ¢C : ";
	cout << money;
	cout << endl<<endl;
	cout << "  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i" << endl;
	cout << "  ¢i      ¢i      ¢i      ¢i" << endl;
	cout << "  ¢i  " << s[6] << "  ¢i  " << s[7] << "  ¢i  " << s[8] << "  ¢i" << endl;
	cout << "  ¢i      ¢i      ¢i      ¢i" << endl;
	cout << "  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i" << endl;
	cout << "  ¢i      ¢i      ¢i      ¢i" << endl;
	cout << "  ¢i  " << s[3] << "  ¢i  " << s[4] << "  ¢i  " << s[5] << "  ¢i" << endl;
	cout << "  ¢i      ¢i      ¢i      ¢i" << endl;
	cout << "  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i" << endl;
	cout << "  ¢i      ¢i      ¢i      ¢i" << endl;
	cout << "  ¢i  " << s[0] << "  ¢i  " << s[1] << "  ¢i  " << s[2] << "  ¢i" << endl;
	cout << "  ¢i      ¢i      ¢i      ¢i" << endl;
	cout << "  ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i" << endl;
}

void turnintomoney(int p)
{
	if(a[p]==1)
	{
		a[p]=0;
		b[p]=1;
		mousetime[p]=0;
	}
	if(s[p]=="¢C")
	{
		s[p]="  ";
		money++;
		moneytime[p]=0;
	}
	else if(c[p]>0)
	{
		c[p]--;
		if(c[p]==0)
		{
			b[p]=1;
			s[p]="  ";
			mousetime[p]=0;
		}
	}
	else if(s[p]=="  ")
	lives--;
}

void press()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'z':
			case '1':
				turnintomoney(0);
				break;
			case 'x':
			case '2':
				turnintomoney(1);
				break;
			case 'c':
			case '3':
				turnintomoney(2);
				break;
			case 'a':
			case '4':
				turnintomoney(3);
				break;
			case 's':
			case '5':
				turnintomoney(4);
				break;
			case 'd':
			case '6':
				turnintomoney(5);
				break;
			case 'q':
			case '7':
				turnintomoney(6);
				break;
			case 'w':
			case '8':
				turnintomoney(7);
				break;
			case 'e':
			case '9':
				turnintomoney(8);
				break;
		}
	}
}
