#include <stdio.h>

int dayElapsed(int day,int month){
	int sum1=0;
	int sum2=0;
	if(month>12){
		printf("errror");
	}

	for (int i=1;i<month;i++){
		if (i == (1 | 3 | 5 | 7 | 9 | 11)){
		sum1=sum1+31;
		}
		else {
		sum2=sum2+30;
		}
	}
	return sum1+sum2+day;
}

	int main()
	{
		int n,m;
		printf("enter the values fore day and month");
		scanf("%d %d",&n,&m);
		printf("%d",dayElapsed(n,m));
		return 0;
	}
