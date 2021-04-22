#include<stdio.h>

//dinh nghia 1 node
struct node 
{ 
  int info;   
  struct node* next; 
}; 

typedef struct node Node;

typedef struct node* NodePTR; //con tro node

//danh sach lien ket don, chi quan tam den node dau tien

//khoi tao danh sach
void init(NodePTR &phead )
{
	phead = NULL;
}

//kiem tra danh sach rong ???
int isEmpty(NodePTR phead)
{
	return (phead == NULL);
}

//tao 1 node, tra ve con tro toi node do
NodePTR createNode(int x )
{
	//cap phat 1 vung nho moi,chua x
	NodePTR p = new Node;  //trong ngon c chuan, su dung ham malloc
	
	p->info = x;
	p->next = NULL;
	
	return p;
}

void insertFirst(NodePTR &phead, int x)
{
	//tao 1 node chua x
	NodePTR p=createNode(x);
	
	//chen vao dau
	p->next = phead;
	//node dau tien chinh la node moi them
	phead = p;
}

void insertLast(NodePTR &phead, int x )
{
	NodePTR p= createNode(x);
	if(phead == NULL)
		phead= p;
	else{
			NodePTR tam= phead;
			
			while(tam->next !=NULL)
				tam=tam->next;
			tam->next=p;			
		}
	
}

void inputList(NodePTR &phead)
{
//	init(phead);
	int x;
	do {
		printf("\n nhap vao gia tri phan tu:");
		scanf("%d", &x);
		if(x!=0) {
//			insertFirst(phead, x);
		insertLast(phead, x);
		}
	} while(x!=0);
}

void printList (NodePTR phead)
{
	
	printf("\n");
	
	while (phead != NULL)
	{
		printf(" %d  ",phead->info );
		phead = phead->next;
		
	}
}

//chen y sau x
int insertAfterX(NodePTR &phead, int x, int y)
{
	NodePTR nodeX = phead;
	
	//tim node chua x
	while (nodeX!= NULL && nodeX->info != x)
//	while (nodeX!= NULL && nodeX->next->info != x)	//chen truoc x
		nodeX = nodeX->next;
	if (nodeX == NULL)
		return 0; //tra ve 0, ko tim thay x, ko chen sau x dc
				
	//chen y sau x
	NodePTR newnode = createNode(y);
	newnode->next = nodeX->next;
	nodeX->next = newnode;
	
	return 1;
	
}

//dem so nut cua ds
int count(NodePTR phead)
{
	int dem=0;
	for ( NodePTR i=phead; i!=NULL; i=i->next)
		dem++;
	return dem;
}

//gia tri cua node thu X
int infoX(NodePTR phead, int x)
{
	NodePTR nodeX=phead;
	int i=0;
	for (i; i<count(phead)  ; i++)
		if(i==x)
			return nodeX->info;
		else 
			nodeX=nodeX->next;
	return 0;
	
}
// tim max
int findMax(NodePTR phead)
{
	NodePTR tam=phead->next;
	int m=phead->info;
	while(tam !=NULL)
	{
		if(m< tam->info) m=tam->info;
		tam = tam->next;
	}
	return m;
}

// tim min
int findMin(NodePTR phead)
{
	NodePTR tam=phead->next;
	int m=phead->info;
	while(tam !=NULL)
	{
		if(m> tam->info) m=tam->info;
		tam = tam->next;
	}
	return m;
}
//xoa phan tu chua k
int deleteK(NodePTR &phead, int k)
{
	
	NodePTR tam=phead; 
	
	if (phead == NULL)
		return 0;
	if (phead->info == k){
		
		NodePTR p = phead;
		phead = phead->next;
		
		delete p;	
	}
		
	while (tam->next!= NULL && tam->next->info != k)
		tam=tam->next;
		
	if (tam->next == NULL)
		return 0;
		
	NodePTR p = tam->next; // p tro toi nut chua k
	tam ->next = p->next;
	
	//delete p;
	
	return 1;
}

int main ()
{
	//khai bao 1 danh sach
	NodePTR pHead;
	
	//khoi tao danh sach
	init(pHead);
	
//	insertFirst(pHead, 1);
//	insertFirst(pHead, 2);
//	insertFirst(pHead, 3);
//	printList(pHead);
//	insertFirst(pHead, 4);
	inputList(pHead);
	printList(pHead);
	printf("\n so phan tu cua danh sach: %d", count(pHead));

//	bool ok = insertAfterX(pHead, 7, 9);
//	
//	if (ok) {
//		printList(pHead);	
//	}
//	else
//		printf("\nchen ko thanh cong !");
//	printf("\n so phan tu cua danh sach: %d", count(pHead));
//	
//	printf( deleteK(pHead, 5)?  "\n da xoa 1 phan tu co gia tri 5 trong mang!!!" : "\n khong co phan tu 5 trong mang!!!");
//	printList(pHead);
//	
//	printf("\n\n gia tri cua node thu 3 là %d", infoX(pHead, 3));
//	printf("\n gia tri max là %d", findMax(pHead));
//	printf("\n gia tri min là %d", findMin(pHead));

	int ok = deleteK(pHead, 4);
	if (ok)
		printList(pHead);
	else
		printf("khong tim thay phan tu can xoa");
	return 0;
}