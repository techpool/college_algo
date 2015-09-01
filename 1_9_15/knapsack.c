#include<stdio.h>
void knapsack(int n, float weight[], float profit[], float capacity){

	int i;
	float x[20];
	float c = capacity, tp = 0.0;


	for(i = 0; i < n; i++){
		x[i] = 0.0;
	}

	for(i = 0; i < n; i++){
		if(weight[i] > c){
			break;
		} else {
			x[i] = 1.0;
			tp = tp + profit[i];
			c = c - weight[i];
		}
	}

	if(i < n){
		x[i] = c/weight[i];
	}

	tp = tp + (profit[i] * x[i]);

	printf("Result vector : \n");

	for(i = 0; i < n; i++){
		printf("%f\t", x[i]);
	}

	printf("\nTotal profit : %f", tp);
}

void main(){
	int n, i, j;
	float weights[20], profit[20], ratio[20], capacity, temp;
	printf("Enter the number of items you have: ");
	scanf("%d", &n);

	printf("Enter the weights :\n");
	for(i = 0; i < n; i++){
		printf("Item %d: ", i+1);
		scanf("%f", &weights[i]);
	}

	printf("Enter the profits :\n");
	for(i = 0; i < n; i++){
		printf("Item %d: ", i+1);
		scanf("%f", &profit[i]);
	}

	printf("Enter the capacity of the knapsack: ");
	scanf("%f", &capacity);

	//calculate ratio
	for(i = 0; i < n; i++){
		ratio[i] = profit[i]/weights[i];
	}

	for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			if(ratio[i] < ratio[j]){
				temp = ratio[i];
				ratio[i] = ratio[j];
				ratio[j] = temp;

				temp = profit[i];
				profit[i] = profit[j];
				profit[j] = temp;

				temp = weights[i];
				weights[i] = weights[j];
				weights[j] = temp;
			} else {
				continue;
			}
		}
	}

	knapsack(n, weights, profit, capacity);
}