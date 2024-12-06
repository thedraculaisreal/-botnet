#include "server.h"

void run_server()
{
    struct sockaddr_in serv_address;
    socklen_t addr_len = sizeof(serv_address);
    int new_socket;
    int server_fd;
    int opt = 1;


    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
	printf("socket creation failed");
	return;
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
	printf("setsockopt failed");
	return;
    }

    serv_address.sin_family = AF_INET;
    serv_address.sin_addr.s_addr = INADDR_ANY;
    serv_address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr*)&serv_address, sizeof(serv_address)) < 0)
    {
	printf("failed to bind to port 8080\n");
	return;
    }
    if (listen(server_fd, 3) < 0)
    {
	printf("listener failed to initialize\n");
	return;
    }
    if ((new_socket = accept(server_fd, (struct sockaddr*)&serv_address, &addr_len) < 0))
    {
	printf("Failed to accept incoming connection");
	return;
    }
    char buffer[1024] = { 0 };
    char* message = "Test message";
    ssize_t value_read;
    value_read = read(new_socket, buffer, 1024 - 1); // we minus 1 because of the nullterminator at the end.
    printf("%s\n", buffer);
    send(new_socket, message, strlen(message), 0);
    printf("Message sent\n");

    close(new_socket); // close client socket
    close(server_fd); // close server socket

    return;
}
