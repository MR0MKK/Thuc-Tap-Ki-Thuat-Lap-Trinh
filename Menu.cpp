#include "AddSV.cpp"
#include "Sapxep.cpp"
#include "TimKiem.cpp"
#include "ThongKe.cpp"

void DisplayMenu(int,int,list&ds);

void DisplayCapNhat(int,int,list&ds);
void DisplayThem(list&ds);
void DisplaySua(list&ds);

void DisplayXuat(int,int,list&ds);
void DisplayTimKiem(int,int);
void DisplaySapXep(int,int);
void DisplayThongKe(int,int);

string Menu[]=
{
	" 1: Cap nhat ho so        >",
	" 2: In danh sach          >",
	" 3: Sap xep du lieu       >",
	" 4: Tim kiem thong tin    >", 
	" 5: Thong ke danh sach    >",
	" 6: Thoat"
};
string CapNhat[]=
{
	" 1.Them moi ho so sinh vien",
	" 2.Sua ho so sinh vien",
	" 3.Main Menu" 
};

string SapXep[]=
{ 
	" 1.Sap Xep Noi Bot" ,
	" 2.Sap Xep Chon" ,
	" 3.Main Menu"
};

string TimKiem[]=
{ 
	" 1.Theo ma sinh vien" ,
	" 2.Theo ho ten" ,
	" 3.Theo ngay sinh" ,
	" 4.Theo diem trung binh" ,
	" 5.Main Menu"
};

string ThongKe[]=
{ 
	" 1.Theo diem lop" , 
	" 2.Theo diem trung binh",
	" 3.Main Menu" 
};
//------------------------------------//


//------------------Menu----------------
void DisplayMenu(int x,int y,list&ds){ 
	docFile(ds,&slsv);

	hidePointer();
	int counter =1;
	DisplayList(Menu,x,y,5);
	
	for(int i=0;;){
		int key; 
		key = getch();
		Move(key,&counter,6);
      	 	if(key ==13){
      	 		int localx= 50; int localy=5;
				switch(counter){
					case 1: DisplayCapNhat(35,6,ds); break;
					//gotoxy(localx,localy);ListToTree(T); prin(T);break;
					case 2: gotoxy(localx,localy);	DisplayXuat(35,6,ds);	 break;
					case 3: gotoxy(localx,localy);	DisplaySapXep(35,6);break;
					case 4: gotoxy(localx,localy);	DisplayTimKiem(35,6); break;
					case 5: gotoxy(localx,localy);	DisplayThongKe(35,6); break;
					case 6: END();	exit(0);
					}
			}
		DisplayList(Menu,x,y,5);
		if(counter >=1 && counter <=6){
			textcolor(11);
			gotoxy(x,y+counter-1);
			cout << Menu[counter-1];
		}

	}
}

//------------Chuc nang 1---------------------


void DisplayCapNhat(int x,int y,list&ds){
	int counter =1;			
	int localx= 100; int localy=5;
	Box("thick",32,4,40,20,8);
	MenuDoc(CapNhat,x,y,30,2,7,2);
//	Box("double",x,y+(counter-1)*4,30,2,5);
	for(int i=0;;){		
		int key; 
		key = getch();
		Move(key,&counter,3);
		if(key==13){
				switch(counter){
					case 1: gotoxy(localx,localy);	DisplayThem(ds); break;
					case 2: gotoxy(localx,localy);	DisplaySua(ds); break;
					case 3: Clear(31,4,80,30);	 return;
				}
			}
		colorMenu(CapNhat,counter,x,y,2);
		}
}

void DisplayXuat(int x,int y,list&ds){
	int counter =1;			
	InSV(); return;
}


void DisplaySapXep(int x,int y){
	int counter =1;			
	list newds=ds;
	Box("thick",32,4,40,15,8);
	MenuDoc(SapXep,x,y,30,2,7,2);
	for(int i=0;;){		
		int key; 
		key = getch();
		Move(key,&counter,3);
		if(key==13){
			switch(counter){
				case 1: DisplayNoiBot(85,7);	 break;
				case 2:	DisplayChon(85,7);	     break;
				case 3:	Clear(31,4,80,40);		 return;
				}
			Box("thick",32,4,40,15,8);
			}
		colorMenu(SapXep,counter,x,y,2);
		DisplayList(Menu,3,5,5);
	}		
}

void DisplayTimKiem(int x,int y){
	int counter =1;					
	Box("thick",32,4,40,25,8);
	MenuDoc(TimKiem,x,y,30,2,7,4);
	for(int i=0;;){		
		int key; 
		key = getch();
		Move(key,&counter,5);
		if(key==13){
				if(counter!=5) FindBox();
				switch(counter){
					case 1:  TuanTuID();	break;
					case 2:  TuanTuTen(); 	break;
					case 3:  TuanTuNS(); break;
					case 4:  TuanTuTB(); break;
					case 5:  Clear(31,4,80,40);	 return;			
				}
				Box("thick",32,4,40,25,8);
				DisplayList(Menu,3,5,5);
			}
			colorMenu(TimKiem,counter,x,y,4);
	}	
}


void DisplayThongKe(int x,int y){
	int counter =1;			
	Box("thick",32,4,40,20,8);
	MenuDoc(ThongKe,x,y,30,2,7,2);
	for(int i=0;;){		
		int key; 
		key = getch();
		Move(key,&counter,3);
		if(key==13){
			switch(counter){
				case 1: TKlop(); break;
				case 2: TKdiem1();break;
				//TKdiem(); 
				case 3: Clear(31,4,80,30); return;
				}
			}
			colorMenu(ThongKe,counter,x,y,2);
	}		
}



