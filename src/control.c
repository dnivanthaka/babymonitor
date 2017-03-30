#include <stdio.h>
#include <stdlib.h>

int main(void)
{
char *data;
int state, ret;

data = getenv("QUERY_STRING");

if(data == NULL){ 
	printf("Content-Type: text/plain\n\n"); 
	printf("Error nodata"); 
	exit(2);
}else if(sscanf(data, "state=%d", &state) > 0){
	if(state == 1){
		//printf("Location: ../index.html\n\n");
		ret = system("sudo service uv4l_raspicam restart");
		//printf("out = %d", ret);
	}else if(state == 2){
		//"Reboot command"
		ret = system("sudo shutdown -r now");
		//printf("out = %d", ret);
	}else if(state == 3){
		ret = system("sudo shutdown -h now");
	}

}

return 0;
}
