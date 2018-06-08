//#include "sinhvien.h"
//#include"cauhoi.h"

	char ml[20];
	char mthi[20];
	int masv;
	int sch;
	int tg;
	NODEPTR P;
//int ktidch(char mamh[]){
//	for(int i=0;i<ds.n;i++){
//		if(strcmp(mamh,ds.nodes[i].mamh)==0)
//			return i;
//	}
//	return -1;
//}

//bool ktmasv(NODEPTREE root,int masv, char malop){
//	
//	if(p!=NULL){	
//		
//	if(p->info.dssv!=NULL)	duyetSV(p->info.dssv);cout<<endl<<endl;
//		duyetTree(p->left);
//		duyetTree(p->right);
//	}
//	return false;
//}
void ktch(int sch){
//	if(sch==i)
}
void thitracnghiem(){
	start:;
	cout<<"Nhap ma lop thi";
	fflush(stdin);
	gets(ml);
	NODEPTREE q	=timkiem(tree,ml);
	if(q==NULL) goto start;
	
	
	begin:;
	cout<<"Nhap mon thi";
	fflush(stdin);
	gets(mthi);
	int temp = ktidch(mthi);
	if(temp==-1) goto begin;
	
	
	hehe:;
	cout<<"Nhap ma sv";
	cin>>masv;
	bool flag = false;

	

	
	while(q->info.dssv->next!=NULL){
		cout<<"MSSV: "<<q->info.dssv->sv.mssv<<endl;
		if(q->info.dssv->sv.mssv == masv){
			flag = true;
			break;	
		}	
		cout<<"Dia chi con tro sinh vien: "<<q->info.dssv<<endl;
		q->info.dssv = q->info.dssv->next;
				
	}
	if(flag == false) goto hehe;
	
//	if(!ktmasv(P,masv)) {
//		
//		goto hehe;
//		
//	}
	
	
	cout<<"Nhap so cau hoi thi";
	cin>>sch;
	
	
	cout<<"Nhap thoi gian thi(phut)";
	cin>>tg;
	
	
		
}
