#include "PreDraw.h"
#include <cstdlib>
void InManHinh();
void Intro();
void MenuBigBox();
void Minibox1();
void veKhung1();
void FixBox();

void Move(int key,int *counter,int last){
  	switch(key){
		case 72:case 75: *counter = *counter -1;
			if(*counter ==0) *counter = last;
			break; 
		case 80:case 77: *counter =*counter +1;
			if(*counter ==last+1) *counter = 1;
			break;
		default : break;
		}
}
void colorMenu(string A[],int counter,int x,int y,int num){
	MenuDoc(A,x,y,30,2,7,num);
	if(counter >=1 && counter <=num+1){
		Box("double",x,y+(counter-1)*4,30,2,5);
		textcolor(11);
		gotoxy(x+1,(y+(counter-1)*4)+1);
		cout << A[counter-1];
	}
}
void ColorAdd(int counter,int x,int y,int w,int h){
	if(counter>=1 && counter <=4){
		Box("double",x,y+6*(counter-1),w,h,5 );
	}
	else if(counter>=5 && counter <=8){
		Box("double", x-20+(counter-5)*25 , y+24 , 15 , 2 ,5);
	}
	else if(counter ==9){
		Box("double", 115, y+28 , 10 , 2 ,5);
	}
	else if(counter ==10){
		Box("double", 145, y+28 , 10 , 2 ,5);	
	}	
}
void Intro(){
	textcolor(5);
	gotoxy(85,1);
	cout << "Chuong trinh quan ly hoc vien" << endl;
	gotoxy(3,44);
	cout << "Author: Duong Quang Minh" << endl;
	gotoxy(3,46);
	cout << "Bao Dam An Toan Thong Tin" << endl;
}
void HelpKey()
{
	int x = 3; int y=18;
	gotoxy(x, y); textcolor(12); cout <<"[" << '\x18'<<"]"; textcolor(14); cout << " UP";
	gotoxy(x, y+2); textcolor(12);	cout <<"[" << '\x19'<<"]"; textcolor(14); cout << " DOWN";
	gotoxy(x+10, y); textcolor(12); printf("[Enter]"); textcolor(14); cout << " ENTER";
	gotoxy(x+10, y+2); textcolor(12); printf("[Enter]x2"); textcolor(14); cout << " BACK";

}
void MenuBigBox()
{
	fullscreen();
	int i;
	Box("double",0,0,210,48,7);
	for(int i=0;i<210;i++){ 
		gotoxy(i,3);printf("%c",'\xCD'); 
  	}
	for(i=3;i<=48;i++){  
  		gotoxy(30,i);printf("%c",'\xBA'); 
  	}
	for(int i=1;i<30;i++){ 
		gotoxy(i,15);printf("%c",'\xC4'); 
  	}  	
  	gotoxy(30,3);	cout << char(203);
  	gotoxy(30,48);	cout << char(midB);
  	gotoxy(0,3);	cout << char(midL);
  	gotoxy(210,3);	cout << char(midR);
	Intro();
	HelpKey();

}
void Minibox1(){
		int x=110;	int w=50;
		int y=12;	int h=3;
		Box("thick",80,4,110,40,8);
		for(int i=0;i<=3;i++){
			Box("double",x,y+6*i,w,h,8 );
		}
		for(int i=0;i<=3;i++){
			Box("double", x-20+i*25 , y+24 , 15 , 2 ,8);
		}
		Box("double", 145, y+28 , 10 , 2 ,8);
		Box("double", 115, y+28 , 10 , 2 ,8);
}

void veKhung1(){
		
		int x=110;	int w=50;
		int y=12;	int h=3;
		Minibox1();

 		//-------------------------------------------------
		textcolor( 12 );
		gotoxy( 120 , 9 );
 		cout << "NHAP DU LIEU CUA HOC VIEN";
 		
 		textcolor(7);
		gotoxy(x-13,y+1);
		cout << "1. Ho Ten ";
 		gotoxy(x-13,y+7);
 		cout << "2. Ma lop ";	
 		gotoxy(x-13,y+13);
		cout << "3. Ngay sinh ";
 		gotoxy(x-13,y+19);
 		cout << "4. Ma SV ";	 	
 			
		gotoxy(116,41);
		cout << "OK";	
		gotoxy(146,41);
		cout << "LEAVE";
 		
 		textcolor(8); 	
 		gotoxy(x+1,y+1);
		cout << "Nguyen Van A";
		gotoxy(x+1,y+7);
		cout << "xxxxxx";
		gotoxy(x+1,y+13);
		cout << "DD/MM/YYYY";
 		gotoxy(x+1,y+19);
 		cout << "xxxxxxx";

 		gotoxy(x-19,y+25);
 		cout << "5.Gender";

 		gotoxy(x+6,y+25);
 		cout << "6.TOAN";
 		gotoxy(x+31,y+25);
 		cout << "7.LY";
 		gotoxy(x+56,y+25);
		cout << "8.HOA";
}
void FixBox(){
	Box("thick",32,28,40,6,8);
	gotoxy(35,31); 
	textcolor(7);
	cout << "Nhap ID can sua:  ";
}
void FindBox(){
	Box("thick",125,4,60,6,8);
	gotoxy(128,7); 
	textcolor(7);
	cout << "Nhap thong tin nguoi can tim:  ";
}
void TKbox(string title,int SL,string arr[],string arr1[]){
	int a,b,c,d,e,f;
	a=125;b=140;c=155;d=170;e=185;f=200;
	Box("thin",135,5,20,3,12);
	gotoxy(137,6);cout << title;
	int h=10+4*SL;
	SetColor(3);
	Box("thin",82,10,119,h-10,3);
	
	for(int l=0;l<8;l++){
		if(l==1){gotoxy(89,12);cout<<arr[l];
		}
		else{gotoxy(84+l*15,12);cout<<arr[l];
		}
			
	}
	for(int i=10;i<=h;i++){
  		gotoxy(88,i);printf("%c",'\xB3'); 
		gotoxy(110,i);printf("%c",'\xB3');
  		gotoxy(a,i);printf("%c",'\xB3'); 
		gotoxy(b,i);printf("%c",'\xB3');
  		gotoxy(c,i);printf("%c",'\xB3'); 
		gotoxy(d,i);printf("%c",'\xB3');
		gotoxy(e,i);printf("%c",'\xB3');

  	}
	for(int j=1;j<=SL-1;j++){
		for(int k=82;k<=201;k++){
			switch(k){
				case 88:case 110:case 125 :case 140:case 155:case 170:case 185: gotoxy(k,10+4*j);cout<<'\xC5';break;//chu thap
				case 82:gotoxy(k,10+4*j);cout<<'\xC3';break;//phai
				case 201:gotoxy(k,10+4*j);cout<<'\xB4';break;//trai
				default: gotoxy(k,10+4*j);cout<<'\xC4';//ngang
			}
		}
		gotoxy(84,12+j*4);cout <<j;
		gotoxy(90,12+j*4);cout <<arr1[j-1];
	} 
  	gotoxy(88,10);cout <<'\xC2';gotoxy(110,10);cout <<'\xC2';gotoxy(a,10);cout <<'\xC2';gotoxy(b,10);cout <<'\xC2';gotoxy(c,10);cout <<'\xC2';gotoxy(d,10);cout <<'\xC2';gotoxy(e,10);cout <<'\xC2';
  	gotoxy(88,h);cout <<'\xC1';gotoxy(110,h);cout <<'\xC1';gotoxy(a,h);cout <<'\xC1';gotoxy(b,h);cout <<'\xC1';gotoxy(c,h);cout <<'\xC1';gotoxy(d,h);cout <<'\xC1';gotoxy(e,h);cout <<'\xC1';
}
void Doc(int x,int y,int h){
	for(;y<=h;y++){
		if(y%5==0&&y!=10){
			gotoxy(x,y);printf("%c",'\xC5');
			gotoxy(x-4,y); cout << (h-y)*4 << "%";  
		}else{
			gotoxy(x,y);printf("%c",'\xB3'); 
		}	
  	}
}
void Ngang(int x,int y,int w,string arr[]){
	int i=0;
	for(;x<=w;x++){
  		if(x%13==11){
			gotoxy(x,y);printf("%c",'\xC5'); 
			gotoxy(x-1,y+1);cout <<arr[i];i++;
		}else{
			gotoxy(x,y);printf("%c",'\xC4');  
		}
		
  	}	
}
void TKbieudo(string arr[],float arr1[]){
	Doc(90,14,40);
	Ngang(90,40,160,arr);
	gotoxy(90,40); cout <<'\xC0';
	gotoxy(90,13); cout <<'\x18';
	gotoxy(160,40); cout <<'>';	
	gotoxy(88,12); cout <<"(%)";
	gotoxy(160,41); cout <<"Hoc luc";
	int a=90;	int i=0;
	for(;a<=160;a++){
		if(a%13==11){
			float tomau=40-0.2*arr1[i];
			gotoxy(a-2,tomau-1);textcolor(7);cout << arr1[i]<<"%";
			for(;tomau<40;tomau++){
				SetColor(i+3);
				gotoxy(a-1,tomau); cout << '\xB2';
				gotoxy(a,tomau); cout << '\xB2';
				gotoxy(a+1,tomau); cout << '\xB2';
			}
			i++;
		}
			
	}
}
