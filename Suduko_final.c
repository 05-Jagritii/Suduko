#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // library to include bool data type
#include <time.h>    // library to include rand and srand function
#define SIZE 9
#define EMPTY 0

// function to check if a number can be filled in a box or not
bool isAvailable(int box[SIZE][SIZE], int row, int col, int num){

    int rowStart = (row / 3) * 3;
    int colStart = (col / 3) * 3;

    for (int i = 0; i < SIZE; ++i){

        if (box[row][i] == num) // check for a number in a row
            return false;
        if (box[i][col] == num) // check for a number in a column
            return false;
        if (box[rowStart + (i % 3)][colStart + (i / 3)] == num) // check for a number in a 3x3 box
            return false;
    }
    return true;
}

// function to check if a box is empty or filled
bool findEmptyLocation(int box[SIZE][SIZE], int *row, int *col){

    for (*row = 0; *row < SIZE; (*row)++)
        for (*col = 0; *col < SIZE; (*col)++)
            if (box[*row][*col] == EMPTY)
                return true;

    return false;
}

// function to make a completely solved sudoku with random entry every time
bool solveSudoku(int box[SIZE][SIZE]){

    int row, col;
    if (!findEmptyLocation(box, &row, &col))
        return true;

    // code to changes random value every time
    int numbers[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < SIZE; i++)
    {
        int j = rand() % SIZE;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // code to fill the num in the sudoku box
    for (int i = 0; i < SIZE; i++)
    {
        int num = numbers[i];
        if (isAvailable(box, row, col, num))
        {
            box[row][col] = num;

            if (solveSudoku(box))
                return true;

            box[row][col] = EMPTY;
        }
    }

    return false;
}

// function to get blank spaces or (0) at various cells
void generateSudoku(int box[SIZE][SIZE], int difficulty)
{
    // declare a empty 9x9 2D array
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            box[i][j] = EMPTY;

    // fill the Suduko box
    solveSudoku(box);

    // code to replace few entry with zero to specify blank space
    int numToRemove = difficulty;
    while (numToRemove > 0)
    {
        int row = rand() % SIZE;
        int col = rand() % SIZE;

        if (box[row][col] != EMPTY)
        {
            int backup = box[row][col];
            box[row][col] = EMPTY;

            int temp[SIZE][SIZE];
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++)
                    temp[i][j] = box[i][j];

            if (!solveSudoku(temp))
                box[row][col] = backup;
            else
                numToRemove--;
        }
    }
}

// function to fill empty sudoku given by the user or generated by the code in part I
bool fillSudoku(int box[][9], int row, int col)
{
    int i;
    if (row < 9 && col < 9)
    {
        if (box[row][col] != 0)
        {
            if ((col + 1) < 9) 
                return fillSudoku(box, row, col + 1);
            else if ((row + 1) < 9) 
                return fillSudoku(box, row + 1, 0);
            else
                return true;
        }
        else
        {
            for (i = 0; i < 9; ++i)
            {
                if (isAvailable(box, row, col, i + 1))
                {
                    box[row][col] = i + 1;
                    if ((col + 1) < 9)
                    {   // fill the entry in columns of particular row 
                        if (fillSudoku(box, row, col + 1))
                            return true;
                        else
                            box[row][col] = 0;
                    }
                    else if ((row + 1) < 9)
                    {   // fill the entry at new row
                        if (fillSudoku(box, row + 1, 0))
                            return true;
                        else
                            box[row][col] = 0;
                    }
                    else
                        return true;
                }
            }
        }
        return false;
    }
    else
        return true;
}


// function to print the Sudoku box
void printSudoku(int box[SIZE][SIZE])
{
    printf("+------+-------+------+\n");
    for (int i = 1; i < 10; ++i)
    {
        for (int j = 1; j < 10; ++j)
        {
            printf("|%d", box[i - 1][j - 1]);
            if (j % 3 == 0 && j != 9)
                printf("| ");
        }
        printf("|\n");
        if (i % 3 == 0)
            printf("+------+-------+------+\n");
    }
}

int main()
{
    printf("Enter your name : ");
    char name[50];
    scanf("%s", &name);

    printf("Welcome to Sudoku Mania, %s (* _ *)\n", name);
    printf("\n1. Press '1' to generate a Suduko\n2. Press '2' to solve a Suduko\n\n");
    printf("ENTER YOUR COMMAND : ");

    int n;
    scanf("%d", &n);
    int box[SIZE][SIZE];

    if (n == 1) // Case I : When code generate a Sudoku Puzzle
    {
        // assign random value at different time
        srand(time(NULL));
        printf("Enter Difficulty of Sudoku Puzzle on Scale 40-65 : ");
        int difficulty;
        scanf("%d", &difficulty);
        generateSudoku(box, difficulty);
        printf("GENERATED SUDOKU PUZZLE:\n\n");
        printSudoku(box);

        printf("\nPress 'y' to Solve the above suduko\nPress 'n' to exit\n\n");
        printf("ENTER YOUR COMMAND : ");

        char c;
        scanf("%c", &c);
        scanf("%c", &c);

        if (c == 'Y' || c == 'y') // Code to print the solved puzzled generated by program
        {
            printf("\nSOLVED SUDOKU PUZZLE:\n\n");

            if (fillSudoku(box, 0, 0))
                printSudoku(box);
            else
                printf("\n\nNO SOLUTION (^.^)\n\n");
        }
        else if (c == 'N' || c == 'n') // Code to exit the program if user says no
            printf("\nENJOY SOLVING THE SUDOKU PUZZLE.....(^.^) \n");
        else
            printf("\nINVALID COMMAND (-_-)");
    }
    else if (n == 2) // Case II : When a user gives a input
    {

        printf("ENTER THE UNSOLVED SUDOKU PUZZLE :\n\n");

        // Input
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                scanf("%d", &box[i][j]);

        if (fillSudoku(box, 0, 0))
            printSudoku(box);
        else
            printf("\n\nNO SOLUTION (^.^)\n\n");
    }
    else
        printf("\nINVALID COMMAND (-_-)");

    return 0;
}