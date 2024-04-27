#include<stdio.h>
#include<stdlib.h>

struct Array {
    int size;
    int *arr;
};

// Display
void Display(struct Array* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array->arr[i]);
    }
}

// is Full
int isFull(struct Array* array, int n) {
    return n == array->size;
}

// Insertion
void Insertion(struct Array* array, int n, int ele) {
    if (isFull(array, n + 1)) {
        printf("Array is Full\n");
    } else {
        int i = n - 1;
        while (i >= 0 && array->arr[i] > ele) {
            array->arr[i + 1] = array->arr[i];
            i--;
        }
        array->arr[i + 1] = ele;
        printf("Element inserted successfully\n");
    }
}

int main() {
    struct Array* array = (struct Array*)malloc(sizeof(struct Array));
    array->size = 100;
    array->arr = (int *)malloc(array->size * sizeof(int));

    int n, ele;

    printf("How many elements you want to add: ");
    scanf("%d", &n);

    printf("Give Sorted Array: \n");
    for(int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array->arr[i]);
    }

    printf("Which element you want to insert: \n");
    scanf("%d", &ele);

    Insertion(array, n, ele);

    printf("Updated Array: ");
    Display(array, n + 1);

    return 0;
}
