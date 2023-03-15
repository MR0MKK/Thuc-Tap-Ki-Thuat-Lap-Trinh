#include "SinhVien.cpp"
#include "input_output.cpp"
int KMP(string,string);
void TuanTuID();
void TuanTuTen();
void TuanTuNS();
void TuanTuTB();
void ifNot(list a,int num){
	if(num==0){
		gotoxy(138,10);
		textcolor(12);
		cout << "KHONG CO HOC VIEN NHU VAY";
		Sleep(1000);
		Clear(125,4,61,7);
	}else{
		OutConsole(a,num-1);
	}
}
int KMP(string text, string pattern)
{
    int m = text.length();
    int n = pattern.length();
//	if(m<n) return 0;
    for (int i = 0, j = 0; i < m; i++)
    {
        if (text[i] == pattern[j])
        {
            if (++j == n) {
                return 1;
            }
        }
        else if (j > 0)
        {
            j = 0;
            i--;    
        }
    }
    return 0;
}
bool SS1(string a,string b){
	if(a==b)
		return 1;
	else return 0;
}
bool SS2(float a,float b){
	if(a==b)
		return 1;
	else return 0;
}
void TuanTuID(){
	string sth;
	cin>>sth;
	list a;KhoiTao(a);
	int num=0;
	for (node *temp=ds.Head;temp!=NULL;temp=temp->next){
		if(SS1(sth,removeTail(temp->data.id))){
			InsertAtLast(a,CopyNode(*temp));
			num++;
		}
	}
	ifNot(a,num);
}

void TuanTuTen(){
	char sth[30];
	setName(sth,159,7);
	list a;
	int num=0;
	KhoiTao(a);
	for (node *temp=ds.Head;temp!=NULL;temp=temp->next){
//		if(SS1(sth,removeTail(temp->data.ten))){		
//			InsertAtLast(a,CopyNode(*temp));
//			num++;
//		}
		if(KMP(removeTail(temp->data.ten),sth)){		
			InsertAtLast(a,CopyNode(*temp));
			num++;
		}
	}
	ifNot(a,num);

}
void TuanTuNS(){
	char sth[30];
	EnterNgaySinh(sth,0,159,7);
	list a;
	int num=0;
	KhoiTao(a);
	for (node *temp=ds.Head;temp!=NULL;temp=temp->next){
		if(SS1(removeTail(sth),removeTail(temp->data.NgaySinh))){
			InsertAtLast(a,CopyNode(*temp));
			num++;
		}
	}
	ifNot(a,num);
}
void TuanTuTB(){
	float sth;
	cin>>sth;
	list a;
	int num=0;
	KhoiTao(a);
	for (node *temp=ds.Head;temp!=NULL;temp=temp->next){
		if(SS2(sth,temp->data.diemTB)){
			InsertAtLast(a,CopyNode(*temp));
			num++;
		}
	}
	ifNot(a,num);
}

