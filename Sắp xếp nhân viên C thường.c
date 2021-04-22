#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct NHANVIEN{
	char Ma[10];
	char Ten[30];
	int Luong;
}NV;

void nhap1(NV &ds)
{
	fflush(stdin);
	printf("\n Ma:");
	gets(ds.Ma);
	printf("\n Ten:");
	gets(ds.Ten);
	printf("\n Luong:");
	scanf("%d", &ds.Luong);	
	printf("\n*************************\n");
}

void nhapNhanVien(int &n, NV ds[])
{
	printf("\n nhap so luong:");
	scanf("%d", &n);
	
	for(int i=0; i<n ;i++)
		nhap1(ds[i]);	
}

void xuat1( NV ds)
{
	printf("\n %10s %30s %-7d\n", ds.Ma, ds.Ten, ds.Luong);
}

void xuatNV(int n, NV ds[])
{
	printf("\n***danh sach nhan vien**********************\n");
	printf("\n ma   ten    luong\n");
	for(int i=0; i<n ;i++)
		xuat1(ds[i]);
	printf("\n*************************\n");
	system("pause");
}

NV swap (NV &a, NV &b)
{
	NV tamp=a; a=b; b=tamp;	
}

void bubblesort(int n, NV ds[])
{
	for(int i=0; i<n-1 ; i++)
		for(int j = n-1 ; j >i; j--)
			if(strcmp(ds[j-1 ].Ma , ds[j].Ma)>0) swap(ds[j-1], ds[j]);
}

void interchangeSort(NV a[], int n)
{
	for (int i=0; i<n-1; i++)
		for(int j=i+1; j<n;j++)
			if(strcmp(a[i].Ten,a[j].Ten)>0) swap (a[i],a[j]);
}

void selectionSort(NV a[],int n)
{
	for(int i=0; i<n-1 ; i++)
	{
		int vtmin = i;
		for (int j= i+1; j<n ; j++)
			if(a[j].Luong < a[vtmin].Luong ) vtmin = j;
		swap(a[i], a[vtmin]);
	}
}

int main()
{
	int n;
	NV ds[100];
	
	nhapNhanVien(n,ds);
	xuatNV(n,ds);
	int chon;
	do{
		
		printf("\n1. sap xep theo ma nhan vien \n");
		printf("\n2. sap xep theo ten nhan vien \n");
		printf("\n3. sap xep theo luong nhan vien \n");
		printf("\n0. thoat!!!  \n");
		printf("\nlua chon cua ban: ");fflush(stdin);
		scanf("%d ", &chon);
		switch (chon)
		{
			case 1:
				bubblesort(n, ds);
				xuatNV(n,ds);break;
			case 2:
				interchangeSort(ds,n);
				xuatNV(n,ds);break;
			case 3:
				interchangeSort(ds,n);
				xuatNV(n,ds);break;
			default:  chon=0; 
				break;
		}
		
	}while (chon !=0);
	
	
	return 0;
}