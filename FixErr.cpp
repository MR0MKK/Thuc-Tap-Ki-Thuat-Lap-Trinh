#include "SinhVien.cpp"
#include <time.h>
//#include "test1.cpp"
void EnterNgaySinh(char*,int,int,int);
void setName(char*,int,int);
void setGender(char*);
void setGender(char*);
void setClass(char*);
void setId(char*,char*);
void EnterDiem(float *diem,int x,int y){
	gotoxy(x,y);
	cin >> *diem;
	if(*diem<0 && *diem >10) *diem = 0;
}
void EnterNgaySinh(char *xau, int i, int x, int y){
	gotoxy(x,y);
	char c;
	do{
	fflush(stdin);
	c=getch();
	if (i >= 0 && c >= '0'&&c <= '9'){
			if (i == 0){
				if (c >= '0'&&c <= '3'){
					xau[i++] = c; printf("%c", c);
					continue;
				}
				if (c >= '4'&&c <= '9'){
					char a = '0';
					xau[i++] = a; printf("0");
					xau[i++] = c; printf("%c", c);
				}
			}
			if (i == 1){
				if (xau[i - 1] == '3' && c >= '0'&&c <= '1'){
					xau[i++] = c; printf("%c", c);
					continue;
				}
				if (((xau[i - 1] == '1') || (xau[i - 1] == '2')) && (c >= '0') && (c <= '9')){
					xau[i++] = c; printf("%c", c);
				}
				if ((xau[i - 1] == '0') && (c > '0') && (c <= '9')){
					xau[i++] = c; printf("%c", c);
				}
			}
			if (i != 4 && i != 3 && i != 2 && i != 1){
				if (i >= 0 && i < 10){
					xau[i++] = c; printf("%c", c);
				}
				continue;
			}
			if (i == 3){
				if (c >= '0'&&c <= '1'){
					xau[i++] = c; printf("%c", c);
					continue;
				}
				if (c >= '2'&&c <= '9'){
					char a = '0';
					xau[i++] = a; printf("0");
					xau[i++] = c; printf("%c", c);
				}
			}
			if (i == 4){
				if (xau[i - 1] == '1' && c >= '0'&&c <= '2'){
					xau[i++] = c; printf("%c", c);
				}
				if (xau[i - 1] == '0' && c > '0'&&c <= '9'){
					xau[i++] = c; printf("%c", c);
				}
			}
			if (i == 2 || i == 5){
				char a = '/'; xau[i++] = a; printf("/");
			}
		}
} while (c != 13);
	if (xau[i - 1] == ' ')
		i--;
	if (c == 13)y++;
	xau[i++] = '\0';
}
void getDate(char*xau,int *d,int *m,int *y){
	char date[20];
	// Ngay
	strncpy(date,xau+0,2);
	date[2]='\0';
	*d=atoi(date);
	// Thang
	strncpy(date,xau+3,2);
	date[2]='\0';
	*m=atoi(date);
	// Nam
	strncpy(date,xau+6,4);
	date[4]='\0';
	*y=atoi(date);
}
void setName(char *xau, int x, int y){
	gotoxy(x,y);
	char c;
	int n;
	int i=0;
	do{
		n=getch(); 
		if(((n>='a' && n<='z') || (n>='A' && n<='Z') || (n==32))&& i<x)
		{
			cout<<char(n); 
			xau[i++]=n;
		}
		else if(n=='\b' && i>0) 
		{
			cout<<"\b \b"; 
			xau[--i]=0;
		}
	}while(n!=13);
	xau[i]='\0';
	int num = strlen(xau);
    if (xau[0]!= 32){					
        if (xau[0]>='a' && xau[0]<='z'){
        	xau[0] -= 32;
		}
    }
	for(int i=1;i<n;i++){		
    	if (xau[i] == 32){
            if (xau[i+1]>='a' && xau[i+1] <='z'){
				xau[i+1] -= 32;
            }
        }
	}
	gotoxy(x,y);
	cout << xau<<"       ";
}
void setGender(char *xau){
	Box("double",89,39,10,3,12);
	string gioitinh[2]={"Nam","Nu"};
	int counter =1;
	DisplayList(gioitinh,90,40,1);
	for(int i=0;;){
		int key; 
		key = getch();
  		switch(key){
			case 72: counter = counter -1;
				if(counter ==0) counter = 2;
				break; 
			case 80: counter = counter +1;
				if(counter ==3) counter = 1;
				break;
      	 	case 13:
      	 		Clear(89,39,11,4);
      	 		gotoxy(91,37);
      	 		textcolor(7);
				switch(counter){
					case 1:
						strcpy(xau,"Nam");
						break;
					case 2:
						strcpy(xau,"Nu");
						break;
				}
      	 		return;
			}	
		DisplayList(gioitinh,90,40,1);
		if(counter >=1 && counter <=2){
			textcolor(11);
			gotoxy(90,40+counter-1);
			cout <<gioitinh[counter-1];
		}	
	}
	
}

void setClass(char *xau){
	Box("double",162,17,15,8,5);
	string lop[7]={"CNTT\0","BDATTT\0","ANHTTT\0","PTDL\0","KTPM\0","HTTT\0","MTTTDL\0"};
	int counter =1;
	DisplayList(lop,163,18,6);
	for(int i=0;;){
		int key; 
		key = getch();
  		switch(key){
			case 72: counter = counter -1;
				if(counter ==0) counter = 7;
				break; 
			case 80: counter = counter +1;
				if(counter ==8) counter = 1;
				break;
			}	
		DisplayList(lop,163,18,6);
		if(counter >=1 && counter <=7){
			textcolor(11);
			gotoxy(163,18+counter-1);
			cout << lop[counter-1];}
		if(key==13){
			Clear(162,17,16,9);
      	 	gotoxy(111,19);
      	 	textcolor(7);
			switch(counter){
				case 1:
					strcpy(xau,"CNTT");break;
				case 2:
					strcpy(xau,"BDATTT");break;
				case 3:
					strcpy(xau,"ANHTTT");break;
				case 4:
					strcpy(xau,"PTDL");break;
				case 5:
					strcpy(xau,"KTMT");break;
				case 6:
					strcpy(xau,"HTTT");break;
				case 7:
					strcpy(xau,"MTT-TTDL");break;	
			}
			return;
		}	

	}
}

void setId(char *xau,char *data){
	int i=0;int n=0; char str[20];
	int no=atoi(data);
	for(int i=0;i<strlen(data);++i){
		if(isdigit(data[i])){
			str[n]=data[i];
			n++;
			str[n]='\0';
		}
	}
	
	int no2 = 15 + rand() % (65 + 1 - 15);
	int no1 = 10 + rand() % (20 + 1 - 10);
//	int num=atoi(str); 
	srand((int)time(0));  
//	cout << rand();
    int id = rand()*no2*no1;
	if(id>10000000)	id=id/10;
	itoa(id,xau,10);
	gotoxy(111,31);
	cout << xau;
}


bool whiteSpace(char c){
	return c==' ' || c=='\t' || c== '\n';
}
string removeTail(char*s){
	int i=strlen(s)-1;
	while(whiteSpace(s[i])){
		s[i]='\0';
		i--;
	}
	return s;
}
string removeHead(char*s) {
	int counter = 0;
	int i;
	for(i = 0; i < strlen(s); i++) {
		if(whiteSpace(s[i])) {
			counter++;
		} else {
			break;
		}
	}
	for(i = 0; i <= strlen(s) - counter; i++) {
		s[i] = s[i + counter];
	}
}
