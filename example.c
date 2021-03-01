/*#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>


int main (int argc , char const * argv [])
{
    char *name="khin";
    char* temp=malloc(34);
    strcpy(temp,name);
    print(temp);
    return 0;
}*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
struct message{ 
    char *hello;
    int X ;
 };
const char *stringA = "foo";
char *stringB = NULL;
int main (int argc , char const * argv [])
{

stringB = (char *) malloc( strlen(stringA) + 1 ); 
strcpy( stringB, stringA );
/* ... */
printf("%s",stringB);
free(stringB);

struct message m;
    m.hello="khin";
    char *name="khin";
    char* temp;
    temp = (char *) malloc( strlen(m.hello) + 1 );
    strcpy(temp,m.hello);
    printf("%s",temp);
    return 0;
}