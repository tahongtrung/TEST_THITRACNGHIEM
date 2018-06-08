#include<cstring>
#include"mylib.h"
#include"sinhvien.h"
using namespace std;


void chenNode(NODEPTREE &p,int x,lop a){
	if(p==NULL){
		p=newNodeTree();
		p->key=x;
		p->info=a;
		p->left=NULL;
		p->right=NULL;
		p->info.dssv=NULL;
	}else{
		if(x<p->key) chenNode(p->left,x,a);
		else chenNode(p->right,x,a);
	}
}

void nhapLop(NODEPTREE &root){
	TextColor(58);
	gotoxy(38,2);
	cout << "LUU Y";
	gotoxy(5,3);
	cout<<"Khoa la 1 so gom 4 chu so,khong dc nhap chu!";
	gotoxy(5,4);
	cout << "Ma lop gom ca so va chu va khong qua 20 ki tu!";
	gotoxy(5,5);
	cout << "Ten lop gom ca so va chu va khong vuot qua 20 ki tu!";
	int k;
	lop in;
	pchose(1,7,79,10,25,50,50,50,1);
	gotoxy(10,9);
	cout<<"Nhap Khoa: ";
	gotoxy(35,9);
	cout<<"Nhap ma lop: ";
	gotoxy(60,9);
	cout<<"nhap ten lop: ";
	int count = 0;
	do{
		count++;
		pchose(1,count*4+7,79,count*4+10,25,50,50,50,1);
		gotoxy(11,count*4+9);
		nhapso(k);
		if(k!=0){
			
			fflush(stdin);
			gotoxy(36,count*4+9);
			gets(in.malop);
			
			fflush(stdin);
			gotoxy(61,count*4+9);
			gets(in.tenlop);
			
			chenNode(root,k,in);
		}
	}while(k!=0);
	duyetTree(tree);getch();
}


