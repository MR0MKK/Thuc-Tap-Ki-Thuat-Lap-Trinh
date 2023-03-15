#include "input_output.cpp"

void DisplayThem(list&ds){
	SV sv;
	veKhung1();
	int x=110;	int w=50;
	int y=12;	int h=3;
	int counter =1;	
	for(int i=0;;){		
		int key; 
		key = getch();
		Move(key,&counter,10);
		Minibox1();
		ColorAdd(counter,x,y,w,h);
		if(key==13){
				switch(counter){
					case 1://Ten		
						gotoxy(x+1,(y+(counter-1)*6)+1);
						setName(sv.ten,x+1,(y+(counter-1)*6)+1);
						break;
					break;
					case 2://Lop
						gotoxy(x+1,(y+(counter-1)*6)+1);
						setClass(sv.lop);
						cout<<sv.lop<<"       ";
						break;
					case 3://NgaySinh
						gotoxy(x+1,(y+(counter-1)*6)+1);
						EnterNgaySinh(sv.NgaySinh, 0, x+1, y+(counter-1)*6+1);
						getDate(sv.NgaySinh,&sv.birth.dd,&sv.birth.mm,&sv.birth.yy);
						break;	
					case 4://ID				
						gotoxy(x+1,(y+(counter-1)*6)+1);
						setId(sv.id,sv.NgaySinh);
						break;
					case 5:
						gotoxy(x-19+(counter-5)*25+7, y+25 );
						setGender(sv.gender);
						cout<<"Gender: "<<sv.gender;
						break;
					case 6:	
						fflush(stdin);
						EnterDiem(&sv.toan,x-19+(counter-5)*25+7, y+25);	
						break;
					case 7:		
						fflush(stdin);	
						EnterDiem(&sv.ly,x-19+(counter-5)*25+7, y+25);				
						break;
					case 8:		
						fflush(stdin);
						EnterDiem(&sv.hoa,x-19+(counter-5)*25+7, y+25);				
						break;
					case 10: 
						Clear(80,4,130,42);	 return;		
					case 9:
						tinhDTB(sv);   xeploai(sv);	Clear(80,4,130,42);
						node *p = new node;
			     	    p = createNode(sv);
			     	    slsv++;
			     	    InsertAtLast(ds,p);
						XuatFile(ds);			
						return;
						}
					}
			}
}

void DisplaySua(list&ds){
	FixBox();
	int x=110;	int w=50;
	int y=12;	int h=3;
	string xid;
	cin >> xid;
	for (node *temp=ds.Head;temp!=NULL;temp=temp->next){
		if(xid==temp->data.id){
			 	veKhung1();
				int counter =1;	
				gotoxy(111,31);
				textcolor(7);
				cout <<xid;
				for(int i=0;;){		
					int key; 
					key = getch();
			  		switch(key){
						case 72: counter = counter -1;
							if(counter ==0) counter = 10;
							if(counter ==4) counter =3;
							break; 
						case 80: counter = counter +1;
							if(counter ==11) counter = 1;
							if(counter ==4) counter =5;
							break;
						}
					Minibox1();
					ColorAdd(counter,x,y,w,h);
					if(key==13){
							switch(counter){
								case 1://Ten		
									gotoxy(x+1,(y+(counter-1)*6)+1);
									setName(temp->data.ten,x+1,(y+(counter-1)*6)+1);
									break;
								break;
								case 2://Lop
									gotoxy(x+1,(y+(counter-1)*6)+1);
									setClass(temp->data.lop);
									cout<<temp->data.lop<<"       ";
									break;
								case 3://NgaySinh
									gotoxy(x+1,(y+(counter-1)*6)+1);
									EnterNgaySinh(temp->data.NgaySinh, strlen(temp->data.NgaySinh), x+1, y+(counter-1)*6+1);
									getDate(temp->data.NgaySinh,&temp->data.birth.dd,&temp->data.birth.mm,&temp->data.birth.yy);
									break;	
								case 5:
									gotoxy(x-19+(counter-5)*25+7, y+25 );
									setGender(temp->data.gender);
									cout<<"Gender: "<<temp->data.gender;
									break;
								case 6:		
									gotoxy(x-19+(counter-5)*25+7, y+25 );
									fflush(stdin);
									cin >> temp->data.toan;
									break;
								
								case 7:		
									gotoxy(x-21+(counter-5)*25+7, y+25 );
									fflush(stdin);					
									cin >> temp->data.ly;
										break;
								case 8:		
									gotoxy(x-20+(counter-5)*25+7, y+25 );
									fflush(stdin);
									cin >> temp->data.hoa;
									break;
								case 10: 
									Clear(80,4,130,42);Clear(32,25,80,20);	 return;		
								case 9:
									tinhDTB(temp->data);   xeploai(temp->data);	Clear(80,4,130,42);
//									Clear(32,28,73,35);
									Clear(32,25,80,20);
									XuatFile(ds);			
									return;
							}
				}
			}
		}
	}
	gotoxy(33,37); cout << "Khong co hoc sinh co ID nay";
	Sleep(1000);
	Clear(32,25,80,20);
	return;

}
void Xoa(list&ds){
	string sth;
	cin>>sth;
	int count=0;
	for(node *temp=a.Head;temp!=NULL;temp=temp->next){
		count++;
		if(atoi(temp->data.id)==sth){
			DeleteSV(ds,count);
		}
	}
}
