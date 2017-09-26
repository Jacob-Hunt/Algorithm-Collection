/*
 * File name: pig_latin.js
 * Author: Jacob Hunt
 * Author email: jacobhuntemail@gmail.com
 * License: MIT https://opensource.org/licenses/MIT
 *          (full text at end of file)
 *
 * Notes:
 *    Converts a string into pig latin; assumes that
 *    the string is a single english word written in
 *    lowercase.
 *
 */

function toPigLatin(str) {
  // convert word to pig latin

  if(isVowel(str[0])){
    return str + 'way';
  } else {
    var indexOfFirstVowel = str.split('').findIndex(isVowel);
    return str.slice(indexOfFirstVowel)
         + str.slice(0, indexOfFirstVowel)
         + 'ay';
  }
}

function isVowel(char){
  // checks if a character is a vowel
  var vowels = ['a', 'e', 'i', 'o', 'u'];
  return vowels.find(function(vowel){
    return char===vowel;
  });
}

// test algorithm
console.log(toPigLatin("clove"));
console.log(toPigLatin("pickle"));
console.log(toPigLatin("apple"));

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