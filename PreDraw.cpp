#include "PreDraw.h"

void SetColor (int color)
{
	HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor,color);
}

void gotoxy(int x,int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
	COORD position = {x,y} ;
	SetConsoleCursorPosition(hStdout,position ) ;
}

void textcolor( int x )
{
	HANDLE handle;
	handle = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( handle , x );
}

void hidePointer(){
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &ConCurInf);
}

void showPointer(){
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = TRUE;
    SetConsoleCursorInfo(hOut, &ConCurInf);
}

void Box(string type,int x,int y,int w,int h,int color){
	char BotL, BotR, TopL, TopR, ColR, ColL, LineT, LineB;
	if(type =="thick" ){
			BotL = BotR = TopL = TopR = ColR = ColL = BoxF;
			LineT = BoxF;
			LineB = BoxF;
	}
	else if(type =="thin" ){
			BotL= thinBL;TopR=thinTR;
			LineT=LineB=thinRow;
			ColR=ColL=thinCol;
			TopL=thinTL;BotR=thinBR;
		}
	else if(type == "double"){
			BotL= doubleBL;TopR=doubleTR;
			LineT=LineB=doubleRow;
			ColR=ColL=doubleCol;
			TopL=doubleTL;BotR=doubleBR;
	} else {
			BotL = BotR = TopL = TopR = ColR = ColL = LineT = LineB = ' ';
	}
	
	SetColor(color);
	for(int ix=x; ix<=x+w ; ix++){
		gotoxy(ix,y);
		cout << ColL;
		gotoxy(ix,y+h);
		cout << ColR;
	}
	for(int iy=y; iy<=y+h ; iy++){
		gotoxy(x,iy);
		cout << LineT ;
		gotoxy(x+w,iy);
		cout << LineB;
	}

	gotoxy(x,y); cout<<TopL;
	gotoxy(x+w,y); cout<<TopR;
	gotoxy(x,y+h); cout<<BotR;
	gotoxy(x+w,y+h); cout<<BotL;
}


void fullscreen(){
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd,SW_SHOWMAXIMIZED);
}

void MenuDoc(string ds[],int x,int y,int w,int h,int color,int number){
	int localx=x; int localy=y;
	textcolor(7);
	for(int i=0;i<=number ;i++){
		gotoxy(localx,localy);
		Box("thin",localx,localy,w,h,color);
		gotoxy(localx+1,localy+1);
		cout <<	ds[i] ;
		localy+=4;
	}
	
}
void DisplayList(string ds[],int x,int y,int number){
	textcolor(7);
	for(int i=0;i<=number;i++){
		gotoxy(x,y+i);
		cout <<	ds[i] ;
		}
}
void Clear(int x,int y,int maxx,int maxy){
	int i, j, local_x, local_y;
	local_x=x, local_y=y;
	gotoxy(x,y);
	for (int i=1;i<=maxy;i++)
		for (j=1;j<=maxx;j++)
		{
			printf(" ");
			if (j==maxx) gotoxy(local_x,++local_y);
		}
	gotoxy(x,y);
}

void END(){
	system("cls");int x=80;int y=30;char s1[] = "END";
	for (int i = 0; i < 3; i++)
	{
		gotoxy(x;y+i);
		Sleep(200);printf("%c", s1[i]);
	}

}


