#include<iomanip>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<fstream>
using namespace std;

bool gameover2=0,print,check1,pause,retryn=0,leveln=0,mainm=1,out3=0;
int width=41,height=20,x,y,pointx,pointy,point,bodyx[400],bodyy[400],body,timesp,add,countpoint,
	manupoint=1,gamestart=0,retry=0,quitgame=0,level=0,wallx[6],wally[6],ewallx,bonusx,bonusy,bonustime,
	scoree[100],type[100],sta,score1[11],score2[11],score3[11],sco,back,co1,co2,co3;
string namee[100],name1[100],name2[100],name3[100];
enum direction{Stop,Up,Down,Left,Right};
ofstream storefile;
ifstream readfile;
direction dir;
string namess;

void mainsnake()
{
	system("cls");
cout<<"             ___________  __    __    _______                  \n";
cout<<"            (\"     _   \")/\" |  | \"\\  /\"     \"|                 \n";
cout<<"             )__/  \\\\__/(:  (__)  :)(: ______)                 \n";
cout<<"                \\\\_ /    \\/      \\/  \\/    |                   \n";
cout<<"                |.  |    //  __  \\\\  // ___)_                  \n";
cout<<"                \\:  |   (:  (  )  :)(:      \"|                 \n";
cout<<"                 \\__|    \\__|  |__/  \\_______)                 \n";
cout<<"                                                               \n";
cout<<"  _______    _______    _______   _______  ________  ___  ___  \n";
cout<<" /\" _   \"|  /\"      \\  /\"     \"| /\"     \"||\"      \"\\|\"  \\/\"  | \n";
cout<<"(: ( \\___) |:        |(: ______)(: ______)(.  ___  :)\\   \\  /  \n";
cout<<" \\/ \\      |_____/   ) \\/    |   \\/    |  |: \\   ) || \\\\  \\/   \n";
cout<<" //  \\ ___  //      /  // ___)_  // ___)_ (| (___\\ || /   /    \n";
cout<<"(:   _(  _||:  __   \\ (:      \"|(:      \"||:       :)/   /     \n";
cout<<" \\_______) |__|  \\___) \\_______) \\_______)(________/|___/      \n";
cout<<"                                                               \n";
cout<<"    ________  _____  ___        __       __   ___  _______       \n";
cout<<"   /\"       )(\\\"   \\|\"  \\      /\"\"\\     |/\"| /  \")/\"     \"|      \n";
cout<<"  (:   \\___/ |.\\\\   \\    |    /    \\    (: |/   /(: ______)      \n";
cout<<"   \\___  \\   |: \\.   \\\\  |   /' /\\  \\   |    __/  \\/    |        \n";
cout<<"    __/  \\\\  |.  \\    \\. |  //  __'  \\  (// _  \\  // ___)_       \n";
cout<<"   /\" \\   :) |    \\    \\ | /   /  \\\\  \\ |: | \\  \\(:      \"|      \n";
cout<<"  (_______/   \\___|\\____\\)(___/    \\___)(__|  \\__)\\_______)      \n";
cout<<"                       press anykey to start ";
while(1)
{
	if(_getch())
	break;
}
}

void mainmenu()
{

do
{
	    	if(out3==1)
		break;
    system("cls");
    for(int a=-1;a++<width+1;)
	cout<<"-";
	cout<<endl;
	cout<<'|';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout<<setw(5)<<' '<<setw(4)<<" ***"<<setw(7)<<"*   *"<<setw(9)<<"*   "<<setw(6)<<"*  *"<<setw(6)<<"****";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout<<setw(5)<<"    |"<<endl;	
	cout<<'|';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout<<setw(5)<<' '<<setw(4)<<"*   "<<setw(7)<<"**  *"<<setw(9)<<"* *  "<<setw(6)<<"* * "<<setw(6)<<"*   ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout<<setw(5)<<"    |"<<endl;
	cout<<'|';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout<<setw(5)<<' '<<setw(4)<<"** "<<setw(7)<<"* * *"<<setw(9)<<"*   * "<<setw(6)<<"**  "<<setw(6)<<"****";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout<<setw(5)<<"    |"<<endl;	
	cout<<'|';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout<<setw(5)<<' '<<setw(4)<<"*"<<setw(7)<<"*  **"<<setw(9)<<"***** "<<setw(6)<<"* * "<<setw(6)<<"*   ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout<<setw(5)<<"    |"<<endl;		
	cout<<'|';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout<<setw(5)<<' '<<setw(4)<<"*** "<<setw(7)<<"*   *"<<setw(9)<<"*     *"<<setw(6)<<"*  *"<<setw(6)<<"****";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout<<setw(5)<<"    |"<<endl;
	for(int a=0;a++<height-8;)
	{
		if(a==3&&manupoint==1)
		cout<<'|'<<setw(27)<<">>遊戲開始<<"<<setw (15)<<'|'<<endl;
		else if(a==3)
		cout<<'|'<<setw(25)<<"遊戲開始"<<setw (17)<<'|'<<endl;
		else if(a==5&&manupoint==2)
		cout<<'|'<<setw(27)<<">> 排行榜 <<"<<setw (15)<<'|'<<endl;
		else if(a==5)
		cout<<'|'<<setw(24)<<"排行榜"<<setw (18)<<'|'<<endl;
		else if(a==7&&manupoint==3)
		cout<<'|'<<setw(27)<<">>難度選擇<<"<<setw (15)<<'|'<<endl;
		else if(a==7)
		cout<<'|'<<setw(25)<<"難度選擇"<<setw (17)<<'|'<<endl;
		else if(a==9&&manupoint==4)
		cout<<'|'<<setw(27)<<">>離開遊戲<<"<<setw (15)<<'|'<<endl;
		else if(a==9)
		cout<<'|'<<setw(25)<<"離開遊戲"<<setw (17)<<'|'<<endl;
		if(a==11)
		cout<<'|'<<setw(41)<<"w:up  s:down  a:left  d:right"<<'|'<<endl; 
		if(a==12)
		 cout<<'|'<<setw(41)<<"p:pause  l:leave  g:enter"<<'|'<<endl; 
		else
		cout<<'|'<<setw(42)<<'|'<<endl;
		
	}
	for(int a=-1;a++<width+1;)
	cout<<"-";
	Sleep(200);
	if(_kbhit())
	{

		switch(_getch())
		{
			case 'w':
				if(manupoint>1)
				manupoint=manupoint-1;
				break;
			case 's':
				if(manupoint<4)
				manupoint=manupoint+1;
				break;
			case 'W':
				if(manupoint>1)
				manupoint=manupoint-1;
				break;
			case 'S':
				if(manupoint<4)
				manupoint=manupoint+1;
				break;
			case 'g':
			case 'G':
				if(manupoint==1)
				gamestart=1;
			    if(manupoint==2)
			    {
			    	readfile.open("snakerank.txt");
			    	sta=0;
			    	co1=0;
			    	co2=0;
			    	co3=0;
			    	while(readfile>>namee[sta]>>scoree[sta]>>type[sta])
			    	{
			    		if(type[sta]==0)
			    		{
			    			if(co1<10)
			    			co1++;
			    			for(int j=9;j>=0;j--)
			    			{
			    				if(score1[j]<=scoree[sta])
			    				{
			    	              
			    				  score1[j+1]=score1[j];
			    				  score1[j]=scoree[sta];
			    				  name1[j+1]=name1[j];
			    				  name1[j]=namee[sta];
								}
							}
						}
			    		if(type[sta]==2)
			    		{
			    			if(co2<10)
			    			co2++;
			    			for(int j=9;j>=0;j--)
			    			{
			    				if(score2[j]<=scoree[sta])
			    				{
			    	              
			    				  score2[j+1]=score2[j];
			    				  score2[j]=scoree[sta];
			    				  name2[j+1]=name2[j];
			    				  name2[j]=namee[sta];
			    				  
								}
								
							}
						}
			    	     if(type[sta]==1)
			    		{
			    			if(co3<10)
			    			co3++;
			    			for(int j=9;j>=0;j--)
			    			{
			    				if(score3[j]<=scoree[sta])
			    				{
			    	              
			    				  score3[j+1]=score3[j];
			    				  score3[j]=scoree[sta];
			    				  name3[j+1]=name3[j];
			    				  name3[j]=namee[sta];
			    				  
								}
								
							}
						}
						sta++;
			    	}
			    	readfile.close();
					system("cls");
			    	cout<<"Easy\t\t\tMiddium\t\t\tHard\n";
					for(int jk=-1;jk++<10;)
			    	{ 
			    	if(jk<co1)
			   		cout<<"No. "<<jk+1<<"\t"<<name1[jk]<<"\t"<<score1[jk];
			   		else
					   cout<<"\t\t";
			   		if(jk<co2)
			   		cout<<"\t"<<"No. "<<jk+1<<"\t"<<name2[jk]<<"\t"<<score2[jk];
			   		else
					   cout<<"\t\t";
			   		if(jk<co3)
			   		cout<<"\t"<<"No. "<<jk+1<<"\t"<<name3[jk]<<"\t"<<score3[jk];
			   		cout<<endl;
			   		score1[jk]=0;
			   		score2[jk]=0;
			   		score3[jk]=0;
			   		} 
					while(back!=1)
					{
						if(_kbhit())
						back=1;
			    	}
			    	back=0;
				}
				if(manupoint==3)
			    {
			    	do
	             {
	            	Sleep(200);
                	if(_kbhit())
                 	{

	                 	switch(_getch())
	                	{
		             	case 'w':
		             	case 'W':
			        	    if(level==1)
			          	    level=2;
			          	    else if(level==2)
			          	    level=0;
			               	break;
			            case 's':
		            	case 'S':
			        	    if(level==0)
			            	level=2;
			            	else if(level==2)
			            	level=1;
			            	break;
		                case 'g':
		                case 'G':
			                leveln=1;
		                   	break;
                        }
                    }
 	         	system("cls");
               	for(int b=0;b++<10;)
	          	   {
			         if(b!=6&&b!=9)
			         cout<<endl;
			         if(b==7&&level==0)
	             	cout<<setw(27)<<">>easy<<"<<endl;
	             	else if(b==7)
	                   	cout<<setw(25)<<"easy"<<endl;
	               	else if(b==8&&level==2)
	                	cout<<setw(28)<<">>normal<<"<<endl;
	               	else if(b==8)
		                cout<<setw(26)<<"normal"<<endl;
	               	else if(b==10&&level==1)
	                	cout<<setw(27)<<">>hard<<"<<endl;
	               	else if(b==10)
		                cout<<setw(25)<<"hard"<<endl;
		            }
	            }while(!leveln);
			    leveln=0;
				}
			    if(manupoint==4)
			    {
				out3=1;
			}
			break;
        }
        
    }

    
}while(gamestart!=1);
mainm=0;  
}

void start()
{
	if(level==2)
	{
		for(int a=0;a<6;a++)
		{
			wallx[a]=0;
			wally[a]=0;
		}
		do{
		ewallx=2*rand()%(width/2)+2;
		}while(ewallx==width/2);
	}
	if(level==1)
	{
		wallx[0]=8;
		wallx[1]=10;
		wallx[2]=12;
		wallx[3]=28;
		wallx[4]=30;
		wallx[5]=32;
		wally[0]=4;
		wally[1]=5;
		wally[2]=6;
		wally[3]=14;
		wally[4]=15;
		wally[5]=16;
	}
	if(level==0)
	{
		for(int a=0;a<6;a++)
		{
			wallx[a]=0;
			wally[a]=0;
		}
	}
	gameover2=0;
	dir=Stop;
	x=width/2;
	y=height/2;
	srand(time(0));
	body=0;
	timesp=220;
	add=10;
	countpoint=0;
	do
	{
		pointx=2*rand()%(width/2)+2;
		pointy=rand()%height;
	}while((pointx==x&&pointy==y)||(pointx==wallx[0]&&pointy==wally[1])||(pointx==wallx[0]&&pointy==wally[4])
			||(pointx==wallx[1]&&pointy==wally[0])||(pointx==wallx[1]&&pointy==wally[1])||(pointx==wallx[1]&&pointy==wally[2])
			||(pointx==wallx[1]&&pointy==wally[3])||(pointx==wallx[1]&&pointy==wally[4])||(pointx==wallx[1]&&pointy==wally[5])
			||(pointx==wallx[2]&&pointy==wally[1])||(pointx==wallx[2]&&pointy==wally[4])||(pointx==wallx[3]&&pointy==wally[1])
			||(pointx==wallx[3]&&pointy==wally[4])||(pointx==wallx[4]&&pointy==wally[0])||(pointx==wallx[4]&&pointy==wally[1])
			||(pointx==wallx[4]&&pointy==wally[2])||(pointx==wallx[4]&&pointy==wally[3])||(pointx==wallx[4]&&pointy==wally[4])
			||(pointx==wallx[4]&&pointy==wally[5])||(pointx==wallx[5]&&pointy==wally[1])||(pointx==wallx[5]&&pointy==wally[4])
			||(pointx==ewallx&&pointy<3&&pointy>height-4));
	point=0;
}

void background()
{
	system("cls");
	HANDLE color;
	color=GetStdHandle(STD_OUTPUT_HANDLE);
	for(int a=-1;a++<width+1;)
	cout<<"-";
	cout<<endl;
	for(int c=-1;c++<height-1;)
	{
		for(int d=-1;d++<width+1;)
		{
			if(d==0||d==width+1)
			cout<<'|';
			else if(((d==2&&c==1)||(d==4&&c==1)||(d==36&&c==2)||(d==38&&c==2)||(d==40&&c==2)||(d==2&&c==4)||(d==2&&c==5)||
			(d==10&&c==8)||(d==8&& c==9)||(d==12&&c==11)||(d==12&&c==10)||(d==38&&c==10)||(d==32&&c==10)||(d==16&&c==14)||
			(d==6&&c==8)||(d==6&&c==9)||(d==8&&c==19)||(d==18&&c==18)||(d==16&&c==18)||(d==14&&c==18)||(d==34&&c==19)||
			(d==32&&c==19)||(d==30&&c==19)||(d==22&&c==1)|| (d==20&&c==2)||(d==24&&c==2)||(d==22&&c==3)||(d==20&&c==8)||(d==22&&c==9)||
			(d==22&&c==10)||(d==2&&c==16))&& ((d==bonusx&&c==bonusy&&bonustime>0)|| (c==pointy&&d==pointx)) 
			)
			{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<'M';
			 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
			
			else if((d==2&&c==1)||(d==4&&c==1)||(d==36&&c==2)||(d==38&&c==2)||(d==40&&c==2)||(d==2&&c==4)||(d==2&&c==5)||
			(d==10&&c==8)||(d==8&& c==9)||(d==12&&c==11)||(d==12&&c==10)||(d==38&&c==10)||(d==32&&c==10)||(d==16&&c==14)||
			(d==6&&c==8)||(d==6&&c==9)||(d==8&&c==19)||(d==18&&c==18)||(d==16&&c==18)||(d==14&&c==18)||(d==34&&c==19)||
			(d==32&&c==19)||(d==30&&c==19)||(d==22&&c==1)|| (d==20&&c==2)||(d==24&&c==2)||(d==22&&c==3)||(d==20&&c==8)||(d==22&&c==9)||
			(d==22&&c==10)||(d==2&&c==16)
			)
			{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout<<'M';
			 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
			else if(d==bonusx&&c==bonusy&&bonustime>0)
			{
		     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			 cout<<'#';
			 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			 }
			else if((d==wallx[0]&&c==wally[1])||(d==wallx[0]&&c==wally[4])
					||(d==wallx[1]&&c==wally[0])||(d==wallx[1]&&c==wally[1])||(d==wallx[1]&&c==wally[2])
					||(d==wallx[1]&&c==wally[3])||(d==wallx[1]&&c==wally[4])||(d==wallx[1]&&c==wally[5])
					||(d==wallx[2]&&c==wally[1])||(d==wallx[2]&&c==wally[4])||(d==wallx[3]&&c==wally[1])
					||(d==wallx[3]&&c==wally[4])||(d==wallx[4]&&c==wally[0])||(d==wallx[4]&&c==wally[1])
					||(d==wallx[4]&&c==wally[2])||(d==wallx[4]&&c==wally[3])||(d==wallx[4]&&c==wally[4])
					||(d==wallx[4]&&c==wally[5])||(d==wallx[5]&&c==wally[1])||(d==wallx[5]&&c==wally[4])
					||(d==ewallx&&c>3&&c<height-4))
			cout<<'X';
			else if(c==y&&d==x)
			{
	
			 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout<<'@';
			 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
			else if(c==pointy&&d==pointx)
			{
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout<<'$';
			 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			 }
			else
			{
				print=0;
				for(int n=-1;n++<body-1;)
				{
					if(d==bodyx[n]&&c==bodyy[n])
					{	
					 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						cout<<'*';
						 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						print=1;
					}
				}
				if (!print)
				cout<<' ';
			}
		}
		cout<<endl;
	}
	for(int b=-1;b++<width+1;)
	cout<<'-';
	cout<<endl<<"point:"<<point;;
}

void control_snake()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'w':
				if(dir!=Down||body==0)
				dir=Up;
				break;
			case 's':
				if(dir!=Up||body==0)
				dir=Down;
				break;
			case 'a':
				if(dir!=Right||body==0)
				dir=Left;
				break;
			case 'd':
				if(dir!=Left||body==0)
				dir=Right;
				break;
			case 'l':
				gameover2=1;
				quitgame=1;
				break;
			case 'p':
				pause=1;
				break;
			case 'W':
				if(dir!=Down||body==0)
				dir=Up;
				break;
			case 'S':
				if(dir!=Up||body==0)
				dir=Down;
				break;
			case 'A':
				if(dir!=Right||body==0)
				dir=Left;
				break;
			case 'D':
				if(dir!=Left||body==0)
				dir=Right;
				break;
			case 'L':
				gameover2=1;
				quitgame=1;
				break;
			case 'P':
				pause=1;
				break;
			case '+':
			    point=point+100;
			if(timesp>40)
		      	timesp=timesp-40;
		    break;
		}
	}
}

void pauserun()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'p':
				pause=0;
				break;
			case 'P':
				pause=0;
				break;
		}
	}	
}

void rules()
{
	int bonus=1;
	while(pause==1)
	pauserun();
	if (bonustime!=0)
	bonustime--;
	if (bonustime==0&&dir!=Stop)
	bonus=rand()%100;
	if (bonus==0)
	bonustime=75;
	for(int i=body+1;i-->1;)
	{
		bodyx[i]=bodyx[i-1]+bodyx[i];
		bodyx[i-1]=bodyx[i]-bodyx[i-1];
		bodyx[i]=bodyx[i]-bodyx[i-1];
		bodyy[i]=bodyy[i-1]+bodyy[i];
		bodyy[i-1]=bodyy[i]-bodyy[i-1];
		bodyy[i]=bodyy[i]-bodyy[i-1];
	}
	bodyx[0]=x;
	bodyy[0]=y;
	if(body<5&&dir!=Stop)
	body++;
	switch(dir)
	{
		case Up:
			y--;
			break;
		case Down:
			y++;
			break;
		case Left:
			x-=2;
			break;
		case Right:
			x+=2;
			break;
		default:
			break;
	}
	if(x==width+1)
	x=2;
	else if(x==0)
	x=width-1;
	if(y==height)
	y=0;
	else if(y==-1)
	y=height-1;
	for(int l=-1;l++<body-1;)
	{
		if(x==bodyx[l]&&y==bodyy[l])
		{
		gameover2=1;
		quitgame=1;
	}
	}
	if ((x==wallx[0]&&y==wally[1])||(x==wallx[0]&&y==wally[4])
		||(x==wallx[1]&&y==wally[0])||(x==wallx[1]&&y==wally[1])||(x==wallx[1]&&y==wally[2])
		||(x==wallx[1]&&y==wally[3])||(x==wallx[1]&&y==wally[4])||(x==wallx[1]&&y==wally[5])
		||(x==wallx[2]&&y==wally[1])||(x==wallx[2]&&y==wally[4])||(x==wallx[3]&&y==wally[1])
		||(x==wallx[3]&&y==wally[4])||(x==wallx[4]&&y==wally[0])||(x==wallx[4]&&y==wally[1])
		||(x==wallx[4]&&y==wally[2])||(x==wallx[4]&&y==wally[3])||(x==wallx[4]&&y==wally[4])
		||(x==wallx[4]&&y==wally[5])||(x==wallx[5]&&y==wally[1])||(x==wallx[5]&&y==wally[4])
		||(x==ewallx&&y>3&&y<height-4))
	{
		gameover2=1;
		quitgame=1;
	}
	if (x==pointx&&y==pointy)
	{
		point+=add;
		countpoint+=add;
		if(countpoint>=100)
		{
			add+=5;
			countpoint-=100;
			if(timesp>40)
			timesp-=40;
		}
		do
		{
			pointx=2*rand()%(width/2)+2;
			pointy=rand()%height;
			check1=0;
			for(int cc=-1;cc++<body-1;)
			{
				if(pointx==bodyx[cc]&&pointy==bodyy[cc])
				check1=1;
			}
		}while((pointx==x&&pointy==y)||check1==1||(pointx==wallx[0]&&pointy==wally[1])||(pointx==wallx[0]&&pointy==wally[4])
				||(pointx==wallx[1]&&pointy==wally[0])||(pointx==wallx[1]&&pointy==wally[1])||(pointx==wallx[1]&&pointy==wally[2])
				||(pointx==wallx[1]&&pointy==wally[3])||(pointx==wallx[1]&&pointy==wally[4])||(pointx==wallx[1]&&pointy==wally[5])
				||(pointx==wallx[2]&&pointy==wally[1])||(pointx==wallx[2]&&pointy==wally[4])||(pointx==wallx[3]&&pointy==wally[1])
				||(pointx==wallx[3]&&pointy==wally[4])||(pointx==wallx[4]&&pointy==wally[0])||(pointx==wallx[4]&&pointy==wally[1])
				||(pointx==wallx[4]&&pointy==wally[2])||(pointx==wallx[4]&&pointy==wally[3])||(pointx==wallx[4]&&pointy==wally[4])
				||(pointx==wallx[4]&&pointy==wally[5])||(pointx==wallx[5]&&pointy==wally[1])||(pointx==wallx[5]&&pointy==wally[4])
				||(pointx==ewallx&&pointy<3&&pointy>height-4));
		body++;
	}
	if(bonus==0)
	{
		do
		{
			bonusx=2*rand()%(width/2)+2;
			bonusy=rand()%height;
			check1=0;
			for(int cc=-1;cc++<body-1;)
			{
				if(bonusx==bodyx[cc]&&bonusy==bodyy[cc])
				check1=1;
			}
		}while((bonusx==x&&bonusy==y)||check1==1||(bonusx==wallx[0]&&bonusy==wally[1])||(bonusx==wallx[0]&&bonusy==wally[4])
				||(bonusx==wallx[1]&&bonusy==wally[0])||(bonusx==wallx[1]&&bonusy==wally[1])||(bonusx==wallx[1]&&bonusy==wally[2])
				||(bonusx==wallx[1]&&bonusy==wally[3])||(bonusx==wallx[1]&&bonusy==wally[4])||(bonusx==wallx[1]&&bonusy==wally[5])
				||(bonusx==wallx[2]&&bonusy==wally[1])||(bonusx==wallx[2]&&bonusy==wally[4])||(bonusx==wallx[3]&&bonusy==wally[1])
				||(bonusx==wallx[3]&&bonusy==wally[4])||(bonusx==wallx[4]&&bonusy==wally[0])||(bonusx==wallx[4]&&bonusy==wally[1])
				||(bonusx==wallx[4]&&bonusy==wally[2])||(bonusx==wallx[4]&&bonusy==wally[3])||(bonusx==wallx[4]&&bonusy==wally[4])
				||(bonusx==wallx[4]&&bonusy==wally[5])||(bonusx==wallx[5]&&bonusy==wally[1])||(bonusx==wallx[5]&&bonusy==wally[4])
				||(bonusx==ewallx&&bonusy<3&&bonusy>height-4));
	}
	if(bonusx==x&&bonusy==y)
	{
		bonustime=0;
		point+=(add*5);
		bonusx=1000;
		bonusy=1000;
	}
}
void gamelose()
{
	retryn=0;
	system("cls");
	cout<<endl<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout<<setw(14)<<"*   "<<setw(5)<<"** "<<setw(5)<<" ***"<<setw(6)<<"****"<<endl;	
	cout<<setw(14)<<"*   "<<setw(5)<<"*  *"<<setw(5)<<"*   "<<setw(6)<<"*   "<<endl;
	cout<<setw(14)<<"*   "<<setw(5)<<"*  *"<<setw(5)<<"** "<<setw(6)<<"****"<<endl;	
	cout<<setw(14)<<"*   "<<setw(5)<<"*  *"<<setw(5)<<"*"<<setw(6)<<"*   "<<endl;		
	cout<<setw(14)<<"****"<<setw(5)<<"** "<<setw(5)<<"*** "<<setw(6)<<"****"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	Sleep(500);
	cout<<endl<<setw(20)<<"your point: ";
	Sleep(500);
	cout<<setw(5)<<point<<endl;
	Sleep(500);
	cout<<endl<<setw(20)<<"your name: ";
	cin>>setw(10)>>namess;
	storefile.open("snakerank.txt",ios::app);
	storefile<<namess<<' '<<point<<' '<<level<<endl;
	storefile.close();
	do
	{
		Sleep(200);
	if(_kbhit())
	{

		switch(_getch())
		{
			case 'w':
			case 'W':
				if(retry==1)
				retry=0;
				else if(retry==2)
				retry=1;
				break;
			case 's':
			case 'S':
				if(retry==1)
				retry=2;
				else if(retry==0)
				retry=1;
				break;
			case 'G':
			case 'g':
			    if(retry==1)
			    {
					retryn=1;
					mainm=1;
				}
				if(retry==0)
				{
					retryn=1;
					start();
				} 
				if(retry==2)
				out3=1;
				retryn=1;
			break;
        }
        
    }
		system("cls");
	for(int b=0;b++<10;)
		{
			if(b!=6&&b!=9)
			cout<<endl;
			if(b==7&&retry==0)
			cout<<setw(27)<<">>retry<<"<<endl;
			else if(b==7)
			cout<<setw(25)<<"retry"<<endl;
			else if(b==8&&retry==1)
			cout<<setw(27)<<">>menu <<"<<endl;
			else if(b==8)
			cout<<setw(24)<<"menu"<<endl;
			else if(b==10&&retry==2)
			cout<<setw(27)<<">>exit <<"<<endl;
			else if(b==10)
			cout<<setw(24)<<"exit"<<endl;
			gamestart=0;
		}
	}while(!retryn);
}
int mainpro_snake()
{
	out3=0;
	mainm=1;
	do
	{
		mainsnake();
		if(mainm==1)
		mainmenu();
		if(out3==1)
		break;
		start();
		while(!gameover2)
		{
			control_snake();
			rules();
			background();
			Sleep(timesp);
		}
		gamelose();
		if(out3==1)
		break;
	}while(quitgame!=0);
}
