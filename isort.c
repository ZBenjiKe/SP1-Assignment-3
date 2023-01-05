#include <stdio.h>

#define ARRAY_SIZE 50

void shift_element(int* arr, int i);
void insertion_sort(int* arr, int len);
void printArray(int* arr, int len);

int main() {

    int arr[ARRAY_SIZE];

    for(int i = 0; i < ARRAY_SIZE; i++){
        scanf("%d", (arr + i));
    }

    
/* --------- Block to get array input from a file --------- */

    // FILE* fp = fopen("./HW3_IO/inputs/sort_input.txt", "r");
    // if(fp == NULL){
    //     printf("file wasn't opened");
    //     return -1;
    // }
    // int fileIndex = 0;
    // while(fileIndex < ARRAY_SIZE){
    //     fscanf(fp, "%d", &arr[fileIndex++]);
    // }
    // fclose(fp);
    
/* --------- End of block --------- */

    insertion_sort(arr, ARRAY_SIZE);

    printArray(arr, ARRAY_SIZE);

    return 0;
}

void shift_element(int* arr, int i) {
    for (int j = i; j > 0; j--) {
        *(arr + j) = *(arr + (j - 1));
    }
}

void insertion_sort(int* arr, int len) {
    for (int i = 1; i < len; i++) {
        int temp = *(arr + i);
        int count = 0;
        while ((count < i) && (*(arr + ((i-1) - count)) > *(arr + i))) {
            count++;
        }
        shift_element((arr + (i-count)), count);
        *(arr + (i - count)) = temp;
    }
}

void printArray(int* arr, int len) {
    for(int i = 0; i < len-1; i++) {
        printf("%d,", *(arr+i));
    }
    printf("%d", *(arr+(len-1)));
    printf("\n");
}