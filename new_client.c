#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>    /* Internet domain header */
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

int main() {

    //unsigned char buf[sizeof(struct in6_addr)];

    // create socket
    int soc = socket(AF_INET, SOCK_STREAM, 0);
    if (soc == -1) {
        perror("client: socket");
        exit(1);
    }

    //initialize server address    
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(50000);
    // server.sin_port = htons(5000);
    memset(&server.sin_zero, 0, 8);

    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int connect_ret = connect(soc, (struct sockaddr *)&server, sizeof(struct sockaddr_in));

    printf("Connect returned %d\n", connect_ret);
    char buf[10];
    read(soc, buf, 7);
    buf[7] = '\0';
    printf(" CLIENT: I read %s\n", buf);

    write(soc, "0123456789", 10);

return 0;}