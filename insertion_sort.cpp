/* Insertion sort 
    The programs wil recive a number number of size then will random integers between 0 to 1 million and then sorting by using 
    insertion sort
    made by Mahudpoj Pongpanich ID : 63070503443 , mayson ross kieng ID : 63070503445
*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

int main () {
    long int *intArray;
    int size = 0; //size of array
    int status = 1; //quit program or not
    int i = 0; // Dummy
    int v = 0;
    int j = 0;
    chrono::time_point<chrono::system_clock> start,end;
    
    srand(time(NULL));
    while (status = 1)
    {
        //Reset 
        i =0;
        v =0;
        j=0;
        //Reset
        cout << "Enter the number of elemnt size ";
        cin >> size;
        intArray = new long int[size];
        cout << "Elements of the array before sorting\n";
        for (i = 0; i < size; i++) //random number
        {
            intArray[i] = rand()%1000001;
            cout << intArray[i] << " ";
        }
        i = 2;
        start = chrono::system_clock::now();
        for (i = 1; i < size ; i++) //inserting part
        {
            v = intArray[i];
            j = i-1;
            while ( (j >= 0) && (intArray[j] > v) )
            {
                intArray[j+1] = intArray[j];
                j = j-1;
            }
            intArray[j+1] = v;
        }
        end = chrono::system_clock::now();
        double runningTime = double (chrono::duration_cast <chrono::milliseconds> (end-start).count());
        i = 0;
        cout << "\nElements of the array after sorting\n";
        for (i=0; i < size; i++)
        {
            cout << intArray[i] << " ";
        }
        cout << "\nRunning time is " << runningTime << " milliseconds\n";

        break;
    }
    

}



