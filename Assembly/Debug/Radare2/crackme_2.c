#include <stdio.h>

int main(){
	int int_pass;
	printf("Enter code: ");
	scanf("%i", &int_pass);

	if(int_pass == 1234){
		printf("Access granted =)\n");
		return 0;
	} else  {
		printf("Access denied...\n");
		return -1;
	}
}

