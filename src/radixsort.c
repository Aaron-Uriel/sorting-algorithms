#include <math.h>

#include "sort.h"

void radixsort(int array[], int first, int last) {
    int max_number = 0;
    for (int i = 0; i < last; i += 1) {
        if (max_number < array[i]) { max_number = array[i]; }
    }
    int digits = log(max_number); 

    for (uint8_t current_digit = 1;
         current_digit <= digits;
         current_digit += 1)
    {
        
    }
}
