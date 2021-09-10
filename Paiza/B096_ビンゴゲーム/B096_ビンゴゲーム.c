#include <stdio.h>
int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！
    // 入力
    char str[1000];
    fgets(str, sizeof(str), stdin);
    int N;
    sscanf(str,"%d\n",&N);
    //printf("N:%d\n",N);
    int s[4][4];
    for(int i=0;i<4;i++){
        fgets(str,sizeof(str),stdin);
        sscanf(str,"%d %d %d %d\n",&s[i][0],&s[i][1],&s[i][2],&s[i][3]);
        //printf("s[%d]:%d %d %d %d\n",i,s[i][0],s[i][1],s[i][2],s[i][3]);
    }
    int p[N];
    for(int i=0;i<N;i++){
        fgets(str,sizeof(str),stdin);
        sscanf(str,"%d\n",&p[i]);
        //printf("p[%d]:%d\n",i,p[i]);
    }

    //すでに選ばれている数字を"-1"に置き換える
    int equalNum = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<(int)(sizeof(s)/sizeof(s[0]));j++){
            for(int k=0;k<(int)(sizeof(s[0])/sizeof(s[0][0]));k++){
                if(s[j][k]==p[i]){
                    s[j][k]=-1;
                    equalNum = 1;
                    break;
                }
            }
            if(equalNum==1){
                equalNum = 0;
                break;
            }
        }
    }

    //リーチチェック
    //縦を確認
    int height[2][4]={};
    //横を確認
    int row[2][4]={};
    //右下方向斜めを確認
    int rightDown[2][1]={};
    //左下方向斜めを確認
    int leftDown[2][1]={};
    int answer = -1;

    //縦を確認
    for(int i=0;i<(int)(sizeof(s[0])/sizeof(s[0][0]));i++){
        for(int j=0;j<(int)(sizeof(s)/sizeof(s[0]));j++){
            if(s[j][i]==-1)
                height[0][i]+=1;
            else
                height[1][i]=s[j][i];
        }
        if(height[0][i]==3){
            answer = height[1][i];
            break;
        }
    }

    //横を確認
    if(answer==-1)
        for(int i=0;i<(int)(sizeof(s)/sizeof(s[0]));i++){
            for(int j=0;j<(int)(sizeof(s[0])/sizeof(s[0][0]));j++){
                if(s[i][j]==-1)
                    row[0][i]+=1;
                else
                    row[1][i]=s[j][i];
            }
            if(row[0][i]==3){
                answer = row[1][i];
                break;
            }
        }

    //右下方向斜めを確認
    if(answer==-1)
        for(int i=0,j=0;i<(int)(sizeof(s[0])/sizeof(s[0][0]))&&j<(int)(sizeof(s)/sizeof(s[0]));i++,j++){
            if(s[i][j]==-1)
                rightDown[0][0]+=1;
            else
                rightDown[1][0]=s[j][i];
        }
        if(rightDown[0][0]==3)
                answer = rightDown[1][0];

//左下方向斜めを確認
    if(answer==-1)
        for(int i=0,j=(int)(sizeof(s)/sizeof(s[0]))-1;i<(int)(sizeof(s[0])/sizeof(s[0][0]))&&j>=0;i++,j--){
            if(s[i][j]==-1)
                leftDown[0][0]+=1;
            else
                leftDown[1][0]=s[i][j];
        }
        if(leftDown[0][0]==3)
                answer = leftDown[1][0];

    if(answer==-1)
        printf("no");
    else
        printf("%d",answer);

    return 0;
}