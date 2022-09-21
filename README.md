# Distinct-Word-Sorting

## Summary
This collection of files was originally a part of my coursework for CSCI 2275(CU Boulder), and I decided to display my work for this assignment. The files of significance are in the **code_1** folder, and **app_1** folder, where the functions and main.cpp file exist.

The essence of this program is to :
1. Read a file with unknown size and store its contents in a dynamic array.
2. Store, search and iterate through data in an array of structs.
3. Use array doubling via dynamic memory to increase the size of the array.

## Specifics
More specifically, the program will take in a file input and analyze the word frequency of the document, without knowing the amount of words in the document prior to exceution of the program. The program will take in three additional arguments on top of the original program call(`./run_app_1 25 document.txt ignoreWords.txt`):
- The first argument is a positive integer `n` which will be used to analyse the word frequency and statistical probability of the word starting at index `n` and ending at index `n+10` ( next 10 words). 
- The program will go through each word in `document.txt` and store it in an array of distinct words. If a word in the `document.txt` matches up with a word from `ignoreWords.txt`(i.e a word that should be ignored/not signifcant), then it won't be stored in the array.
- The third argument is a text file that has words that should be ignored, separated by line breaks(`'\n'`). A function that I've written will store all of the ignore words in an array to make it easier to compare with.

