#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

int similarWords(char *word, char *keyword);

int main() {

    char keyword[WORD] = {0};
    char decision = 'c';
    char line[LINE] = {0};

    // Get the keyword and decision.
    scanf("%s %c", keyword, &decision);

    // If the keyword appears as a substring in one of the text lines, print the line.
    if(decision == 'a') {
        while(fgets(line, LINE, stdin) != NULL) {
            if(strstr(line, keyword) != NULL) {
                printf("%s", line);
            }
        }

    // Decision == 'b' (instructions are to assume valid input).
    } else {
        char word[WORD] = {0};

        // Scan the text word by word, until the end of the document.
        // If a word's length is equals or longer by one than the keyword's, check similarity.
        // If the word is similar to the keyword, print the word.
        while(scanf("%s", word) > 0) {
            if(strlen(word) == strlen(keyword) || strlen(word) == strlen(keyword) + 1) {
                if(similarWords(word, keyword)) {
                    printf("%s\n", word);
                }
            }
        }
    }
    return 0;
}


// Function to check similarity of a word to the keyword.
// Option 1: they match exactly.
// Option 2: if a single letter is omitted from the word, it will match to the keyword.
int similarWords(char *word, char *keyword){
    
    int result = 0;
    int letter = 0;
    int len = strlen(keyword);

    // Word is same length as keyword, so all letters must match exactly.
    if(strlen(word) == len){
        while((word[letter] == keyword[letter]) && (letter < len)){
            letter++;
        }
        if (letter == len) {
            result = 1;
        }

    // Word is longer than keyword by 1, so all letters, except for one, must match exactly.
    } else if(strlen(word) == len + 1) {
        int mistakes = 0;
        while((mistakes <= 1) && (letter < len)) {
            if (word[letter+mistakes] != keyword[letter]) {
                mistakes++;
            }
            letter++;
        }
        if((letter == len) && (mistakes < 2)) {
            result = 1;
        }
    }
    return result;
}