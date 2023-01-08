/* Name: Integer to English Converter
   Purpose: A simple converter that prompts the user to
            enter any integer from 1-999 and converts it
            into the English word
    Author: Juan Espinal
    Student #: 251214614
                        */

#include <stdio.h>

int main(void)
{

    int input_num, temp_input_num, temp_input_num2;

    for (;;)
    {
        // Scans for user input
        printf("Please enter a value (1-999, 0 to quit): ");
        scanf("%d", &input_num);

        // Exits the main function if user input is 0 
        if (input_num == 0)
            return 0;

        printf("You entered the number ");

        // Checks to see if the number is greater than 100
        if (input_num >= 100)
        {

            // Takes the first number of the 3 digit number
            temp_input_num = input_num / 100;
            // Takes away the first digit of the 3 digit number (it is now a 2 digit number)
            input_num = input_num % 100;
            switch (temp_input_num)
            {
            case 1:
                printf("one hundred ");
                break;
            case 2:
                printf("two hundred ");
                break;
            case 3:
                printf("three hundred ");
                break;
            case 4:
                printf("four hundred ");
                break;
            case 5:
                printf("five hundred ");
                break;
            case 6:
                printf("six hundred ");
                break;
            case 7:
                printf("seven hundred ");
                break;
            case 8:
                printf("eight hundred ");
                break;
            case 9:
                printf("nine hundred ");
                break;
            }


            // If the 3 digit number is NOT divisible by 100, then print the word "and"
            if (input_num != 0)
            {
                printf("and ");
            }
        }

        // Checks to see if the number is between 20 and 99

        if (input_num >= 20 && input_num <= 99)
        {
            // Takes the first digit of the 2 digit number
            temp_input_num2 = input_num / 10;
            // Takes away the first digit of the 2 digit number (it is now a 1 digit number)
            input_num = input_num % 10;

            switch (temp_input_num2)
            {
            case 2:
                printf("twenty");
                break;
            case 3:
                printf("thirty");
                break;
            case 4:
                printf("fourty");
                break;
            case 5:
                printf("fifty");
                break;
            case 6:
                printf("sixty");
                break;
            case 7:
                printf("seventy");
                break;
            case 8:
                printf("eighty");
                break;
            case 9:
                printf("ninety");
                break;
            }


            // If the number is not 0, then print "-"
            if (input_num != 0)
                printf("-");
            else
            {
                printf("\n\n");
                continue;
            }
        }

        // Checks to see if the number is between 10 and 19
        if (input_num >= 10 && input_num <= 19)
        {

            switch (input_num)
            {
            case 10:
                printf("ten");
                break;
            case 11:
                printf("eleven");
                break;
            case 12:
                printf("twelve");
                break;
            case 13:
                printf("thirteen");
                break;
            case 14:
                printf("fourteen");
                break;
            case 15:
                printf("fifteen");
                break;
            case 16:
                printf("sixteen");
                break;
            case 17:
                printf("seventeen");
                break;
            case 18:
                printf("eighteen");
                break;
            case 19:
                printf("nineteen");
                break;
            }

            printf("\n\n");

            continue;
        }

        if (input_num >= 1 && input_num <= 9)
        {
            switch (input_num)
            {
            case 1:
                printf("one");
                break;
            case 2:
                printf("two");
                break;
            case 3:
                printf("three");
                break;
            case 4:
                printf("four");
                break;
            case 5:
                printf("five");
                break;
            case 6:
                printf("six");
                break;
            case 7:
                printf("seven");
                break;
            case 8:
                printf("eight");
                break;
            case 9:
                printf("nine");
                break;
            }
        }

        printf("\n\n");
    }
}