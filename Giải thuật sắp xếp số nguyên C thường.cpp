#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void nhapMangNgauNhien(int a[], int r)
{
	srand(time (0));
    for(int i = 0; i < r; i++ )
	{
        a[i] = rand()%20;
        printf("Rand %d is %d\n",i, a[i]);

    } 
}

void xuatMang(int a[], int n)
{
	
	printf("mang mot chieu la : \n");
	for(int i=0;i<n;i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n ---------------------------------\n");	
}
void swap(int &a,int &b)
{
	int tamp=a; a=b; b=tamp;
}

void bubbleSort(int a[], int n)
{
	for (int i=0; i< n-1; i++)
		for(int j=n-1; j> i; j--)
		{
			if(a[j-1] > a[j]) swap(a[j-1], a[j]);
		}
}

void interchangeSort(int a[], int n)
{
	for (int i=0; i<n-1; i++)
		for(int j=i+1; j<n;j++)
			if(a[i]  > a[j]) swap (a[i],a[j]);
}

void selectionSort(int a[],int n)
{
	for(int i=0; i<n-1 ; i++)
	{
		int vtmin = i;
		for (int j= i+1; j<n ; j++)
			if(a[j] < a[vtmin] ) vtmin = j;
		swap(a[i], a[vtmin]);
	}
}

void insertionSort(int a[], int n)
{
	 int pos, x;
	 for(int i=1; i<n;i++)
	{
		int x = a[i]; pos = i-1; // xét vi tri i tro ve truoc
		while ( pos >=0 && a[pos] > x)
		{
			a[pos +1 ] = a[pos];
			pos--;
		}
		a[pos +1 ] =x;
	}
}
void QuickSort(int a[], int left, int right)
{
	int i,j,x;
	i=left;
	j=right;
	x=a[(left+right)/2];
	do{
		while(a[i]< x) i++;
		while(a[j]> x) j--;
		if( i<=j ) 
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
		 
	}while(i<j);
	if( left<j ) QuickSort(a, left, j);
	if( right>i ) QuickSort(a, i, right);
}
int main ()
{
	int a[100];
	int n=15;
	nhapMangNgauNhien(a,n);
	printf("\n ---------------------------------\n");
	xuatMang(a,n);
	int chon;
	do{
		printf("\n ---------------^^----------------\n");
		printf("1: selection sort\n"); 
		printf("2: bubble sort\n"); 
		printf("3: interchange sort\n"); 
		printf("4: insertion sort\n");   
		printf("5: Quick Sort\n");
		printf("0: Thoat\n"); 
		printf("\n ---------------^^----------------\n");
		fflush(stdin);
		printf("Hay chon cong viec:"); scanf("%d", &chon); 
	switch (chon){
				case 1:
			printf("\n sap xep selection sort :\n");
			selectionSort(a,n);
			xuatMang(a,n);
	  			break;
				case 2:
			printf("\n sap xep bubble sort :\n");
			bubbleSort(a,n);
			xuatMang(a,n);
	  			break;
				case 3:
			printf("\n sap xep interchange sort :\n");
			interchangeSort(a,n);
			xuatMang(a,n);
	  			break;
				case 4:
			printf("\n sap xep insertion sort :\n");
			insertionSort(a,n);
			xuatMang(a,n);
	  			break;
				case 5:
			printf("\n sap xep Quick sort :\n");
			QuickSort(a,0,n-1);
			xuatMang(a,n);
	  			break;
	  			
				default:  chon=0; 
				break; 
				}
	
	
	}while (chon !=0);
	
	printf("\n"); 
	return 0;
}