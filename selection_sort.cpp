/*
 *  Selection sort
 *  The programs will recive a number of size then will random integers between 0 to 1 million and then sorting by using 
 *  selection sort. After that, it will tell the summary of the time counted.
 *  made by Seiya Tajima ID : 63070503409
 * 
 * */
#include <bits/stdc++.h>
#include <random>
#include <iostream>
#include <chrono>
using namespace std;

/*
 * Get random number for each element
 */
void GetElement(int element[],int number)
{
    int i;
    for (i = 0; i < number; i++)
        element[i] = ((rand()*rand()) % 1000000) +1;
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort(int arr[], int number)
{
	int i, j, min;

	for (i = 0; i < number-1; i++)
	{
		min = i;
		for (j = i+1; j < number; j++)
			if (arr[j] < arr[min])
				min = j;

		swap(&arr[min], &arr[i]);
	}
}

int main()
{
	int *element; //array of element which have size of number
    int number; //amount of element
	int i = 0;
    chrono::steady_clock clock;
    cout << "Enter the number of element: ";
    cin >> number;
    element = new int[number];
    srand(time(nullptr));
    GetElement(element,number);
    cout << "Elements of the array before sorting\n";
    for(i=0;i<number;i++)
    {
    	cout << element[i] << " ";
	}
    auto start = clock.now(); //start count
	selectionSort(element, number);
    auto end = clock.now(); //end count
    auto time_span = static_cast<chrono::duration<double>>(end - start);
    cout << "\nElements of the array after sorting\n";
    for(i=0;i<number;i++)
    {
    	cout << element[i] << " ";
	}
	cout << "\nTime taken for selection sort : " <<time_span.count()<<" seconds"<<"\n";
    delete[]element;
	return 0;
}
