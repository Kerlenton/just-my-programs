#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "vector.h"

int main()
{
	Vector *v = (Vector*)malloc(sizeof(Vector));
	uint8_t *p = "helllo";
	uint8_t *q = "hi";
	uint8_t *r = "he";
	vector_setup(v, 5, sizeof(uint8_t*));
	vector_push_back(v, &p);
	vector_push_back(v, &q);

	printf("%s\n", *(v->data));
	printf("%s\n", *(v->data + v->element_size));

	vector_assign(v, 0, &r);

	printf("%s\n", *(v->data));
	printf("%s\n", *(v->data + v->element_size));

	getchar();
	system("PAUSE");
	return 0;
}

extern int vector_setup(Vector* vector, size_t capacity, size_t element_size) 
{
	assert(vector != NULL);

	if (vector == NULL) return VECTOR_ERROR;

	vector->size = 0;
	vector->capacity = MAX(VECTOR_MINIMUM_CAPACITY, capacity);
	vector->element_size = element_size;
	vector->data = malloc(vector->capacity * element_size);

	return vector->data == NULL ? VECTOR_ERROR : VECTOR_SUCCESS;
}

extern int vector_copy(Vector* dst, Vector* src)
{
	assert(dst != NULL);
	assert(src != NULL);
	assert(vector_is_initialized(src));
	assert(!vector_is_initialized(dst));

	if (dst == NULL) return VECTOR_ERROR;
	if (src == NULL) return VECTOR_ERROR;
	if (vector_is_initialized(dst)) return VECTOR_ERROR;
	if (!vector_is_initialized(src)) return VECTOR_ERROR;

	dst->size = src->size;
	dst->capacity = src->size * 2;
	dst->element_size = src->element_size;

	dst->data = malloc(dst->capacity * src->element_size);
	if (dst->data == NULL) return VECTOR_ERROR;

	memcpy(dst->data, src->data, vector_byte_size(src));

	return VECTOR_SUCCESS;
}

extern int vector_copy_assign(Vector* dst, Vector* src)
{
	assert(dst != NULL);
	assert(src != NULL);
	assert(vector_is_initialized(src));
	assert(vector_is_initialized(dst));

	if (dst == NULL) return VECTOR_ERROR;
	if (src == NULL) return VECTOR_ERROR;
	if (!vector_is_initialized(dst)) return VECTOR_ERROR;
	if (!vector_is_initialized(src)) return VECTOR_ERROR;

	vector_destroy(dst);

	return vector_copy(dst, src);
}

extern int vector_move(Vector* dst, Vector* src)
{
	assert(dst != NULL);
	assert(src != NULL);

	if (dst == NULL) return VECTOR_ERROR;
	if (src == NULL) return VECTOR_ERROR;

	*dst = *src;
	src->data = NULL;

	return VECTOR_SUCCESS;
}

extern int vector_move_assign(Vector* dst, Vector* src)
{
	vector_swap(dst, src);
	return vector_destroy(src);
}

extern int vector_swap(Vector* dst, Vector* src)
{
	void* temp;

	assert(dst != NULL);
	assert(src != NULL);
	assert(vector_is_initialized(src));
	assert(vector_is_initialized(dst));

	if (dst == NULL) return VECTOR_ERROR;
	if (src == NULL) return VECTOR_ERROR;
	if (!vector_is_initialized(dst)) return VECTOR_ERROR;
	if (!vector_is_initialized(src)) return VECTOR_ERROR;

	_vector_swap(&dst->size, &src->size);
	_vector_swap(&dst->capacity, &src->capacity);
	_vector_swap(&dst->element_size, &src->element_size);

	temp = dst->data;
	dst->data = src->data;
	src->data = temp;

	return VECTOR_SUCCESS;
}

// Insertion 
extern int vector_push_back(Vector* vector, uint8_t** element)
{
	assert(vector != NULL);
	assert(element != NULL);

	if (_vector_should_grow(vector)) 
		if (_vector_adjust_capacity(vector) == VECTOR_ERROR)
			return VECTOR_ERROR;
	


	_vector_assign(vector, vector->size, element);

	++vector->size;

	return VECTOR_SUCCESS;
}

extern int vector_push_front(Vector *vector, uint8_t **element)
{
	return vector_insert(vector, 0, element);
}

extern int vector_insert(Vector *vector, size_t index, uint8_t **element)
{
	uint8_t **offset;
	assert(vector != NULL);
	assert(element != NULL);
	assert(index <= vector->size);

	if (vector == NULL) return VECTOR_ERROR;
	if (element == NULL) return VECTOR_ERROR;
	if (index > vector->size) return VECTOR_ERROR;
	if (vector->element_size == 0) return VECTOR_ERROR;

	if (_vector_should_grow(vector))
		if (_vector_adjust_capacity(vector) == VECTOR_ERROR)
			return VECTOR_ERROR;
	
	if (_vector_move_right(vector, index) != VECTOR_SUCCESS)
		return VECTOR_ERROR;

	offset = _vector_offset(vector, index);



	offset = _vector_offset(vector, index);
	memcpy(offset, element, vector->element_size);
	++vector->size;

	return VECTOR_SUCCESS;
}

extern int vector_assign(Vector *vector, size_t index, uint8_t **element)
{
	assert(vector != NULL);
	assert(element != NULL);
	assert(index < vector->size);

	if (vector == NULL) return VECTOR_ERROR;
	if (element == NULL) return VECTOR_ERROR;
	if (index >= vector->size) return VECTOR_ERROR;
	if (vector->element_size == 0) return VECTOR_ERROR;

	_vector_assign(vector, index, element);
}

extern bool vector_is_initialized(const Vector *vector)
{
	return vector->data != NULL;
}

extern size_t vector_byte_size(const Vector *vector)
{
	return vector->size * vector->element_size;
}

extern int vector_destroy(Vector *vector)
{
	assert(vector != NULL);

	if (vector == NULL) return VECTOR_ERROR;

	free(vector->data);
	vector->data = NULL;

	return VECTOR_SUCCESS;
}


// Static
static void _vector_swap(size_t *first, size_t *second)
{
	size_t temp = *first;
	*first = *second;
	*second = temp;
}

static bool _vector_should_grow(Vector *vector)
{
	assert(vector->size <= vector->capacity);
	return vector->size == vector->capacity;
}

static int _vector_adjust_capacity(Vector *vector)
{
	return _vector_reallocate(vector, MAX(1, vector->size * VECTOR_GROWTH_FACTOR));
}

static int _vector_reallocate(Vector *vector, size_t new_capacity)
{
	size_t new_capacity_in_bytes;
	void* old;
	assert(vector != NULL);

	if (new_capacity < VECTOR_MINIMUM_CAPACITY) 
	{
		if (vector->capacity > VECTOR_MINIMUM_CAPACITY)
			new_capacity = VECTOR_MINIMUM_CAPACITY;
		else 
			return VECTOR_SUCCESS;
	}

	new_capacity_in_bytes = new_capacity * vector->element_size;
	old = vector->data;

	if ((vector->data = malloc(new_capacity_in_bytes)) == NULL)  return VECTOR_ERROR;


	memcpy(vector->data, old, vector_byte_size(vector));
}

static void _vector_assign(Vector *vector, size_t index, uint8_t **element)
{
	uint8_t **offset = _vector_offset(vector, index);
	memcpy(offset, element, vector->element_size);
}

static uint8_t** _vector_offset(Vector* vector, size_t index)
{
	return vector->data + (index * vector->element_size);
}

static int _vector_move_right(Vector *vector, size_t index)
{
	assert(vector->size < vector->capacity);

	uint8_t **offset = _vector_offset(vector, vector->size - 1);
	size_t elements_in_bytes = (vector->size - index) * vector->element_size;

	for (size_t i = elements_in_bytes; i > 0; i -= vector->element_size)
	{
		memmove(offset + vector->element_size, offset, vector->element_size);
		offset -= vector->element_size;
	}

	return VECTOR_SUCCESS;
}
