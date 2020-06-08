#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "vector.h"

int main()
{
	Vector *v = (Vector*)malloc(sizeof(Vector));
	uint8_t *p = "helllo";
	int64_t q = 8;
	vector_setup(v, 5, sizeof(uint8_t*));
	vector_push_back(v, &p);
	printf("%s", v->data[0]);

	system("PAUSE");
	return 0;
}

int vector_setup(Vector* vector, size_t capacity, size_t element_size) 
{
	assert(vector != NULL);

	if (vector == NULL) return VECTOR_ERROR;

	vector->size = 0;
	vector->capacity = MAX(VECTOR_MINIMUM_CAPACITY, capacity);
	vector->element_size = element_size;
	vector->data = malloc(vector->capacity * element_size);

	return vector->data == NULL ? VECTOR_ERROR : VECTOR_SUCCESS;
}

int vector_copy(Vector* destination, Vector* source) 
{
	assert(destination != NULL);
	assert(source != NULL);
	assert(vector_is_initialized(source));
	assert(!vector_is_initialized(destination));

	if (destination == NULL) return VECTOR_ERROR;
	if (source == NULL) return VECTOR_ERROR;
	if (vector_is_initialized(destination)) return VECTOR_ERROR;
	if (!vector_is_initialized(source)) return VECTOR_ERROR;

	destination->size = source->size;
	destination->capacity = source->size * 2;
	destination->element_size = source->element_size;

	destination->data = malloc(destination->capacity * source->element_size);
	if (destination->data == NULL) return VECTOR_ERROR;

	memcpy(destination->data, source->data, vector_byte_size(source));

	return VECTOR_SUCCESS;
}

int vector_copy_assign(Vector* destination, Vector* source) 
{
	assert(destination != NULL);
	assert(source != NULL);
	assert(vector_is_initialized(source));
	assert(vector_is_initialized(destination));

	if (destination == NULL) return VECTOR_ERROR;
	if (source == NULL) return VECTOR_ERROR;
	if (!vector_is_initialized(destination)) return VECTOR_ERROR;
	if (!vector_is_initialized(source)) return VECTOR_ERROR;

	vector_destroy(destination);

	return vector_copy(destination, source);
}

int vector_move(Vector* destination, Vector* source) 
{
	assert(destination != NULL);
	assert(source != NULL);

	if (destination == NULL) return VECTOR_ERROR;
	if (source == NULL) return VECTOR_ERROR;

	*destination = *source;
	source->data = NULL;

	return VECTOR_SUCCESS;
}

int vector_move_assign(Vector* destination, Vector* source)
{
	vector_swap(destination, source);
	return vector_destroy(source);
}

int vector_swap(Vector* destination, Vector* source) 
{
	void* temp;

	assert(destination != NULL);
	assert(source != NULL);
	assert(vector_is_initialized(source));
	assert(vector_is_initialized(destination));

	if (destination == NULL) return VECTOR_ERROR;
	if (source == NULL) return VECTOR_ERROR;
	if (!vector_is_initialized(destination)) return VECTOR_ERROR;
	if (!vector_is_initialized(source)) return VECTOR_ERROR;

	_vector_swap(&destination->size, &source->size);
	_vector_swap(&destination->capacity, &source->capacity);
	_vector_swap(&destination->element_size, &source->element_size);

	temp = destination->data;
	destination->data = source->data;
	source->data = temp;

	return VECTOR_SUCCESS;
}

/* Insertion */
int vector_push_back(Vector* vector, uint8_t** element)
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
	//*offset = *element;
}

void* _vector_offset(Vector* vector, size_t index)
{
	return vector->data + (index * vector->element_size);
}
