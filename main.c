#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fn.h"

int main() {
    char arr[24][24];
    printf("Enter begin to start new game\n");
    char str[6];
    scanf("%s", str);
    if(strcmp(str,"begin")==0){
        new_game(arr); // fn to start new board
        while(1){
             play_game_red(arr);
             play_game_black(arr);
        }
    }
    else {
        printf("Error!\n");
        main();
    }
    
    return 0;
}