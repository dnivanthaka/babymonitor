#include <stdio.h>
#include <stdlib.h>

int main(void)
{
char *data;
int state, ret;

data = getenv("QUERY_STRING");

if(data == NULL){
	printf("Content-Type: text/plain\n\n");
	printf("Error no data");
	exit(2);
}else if(sscanf(data, "state=%d", &state) > 0){
	//printf("Got data %d", state);
	if(state == 1){
		printf("Location: ../index.html\n\n");
		ret = system("sudo service uv4l_raspicam restart");
		//printf("out = %d", ret);
	}else if(state == 2){
		//printf("Reboot command");
		//printf("Location: ../index.html\n\n");
		printf("Content-Type: text/html\n\n");
		printf("<meta http-equiv='refresh' content='20; url=../index.html' />");
		ret = system("sudo shutdown -r now");
		//printf("out = %d", ret);
	}else if(state == 3){
		ret = system("sudo shutdown -h now");
	}

}

return 0;
}
