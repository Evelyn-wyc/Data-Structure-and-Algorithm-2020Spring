#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    char ext,v[100];
    scanf("%d",&n);
    ext=getchar();
    while(n--){
        int count[26]={0},max=0,i;
        char letter,letmax;
        while((letter=getchar())!='\n'){
            count[letter-'a']++;
        }
        for(i=0;i<26;i++){
            if(/* МоїХ */){
                max=count[i];
                letmax=/* МоїХ */;
            }
        }
        printf("%c %d\n",letmax,max);
        gets(v);
    }
    return 0;
}