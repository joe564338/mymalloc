
#include "MyAllocator.h"
void my_initialize_heap(int size) {
	freehead1 = (Block *)malloc(size);
	freehead1->block_size = size - OVERHEAD;
	freehead1->next_block = NULL;

	//printf("INIT %p \n", freehead11);
}
void* my_alloc(int size) {
	struct Block* new_block = NULL;
	int jump_size;
	struct Block* current = freehead1;
	struct Block* last_block = freehead1;
	while (size % VOID_SIZE != 0) {
		size++;
	}
	while (current != NULL) {
		printf("\nTEST1\n");
		if (current == freehead1) {
			printf("\nYES\n");
			int s = size + OVERHEAD;
			int t = freehead1->block_size + OVERHEAD;
			printf("\n%d = size of NEW STUFF;;; %d = size of OLD STUFF\n", s, t);
		}
		if (freehead1 == current && (current->block_size >= size)) {
			printf("\nTEST 2\n");
			jump_size = size + OVERHEAD;
			struct Block* new_free = (struct Block*) ((unsigned char*)freehead1 + jump_size);
			new_free->block_size = freehead1->block_size - size - OVERHEAD;
			new_block = freehead1;
			new_block->block_size = size;
			freehead1 = new_free;
			printf("\nTEST3 new_block %p freehead1 %p  newblock->data %p\n", new_block, freehead1, &new_block->data);
			return &new_block->data;
		}
		else if (current == freehead1 && current->block_size < size + OVERHEAD) {
			printf("\nTEST4 + current's address: %p\n", current);
			last_block = current;
			current = freehead1->next_block;
			printf("\nTest 5656 + current's address: %p\n", current);
		}
		else if (current->block_size >= size + OVERHEAD) {
			printf("\nTEST 5\n");
			last_block->next_block = current->next_block;
			if (current->block_size > size + OVERHEAD * 2) {
				printf("\nTEST6\n");
				struct Block* split_block;
				jump_size = size + OVERHEAD;
				split_block = (struct Block*) (((unsigned char*)current) + jump_size);
				split_block->block_size = current->block_size - size - OVERHEAD;
				
				current->block_size = size;
				current->next_block = NULL;
				split_block->next_block = freehead1->next_block;
				freehead1 = split_block;
				printf("\nTEST7\n");
				printf("\nCurrent's address: %p\n", current);
				return &current->data;
			}
			else {
				printf("\nTEST 8\n");
				current->block_size = size;
				current->next_block = NULL;
				printf("\nCurrent's address: %p\n", current);
				return &current->data;
			}
		}
		else if(current->block_size < size + OVERHEAD){
			printf("\nTEST9\n");
			*last_block = *current;
			current = current->next_block;
		}
	}
	printf("OUT OF MEMORY \n");
	return 0;
}
void my_free(void* data) {
	printf("%p \n", data);
	struct Block* last_fh = NULL;
	last_fh = freehead1;
	printf("%p \n", freehead1);
	freehead1 = (struct Block*)((unsigned char*)data - OVERHEAD);
	printf("%p \n", freehead1);
	freehead1->next_block = last_fh;
	printf("FREED \n");
}