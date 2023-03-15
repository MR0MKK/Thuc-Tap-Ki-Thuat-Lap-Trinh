#include "SinhVien.cpp"
#include "input_output.cpp"
void floatdiem(float A[7][5],float diemtb,int idlop){
	if(diemtb>=9)	A[idlop][0]++;
	else if(diemtb>=8)A[idlop][1]++;
	else if(diemtb>=6.5)A[idlop][2]++;
	else if(diemtb>=5)A[idlop][3]++;
	else A[idlop][4]++;
}
void inDiem(float a[7][5],int arr2[]){
	gotoxy(0,30);
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 7; j++){	
			gotoxy(117+i*15,16+j*4);
			cout << a[j][i];
		}
		cout<<endl;
	}
	for(int k=0;k<7;k++){
		gotoxy(192,16+k*4);
		cout << arr2[k];
	}
}
void TKlop(){

	int count[7]={};
	float diem[7][5]={};
	string TK1[]={"STT","  Lop hoc","Xuat sac","  Gioi","  Kha","Trung Binh","  Yeu","  Tong"};
	string lop[]={"CNTT","BDATTT","ANHTTT","PTDL","KTPM","HTTT","MTTTDL"};
	for (node *temp=ds.Head;temp!=NULL;temp=temp->next){
		string str =removeTail(temp->data.lop);
		if(str==lop[0]){
			count[0]++;
			floatdiem(diem,temp->data.diemTB,0);
		}
		else if(str==lop[1]){
			count[1]++;	
			floatdiem(diem,temp->data.diemTB,1);
		}
		else if(str==lop[2]){
			count[2]++;
			floatdiem(diem,temp->data.diemTB,2);
		}
		else if(str==lop[3]){
			count[3]++;
			floatdiem(diem,temp->data.diemTB,3);
		}
		else if(str==lop[4]){
			count[4]++;
			floatdiem(diem,temp->data.diemTB,4);
		}
		else if(str==lop[5]){
			count[5]++;
			floatdiem(diem,temp->data.diemTB,5);
		}
		else if(str==lop[6]){
			count[6]++;
			floatdiem(diem,temp->data.diemTB,6);
		}
	}	
	TKbox("Thong Ke Theo Lop",8,TK1,lop);	
	inDiem(diem,count);
	getch();
	Clear(80,4,122,41);	 return;
}
void TKdiem1(){
	float count[6]={};
	string hocluc[]={"XS","Gioi","Kha","TB","Yeu"};
	for (node *temp=ds.Head;temp!=NULL;temp=temp->next){
//		string str =removeTail(temp->data.hocluc);
		if(temp->data.diemTB>=9)count[0]++;
		else if(temp->data.diemTB>=8)count[1]++;
		else if(temp->data.diemTB>=6.5)count[2]++;
		else if(temp->data.diemTB>=5)count[3]++;
		else count[4]++;
		count[5]++;
	}
	for(int i=0;i<5;i++){
		count[i]=round(count[i]/count[5] * 100*100) / 100;
	}	
	TKbieudo(hocluc,count);
	gotoxy(120,13);textcolor(6);cout << "Thong Ke Theo Diem Trung Binh";
		
	getch();
	Clear(80,4,90,41);	 return;
}
