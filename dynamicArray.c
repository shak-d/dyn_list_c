#include "dynamicArray.h"

DArray* create_darray(int capacity, int datatypesize)
{
    DArray* array = malloc(sizeof(DArray));
    array->elements = malloc(datatypesize*capacity);//capacity * datatypesize
    array->capacity = capacity;
    array->elementsize = datatypesize;
    array->size = 0;
    return array;
}

void delete_darray(DArray* array)
{
    free(array);
}

int is_darray_empty(DArray* array)
{
    if (array != NULL && array->size > 0)
        return 0;
    return 1;
}

int push_darray(DArray* array, void* element)
{
    if (array == NULL)
        return 0;

    if (array->size == array->capacity) {
            
       array->elements = realloc(array->elements, sizeof(array->elements) + (5 * sizeof(array->elementsize)));//array->elementsize
        array->capacity = array->capacity + 4;

    }
    memcpy((char*)array->elements + (array->size * array->elementsize), element, array->elementsize);
    //array->elements[array->size] = element;
    array->size = array->size + 1;
    return 1;
}

int insert_darray(DArray* array, void* element, int position)
{
    if (array == NULL || position < 0)
        return 0;

    if (position >= array->size) {
        push_darray(array, element);
        return 1;
    }
    if (array->size == array->capacity) {

        array->elements = realloc(array->elements, sizeof(array->elements) + (5 * sizeof(array->elementsize)));
        array->capacity = array->capacity + 4;

    }

    for (int i = array->size-1; i >= position; i--) {
        
        //array->elements[i + 1] = array->elements[i];
        memcpy((char*)array->elements + ((i + 1) * array->elementsize), (char*)array->elements + (i * array->elementsize), array->elementsize);
    
    }
    //array->elements[position] = element;
    memcpy((char*)array->elements + (position * array->elementsize), element, array->elementsize);
    array->size = array->size + 1;
    return 1;
}

int pop_darray(DArray* array)
{
    if(array == NULL || array->size < 1)
        return 0;
    array->size = array->size - 1;
}

int delete_element_darray(DArray* array, int position)
{
    if(array == NULL ||position < 0)
        return 0;
    if (position >= array->size) {
        pop_darray(array);
        return 1;
    }
    for (int i = position; i < array->size; i++) {
    
        //array->elements[i] = array->elements[i + 1];
        memcpy((char*)array->elements + (i * array->elementsize), (char*)array->elements + ((i + 1) * array->elementsize), array->elementsize);

    }
    array->size = array->size - 1;
    return 1;
}

void* get_element_darray(DArray* array, int position)
{
    if(array == NULL || position < 0 || position > array->size)
        return NULL;
    return (char*)array->elements + (position * array->elementsize);
    //return array->elements[position];
}

int get_darray_size(DArray* array)
{
    if(array == NULL)
        return 0;
    return array->size;
}

DArrayIterator* create_darray_iterator(DArray* array)
{
    if(array == NULL)
        return NULL;
    DArrayIterator* iterator = malloc(sizeof(DArrayIterator));
    iterator->array = array;
   // iterator->current = array->elements[0];
    iterator->current = array->elements;
    iterator->position = 0;
    return iterator;
}

void delete_darray_iterator(DArray* array)
{
    if (array == NULL)
        return;
    free(array);
    array = NULL;
    return;
}

int done_darray_iteration(DArrayIterator* iterator)
{
    if (iterator != NULL && iterator->position == iterator->array->size)
        return 1;
    return 0;
}

void* get_darray_iteration_elem(DArrayIterator* iterator)
{
    if (iterator != NULL)
        return iterator->current;
    return NULL;
}

void* next_darray_iteration(DArrayIterator* iterator)
{
    if (iterator != NULL && iterator->position != iterator->array->size) {
    
        iterator->position = iterator->position + 1;
        //iterator->current = iterator->array->elements[iterator->position];
        iterator->current = (char*)iterator->array->elements + (iterator->position * iterator->array->elementsize);
        return (iterator->current);
    
    }
    return NULL;
}
