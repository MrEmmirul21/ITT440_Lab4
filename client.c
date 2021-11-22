#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>      //strlen
#include <sys/socket.h>  //socket()
#include <arpa/inet.h>   // inet_addr()

int main(int argc, char *argv[])
{
  int socket_desc;
  struct sockaddr_in server;
  char *message , server_reply[2000];

  // create socket
  socket_desc = socket(AF_INET,SOCK_STREAM,0);

  if (socket_desc == -1)
  {
    printf("Could not create socket");
  }

  server.sin_addr.s_addr = inet_addr("192.168.170.13");  // ip address of ubuntu server
  server.sin_family = AF_INET;
  server.sin_port = htons( 8888 );

  // connect to remote server(ubuntu server)
  if (connect(socket_desc,(struct sockaddr *)&server,sizeof(server)) < 0)
  {
    puts("Error connection");
    return 1;
  }

  puts("Connected\n");

  // send data to remote server
  message = "connect";
  if(send(socket_desc,message,strlen(message),0) < 0)
  {
    puts("Sending failed\n");
    return 1;
  }
  puts("Sending successfull\n");

  // receive data from remote server
  if(recv(socket_desc,server_reply,2000,0) < 0)
  {
    puts("Receiving failed\n");
  }
  puts("Receiving successfull\n");
  puts(server_reply);

  close(socket_desc);

  return 0;
}
