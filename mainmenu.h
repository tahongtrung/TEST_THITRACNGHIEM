#include<cstring>
using namespace std;

int printMenu(){
	string s[5];
	system("cls");
	int c =0;
	s[0]="THI TRAC NGHIEM";
	s[1]="1.NHAP LOP";
	s[2]="2.NHAP SV OF LOP";
	s[3]="3.NHAP MON";
	s[4]="4.NHAP CAUHOI";
	menu(s,5,4,3,12,1,c);
	return c;
}

