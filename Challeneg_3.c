#include <stdio.h>
#include <stdlib.h>

int populate(int* , int);
int insertF(int*, int);
int insertL(int*, int);
int Update(int*, int);
int deleteF(int*, int);
int deleteL(int*, int);
int* segEven(int*, int, int*);
int* segOdd(int*, int, int*);

int main(){

    int size;

    printf("Please enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("\nPopulate the array\n");

    populate(arr , size);

    int stop = 1;

    do{
        int choice;
        int ocount = 0;
        int ecount = 0;
        int* even;
        int* odd;

        printf("\n");
        printf("\n1. Do you want to add a value in the first index?\n");
        printf("2. Do you want to add a value in the last index?\n");
        printf("3. Do you want to update the array? \n");
        printf("4. Do you want to delete the first index?\n");
        printf("5. Do you want to delete the last index?\n");
        printf("6. Do you want to get the even numbers?\n");
        printf("7. Do you want to get the odd numbers?\n");
        printf("8. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch(choice){

            case 1: insertF(arr, size);
                    break;

            case 2: insertL(arr, size);
                    break;

            case 3: Update(arr, size);
                    break;

            case 4: deleteF(arr, size);
                    break;

            case 5: deleteL(arr, size);
                    break;

            case 6: even = segEven(arr, size, &ecount);

                    printf("\nResults for Even: ");
                    for(int i = 0; i < ecount; i++){
                        printf("%d ", even[i]);
                    }

                    break;

            case 7: odd = segOdd(arr, size, &ocount);

                    printf("\nResults for Odd: ");
                    for(int i = 0; i < ocount; i++){
                        printf("%d ", odd[i]);
                    }

                    break;

            case 8: stop = !stop;
                    break;

            default: printf("Invalid Input.");
                     continue;

        }
    }while(stop);

    printf("Thank you for using my program 0w0");

    return 0;
}

int populate(int* arr, int size){

    for(int i = 0; i < size; i++){
        printf("Array [%d]: ", i);
        scanf("%d", &arr[i]);
    }

}

int insertF(int* arr, int size){

    int val;

    printf("\nEnter a value in the first index: ");
    scanf("%d", &val);

    arr[0] = val;

    printf("\nResults: ");

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

}

int insertL(int* arr, int size){

    int val;

    printf("\nEnter a value in the last index: ");
    scanf("%d", &val);

    arr[size - 1] = val;

    printf("\nResults: ");

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

}

int Update(int* arr, int size){

    int index, val;

    printf("\nEnter an index to update the value: ");
    scanf("%d", &index);

    printf("\nInput Value: ");
    scanf("%d", &val);

    arr[index] = val;

    printf("\nResults: ");

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

}

int deleteF(int* arr, int size){

    arr[0] = 0;

    printf("\nResults: ");

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

}

int deleteL(int* arr, int size){

    arr[size - 1] = 0;

    printf("\nResults: ");

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

}

int* segEven(int* arr, int size, int* ecount){

    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0 && arr[i] != 0){
            (*ecount)++;
        }
    }

    int* reven = malloc(*ecount * sizeof(int));

    int j = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0 && arr[i] != 0){
            reven[j] = arr[i];
            j++;
        }
    }

    return reven;

}

int* segOdd(int* arr, int size, int* ocount){

    for(int i = 0; i < size; i++){
        if(arr[i] % 2 != 0 && arr[i] != 0){
            (*ocount)++;
        }
    }

    int* rodd = malloc(*ocount * sizeof(int));

    int j = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] % 2 != 0 && arr[i] != 0){
            rodd[j] = arr[i];
            j++;
        }
    }

    return rodd;
}