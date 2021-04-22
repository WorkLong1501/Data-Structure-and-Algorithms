#include <stdio.h>

//dinh nghia cau truc 1 node
typedef struct node{
	int info;
	struct node* next;
	
}Node;

//dinh nghia stack: truy xuat vao phan tu dau cua ds  ==> quan tam den node dau tien
typedef Node* stack;

//dinh nghia queue
typedef struct tQueue {
	Node * pHead;
	Node *pTail;
}Queue;

//ham: kiem tra stack co rong hay khong
int isEmpty(stack s)
{
	return (s == NULL);
}

// dua pt x vao stack
void push(stack &s, int x)
{
	Node* p= new Node;
	p->info = x;
	
	p->next = s;
	s=p;
}

//lay 1 phan tu ra khoi stack va gan cho bien x
int pop(stack &s, int &x)
{
	Node* p= s;
	x=p->info ;
	s=s->next;
	
	delete p;
	
	return 1;		
}

//chuyen so nguyen n dang thap phan sang nhi phan (luu trong stack s)
void convert(int n, stack &s)
{
	int soDu;
	while (n!= 0){
		soDu = n%2;
		push(s,soDu);
		n=n/2;
	}	
}

void print(stack s)
{
	int k;
	while(!isEmpty(s)){
		pop(s,k);
		printf("%d ", k);
	}
}
	
int main()
{
	stack S;
	S = NULL; //khoi tao stack
	
	int n;
	 
	printf("\n nhap so thap phan: ");
	scanf("%d", &n); 
	
	convert(n, S);
	printf("Dang nhi phan cua %d la:", n);
	print(S);
	
	return 0;
}