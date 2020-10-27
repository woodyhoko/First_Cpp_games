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
	cout<<"             Snake (press 1)\n\n";
	cout<<"             Whac-A-mole (press 2)\n\n";
	cout<<"             Reversi (press 3)\n\n";
	cout<<"             Card game 99 (press 4)\n\n";
	cout<<"             Memory game (press 5)\n\n";
	cout<<"             press 0 to leave\n\n             ";
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
