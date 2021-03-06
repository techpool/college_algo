#include<stdio.h>
int heap_size;

int left(int i){
	if(2 * i <= heap_size){
		return 2*i;
	} else {
		return 0;
	}
}

int right(int i){

	if((2 * i) + 1 <= heap_size){
		return (2*i) + 1;
	} else {
		return 0;
	}
}

void max_heapify(int arr[], int i){
	int l, r, largest, swap;
	l = left(i);
	r = right(i);
	if(l <= heap_size && arr[l] > arr[i]){
		largest = l;
	} else {
		largest = i;
	}
	if(r <= heap_size && arr[r] > arr[i]){
		largest = r;
	}

	if(largest != i){
		swap = arr[i];
		arr[i] = arr[largest];
		arr[largest] = swap;
		max_heapify(arr, largest);
	}


}

void build_max_heap(int arr[]){
	int i;
	for(i = heap_size/2; i >= 0; i--){
		max_heapify(arr, i);
	}
}

void heap_sort(int arr[]){

	int i, swap;
	build_max_heap(arr);
	for(i = heap_size; i >= 1; i--){
		swap = arr[i];
		arr[i] = arr[0];
		arr[0] = swap;
		heap_size -= 1;
		max_heapify(arr, 1);
	}
}

void main(){
	int n, i, arr[20];

	printf("Enter the number of inputs = ");
	scanf("%d", &n);
	heap_size = n - 1;
	for(i = 0; i < n; i++){
		printf("Element %d = ", i+1);
		scanf("%d", &arr[i]);
	}

	heap_sort(arr);

	for(i = 0; i < n; i++){
		printf("Element %d = %d", i+1, arr[i]);
	}
}