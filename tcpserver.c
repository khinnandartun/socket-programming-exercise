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
    char *hello;
    int X ;
 };


int main (int argc , char const * argv [])
{
    int socket_s=0 , new_socket;
    unsigned int j;
    struct sockaddr_in client;
    struct message  recv_message;
    recv_message.hello="Hello";
    recv_message.X=0;
    int c = sizeof(client);
    int i,flag;
    //char *temp;
    client.sin_port = htons (8000);
    client.sin_family=AF_INET;
    client.sin_addr.s_addr=INADDR_ANY;
    socket_s = socket(AF_INET,SOCK_STREAM,0);
    if (socket_s == 0)
    {
        printf (" Socket cannot be created \n");
        return -1;
    }
    if (bind(socket_s,(struct sockaddr *)&client,sizeof(client))<0)
    {
        printf(" Cannot bind \n");
        return -1;
    }
    if (listen(socket_s,3)<0)
    {
        printf(" Cannot Listen \n");
        return -1; 
    }
    new_socket = accept(socket_s, (struct sockaddr *)&client ,(socklen_t*)&c);
    if (new_socket <0)
    {
        printf ("Cannot Accept \n");
        return -1;
    }
    printf("Connection Accepted\n");
   /* recv (new_socket,recv_buffer,sizeof(recv_buffer),0);
    //i=read(new_socket,recv_buffer,1024);
    printf("%s",recv_buffer ); 
    send_buffer="Hello Y";
    send (new_socket,send_buffer,sizeof(send_buffer),0);
     recv (new_socket,recv_buffer,sizeof(recv_buffer),0);
    printf("\n%s",recv_buffer );*/
    if ((flag=recv(new_socket, (struct message *)&recv_message, sizeof(recv_message), 0)) == -1)  //1st receive
    { 
        printf("Error");
        exit(1);
    }
    else
    /*char *temp = (char *) malloc( strlen(recv_message.hello) + 1 );
    strcpy(temp,recv_message.hello);
    puts(temp);
    free(recv_message.hello);*/
    //recv_message.hello="Hello";
    printf("Hello");
   // printf("%s",recv_message.hello);
    printf("%d",recv_message.X);
    recv_message.X=recv_message.X+1; 
    i=recv_message.X;
    send(new_socket,&recv_message,sizeof(recv_message),0);//2nd send
    recv(new_socket,&recv_message,sizeof(recv_message),0); //3rd receive
    if (recv_message.X!= i+1)
   {
       printf("\n ERROR");
       close(new_socket);
   }
   else
   {
       printf("\nHello");
       printf("%d",recv_message.X);
   }
    close (new_socket);
    return 0;

}
