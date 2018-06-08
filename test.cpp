#include<iostream>
#include"lop.h"
//#include"sinhvien.h"
#include"diemthi.h"
//#include"monhoc.h"
#include"cauhoi.h"
#include"mainmenu.h"
#include"thi.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//NODEPTR p;
listch nh;
int main(int argc, char** argv) {
	
	system("TITLE PHÂN MÊM THI TRAC NGHIÊM");
	system("color 3F");
	int c=0;
	do{
	c=	printMenu();
	//clrscr();
	system("cls");
		switch(c){
			case 0: {
				thitracnghiem();
				break;
			}
			case 1:{
				nhapLop(tree);
				duyetTree(tree);
				break;
			}
				
			case 2:{
				initialize(First);
				nhapSV(First);
				duyetSV(First);
				break;	
			}		
			case 3:{
				nhapMH(ds);
				break;
			}
			
			case 4:{
				nhap_cau_hoi(nh);
				break;
			}
		}
	}while(!0);
	return 0;
}
