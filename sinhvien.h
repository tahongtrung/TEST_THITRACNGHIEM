#include<cstring>
using namespace std;

// dinh nghia kieu du lieu sinh vien

struct sinhvien{
	int mssv;
	char ho[30];
	char ten[20];
	char phai[5];
};
sinhvien sv;
// dinh nghia node co kieu data la sinhvien
typedef struct nodesv{
	sinhvien sv;
	struct nodesv* next;
};

typedef nodesv* NODEPTR;
NODEPTR First;
// cap phat 1 nut cho danh sach
NODEPTR newNode(){
	NODEPTR p;
	p = (NODEPTR)malloc(sizeof(struct nodesv));
	return p;
}
struct lop{
	char malop[20];
	char tenlop[20];
	NODEPTR dssv;
};
struct node{
	int key;
	lop info;
	struct node* left;
	struct node* right;
	
};
typedef struct node *NODEPTREE;
NODEPTREE tree;

void khoitaoCay(NODEPTREE &root){
	root=NULL;
}
NODEPTREE newNodeTree(){
	NODEPTREE p;
	p=new node;
	p->info.dssv=NULL;
	return p;
}
NODEPTREE timkiem(NODEPTREE root,char m[]){
	NODEPTREE p;
	p=root;
	while(p!=NULL){
		if(strcmp(p->info.malop,m)!=0) p=p->left;
		else return p;
	}
	p=root;
		while(p!=NULL){
		if(strcmp(p->info.malop,m)!=0) p=p->right;
		else return p;
	}
	return NULL;
}

// khoi tao danh sach lien ket
void initialize(NODEPTR &First){
	First = NULL;
	
}
// nhap/tao danh sach sinh vien
/*void Insert_First(PTR &First, int x)
{
   NODEPTR p;
   p = new node;
   p->info = x;
   p->next = First;
   First = p;
}*/
void duyetSV(NODEPTR First){
	NODEPTR p;
	int stt = 0;
	p = First;
	if(p == NULL){
		cout<<"Khong co sinh vien trong danh sach!";
	}
	while(p!=NULL){
		cout<<++stt<<"  "<<p->sv.mssv<<"  "<<p->sv.ho<<"  "<<p->sv.ten<<endl;
		p=p->next;
	}
	
}
//NLR Preorder
void duyetTree(NODEPTREE p){
	if(p!=NULL){
	
		cout<<p->key<<endl;
		cout<<p->info.malop<<endl;
		cout<<p->info.tenlop<<endl;
	if(p->info.dssv!=NULL)	duyetSV(p->info.dssv);cout<<endl<<endl;
		duyetTree(p->left);
		duyetTree(p->right);
	}
}
void nhapSV(NODEPTR &First){
	TextColor(58);
while(!0)
	{	
	First =NULL;
	NODEPTR Last,p;
	sinhvien sv;
	char maso[5],malopsv[20];
	
//	cout<<"Chon lop ban muon nhap: "<<endl;
star:;
	cout<<"Vui long nhap ma lop: "<<endl;
	fflush(stdin);
	gets(malopsv);
	if(malopsv[0]=='\0') break;
	NODEPTREE q	=timkiem(tree,malopsv);
	// duyet ds lop qua 1 lan neu ma lop trung thi lay con tro tro toi ds  lop*ptr = first
	if(q==NULL) goto star;
	//getch();
	
	cout<<"MSSV: ";
	cin>>maso;
	sv.mssv = atoi(maso);
	while(sv.mssv != 0){
		cout<<"HO SV"<<endl;
		fflush(stdin);
		gets(sv.ho);
		cout<<"TEN SV: "<<endl;
		fflush(stdin);
		gets(sv.ten);
		cout<<"GIOI TINH: "<<endl;
		fflush(stdin);
		gets(sv.phai);
		p = newNode();
		p->sv = sv;
		if(First == NULL){
			First = p;
		}else{
			Last->next = p;
		}
		Last = p;
		p->next = NULL;
		
		cout<<"MSSV: "<<endl;
		fflush(stdin);
		gets(maso);
		sv.mssv = atoi(maso);
		
	}
	end:;
	q->info.dssv = First;
	}
	duyetTree(tree);
	getch();
}
// duyet/in ra danh sach sv

