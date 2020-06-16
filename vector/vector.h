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
	uint8_t **pointer;
	size_t element_size;
} Iterator;





#define MAX(a, b) ((a) > (b) ? (a) : (b))





//..
extern int vector_setup(Vector* vector, size_t capacity, size_t element_size);
extern int vector_copy(Vector *dst, Vector *src);
extern int vector_copy_assign(Vector *dst, Vector *src);
extern int vector_move(Vector *dst, Vector *src);
extern int vector_move_assign(Vector *dst, Vector *src);
extern int vector_swap(Vector *dst, Vector *src);








// Insertion
extern int vector_push_back(Vector *vector, uint8_t **element);
extern int vector_push_front(Vector *vector, uint8_t **element);
extern int vector_assign(Vector *vector, size_t index, uint8_t **element);
extern int vector_insert(Vector *vector, size_t index, uint8_t **element);

// Delition
extern int vector_pop_back(Vector *vector);
extern int vector_pop_front(Vector *vector);
extern int vector_erase(Vector *vector, size_t index);
extern int vector_clear(Vector *vector);

// Memory managment

extern int vector_resize(Vector *vector, size_t new_size);
extern int vector_reserve(Vector *vector, size_t minimum_capacity);
extern int vector_shrink_to_fit(Vector *vector);

// Iterators

extern Iterator vector_begin(Vector *vector);
extern Iterator vector_iterator(Vector* vector, size_t index);
extern uint8_t **iterator_get(Iterator* iterator);
extern int iterator_erase(Vector* vector, Iterator* iterator);
extern void iterator_increment(Iterator *iterator);
extern void iterator_decrement(Iterator *iterator);
extern uint8_t **iterator_next(Iterator *iterator);
extern uint8_t **iterator_previous(Iterator *iterator);
bool iterator_equals(Iterator* first, Iterator* second);
bool iterator_is_before(Iterator* first, Iterator* second);
bool iterator_is_after(Iterator* first, Iterator* second);
extern size_t iterator_index(Vector* vector, Iterator* iterator);

//.....
extern bool vector_is_initialized(const Vector *vector);
extern size_t vector_byte_size(const Vector *vector);
extern int vector_destroy(Vector *vector);
extern size_t vector_free_space(const Vector* vector);
extern bool vector_is_empty(Vector* vector);

// Look
extern void* vector_get(Vector* vector, size_t index);
extern void* vector_front(Vector* vector);
extern void* vector_back(Vector* vector);


// Static
static void _vector_swap(size_t *first, size_t *second);
static bool _vector_should_grow(Vector *vector);
static int _vector_adjust_capacity(Vector *vector);
static int _vector_reallocate(Vector *vector, size_t new_capacity);
static void _vector_assign(Vector *vector, size_t index, uint8_t **element);
static uint8_t** _vector_offset(Vector* vector, size_t index);
static int _vector_move_right(Vector *vector, size_t index);
static bool _vector_should_shrink(Vector *vector);
static void _vector_move_left(Vector *vector, size_t index);
static size_t _vector_free_bytes(const Vector* vector);

#endif
