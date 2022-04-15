#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>    /* Internet domain header */

#define PORTNUM 54321
#define BACKLOG 5

int main(int argc, char** argv){

//Setup socket
int soc = socket(AF_INET, SOCK_STREAM, 0);

//sockaddr struct for server information
struct sockaddr_in addr;
addr.sin_family = AF_INET;
addr.sin_port = htons(PORTNUM);
addr.sin_addr.s_addr = INADDR_ANY;
memset(&addr.sin_zero, 0, 8);


//Bind socket
bind(soc, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));

//listen
listen(soc, BACKLOG);

//Accept
//struct for client side information

struct sockaddr_in client_addr;
client_addr.sin_family = AF_INET;
unsigned int client_len = sizeof(struct sockaddr_in);

int client_fd = accept(soc, (struct sockaddr *)&client_addr, &client_len);

write(client_fd, "hello\r\n", 7);

char line[10];
read(client_fd, line, 10);
/* before we can use line in a printf statement, ensure it is a string */
line[9] = '\0';
printf("SERVER: I read %s\n", line);

return 0;
}