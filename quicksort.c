#include<stdio.h>

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
    int array[5] = {8137, 3522, 7383, 7336, 9659};
    int n = sizeof array / sizeof array[0];
    int i;

    if(argsSize > 1){
        n = argsSize-1;
        array[n];

        int i;
        for (i = 1; i <= n; ++i)
            array[i-1] = *args[i] - '0';

    }

    QuickSort(array, n);

    printCollection(array, n);

	return 0;
}
