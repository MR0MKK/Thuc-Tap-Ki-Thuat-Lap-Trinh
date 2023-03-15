#pragma once
#include <math.h>
#include "Draw.cpp"
#include "KhoiTao.cpp"
#include <fstream>

void KhoiTao(list&);
int KiemTraRong(list);
node* createNode(SV);
void InsertAtLast(list&,node*);
void CopyList(list*,list&);
void DeleteSV(list &,int);
void deleteall(list&);
void tinhDTB(SV &);
void xeploai(SV &);
node* CopyNode(node);

list ds;
int count=0;


void KhoiTao(list &ds){
    ds.Head = NULL;
    ds.Tail = NULL;
}
int KiemTraRong(list ds){
    if (ds.Head == NULL){
        return 1;
    }
    return 0;
}

node* createNode(SV sv)
{
	node* temp = new node();
	temp->next = NULL;
	temp->data = sv  ;
	return temp;
}
void InsetAtFirst(list&ds,node *temp){
    if (ds.Head==NULL) {
        ds.Head=ds.Tail=temp;
    }
	else {
		temp->next=ds.Head;
		ds.Head=temp;
    }	
}
void InsertAtLast(list &ds, node *temp){
    if (ds.Head==NULL) {
        ds.Head=ds.Tail=temp;
    }
    else {
        ds.Tail->next=temp;
        ds.Tail=temp;
    }
}
void DeleteSV(list &ds,int pos){
	node *temp1=ds.Head;
	node *temp2=new node;
	int i=0;
    if(pos == 0)
    	ds.Head=ds.Head->next;
    else if(pos==ds.count) {
        ds.Tail->next = NULL;
    }
    else{
        while(temp1!=NULL && i!= pos-1)  {
            i++;
            temp1=temp1->next;
        }
        temp2 = temp1->next->next;
        temp1->next = temp2;

    }
    ds.count--;
}

node* CopyNode(node temp){
	node* newNode = NULL;
	newNode = new node();
	newNode->data = temp.data;
	newNode->next = NULL;
	return newNode;	
} 
void deleteall(list&ds){
	do  {
		DeleteSV(ds,0);
	}while(ds.Head!=NULL);
}
void tinhDTB(SV &sv) {
    sv.diemTB = round((sv.toan + sv.ly + sv.hoa) / 3 * 100) / 100 ;    
}

void xeploai(SV &sv) {
    if(sv.diemTB >= 9) strcpy(sv.hocluc, "Xuat sac");
    else if(sv.diemTB >= 8) strcpy(sv.hocluc, "Gioi");
    else if(sv.diemTB >= 6.5) strcpy(sv.hocluc, "Kha");
    else if(sv.diemTB >= 5) strcpy(sv.hocluc, "Trung binh");
    else strcpy(sv.hocluc, "Yeu");
}

//void AddTree(tree&t,SV sv){
//	tinhDTB(sv);
//	xeploai(sv);
//	if(t==NULL){
//		NODE *p=new NODE;
//		p->data=sv;
//		p->pRight=NULL;
//		p->pLeft=NULL;
//		t=p;
//	}
//	else{
//		if(t->data.diemTB>sv.diemTB){
//			AddTree(t->pLeft,sv);	
//		}
//		else if(t->data.diemTB<=sv.diemTB){
//			AddTree(t->pRight,sv);	
//		}	
//	}
//}
//void ListToTree(tree&t){
//	node *temp=ds.Head;
//	while(temp!=NULL){
//		AddTree(t,temp->data);
//		temp=temp->next;
//	}
//}
//tree searchSV(tree T,float diem){
//	NODE *P = T;
//	if (T != NULL)
//	{
//		if (T->data.diemTB== diem)
//		{
//			return P;
//
//		}
//		else if (T->data.diemTB>diem)
//		{
//			return searchSV(T->pLeft, diem);
//		}
//		else
//			return searchSV(T->pRight, diem);
//	}
//	else
//		return NULL;
//}
//void prin(tree T){
//	if(T!=NULL){
//		prin(T->pLeft);
//		prin(T->pRight);
//		cout << T->data.toan << "  ";
//	}
//}
