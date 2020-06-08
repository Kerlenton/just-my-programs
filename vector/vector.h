#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define VECTOR_MINIMUM_CAPACITY 2
#define VECTOR_GROWTH_FACTOR 2
#define VECTOR_SHRINK_THRESHOLD (1 / 4)

#define VECTOR_ERROR -1
#define VECTOR_SUCCESS 0

#define VECTOR_UNINITIALIZED NULL
#define VECTOR_UNITIALIZER \
   {0, 0, 0, VECTOR_UNINITIALIZED}

typedef enum
{
	DECIMAL_ELEM,
	REAL_ELEM,
	STRING_ELEM
} vtype;

typedef struct Vector
{
	size_t size; 
	size_t capacity;
	size_t element_size;

	uint8_t **data;
} Vector;

typedef struct Iterator
{
	void *pointer;
	size_t element_size;
} Iterator;

#endif






#define MAX(a, b) ((a) > (b) ? (a) : (b))





//..
int vector_setup(Vector* vector, size_t capacity, size_t element_size);
extern int vector_copy(Vector *dst, Vector *src);
extern int vector_copy_assign(Vector *dst, Vector *src);
extern int vector_move(Vector *dst, Vector *src);
extern int vector_move_assign(Vector *dst, Vector *src);
extern int vector_swap(Vector *dst, Vector *src);








// Insertion
extern int vector_push_back(Vector *vector, uint8_t **element);






//.....
extern bool vector_is_initialized(const Vector *vector);
extern size_t vector_byte_size(const Vector *vector);
extern int vector_destroy(Vector *vector);






// Static
static void _vector_swap(size_t *first, size_t *second);
static bool _vector_should_grow(Vector *vector);
static int _vector_adjust_capacity(Vector *vector);
static int _vector_reallocate(Vector *vector, size_t new_capacity);
static void _vector_assign(Vector *vector, size_t index, uint8_t **element);
void* _vector_offset(Vector* vector, size_t index);


