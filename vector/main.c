#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "vector.h"

int main(int argc, char* argv[])
{
	Vector *vector = (Vector*)malloc(sizeof(Vector));
	vector_setup(vector, 1, REAL_ELEM);

	Vector *vector1 = (Vector*)malloc(sizeof(Vector));
	vector_setup(vector1, 4, REAL_ELEM);

	vector1->data.real = NULL;
	printf("%d\n\n", vector_copy(vector1, vector));

	printf("%d\n", vector->element_size);
	printf("%d\n", vector->size);
	printf("%d\n\n", vector->capacity);

	printf("%d\n", vector1->element_size);
	printf("%d\n", vector1->size);
	printf("%d\n", vector1->capacity);

	putchar('\n');
	system("PAUSE");
	return 0;
}

extern int vector_setup(Vector *vector, size_t capacity, vtype type)
{
	assert(vector != NULL);

	if (vector == NULL) return VECTOR_ERROR;

	vector->capacity = MAX(VECTOR_MINIMUM_CAPACITY, capacity);
	vector->size = 0;
	vector->type = type;

	switch (type)
	{
	case DECIMAL_ELEM:
		vector->element_size = sizeof(int64_t);
		vector->data.decimal = malloc(vector->capacity * vector->element_size);
		return vector->data.decimal == NULL ? VECTOR_ERROR : VECTOR_SUCCESS;
		break;
	case REAL_ELEM:
		vector->element_size = sizeof(double);
		vector->data.decimal = malloc(vector->capacity * vector->element_size);
		return vector->data.real == NULL ? VECTOR_ERROR : VECTOR_SUCCESS;
		break;
	case STRING_ELEM:
		vector->element_size = sizeof(uint8_t*);
		vector->data.decimal = malloc(vector->capacity * vector->element_size);
		return vector->data.string == NULL ? VECTOR_ERROR : VECTOR_SUCCESS;
		break;
	}
}

extern int vector_copy(Vector *dst, Vector *src)
{
	assert(dst != NULL);
	assert(src != NULL);
	assert(vector_is_initialized(src));
	assert(!vector_is_initialized(dst));

	if(dst == NULL) return VECTOR_ERROR;
	if (src == NULL) return VECTOR_ERROR;
	if (vector_is_initialized(dst)) return VECTOR_ERROR;
	if (!vector_is_initialized(src)) return VECTOR_ERROR;

	dst->size = src->size;
	dst->capacity = src->capacity;
	dst->element_size = src->element_size;
	dst->type = src->type;

	switch (src->type)
	{
	case DECIMAL_ELEM:
		dst->data.decimal = malloc(dst->capacity * src->element_size);
		if (dst->data.decimal == NULL) return VECTOR_ERROR;
		memcpy(dst->data.decimal, src->data.decimal, vector_byte_size(src));
		break;
	case REAL_ELEM:
		dst->data.real = malloc(dst->capacity * src->element_size);
		if (dst->data.real == NULL) return VECTOR_ERROR;
		memcpy(dst->data.real, src->data.real, vector_byte_size(src));
		break;
	case STRING_ELEM:
		dst->data.string = malloc(dst->capacity * src->element_size);
		if (dst->data.string == NULL) return VECTOR_ERROR;
		memcpy(dst->data.string, src->data.string, vector_byte_size(src));
		break;
	}

	return VECTOR_SUCCESS;
}

/*extern int vector_copy_assign(Vector *dst, Vector *src)
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

extern int vector_move(Vector *dst, Vector *source)
{
	assert(dst != NULL);
	assert(source != NULL);

	if (dst == NULL) return VECTOR_ERROR;
	if (source == NULL) return VECTOR_ERROR;

	*dst = *source;
	source->data = NULL;

	return VECTOR_SUCCESS;
}

extern int vector_move_assign(Vector *dst, Vector *src)
{
	vector_swap(dst, src);
	return vector_destroy(src);
}

extern int vector_swap(Vector *dst, Vector *src)
{
	void *temp;

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
}*/

extern bool vector_is_initialized(const Vector *vector)
{
	switch (vector->type)
	{
	case DECIMAL_ELEM:
		return vector->data.decimal != NULL;
		break;
	case REAL_ELEM:
		return vector->data.real != NULL;
		break;
	case STRING_ELEM:
		return vector->data.string != NULL;
		break;
	}

	return VECTOR_ERROR;
}

extern size_t vector_byte_size(const Vector *vector)
{
	return vector->size * vector->element_size;
}

/*extern int vector_destroy(Vector *vector)
{
	assert(vector != NULL);

	if (vector == NULL) return VECTOR_ERROR;

	free(vector->data);
	vector->data = NULL;

	return VECTOR_SUCCESS;
}

// Insertion



extern int vector_push_back(Vector *vector, void *element)
{
	assert(vector != NULL);
	assert(element != NULL);

	if (_vector_shlould_grow(vector))
	{
		if (_vector_adjust_capacity(vector) == VECTOR_ERROR)
			return VECTOR_ERROR;
	}

	_vector_assign(vector, vector->size, element);

	++vector->size;
	return VECTOR_SUCCESS;
}



//---------------------------



// Static
static void _vector_swap(size_t *first, size_t *second)
{
	size_t temp = *first;
	*first = *second;
	*second = temp;
}

static bool _vector_shlould_grow(Vector *vector)
{
	assert(vector->size <= vector->capacity);
	return vector->size == vector->capacity;
}

static int _vector_adjust_capacity(Vector *vector)
{
	return _vector_realocate(vector, MAX(1, vector->size * VECTOR_GROWTH_FACTOR));
}

static int _vector_realocate(Vector *vector, size_t new_capacity)
{
	size_t new_capacity_in_bytes;
	void *old;
	assert(vector != NULL);

	if (new_capacity < VECTOR_MINIMUM_CAPACITY)
	{
		if (vector->capacity > VECTOR_MINIMUM_CAPACITY)
		{
			new_capacity = VECTOR_MINIMUM_CAPACITY;
		}
		else
		{
			return VECTOR_SUCCESS;
		}
	}

	new_capacity_in_bytes = new_capacity * vector->element_size;
	old = vector->data;

	if ((vector->data = malloc(new_capacity_in_bytes)) == NULL)
	{
		return VECTOR_ERROR;
	}

	memcpy(vector->data, old, vector_byte_size(vector));
	vector->capacity = new_capacity;
	free(old);

	return VECTOR_SUCCESS;
}

static void _vector_assign(Vector *vector, size_t index, void *element)
{
	void *offset = _vector_offset(vector, index);
	memcpy(offset, element, vector->element_size);
}

void* _vector_offset(Vector* vector, size_t index)
{
	return vector->data + (index * vector->element_size);
}*/
