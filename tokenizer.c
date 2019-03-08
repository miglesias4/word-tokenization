#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/*
Matthew Iglesias
CS 3432 - Lab 1
Eric Freudenthal
Spring 2019

*/


/* Counts the number of characters in the string argument. */
int string_length(char* s){
    int counter = 0;
    for(int i = 0; s[i] != '\0'; i++){
        counter += 1;
    }
    return counter;

}

/* Evaluates if the character c is an acceptable character for
   a token. Acceptable characters include any alphanumeric or
   special character. Unacceptable characters include any
   whitespace or control characters.
   Returns 0 if not, 1 if yes. */
char is_valid_character(char c){
    if(c >= 32){            //ASCII respresentaion any numeric value greater than a space
        return '1';
    }
    return '0';

}

/* Finds the next word in the string. 
   For example, given an input of "  my cake" the function
   should return "my cake". */
int find_word_start(char* str, int st){
    int i;
    int result = 0;

    for(i = st; str[i] != '\0'; i++){     //Starts with index st as given by user
        if(str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0'){
            result = i + 1;
            break;
        }
    }
    return result;
}

/* Finds the end of current word.
   For example, given an input of "my cake" the function
   should return " cake". */
int find_word_end(char* str, int st){
    int i;
    int result = 0;

    for(i = st; str[i] != '\0'; i++){     //Starts with the end index
        if((str[i + 1] == ' ') || (str[i + 1] == '\0')){
            result = i;
            break;
        }
    }
    return result;
}

/* Counts the number of words in the string argument. */
int count_words(char* word){
    int count = 0;
    int index;

    for(index = 0; word[index] != '\0'; index++){
        if(index == 0 && word[index] != ' '){     
            count += 1;     //Incremented iff word is passed by is_valid_character
        }
        if(word[index] == ' ' && word[index + 1] != ' ' && word[index + 1] != '\0'){
            count += 1;
        }
    }

    return count;

}

/* Prints all tokens. */
void print_tokens(char** tokens){
    int i;
    for(i = 0; **tokens != '\0'; i++){
        printf("%s\n", tokens[i]);
    }

}

/* Frees all tokens and the array containing the tokens. */
void free_tokens(char** tokens){
    char** t = tokens; 
    while(**t != '\0'){
        free(*tokens);
        t++;
    }
}

/* Tokenizes the string argument into an array of tokens.
   For example, "hello world string" would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" */

//Contributions from Matt Montoya, Yamel Hernandez, Hiram Rios and Jorge Felix helped me understand the use and
//the necessary knowledge to utilize this method in this lab as well as in future CS labs. Tokenizing words and
//implementing them in a 2D array structure.

char **tokenize(char* str){  
    int wordsNum = count_words(str); //Word counter
    int startWord = 0;
    int endWord = 0;
    int i, j;
    int wordLen;
    int charIndex;
    char **word = malloc(wordsNum * sizeof(char*)+1); //Stores the word in char array 
    word[wordsNum] = (char*) malloc(sizeof(char)); //Malloc to allocate space for the word
    *word[wordsNum] = '\0';
  
    for(i = 0; i < wordsNum; i++){ //Number of words that will be added
        if(i == 0){ //First word starting at index 0
            endWord = find_word_end(str, startWord);
            word[i] = (char*) malloc((endWord + 2) * sizeof(char)); //Implementing malloc to current word
            for(j = 0; j < endWord+1; j++){ //Enter word into position of the string array
	            word[i][j] = str[j];
            }
            word[i][endWord+1] = '\0'; 
        }
        else{
            startWord = find_word_start(str, endWord); //Locates next word that follows previous word
            charIndex = startWord; //Used as a pointer of that next word
            endWord = find_word_end(str, startWord);
            wordLen = endWord - startWord; //Length of the word being tokenized
            word[i] = (char*) malloc((wordLen + 2) * sizeof(char)); //Implement malloc to current word
            for(j = 0; j < wordLen + 1; j++){
	            word[i][j] = str[charIndex];
	            charIndex++;
            }
            word[i][endWord + 1] = '\0';
        }
    }

  return word; //Returns the token string
}

