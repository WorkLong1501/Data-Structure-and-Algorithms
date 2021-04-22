#include <stdio.h>

typedef struct benhVien
{
	int stt;
	char hoTen[30];
	int tuoi;
}BV;

typedef struct node{
	BV info;
	struct	node* next;
}Node;

typedef struct node* stack;

void nhap1(BV &h, int n)
{
	h.stt=n;
	printf("\n nhap ho ten benh nhan:");
	fflush (stdin);
	gets(h.hoTen);
	printf("\n nhap tuoi :");
	scanf("%d", &h.tuoi);	
}

int isEmpty(stack ds)
{
	return (ds == NULL);
}

void push(stack &ds, BV h)
{
	node* p= new node;
	p->info = h;
	p->next = ds;
	ds = p;	
}

void nhapNhieu( stack &ds)
{
	int n=1;
	while (n <= 3)
	{
		BV h;
		nhap1(h,n);
		push(ds, h);
		n++;
	}
}

int pop(stack &ds, BV &k)
{
	node* tam = ds;
	k= tam->info ;
	ds=ds->next;
	
	delete tam;
	return 1;
}

void xuat1(BV h)
{
	printf("%2d %10s %-2d\n", h.stt, h.hoTen, h.tuoi);
}

void xuatNhieu(stack ds, BV h)
{
	printf("\n danh sach benh nhan\n\n");
	while (! isEmpty(ds))
	{
		BV k;
		pop(ds,k);
		xuat1(k);
	}
}

int main()
{
	BV Hop;
	stack ds;
	ds = NULL;
	
	nhapNhieu(ds);
	xuatNhieu(ds,Hop);
	
	return 0;
}