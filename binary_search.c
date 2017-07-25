/*
 * File name: binary_search.c
 * Author: Jacob Hunt
 * Author email: jacobhuntemail@gmail.com
 * License: MIT https://opensource.org/licenses/MIT
 *          (full text at end of file)
 *
 * Notes:
 *    Implimentation of a Binary Search algorithm.  Finds a value
 *    in a sorted array in logarithmic time of O(log n)
 *    (https://en.wikipedia.org/wiki/Binary_search_algorithm).
 *
 */


#include <stdio.h>

int search(int value, int values[], int arrLen);
void printResult(int num, int result);

int main(void){
    /* Demonstrate Algorithm */

    // Prepare variables
    int result;
    int numToFind;

    int sortedArray[] = {2, 4, 8, 19, 21};
    int arrLen = 5;

    // Test algorithm 4 times
    numToFind = 4;
    result = search(numToFind, sortedArray, arrLen);
    printResult(numToFind, result);

    numToFind = 21;
    result = search(numToFind, sortedArray, arrLen);
    printResult(numToFind, result);

    numToFind = 2;
    result = search(numToFind, sortedArray, arrLen);
    printResult(numToFind, result);

    numToFind = 9;
    result = search(numToFind, sortedArray, arrLen);
    printResult(numToFind, result);

    return 0;
}


int search(int value, int values[], int arrLen) {
    /* Binary Search algorithm */
    int left = 0;
    int right = arrLen;
    int middle = 0;
    while (right - left > 1)
    {
        if (values[middle] == value)
        {
            return middle;
        }
        else if (values[middle] < value)
        {
            left = middle;
        }
        else if (values[middle] > value)
        {
            right = middle;
        }
        else
        {
            break;
        }
        middle = ((right + left) / 2);
    }
    
    return -1;
}

void printResult(int num, int result){
    if (result < 0){
        printf("The number %i is not in the array\n",
               num);
    } else {
        printf("The number %i is at position %i in the array\n",
               num,
               result);
    }
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