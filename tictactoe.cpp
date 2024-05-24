#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char arr[3][3]= {'.','.','.',
                 '.','.','.',
                 '.','.','.'};

void mainScreen(){
    printf("================= Tic Tac Toe =================\n\n");
    printf("\tPlayer vs Bot\n");
    printf("===============================================\n");
}

void gameBoard(const char* P1, const char* P2) {
    printf("=============== Tic Tac Toe ===============\n\n");
    printf("\t\t %c | %c | %c \n", arr[0][0], arr[0][1], arr[0][2]);
    printf("\t\t---+---+---\n");
    printf("\t\t %c | %c | %c \n", arr[1][0], arr[1][1], arr[1][2]);
    printf("\t\t---+---+---\n");
    printf("\t\t %c | %c | %c \n", arr[2][0], arr[2][1], arr[2][2]);
    printf("\n\t %s : 'X'\t %s : 'O'\n", P1, P2);
    printf("===========================================\n");
}

void init(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i][j]='.';
        }
    }
}

char result(){
    for (int i = 0; i < 3; i++){
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] != '.'){
            return arr[i][0];
        }
    }

    for (int i = 0; i < 3; i++){
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[2][i] != '.'){
            return arr[0][i];
        }
    }

    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] != '.'){
        return arr[0][0];
    }

    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] != '.'){
        return arr[0][2];
    }

    bool isDraw = true;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[i][j] == '.') {
                isDraw = false;
                break;
            }
        }
    }

    if(isDraw) return 'T';
    return '-';
}

int main (){
    while(1){
        system("cls");
        mainScreen();
        init();

        int player = 1, x, y, cnt = 0;

        // Player vs Bot
        int turn;
        system("cls");
        printf("Bot go first? (1/0) : ");
        scanf("%d", &turn);

        if(turn) cnt++;
        while(1){
            system("cls");
            gameBoard("Player", "Bot");
            if(cnt % 2 == 0){
                printf("\n\t     Player your move: \n\t\t    ");
                scanf("%d %d", &x, &y);
                if(arr[x][y] == 'X' || arr[x][y] == 'O' || x < 0 || x > 2 || y < 0 || y > 2) continue;
                arr[x][y] = 'X';
                cnt++;
            }
            else {
                printf("\nBot\n");
                srand(time(0));
                while(1){
                    x = rand() % 3;
                    y = rand() % 3;
                    if(arr[x][y] == '.') break;
                }
                arr[x][y] = 'O';
                cnt++;
            }
            char res = result();
            if(res != '-'){
                system("cls");
                gameBoard("Player", "Bot");
                if(res == 'O')          printf("\n\t\t  Bot Win.\n");
                else if (res == 'X')    printf("\n\t\tPlayer Win.\n");
                else if (res == 'T')    printf("\n\t\t   Draw.\n");
                break;
            }
        }

        int repeat;
        printf("\n===========================================\n\n");
        printf("\t   Play again? (1/0) : ");
        scanf("%d", &repeat);
        if (repeat == 0) return 0;
    }
}
