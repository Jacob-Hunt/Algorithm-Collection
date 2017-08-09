/*
 * File name: random_array.c
 * Author: Jacob Hunt
 * Author email: jacobhuntemail@gmail.com
 * License: MIT https://opensource.org/licenses/MIT
 *          (full text at end of file)
 *
 * Notes:
 *    Generates an array of LENGTH random integers between 0 and RANGE,
 *    ideal for testing sorting algorithms.
 *
 */

// * * * LIBRARIES * * * //
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// * * * DEFINITIONS * * * //
#define LENGTH 10
#define RANGE 256


// * * * FUNCTION PROTOTYPES * * * //
void randomize(int *arr, int arrlen, int range);
void printarr(int *arr, int arrlen);


// * * * MAIN FUNCTION * * * //
int main(void){
  /* Demonstrate algorithm */

  // Array to be randomized
  int numbers[LENGTH];

  // Seed pseudo-random number generator
  srand(time(NULL));

  // Fill numbers[] with random ints
  randomize(numbers, LENGTH, RANGE);

  // Print numbers[]
  printarr(numbers, LENGTH);

  return 0;
}


// * * * HELPER FUNCTIONS * * * //
void randomize(int *arr, int arrlen, int range){
  /* Fill array "arr" of length "arrlen" with random ints between 0
     and "range" */

  for(int i = 0; i < arrlen; i++) 
  {
     arr[i] = rand() % range;
  }
}

void printarr(int *arr, int arrlen){
  /* Print array of ints "arr" of length "arrlen" */
  printf("[");
  for(int i = 0; i < arrlen - 1; i++){
    printf("%i, ", arr[i]);
  }
  printf("%i]\n", arr[arrlen - 1]);
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
