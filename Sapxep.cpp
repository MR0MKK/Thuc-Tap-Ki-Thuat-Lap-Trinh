#include <sstream>
#include "SinhVien.cpp"
#include "input_output.cpp"
string SapXep2[]=
{ 
	" 1.Theo ma sinh vien" ,
	" 2.Theo ho ten" ,
	" 3.Theo ngay sinh" ,
	" 4.Theo diem trung binh" ,
	" 5.Main Menu"
};
void Swap(node*,node&);
//---------------------------------------
void DisplayNoiBot(int,int);
void IDNoiBot(list&);
void DiemNoiBot(list&);
void BirthNoiBot(list&);
void TenNoiBot(list&);
//----------------------------------------
void DisplayChon(int,int);
void IDChon(list&);
void DiemChon(list&);
void BirthChon(list&);
void TenChon(list&);
//--------------------------------------
void DisplayNoiBot(int x,int y){
	int counter =1;			
	list newds=ds;
	Box("thick",80,4,40,25,8);
	MenuDoc(SapXep2,x,y,30,2,7,4);
	Box("double",x,y+(counter-1)*4,30,2,5);
	for(int i=0;;){		
		int key; 
		key = getch();
		Move(key,&counter,5);
		if(key==13) {
			switch(counter){
				case 1:	IDNoiBot(newds);	OutConsole(newds,slsv);	 return;
				case 2: TenNoiBot(newds);	OutConsole(newds,slsv);	 return;
				case 3:	BirthNoiBot(newds);	OutConsole(newds,slsv);	 return;
				case 4:	DiemNoiBot(newds);	OutConsole(newds,slsv);  return;
				case 5: Clear(80,4,80,40);	 return;	
				}
			}
			colorMenu(SapXep2,counter,x,y,4);
		}
}
void DisplayChon(int x,int y){
	int counter =1;		
	list newds=ds;
	Box("thick",80,4,40,25,8);
	MenuDoc(SapXep2,x,y,30,2,7,4);
	Box("double",x,y+(counter-1)*4,30,2,5);
	for(int i=0;;){		
		int key; 
		key = getch();
		Move(key,&counter,5);	
		if(key==13) {
			int localx=105;int localy=10;
			switch(counter){
				case 1: DiemChon(newds);	OutConsole(newds,slsv);	return;
				case 2: TenChon(newds);		OutConsole(newds,slsv);	return;
				case 3: BirthChon(newds);	OutConsole(newds,slsv);	return;
				case 4: DiemChon(newds);	OutConsole(newds,slsv);	return;
				case 5: Clear(80,4,80,40);	 return;
				}
			}
			colorMenu(SapXep2,counter,x,y,4);
		}
}
void swapSV(node* node1, node* node2){
	SV temp;
	temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}
bool NameCompare(string sv1,string sv2){
	stringstream ss1(sv1);
	stringstream ss2(sv2);
	string n1[5];string n2[5];
	int i=0, j=0;
	while (ss1 >> n1[i]) 
        i++;
    while (ss2 >> n2[j]) 
    	j++;
    int x = 0;
    while(x==0&&i>=0&&j>=0){
    	if(j==0||i==0)
    	i=j=0;
    	x = strcmp(n1[i].c_str(), n2[j].c_str());
    	i--;j--;
		}
	if(x > 0)
	return 1;
	else return 0;
	}
//--------Sap xep noi bot----------
//------------Theo ID--------------//

void IDNoiBot(list&a){
 	for(node *temp=a.Head;temp!=NULL;temp=temp->next){
		for(node *temp2=temp->next;temp2!=NULL;temp2=temp2->next){
			if(atoi(temp->data.id)>atoi(temp2->data.id)){
				swapSV(temp,temp2);
     		}
 		}
 	}
}
//----------Theo ten--------------------/
void TenNoiBot(list&a){
    for(node *temp=a.Head;temp!=NULL;temp=temp->next){
        for(node *temp2=temp->next;temp2!=NULL;temp2=temp2->next){
           //if(strcmp(temp->data.ten,temp2->data.ten)>0){
           if(NameCompare(temp->data.ten,temp2->data.ten)){
				swapSV(temp,temp2);
		   }
        }
    } 
}
//------------Theo Ngay Sinh--------------//
void BirthNoiBot(list&a){
 	for(node *temp=a.Head;temp!=NULL;temp=temp->next){
		for(node *temp2=temp->next;temp2!=NULL;temp2=temp2->next){
			if(temp->data.birth.yy<temp2->data.birth.yy){				
				swapSV(temp,temp2);
			}else if((temp->data.birth.yy==temp2->data.birth.yy)&&(temp->data.birth.mm<temp2->data.birth.mm)){
    			swapSV(temp,temp2);
			}else if((temp->data.birth.yy==temp2->data.birth.yy)&&(temp->data.birth.mm==temp2->data.birth.mm)&&(temp->data.birth.dd<temp2->data.birth.dd)){
				swapSV(temp,temp2);
			}
 		}
 	}
}
//------------Theo diem------------//
void DiemNoiBot(list&a){
 	for(node *temp=a.Head;temp!=NULL;temp=temp->next){
		for(node *temp2=temp->next;temp2!=NULL;temp2=temp2->next){
			if(temp->data.diemTB>temp2->data.diemTB){
				swapSV(temp,temp2);
     		}
 		}
 	}
}
//--------Sap xep chon----------
//---------Theo ID-----------
void IDChon(list&a){
	for(node *temp=a.Head;temp!=NULL;temp=temp->next){
		node *min=temp;
		for(node *temp2=temp->next;temp2!=NULL;temp2=temp2->next){
			if(temp->data.id>temp2->data.id){
				min=temp2;
				swapSV(temp,min);
     		}
 		}
 	}
}
//----------Theo ten-------------
void TenChon(list&a){
    for(node *temp=a.Head;temp!=NULL;temp=temp->next){
        node *min=temp;
		for(node *temp2=temp->next;temp2!=NULL;temp2=temp2->next){
           if(strcmp(temp->data.ten,temp2->data.ten)>0){
           		min=temp2;
				swapSV(temp,temp2);
		   }
        }
    } 
}
//------------Theo Ngay Sinh--------------//
void BirthChon(list&a){
 	for(node *temp=a.Head;temp!=NULL;temp=temp->next){
 		node *min=temp;
		for(node *temp2=temp->next;temp2!=NULL;temp2=temp2->next){
			if((temp->data.birth.yy<temp2->data.birth.yy)||((temp->data.birth.yy==temp2->data.birth.yy)&&(temp->data.birth.mm<temp2->data.birth.mm))||((temp->data.birth.yy==temp2->data.birth.yy)&&(temp->data.birth.mm==temp2->data.birth.mm)&&(temp->data.birth.dd<temp2->data.birth.dd))){				
				min=temp2;
				swapSV(temp,min);
			}
 		}
 	}
}
//---------Theo diem--------------
void DiemChon(list&a){
	for(node *temp=a.Head;temp!=NULL;temp=temp->next){
		node *min=temp;
		for(node *temp2=temp->next;temp2!=NULL;temp2=temp2->next){
			if(temp->data.diemTB>temp2->data.diemTB){
				min=temp2;
				swapSV(temp,min);
     		}
 		}
 	}
}

