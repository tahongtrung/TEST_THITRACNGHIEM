#include<cstring>
#define MAXLIST 100
using namespace std;
struct cauhoi{
	int id;
	char mamh[20];
	string noidung;
	string A;
	string B;
	string C;
	string D;
	char key;
};
typedef struct listch{
	int n;
	cauhoi nodesch[MAXLIST];
};

struct monhoc{
	char mamh[20];
	char tenmh[20];
	listch dethi;
};

typedef struct list{
	int n;
	monhoc nodes[MAXLIST];
	
};
list ds;

int isEmpty(list ds){
	return ds.n==0;
}

int isFull(list ds){
	return ds.n==MAXLIST;
}
//them 1 phan tu
//int insertItem(struct list &plist,int i, int info){
//	int j;
//	if(i<0||i>plist.n||Full(plist)) return 0;
//	for(j=plist.n-1;j>=i;j--){
//		
//	}
//}
void nhapMH(struct list &plist){
	TextColor(58);
	gotoxy(38,2);
	cout << "LUU Y";
	gotoxy(5,3);
	cout<<"So mon hoc cho truoc, co dinh, khong the thay doi trong qua trinh nhap";
	gotoxy(5,4);
	cout << "Ma mon hoc gom ca so va chu va khong qua 20 ki tu!";
	gotoxy(5,5);
	cout << "Ten mon hoc gom ca so va chu va khong vuot qua 20 ki tu!";
	pchose(1,7,79,10,40,40,40,40,1);
	gotoxy(15,9);
	cout<<"So Mon Hoc";
	gotoxy(55,9);
	cin>>plist.n;
	pchose(1,11,79,14,40,40,40,40,1);
	gotoxy(15,13);
	cout<<"Nhap Ma Mon";
	gotoxy(55,13);
	cout<<"Nhap Ten Mon";
	for(int i=0;i<plist.n;i++){
		pchose(1,(i+1)*4+11,79,(i+1)*4+14,40,40,40,40,1);
		fflush(stdin);
		gotoxy(15,(i+1)*4+13);
		gets(plist.nodes[i].mamh);
		fflush(stdin);
		gotoxy(55,(i+1)*4+13);
		gets(plist.nodes[i].tenmh);
		
		
	}	
}
void duyetMH(){
	
}
int ktidch(char mamh[]){
	for(int i=0;i<ds.n;i++){
		if(strcmp(mamh,ds.nodes[i].mamh)==0)
			return i;
	}
	return -1;
}
