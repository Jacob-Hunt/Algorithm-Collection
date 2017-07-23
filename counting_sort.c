/*
 * File name: counting_sort.c
 * Author: Jacob Hunt
 * Author email: jacobhuntemail@gmail.com
 * License: MIT https://opensource.org/licenses/MIT
 *          (full text at end of file)
 *
 * Notes:
 *    Implimentation of a Counting Sort algorithm,
 *    sorts an array of positive ints in linear
 *    time of O(2(n + k)).
 *
 */

#include <stdio.h>

// function prototypes
void sort(int values[], int arraySize, int limit);

// main function demonstrates sort function
int main(void){
    // sample array to be sorted
    int array[8] = {12, 8, 3, 72, 4, 1, 1, 9};

    // get number of entries in array
    int arraySize = sizeof(array)/sizeof(array[0]);

    // sort
    sort(array, arraySize, 100);

    // print results
    for (int i = 0; i < arraySize; i++){
        printf("%i ", array[i]);
    }
    printf("\n");
    return 0;
}

 
// counting sort algorithm, limit is max value of any
// number in the array
void sort(int values[], int arraySize, int limit)
{

    // array for counting values
    int countarray[limit];
    
    // prime the countarray with zeroes
    for (int i = 0; i < limit; i++)
    {
        countarray[i] = 0;
    }
    
    // count numbers in values array
    for (int i = 0; i < arraySize; i++)
    {
        countarray[values[i]] ++;
    }
    
    
    int values_position = 0; // counter to keep track of current position
                             // in values[] for algorithm
                             
    // put numbers back in values array in order                     
    for (int i = 0; i < limit; i++)
    {
        if (countarray[i] != 0)
        {
            for (int j = 0; j < countarray[i]; j++)
            {
                values[values_position] = i;
                values_position ++;
            }
        }
    }
    
    return;
}


/*
 *
 * Copyright 2017 Jacob Hunt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy 
 * of this software and associated documentation files (the "Software"), to deal 
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */
