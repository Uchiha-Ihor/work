#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr; 

    char sendBuff[1025];
    char readBuff[1025];

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    listen(listenfd, 10); 
    printf("-------------------------\n----------Wait----------\n-------------------------\n");

    while(1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 
        read(connfd, readBuff, strlen("Hello server\n")+1);
        printf("From client: %s", readBuff);
        printf("-------------------------\n\n");
        snprintf(sendBuff, sizeof(sendBuff), "Hello client \n");
        printf("To client: %s", sendBuff);
        printf("-------------------------\n\n");
        write(connfd, sendBuff, strlen(sendBuff)+1);
        write(connfd, readBuff, strlen(readBuff)+1);
        close(connfd);
        sleep(1);
     }
}