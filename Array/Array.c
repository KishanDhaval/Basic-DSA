#include <stdio.h>
#include <stdlib.h>

// Display of array element
void Display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// is Full
int isFull(int size) {
    return size == 10;
}

// is Empty
int isEmpty(int size) {
    return size == 0;
}

// insertion in array
void insertion(int arr[], int *size, int ele) {
    if (isFull(*size)) {
        printf("Array is Full\n");
    } else {
        arr[*size] = ele;
        (*size)++;
        printf("Element %d inserted at index %d\n", ele, *size - 1);
    }
}

// deletion in array
void delete(int arr[], int *size, int ele) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (arr[i] == ele) {
            found = 1;
            // Shift elements to fill the gap
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            printf("Element %d deleted from index %d\n", ele, i);
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array\n", ele);
    }
}

int main() {
    int arr[10];
    int size = 0;
    int option, ele;

    while (1) {
        printf("\n1 for insertion\n");
        printf("2 for deletion\n");
        printf("3 for Display\n");
        printf("0 to exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the element you want to insert: ");
                scanf("%d", &ele);
                insertion(arr, &size, ele);
                break;

            case 2:
                printf("Enter the element you want to delete: ");
                scanf("%d", &ele);
                delete(arr, &size, ele);
                break;

            case 3:
                Display(arr, size);
                break;

            case 0:
                exit(0);
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}
