#pragma once

#include "FixErr.cpp"
int slsv=0;
void InManHinh(list&ds,int a){
	Box("thin",40,4,160,2,8);
	int x1=47;int y1=7;
    node *p=ds.Head;
	int count =0;int sety;
	int x=40;int y=4;
		gotoxy(x+5,5); cout << "STT";
		gotoxy(x+22,5); cout << "LOP";
		gotoxy(x+36,5); cout << "MA SV";
		gotoxy(x+57,5); cout << "HO TEN";
		gotoxy(x+80,5); cout << "NGAY SINH";
		gotoxy(x+101,5); cout << "GIOI TINH";
		gotoxy(x+122,5); cout << "DIEM TB";
		gotoxy(x+143,5); cout << "XEP LOAI";

	for(int i=1;i<a+2;i++){//+++++++
		gotoxy(x1,y1+count*2);
		printf("%-10d %-14s  %-17s  %-25s  %-20s  %-18s   %-18.02f  %-15s  \n", count+1,p->data.lop,p->data.id,p->data.ten,p->data.NgaySinh, p->data.gender,p->data.diemTB ,p->data.hocluc)	;
		p=p->next;
		count++;
		sety=y+2*i;
		veNgang(x+1,y+2+2*i,159);veDoc(x,sety+1);
		gotoxy(x,sety); cout<<char(195);			gotoxy(200,y+2*i); cout<<char(180);			
		veCong(x+15,sety);	veDoc(x+15,sety+1);
		veCong(x+30,sety);	veDoc(x+30,sety+1);
		veCong(x+45,sety);	veDoc(x+45,sety+1);
		veCong(x+75,sety);	veDoc(x+75,sety+1);
		veCong(x+95,sety);	veDoc(x+95,sety+1);
		veCong(x+115,sety);	veDoc(x+115,sety+1);
		veCong(x+135,sety);	veDoc(x+135,sety+1);
								veDoc(x+160,sety+1);
	}
	int bottomy=y+(a+2)*2;
	gotoxy(x,bottomy); cout<<char(192);gotoxy(200,bottomy); cout<<char(217);
	gotoxy(x+15,bottomy); cout << char(193);
	gotoxy(x+30,bottomy); cout << char(193);
	gotoxy(x+45,bottomy); cout << char(193);
	gotoxy(x+75,bottomy); cout << char(193);
	gotoxy(x+95,bottomy); cout << char(193);
	gotoxy(x+115,bottomy); cout << char(193);
	gotoxy(x+135,bottomy); cout << char(193);
	
}


void XuatKhungFile(){
	FILE *f1= fopen("dataSinhVien.txt","w");
	fprintf( f1, "          \t\t-----------DANH SÁCH SINH VIÊN-------------\n");
	fprintf(f1, "---------------------------------------------------------------------------------------------\n");
	fprintf(f1, "  LOP     MASV              HOTEN            NGAYSINH   GIOITINH    TOAN     LY     HOA \n");
}
void XuatFile(list &ds){
//	XuatKhungFile();
	int count=0;
	FILE *f1= fopen("dataSinhVien.txt","w");
	for (node *p=ds.Head;p!=NULL;p=p->next)
	{
		fprintf(f1," %-6s  %s  %-25s %-10s  %-8s  %.02f    %.02f    %.02f    \n", p->data.lop,p->data.id,p->data.ten,p->data.NgaySinh, p->data.gender,p->data.toan , p->data.ly,p->data.hoa)	;
		count++;
	}
	fclose(f1);
}
void XuatCon(list &ds){
	int count=0;
	char arr[128];
	int x=47;int y=7;
	for (node *p=ds.Head;p!=NULL;p=p->next)
	{	gotoxy(x,y+count*2);
		printf("%-10d %-14s  %-17s  %-25s  %-20s  %-18s   %-18.02f  %-15s  \n", count+1,p->data.lop,p->data.id,p->data.ten,p->data.NgaySinh, p->data.gender,p->data.diemTB ,p->data.hocluc)	;
		count++;
	}
}
void docFile(list &ds,int *sl) {
	FILE* f2 = fopen("dataSinhVien.txt", "r");
	int i = 0;
	if(f2) {
		for(int i=0;;i++) {
				
			sinhvien sv;
			fscanf(f2, " %6s  %s  %25[^\n] %10s  %8s  %f    %f    %f\n",
			sv.lop, sv.id, sv.ten,sv.NgaySinh ,sv.gender,&sv.toan, &sv.ly, &sv.hoa);
			tinhDTB(sv); 
			xeploai(sv); 
			
			getDate(sv.NgaySinh,&sv.birth.dd,&sv.birth.mm,&sv.birth.yy);
			node *p = new node;
			p = createNode(sv);
			InsertAtLast(ds,p);
			if(feof(f2)) { // thoat chuong trinh
				*sl=i;
				break;
			}
		}
	}
	fclose(f2);
}

void OutConsole(list&a,int num){
	system("cls");
	textcolor(3);
//	XuatCon(a);
	InManHinh(a,num);
	deleteall(a);
	gotoxy(10,10); cout <<"Press any key to return";	getch();
	system("cls");	
	MenuBigBox();	
}
void InSV(){
	system("cls");
	deleteall(ds);
	docFile(ds,&slsv);
	textcolor(3);
//	XuatCon(ds);
	InManHinh(ds,slsv);
	gotoxy(10,10); cout <<"Press any key to return";	getch();
	system("cls");	
	MenuBigBox();	
}
