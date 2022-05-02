#include <stdio.h>

#define FIELD 100

enum beatles {rBeatle,gBeatle,bBeatle};

int direct(char d){
    int m;
    switch (d)
    {
    case 'L':
        m = -1;
        break;
    case 'R':
        m = 1;
        break;
    default:
        m = 0;
        break;
    }
    return m;
}

int moving(int x, char dotti, char light, enum beatles be){
    int move = 0;
    //どちらのライトが点灯したかで進む方向を定義
    move = direct(dotti);
    //カブトムシを動かす
    switch (be)
        {
        case rBeatle:
            if(light=='R'||light=='Y'||light=='M'||light=='W')
                x = x + move;
            break;
        case gBeatle:
            if(light=='G'||light=='Y'||light=='C'||light=='W')
                x = x + move;
            break;
        case bBeatle:
            if(light=='B'||light=='M'||light=='C'||light=='W')
                x = x + move;
            break;
        default:
            break;
        }
    ///フィールド外に出ていないかチェック
    if(x>FIELD)
        x=FIELD;
    else if(x<-FIELD)
        x=-FIELD;

    return x;
}

int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！
    char str[1000];
    int N=0, x_R, x_G, x_B;
    fgets(str, sizeof(str), stdin);
    sscanf(str,"%d\n",&N);
    fgets(str, sizeof(str), stdin);
    sscanf(str,"%d %d %d\n",&x_R, &x_G, &x_B);
    char t_n[N],c_n[N];
    for(int i=0; i<N; i++){
        fgets(str, sizeof(str), stdin);
        sscanf(str,"%s %s\n",&t_n[i], &c_n[i]);
    }

    for(int i=0;i<N;i++){
        //動かす
        x_R = moving(x_R,t_n[i],c_n[i],rBeatle);
        x_G = moving(x_G,t_n[i],c_n[i],gBeatle);
        x_B = moving(x_B,t_n[i],c_n[i],bBeatle);
        //それぞれのカブトムシが同じ位置にいるか確認する
        if((x_R==x_G)&&(x_G==x_B))
            break;
    }

    //結果出力
    if((x_R==x_G)&&(x_G==x_B))
        printf("%d\n",x_R);
    else
        printf("no\n");

    return 0;
}