#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void error(void);
void show(void);
void print(int, int);
void move(char*);
void capture(char*);
void promote(char*);
int whitePawn();
int blackPawn();
int whiteKing();
int blackKing();
int whiteRook();
int blackRook();
int whiteBishop();
int blackBishop();
int whiteHorse();
int blackHorse();
int whiteQueen();
int blackQueen();

int board[8][8] = {
    {-4, -2, -3, -5, -6, -3, -2, -4},
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {4, 2, 3, 5, 6, 3, 2, 4}

};
int i1, i2, f1, f2;
FILE* output;

bool whitePawn2StepCheck[8];
bool blackPawn2StepCheck[8];

int main(int argc, char** argv) {
    for (int i = 0; i < 8; i++) {
        whitePawn2StepCheck[i] = blackPawn2StepCheck[i] = 1;

    }
    output = fopen("board.csv", "r+");

    for (int i = 0; i < 8; i++) { //print initial board
        for (int j = 0; j < 8; j++) {
            if (board[i][j] < 0) {
                if (j != 7) {
                    fprintf(output, "%d,", board[i][j]);
                } else {
                    fprintf(output, "%d\n", board[i][j]);
                }
            } else if (board[i][j] == 0) {
                if (j != 7) {
                    fprintf(output, " %d,", board[i][j]);
                } else {
                    fprintf(output, " %d\n", board[i][j]);
                }
            } else {
                if (j != 7) {
                    fprintf(output, "+%d,", board[i][j]);
                } else {
                    fprintf(output, "+%d\n", board[i][j]);
                }
            }
        }
    }

    fflush(output);

    int i = 0;
    char cmd[13];
    printf("WELCOME TO CHESS!\nPlease enter commands in this format: mv a1b1\nInput 'quit' to exit game\n\n");
    while (1) {
        printf("Enter command: ");
        scanf("%13[^\n]", cmd);
        getchar();
        //TODO
        if (cmd[0] == 'm' && cmd[1] == 'v') {
            move(cmd);
        } else if (cmd[0] == 'c' && cmd[1] == 'p') {
            capture(cmd);
        } else if (cmd[0] == 'p' && cmd[1] == 'r') {
            promote(cmd);
        } else if (cmd[0] == 's' && cmd[1] == 'h') {
            show();
        } else {
            printf("Game Over!\n");
            break;
        }
    }
    fclose(output);
    return (0);
}

void move(char* cmd) {
    i1 = (9 - (cmd[4] - 48)) - 1; // initial row 
    i2 = cmd[3] - 97; //initial colomn
    f1 = (9 - (cmd[6] - 48)) - 1; //final row
    f2 = cmd[5] - 97; //final colomn

    if ((board[i1][i2] != 0) && (board[f1][f2] == 0)) { //checks if initial position is a piece and final position is empty
        if (board[i1][i2] == 1) { //checks if initial position has a whitepawn
            if (whitePawn()) {
                board[i1][i2] = 0;
                board[f1][f2] = 1;
                print(i1, i2); //first write
                print(f1, f2); //second write
                show();
            }
        } else if (board[i1][i2] == -1) { //chekcs if initial position has a black pawn
            if (blackPawn()) {
                board[i1][i2] = 0;
                board[f1][f2] = -1;
                print(i1, i2); //first write
                print(f1, f2); //second write
                show();
            }
        } else if (board[i1][i2] == 6) { //checks if initial position has a whiteking
            if (whiteKing()) {
                board[i1][i2] = 0;
                board[f1][f2] = 6;
                print(i1, i2); //first write
                print(f1, f2); //second write
                show();
            }
        } else if (board[i1][i2] == -6) { //checks if initial position has a blackKing
            if (blackKing()) {
                board[i1][i2] = 0;
                board[f1][f2] = -6;
                print(i1, i2); //first write
                print(f1, f2); //second write
                show();
            }
        } else if (board[i1][i2] == 4) { //checks if initial position has a whiteRook
            if (whiteRook()) {
                board[i1][i2] = 0;
                board[f1][f2] = 4;
                print(i1, i2); //first write
                print(f1, f2); //second write
                show();
            }
        } else if (board[i1][i2] == -4) { //checks if initial position has a blackRook
            blackRook();
            if (blackRook) {
                board[i1][i2] = 0;
                board[f1][f2] = -4;
                print(i1, i2); //first write
                print(f1, f2); //second write
                show();
            }
        } else if (board[i1][i2] == 3) { //checks if initial position has a whiteBishop
            if (whiteBishop()) {
                board[i1][i2] = 0;
                board[f1][f2] = 3;
                print(i1, i2);
                print(f1, f2);
                show();
            }
        } else if (board[i1][i2] == -3) { //checks if initial position has a blackBishop
            if (blackBishop()) {
                board[i1][i2] = 0;
                board[f1][f2] = -3;
                print(i1, i2);
                print(f1, f2);
                show();
            }
        } else if (board[i1][i2] == 2) { //checks if initial position has a whiteHorse
            if (whiteHorse()) {
                board[i1][i2] = 0;
                board[f1][f2] = 2;
                print(i1, i2);
                print(f1, f2);
                show();
            }
        } else if (board[i1][i2] == -2) { //checks if initial position has a blackHorse
            if (blackHorse()) {
                board[i1][i2] = 0;
                board[f1][f2] = -2;
                print(i1, i2);
                print(f1, f2);
                show();
            }
        } else if (board[i1][i2] == 5) { //checks if initial position has a whiteQueen
            if (whiteQueen()) {
                board[i1][i2] = 0;
                board[f1][f2] = 5;
                print(i1, i2);
                print(f1, f2);
                show();
            }
        } else if (board[i1][i2] == -5) {
            if (blackQueen()) {
                board[i1][i2] = 0;
                board[f1][f2] = -5;
                print(i1, i2);
                print(f1, f2);
                show();
            }
        }// enter rest of the pieces to move
    } else {
        error();
    }
}

void capture(char* cmd) { //checks if initial position is a piece and final position is not empty
    i1 = (9 - (cmd[4] - 48)) - 1; // initial row 
    i2 = cmd[3] - 97; //initial colomn
    f1 = (9 - (cmd[6] - 48)) - 1; //final row
    f2 = cmd[5] - 97; //final colomn
    int value, i, j;
    if ((board[i1][i2] != 0) && (board[f1][f2] != 0)) {
        i = i1 - f1, j = i2 - f2;
        if (board[i1][i2] == 1 && board[f1][f2] < 0) { //checks if initial position has a whitepawn
            if (i == 1 && (j == 1 || j == -1)) {
                board[i1][i2] = 0;
                board[f1][f2] = 1;
                show();
                print(i1, i2); //first write
                print(f1, f2); //second write
            } else {
                error();
            }
        } else if (board[i1][i2] == -1 && board[f1][f2] > 0) { //checks if initial position has a black pawn
            if (i == -1 && (j == 1 || j == -1)) {
                board[i1][i2] = 0;
                board[f1][f2] = -1;
                show();
                print(i1, i2); //first write
                print(f1, f2); //second write
            } else {
                error();
            }
        } else if (board[i1][i2] == 6 && board[f1][f2] < 0) { //checks if initial position has a whiteking and final position isn't empty
            value = board[f1][f2];
            board[f1][f2] = 0; //done
            if (whiteKing()) {
                board[i1][i2] = 0;
                board[f1][f2] = 6;
                print(i1, i2);
                print(f1, f2);
                show();
            } else {
                board[f1][f2] = value;
                error();
            }
        } else if (board[i1][i2] == -6 && board[f1][f2] > 0) { //checks if initial position has a blackKing
            value = board[f1][f2];
            board[f1][f2] = 0; //done
            if (blackKing()) {
                board[i1][i2] = 0;
                board[f1][f2] = -6;
                print(i1, i2);
                print(f1, f2);
                show();
            } else {
                board[f1][f2] = value;
                error();
            }
        } else if (board[i1][i2] == 4 && board[f1][f2] < 0) { //checks if initial position has a whiteRook
            value = board[f1][f2];
            board[f1][f2] = 0; //done
            if (whiteRook()) {
                board[i1][i2] = 0;
                board[f1][f2] = 4;
                print(i1, i2);
                print(f1, f2);
                show();
            } else {
                board[f1][f2] = value;
                error();
            }
        } else if (board[i1][i2] == -4 && board[f1][f2] > 0) { //checks if initial position has a blackRook
            value = board[f1][f2];
            board[f1][f2] = 0; //done
            if (blackRook()) {
                board[i1][i2] = 0;
                board[f1][f2] = -4;
                print(i1, i2);
                print(f1, f2);
                show();
            } else {
                board[f1][f2] = value;
                error();
            }
        } else if (board[i1][i2] == 3 && board[f1][f2] < 0) { //checks if initial position has a whiteBishop
            value = board[f1][f2];
            board[f1][f2] = 0; //done
            if (whiteBishop()) {
                board[i1][i2] = 0;
                board[f1][f2] = 3;
                print(i1, i2);
                print(f1, f2);
                show();
            } else {
                board[f1][f2] = value;
                error();
            }

        } else if (board[i1][i2] == -3 && board[f1][f2] > 0) { //checks if initial position has a blackBishop
            value = board[f1][f2];
            board[f1][f2] = 0; //done
            if (blackBishop()) {
                board[i1][i2] = 0;
                board[f1][f2] = -3;
                print(i1, i2);
                print(f1, f2);
                show();
            } else {
                board[f1][f2] = value;
                error();
            }

        } else if (board[i1][i2] == 2 && board[f1][f2] < 0) { //checks if initial position has a whiteHorse
            value = board[f1][f2];
            board[f1][f2] = 0; //done
            if (whiteHorse()) {
                board[i1][i2] = 0;
                board[f1][f2] = 2;
                print(i1, i2);
                print(f1, f2);
                show();
            } else {
                board[f1][f2] = value;
                error();
            }
        } else if (board[i1][i2] == -2 && board[f1][f2] > 0) { //checks if initial position has a blackHorse
            value = board[f1][f2];
            board[f1][f2] = 0; //TODO
            if (blackHorse()) {
                board[i1][i2] = 0;
                board[f1][f2] = -2;
                print(i1, i2);
                print(f1, f2);
                show();
            } else {
                board[f1][f2] = value;
                error();
            }
        } else if (board[i1][i2] == 5 && board[f1][f2] < 0) { //checks if initial position has a whiteQueen
            value = board[f1][f2];
            board[f1][f2] = 0; //TODO
            if (whiteQueen()) {
                board[i1][i2] = 0;
                board[f1][f2] = 5;
                print(i1, i2);
                print(f1, f2);
                show();
            } else {
                board[f1][f2] = value;
                error();
            }
        } else if (board[i1][i2] == -5 && board[f1][f2] > 0) { //checks if initial position has a blackQueen
            value = board[f1][f2];
            board[f1][f2] = 0; //TODO
            if (blackQueen()) {
                board[i1][i2] = 0;
                board[f1][f2] = -5;
                print(i1, i2);
                print(f1, f2);
                show();
            } else {
                board[f1][f2] = value;
                error();
            }
        } else {
            error();
        }

    }
}

void promote(char* cmd) {
    i1 = (9 - (cmd[4] - 48)) - 1; // initial row 
    i2 = cmd[3] - 97; //initial colomn
    f1 = (9 - (cmd[6] - 48)) - 1; //final row
    f2 = cmd[5] - 97; //final colomn
    char promote = cmd[2];

    int i = board[i1][i2], f = board[f1][f2];

    if (i == 1 && f == 0 && f1 == 1) { //checks if initial position has whitepawn, and final position is empty and is in row 7
        if (whitePawn()) {
            if (!strcmp(promote, 'K')) {
                board[i1][i2] = 0;
                board[f1][f2] = 2;
                show();
                print(i1,i2);
                print(f1,f2);
            } else if (!strcmp(promote, 'B')) {
                board[i1][i2] = 0;
                board[f1][f2] = 3;
                show();
                print(i1,i2);
                print(f1,f2);
            } else if (!strcmp(promote, 'R')) {
                board[i1][i2] = 0;
                board[f1][f2] = 4;
                show();
                print(i1,i2);
                print(f1,f2);
            }
        }

    } else if (i == -1 && f == 0 && f1 == 6) {
        if (blackPawn()) {
            if (!strcmp(promote, 'K')) {
                board[i1][i2] = 0;
                board[f1][f2] = -2;
                show();
                print(i1,i2);
                print(f1,f2);
            } else if (!strcmp(promote, 'B')) {
                board[i1][i2] = 0;
                board[f1][f2] = -3;
                show();
                print(i1,i2);
                print(f1,f2);
            } else if (!strcmp(promote, 'R')) {
                board[i1][i2] = 0;
                board[f1][f2] = -4;
                show();
                print(i1, i2);
                print(f1, f2);
            }
        }
    } else {
        error();
    }

}

int blackQueen() {
    int i, j, tmp, tmp2;
    i = i1 - f1, j = i2 - f2;
    /*
        moving like bishop
     */
    if ((i1 - f1) == (i2 - f2) && (i1 - f1 > 0) && (i2 - f2 > 0)) { //towards upper left quadrant
        j = i2 - 1;
        for (i = i1 - 1; i > f1; i--) {
            if (board[i][j--] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else if ((i1 - f1) == (f2 - i2) && (i1 - f1 > 0) && (i2 - f2 < 0)) { //towards upper right quadrant
        j = i2 + 1;
        for (i = i1 - 1; i > f1; i--) {
            if (board[i][j++] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else if ((f1 - i1) == (i2 - f2) && (i1 - f1 < 0) && (i2 - f2 > 0)) {//towards lower left
        j = i2 - 1;
        for (i = i1 + 1; i < f1; i++) {
            if (board[i][j--] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else if ((f1 - i1) == (f2 - i2) && (i1 - f1 < 0) && (i2 - f2 < 0)) { //towards lower right
        j = i2 + 1;
        for (i = i1 + 1; i < f1; i++) {
            if (board[i][j++] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else if (i2 == f2) { //moving like rook
        if (i1 - f1 > 0) {
            for (i = i1 - 1; i > f1 - 1; i--) {
                if (board[i][f2] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else if (i1 - f1 < 0) {
            for (int i = i1 + 1; i < f1; i++) {
                if (board[i][f2] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else {
            error();
            return 0;
        }
    } else if (i1 == f1) { //moving like rook
        if (i2 - f2 > 0) {
            for (i = i2 - 1; i > f2 - 1; i--) {
                if (board[f1][i] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else if (i2 - f2 < 0) {
            for (i = i2 + 1; i < f2 + 1; i++) {
                if (board[f1][i] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else {
            error();
            return 0;
        }

    } else {
        error();
        return 0;
    }
    return 1;
}

int whiteQueen() {
    int i, j, tmp, tmp2;
    i = i1 - f1, j = i2 - f2;
    /*
        moving like bishop
     */
    if ((i1 - f1) == (i2 - f2) && (i1 - f1 > 0) && (i2 - f2 > 0)) { //towards upper left quadrant
        j = i2 - 1;
        for (i = i1 - 1; i > f1; i--) {
            if (board[i][j--] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else if ((i1 - f1) == (f2 - i2) && (i1 - f1 > 0) && (i2 - f2 < 0)) { //towards upper right quadrant
        j = i2 + 1;
        for (i = i1 - 1; i > f1; i--) {
            if (board[i][j++] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else if ((f1 - i1) == (i2 - f2) && (i1 - f1 < 0) && (i2 - f2 > 0)) {//towards lower left
        j = i2 - 1;
        for (i = i1 + 1; i < f1; i++) {
            if (board[i][j--] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else if ((f1 - i1) == (f2 - i2) && (i1 - f1 < 0) && (i2 - f2 < 0)) { //towards lower right
        j = i2 + 1;
        for (i = i1 + 1; i < f1; i++) {
            if (board[i][j++] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else if (i2 == f2) { //moving like rook
        if (i1 - f1 > 0) {
            for (i = i1 - 1; i > f1 - 1; i--) {
                if (board[i][f2] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else if (i1 - f1 < 0) {
            for (int i = i1 + 1; i < f1; i++) {
                if (board[i][f2] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else {
            error();
            return 0;
        }
    } else if (i1 == f1) { //moving like rook
        if (i2 - f2 > 0) {
            for (i = i2 - 1; i > f2 - 1; i--) {
                if (board[f1][i] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else if (i2 - f2 < 0) {
            for (i = i2 + 1; i < f2 + 1; i++) {
                if (board[f1][i] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else {
            error();
            return 0;
        }

    } else {
        error();
        return 0;
    }
}

int blackHorse() {
    int i = i1 - f1, j = i2 - f2;
    if (i < 0) { //lower L
        if (j > 0 && ((i == -1 && j == 2) || (i == -2 && j == 1))) { //lower left

            return 1;
        } else if (j < 0 && ((i == -2 && j == -1) || (i == -1 && j == -2))) { //lower right

            return 1;
        } else {
            error();
            return 0;
        }
    } else if (i > 0) { //upper
        if (j > 0 && ((i == 1 && j == 2) || (i == 2 && j == 1))) { //upper left

            return 1;
        } else if (j < 0 && ((i == 2 && j == -1) || (i == 1 && j == -2))) { //upper right

            return 1;
        } else {
            error();
            return 0;
        }
    }

}

int whiteHorse() {
    int i = i1 - f1, j = i2 - f2;
    if (i < 0) { //lower L
        if (j > 0 && ((i == -1 && j == 2) || (i == -2 && j == 1))) { //lower left

            return 1;
        } else if (j < 0 && ((i == -2 && j == -1) || (i == -1 && j == -2))) { //lower right

            return 1;
        } else {
            error();
            return 0;
        }
    } else if (i > 0) { //upper
        if (j > 0 && ((i == 1 && j == 2) || (i == 2 && j == 1))) { //upper left

            return 1;
        } else if (j < 0 && ((i == 2 && j == -1) || (i == 1 && j == -2))) { //upper right

            return 1;
        } else {
            error();
            return 0;
        }
    }

}

int blackBishop() {
    int i, j;
    if ((i1 - f1) == (i2 - f2) && (i1 - f1 > 0) && (i2 - f2 > 0)) { //towards upper left quadrant
        j = i2 - 1;
        for (i = i1 - 1; i > f1; i--) {
            if (board[i][j--] != 0) {
                error();
                return 0;
                ;
            }
        }

        return 1;
    } else if ((i1 - f1) == (f2 - i2) && (i1 - f1 > 0) && (i2 - f2 < 0)) { //towards upper right quadrant
        j = i2 + 1;
        for (i = i1 - 1; i > f1; i--) {
            if (board[i][j++] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else if ((f1 - i1) == (i2 - f2) && (i1 - f1 < 0) && (i2 - f2 > 0)) {//towards lower left
        j = i2 - 1;
        for (i = i1 + 1; i < f1; i++) {
            if (board[i][j--] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else if ((f1 - i1) == (f2 - i2) && (i1 - f1 < 0) && (i2 - f2 < 0)) { //towards lower right
        j = i2 + 1;
        for (i = i1 + 1; i < f1; i++) {
            if (board[i][j++] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else {
        error();
        return 0;
    }

}

int whiteBishop() {
    int i, j;
    if ((i1 - f1) == (i2 - f2) && (i1 - f1 > 0) && (i2 - f2 > 0)) { //towards upper left quadrant
        j = i2 - 1;
        for (i = i1 - 1; i > f1; i--) {
            if (board[i][j--] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else if ((i1 - f1) == (f2 - i2) && (i1 - f1 > 0) && (i2 - f2 < 0)) { //towards upper right quadrant
        j = i2 + 1;
        for (i = i1 - 1; i > f1; i--) {
            if (board[i][j++] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else if ((f1 - i1) == (i2 - f2) && (i1 - f1 < 0) && (i2 - f2 > 0)) {//towards lower left
        j = i2 - 1;
        for (i = i1 + 1; i < f1; i++) {
            if (board[i][j--] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else if ((f1 - i1) == (f2 - i2) && (i1 - f1 < 0) && (i2 - f2 < 0)) { //towards lower right
        j = i2 + 1;
        for (i = i1 + 1; i < f1; i++) {
            if (board[i][j++] != 0) {
                error();
                return 0;
            }
        }

        return 1;
    } else {
        error();
        return 0;
    }
}

int blackRook() {
    if (i2 == f2) { //climbing up without nothing in between
        if (i1 - f1 > 0) {
            int i;
            for (i = i1 - 1; i > f1 - 1; i--) {
                if (board[i][f2] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else if (i1 - f1 < 0) {
            for (int i = i1 + 1; i < f1; i++) {
                if (board[i][f2] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else {
            error();
            return 0;
        }
    } else if (i1 == f1) {
        if (i2 - f2 > 0) {
            int i;
            for (i = i2 - 1; i > f2 - 1; i--) {
                if (board[f1][i] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else if (i2 - f2 < 0) {
            int i;
            for (i = i2 + 1; i < f2 + 1; i++) {
                if (board[f1][i] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else {
            error();
            return 0;
        }

    } else {
        error();
        return 0;
    }
}

int whiteRook() {
    if (i2 == f2) { //climbing straight up without nothing in between
        if (i1 - f1 > 0) {
            int i;
            for (i = i1 - 1; i > f1 - 1; i--) {
                if (board[i][f2] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else if (i1 - f1 < 0) {
            for (int i = i1 + 1; i < f1; i++) {
                if (board[i][f2] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else {
            error();
            return 0;
        }
    } else if (i1 == f1) {
        if (i2 - f2 > 0) {
            int i;
            for (i = i2 - 1; i > f2 - 1; i--) {
                if (board[f1][i] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else if (i2 - f2 < 0) {
            int i;
            for (i = i2 + 1; i < f2 + 1; i++) {
                if (board[f1][i] != 0) {
                    error();
                    return 0;
                }
            }

            return 1;
        } else {
            error();
            return 0;
        }

    } else {
        error();
        return 0;
    }
}

int whiteKing() {
    if ((i1 < 8 && i1 >= 0 && i2 < 8 && i2 >= 0 && f1 < 8 && f1 >= 0 && f2 < 8 && f2 >= 0)) {
        if ((f1 - i1 == 0 || f1 - i1 == -1 || f1 - i1 == 1)&&(f2 - i2 == 0 || f2 - i2 == 1 || f2 - i2 == -1)) {

            return 1;
        } else {
            error();
            return 0;
        }
    } else {
        error();
        return 0;
    }
}

int blackKing() {
    if ((i1 < 8 && i1 >= 0 && i2 < 8 && i2 >= 0 && f1 < 8 && f1 >= 0 && f2 < 8 && f2 >= 0)) { // checks if row and col are in boundaries
        //checks if final space is one tile away in any direction 
        if ((f1 - i1 == 0 || f1 - i1 == -1 || f1 - i1 == 1)&&(f2 - i2 == 0 || f2 - i2 == 1 || f2 - i2 == -1)) {

            return 1;
        } else {
            error();
            return 0;
        }
    } else {
        error();
        return 0;
    }
}

int whitePawn() {
    if (i1 - f1 > 0 && i2 == f2) { //checks if white pawn is moving up and in the same colomn
        if (i1 - f1 == 2) { //checks if white pawn is moving 2 spaces at first move
            if (whitePawn2StepCheck[i2] == 1) { //checks if 2 space move is available for that colomn
                whitePawn2StepCheck[i2] = 0;
                return 1;
            } else {
                error();
                return 0;
            }
        } else if (i1 - f1 == 1) { //checks if white pawn is moving 1 space

            whitePawn2StepCheck[i2] = 0;
            return 1;
        } else {
            error();
            return 0;
        }
    } else {
        error();
        return 0;
    }
}

int blackPawn() {

    if (i1 - f1 < 0 && i2 == f2) { //checks if black pawn is moving down and in the same colomn
        if (i1 - f1 == -2) { //checks if black pawn is moving 2 spaces at first move
            if (blackPawn2StepCheck[i2] == 1) { //checks if 2 space move is available for that colomn
                board[i1][i2] = 0;
                board[f1][f2] = -1;
                show();
                print(i1, i2); //first write
                print(f1, f2); //second write
                blackPawn2StepCheck[i2] = 0;
            } else {
                error();
            }
        } else if (i1 - f1 == -1) { //checks if black pawn is moving 1 space down
            board[i1][i2] = 0;
            board[f1][f2] = -1;
            show();
            print(i1, i2); //first write
            print(f1, f2); //second write
            blackPawn2StepCheck[i2] = 0;

        } else {
            error();
        }
    } else {
        error();
    }
}

void print(int row, int col) {
    int trv = 0;
    trv += (row * 24) + 1;
    trv += (col * 3);
    rewind(output);

    if (board[row][col] < 0) {
        fseek(output, trv - 1, SEEK_SET);
        fprintf(output, "%d", board[row][col]);
    } else if (board[row][col] > 0) {
        fseek(output, trv - 1, SEEK_SET);
        fprintf(output, "+%d", board[row][col]);
    } else {
        fseek(output, trv - 1, SEEK_SET);
        fprintf(output, " %d", board[row][col]);
    }

    fflush(output);
}

void show() {
    int row = 8;
    for (int i = 0; i < 8; i++) {
        printf("%d: ", row--);
        for (int j = 0; j < 8; j++) {

            if (board[i][j] < 0) {
                if (j != 7) {
                    printf("%d,", board[i][j]);
                } else {
                    printf("%d\n", board[i][j]);
                }
            } else if (board[i][j] == 0) {
                if (j != 7) {
                    printf(" %d,", board[i][j]);
                } else {
                    printf(" %d\n", board[i][j]);
                }
            } else {
                if (j != 7) {
                    printf("+%d,", board[i][j]);
                } else {
                    printf("+%d\n", board[i][j]);
                }
            }

        }
    }
    printf("    a  b  c  d  e  f  g  h\n");
}

void error() {
    printf("Illegal move, try again\n");
}