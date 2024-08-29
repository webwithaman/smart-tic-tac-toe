// C++ Bootcamp Tic Tac Toe Game Project

// Header Files
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/************** Function Declarations ***************/

// Function to Display Game Rules
void gameRules();

// Function to Get User's Choice
int choice();

// Function to Play With Computer
void playWithComputer();

// Function to Play With Evil
void playWithEvil();

// Function to Play With Player
void playWithPlayer();

// Function to Get Player Name
void getPlayerName(char *);

// Function to Start Game
void startGame(char *, char *, int);

// Function to Display Matrix
void displayMatrix(char *);

// Function to Get Key from User
int getKey(char *);

// Function to Check That X or O has Became Same
int hasSame(char *);

// Function to Delete Char Key
void deleteKey(char *, int);

// Function For Computer Turn
int computerTurn(char *, int);

// Function to Check X
int checkX(char *);

// Function to Get Random Number Between Two Values
int random(int, int);

// 2D- Array For Winning Combinations
int comb[][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

// Main Function Start
int main()
{
    // Display Game Rules
    gameRules();

    while (1)
    {
        switch (choice())
        {
        case 0:
            exit(0);

        case 1:
            playWithComputer();
            break;

        case 2:
            playWithEvil();
            break;

        case 3:
            playWithPlayer();
            break;

        default:
            puts("\t\t\t   !!! Invalid Choice...");
        }
        getch();
        system("cls");
    }

    return 0;
}
// Main Function End

/************** Function Definitions ***************/

void gameRules()
{
    system("color 4");
    puts("\n\t\t\t   >>>>>>>>>>>>>> TIC TAC TOE <<<<<<<<<<<<<<");
    puts("\n\t\t\t   -------------- GAME RULES ---------------\n");
    puts("\t\t\t   1. YOU WILL BE NOT ABLE TO ENTER NUMBER WHICH HAS ALREADY FILLED");
    puts("\t\t\t   2. USE ONLY NUMERIC KEYS 1 - 9");
    puts("\t\t\t   3. YOU CAN CHOOSE THAT WHICH PLAYER SHOULD HAVE FIRST TURN");
    puts("\t\t\t   .........................................\n");
    puts("\n\t\t\t   PRESS ANY KEY TO START....\n");
    printf("\t\t\t   ");
    getch();
    system("cls");
}

// Function to Get User's Choice
int choice()
{
    system("color 5");
    puts("\n\t\t\t   >>>>>>>>>>>>>> TIC TAC TOE <<<<<<<<<<<<<<");
    puts("\n\t\t\t   .........................................\n");
    puts("\t\t\t   PRESS 0. EXIT");
    puts("\t\t\t   PRESS 1. PLAY WITH SMART COMPUTER");
    puts("\t\t\t   PRESS 2. PLAY WITH EVIL COMPUTER");
    puts("\t\t\t   PRESS 3. PLAY WITH PLAYER");
    puts("\n\t\t\t   .........................................\n");
    printf("\t\t\t   ENTER YOUR CHOICE => ");
    fflush(stdin);
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Function to Play With Computer
void playWithComputer()
{
    system("cls");
    system("color 1");
    puts("\n\t\t\t   >>>>>>>>>>>>>> TIC TAC TOE <<<<<<<<<<<<<<");
    char player1Name[16], player2Name[16];
    printf("\n\t\t\t   ENTER PLAYER 1. NAME => ");
    getPlayerName(player1Name);
    strcpy(player2Name, "COMPUTER");
    startGame(player1Name, player2Name, 1);
}

// Function to Play With Evil
void playWithEvil()
{
    system("cls");
    system("color 3");
    puts("\n\t\t\t   >>>>>>>>>>>>>> TIC TAC TOE <<<<<<<<<<<<<<");
    char player1Name[16], player2Name[16];
    printf("\n\t\t\t   ENTER PLAYER 1. NAME => ");
    getPlayerName(player1Name);
    strcpy(player2Name, "DEVIL");
    startGame(player1Name, player2Name, 2);
}

// Function to Play With Player
void playWithPlayer()
{
    system("cls");
    system("color 2");
    puts("\n\t\t\t   >>>>>>>>>>>>>> TIC TAC TOE <<<<<<<<<<<<<<");
    char player1Name[16], player2Name[16];
    printf("\n\t\t\t   ENTER PLAYER 1. NAME (NICK NAME) => ");
    getPlayerName(player1Name);
    printf("\n\t\t\t   ENTER PLAYER 2. NAME (NICK NAME) => ");
    getPlayerName(player2Name);
    startGame(player1Name, player2Name, 3);
}

// Function to Get Player Name
void getPlayerName(char *name)
{
    fflush(stdin);
    fgets(name, 15, stdin);
    name[strlen(name) - 1] = 0;
    strupr(name);
}

// Function to Start Game
void startGame(char *player1Name, char *player2Name, int whoIsPlaying)
{
    int turn;
    printf("\n\t\t\t   ENTER 0. FOR %s'S FIRST TURN", player2Name);
    printf("\n\t\t\t   ENTER 1. FOR %s'S FIRST TURN\n", player1Name);
    printf("\n\t\t\t   ENTER CHOICE => ");

    // Take Input Till User Not Enter 1 or 0
    while (1)
    {
        turn = getch();
        if (turn == '1' || turn == '0')
        {
            putch(turn);
            getch();
            break;
        }
    }
    turn -= 48;

    system("cls");
    system("color e");
    char str[] = "123456789", keys[] = "123456789";
    int count = 1, key, index, i;

    while (count < 10)
    {
        puts("\n\t\t\t   >>>>>>>>>>>>>> TIC TAC TOE <<<<<<<<<<<<<<");
        printf("\n\t\t\t     %15s V/S %-15s", player1Name, player2Name);
        printf("\n\n\t\t\t   PLAYER 1. %-15s     ---> HAVE X", player1Name);
        printf("\n\t\t\t   PLAYER 2. %-15s     ---> HAVE O", player2Name);
        puts("\n\t\t\t   ..........................................");
        // Display Matrix
        displayMatrix(str);
        printf("\t\t\t\t");

        if (turn)
        {
            printf("=> TURN %s => X\n\n", player1Name);
            key = getKey(keys);
            if (key == -99)
            {
                printf("\n\t\t\t\t");
                printf("!!! INVALID INPUT ....");
                getch();
                system("cls");
                continue;
            }
            turn = 0;
        }
        else
        {
            printf("=> TURN %s => O\n\n", player2Name);
            turn = 1;

            if (whoIsPlaying == 1)
                key = computerTurn(str, count);
            else if (whoIsPlaying == 2)
                key = computerTurn(str, count);
            else
            {
                key = getKey(keys);
                if (key == -99)
                {
                    printf("\n\t\t\t\t");
                    printf("!!! INVALID INPUT ....");
                    getch();
                    system("cls");
                    continue;
                }
            }
        }

        // Delete Used Key From keys String
        deleteKey(keys, key);

        if (turn)
            str[key - 1] = 'O';
        else
            str[key - 1] = 'X';

        printf("\t\t\t\t");

        // Check Same or Not
        index = hasSame(str);
        if (index >= 0)
            break;

        count++;

        // Check X For Evil Again Turn or Cheat
        if (whoIsPlaying == 2 && checkX(str))
            turn = 0;

        system("cls");
    }

    system("cls");
    puts("\n\t\t\t   >>>>>>>>>>>>>> TIC TAC TOE <<<<<<<<<<<<<<");
    printf("\n\t\t\t   PLAYER 1. %-12s, HAVE X", player1Name);
    printf("\n\t\t\t   PLAYER 2. %-12s, HAVE O", player2Name);
    puts("\n\t\t\t   .........................................");
    // Display Matrix
    displayMatrix(str);

    puts("\n\n\n\t\t\t    >>>>>>>>>>>>>> GAME OVER <<<<<<<<<<<<<<\n");
    printf("\t\t\t    ");
    if (count == 10)
        printf("=> 0HH !! MATCH DRAW ......\n");
    else if (str[index] == 'X')
        printf("=> YIPEE %s = X , WON ......\n\n", player1Name);
    else
        printf("=> YIPEE %s = O , WON ......\n\n", player2Name);
    printf("\t\t\t    ");
}

// Function to Get Key from User for Input 0 or X
int getKey(char *keys)
{
    char key;
    printf("\t\t\t\t");
    printf("ENTER NUMBER WHERE TO INSERT => ");
    int i;
    fflush(stdin);
    key = getchar();
    for (i = 0; keys[i]; i++)
        if (key == keys[i])
            break;

    if (keys[i] == 0)
        return -99;

    key -= 48;
    return key;
}

// Function to Display Matrix
void displayMatrix(char *ptr)
{
    printf("\n");
    printf("\t\t\t\t");
    puts("-------------------------------");
    printf("\t\t\t\t");
    puts("|         |         |         |");
    printf("\t\t\t\t");

    for (int i = 0; ptr[i]; i++)
    {
        printf("|");
        printf("    %c    ", ptr[i]);
        if (i == 2 || i == 5)
        {
            printf("|");
            putch(10);
            printf("\t\t\t\t");
            puts("|         |         |         |");
            printf("\t\t\t\t");
            puts("-------------------------------");
            printf("\t\t\t\t");
            puts("|         |         |         |");
            printf("\t\t\t\t");
        }
    }
    printf("|");
    putch(10);
    printf("\t\t\t\t");
    puts("|         |         |         |");
    printf("\t\t\t\t");
    puts("-------------------------------");
    printf("\n");
}

// Function to Check That 0 or X Has Same
int hasSame(char *ptr)
{
    for (int i = 0; i < 8; i++)
        if (ptr[comb[i][0]] == ptr[comb[i][1]] && ptr[comb[i][1]] == ptr[comb[i][2]])
            return comb[i][0];
    return -1;
}

// Function to Delete Key
void deleteKey(char *str, int position)
{
    int i;
    for (i = 0; str[i]; i++)
        if (str[i] == 48 + position)
            position = i + 1;

    for (i = position; str[i]; i++)
        str[i - 1] = str[i];

    str[i - 1] = 0;
}

// Function for Computer Turn
int computerTurn(char *str, int chance)
{
    int count, flag;

    // Check Number If An combination has Two 0's For Computer Winning
    for (int i = 0; i < 8; i++)
    {
        count = 0;
        flag = -1;
        for (int j = 0; j < 3; j++)
        {
            if (str[comb[i][j]] == 'O')
                count++;
            if (str[comb[i][j]] != 'O' && str[comb[i][j]] != 'X')
                flag = j;
            if (count == 2 && flag != -1)
                return comb[i][flag] + 1;
        }
    }

    if (chance == 1)
        return random(1, 10);

    if (chance == 2)
    {
        int i;
        for (i = 0; str[i] != 'X'; i++)
            ;
        int r = random(1, 10);
        while (r == i + 1)
            r = random(1, 10);
        return r;
    }

    if (chance == 9)
    {
        int i;
        for (i = 0; str[i] == 'O' || str[i] == 'X'; i++)
            ;
        return i + 1;
    }

    // Check Number If An combination has Two X to Stop Player
    for (int i = 0; i < 8; i++)
    {
        count = 0;
        flag = -1;
        for (int j = 0; j < 3; j++)
        {
            if (str[comb[i][j]] == 'X')
                count++;
            if (str[comb[i][j]] != 'O' && str[comb[i][j]] != 'X')
                flag = j;
            if (count == 2 && flag != -1)
                return comb[i][flag] + 1;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        count = 0;
        flag = -1;
        for (int j = 0; j < 3; j++)
        {
            if (str[comb[i][j]] == 'X')
                count++;
            if (str[comb[i][j]] != 'O' && str[comb[i][j]] != 'X')
                flag = j;
            if (count == 1 && flag != -1)
                return comb[i][flag] + 1;
        }
    }
}

// Function to Check Frequency of X
int checkX(char *str)
{
    int count, flag;
    for (int i = 0; i < 8; i++)
    {
        count = 0;
        flag = -1;
        for (int j = 0; j < 3; j++)
        {
            if (str[comb[i][j]] == 'X')
                count++;
            if (str[comb[i][j]] != 'O' && str[comb[i][j]] != 'X')
                flag = j;
            if (count == 2 && flag != -1)
                return 1;
        }
    }
    return 0;
}

// Function to Get Random Number Between Two Values
int random(int min, int max)
{
    return rand() % (max - min) + min;
}
