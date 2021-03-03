 #include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<pthread.h>
char message[1000];
void * sThread (void * arg){
  int newSocket = *((int *)arg);
  recv(newSocket , message , 1000, 0);
  printf("\n%s",message);
  close(newSocket);
  pthread_exit(NULL);

}

int main (int argc , char const * argv [])
{
    int socket_s=0 , new_socket;
    struct sockaddr_in client;
    int c = sizeof(client);
    int i,rc;
    pthread_t threadID[4];
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
    if (listen(socket_s,1)<0)
    {
        printf(" Cannot Listen \n");
        return -1; 
    }
    
  /* i=0;
     while (i<4)
    {
        printf("%d",i);
        new_socket = accept(socket_s, (struct sockaddr *)&client ,(socklen_t*)&c);
         /*rc=( pthread_create(&threadID[i], NULL, sThread, &new_socket) != 0 );
         
         if (rc)
         {
            printf("Failed to create thread\n");
            return -1;
         }
       
        i++;
         
    }*/
    i=0;
     while(i<4)
    {
        //Accept call creates a new socket for the incoming connection
        new_socket = accept(socket_s, (struct sockaddr *)&client ,(socklen_t*)&c);
        
        //for each client request creates a thread and assign the client request to it to process
       //so the main thread can entertain next request
        if( pthread_create(&threadID[i], NULL, sThread, &new_socket) != 0 )
           printf("Failed to create thread\n");
        pthread_join(threadID[i],NULL);
       i++;
    }
   // pthread_exit(NULL);
    return 0;

}
