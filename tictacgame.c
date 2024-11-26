#include<stdio.h>

int drawbo(char ar[9], int a, int f)
{
    if (f == 1)
    {
        f = 2;
        ar[a - 1] = 'x';
    }
    else if (f == 2)
    {
        f = 1;
        ar[a - 1] = 'o';
    }
    return f;
}

void dipbo(char ar[9])
{
    for (int i = 0; i < 9; i++)
    {
        printf("%c | ", ar[i]);
        if (i == 2 || i == 5) printf("\n");
    }
    printf("\n");
}

int winfun(char ar[9])
{
    int a = 0;
    // Check rows, columns and diagonals
    for (int i = 0; i < 3; i++) {
        if (ar[i] == ar[i + 3] && ar[i] == ar[i + 6]) {
            a = (ar[i] == 'x') ? 1 : 2;
            return a;
        }
    }
    for (int i = 0; i < 9; i += 3) {
        if (ar[i] == ar[i + 1] && ar[i] == ar[i + 2]) {
            a = (ar[i] == 'x') ? 1 : 2;
            return a;
        }
    }
    if ((ar[0] == ar[4] && ar[0] == ar[8]) || (ar[2] == ar[4] && ar[2] == ar[6])) {
        a = (ar[4] == 'x') ? 1 : 2;
    }
    return a;
}

int main()
{
    char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int d;
    int p = 1;
    int cn = 0;
    int a = 0;
    
    dipbo(arr);
    printf("\nPlayer 1 = 'x' and Player 2 = 'o'\n");

    while (a == 0 && cn < 9)
    {
        printf("\nEnter the position (1-9): ");
        scanf("%d", &d);

        // Input validation for move
        if (d < 1 || d > 9 || arr[d - 1] == 'x' || arr[d - 1] == 'o')
        {
            printf("Invalid move. Try again.\n");
            continue;
        }

        p = drawbo(arr, d, p);
        printf("\n");
        dipbo(arr);

        a = winfun(arr);
        cn++;
    }

    if (cn == 9 && a == 0)
    {
        printf("It's a draw\n");
    }
    else if (a == 1)
    {
        printf("Player 1 wins\n");
    }
    else if (a == 2)
    {
        printf("Player 2 wins\n");
    }

    return 0;
}
