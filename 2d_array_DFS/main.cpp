//
//  main.cpp
//  2D array DFS Algorithm
//
//  Created by Hasan Unlu on 7/6/16.
//  Copyright © 2016 Hasan Unlu. All rights reserved.
//
//

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void recc(int **tb, int size, int depth, int del_col, int& sol_num){
    
    if(depth==0){
        sol_num++;
        return;
    }
    
    for(int i=0, j=1; i<size; i++, j=j<<1)
        if(tb[depth-1][i] && !(del_col&j))
            recc(tb, size, depth-1, del_col|j, sol_num);
}

int main(int argc, const char * argv[]) {
    
    clock_t begin = clock();//Timer starts
    
    int N=20;
    
    int **table = new int*[N];
    for(int i = 0; i < N; i++)
        table[i] = new int[N];
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if( !((i+1)%(j+1)) || !((j+1)%(i+1)))
                table[i][j]=1;
            else
                table[i][j]=0;
    
    int sol_num=0;
    
    
    
    recc(table, N, N, 0, sol_num);
    
    clock_t end = clock();//Timer ends
    
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout<<"time: "<<elapsed_secs<<" res: "<<sol_num<<endl;
    
    
    for(int i = 0; i < N; i++) {
        delete [] table[i];
    }
    delete [] table;
    
    return 0;
}


