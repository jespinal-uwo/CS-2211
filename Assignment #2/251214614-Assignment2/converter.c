/* Name: Converter
   Purpose: A simple converter that prompts the user to
            enter which conversion they want to convert
            (Kilograms and Pounds or Hectares and Acres)
            and then converts the value specified by the
            user
    Author: Juan Espinal
    Student #: 251214614
                        */

// Converstion rates defined as macros
#include <stdio.h>
#define KILOGRAM_POUNDS_CONVERSION 2.20462f
#define HECTARES_ACRES_CONVERSION 2.47105f
#define LITRES_GALLONS_CONVERSION 0.264172f
#define KILOMETRES_MILES_CONVERERSION 0.621371f

int main(void)
{

    int input;
    char character_input;
    float input_float, converted_float;

    for (;;)
    {

        // Prints to the screen the main menu
        printf("-----------Simple Measure Converter---------\n");

        printf("Commands:\n");
        printf("1:  conversion between Kilograms and Pounds \n");
        printf("2:  conversion between Hectares and Acres \n");
        printf("3:  conversion between Litres and Gallons \n");
        printf("4:  conversion between Kilometre and Mile \n");
        printf("5:  quit\n");
        printf("Any other number: try again\n\n");

        // prompts the user for a command to dictate what conversion they want to do
        printf("Please enter a command: ");

        scanf("%d", &input);

        printf("\n");

        switch (input)
        {
        case 1:
            // Prompts the user which conversion of direction they want to do based on the command
            printf("K: conversion from Kilograms to Pounds\n");
            printf("P: conversion from Pounds to Kilograms\n");
            printf("\n");
            printf("Enter direction of conversion: ");
            scanf(" %c", &character_input);
            printf("\n");
            if (character_input == 'K')
            {
                // Prompts the user to enter a value based on the direction of conversion
                printf("Please enter a value to convert Kilogram to Pounds: ");
                scanf("%f", &input_float);
                // Calculates the appropiate conversion and prints it to the screen
                converted_float = input_float * KILOGRAM_POUNDS_CONVERSION;
                printf("Your conversion is: %.6f lbs", converted_float);
                printf("\n\n");
                break;
            }
            else if (character_input == 'P')
            {
                // Prompts the user to enter a value based on the direction of conversion
                printf("Please enter a value to convert Pounds to Kilograms: ");
                scanf("%f", &input_float);
                // Calculates the appropiate conversion and prints it to the screen
                converted_float = input_float * (1.0f / KILOGRAM_POUNDS_CONVERSION);
                printf("Your conversion is %.6f kg", converted_float);
                printf("\n\n");
                break;
            }
            else
            {
                printf("Error! Please enter a correct character!\n\n");
                break;
            }
        case 2:
            // Prompts the user which conversion of direction they want to do based on the command
            printf("H: conversion from Hectares to Acres\n");
            printf("A: conversion from Acres to Hectares\n");
            printf("\n");
            printf("Enter direction of conversion: ");
            scanf(" %c", &character_input);
            printf("\n");
            if (character_input == 'H')
            {
                // Prompts the user to enter a value based on the direction of conversion
                printf("Please enter a value to convert Hectares to Acres: ");
                scanf("%f", &input_float);
                // Calculates the appropiate conversion and prints it to the screen
                converted_float = input_float * HECTARES_ACRES_CONVERSION;
                printf("Your conversion is: %.6f acres", converted_float);
                printf("\n\n");
                break;
            }
            else if (character_input == 'A')
            {
                // Prompts the user to enter a value based on the direction of conversion
                printf("Please enter a value to convert Acres to Hectares: ");
                scanf("%f", &input_float);
                // Calculates the appropiate conversion and prints it to the screen
                converted_float = input_float * (1.0f / HECTARES_ACRES_CONVERSION);
                printf("Your conversion is %.6f hectares", converted_float);
                printf("\n\n");
                break;
            }
            else
            {
                printf("Error! Please enter a correct character!\n\n");
                break;
            }
        case 3:
            // Prompts the user which conversion of direction they want to do based on the command
            printf("L: conversion from Litres to Gallons\n");
            printf("G: conversion from Gallons to Litres\n");
            printf("\n");
            printf("Enter direction of conversion: ");
            scanf(" %c", &character_input);
            printf("\n");
            if (character_input == 'L')
            {
                // Prompts the user to enter a value based on the direction of conversion
                printf("Please enter a value to convert Litres to Gallons: ");
                scanf("%f", &input_float);
                // Calculates the appropiate conversion and prints it to the screen
                converted_float = input_float * LITRES_GALLONS_CONVERSION;
                printf("Your conversion is: %.6f gallons", converted_float);
                printf("\n\n");
                break;
            }
            else if (character_input == 'G')
            {
                // Prompts the user to enter a value based on the direction of conversion
                printf("Please enter a value to convert Gallons to Litres: ");
                scanf("%f", &input_float);
                // Calculates the appropiate conversion and prints it to the screen
                converted_float = input_float * (1.0f / LITRES_GALLONS_CONVERSION);
                printf("Your conversion is %.6f litres", converted_float);
                printf("\n\n");
                break;
            }
            else
            {
                printf("Error! Please enter a correct character!\n\n");
                break;
            }

        case 4:
            // Prompts the user which conversion of direction they want to do based on the command
            printf("K: conversion from Kilometre to Miles\n");
            printf("M: conversion from Miles to Kilometres\n");
            printf("\n");
            printf("Enter direction of conversion: ");
            scanf(" %c", &character_input);
            printf("\n");
            if (character_input == 'K')
            {
                // Prompts the user to enter a value based on the direction of conversion
                printf("Please enter a value to convert Kilometres to Miles: ");
                scanf("%f", &input_float);
                // Calculates the appropiate conversion and prints it to the screen
                converted_float = input_float * KILOMETRES_MILES_CONVERERSION;
                printf("Your conversion is: %.6f miles", converted_float);
                printf("\n\n");
                break;
            }
            else if (character_input == 'M')
            {
                // Prompts the user to enter a value based on the direction of conversion
                printf("Please enter a value to convert Miles to Kilometres: ");
                scanf("%f", &input_float);
                // Calculates the appropiate conversion and prints it to the screen
                converted_float = input_float * (1.0f / KILOMETRES_MILES_CONVERERSION);
                printf("Your conversion is %.6f kilometres", converted_float);
                printf("\n\n");
                break;
            }
            else
            {
                printf("Error! Please enter a correct character!\n\n");
                break;
            }

        // Exits the main function if user entered command #5
        case 5:
            return 0;

        // Returns to the main menu if user entered any other command
        default:
            break;
        }
    }
}