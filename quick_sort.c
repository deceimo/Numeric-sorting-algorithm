/*	Quick sort 
    The programs wil recive a number number of size then will random integers between 0 to 1 million and then sorting by using 
    quick sort
    made by Nattapong Saengarunvong	ID: 63070503415
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int partition(int * array,int l,int r)
{
	int p=array[l];
	int i,j,reserve;

	i=l;
	j=r+1;

	do
		{
		while(1)
			{
			i++;
			if((array[i]>=p)||(i>=r))
				break;
			}
			
		while(1)
			{
			j--;
			if(array[j]<=p)
				break;
			}

		reserve=array[i];
		array[i]=array[j];
		array[j]=reserve;			
		}while(i<j);

	reserve=array[i];
	array[i]=array[j];
	array[j]=reserve;

	reserve=array[l];
	array[l]=array[j];
	array[j]=reserve;
	
	return j;
}

void quick_sort(int * array,int l,int r)
{
	if(l<r)
		{
		int s=partition(array,l,r);
		
		quick_sort(array,l,s-1);
		quick_sort(array,s+1,r);
		}
}

int main()
{
    char input[32];
    int n,i;
    int upper=1000000;
	int lower=0;
    int *array;
	clock_t start, end;
    double cpu_time_used;

	while(1)
		{
	    srand(time(NULL));
	
		printf("Enter the number of elements(Enter -1 to stop): ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&n);
		
		if(n<0)
			exit(0);
	
		array=calloc(n,sizeof(int));
	
		printf("Element of the element before sorting\n");
	
		for(i=0;i<n;i++)
			{
			array[i]= (rand() * rand()) % 1000001;
			printf("%d ",array[i]);
			}
	
		printf("\n");
			
		start = clock();
		quick_sort(array,0,n-1);
		end = clock();
		
		printf("\nElement of the element after sorting\n");
		for(i=0;i<n;i++)
			{
			printf("%d ",array[i]);
			}
		
			
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("\nRunning time of quick sort: %f seconds\n\n", cpu_time_used);
			
		free(array);
		}
}
