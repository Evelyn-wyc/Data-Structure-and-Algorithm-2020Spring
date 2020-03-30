#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,point[10]={0},total_point=0;
    float sum=0,score[10]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&point[i]);
    }
    for(/* МоїХ */){
        scanf("%f",&score[i]);
        if(score[i]>=90){
            /* МоїХ */;
        }
        else if(score[i]>=85){
            score[i]=3.7;
        }
        else if(score[i]>=82){
            score[i]=3.3;
        }
        else if(score[i]>=78){
            score[i]=3.0;
        }
        else if(score[i]>=75){
            score[i]=2.7;
        }
        else if(score[i]>=72){
            score[i]=2.3;
        }
        else if(/* МоїХ */){
            score[i]=2.0;
        }
        else if(score[i]>=64){
            score[i]=1.5;
        }
        else if(score[i]>=60){
            score[i]=1.0;
        }
        else{
            score[i]=0;
        }
    }
    for(i=0;i<n;i++){
        /* МоїХ */;
        total_point+=point[i];
    }
    printf("%.2f",sum/total_point);
    return 0;
}