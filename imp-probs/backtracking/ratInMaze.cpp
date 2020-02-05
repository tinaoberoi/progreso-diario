bool notValid(int maze[][20], int n, int x, int y, int solution[20][20]){
    if(x>=n || y>=n || solution[x][y] == 1 || maze[x][y] == 0 || x<0 || y<0)
        return true;
    
    return false;
}

void printSol(int solution[20][20], int n){
    for(int i=0; i<n; i++){
        for(int j =0; j<n; j++){
            cout<<solution[i][j]<<" ";
        }
    }
    cout<<endl;
}

void helper(int maze[][20], int n, int x, int y, int solution[20][20]){
    if(x == n-1 && y == n-1){
        solution[x][y] = 1;
        printSol(solution, n);
        solution[x][y] = 0;
    }
    
    if(notValid(maze, n, x, y, solution))
        return;
    
    solution[x][y] = 1;
    helper(maze, n, x+1, y, solution);
    helper(maze, n, x, y+1, solution);
    helper(maze, n, x-1, y, solution);
    helper(maze, n, x, y-1, solution);
    solution[x][y] = 0;
}

void ratInAMaze(int maze[20][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    int solution[20][20];
    for(int i=0; i<20; i++){
        for(int j =0; j<20; j++){
            solution[i][j]= 0;
        }
    }
    helper(maze, n, 0, 0, solution);

}
