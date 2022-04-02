#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>    /* Internet domain header */

#define PORT_NUM 50000
#define MAX_BACKLOG 5 // wait on max 5 clients

void serve_client(int fd);

int main() {

    // Create socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("server: socket");
        exit(1);
    }

    // Bind socket to an address
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT_NUM);  // Note use of htons here
    server.sin_addr.s_addr = INADDR_ANY; //listen on same system
    memset(&server.sin_zero, 0, 8);  // Initialize sin_zero to 0

    if (bind(sock_fd, (struct sockaddr *)&server, sizeof(struct sockaddr_in)) < 0) {
        perror("server: bind");
        close(sock_fd);
        exit(1);
    }

    // Create queue in kernel for new connection requests
    if (listen(sock_fd, MAX_BACKLOG) < 0) {
        perror("server: listen");
        close(sock_fd);
        exit(1);
    }

    // Accept a new connection
    int client_fd = accept(sock_fd, NULL, NULL);
    if (client_fd < 0) {
        perror("server: accept");
        close(sock_fd);
        exit(1);
    }

    printf("Got a new connection.\n");
    serve_client(client_fd);

    close(client_fd);
    close(sock_fd);

    return 0;
}

void serve_client(int fd) {
    char *msg = "Here you go. Have a good day!\r\n";
    char buf[128]; //to read what client wants
   
    int num_read = read(fd, buf, 127);
    buf[num_read] = '\0';
    printf("Server received the following order: %s", buf);
    write(fd, msg, strlen(msg));
}
