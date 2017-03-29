#include <stdio.h>
#include <stdlib.h>

int main(void)
{
char *data;
int state, ret;
char buff[50];

data = getenv("QUERY_STRING");

if(data == NULL){
	printf("Content-Type: text/plain\n\n");
	printf("Error no data");
	exit(2);
}else if(sscanf(data, "op=%d", &state) > 0){
	
	if(state == 1){
		FILE *fp;
		fp = popen("ifconfig wlan0 | grep -o 'inet addr:[0-9]*.[0-9]*.[0-9]*.[0-9]'", "r");
		fgets(buff, 50, fp);
		pclose(fp);
		printf("%s", buff);
	}else if(state == 2){
	}else if(state == 3){
	}

}

return 0;
}
