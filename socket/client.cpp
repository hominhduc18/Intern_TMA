#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include<iostream>
#include<thread>
#define MAX 1000
using namespace std;


 void thread_send(int socket){
    while(1){
        char hello[MAX];
        fgets(hello,MAX,stdin);
        send(socket, hello, strlen(hello), 0);
    }
 }

 void thread_rcv(int socket){
    while(1){
        
        char buffer[MAX] {};
        int on = recv(socket, buffer, MAX, 0);
        if(!on){
            exit(EXIT_FAILURE);
        }
        printf("server send client: ");
	    printf("%s", buffer);
    }
 }

int main()
{
    int network_socket;
 
    // Create a stream socket
    network_socket = socket(AF_INET,
                            SOCK_STREAM, 0);
 
    // Initialise port number and address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8000);
 
    // socket connection
    int connection_status = connect(network_socket,
                                    (struct sockaddr*)&server_address,
                                    sizeof(server_address));
 
    // Check for connection error
    if (connection_status < 0) {
        puts("Error\n");
        return 0;
    }
    printf("Name: ");
    char username[32];
    fgets(username, 32, stdin);
    username[strlen(username)-1] = '\0';
    send(network_socket, &username,sizeof(username), 0);
    printf("Connect successful\n");

    std::thread thread1(&thread_send, network_socket);
    std::thread thread2(&thread_rcv, network_socket);

     // Send data to the socket
    thread1.join();
    thread2.join();


    // Close the connection
    close(network_socket);
}