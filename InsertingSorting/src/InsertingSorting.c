

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int x[], int size){
	int i, j, key;
	for(i=1; i<size; i++){
		key = x[i];
		for(j = i - 1 ; j >= 0; j--){
			if(key < x[j]){
				x[j+1] = x[j];
				if(j==0){
					x[j] = key;
				}
			} else if(key>x[j] || key == x[j]){
				x[j+1]=key;
				break;
			}
		}
	}
}


void printList(int x[],int size){
	int i;
	for(i=0; i<size; i++){
		printf("%i ", x[i]);
	}
}
int main(void) {

	int arr []  = {3,5,7,11,13,2,9,6};

	insertionSort(arr, 8);
	printList(arr, 8);

	return EXIT_SUCCESS;
}
