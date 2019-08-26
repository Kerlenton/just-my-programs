#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE_STACK 255
#define IGCT 8

typedef enum
{
	INT,
	TWIN
}oType;

typedef struct cObject
{
	oType type;
	unsigned char marked;

	struct cObject* next;

	union
	{
		int value;

		struct
		{
			struct cObject* head;
			struct cObject* tail;
		};
	};
}Object;

typedef struct
{
	Object* stack[MAX_SIZE_STACK];
	int stackSize;
	Object* firstObject;
	int numObjects;
	int maxObjects;
}vm;

void push(vm* vm, Object* value)
{
	vm->stack[vm->stackSize++] = value;
}

Object* pop(vm* vm)
{
	return vm->stack[--vm->stackSize];
}

vm* newVm()
{
	vm* newVm = (vm*)malloc(sizeof(vm));
	newVm->stackSize = 0;
	newVm->firstObject = NULL;
	newVm->numObjects = 0;
	newVm-> maxObjects = IGCT;

	return newVm;
}

void mark(Object* object)
{
	if (object->marked) return;

	object->marked = 1;

	if (object->type == TWIN)
	{
		mark(object->head);
		mark(object->tail);
	}
}

void markAll(vm* vm)
{
	for (int i = 0; i < vm->stackSize; i++)
	{
		mark(vm->stack[i]);
	}
}

void marksweep(vm* vm)
{
	Object** object = &vm->firstObject;

	while (*object)
		if (!(*object)->marked)
		{
			Object* unreached = *object;
			*object = unreached->next;
			free(unreached);

			vm->numObjects--;
		}
		else
		{
			(*object)->marked = 0;
			object = &(*object)->next;
		}
}

void gc(vm* vm)
{
	int numObjects = vm->numObjects;
	markAll(vm);
	marksweep(vm);

	vm->maxObjects = vm->numObjects * 2;

	printf("Collected %d objects, %d left\n", numObjects - vm->numObjects, vm->numObjects);
}

Object* newObject(vm* vm, oType type)
{
	if (vm->numObjects == vm->maxObjects) gc(vm);

	Object* object = (Object*)malloc(sizeof(Object));
	object->type = type;
	object->next = vm->firstObject;
	vm->firstObject = object;
	object->marked = 0;

	vm->numObjects++;
	return object;
}

void pushInt(vm* vm, int intV)
{
	Object* object = newObject(vm, INT);
	object->value = intV;

	push(vm, object);
}

Object* pushPair(vm* vm)
{
	Object* object = newObject(vm, TWIN);
	object->tail = pop(vm);
	object->head = pop(vm);

	push(vm, object);

	return object;
}

void printObj(Object* object)
{
	switch (object->type)
	{
	    case INT:
		printf("%d", object->value);
		break;

		case TWIN:
		printf("(");
		printObj(object->head);
		printf(", ");
		printObj(object->tail);
		printf(")");
	}
}

void freeVm(vm* vm)
{
	vm->stackSize = NULL;

	gc(vm);
	free(vm);
}

void first_test() {
	printf("1: Objects on the stack are preserved.\n");
	vm* vm = newVm();
	pushInt(vm, 1);
	pushInt(vm, 2);

	gc(vm);
	freeVm(vm);
}

void second_test() {
	printf("2: Unreached objects are collected.\n");
	vm* vm = newVm();
	pushInt(vm, 1);
	pushInt(vm, 2);
	pop(vm);
	pop(vm);

	gc(vm);
	freeVm(vm);
}

void third_test() {
	printf("3: Reach the nested objects.\n");
	vm* vm = newVm();
	pushInt(vm, 1);
	pushInt(vm, 2);
	pushPair(vm);
	pushInt(vm, 3);
	pushInt(vm, 4);
	pushPair(vm);
	pushPair(vm);

	gc(vm);
	freeVm(vm);
}

void another_test() {
	printf("4: Cycles.\n");
	vm* vm = newVm();
	pushInt(vm, 1);
	pushInt(vm, 2);
	Object* a = pushPair(vm);
	pushInt(vm, 3);
	pushInt(vm, 4);
	Object* b = pushPair(vm);

	a->tail = b;
	b->tail = a;

	gc(vm);
	freeVm(vm);
}

void performance() {
	printf("Performance of GC.\n");
	vm* vm = newVm();

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 20; j++) {
			pushInt(vm, i);
		}

		for (int k = 0; k < 20; k++) {
			pop(vm);
		}
	}
	freeVm(vm);
}

int main(int argc, const char** argv) {
	first_test();
	second_test();
	third_test();
	another_test();
	performance();

	system("PAUSE");
	return 0;
}
