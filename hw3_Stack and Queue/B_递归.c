#include<stdio.h>
#include<stdlib.h>

double RPN(){
	char temp[20];
	scanf("%s",temp);
	switch(temp[0]){
		case'+': return /* ��� */
		case'-': return /* ��� */
		case'*': return /* ��� */
		case'/': return /* ��� */
		default: return atof(temp);break;
	}
}

int main(){
	printf("%lf\n",RPN());
	return 0;
}
