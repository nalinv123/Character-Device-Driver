#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define BUFFER_LENGTH 256
static char receive[BUFFER_LENGTH];

int main()
{
	int ret,fd;
	char stringToSend[BUFFER_LENGTH];
	
	printf("Starting device test code example...\n");
	fd = open("/dev/Marvellous Driver 1", O_RDWR);
	
	if(fd < 0)
	{
		perror("Failed to open device..");
		return errno;
	}
	printf("Type short string to send to the kernel module : ");
	scanf("%s[^\n]", stringToSend);
	
	printf("Writing message to the device [%s]. \n",stringToSend);
	ret = write(fd, stringToSend, strlen(stringToSend));
	
	if(ret < 0)
	{
		perror("Failed to write the message to the device \n");
		return errno;
	}
	
	printf("Press ENTER to read back from the device...\n");
	getchar();
	
	printf("Reading from the device...\n");
	
	ret == read(fd, receive, BUFFER_LENGTH);
	
	if(ret < 0)
	{
		perror("Failed to read the message from the device. \n");
		return errno;
	}
	
	printf("The recieved message : [%s] \n",receive);
	printf("End of the program\n");

	return 0;
}
