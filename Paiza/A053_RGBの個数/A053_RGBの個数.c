#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHECK 'c'

void checkMasu(char color, int i, int j, int H, int W, char *field){
    // 対象右マスをチェックする
    if((j + 1) < W && field[i * W + (j + 1)] == color){
        field[i * W + (j + 1)] = CHECK;
        checkMasu(color, i, j + 1, H, W, field);
    }
    // 対象下マスをチェックする
    if((i + 1) < H && field[(i + 1) * W + j] == color){
        field[(i + 1) * W + j] = CHECK;
        checkMasu(color, i + 1, j, H, W, field);
    }
    // 対象左マスをチェックする
    if((j - 1) >= 0 && field[i * W + (j - 1)] == color){
        field[i * W + (j - 1)] = CHECK;
        checkMasu(color, i, j - 1, H, W, field);
    }
    // 対象上マスをチェックする
    if((i - 1) >= 0 && field[(i - 1) * W + j] == color){
        field[(i - 1) * W + j] = CHECK;
        checkMasu(color, i - 1, j, H, W, field);
    }
}

void countDraw(int *r, int *g, int *b, int H, int W, char *field){
    for( int i = 0; i < H; i ++ ){
        for( int j = 0; j < W; j ++ ){
            if(field[i * W + j] != CHECK){
                // マスの色が赤の場合
                if(field[i * W + j] == 'R'){
                    // カウント
                    (*r) ++;
                    // 対象マスをチェックする
                    field[i * W + j] = CHECK;
                    checkMasu('R', i, j, H, W, field);
                }
                // マスの色が緑の場合
                else if(field[i * W + j] == 'G'){
                    // カウント
                    (*g) ++;
                    // 対象マスをチェックする
                    field[i * W + j] = CHECK;
                    checkMasu('G', i, j, H, W, field);
                }
                // マスの色が青の場合
                else if(field[i * W + j] == 'B'){
                    // カウント
                    (*b) ++;
                    // 対象マスをチェックする
                    field[i * W + j] = CHECK;
                    checkMasu('B', i, j, H, W, field);
                }
            }
        }
    }
}

int main(void){
    //入力
    char str[2000];
    fgets(str, sizeof(str), stdin);
    int H = 0, W = 0; // 縦横サイズ
    sscanf(str, "%d %d\n", &H, &W);
    char *field; // マス目
    field = (char *)malloc(sizeof(char) * H * W + 1);
    for( int i = 0; i < H; i ++ ){
        fgets(str, sizeof(str), stdin);
        sscanf(str, "%s\n", str);
        for( int j = 0; j < W; j ++ ){
            field[i * W + j] = str[j];
        }
    }

    //塗る回数をカウントする
    int *r, *g, *b;
    r = (int *)malloc(sizeof(int));
    g = (int *)malloc(sizeof(int));
    b = (int *)malloc(sizeof(int));
    *r = 0; *g = 0; *b = 0;
    countDraw(r, g, b, H, W, field);

    printf("%d %d %d\n", *r, *g, *b);

    free(field);
    free(r);
    free(g);
    free(b);

    return 0;
}