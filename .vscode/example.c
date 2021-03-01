#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
struct message{ 
    char *hello;
    int X ;
 };

int main (int argc , char const * argv [])
{
    struct message m;
    m.hello="khin";
    char *name="khin";
    char* temp;
    strcpy(temp,m.hello);
    printf("%s")
}
