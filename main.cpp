//
//  main.cpp
//  Sudoku Backtracking
//
//  Created by 李欣达 on 16/8/21.
//  Copyright © 2016年 李欣达. All rights reserved.
//


// A Sukodu solver program using backtracking algorithm


#include <stdio.h>

bool is_valid(int [9][9],int,int,int);


// find the first 0 in grid.
bool find(int grid[9][9],int &r,int &c){
    for(r=0;r<9;++r){
        for(c=0;c<9;++c){
            if(grid[r][c]==0)
                return true;
        }
    }
    return false;
}


// determine whether grid has a solution.
bool have_sol(int grid[9][9]){
    int r,c;
    if(!find(grid,r,c))
        return true;
    for(int i=1;i<=9;++i){
        if(is_valid(grid,r,c,i)){
            grid[r][c]=i;
            if(have_sol(grid))
                return true;
            else{
                grid[r][c]=0;
            }
        }
    }
    return false;
}



// checking the inserted row
bool check_row(int grid[9][9],int row,int n){
    for(int c=0;c<9;++c){
        if(grid[row][c]==n)
            return true;
    }
    return false;
}


// checking the inserted column
bool check_col(int grid[9][9],int col,int n){
    for(int r=0;r<9;++r){
        if(grid[r][col]==n)
            return true;
    }
    return false;
}


// checking the inserted 3*3 grid
bool check_grid(int grid[9][9],int row,int col,int n){
    int start_row=row-row%3;
    int start_col=col-col%3;
    for(int r=start_row;r<start_row+3;++r){
        for(int c=start_col;c<start_col+3;++c){
            if(grid[r][c]==n)
                return true;
        }
    }
    return false;
}


// checking whether the inserted position is valid
bool is_valid(int grid[9][9],int row,int col,int n){
    return !check_row(grid,row,n)&&!check_col(grid,col,n)&&!check_grid(grid,row,col,n);
}



// print the Sudoku board
void draw(int grid[9][9]){
    for(int r=0;r<9;++r){
        if(r%3==0)
            printf("----------------------\n");
        for(int c=0;c<9;++c){
            if(c%3==0)
                printf("|");
            printf("%2d",grid[r][c]);
            if(c==8)
                printf("|");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    /*
     Samples:
    int grid[9][9]={
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,0,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };
    int grid2[9][9]={
        {0,8,5,0,0,0,2,1,0},
        {0,9,4,0,1,2,0,0,3},
        {0,0,0,3,0,0,7,0,4},
        {5,0,3,4,0,9,0,0,0},
        {0,4,0,2,0,6,0,3,0},
        {0,0,0,1,0,3,9,0,7},
        {6,0,8,0,0,5,0,0,0},
        {1,0,0,8,4,0,3,6,0},
        {0,2,7,0,0,0,8,9,0}
    };
     */
    
    int grid0[9][9];
    printf("Please insert a VALID Sudoku board: \n");
    for(int r=0;r<9;++r){
        for(int c=0;c<9;++c){
            if(scanf("%d",&grid0[r][c])!=1||grid0[r][c]>9||grid0[r][c]<0){
                printf("Invalid input!\n");
                return 0;
            }
        }
    }

    if(have_sol(grid0)){
        printf("One solution is: \n");
        draw(grid0);
    }
    else
        printf("No Sol!\n");

}


