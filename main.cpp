#include"99.cpp"
#include"balck and white test.cpp"
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
	cout<<"             �n���g�Y�D�Ы�1  (�D�D�I�I�I)\n\n";
	cout<<"             �n�����a���Ы�2  (���ݤp�C��)\n\n";
	cout<<"             �n���¥մѽЫ�3  (�D�Ԭݬ�AI)\n\n";
	cout<<"             �n��99�Ы�4  (�ոլݤ��ݧ�s�e�����C��)\n\n";
	cout<<"             �n��½�P�Ы�5  (���g4�ӤF�A�����̫�@�ӧa)\n\n";
	cout<<"             �n���}�п�J0\n\n             ";
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
