/*
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
*/
#include<iostream>
using namespace std;

int board[11][11];

void printBoard(int n){
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
    }
    return;
}

bool isPossible(int n, int row, int column){
    for(int i = row -1; i>=0; i--){
        if(board[i][column] == 1)
            return false;
    }
    for(int i = row-1, j = column-1; i>=0 && j >=0; i--, j--){
        if(board[i][j] == 1)
            return false;
    }
    for(int i = row-1, j = column+1; i>=0 && j <n; i--, j++){
        if(board[i][j] == 1)
            return false;
    }
    return true;
}

void placeNQueensHelper(int n, int row){
    // If row is n, we have reached an answer
    if(row == n){
        printBoard(n);
        cout<<endl;
        return;
    }else{
        for(int j =0; j<n; j++){
            if(isPossible(n, row, j)){
                board[row][j] = 1;
                placeNQueensHelper(n, row+1);
                board[row][j] = 0;
            }
        }
    }
    return;
}

void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
   placeNQueensHelper(n, 0);

}

int main(){

  int n; 
  cin >> n ;
  placeNQueens(n);

}


