#include "MyAllocator.h"

int main() {
	my_initialize_heap(5000);
	//test case 1
	int* i = (int*)my_alloc(sizeof(int));
	printf("\n Address of i: %p \n", i);
	my_free(i);
	int* j = (int*)my_alloc(sizeof(int));
	printf("\n Address of j: %p \n", j);
	
	//test case 2
	int* i = (int*)my_alloc(sizeof(int));
	printf("\n Address of i: %p \n", i);
	int* j = (int*)my_alloc(sizeof(int));
	printf("\n Address of j: %p \n", j);
	
	//test case 3
	int* i = (int*)my_alloc(sizeof(int));
	int* j = (int*)my_alloc(sizeof(int));
	int* k = (int*)my_alloc(sizeof(int));
	printf("\n Address of i: %p \n", i);
	printf("\n Address of j: %p \n", j);
	printf("\n Address of k: %p \n", k);
	my_free(j);
	double* l = (double*)my_alloc(sizeof(double));
	printf("\n Address of l: %p \n", l);
	//test case 4
	int* i = (int*)my_alloc(sizeof(int));
	char* c = (char*)my_alloc(sizeof(char));
	printf("\n Address of i: %p \n", i);
	printf("\n Address of c: %p \n", c);
	//test case 5
	int* i100[100];
	for (int* i : i100) {
		i = (int*)my_alloc(sizeof(int));
		printf("\naddress of current index: %p\n", i);
	}
	return 0;
	
}