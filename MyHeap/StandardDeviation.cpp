#include "StandardDeviation.h"
#include "MyAllocator.h"
#include "math.h"
void standard_deviation(int n) {
	my_initialize_heap(10000);
	int* sdarray[100];
	for (int i = 0; i < n; i++) {
		sdarray[i] = (int*)my_alloc(sizeof(int));
		int user_int = 0;
		printf("\nType a number\n");
		
		scanf("%d", &user_int);
		*sdarray[i] = user_int;
		printf("\n%d\n", user_int);
		printf("\n%d\n", *sdarray[i]);
	}
	double* sum = (double*)my_alloc(sizeof(double));

	*sum = 0;
	for (int i = 0; i < n; i++) {
		*sum += *sdarray[i];
	}
	double* mean = (double*)my_alloc(sizeof(double));
	*mean = *sum / n;
	double* summation = (double*)my_alloc(sizeof(int));
	*summation = 0;
	for (int i = 0; i < n; i++) {
		*summation += pow(*sdarray[i] - *mean, 2);
	}
	*summation = *summation / n;

	*summation = sqrt(*summation);
	printf("\n%lf\n", *summation);
}
int main() {
	printf("HOW LONG IS ARRAY?");
	int num;
	scanf("%d", &num);
	standard_deviation(num);
	return 0;
}