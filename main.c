#include <stdio.h>
int main()
{
    int choice, size, shape, row, col, space, rows, value;
    int length, left, right, palindrome;
    char word[100], again = 'Y';
    float prelim, midterm, prefinal, finalExam, average;
    do
    {
        printf("\n===== IT101 FINAL PROJECT =====\n");
        printf("1. Pattern Generator\n2. Pascal's Triangle\n");
        printf("3. Grade Calculator\n4. Palindrome Checker\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("\nEnter pattern size (1-20): ");
            scanf("%d", &size);
            if (size < 1 || size > 20) printf("Invalid size.\n");
            else
            {
                printf("1.Right Triangle 2.Square 3.Pyramid\n");
                printf("4.Inverted Triangle 5.Christmas Tree\nChoice: ");
                scanf("%d", &shape);
                if (shape >= 1 && shape <= 5)
                {
                    if (shape == 5) printf("\nChristmas Tree:\n");
                    else if (shape == 4) printf("\nInverted Triangle:\n");
                    else if (shape == 1) printf("\nRight Triangle:\n");
                    else if (shape == 2) printf("\nSquare:\n");
                    else printf("\nPyramid:\n");
                    
                    if (shape == 5)
                    {
                        for (rows = 1; rows <= 3; rows++)
                        {
                            for (row = 1; row <= size; row++)
                            {
                                for (space = 1; space <= size - row; space++) printf(" ");
                                for (col = 1; col <= 2 * row - 1; col++) printf("*");
                                printf("\n");
                            }
                        }
                        for (row = 1; row <= 2; row++)
                        {
                            for (space = 1; space < size; space++) printf(" ");
                            printf("*\n");
                        }
                    }
                    else if (shape == 4)
                    {
                        for (row = size; row >= 1; row--)
                        {
                            for (col = 1; col <= row; col++) printf("* ");
                            printf("\n");
                        }
                    }
                    else if (shape == 1)
                    {
                        for (row = 1; row <= size; row++)
                        {
                            for (col = 1; col <= row; col++) printf("* ");
                            printf("\n");
                        }
                    }
                    else if (shape == 2)
                    {
                        for (row = 1; row <= size; row++)
                        {
                            for (col = 1; col <= size; col++) printf("* ");
                            printf("\n");
                        }
                    }
                    else
                    {
                        for (row = 1; row <= size; row++)
                        {
                            for (space = 1; space <= size - row; space++) printf(" ");
                            for (col = 1; col <= 2 * row - 1; col++) printf("*");
                            printf("\n");
                        }
                    }
                }
                else printf("Invalid shape choice.\n");
            }
        }
        else if (choice == 2)
        {
            printf("\nEnter number of rows (1-15): ");
            scanf("%d", &rows);
            if (rows < 1 || rows > 15) printf("Invalid number of rows.\n");
            else
            {
                for (row = 0; row < rows; row++)
                {
                    for (space = 1; space <= rows - row; space++) printf(" ");
                    value = 1;
                    for (col = 0; col <= row; col++)
                    {
                        printf("%4d", value);
                        value = value * (row - col) / (col + 1);
                    }
                    printf("\n");
                }
            }
        }
        else if (choice == 3)
        {
            printf("\nEnter college grades from 1.00 to 5.00.\n");
            printf("Prelim: "); scanf("%f", &prelim);
            printf("Midterm: "); scanf("%f", &midterm);
            printf("Pre-Final: "); scanf("%f", &prefinal);
            printf("Final: "); scanf("%f", &finalExam);
            
            if (prelim < 1 || prelim > 5 || midterm < 1 || midterm > 5 ||
                prefinal < 1 || prefinal > 5 || finalExam < 1 || finalExam > 5)
                printf("Invalid grade. Please enter grades from 1.00 to 5.00.\n");
            else
            {
                average = (prelim + midterm + prefinal + finalExam) / 4;
                printf("Average college grade: %.2f\n", average);
                if (average <= 3.00)
                    printf("Status: PASS\n");
                else printf("Status: FAIL\n");
            }
        }
        else if (choice == 4)
        {
            printf("\nEnter one word: ");
            scanf("%99s", word);
            length = 0;
            while (word[length] != '\0')
                length++;
            left = 0; right = length - 1; palindrome = 1;
            while (left < right)
            {
                if (word[left] != word[right]) palindrome = 0;
                left++; right--;
            }
            if (palindrome == 1) printf("%s is a palindrome.\n", word);
            else printf("%s is not a palindrome.\n", word);
        }
        else if (choice == 5)
            printf("\nExiting program...\n");
        else printf("Invalid menu choice.\n");
        
        if (choice != 5)
        {
            printf("\nTry another operation? (Y/N): ");
            scanf(" %c", &again);
        }
    } while ((again == 'Y' || again == 'y') && choice != 5);
    
    printf("Thank you for using the program!\n");
    return 0;
}