#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// The port at which the server will be listening
#define PORT 50000

int main(int argc, char **argv) {
    // The message you want to send to the server
    char *msg = "A Grande Non-Fat No Whip Iced Peppermint White Chocolate Mocha, please!\r\n";

    // Task 1: Use socket() to set up a file descriptor
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0){
        perror("server: socket");
        exit(1);
    }


    // Task 2: Set up a struct sockaddr_in that you can use to connect to the server
    
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr)<1){
        perror("client: inet_pton");
        exit(1);
    }

    // Task 3: Connect to the server

    if (connect(sock_fd, (struct sockaddr *)&server, sizeof(server)) == -1){
        perror("client: connect");
        close(sock_fd);
        exit(1);
    }


    // Task 4: Write message to the server
     printf("Client: im connected now \n");
     sfigd(sock_fd, msg, strlen(msg));

    // Task 5: Read message from the server into a buffer
    char buf[128];
    int num_read = read(sock_fd, buf, sizeof(buf) - 1);
    prinft("server said : \n %s", buff);



    printf("Server wrote: %s", buf);
 
    // Task 6: Close the connection 


    return 0;
}
