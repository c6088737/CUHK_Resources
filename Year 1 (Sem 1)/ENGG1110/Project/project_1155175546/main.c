/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : Chan Cho Kit
 * Student ID    : 1155175546
 * Class/Section : F
 * Date          : 17/11/2021
 */

#include <stdio.h>
/* NO other header files are allowed */

/* NO global variables are allowed */

/* Macros used to represent the state of each square */
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2

/* Initialize the game board by setting all squares to EMPTY */
void initGameBoard(int gameBoard[6][7]) {

    // TODO : Complete this part
    int i,j;
    for (i=0;i<6;i++){
      for (j=0;j<7;j++){
        gameBoard[i][j] = EMPTY;
      }
    }
    for (i=0;i<6;i++){
      for (j=0;j<7;j++){
        if (gameBoard[i][j] == EMPTY)
        printf("| ");
        }
      printf("|\n");
    }
    printf(" 1 2 3 4 5 6 7 \n");
    return ;
}



/* Display the game board on the screen.
   You are required to exactly follow the output format stated in the project specification.
   IMPORTANT: Using other output format will result in mark deduction. */
void printGameBoard(int gameBoard[6][7]) {

    // TODO : Complete this part
    int h,k;

    for (h=0;h<6;h++){
      for (k=0;k<7;k++){
        if (gameBoard[h][k] == EMPTY)
        printf("| ");
        else if (gameBoard[h][k] == CIRCLE)
        printf("|0");
        else if (gameBoard[h][k] == CROSS)
        printf("|X");
        }
      printf("|\n");
    }
    printf(" 1 2 3 4 5 6 7 \n");
    return ;
}



/* Ask the human player to place the mark.
   You can assume that the user input must be an integer. */
void placeMarkByHumanPlayer(int gameBoard[6][7], int mark) {

    // TODO : Complete this part
    int input,a=6;
    scanf("%d",&input);
    while(input <1 || input >7){
      printf("Input out of range. Please input again:\n");
      scanf("%d",&input);}
    if(input >=1 && input <=7){
      while (a>=0){
        if (gameBoard[a-1][input-1] != EMPTY)
        a--;
        else if (gameBoard[a-1][input-1] == EMPTY)
        {if (mark == CIRCLE) gameBoard[a-1][input-1] = CIRCLE;
        else if (mark == CROSS) gameBoard[a-1][input-1] = CROSS;
        a=-1;}
        if (a==0)
        {printf("Column is full. Please input again:\n");
        scanf("%d",&input);
        while(input <1 || input >7){
          printf("Input out of range. Please input again:\n"); scanf("%d",&input);}
        a=6;}
      }
      }
      return ;
      }
/* Return 1 if there is a winner in the game, otherwise return 0.
   Note: the winner is the current player indicated in main(). */
int hasWinner(int gameBoard[6][7]){

    // TODO : Complete this part
    int p,q,r,s,vert=0,hori=0,rdign=0,ldign=0;
    for(p=5;p>=0;p--){
      for(q=3;q<=6;q++){
      if (gameBoard[p][q] == gameBoard[p][q-1] && gameBoard[p][q-1] == gameBoard[p][q-2] && gameBoard[p][q-2] == gameBoard[p][q-3] && gameBoard[p][q] != EMPTY)
      hori++;}
      }
    for(s=0;s<=6;s++){
      for(r=5;r>=3;r--){
      if (gameBoard[r][s] == gameBoard[r-1][s] && gameBoard[r-1][s] == gameBoard[r-2][s] && gameBoard[r-2][s] == gameBoard[r-3][s] && gameBoard[r][s] != EMPTY)
      vert++;}
      }
    for(s=0;s<=6;s++){
      for(r=0;r<=2;r++){
      if (gameBoard[r][s] == gameBoard[r+1][s+1] && gameBoard[r+1][s+1] == gameBoard[r+2][s+2] && gameBoard[r+2][s+2] == gameBoard[r+3][s+3] && gameBoard[r][s] != EMPTY)
      ldign++;}
      }
    for(s=6;s>=0;s--){
      for(r=0;r<=2;r++){
      if (gameBoard[r][s] == gameBoard[r+1][s-1] && gameBoard[r+1][s-1] == gameBoard[r+2][s-2] && gameBoard[r+2][s-2] == gameBoard[r+3][s-3] && gameBoard[r][s] != EMPTY)
      rdign++;}
      }
    if (vert>0 || hori>0 || rdign>0 || ldign>0)
    return 1;
    else return 0;
    }



/* Return 1 if the game board is full, otherwise return 0. */
int isFull(int gameBoard[6][7]) {

    // TODO : Complete this part
    int x=0,y=0;
    for (x=0;x<=6;x++){
      if (gameBoard[0][x] != EMPTY)
      y++;
    }
    if (y==7) return 1;
    else return 0;
}



/* Determine the next move of the computer player.
   You are required to exactly follow the strategy mentioned in the project specification.
   Using other strategies will result in mark deduction. */

// TODO : **Write the placeMarkByComputerPlayer(...) function here

void placeMarkByComputerPlayer(int gameBoard[6][7], int mark){
  int o=5,i=5,t=0,u=0,e=5,f=6;

  while(t<=6){
    if(gameBoard[o][t] != EMPTY)
    o--;
    if(o<0)
    {o=5;
    t++;}
    if(gameBoard[o][t] == EMPTY)
    {
      gameBoard[o][t] = CROSS;
      if (hasWinner(gameBoard) == 1)
      {t=10;
      o=-10;}
      else {gameBoard[o][t] = EMPTY;
      t++;
      o=5;}
    }
  }

  if(t==7){
  while(u<=6){
    if(gameBoard[i][u] != EMPTY)
    i--;
    if(i<0)
    {i=5;
    u++;}
    if(gameBoard[i][u] == EMPTY)
    {
      gameBoard[i][u] = CIRCLE;
      if (hasWinner(gameBoard) == 1)
      {gameBoard[i][u] = CROSS;
      u=10;
      i=-10;}
      else {gameBoard[i][u] = EMPTY;
      u++;
      i=5;}
    }
  }

  if(u==7){
    for(e=5;e>=0;e--){
      f=6;
      while(f>=0){
        if (gameBoard[e][f] == EMPTY)
        {gameBoard[e][f] = CROSS;
        e=-10;
        f=-10;}
        else f--;
      }
    }
  }

return ;
}
}


/* The main function */
int main()
{
    /* Local variables */
    int gameBoard[6][7];    // Each element stores 0 (EMPTY), 1 (CIRCLE), or 2 (CROSS)
    int currentPlayer;      // 1: Player 1             2: Player 2
    int gameContinue;       // 1: The game continues   0: The game ends
    int numOfHumanPlayers;  // 1 or 2

    /* Initialize the local variables */
    currentPlayer = 1;
    gameContinue = 1;
    printf("Enter the number of human players [1-2]:\n");
    scanf("%d", &numOfHumanPlayers);    // You can assume that the user input must be valid
    initGameBoard(gameBoard);
    /* Uncomment the following statements to test whether the printGameBoard() and the placeMarkByHumanPlayer() functions
       are implemented correctly.
       You can add more if you wish.
       After testing, you can delete them or move them elsewhere. */
    //printGameBoard(gameBoard);
    //printf("Player 1's turn:\n");
    //placeMarkByHumanPlayer(gameBoard, CIRCLE);
    //printGameBoard(gameBoard);
    //printf("Player 2's turn:\n");
    //placeMarkByHumanPlayer(gameBoard, CROSS);
    //printGameBoard(gameBoard);

    /* Game start
       If there are two human players, they are Player 1 and Player 2
       If there is only one human player, he/she is Player 1 and another player is the computer player
       For both cases, Player 1 moves first and places the CIRCLE mark; while Player 2 (or the computer player) places the CROSS mark
       Hint: use a while loop */

    // TODO : Complete this part
    int w=0;

    //2 human players
    if (numOfHumanPlayers == 2){

    while(w==0){
    if(gameContinue==1){
    printf("Player 1's turn:\n");
    placeMarkByHumanPlayer(gameBoard, CIRCLE);
    printGameBoard(gameBoard);
    hasWinner(gameBoard);
    if (hasWinner(gameBoard) == 1){
      printf("Congratulations!Player 1 wins!\n");
      gameContinue=0;
      w++;}
    isFull(gameBoard);
    if (isFull(gameBoard) == 1){
      printf("Draw game.\n");
      gameContinue=0;
      w++;}
    }

    if(gameContinue==1){
    printf("Player 2's turn:\n");
    placeMarkByHumanPlayer(gameBoard, CROSS);
    printGameBoard(gameBoard);
    hasWinner(gameBoard);
    if (hasWinner(gameBoard) == 1){
      printf("Congratulations!Player 2 wins!\n");
      gameContinue=0;
      w++;}
    isFull(gameBoard);
    if (isFull(gameBoard) == 1){
      printf("Draw game.\n");
      gameContinue=0;
      w++;}
    }
    }
    }





    //1 computer player
    else if (numOfHumanPlayers == 1){

    while(w==0){
    if(gameContinue==1){
    printf("Player 1's turn:\n");
    placeMarkByHumanPlayer(gameBoard, CIRCLE);
    printGameBoard(gameBoard);
    hasWinner(gameBoard);
    if (hasWinner(gameBoard) == 1){
      printf("Congratulations!Player 1 wins!\n");
      gameContinue=0;
      w++;}
    isFull(gameBoard);
    if (isFull(gameBoard) == 1){
      printf("Draw game.\n");
      gameContinue=0;
      w++;}
    }

    if(gameContinue==1){
    printf("Computer's turn:\n");
    placeMarkByComputerPlayer(gameBoard, CROSS);
    printGameBoard(gameBoard);
    hasWinner(gameBoard);
    if (hasWinner(gameBoard) == 1){
      printf("Computer wins!\n");
      gameContinue=0;
      w++;}
    isFull(gameBoard);
    if (isFull(gameBoard) == 1){
      printf("Draw game.\n");
      gameContinue=0;
      w++;}
    }
    }
    }
    return 0;
}
