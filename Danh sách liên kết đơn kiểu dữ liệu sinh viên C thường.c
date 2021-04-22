#include<stdio.h>
#include<string.h>



//dih nghia kieu du lieu sinh vien
typedef struct SinhVien{
	char maSV[10];
	char hoTen[40];
	float dtb;
}SV;

//dinh nghia danh sach lien ket don
typedef struct node{
	SV info;
	struct node* next;
}node;

// dinh nghia node pointer
typedef struct node* nodePTR;

//nhap 1 sinh vien
void nhap1SV(SV &x)
{
	printf("\n nhap ma sinh vien : ");
	fflush(stdin);
	gets(x.maSV);
	printf("\n nhap ten sinh vien : ");
	fflush(stdin);
	gets(x.hoTen);
	printf("\n nhap diem trung binh cua sinh vien : ");
	fflush(stdin);
	scanf("%f", &x.dtb);
	printf("\n=======================================\n");
}

//xuat 1 sinh vien
void xuat1SV(SV x)
{
	printf("\n%6s %-10s %-3.3f ", x.maSV,x.hoTen,x.dtb);
}

//tao danh sach lien ket don
void init(nodePTR &p)
{
	p = NULL;
}

//tao node co du lieu la x
nodePTR createNode(SV x)
{
	// cap phat vùng nho moi
	nodePTR p= new node;
	
	p->info =x;
	p->next =NULL;
	
}

//chen vao dau tien cach 1
void insertFisrt(nodePTR &p,SV x)
{
	//tao node pointer tamp
	nodePTR tamp= createNode(x);
	//moc node pointer tamp vao p
	tamp->next = p;
	// di chuyen p ve node dau tien
	p= tamp;
}
//chen dau tien cach 2
//void insertFisrt2(nodePTR &phead, SV x)
//{
//	nodePTR tamp= createNode(x);
//	nodePTR p= phead;
//	tamp->next = p;
//}

//chen cuoi cung
void insertLast(nodePTR &phead, SV x)
{
	nodePTR tamp=createNode(x);
	if(phead==NULL)
		phead= tamp;
	else 
	{
		nodePTR p= phead;
		while(p->next != NULL)
			p=p->next;
		p->next = tamp;	
	}		
}

//nhap danh sach SV
void insertList(nodePTR &phead)
{
	int dem=2;
	while( dem-->=0)
	{
		SV x;
		nhap1SV(x);
	//	insertFisrt(phead,x);
	//	insertFisrt2(phead,x);
		insertLast(phead, x);		
		}	
}

void sapXep(nodePTR &phead);
//in danh sach SV ra man hinh cach 1
void printList(nodePTR phead)
{
//	sapXep(phead);
	printf("\n Danh Sach SV\n");
	while(phead != NULL)
	{
		xuat1SV(phead->info);
		phead = phead->next;
	}
	printf("\n-------------------------------\n");
}
//in ra danh sach sinh vien cach 2
void printList2(nodePTR phead)
{
	printf("\n Danh Sach SV\n");
	for(phead; phead != NULL; phead = phead->next)
		xuat1SV(phead->info);	
	printf("\n-------------------------------\n");
}

//xuat Sv co DTB > 5
void xuatSVLonHon5(nodePTR phead)
{
	int dem=0;
	printf("\n ----- SV co Dtb > 5 la:\n");
	while(phead != NULL)
	{
		if(phead->info.dtb > 5)
			{
				xuat1SV(phead->info);
				dem++;
			}
		phead=phead->next;
	}
	if(dem==0) printf("Khong ton tai !!!!");
	printf("\n-------------------------------\n");
}

//tim sinh vien co ma la x
void timSV(nodePTR phead, char x[])
{
	int dem=0;// gioi han so sinh vien nhap vao
	printf("\n ----- SV co ma la \"%s\" la:\n",x);	
	while(phead != NULL)
	{
		if(strcmp(phead->info.maSV,x)==0) 
		{
			xuat1SV(phead->info);dem++;
		}
		phead= phead->next;
	}
	if(dem==0) printf("Khong ton tai !!!!");
	printf("\n-------------------------------\n");	
}

// hoan vi node
void swap (SV &a, SV &b)
{
	SV t = a;
	a=b;
	b=t;
}

// sort interchange diem trung binh
void sapXep(nodePTR &phead)
{
//	printf("\n------ sau khi sap xep:\n");
	nodePTR i= phead;
	while(i !=NULL)
	{
		nodePTR j= phead;
		for(j; j!=NULL; j=j->next)
		{
			if(j->info.dtb > i->info.dtb) 
				swap(j->info,i->info);
		}
		i=i->next;
	}	
}

//chen sinh vien y sau sinh vien co ma la maTam
void insertAfter(nodePTR phead)
{
	SV y;// khai bao bien sinh vien la y
	char maTam[10];// khai bao bien chua ma la maTam
	printf("\n nhap vao ma sinh vien can chen sau:");fflush(stdin);
	gets(maTam);// nhap maTam
	
	int dem=0;
	nodePTR x=phead;
	while (x!= NULL)
	{
		if(strcmp((x->info.maSV), maTam) == 0) //so sanh tim sinh vien co ma nhu da nhap
		{
			printf("\n da tim thay sinh vien co ma la \"%s\" !", maTam);
			nhap1SV(y);dem++;
			nodePTR Y = createNode(y);
			Y->next = x->next;  // móc node pointer Y vao node pointer sau x
			x->next = Y; // móc node pointer x vao node Pointer Y
		}
		x= x->next;
	}
	if(dem==0) printf("\n khong co sinh vien co ma la \"%s\"!!!\n ",maTam);
	else 	printList(phead);
	printf("\n-------------------------------\n");	

}

//xoa sinh vien dau danh sach
int deleteFisrt(nodePTR &phead)
{
	if(phead == NULL)	return 0;
	
	nodePTR tam= phead;
	phead = phead->next;
	delete tam;
	return 1;
}

//xoa sinh vien cuoi danh sach
//xoa all list
//xoa sv co ma la xxx


int main()
{
	nodePTR pHead;
	init(pHead);
	char c[5]="haha";
	
	insertList(pHead);
//	printList(pHead);
//	printList2(pHead);	
	int menu=0;
	do{
	
//	xuatSVLonHon5(pHead);
//	timSV(pHead,c);
	sapXep(pHead);
	printList(pHead);
	
	insertAfter(pHead);
	
	bool ok=deleteFisrt(pHead);
	printf((ok)? "\n da xoa thanh cong SV dau tien!!!" : "\n khong the thuc hien xoa phan tu dau tien!!" );
	if(ok) printList(pHead);
	
	
	printf("\n ban muon lam tiep khong?\n 1.co \n 0.thoat\n");
	scanf("%d", &menu);
	}while(menu !=0);
	return 0;
}