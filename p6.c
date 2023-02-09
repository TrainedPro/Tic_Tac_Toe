#include <stdio.h>

void printArr(int, char (*arr)[*]);
int check(char, int, char (*arr)[*]);

int main(void) {
    int size = 3;
    char board[3][3] =
        {
            {'*', '*', '*'},
            {'*', '*', '*'},
            {'*', '*', '*'}};

    puts("");
    printArr(size, board);

    int row, col, turns = 0, res = 0;
    int player;
    char targ;
    while (turns < 9) {
        turns++;
        player = 1;
        targ = 'X';

        if (turns % 2 == 0) {
            player = 2;
            targ = 'O';
        }

        printf("\n--------------------------------\n\nPlayer %d Select A Location (Row Col): ", player);
        scanf("%d %d", &row, &col);

        if (board[row][col] == '*' && row >= 0 && row <= 2 && col >= 0 && col <= 2) {
            board[row][col] = targ;
        }

        else {
            printf("Invalid Value, Select Again!\nOnly Numbers Between 0 and 2!\n\n");
            printArr(size, board);
            turns--;
            continue;
        }

        puts("");
        printArr(size, board);


        res = check(targ, size, board);

        if (res == 1) {
            printf("\nPlayer %d Won!\n\n", player);
            return 0;
        }
    }

    printf("\nMatch Ended In A Tie!\n\n");

    return 0;
}

void printArr(int size, char arr[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", arr[i][j]);
        }
        puts("");
    }
}

int check(char targ, int size, char arr[size][size]) {

    int res[4] = {0};

    for (int i = 0; i < size; i++) {
        res[0] = 0;
        res[1] = 0;
        for (int j = 0; j < size; j++) {
            if(arr[i][j] == targ){
                res[0]++;
                if(i == j){
                    res[2]++;
                }

                else if(i == 2 - j){
                    res[3]++;
                }
            }

            if(arr[j][i] == targ){
                res[1]++;
            }

        }

        if(res[0] == 3 || res[1] == 3 || res[2] == 3 || res[3] == 3){
            return 1;
        }
    }

    return 0;
}