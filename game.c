#include <stdio.h>
#include <stdbool.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char turn = 'X';

int tries = 0;

void display_board() {
    printf("\n\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

void get_input() {
    int x, y;
    printf("\n%c's turn. Enter the coordinates: ", turn);
    scanf("%d%d", &x, &y);

    tries++;

    x--;
    y--;

    if (board[x][y] != 'X' && board[x][y] != 'O') {
        board[x][y] = turn;
        if (turn == 'X')
            turn = 'O';
        else
            turn = 'X';
    } else {
        printf("\nInvalid move! Try again.");
    }
}

char check_win() {
    int i;

    // check rows
    for (i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0];

    // check columns
    for (i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return board[0][i];

    // check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return board[0][0];
    if (board[2][0] == board[1][1] && board[2][0] == board[0][2])
        return board[2][0];

    return ' ';
}

int main() {
    printf("Welcome to Tic Tac Toe!\n\n");
    printf("Enter the coordinates of your move, such as '1 1' for the top left cell.\n\n");

    display_board();

    while (true) {
        get_input();
        display_board();

        char win = check_win();
        if (win == 'X') {
            printf("\nX wins!\n");
            break;
        } else if (win == 'O') {
            printf("\nO wins!\n");
            break;
        } else if (tries == 9) {
            printf("\nGame tied!\n");
            break;
        }
    }

    printf("\nGame over. Thanks for playing!\n");
}
