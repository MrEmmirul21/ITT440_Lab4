#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>    // inet_addr
//This program shows how to create a socket

int main(int argc, char*argv[])
{
  int socket_desc;
  struct sockaddr_in server;

  // create socket
  socket_desc = socket(AF_INET,SOCK_STREAM,0);
  if (socket_desc == -1)
  {
    printf("Could not create a socket");
  }

  server.sin_addr.s_addr("192.168.170.13");  // ip address of ubuntu server
  server.sin_family = AF_INET;
  server.sin_port = htons(22);

  //connect to the remote server(ubuntu server)
  if ( connect(socket_desc,(struct sockaddr *)&server,sizeof(server)) <0 )
  {
    puts("Error connection");
    return 1;
  }

  puts("Connected");

  return 0;
}
