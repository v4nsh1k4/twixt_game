#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "win.h"
#include "links.h"

// void check_win(char arr[24][24], int player){
//     // player =1 for red, 0 for black
//     int i,j;
//     if(player==1){
//     for(j=0;j<23;j++){
//         if(arr[0][j]=='r'){
//             int x=0,y=j;
//             while(x<24 && y<24){
                
//             }
//         }
//         }
//     }
// }

int a[8]={-2,-2,-1,-1,1,1,2,2};
int b[8]={-1,1,-2,2,-2,2,-1,1};

int inside(int x, int y){
    if(x>23 || y>23|| x<0 || y<0) return 0;
    return 1;
}

int recur_red(int i, int j, char arr[24][24], int done[24][24]){
    if(i==23) return 1;
    done[i][j]=1;
    for(int k=0;k<8;k++){
        int new_i=i+a[k];
        int new_j=j+b[k];
        int one=inside(new_i,new_j);
        // char two=arr[new_i][new_j];
        int three=done[new_i][new_j];
        if(one==1 && arr[new_i][new_j]=='r' && three==0 && link_exists(i, j, new_i, new_j)==1){
            if(recur_red(new_i,new_j,arr,done)) return 1;
        }
    }
    return 0;
}

int red_win(char arr[24][24]){
    int done[24][24];
    for(int i=0;i<24;i++){
        for(int j=0;j<24;j++){
            done[i][j]=0;
        }
    }
    for(int j=0;j<24;j++){
        if(arr[0][j]=='r'){
            if(recur_red(0,j,arr,done)) return 1;
        }
    }
    return 0;
}

int recur_black(int i, int j, char arr[24][24], int done[24][24]){
    if(j==23) return 1;
    done[i][j]=1;
    for(int k=0;k<8;k++){
        int new_i=i+a[k];
        int new_j=j+b[k];
        int one=inside(new_i,new_j);
        // char two=arr[new_i][new_j];
        int three=done[new_i][new_j];
        if(one==1 && arr[new_i][new_j]=='b' && three==0 && link_exists(i, j, new_i, new_j)==1){
            if(recur_black(new_i,new_j,arr,done)) return 1;
        }
    }
    return 0;
}

int black_win(char arr[24][24]){
    int done[24][24];
    for(int i=0;i<24;i++){
        for(int j=0;j<24;j++){
            done[i][j]=0;
        }
    }
    for(int j=0;j<24;j++){
        if(arr[j][0]=='b'){
            if(recur_black(j,0,arr,done)) return 1;
        }
    }
    return 0;
}