struct Birth{
	int dd;
	int mm;
	int yy;
};
struct sinhvien {
	char gender[10];
	char id[10];
	char lop[10];
	char ten[30];
	char NgaySinh[25];
	float toan;  
	float ly;
	float hoa;
	float diemTB;
	char hocluc[10];
	Birth birth;
};

typedef struct sinhvien SV;
struct node{
    SV data;
    node * next;
};
struct list{
    node *Head;
    node *Tail;
    int count;
};

//struct NODE{
//	SV data;
//	NODE *pLeft;
//	NODE *pRight;
//};
//typedef NODE *tree;
//
//void KhoiTaoCay(tree&t){
//	t=NULL;
//}

