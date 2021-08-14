#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ロボットの向きを定義する
enum dir{
    ABOBE,BELOW,LEFT,RIGHT
};
//ロボットが上向きの時の動き
void robotAbobe(int* moveX,int* moveY,enum dir move){
    switch(move){
        case ABOBE:
            *moveY=0;
            *moveX=-1;
            //*direction=ABOBE;
            break;
        case BELOW:
            *moveY=0;
            *moveX=1;
            //*direction=BELOW;
            break;
        case LEFT:
            *moveY=-1;
            *moveX=0;
            //*direction=LEFT;
            break;
        case RIGHT:
            *moveY=1;
            *moveX=0;
            //*direction=RIGHT;
            break;
    }
}
//ロボットが下向きの時の動き
void robotBelow(int* moveX,int* moveY,enum dir move){
    switch(move){
        case ABOBE:
            *moveY=0;
            *moveX=1;
            //*direction=BELOW;
            break;
        case BELOW:
            *moveY=0;
            *moveX=-1;
            //*direction=ABOBE;
            break;
        case LEFT:
            *moveY=1;
            *moveX=0;
            //*direction=RIGHT;
            break;
        case RIGHT:
            *moveY=-1;
            *moveX=0;
            //*direction=LEFT;
            break;
    }
}
//ロボットが左向きの時の動き
void robotLeft(int* moveX,int* moveY,enum dir move){
    switch(move){
        case ABOBE:
            *moveY=-1;
            *moveX=0;
            //*direction=LEFT;
            break;
        case BELOW:
            *moveY=1;
            *moveX=0;
            //*direction=RIGHT;
            break;
        case LEFT:
            *moveY=0;
            *moveX=1;
            //*direction=BELOW;
            break;
        case RIGHT:
            *moveY=0;
            *moveX=-1;
            //*direction=ABOBE;
            break;
    }
}
//ロボットが右向きの時の動き
void robotRight(int* moveX,int* moveY,enum dir move){
    switch(move){
        case ABOBE:
            *moveY=1;
            *moveX=0;
            //*direction=RIGHT;
            break;
        case BELOW:
            *moveY=-1;
            *moveX=0;
            //*direction=LEFT;
            break;
        case LEFT:
            *moveY=0;
            *moveX=-1;
            //*direction=ABOBE;
            break;
        case RIGHT:
            *moveY=0;
            *moveX=1;
            //*direction=BELOW;
            break;
    }
}
//ロボットが移動する関数
int robotMove(int* moveX,int* moveY,enum dir* direction,enum dir move){
    //printf("direction:%u\n",*direction);
    switch(*direction){
        case ABOBE:
            robotAbobe(moveX,moveY,move);
            break;
        case BELOW:
            robotBelow(moveX,moveY,move);
            break;
        case LEFT:
            robotLeft(moveX,moveY,move);
            break;
        case RIGHT:
            robotRight(moveX,moveY,move);
            break;
    }
    //printf("moveX:%d moveY:%d\n",*moveX,*moveY);
    return 1;
}
//向きを決める関数
void robotStateAbobe(enum dir* direction){
    //printf("direction:%u\n",*direction);
    switch(*direction){
        case ABOBE:
            *direction = ABOBE;
            break;
        case BELOW:
            *direction = BELOW;
            break;
        case LEFT:
            *direction = LEFT;
            break;
        case RIGHT:
            *direction = RIGHT;
            break;
    }
}
void robotStateRight(enum dir* direction){
    //printf("direction:%u\n",*direction);
    switch(*direction){
        case ABOBE:
            *direction = RIGHT;
            break;
        case BELOW:
            *direction = LEFT;
            break;
        case LEFT:
            *direction = ABOBE;
            break;
        case RIGHT:
            *direction = BELOW;
            break;
    }
}
void robotStateLeft(enum dir* direction){
    //printf("direction:%u\n",*direction);
    switch(*direction){
        case ABOBE:
            *direction = LEFT;
            break;
        case BELOW:
            *direction = RIGHT;
            break;
        case LEFT:
            *direction = BELOW;
            break;
        case RIGHT:
            *direction = ABOBE;
            break;
    }
}
int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！
    // 入力値を受け取ってマス目状の迷路を作成する
    char str[1000], a[2]={'a','.'};
    int H, W;
    fgets(str, sizeof(str), stdin);
    sscanf(str,"%d %d\n",&H,&W);
    char field[H][W];
    for(int i = 0; i < H; i++){
        fgets(str, sizeof(str), stdin);
        for(int j = 0; j < (int)strlen(str) - 1; j++)
            field[i][j] = str[j];
    }
    field[0][0]=a[0];

    //ロボットを規則に従って移動させる
    int locateX = 0;
    int locateY = 0;
    enum dir direction = RIGHT;
    int moveX = 0;
    int moveY = 0;
    //printf("%d %d\n", locateY,locateX);
    while(1){
        /*for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++){
                printf("%c",field[i][j]);
                if(j==W-1)
                    printf("\n");
            }
        printf("\n");*/
        //１．まっすぐ進む
        if(robotMove(&moveX,&moveY,&direction,ABOBE) && (locateX+moveX) >= 0 && (locateX+moveX) < H  && (locateY+moveY) >= 0 && (locateY+moveY) < W  && field[locateX+moveX][locateY+moveY] == a[1]){
            locateX+=moveX;
            locateY+=moveY;
            robotStateAbobe(&direction);
            field[locateX][locateY]=a[0];
            //printf("in straight\n");
        }
        //２．右に曲がる
        else if(robotMove(&moveX,&moveY,&direction,RIGHT) && (locateX+moveX) >= 0 && (locateX+moveX) < H  && (locateY+moveY) >= 0 && (locateY+moveY) < W  && field[locateX+moveX][locateY+moveY] == a[1]){
            locateX+=moveX;
            locateY+=moveY;
            robotStateRight(&direction);
            field[locateX][locateY]=a[0];
            //printf("in right\n");
        }
        //３．左に曲がる
        else if(robotMove(&moveX,&moveY,&direction,LEFT) && (locateX+moveX) >= 0 && (locateX+moveX) < H  && (locateY+moveY) >= 0 && (locateY+moveY) < W  && field[locateX+moveX][locateY+moveY] == a[1]){
            locateX+=moveX;
            locateY+=moveY;
            robotStateLeft(&direction);
            field[locateX][locateY]=a[0];
            //printf("in left\n");
        }
        //４．静止する
        else
            break;
    }

    printf("%d %d\n", locateY,locateX);

    return 0;
}