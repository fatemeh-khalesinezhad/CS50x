#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string number = get_string("Number: ");

    int length = strlen(number);
    int sum = 0;
    bool alternate = false;

    for (int i = length - 1; i >= 0; i--)
    {
        int digit = number[i] - '0';

        if (alternate)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit = (digit % 10) + (digit / 10);
            }
        }

        sum += digit;
        alternate = !alternate;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }


    int first_two = (number[0] - '0') * 10 + (number[1] - '0');


    if ((length == 15) && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if ((length == 16) && (first_two >= 51 && first_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && number[0] == '4')
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}