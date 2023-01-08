/* Name: Part1
   Purpose: Simple C program that works with arrays, each function works
            on integers found in the array
    Author: Juan Espinal
    Student #: 251214614
                        */

#include <stdio.h>

// Function that prints out the element of the array and which position they are in
void part1(int size, const int arr[size])
{

    printf("Your array is: ");
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1) // Ensures that the last element to be printed doesn't have a comma
            printf("[%d] = %d,  ", i, arr[i]);
        else
            printf("[%d] = %d  ", i, arr[i]);
    }

    printf("\n\n");
}

// Function that prints out the largest value in the array
void part2(int size, const int arr[size])
{
    int largest = arr[0]; // Assumes largest element is at index 0

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
    }

    printf("The largest value in your array is: %d", largest);

    printf("\n\n");
}

// Function that prints out the elements of the array in reverse order
void part3(int size, const int arr[size])
{

    printf("Your array in reverse is: ");
    for (int i = size - 1; i >= 0; i--) // Iterates through the loop in reverse order 
    {
        printf("%d ", arr[i]);
    }

    printf("\n\n");
}

// Function that prints out the sum of all values in the array

void part4(int size, const int arr[size])
{

    int sum = 0;

    for (int i = 0; i < size; i++) // Iterates through the loop
    {
        sum += arr[i];
    }
    printf("The sum of all values in your array is: %d", sum);
    printf("\n\n");
}

// Function that prints out the elements of the array from largest to smallest (descending order)
void part5(int size, const int arr[size])
{

    // Creates a new array and copies all the element of the original array into the new array
    int sortedArray[size];

    for (int i = 0; i < size; i++)
    {
        sortedArray[i] = arr[i];
    }

    // Creates a temporary variable from which to replace the first sorted element
    int temporary;

    printf("Your array in sorted order: ");

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (sortedArray[i] < sortedArray[j])
            {
                temporary = sortedArray[i];
                sortedArray[i] = sortedArray[j];
                sortedArray[j] = temporary;
            }
        }
    }

    // prints out the sorted array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", sortedArray[i]);
    }

    printf("\n\n");
}

// Function that prints out the elements of the array except the first and last element are swapped
void part6(int size, const int arr[size])
{

    printf("Your array with first and last element switched is: ");

    for (int i = 0; i < size; i++)
    {
        if (i == 0) // prints out last element first
            printf("%d ", arr[size - 1]);
        else if (i == size - 1)
            printf("%d ", arr[0]); // prints out the first element last
        else
            printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main(void)
{

    int sizeOfArray;
    // Asks the user for the size of the array and stores it in a variable
    for (;;)
    {

        printf("Please enter the number of integers to process: ");
        scanf("%d", &sizeOfArray);

        // Prompts the user again for the size of the array if the number lies outside of 12 or below 5 non-inclusive
        if (sizeOfArray < 5 || sizeOfArray > 12)
        {
            printf ("\n");
            printf("Error! You must provide a minimum of 5 integers and a maximum of 12! \n\n");
        }
        else
            break;
    }

    // Declares a Variable Length Array (VLA) of size specified by the user
    int array[sizeOfArray];

    // Prints the size of the array in bytes and the size of the array
    printf("\tThere is enough room in your array for %d integers (%d bytes)\n\n", sizeOfArray, (int)(sizeof(array)));

    // Assigns the integers the user gives into the VLA
    printf("Please enter your integers by spaces: ");

    for (int i = 0; i < sizeOfArray; i++)
    {
        scanf("%d", &array[i]);
    }

    // Calls all the functions which work on the integers found in the array
    printf("Part 1:\n\t");
    part1(sizeOfArray, array);
    printf("Part 2:\n\t");
    part2(sizeOfArray, array);
    printf("Part 3:\n\t");
    part3(sizeOfArray, array);
    printf("Part 4:\n\t");
    part4(sizeOfArray, array);
    printf("Part 5:\n\t");
    part5(sizeOfArray, array);
    printf("Part 6:\n\t");
    part6(sizeOfArray, array);

    return 0;
}