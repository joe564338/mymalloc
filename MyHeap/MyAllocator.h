#pragma once
#include <stdio.h>
#include <stdlib.h>
#ifndef __MYALLOCATOR_H
#define __MYALLOCATOR_H
struct Block {
	int block_size;
	struct Block* next_block;
	void* data;
};

const int VOID_SIZE = sizeof(void*);
const int OVERHEAD = sizeof(int) + VOID_SIZE;
struct Block *freehead;
void my_initialize_heap(int);
void* my_alloc(int);
void my_free(void*);
#endif