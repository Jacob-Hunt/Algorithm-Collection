/*
 *
 * File name: largest_prime.c
 * Author: Jacob Hunt
 * Author email: jacobhuntemail@gmail.com
 * License: MIT https://opensource.org/licenses/MIT
 *          (full text at end of file)
 *
 * Notes:
 *    Calculates the largest prime factor of NUMBER_TO_FACTOR using
 *    a modified Trial Division algorithm
 *    (https://en.wikipedia.org/wiki/Trial_division)
 *
 */

// imports and constant definitions
#include <stdio.h>
#include <math.h>

#define NUMBER_TO_FACTOR 600851475143

// function prototype
unsigned long long largest_prime(unsigned long long n);


// * * * BEGIN PROGRAM EXECUTION * * *

int main(void){
  /* Demonstrate algorithm */

  unsigned long long result = largest_prime(NUMBER_TO_FACTOR);

  printf("The largest prime factor of %llu is %llu\n",
          NUMBER_TO_FACTOR, result);

  return 0;
}


unsigned long long largest_prime(unsigned long long num){
  /* Calculate the largest prime factor of a number */

  // variable to contain remainder
  unsigned long long r = num;

  // variable to contain largest prime
  unsigned long long lp = num;

  // if remainder is divisible by 2, then 2 is a factor
  if (r % 2 == 0){
    lp = 2;
  }

  // factor out all the twos until number is odd
  while (r % 2 == 0){
    r /= 2;
  }

  // since odd numbers cannot have even factors, and every composite
  // number has a factor less-than-or-equal-to its square root,
  // try to factor out every odd number until the square root of
  // remainder is reached
  for (unsigned long long i = 3; i <= sqrt(r); i += 2){
    // if a factor has been found...
    if (r % i == 0){
      // ...factor out every instance of it
      while (r % i == 0){
        r /= i;
      }
      // set the "largest prime" variable to value of current factor
      lp = i;
    }
  }
  // since the final remainder will either be 1 or the final prime
  // factor, test to see weather the remainder is larger than the last
  // prime factor from the loop and, if so, assign the remainder's value
  // to the "largest prime" variable
  if (r > lp){
    lp = r;
  }

  // success!
  return lp;
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
