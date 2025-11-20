#include <stdio.h>
int N=9;  

int isSafe(int board[N][N], int row, int col, int num) {
    int startRow = row - row % 3;
    int startCol = col - col % 3;


    for (int x = 0; x < N; x++) {
        if (board[row][x] == num || board[x][col] == num)
            return 0;
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num)
                return 0;
        }
    }

    return 1;
}

int solveSudoku(int board[N][N]) {
    int row, col, foundEmpty = 0;

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                foundEmpty = 1;
                break;
            }
        }
        if (foundEmpty)
            break;
    }

    if (!foundEmpty)
        return 1;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board))
                return 1;

            board[row][col] = 0; 
        }
    }

    return 0; 
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    
    printf("Welcome to solver \n Please enter you puzzel and we will tell is soulution\n Enter '0' for empty spaces and rest 1-9");
    int board[9][9];
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){   
            scanf("%d",&board[i][j]);            
        }
    }
    if (solveSudoku(board))
        printBoard(board);
    else
        printf("No solution exists.\n");

    return 0;
}
