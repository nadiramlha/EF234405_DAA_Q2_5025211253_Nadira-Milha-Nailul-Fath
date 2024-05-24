# DAA Q2

### Group Member :
Nadira Milha Nailul Fath - 5025211253

### About

**The Tic Tac Toe game** is a classic two-player game where the objective is to form a straight line (horizontal, vertical, or diagonal) with three marks (X or O) on a 3x3 grid. This implementation of Tic Tac Toe is designed for a single player to compete against a bot. The bot uses a simple random selection method to make its moves. The game provides a console interface for user interaction.

### Design

#### 1. Program Structure:

The program is written in C and consists of several functions to handle different aspects of the game such as displaying the main screen, drawing the game board, initializing the game state, checking for game results, and determining the bot's moves.

#### 2. Key Components:

arr[3][3]: A 3x3 character array that represents the game board. Each cell can be '.', 'X', or 'O'.
mainScreen(): Displays the main menu of the game, simplified to only display the Player vs Bot option.
gameBoard(const char* P1, const char* P2): Renders the current state of the game board along with player names.
init(): Initializes the game board to its default empty state (all cells set to '.').
result(): Checks the current state of the board and returns the result of the game ('X' if Player 1 wins, 'O' if the Bot wins, 'T' for a draw, and '-' if the game is still ongoing).
minimax(int depth, bool isMaximizing): A function for evaluating the best move for the bot using the Minimax algorithm (though not used in the current bot's move strategy).
bestMove(): Determines the best possible move for the bot using the Minimax algorithm (though this function is not called in the current game loop).
main(): The main function which contains the game loop, handling player input, and bot moves.

#### 3. Game Flow:

The game starts with displaying the main menu.
The player chooses whether the bot goes first.
The game alternates between player and bot moves until there is a win or a draw.
After the game ends, the player can choose to play again or exit.

### 4. Bot Logic:

The bot's move is currently determined by randomly selecting an empty cell on the board.

### Analysis
#### 1. Game Mechanics:

The game correctly alternates turns between the player and the bot.
It checks for invalid moves and prompts the player to input a valid move.
The game ends when there is a win or a draw, and it correctly identifies and displays the result.

#### 2. Bot Strategy:

The current bot strategy uses random moves. While simple, this strategy can be improved to provide a more challenging opponent using algorithms like Minimax for optimal play.
The Minimax function is implemented but not integrated into the main game loop. Integrating it could make the bot unbeatable, providing a better challenge.

#### 3. User Interaction:

The console-based interface is straightforward but could be enhanced with better error messages and prompts.
Input validation is basic; further enhancements could include better handling of out-of-bounds and invalid input.

#### 4. Code Efficiency:

The code is structured in a clear and modular way, which is good for maintenance and further development.
Some redundant code (like the Minimax function and bestMove function) could be optimized or removed if not used.

### Algorithms Used in the Tic Tac Toe Game
#### Random Move Selection for the Bot:

In the current implementation of the game, the bot selects its moves randomly from the available empty cells on the board. This is a simple and straightforward approach that ensures the bot's moves are valid but not necessarily optimal.

Code Snippet:

```
srand(time(0));
while(1){
    x = rand() % 3;
    y = rand() % 3;
    if(arr[x][y] == '.') break;
}
arr[x][y] = 'O';
```
Explanation:

srand(time(0)) seeds the random number generator to ensure different sequences of random numbers in different runs.
rand() % 3 generates a random number between 0 and 2 for both row (x) and column (y).
The while loop checks if the randomly chosen cell is empty (i.e., arr[x][y] == '.'). If it is, the loop breaks, and the bot places 'O' in that cell.

#### Result Checking:

The function result() is used to determine the current state of the game by checking for winning conditions or a draw.

Code Snippet:

```
char result() {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] != '.') {
            return arr[i][0];
        }
    }
    for (int i = 0; i < 3; i++) {
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[2][i] != '.') {
            return arr[0][i];
        }
    }
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] != '.') {
        return arr[0][0];
    }
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] != '.') {
        return arr[0][2];
    }
    bool cek = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == '.') {
                cek = false;
                break;
            }
        }
    }
    if (cek) return 'T';
    return '-';
}
```

Explanation:

The function checks each row, column, and diagonal to see if all cells in any of them are the same (either 'X' or 'O') and not empty ('.'). If a winning line is found, it returns the winner ('X' or 'O').
If no winner is found, it checks if the board is full, indicating a draw ('T').
If neither condition is met, it returns '-' indicating that the game is still ongoing.

#### Summary
Random Move Selection: The current bot strategy that selects moves randomly from available cells.
Result Checking: A straightforward algorithm to determine the game outcome by checking rows, columns, and diagonals.
While the Minimax algorithm provides a robust method for making optimal moves, integrating it into the game will significantly enhance the bot's performance, making it a challenging opponent for the player. The current implementation's simplicity makes it a good starting point for further enhancements and improvements.
