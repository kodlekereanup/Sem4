#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAX_VAL 9999
void display(int arr[], int hsize)
{
	int i;
	if (hsize == 0)
	{
		printf("heap is empty");
		return;
	}
	for (i = 1;i <= hsize;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("Number of elemnts= %d\n", hsize);
}
void restoreup(int arr[], int i)
{
	int k = arr[i];
	int par = i / 2;
	while (arr[par] < k)
	{
		arr[i] = arr[par];
		i = par;
		par = i / 2;
	}
	arr[i] = k;
}
void insert(int num, int arr[], int *p_hsize)
{
	(*p_hsize)++;
	arr[*p_hsize] = num;
	restoreup(arr, *p_hsize);
}
void restoredown(int arr[], int i, int hsize)
{
	int lchild = 2 * i, rchild = lchild + 1;
	int num = arr[i];
	while (rchild <= hsize)
	{
		if (num >= arr[lchild] && num >= arr[rchild])
		{
			arr[i] = num;
			return;
		}
		else if (arr[lchild] > arr[rchild])
		{
			arr[i] = arr[lchild];
			i = lchild;
		}
		else
		{
			arr[i] = arr[rchild];
			i = rchild;
		}
		lchild = 2 * i;
		rchild = lchild + 1;
	}
	if (lchild == hsize&&num < arr[lchild])
	{
		arr[i] = arr[lchild];
		i = lchild;
	}
	arr[i] = num;
}
int del_root(int arr[], int *p_hsize)
{
	int max = arr[1];
	arr[1] = arr[*p_hsize];
	(*p_hsize)--;
	restoredown(arr, 1, *p_hsize);
	return max;
}
void buildheapu(int arr[], int size)
{
	int i;
	for (i = 2;i <= size;i++)
	{
		restoreup(arr, i);
	}
}
/*
void buildheapd(int arr[], int size)
{
	int i;
	for (i = size / 2;i >= 1;i--)
		restoredown(arr, i, size);
}*/
int main()
{
	int arr[100];
	int hsize = 0;
	int i, choice, num;
	arr[0] = MAX_VAL;
	while (1)
	{
		printf("1.insert ");
		printf("2.delete ");
		printf("3.display ");
		printf("4.buildheap ");
		printf("5.exit ");
		printf("\nenter your choice\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("enter the number to be inserted: ");
			scanf("%d", &num);
			insert(num, arr, &hsize);
			break;
		case 2:
			if (hsize == 0)
				printf("heap is empty\n");
			else
			{
				num = del_root(arr, &hsize);
				printf("max elemnt is %d\n", num);
			}
			break;
		case 3:
			display(arr, hsize);
			break;
		case 4:
			printf("\nenter size of the array\n");
			scanf("%d", &hsize);
			printf("\nenter the array: \n");
			for (i = 1;i <= hsize;i++)
				scanf("%d", &arr[i]);
			buildheapu(arr, hsize);
			break;
		case 5:
			exit(0);
			break;
		}
	}
  return 0;
}

