#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 8

void FillArray(int *arr, int size);

int main(){
    FILE *file;
    file = fopen("automated_outputs.txt", "a");

    if (file == NULL){
        printf("Failed to open file\n");
        return 1;
    }

    srand(time(NULL));
    int arr[ARR_SIZE];
    double avg = 0;
    int times = 10000;
    for (int j = 0; j < times; j++){
        FillArray(arr, ARR_SIZE);

        int correct_guesses = 0;
        int ones_remaining = 4;
        int twos_remaining = 4;

        for (int i = 0; i < ARR_SIZE; i++){
            int num;
            if(ones_remaining >= twos_remaining){
                num = 1;
            }
            else{
                num = 2;
            }
            if (arr[i] == 1) {
                ones_remaining--;
            }
            else{
                twos_remaining--;
            }

            if(num == arr[i]){
                correct_guesses++;
            }
        }

        char thingy[7];
        snprintf(thingy, sizeof(thingy), "%.3f\n", correct_guesses/(8.0));
        fprintf(file, "%.3f\n", correct_guesses/(8.0));
        avg += correct_guesses/(8.0);
    }
    avg /= times;
    printf("avg = %lf\n", avg);
    fclose(file);
    return 0;
}

void FillArray(int *arr, int size){
    int ones = size/2;
    int twos = size/2;

    for (int i = 0; i < size; i++){
        srand(rand());
        int num = rand()%2+1;
        if((num == 1 && ones > 0) || twos == 0){
            arr[i] = 1;
            ones--;
        }
        else{
            arr[i] = 2;
            twos--;
        }
    }
}
