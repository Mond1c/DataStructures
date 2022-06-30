#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int* arr;
    int size;
    int capacity
} vector_t;


vector_t* vector_create() {
    vector_t* this = malloc(sizeof(vector_t));
    this->arr = malloc(sizeof(int) * 2);
    return this;
}

vector_t* vector_copy(vector_t* this) {
    vector_t* new_this = malloc(sizeof(vector_t));
    new_this->capacity = this->capacity;
    new_this->size = this->size;
    new_this->arr = malloc(sizeof(int) * this->capacity);
    int i;
    for (i = 0; i < this->size; ++i) {
        new_this->arr[i] = this->arr[i];
    }
    return new_this;
}

void vector_free(vector_t* this) {
    if (this == NULL) return;
    if (this->arr != NULL) free(this->arr);
    free(this);
}

void vector_add_memory(vector_t* this) {
    if (this->capacity == 0) this->capacity = 1;
    this->capacity *= 2;
    int i;
    this->arr = realloc(this->arr, sizeof(int) * this->capacity);
}

int vector_is_empty(vector_t* this) {
    return this->size == 0;
}

int vector_get_size(vector_t* this) {
    return this->size;
}

void vector_add_element(vector_t* this, int element) {
    if (this->size == this->capacity) vector_add_memory(this);
    this->arr[this->size++] = element;
}

int vector_get_element(vector_t* this, int index) {
    return this->arr[index];
}

void vector_print(vector_t* this) {
    int i;
    for (i = 0; i < this->size; ++i) printf("%d ", this->arr[i]);
    printf("\n");
}

