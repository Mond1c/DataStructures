#include "vector.h"

int main(void) {
    vector_t* vec = vector_create();
    int i;
    for (i = 1; i <= 10; ++i) vector_add_element(vec, i);
    vector_print(vec);
    vector_t* new_vec = vector_copy(vec);
    vector_free(vec);
    vector_print(new_vec);
    printf("%d\n", vector_get_element(new_vec, 3));
    vector_free(new_vec);
    return 0;
}
