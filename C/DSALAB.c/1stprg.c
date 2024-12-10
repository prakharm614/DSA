#include <stdio.h>
// Function to check if a number is prime
int checkPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{

    int arr[10];
    printf("Enter the 10 elements of the array:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    int evenCount = 0;
    int oddCount = 0;
    int primeCount = 0;

    for (int i = 0; i < 10; i++)
    {
        {
            if (arr[i] % 2 == 0)
            {
                evenCount++;
            }
            else
            {
                oddCount++;
            }

            if (checkPrime(arr[i]))
            {
                primeCount++;
            }
        }
    }

    printf("Total even elements: %d\n", evenCount);
    printf("Total odd elements: %d\n", oddCount);
    printf("Total prime elements: %d\n", primeCount);

    return 0;
}