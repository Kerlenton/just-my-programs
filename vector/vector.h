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

typedef union
{
	int64_t *decimal;
	double *real;
	uint8_t **string;
} data;

typedef struct Vector
{
	size_t size; 
	size_t capacity;
	size_t element_size;

	vtype type;
	data data;
} Vector;

typedef struct Iterator
{
	void *pointer;
	size_t element_size;
} Iterator;

#endif

#define MAX(a, b) ((a) > (b) ? (a) : (b))


extern int vector_setup(Vector *vector, size_t capacity, size_t element_size);
extern int vector_copy(Vector *dst, Vector *src);
extern int vector_copy_assign(Vector *dst, Vector *src);
extern int vector_move(Vector *dst, Vector *src);
extern int vector_move_assign(Vector *dst, Vector *src);
extern int vector_swap(Vector *dst, Vector *src);

// Insertion

extern int vector_push_back(Vector *vector, void *element);


//-------------------------

extern bool vector_is_initialized(const Vector *vector);
extern size_t vector_byte_size(const Vector *vector);
extern int vector_destroy(Vector *vector);

static void _vector_swap(size_t *first, size_t *second);
static bool _vector_shlould_grow(Vector *vector);
static int _vector_adjust_capacity(Vector *vector);
static int _vector_realocate(Vector *vector, size_t new_capacity);
static void _vector_assign(Vector *vector, size_t index, void *element);
void* _vector_offset(Vector* vector, size_t index);


