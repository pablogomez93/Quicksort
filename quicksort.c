#include <stdio.h>

typedef unsigned int uint;

void printCollection(int* collection, uint n){
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", collection[i]);
    printf("\n");
}

void QuickSort(int* array, uint n) {
    if(n < 2) return;

    int pivot = array[rand() % n];
    int left = 0;
    int right = n-1;

    while(left <= right) {
        while(array[left] < pivot)
            ++left;

        while(array[right] > pivot)
            --right;

        if(left <= right) {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;

            left++;
            right--;
        }
    }

    QuickSort(array, right+1);
    QuickSort(&array[left], n-left);

    return;
}


int main(int argsSize, char* args[]) {
	/* 
	 * Charging the array to sort.
	 * Define n as total size of the array and divide it by the size of one
	 * element of it. It's a kind of hack to find the length of the array.
	 */
    int array[5] = {8137, 3522, 7383, 7336, 9659};
    int n = sizeof array / sizeof array[0];

	/*
	 * If you prefer, you can charge the collection to sort into the program
	 * by passing its elements as arguments from a terminal.
	 * If you don't pass arguments to sort, this program will sort the array
	 * charged manually above.
	 *
	 * Example: 
	 *	$ make all
	 *  $ ./quicksort 5 7 8 6 69 18782 9
	 *
	 *  Then Quick Sort will sort the array [5, 7, 8, 6, 69, 18782, 9] 
	 */
	if(argsSize > 1) {
        n = argsSize-1;
        array[n];

        int i;
        for (i = 1; i <= n; ++i)
            array[i-1] = (int) strtol(args[i], &args[i], 10);

    }

    //Finally, sort the collection with Quick Sort Algorithm
    QuickSort(array, n);

    //Send to the standar output the sorted array 
    printCollection(array, n);

	return 0;
}
