#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fn.h"
#include "win.h"
#include "links.h"

void new_game(char arr[24][24]){
    for(int i=0;i<=24;i++){
        printf("%2d ", i);
    }
    printf("\n");
    for(int i=0;i<24;i++){
        printf("%2d ", i+1);
        for(int j=0;j<24;j++){
            if(i==0 && j==0){ arr[i][j]=' ';}
            else if(i==0 && j==23){ arr[i][j]=' ';}
            else if(i==23&&j==0){ arr[i][j]=' ';}
            else if(i==23&&j==23){ arr[i][j]=' ';}
            else {arr[i][j]='.';}
            printf(" %c ", arr[i][j]);
        }
        printf("\n");
    }
    printf("It is Red's turn.\n");
}

void play_game_red(char arr[24][24]){
    int x,y;
    int red; //red =1 for red playing and =0 for black playing
    printf("Press 0 0 to restart the game and 24 24 to resign.\n");
    scanf("%d%d",&x,&y);
    if(x==0 && y==0){
        new_game(arr);
    }
    else if(x==24 && y==24){
        printf("Red resigned. Black wins!\n");
        exit(1);
    }
    else if((x==1 && y==1) || (x==1 && y==24)|| (x==24 && y==1)){
        printf("Invalid space. Choose again.\n");
        play_game_red(arr);
        return;
    }
    else if(y==1 || y==24){
        printf("Invalid space. Choose again.\n");
        play_game_red(arr);
        return;
    }
    else if(x>24 || y>24 || x<1 || y<1){
        printf("Invalid space. Choose again.\n");
        play_game_red(arr);
        return;
    }
    else if(arr[x-1][y-1]=='b'){
        printf("Space already chosen by black! Choose again.\n");
        play_game_red(arr);
        return;
    }
    else {
        arr[x-1][y-1]='r';
        create_link_after_placing(arr,x-1,y-1);
    }
    for(int i=0;i<=24;i++){
        printf("%2d ", i);
    }
    printf("\n");
    for(int i=0;i<24;i++){
        printf("%2d ", i+1);
        for(int j=0;j<24;j++){
            printf(" %c ", arr[i][j]);
        }
        printf("\n");
    }
    if(red_win(arr)){ 
        printf("Red won.\n");
        exit(1);
    }
    printf("It is Black's turn.\n");
}

void play_game_black(char arr[24][24]){
    int x,y;
    printf("Press 0 0 to restart the game and 24 24 to resign.\n");
    scanf("%d%d",&x,&y);
    if(x==0 && y==0){
        new_game(arr);
    }
    else if(x==24 && y==24){
        printf("Black resigned. Red wins!\n");
        exit(1);
    }
    else if((x==1 && y==1) || (x==1 && y==24)|| (x==24 && y==1)){
        printf("Invalid space. Choose again.\n");
        play_game_black(arr);
        return;
    }
    else if(x==1 || x==24){
        printf("Invalid space. Choose again.\n");
        play_game_black(arr);
        return;
    }
    else if(x>24 || y>24|| x<1 || y<1){
        printf("Invalid space. Choose again.\n");
        play_game_black(arr);
        return;
    }
    else if(arr[x-1][y-1]=='r'){
        printf("Space already chosen by red! Choose again.\n");
        play_game_black(arr);
        return;
    }
    else {
        arr[x-1][y-1]='b';
        create_link_after_placing(arr,x-1,y-1);
    }
    for(int i=0;i<=24;i++){
        printf("%2d ", i);
    }
    printf("\n");
    for(int i=0;i<24;i++){
        printf("%2d ", i+1);
        for(int j=0;j<24;j++){
            printf(" %c ", arr[i][j]);
        }
        printf("\n");
    }
    if(black_win(arr)){ 
        printf("Black won.\n");
        exit(1);
    }
    printf("It is Red's turn.\n");
}