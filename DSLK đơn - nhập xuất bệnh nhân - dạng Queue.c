#include<stdio.h>

#define Max 10

typedef struct benhnhan
{
	int stt;
	char hoTen[30];
	int tuoi;
}BN;

typedef struct node {
	BN info;
	struct node * next;
}Node;

//dinh nghia 1 queue -> danh sach lien ket don
typedef struct queue {
	Node *pHead;
	Node *pTail;	
}Queue;

void initQueue(Queue &q) {
	q.pHead = q.pTail = NULL;
}

//kiem tra queue co rong hay khong

int isEmptyQueue(Queue q){
	return (q.pHead == NULL);
}

//them 1 phan tu vao queue -> them vao sau/ duoi cua dslk
void insertQueue(Queue &q, BN x) {
	Node *p = new Node;
	p->info = x;
	p->next = NULL;
	
	if (isEmptyQueue(q)) // truong hop Queue rong
		q.pHead = q.pTail = p;
	else
	{
		q.pTail->next = p;
		q.pTail = p;
	}	
	
}

int removeQueue(Queue &q, BN &x) {
	if (isEmptyQueue(q))
		return 0;
	Node *p = q.pHead;
	
	q.pHead = q.pHead->next;
	
	x = p->info;
	
	delete p;
	
	return 1;
}

void inOne(BN &h, int n)
{
	h.stt=n;
	printf("\n nhap ho ten benh nhan:");
	fflush (stdin);
	gets(h.hoTen);
	printf("\n nhap tuoi :");
	scanf("%d", &h.tuoi);	
}


void inPut(Queue &ds)
{
	int n;
	printf("\n==========------------=============\n");
	printf("Nhap so benh nhan:");
	scanf("%d", &n);
	
	BN x;
	
	for (int i=1; i<=n; i++) {
		inOne(x,i);
		insertQueue(ds, x);
	}
	printf("\n==========------------=============\n");
}

void title()
{
	char a[4] ="STT";char b[10]= "Ho Ten"; char c[5]="Tuoi";
	printf("\n%3s %-10s %2s\n", a,b,c);
}

void outOne(BN h)
{
	printf("%3d %-10s %2d\n", h.stt, h.hoTen, h.tuoi);
}

void outPut(Queue ds)
{
	printf("\n====================================\n");
	printf("\n danh sach benh nhan\n\n");
	title();
	while (ds.pHead != NULL)
	{
		outOne(ds.pHead->info);
		ds.pHead = ds.pHead->next;
	}
	printf("\n====================================\n");
}

int main()
{
	BN H;
	Queue ds;
	initQueue(ds);
	
	inPut(ds);
	outPut(ds);
	
	return 0;
}