#pragma once
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdlib.h>
typedef struct DynamicArray {

    void* elements;

    //size of the entire array
    int capacity;

    //size of the single element
    int elementsize;

    //size of the used space
    int size;

}DArray;


typedef struct DArrayIterator {

    DArray* array;

    //current element
    void* current;

    //index in the array
    int position;

}DArrayIterator;

//Creates a new dynamic array
DArray* create_darray(int capacity, int datatypesize);

//cleans up the memory from the array
void delete_darray(DArray* array);

//return true if the array is empty
int is_darray_empty(DArray* array);

//adds and element at the end of the array
int push_darray(DArray* array, void* element);

//adds an element in the array in a given position
int insert_darray(DArray* array, void* element, int position);

//removes an element from the end of the array
int pop_darray(DArray* array);

//deletes an element from the array at a given position
int delete_element_darray(DArray* array, int position);

//return a given element from the array
void* get_element_darray(DArray* array, int position);

//return the amount of elements in the array
int get_darray_size(DArray* array);

//creates a new dynamic array iterator
DArrayIterator* create_darray_iterator(DArray* array);


//cleans up the memory from the iterator
void delete_darray_iterator(DArray* array);

//returns 1 if the array end is reached
int done_darray_iteration(DArrayIterator* iterator);

//get the current element of the iteration
void* get_darray_iteration_elem(DArrayIterator* iterator);

//return the next element in the array
void* next_darray_iteration(DArrayIterator* iterator);

#endif // !DYNAMICARRAY_H
