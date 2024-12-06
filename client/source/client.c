#include "client.h"

void connect_server()
{
    int status, value_read, client_fd;
    struct sockaddr_in serv_address;
    char* message = "Hello from client";
    char buffer[1024];

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
	printf("socket failed to create\n");
	return;
    }
    serv_address.sin_family = AF_INET;
    serv_address.sin_port = htons(8080);
    inet_pton(AF_INET, "192.168.1.35", &serv_address.sin_addr);

    if ((status = connect(client_fd, (struct sockaddr*)&serv_address, sizeof(serv_address))) < 0)
    {
	printf("Connection failed\n");
	return;
    }
    send(client_fd, message, strlen(message), 0);
    prinf("Message sent\n");
    value_read = read(client_fd, buffer, 1024 - 1);

    printf("%s\n", buffer);

    close(client_fd);
}
