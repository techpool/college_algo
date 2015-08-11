#include<stdio.h>
void main(){
	int n, i, j, position, a[30], swap;
	printf("Enter the number of elements you want to enter: ");
	scanf("%d", &n);

	printf("Enter the elements:\n");
	for(i = 0; i < n; i++){
		printf("Element %d = ", i+1);
		scanf("%d", &a[i]);
	}

	printf("Entered elements:\n");
	for(i = 0; i < n; i++){
		printf("Element %d = %d\n", i+1, a[i]);
	}

	for(i = 0; i < n - 1; i++){

		position = i;

		for(j = i + 1; j < n; j++){
			if(a[position] > a[j]){
				position = j;
			}
		}

		if(position != i){
			swap = a[position];
			a[position] = a[i];
			a[i] = swap;
		}
	}

	printf("\nSorted Elements:\n");
	for(i = 0; i < n; i++){
		printf("Element %d = %d\n", i+1, a[i]);
	}
}