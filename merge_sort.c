/*	Merge sort 
    The programs wil recive a number number of size then will random integers between 0 to 1 million and then sorting by using 
    Merge sort
    made by Preutta Woratol	ID: 63070503433
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int * elements, int left, int middle, int right)
{
	int * dummy = NULL;
	int n1 = 0;
	int n2 = 0;
	int i = 0;
	int j = 0;
	int k = 0;	
	
	dummy = calloc(right-left+1,sizeof(int));
	n1 = middle-left+1;
	n2 = right-middle;
	while(i < n1 && j < n2)
	{
		if(elements[left+i] < elements[middle+1+j])
		{
			dummy[k] = elements[left+i];
			i++;
		}
		else
		{
			dummy[k] = elements[middle+1+j];
			j++;
		}	
		k++;
	}
	if(i == n1)
	{
		for(j;j < n2;j++)
		{
			dummy[k] = elements[middle+1+j];
			k++;
		}
	}
	else
	{
		for(i;i < n1;i++)
		{
			dummy[k] = elements[left+i];
			k++;
		}
	}
	for(k=0;k < right+1;k++)
	{
		if(k+left > right)
			break;
		elements[k+left] = dummy[k];
	}
	free(dummy);
}

void mergeSort(int * elements, int left, int right)
{
	int middle = 0;
	if((right-left) > 0)
	{
		middle = (left+right)/2;
		mergeSort(elements,left,middle);
		mergeSort(elements,middle+1,right);
		merge(elements,left,middle,right);
	}
}

int main()
{
	char input[256];
	int * elements = NULL;
	int amount = 0;
	int i = 0;
	clock_t start, end;
	double cpu_time_used;
	while(1)
	{
		srand(time(NULL));
		printf("Enter the number of elements (Enter 0 to stop) : ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&amount);
		if(amount == 0)
		{
			break;
		}
		
		elements = calloc(amount,sizeof(int));
		
		printf("\nElements of array before sorting\n");
		for(i = 0;i < amount;i++)
		{
	
			elements[i] = (rand() * rand()) % 1000001;
			printf("%10d",elements[i]);
		}
		
		start = clock();
		mergeSort(elements,0,amount-1);
		end = clock();
		
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		
		printf("\n\nElements of array after sorting\n");
		for(i = 0;i < amount;i++)
		{
			printf("%10d",elements[i]);
		}
		printf("\n\nElapsed time: %lf seconds\n\n", cpu_time_used);
		
		free(elements);
	}
}


