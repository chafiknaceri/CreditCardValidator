#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{


    long num;
    long first; //this number is for the second digit
    long second; // fr the rest of numbers
    int sum = 0;
    int sum2 = 0;
    int rand = 0; // this variable is to keep track of what second digits
    do
    {
        num  = get_long("Number: ");
    }
    while (num < 0);
    int length = (int)ceil(log10(num));
    first = num;
    second = num;

    // checking if the number entered is in range of length for numbers
    if (length == 13 || length == 15 || length == 16)
    {
        long divisible = 10;

        // this loop is used to get the first two digits of card
        while (first >= 100)
        {
            first = first / 10;

        }
        // divide number until the last digit is shown
        while (second >= 1)
        {

            //printf(" counter %i\n",rand);
            if (rand % 2 == 0)
            {
                sum2 += second % 10; // used to get the left over numbers in the calculations and sum them up
            }
            second = second / 10;
            if (rand % 2 == 0)
            {

                int current = (second % 10) * 2;
                if ((current / 10) > 0)
                {
                    // used to get every second dgit starting from second to last
                    // adding sum of them and doing the Algorithm formula
                    sum += current % 10;
                    sum += (current / 10) % 10;
                }
                else
                {
                    sum += (second % 10) * 2;
                }

            }
            rand += 1;
        }
        // start checking to what card could the number by comparing the first two digits
        if (first == 34 || first == 37)
        {
            if ((sum + sum2) % 10 == 0)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }

        }
        else if (first == 51 || first == 52 || first == 53 || first == 54 || first == 55)
        {
            if ((sum + sum2) % 10 == 0)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if ((first / 10) == 4)
        {
            if ((sum + sum2) % 10 == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}
