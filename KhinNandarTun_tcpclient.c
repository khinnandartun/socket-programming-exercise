 #include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
struct message{
    char *hello ;
    int X ;
 };

int main (int argc , char const * argv [])
{
    
    int socket_c,i;
    struct sockaddr_in server;
    struct message send_message;
    char  *hello="Hello X";
    char recv_buff [1024];
    char *send_buff;
    char ip[20];
    server.sin_family = AF_INET; 
    //server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons (8000);
    send_message.hello="Hello";
    send_message.X=1;
    socket_c = socket(AF_INET,SOCK_STREAM,0);
    printf("Enter Server IP:");
    scanf("%s",ip);
   server.sin_addr.s_addr = inet_addr(ip);
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
  // printf("sent\n");
   /*send(socket_c,(void *)hello, sizeof(hello),0);
   recv(socket_c,recv_buff,sizeof(recv_buff),0);
   printf("\n%s",recv_buff);
   send_buff="Hello Z";
   send(socket_c,send_buff,sizeof(send_buff),0);*/
   printf("Enter Initial sequential number:");
   scanf("%d",&i);
   send_message.X=i;
   send(socket_c,&send_message,sizeof(send_message),0);  //1st send
   recv(socket_c,&send_message,sizeof(send_message),0);  //2nd receive
   if (send_message.X!= i+1)
   {
       printf("ERROR");
       close(socket_c);
   }
   else
   {
       printf("%s",send_message.hello);
       printf("%d",send_message.X);
   }
   send_message.X=send_message.X+1;
    send(socket_c,&send_message,sizeof(send_message),0); //3rd send
   close(socket_c);
   return 0;

}