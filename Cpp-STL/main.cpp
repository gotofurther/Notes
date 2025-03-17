#include <stdio.h>

int logical(long long a){
	long long front_1 = a / 1000;
	long long front_2 = a / 100 % 10;
	long long after_1 = a / 10 % 10;
	long long after_2 = a / 1 % 10;
	if((front_2 > 1 && front_1 > 2) || (front_2 >= 2)){
		return 0;
	}
	if((after_2 > 1 && after_1 > 2) || (after_2 >= 2)){
		return 0;
	}
}

int out(long long a){
	long long front_1 = a / 1000;
	long long front_2 = a / 100 % 10;
	long long after_1 = a / 10 % 10;
	long long after_2 = a / 1 % 10;
	printf("%lld%lld%lld%lld%lld\n", a, after_2, after_1, front_2, front_1);
}

int logical_pro(long long a){
	long long front_1 = a / 1000;
	long long front_2 = a / 100 % 10;
	long long after_1 = a / 10 % 10;
	long long after_2 = a / 1 % 10;
	if((front_2 > 1 && front_1 > 2) || (front_2 >= 2)){
		return 0;
	}
	if((after_2 > 1 && after_1 > 2) || (after_2 >= 2)){
		return 0;
	}
	if(front_1 == after_1 && front_2 == after_2){
		return 1;
	}
	return 0;
}

int data_right(long long a){
	long long front_1 = a / 1000;
	long long front_2 = a / 100 % 10;
	long long after_1 = a / 10 % 10;
	long long after_2 = a / 1 % 10;
	if(after_2 == 0 && after_1 == 1 || after_2 == 0 && after_1 == 3 || after_2 == 0 && after_1 == 5 || after_2 == 0 && after_1 == 7 || after_2 == 0 && after_1 == 9 || after_2 == 1 && after_1 == 1){
		if(front_2 <= 3 || (front_2 == 3 && front_1 <= 1)){
			return 1;
		}
	}
	if(after_2 == 0 && after_1 == 4 || after_2 == 0 && after_1 == 6 || after_2 == 0 && after_1 == 8 || after_2 == 1 && after_1 == 0 || after_2 == 1 && after_1 == 2){
		if(front_2 <= 3 || (front_2 == 3 && front_1 <= 0)){
			return 1;
		}
	}
	if(after_2 == 0 && after_1 == 2){
		int year = front_1 * 1000 + front_2 * 100 + after_1 * 10 + after_2;
		if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
			if(front_2 <= 2 || (front_2 == 2 && front_1 <= 9)){
				return 1;
			}
		}else{
			if(front_2 <= 2 || (front_2 == 2 && front_1 <= 8)){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	long long a;
	scanf("%d", &a);
	long long year1 = a / 10000;
	while(year1++){
		if(logical(year1) && data_right(year1)){//1允许逆转,0不允许 
			break;
		}
	}
	out(year1);
	long long year2 = a / 10000;
	while(year2++){
		if(logical_pro(year2) && data_right(year2)){//1允许逆转,0不允许 
			break;
		}
	}
	out(year2);
}
