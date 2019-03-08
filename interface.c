#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#include "tokenizer.c"
#include "history.c"
#define MAX 50

/*
Matthew Iglesias
CS 3432 - Lab 1
Eric Freudenthal
Spring 2019

*/
int main(){
    printf("Enter string: ");
    char buffer[MAX];
    fgets(buffer, MAX, stdin);     //fgets(char *str, int n, FILE *stream)
    printf("Echoed word: %c \n",buffer);

    printf("Testing: %s... \n", buffer);
    
    int lenWord = string_length(buffer);
    printf("String Length: %d \n", lenWord);

    int countWord = count_words(buffer);
    printf("Count Words: %d \n", countWord);

    int start = find_word_start(buffer, 0);
    printf("Beginning word: %d \n",start);

    int end = find_word_end(buffer, 0);
    printf("End of word: %d \n", end);

    char **token = tokenize(buffer);
    printf("Tokenizing\n");
    //char* input = "Hello world";
    //print_tokens(buffer);
    

    printf("Printing tokens: \n");
    print_tokens(token);

    printf("Freeing tokens! \n");
    free_tokens(token);

//Testing the history.h and history.c files
    List *historyList = init_history();
    printf("History Initalized \n");

    add_history(historyList, "Hello World");
    add_history(historyList, "Hello America");
    add_history(historyList, "Hello Texas");
    add_history(historyList, "Hello El Paso");

    printf("Printing History...\n");
    print_history(historyList);

    printf("Get History: \n");
    char *history = get_history(historyList,2);
    printf("%s\n", history);

    printf("Get OUT OF BOUNDS History: \n");
    history = get_history(historyList, 5);
    printf("%s\n", history);

    printf("Freeing History...\n");
    free_history(historyList);
    printf("Done.");
    
    return 0;

}