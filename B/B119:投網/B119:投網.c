#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！

    // 入力値の取得
    int H = 0, W = 0;
    int R = 0, C = 0;
    char str[1000];
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d %d\n", &H, &W);
    //printf("H, W : %d, %d\n", H, W);

    char s[H][W];
    char n[R][1000];

    for(int i = 0; i < H; i++){

        fgets(str, sizeof(str), stdin);
        for(int j = 0; j < W; j++){

            s[i][j] = str[j*2] ; // 以降のfget後に，s[0][0]でおかしな値が入るため
            //printf("s[%d][%d] : %d \n", i, j, s[i][j]);

        }

    }

    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d %d\n", &R, &C);

    for(int i = 0; i < R; i++){

        fgets(str, sizeof(str), stdin);
        //printf("s[0][0] : %d\n", s[0][0]);
        sscanf(str, "%s\n", n[i]);
        //printf("n[%d] : %s\n", i, n[0]);

    }



    // 全パターンチェック
    int searchH = H - R + 1;
    int searchW = W - C + 1;
    int getfishArray[searchH][searchW];
    int getfishMax = 0;

    for (int i = 0; i < searchH; i++){
        for (int j = 0; j < searchW; j++){

            getfishArray[i][j] = 0;
            for (int k = 0; k < R; k++)
                for (int l = 0; l < C; l++){

                    //printf("n[k][l] : %c\n", n[k][l]);
                    if(n[k][l] == '#'){

                        //printf("s[%d+%d][%d+%d] : %d\n", i, k, j, l, s[i+k][j+l]);
                        getfishArray[i][j] += (int)s[i+k][j+l] - '0';

                    }

                }

            if(getfishMax < getfishArray[i][j]){

                getfishMax = getfishArray[i][j];

            }

        }
    }

    //答え
    //printf("getfishMax : %d\n", getfishMax);
    printf("%d\n", getfishMax);

    return 0;
}