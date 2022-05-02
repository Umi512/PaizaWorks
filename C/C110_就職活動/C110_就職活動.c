#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int first, last, count;
}Recode;

void RecodeInit(Recode *r, int first, int last, int count){
    r->first = first;
    r->last = last;
    r->count = count;
}

int cmpnum(const void * n1, const void * n2)
{
	if (*(int *)n1 > *(int *)n2)
	{
		return 1;
	}
	else if (*(int *)n1 < *(int *)n2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！
    char str[1000];
    int N,x,y; //企業説明会回数，参加初日，参加終日
    fgets(str, sizeof(str), stdin);
    sscanf(str,"%d",&N);
    int d[N]; //企業説明会日程
    for(int i=0;i<N;i++){
        fgets(str, sizeof(str), stdin);
        sscanf(str,"%d",&d[i]);
    }
    qsort(d,N,sizeof(int),cmpnum);

    Recode re[N];
    for(int i=0;i<N;i++)
        RecodeInit(&re[i],-1, -1, 0);
    int c1 = 0, c2 = 1, c3 = 0;
    for(int i=0;i<(N-1);i++){
        c1 = d[i];
        if(c2==1)
            re[c3].first = d[i];
        if(c1==(d[i+1]-1)||c1==d[i+1])
            c2++;
        else{
            re[c3].last = d[i];
            re[c3].count = c2;
            c2 = 1;
            c3++;
        }
    }
    int max = 0, maxN = 0;
    for(int i=0;i<N;i++)
        if(max<re[i].count){
            max = re[i].count;
            maxN = i;
        }

    if(re[0].first != -1){
        x = re[maxN].first;
        y = re[maxN].last;
    }
    else{
        x = y = d[0];
    }

    printf("%d %d",x,y);
    return 0;
}