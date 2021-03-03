 #include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>

int main (int argc , char const * argv [])
{
    
    int socket_c,i;
    struct sockaddr_in server;
    char* hello="hello 1";
    server.sin_family = AF_INET; 
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons (8000);
    socket_c = socket(AF_INET,SOCK_STREAM,0);
    if (socket_c < 0)
    {
        printf("Socket cannot be created \n");
        return  -1;
    }
    if (connect(socket_c ,(struct sockaddr *)&server,sizeof(server))<0)
    {
        printf("Fail to connect\n");
        return -1;
    }
   printf ("Successfully Connected\n");
   send(socket_c,hello,sizeof(hello),0);  //1st send
 
   close(socket_c);
   return 0;

}