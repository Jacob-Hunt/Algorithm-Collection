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
 *    time of O(n + k).
 *
 */


// * * * LIBRARIES * * * //
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// * * * CONSTANT DEFINITIONS * * * //
#define LENGTH 10
#define RANGE 256


// * * * FUNCTION PROTOTYPES * * * //
void sort(int values[], int arraySize, int limit);
void randomize(int *arr, int arrlen, int range);
void printarr(int *arr, int arrlen);


// * * * MAIN FUNCTION * * * //
int main(void){
  /* Demonstrate algorithm */

  // Seed the pseudo-random number generator
  srand(time(NULL));

  // Introduce the program
  printf("\n\n");
  printf("* * * THE AMAZING MAGIC SORTING ALGORITHM * * *\n\n");

  // Generate and print an array of random ints
  int numbers[LENGTH];
  randomize(numbers, LENGTH, RANGE);

  printf("An array of random integers:\n");
  printarr(numbers, LENGTH);
  printf("\n");

  // Sort the array
  sort(numbers, LENGTH, RANGE);
  printf("Putting it in the magic hat, tapping three times...\n\n");

  // Print results
  printf("The numbers are sorted!\n");
  printarr(numbers, LENGTH);
  printf("\nAnd now the world is a better place.\n\n\n");

  return 0;
}

 
// * * * SORTING ALGORITHM * * * //
void sort(int values[], int arrlen, int range){
  /* Implimentation of counting sort,
     see https://en.wikipedia.org/wiki/Counting_sort */

  // Array for counting values
  int countarray[range];

  // Set all values in countarray to 0
  for (int i = 0; i < range; i++){
    countarray[i] = 0;
  }

  // Count numbers in values[]
  for (int i = 0; i < arrlen; i++){
    countarray[values[i]] ++;
  }

  // Counter to keep track of algorithm's current position in values[]
  int valuesPos = 0;

  // put numbers back in values array in order                     
  for (int i = 0; i < range; i++){
    if (countarray[i] != 0){
      for (int j = 0; j < countarray[i]; j++){
        values[valuesPos] = i;
        valuesPos ++;
      }
    }
  }
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
