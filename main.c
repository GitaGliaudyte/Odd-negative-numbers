/*
Gita Gliaudytė, 2022
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9999

bool is_it_int(char *string, int *integer);

int main(void)
{
    int n = 1;
    int last_chance = 0;
    int position = 0;
    int neg_odd_num = 0;
    int integer;
    bool its_correct_int = true;
    int circle = 1;

    printf("This program outputs the amount of odd negative numbers of the sequence you have entered.\n");

    do
    {
        while(n != 0){

            do
            {
                char input_integer[MAX];

                printf("Enter a number:\n");
                fgets(input_integer, MAX, stdin);

                its_correct_int = is_it_int(input_integer, &integer);

                n = integer;

                if(!its_correct_int){

                    printf("Enter integer value only!\n");

                } else if(n != 0){

                    position++;

                    if(n < 0 && position % 2 != 0){

                        neg_odd_num++;

                    }
                }

            } while(!its_correct_int);
        }

    printf("The amount of negative odd numbers is: %d\n", neg_odd_num);

    position = 0;
    neg_odd_num = 0;

    printf("Do you want to enter another sequence of numbers? If yes, enter 1. If no, enter 0.\n");

    do
    {
        char input_integer[MAX];

        printf("Enter a your choice:\n");
        fgets(input_integer, MAX, stdin);

        its_correct_int = is_it_int(input_integer, &integer);

        if(!its_correct_int){

            printf("Enter integer value only!\n");

        } else if(integer == 1){
            n = 1;
        } else{
            circle = 0;
        }

    } while(!its_correct_int);


} while(circle != 0);



    return 0;

}

bool is_it_int(char *string, int *integer)
{
    int i = 0;

    while(isspace(string[i]))
        i++;

    int length = strlen(string);

    if(length == i)
        return false;

    char integer_limit[MAX];

    int integer_chars = 0;

    if(string[i]== '-'){ //tikrinamas minusas, jei jis yra, reiksme dar nera false

        integer_limit[integer_chars] = '-';
        integer_chars++;
        i++;
        if(!isdigit(string[i]))
            return false;
    }

    while (i < length && !isspace(string[i])){
        if(!isdigit(string[i]))
            return false;

        integer_limit[integer_chars] = string[i];
        integer_chars++;
        i++;
    }

    integer_limit[integer_chars] = '\0';

    while (isspace(string[i]))
        i++;

    if(string[i] != '\0')
        return false;

    *integer = atoi(integer_limit);

    return true;
}
