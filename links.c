#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "links.h"

typedef struct{
    int x1;
    int y1;
    int x2;
    int y2;
} link;

link links[100005];
int total=0;

int a1[8]={-2,-2,-1,-1,1,1,2,2};
int b1[8]={-1,1,-2,2,-2,2,-1,1};

int inside1(int x, int y){
    if(x>23 || y>23|| x<0 || y<0) return 0;
    return 1;
}

void add_link(int x1, int y1, int x2, int y2){
    if(total>=100005) return;
    links[total].x1=x1;
    links[total].y1=y1;
    links[total].x2=x2;
    links[total].y2=y2;
    total++;
}

int point_wrt_line(int x1,int y1, int x2, int y2, int x3, int y3){
    return (y2-y1)*(x3-x1)-(x2-x1)*(y3-y1);
}

int link_exists(int x1, int y1, int x2, int y2){
    for(int i=0;i<total;i++){
        if(links[i].x1==x1 && links[i].y1==y1 && links[i].x2==x2 && links[i].y2==y2 ||links[i].x1==x2 && links[i].y1==y2 && links[i].x2==x1 && links[i].y2==y1){
            return 1;
        }
    }
    return 0;
}

int intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    if((x1==x3 && y1==y3) || (x1==x4 && y1==y4)|| (x2==x3 && y2==y3) || (x2==x4 && y2==y4)){
        return 0; //end point same then share it not intersectign
    }
    int p1=point_wrt_line(x1,y1,x2,y2,x3,y3);
    int p2=point_wrt_line(x1,y1,x2,y2,x4,y4);
    int p3=point_wrt_line(x3,y3,x4,y4,x1,y1);
    int p4=point_wrt_line(x3,y3,x4,y4,x2,y2);
    int pos1=0,pos2=0;
    if(p1 > 0 && p2<0 || p1<0 && p2>0) pos1=1;
    if(p3 > 0 && p4<0 || p3<0 && p4>0) pos2=1;
    if(pos1==1 && pos2==1) return 1;
    return 0;
}

int cross_link_exist(int i,int j,int new_i,int new_j){
    for(int k=0;k<total;k++){
        if(intersect(i,j,new_i,new_j,links[k].x1,links[k].y1,links[k].x2,links[k].y2)==1) return 1;
    }
    return 0;
}

void create_link_after_placing(char arr[24][24], int i, int j){
    char now=arr[i][j];
    for(int k=0;k<8;k++){
        int new_i=i+a1[k];
        int new_j=j+b1[k];
        if(inside1(new_i,new_j)==0) continue;
        if(arr[new_i][new_j]!=now) continue;
        if(link_exists(i,j,new_i,new_j)==1) continue;
        if(cross_link_exist(i,j,new_i,new_j)==1) continue;
        add_link(i,j,new_i,new_j);
    }

}