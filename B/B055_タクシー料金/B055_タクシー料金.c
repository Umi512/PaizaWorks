#include <stdio.h>
int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！
    char str[1000];
    int N,Dis;
    fgets(str, sizeof(str), stdin);
    sscanf(str,"%d %d\n",&N,&Dis);
    int initDis[N],initFear[N],addDis[N],addFear[N],sumDis[N],sumFear[N],lowFear,highFear;
    for(int i=0;i<N;i++){
        fgets(str, sizeof(str), stdin);
        sscanf(str,"%d %d %d %d\n",&initDis[i],&initFear[i],&addDis[i],&addFear[i]);
        sumDis[i]=initDis[i];
        sumFear[i]=initFear[i];
        //printf("%d\n",Dis);
        //printf("%d %d\n",sumDis[i],sumFear[i]);
        while(sumDis[i]<=Dis){
            sumDis[i]+=addDis[i];
            sumFear[i]+=addFear[i];
            //printf("%d %d\n",sumDis[i],sumFear[i]);
        }

        if(i>0){
            if(lowFear>sumFear[i])
                lowFear=sumFear[i];
            if(highFear<sumFear[i])
                highFear=sumFear[i];
        }
        else{
            lowFear=sumFear[i];
            highFear=sumFear[i];
        }
    }

    printf("%d %d",lowFear,highFear);
    return 0;
}