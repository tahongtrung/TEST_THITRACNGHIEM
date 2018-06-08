#include<cstring>
#include"monhoc.h"
#define MAXLIST 100
using namespace std;

//listch dethi;
int isEmptyCH(listch ds){
	return ds.n==0;
}

int isFullCH(listch ds){
	return ds.n==MAXLIST;
}

int kiemtra(char a[20])
{
	for(int i = 0; i< ds.n; i++)
	{	
		if(strcmp(a,ds.nodes[i].mamh)==0)
		return i;
	
	}
	return -1;
}
void ghifilecauhoi(listch t){
	ofstream out("cauhoi.txt",ios::app);
	for(int i = 0; i < t.n;i++)
	{
		out<<t.nodesch[i].noidung<<" "<<t.nodesch[i].A<<" "<<t.nodesch[i].B<<" "<<t.nodesch[i].C<<" "<<t.nodesch[i].D<<" "<<t.nodesch[i].key<<endl;
	}
	out.close();
}


void nhapCH(struct listch &plist, char *a){
	
	int i = plist.n;
	while(!0){
		plist.nodesch[i].id=i;
		strcpy(plist.nodesch[i].mamh,a);
		cout<<"NHAP NOI DUNG CH: ";
		fflush(stdin);
		getline(cin,plist.nodesch[i].noidung);
		if(cin,plist.nodesch[i].noidung[0]=='\0') break;
		cout<<"NHAP D/A A: ";
		fflush(stdin);
		getline(cin,plist.nodesch[i].A);
		cout<<"NHAP D/A B: ";
		fflush(stdin);
		getline(cin,plist.nodesch[i].B);
		cout<<"NHAP D/A C: ";
		fflush(stdin);
		getline(cin,plist.nodesch[i].C);
		cout<<"NHAP D/A D: ";
		fflush(stdin);
		getline(cin,plist.nodesch[i].D);
		do{
			cout<<"NHAP D/A: ";
			fflush(stdin);
			plist.nodesch[i].key = getchar();
			if(plist.nodesch[i].key!='A'&&plist.nodesch[i].key!='a'&&plist.nodesch[i].key!='B'&&plist.nodesch[i].key!='b'&&plist.nodesch[i].key!='C'&&plist.nodesch[i].key!='c'&&plist.nodesch[i].key!='d'&&plist.nodesch[i].key!='D')
				cout << "Vui long nhap D/A = A,a,B,b,C,c,D,d" <<endl;
		}
	
	while(plist.nodesch[i].key!='A'&&plist.nodesch[i].key!='a'&&plist.nodesch[i].key!='B'&&plist.nodesch[i].key!='b'&&plist.nodesch[i].key!='C'&&plist.nodesch[i].key!='c'&&plist.nodesch[i].key!='d'&&plist.nodesch[i].key!='D');
	i++;
	plist.n++;
}
ghifilecauhoi(plist);
}

void duyetCH(listch t){
	for(int i = 0; i < t.n;i++)
	{
		cout<<t.nodesch[i].noidung<<" "<<t.nodesch[i].A<<" "<<t.nodesch[i].B<<" "<<t.nodesch[i].C<<" "<<t.nodesch[i].D<<endl;
	}
}
void nhap_cau_hoi(struct listch &plist)
{
	int tam;
	char a[20];
	while(!0)
	{
		TextColor(58);
		pchose(1,7,79,10,40,40,40,40,1);
		gotoxy(15,9);
		cout<<"NHAP MA MON HOC";
		gotoxy(55,9);
		
		fflush(stdin);
		gets(a);
		gotoxy(1,14);
		if(a[0]=='\0') break;
		tam = ktidch(a);
		if(kiemtra(a)==-1){
			system("cls");
			gotoxy(20,9);
			cout<<"Ma mon hoc khong ton tai!Xin nhap lai!";
			Sleep(1000);
			goto end;
		}
		else
		{
			if(tam==-1) continue;
			else nhapCH(ds.nodes[ktidch(a)].dethi, a);
		}
		
		
		end:;
		system("cls");
	}
	duyetCH(ds.nodes[tam].dethi);
	getch();
}
