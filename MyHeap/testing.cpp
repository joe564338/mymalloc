#include "MyAllocator.h"

int main() {
	my_initialize_heap(5000);
	int input;
	printf("\n What test case do you want enter 1 through 5\n");
	scanf("%d" , &input);
	switch(input){
		
		//test case 1
		case 1:
			if(true){
				int* i = (int*)my_alloc(sizeof(int));
				printf("\n Address of i: %p \n", i);
				my_free(i);
				int* j = (int*)my_alloc(sizeof(int));
				printf("\n Address of j: %p \n", j);
			}
			break;
		//test case 2
		case 2:
			if(true){
				int* i = (int*)my_alloc(sizeof(int));
				printf("\n Address of i: %p \n", i);
				int* j = (int*)my_alloc(sizeof(int));
				printf("\n Address of j: %p \n", j);
			}
			break;
	
		//test case 3
		case 3:
			if(true){
				int* i = (int*)my_alloc(sizeof(int));
				int* j = (int*)my_alloc(sizeof(int));
				int *k = (int*)my_alloc(sizeof(int));
				printf("\n Address of i: %p \n", i);
				printf("\n Address of j: %p \n", j);
				printf("\n Address of k: %p \n", k);
				my_free(j);
				double* l = (double*)my_alloc(sizeof(double));
				printf("\n Address of l: %p \n", l);
			}
			break;
		//test case 4
		case 4:
		if(true){
			int* i = (int*)my_alloc(sizeof(int));
			char* c = (char*)my_alloc(sizeof(char));
			printf("\n Address of i: %p \n", i);
			printf("\n Address of c: %p \n", c);
		}
			break;
		
		//test case 5
		case 5:
			if(true){
				int* i100[100];
				for (int* i : i100) {
					i = (int*)my_alloc(sizeof(int));
					printf("\naddress of current index: %p\n", i);
				}
			}
			break;
			
		default:
			printf("\n Not a case. Please rerun the program\n");
			break;
	}
	return 0;
	
}