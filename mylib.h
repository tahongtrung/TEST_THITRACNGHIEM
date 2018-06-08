#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<windows.h>

void xoavitrichuoi(char *a, int x);
using namespace std;
void SetBGColor(WORD color){//cai dat mau nen cho console
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void clrscr(){	//xoa man hinh
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0, 0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

//tra ve vi tri hoanh do con tro
int wherex()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.X;
}
//tra ve vi tri tung do con tro
int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.Y;
}
//mau nen chu
void textbk(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//mau chu
void TextColor(int x) 
{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , x);
}

void gotoxy(int x,int y) 
{ 
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ; 
COORD position = {x,y} ; 
SetConsoleCursorPosition(hStdout,position ) ; 
}
//nhan phim tu keyboard
bool checkKey(int key)
{
    return GetAsyncKeyState(key);
}
//ve chu nhat bang duong thang co duong cheo qua 2 diem (x0,y0) (x1,y1), loai 1 ve duong do, 2 ve duong doi, 0 xoa hinh chu nhat 
void chose(int x0, int y0, int x1, int y1, int loai)
{
	if(loai==1)
	{
		gotoxy(x0,y0);	 cout<<char(218);
		gotoxy(x0,y1);	cout<<char(192);
		gotoxy(x1,y0);	cout<<char(191);
		gotoxy(x1,y1);	cout<<char(217);
		
		for(int i=x0+1; i<x1; i++)
		{
			gotoxy(i,y0);	cout<<char(196);
			gotoxy(i,y1);	cout<<char(196);
		}
		
		for(int i=y0+1; i<y1; i++)
		{
			gotoxy(x0,i);	cout<<char(179);
			gotoxy(x1,i);	cout<<char(179);
		}
	}
	
	if(loai==2)
	{
		gotoxy(x0,y0);	 cout<<char(201);
		gotoxy(x0,y1);	cout<<char(200);
		gotoxy(x1,y0);	cout<<char(187);
		gotoxy(x1,y1);	cout<<char(188);
		
		for(int i=x0+1; i<x1; i++)
		{
			gotoxy(i,y0);	cout<<char(205);
			gotoxy(i,y1);	cout<<char(205);
		}
		
		for(int i=y0+1; i<y1; i++)
		{
			gotoxy(x0,i);	cout<<char(186);
			gotoxy(x1,i);	cout<<char(186);
		}
	}
	if(loai==0)
	{	
		for(int i=x0; i<=x1; i++)
		{
			gotoxy(i,y0);
			cout<<" ";
			gotoxy(i,y1);
			cout<<" ";
		}
		
		for(int i=y0; i<=y1; i++)
		{
			gotoxy(x0,i);
			cout<<" ";
			gotoxy(x1,i);
			cout<<" ";
		}
	}
}
//xoa mot chuoi
void xoachuoi(char *a)
{
	for(int i=0;i<=strlen(a);i++)
	a[i]='\0';
}

//nhap chu khong cho nhap so
void nhapchu(char *a, string b)
{	
	char t;
	int i=0;
	while(!0)
	{
		t=getch();
		if(t==13)	break;
		if((t>='A'&&t<='Z')||(t<='z'&&t>='a')||t==' ')
		{
		if(b=="hoa")	a[i]=toupper(t);
		else if(b=="")	a[i]=tolower(t);
		i++;
		cout<<t;
		}
		if(checkKey(VK_BACK)&&i>0)
		{
			gotoxy(wherex()-1, wherey());
			cout<<" ";
			gotoxy(wherex()-1, wherey());
			a[i-1]='\0';
			i--;
		}
	}
	a[i]='\0';
	cout<<endl;
}
//nhap so khong cho nhap chu
int nhapso(int &a)
{
	char t, *b=new char;
	int i=0;
	while(!0)
	{
		t=getch();
		if(t==13)	break;
		if(t>='0'&&t<='9'||t=='.')
			{
				b[i]=t;
				i++;
				cout<<t;
			}
		if(checkKey(VK_BACK)&&i>0)
		{
			gotoxy(wherex()-1, wherey());
			cout<<" ";
			gotoxy(wherex()-1, wherey());
			b[i-1]='\0';
			i--;
		}
	}
	b[i]='\0';
	a=atoi(b);
	cout<<endl;
	return strlen(b);
}
//can le cho chuoi
//giua
void aligncenter(string s,int y)
{
	gotoxy(39-s.size()/2,y);
	cout<<s;
}
//can trai n ki tu
void alignleft(string s, int n)
{
	gotoxy(n,wherey());
	cout<<s;
}
//can phai n ki tu
void alignright(string s, int n)
{
	gotoxy(80-n-s.size(),wherey());
	cout<<s;
}
char* chuyen_chuoi(string s)
{
	int len = s.size();
	char a[len+1];
	for(int i = 0; i<len; i++)
	{
		a[i] = s[i];
	}
	s[len] = '\0';
	return a;
}

//chuyen so n sang chuoi a[]
char* so_chuoi(int n, char a[20])
{
	xoachuoi(a);
	int i=0;
	while(n!=0)
	{
		a[i]=n%10+48;
		n=n/10;
		i++;
	}
	a[i]='\0';
	int left=0, right=strlen(a)-1;
	while(left<right)
	{
		char temp=a[left];
		a[left]=a[right];
		a[right]=temp;
		left++, right--;
	}
	return a;
}
//ve chu nhat mau tai vi tri x,y va co chieu cao h chieu rong w, mau tu 1->15, int nen la mau nen hien tai
void chunhat(int x, int y, int h, int w,int mau, int nen)
{
	textbk(mau);
	for(int i=y; i<y+h; i++)
		{for(int j=x;j<x+w;j++)
			{
				gotoxy(j,i);
				cout<<" ";
			}
		}
	gotoxy(x+w,y);
	textbk(nen);
}

//an di con tro, ancontro(0) -> an;;; ancontro(1)->hien lai con tro
 void ancontro(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}
// ve duong thang ngang tu x0 toi x1, tai tung do y
void linex(int x0, int x1, int y)
{
	gotoxy(x0,y);
	for(int i=x0; i<x1; i++)
	cout<<char(196);
}
//ve duong thang doc tu y0 toi y1 tai hoanh do x
void liney(int y0, int y1, int x)
{
	for(int i=y0;i<y1;i++)
	{
	gotoxy(x,i);
	cout<<char(179);
	}
	gotoxy(wherex(),y0);
}
//cho so ngau nhien tu x->y x<y
int randd(int x, int y)
{
	int khoangcach;
	if(x>=0)
	{
		khoangcach=y-x+1;
		khoangcach=rand()%khoangcach;
		return khoangcach+x;
	}
	if(y<0)
	{
		return -randd(abs(y),abs(x));
	}
	
	if(y>-x)	khoangcach=y+1;
	else	khoangcach=-x+1;
	int temp;
	temp=rand()%khoangcach;
	if(temp>-x)	return temp;
	else
	{
		int i=rand()%2;
		if(i==0)	return temp;
		else	return -temp;
	}
}
void xoavitri(int *a, int len, int x)
{
	for(int i=x; i<len; i++)
	{
		a[i]=a[i+1];
	}
}
void chenvitri(int *a, int len, int x, int n)
{
	for(int i=len; i>x; i--)
	{
		a[i]=a[i-1];
	}
	a[x]=n;
}
void xeptang(int *a, int len)
{
	int min, vt;
	for(int i=0; i<len-1; i++)
	{ min=a[i], vt=i;
		for(int j=i; j<len; j++)
		{
			if(min>a[j])
			{
				min=a[j];
				vt=j;
			}
		}
		a[vt]=a[i];
		a[i]=min;
	}
}
void xepgiam(int *a, int len)
{
	int max, vt;
	for(int i=0; i<len-1; i++)
	{	max=a[i], vt=i;
		for(int j=i; j<len; j++)
		{
			if(max<a[j])
			{
				max=a[j];
				vt=j;
			}
		}
	a[vt]=a[i];
	a[i]=max;
	}
}
int kiemtratang(int *a, int len)
{
	for(int i=0; i<len-1; i++)
	{
		if(a[i]>a[i+1])	return 0;
	}
	return 1;
}
void noichuoi(char *a, char *b)
{
	int i,j;
	for(i=strlen(a), j=0; i<strlen(a)+strlen(b);i++,j++)
	{
		a[i]=b[j];
	}
	a[i]='\0';
}

int khungyesno(int x, int y)
{	
ancontro(0);
	chose(x,y,x+30,y+14,2);
	gotoxy(x+9,y+7);	cout<<" YES ";
	gotoxy(x+17,y+7);	cout<<" NO  ";
	int chon=0;
	chose(x+16,y+6,x+22,y+8,1);
		Beep(400,100);
		Sleep(100);
		Beep(800,200);
	while(getch()!=13)
	{	char t=getch();
		if(checkKey(VK_LEFT)||checkKey(VK_RIGHT))	{	if(chon==0)	{chon=1;
												chose(x+8,y+6,x+14,y+8,1);
												chose(x+16,y+6,x+22,y+8,0);
												Beep(500,150);
												}
									else 		{chon=0;
												chose(x+16,y+6,x+22,y+8,1);
												chose(x+8,y+6,x+14,y+8,0);
												Beep(500,150);}									
											}
	}
	gotoxy(x+30, y+17);
	return chon;
ancontro(1);	
}

void menutinh(string s[], int sodong, int y, int maunen, int mauchu, int mauchon, int &vitri)
{
	TextColor(10);
	chose(1,0,78,24,2);
	gotoxy(0,y);
	TextColor(mauchu);
	for(int i=0;i<sodong;i++)
	{
		if(i==vitri)	{TextColor(14);textbk(mauchon);aligncenter(s[i],wherey());TextColor(mauchu);}
		else	{textbk(maunen);	aligncenter(s[i],wherey());}
		cout<<endl<<endl;
	}
	textbk(maunen);
}
void menu(string s[], int sodong, int y, int maunen, int mauchu, int mauchon, int &vitri)
{
	menutinh(s,sodong,y,maunen,mauchu,mauchon,vitri);
	while(getch()!=13)
	{
		if(checkKey(VK_UP))	{if(vitri==0)	vitri=sodong-1;
							else	vitri--;
							menutinh(s,sodong,y,maunen,mauchu,mauchon,vitri);
							Beep(500,150);}
		
		
		
		if(checkKey(VK_DOWN))	{if(vitri==sodong-1)	vitri=0;
								else	vitri++;
								menutinh(s,sodong,y,maunen,mauchu,mauchon,vitri);
								Beep(500,150);}
		if(checkKey(VK_ESCAPE))	{
								system("cls");
								aligncenter("BAN MUON THOAT???",7);
								if(khungyesno(23,5))	exit(0);
								else {system("cls"); menutinh(s,sodong,y,maunen,mauchu,mauchon,vitri);	}
							}
	}
}
void copy(int *a, int lena, int *b, int &lenb)
{
	for(int i=0; i<lena; i++)
	{
		b[i]=a[i];
	}
	lenb=lena;
}
int yon(int *a, int len, int x)
{
	for(int i=0;i<len;i++)
	{
		if(x==a[i])	return 1;
	}
	return 0;
}
void xoatrung(int *a, int &len)
{
		for(int i=1; i<len; i++)
		for(int j=0; j<i; j++)
			if(a[j]==a[i])
			{
				xoavitri(a,len,i);
				i--;
				len--;
			}
}
void noimang(int *a,int lena, int *b, int lenb, int *c, int &lenc)
{
	int i=lenc;
	for(int j=0;j<lena;j++,i++)
	{
		c[i]=a[j];
	}
	for(int j=0;j<lenb;j++,i++)
	c[i]=b[j];
	lenc=i;
}
int khungchonhai(int x, int y, string a, string b)
{	
if(checkKey(VK_ESCAPE));
if(checkKey(VK_LEFT)||checkKey(VK_RIGHT));
	chose(x,y,x+30,y+12,2);
	gotoxy(x+10,y+7);	cout<<a;
	gotoxy(x+18,y+7);	cout<<b;
	int chon=0;
	chose(x+16,y+6,x+b.size()+18,y+8,1);
		Beep(400,100);
		Sleep(100);
		Beep(800,200);
	while(getch()!=13)
	{	
		if(checkKey(VK_LEFT)||checkKey(VK_RIGHT))	{	if(chon==0)	{chon=1;
												chose(x+8,y+6,x+a.size()+10,y+8,1);
												chose(x+16,y+6,x+b.size()+18,y+8,0);
												Beep(500,150);
												}
									else 		{chon=0;
												chose(x+16,y+6,x+b.size()+18,y+8,1);
												chose(x+8,y+6,x+a.size()+10,y+8,0);
												Beep(500,150);}									
											}
		if(checkKey(VK_ESCAPE))		{chon=-1;break;}
	}
	gotoxy(x+30, y+17);
	return chon;	
}
void warning(string s,int x, int y)
{
	int tem=0;
	string te;
	chunhat(x,y,15,30,1,0);
	chose(x,y,x+30,y+15,2);
	gotoxy(x,y+7-s.size()/25);
	for(int i=0;i<s.size()/25+1;i++)
	{
		te=s.substr(tem,25);
		aligncenter(te,wherey()+1);
//		gotoxy(0,wherey()+1);
		tem+=25;
	}
}
int so_ki_tu_giong(char *a, char *b)
{
	for(int i=0; i<strlen(a) || i<strlen(b); i++)
	{
		if(a[i]!=b[i])	return i;
	}
}
int strinstr(string a, string b)
{
	int i= a.find(b), j= b.find(a);
	if(i<a.size()||j<b.size())	return 1;
	else return 0;
}
int linestrinstr(string a, string b)
{
	int i = a.find(b);
	if(i<a.size())
	{
		if(i==0 && a[i+b.size()]==','||a[i+b.size()]=='\0')	return 1;
		if(a[i-1]==' ' && a[i-2]==',' && a[i+b.size()]==','||a[i+b.size()]=='\0')	return 1;
	}
	return 0;
}
char* xoa_khoang_trang_thua(char *a);
int likenode(string a, string b)
{
	char *hb=strtok(&b[0],",.");
	while(hb!=NULL)
	{
		//if(hb[0]==' ')	xoavitrichuoi(hb,0);
		xoa_khoang_trang_thua(hb);
		char *ha=strtok(&a[0],",.");
		while(ha!=NULL)
		{
		//	if(ha[0]==' ')	xoavitrichuoi(ha,0);
		xoa_khoang_trang_thua(ha);
			if(strcmp(ha,hb)==0)	return 1;
			ha=strtok(NULL,",.");
		}
		hb=strtok(NULL,",.");
	}
	return 0;
}
int mean(string a, string b)
{
	if(likenode(a,b)||likenode(b,a))	return 1;
	return 0;
}
void chenvitrichuoi(char *a, int x, char n)
{
	for(int i=strlen(a); i>x; i--)
	{
		a[i]=a[i-1];
	}
	a[x]=n;
}
void xoavitrichuoi(char *a, int x)
{
	for(int i=x; i<strlen(a); i++)
	{
		a[i]=a[i+1];
	}
	a[strlen(a)-1]=='\0';
}
void editstr(char a[100], int len)
{	if(checkKey(VK_LEFT));
	if(checkKey(VK_RIGHT));
	int tamx = wherex(), tamy=wherey();

	int i,j=strlen(a); i=j;
	char temp;
	if(len < strlen(a))
	for(int k = j -len; k <j; k++)
				{
					cout<<a[k];
				}
	else
	cout<<a;
	if(checkKey(VK_BACK));
	while(temp!=13)
	{
		if(checkKey(VK_LEFT) || checkKey(VK_RIGHT) || checkKey(VK_DOWN) || checkKey(VK_UP) || checkKey(VK_DELETE) || checkKey(VK_ESCAPE))	break;
		fflush(stdin);
		temp=getch();
		if(checkKey(VK_BACK) && i>0){
									if(i<=len)
									{
									  gotoxy(wherex()-1,wherey());
									  cout<<" ";
									  gotoxy(wherex()-1,wherey());
									  a[i]='\0';
									  if(i>0)
									  i--;
									  a[j--]='\0';
									}
									else
									{
										a[i]='\0';
										i--;
									  	a[j--]='\0';
										gotoxy(tamx,tamy);
										for(int k = j -len; k <j; k++)
										{
										cout<<a[k];
										}
										
									}
									}
		

		
		if(temp>='a'&&temp<='z' || temp >=33&& temp<=64|| temp==' ' || temp==',' && temp !=13)
		{
			if(i<len)
			{
			a[i]=temp; j++,i++;
			cout<<temp;
			}
			else
			{
				a[i]=temp;
				i++, j++;
			//	cout<<"in";
				gotoxy(tamx,tamy);
				for(int k = j -len; k <j; k++)
				{
					cout<<a[k];
				}
			}
			
		}
	}
	a[i]='\0';
	gotoxy(tamx, tamy);
	if(len<strlen(a))
	for(int k = 0; k<len; k++)
				{
					cout<<a[k];
				}
	else cout<<a;
	
}
void pchose(int x0, int y0, int x1, int y1, int nga3x1, int nga3x2, int nga3x3, int nga3x4, int loai)
{
	int wx=wherex(),wy=wherey();
	if(loai==1)
	{
		//ve 4 goc
		gotoxy(x0,y0);	 cout<<char(218);
		gotoxy(x0,y1);	cout<<char(192);
		gotoxy(x1,y0);	cout<<char(191);
		gotoxy(x1,y1);	cout<<char(217);
		
		for(int i=x0+1; i<x1; i++)
		{
			if(i==x0+nga3x1|| i==x0+nga3x2||i==x0+nga3x3||i==x0+nga3x4)
				{
					
				gotoxy(i,y0);	cout<<char(194); // ve net nga 3 ben tren
				gotoxy(i,y1);	cout<<char(193); //ve net nga 3 ben duoi
				}
			else
			{
				gotoxy(i,y0);	cout<<char(196);//ve duong ngang
				gotoxy(i,y1);	cout<<char(196);
			}
		}
		
		for(int i=y0+1; i<y1; i++)
		{
			//ve  duong doc
			gotoxy(x0+nga3x1,i); cout<<char(179);
			gotoxy(x0+nga3x2,i);cout<<char(179);
			gotoxy(x0+nga3x3,i);cout<<char(179);
			gotoxy(x0+nga3x4,i);cout<<char(179);
			
			//ve 2 duong vien
			gotoxy(x0,i);	cout<<char(179);
			gotoxy(x1,i);	cout<<char(179);
		}
	}
	if(loai==0)
	{	
		for(int i=x0; i<=x1; i++)
		{
			gotoxy(i,y0);
			cout<<" ";
			gotoxy(i,y1);
			cout<<" ";
		}
		
		for(int i=y0; i<=y1; i++)
		{
			gotoxy(x0,i);
			cout<<" ";
			gotoxy(x1,i);
			cout<<" ";
		}
		for(int i=y0+1; i<y1; i++)
		{//xoa 4 duong ben trong
			gotoxy(x0+nga3x1,i); cout<<" ";
			gotoxy(x0+nga3x2,i);cout<<" ";
			gotoxy(x0,i);	cout<<" ";
			gotoxy(x1,i);	cout<<" ";
			gotoxy(x0+nga3x3,i);cout<<" ";
			gotoxy(x0+nga3x4,i);cout<<" ";
		}
	}
	gotoxy(wx,wy);
}

void dsach(int x, int y, int wei, int hei, string s[], int soluong, int chon)
{
//	chunhat(x,y,hei,wei,0,0);
	gotoxy(x,y+1);
	for(int i=0;i<hei-1; i++)
	{

		gotoxy(x,wherey()); cout<<"                           ";//alignleft(s[i],x+1);
		gotoxy(x, wherey()+1);
		textbk(0);
	}
	gotoxy(x,y); cout<<"                           ";
	gotoxy(x,y+hei); cout<<"                         ";
	if(soluong>0)
	{chose(x,y,x+wei+4,y+soluong+1,1);
	gotoxy(x,y+1);
	for(int i=0;i<soluong; i++)
	{
		if(i==chon) textbk(9);
		else textbk(0);
		alignleft(s[i],x+1);
		gotoxy(x+1, wherey()+1);
		textbk(0);
	}
	}
}

char* xoa_khoang_trang_thua(char *a)
{
	int i,k=strlen(a);
	for( i=0; i<strlen(a); i++)
	{
		if(a[i]!=' ')	break;
		xoavitrichuoi(a,0);
		i--;
	}
	
	for(int j=0;j<strlen(a);j++)
	{
		if(a[j]==' '&&a[j-1]==' ')
		{
			xoavitrichuoi(a,j);
			j--;
		}
		
	}
	if(a[strlen(a)-1]==' ')	xoavitrichuoi(a,strlen(a)-1);
	if(a[strlen(a)]<65||a[strlen(a)]>122||(a[strlen(a)]>=91&&a[strlen(a)]<=96))	a[strlen(a)]=='\0';
	return a;
}
void xoademao()
{
	if(checkKey(VK_UP));
	if(checkKey(VK_DOWN));
	if(checkKey(VK_RIGHT));
	if(checkKey(VK_LEFT));
	if(checkKey(VK_ESCAPE));
}

void copychuoi(char *a, char *b)
{
	int max=strlen(a);
	if(max<strlen(b))	max=strlen(b);
	for(int i=0; i<max; i++)
	{
		if(i<strlen(b))	a[i]=b[i];
		else if(a[i]-1=='\n')	a[i-1]='\0'; 
		else a[i]='\0';
	}
	if(a[max-1]<'a'||a[max-1]>'z')	a[max-1]='\0';
	else
	a[max]='\0';
}
int khungync(int x, int y)
{	
	chose(x,y,x+30,y+14,2);
	gotoxy(x+9,y+7);	cout<<" YES ";
	gotoxy(x+17,y+7);	cout<<" NO  ";
	gotoxy(x+12,y+11);	cout<<"CANCLE";
	int chon=0;
	chose(x+16,y+6,x+22,y+8,1);
		Beep(400,100);
		Sleep(100);
		Beep(800,200);
	while(getch()!=13)
	{	char t=getch();
		if(checkKey(VK_LEFT)||checkKey(VK_RIGHT))	{	if(chon==0)	{chon=1;
												chose(x+8,y+6,x+14,y+8,1);
												chose(x+16,y+6,x+22,y+8,0);
												chose(x+11,y+10,x+18,y+12,0);
												Beep(500,150);
												}
									else 		{chon=0;
												chose(x+16,y+6,x+22,y+8,1);
												chose(x+8,y+6,x+14,y+8,0);
												chose(x+11,y+10,x+18,y+12,0);
												Beep(500,150);}									
											}
		if(checkKey(VK_UP)||checkKey(VK_DOWN))
												{
													if(chon!=3)
														{
															chon=3;
															chose(x+8,y+6,x+14,y+8,0);
															chose(x+16,y+6,x+22,y+8,0);
															chose(x+11,y+10,x+18,y+12,2);
														}
													else
														{
															chon=0;
															chose(x+8,y+6,x+14,y+8,0);
															chose(x+16,y+6,x+22,y+8,1);
															chose(x+11,y+10,x+18,y+12,0);
														}
												}
	}
	gotoxy(x+30, y+17);
	return chon;	
}
void resizeConsole(int h, int w)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console,&r);
	MoveWindow(console,r.left,r.top,w,h,TRUE);
}

void dinh_dang_chuoi(char a[100], int kieu)
{
	if(kieu==0)
	{
		for(int i=0; i<strlen(a); i++)
		{
			a[i]=tolower(a[i]);
		}
	}
	else if(kieu==1)
	{
		for(int i=0; i<strlen(a); i++)
		{
			a[i]=toupper(a[i]);
		}
	}
	else if(kieu==2)
	{
	a[0] = toupper(a[0]);
		for(int i=1; i<strlen(a); i++)
		{
			if(a[i-1]==' ')	a[i]=toupper(a[i]);
			else	a[i]=tolower(a[i]);
		}
	}
}

void in_text_box(char a[100], int len)
{
	int j = strlen(a);
	if(len < strlen(a))
	for(int k = 0; k <len; k++)
				{
					cout<<a[k];
				}
	else
	cout<<a;
}
void SetColor(WORD color){
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void hinhChuNhat(int x, int y, int width, int height){
    gotoxy(x,y);
    printf("%c",218); // goc tren trai
    for(int i=1;i<width;i++){
        gotoxy(x+i,y);
        printf("%c",196);
    }
    gotoxy(x+width,y); // goc tren phai
    printf("%c",191);
    for(int i = 1;i<height;i++){
        gotoxy(x,y+i);
        printf("%c",179);
    }
    gotoxy(x,y+height); // goc duoi trai
    printf("%c",192);
    for(int i=1;i<width;i++){
        gotoxy(x+i,y+height);
        printf("%c",196);
    }
    gotoxy(x+width,y+height);  // goc duoi phai
    printf("%c",217);
    for(int i =1;i<height;i++){
        gotoxy(x+width,y+i);
        printf("%c",179);
    } 
}

