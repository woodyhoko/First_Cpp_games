#include"99.cpp"
#include"black and white test.cpp"
#include"snake1.22.cpp"
#include"mole.cpp"
#include"flip.cpp"
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

char chose;
void mainmenu1()
{
	cout<<endl;
cout<<"     ********       **      ****     ****  ********   ********\n";
cout<<"    **//////**     ****    /**/**   **/** /**/////   **////// \n";
cout<<"   **      //     **//**   /**//** ** /** /**       /**       \n";
cout<<"  /**            **  //**  /** //***  /** /*******  /*********\n";
cout<<"  /**    *****  ********** /**  //*   /** /**////   ////////**\n";
cout<<"  //**  ////** /**//////** /**   /    /** /**              /**\n";
cout<<"   //********  /**     /** /**        /** /********  ******** \n";
cout<<"    ////////   //      //  //         //  ////////  ////////  \n\n\n";
	cout<<"             要玩貪吃蛇請按1  (主題！！！)\n\n";
	cout<<"             要玩打地鼠請按2  (附屬小遊戲)\n\n";
	cout<<"             要玩黑白棋請按3  (挑戰看看AI)\n\n";
	cout<<"             要玩99請按4  (試試看不需更新畫面的遊戲)\n\n";
	cout<<"             要玩翻牌請按5  (都寫4個了，完成最後一個吧)\n\n";
	cout<<"             要離開請輸入0\n\n             ";
	do
	{
		if(_kbhit())
		{
		switch(_getch())
		{
			case '0':
				chose='0';
				break;
			case '1':
				chose='1';
				break;
			case '2':
				chose='2';
				break;
			case '3':
				chose='3';
				break;
			case '4':
				chose='4';
				break;
			case '5':
				chose='5';
				break;
		}
		}
	}while(chose!='5'&&chose!='0'&&chose!='1'&&chose!='2'&&chose!='3'&&chose!='4');
	system("cls");
}

int main()
{
	while(1)
	{
	mainmenu1();
	if(chose=='1'){
	mainpro_snake();system("cls");chose='x';}
	if(chose=='2'){
	mainpro_mole();system("cls");chose='x';}
	if(chose=='3'){
	mainpro_bnw();system("cls");chose='x';}
	if(chose=='4'){
	mainpro_99();system("cls");chose='x';}
	if(chose=='5'){
	mainpro_flip();system("cls");chose='x';}
	if(chose=='0')
	exit(1);
	}
}
