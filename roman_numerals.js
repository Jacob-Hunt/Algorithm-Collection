/*
 * File name: roman_numerals.js
 * Author: Jacob Hunt
 * Author email: jacobhuntemail@gmail.com
 * License: MIT https://opensource.org/licenses/MIT
 *          (full text at end of file)
 *
 * Notes:
 *    Algorithm to convert a positive integer with a value less
 *    than 4000 into a roman numeral.
 *
 */

var romans = [
  [1000, 'M'],
  [900, 'CM'],
  [500, 'D'],
  [400, 'CD'],
  [100, 'C'],
  [90, 'XC'],
  [50, 'L'],
  [40, 'XL'],
  [10, 'X'],
  [9, 'IX'],
  [5, 'V'],
  [4, 'IV'],
  [1, 'I']
];

function toRoman(num) {
  /* Takes a number and returns roman numeral equivilant */

  var romanNum = "";
  for (var i=0, len=romans.length; i < len; i++){
    if (num >= romans[i][0]){
      romanNum += romanDivide(num, romans[i]);
      num %= romans[i][0];
    }
  }
  return romanNum;
}

function romanDivide(number, conversionKey){
  /* Helper function for toRoman() */
  returnString = "";
  for (var i = 0, n = Math.floor(number / conversionKey[0]); i < n; i++){
    returnString += conversionKey[1];
  }
  return returnString;
}

// Test algorithm
console.log(toRoman(144));
console.log(toRoman(42));
console.log(toRoman(3254));

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