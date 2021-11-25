#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc,char *argv[])
{
   int socket_desc;
   struct sockaddr_in server;
   char *message , server_reply[2000];

   // create socket
   socket_desc = socket(AF_INET,SOCK_STREAM,0);

   if(socket_desc == -1)
   {
      printf("Could not create socket");
   }

   // prepare the sockaddr_in structure
   server.sin_addr.s_addr = inet_addr("192.168.170.13");
   server.sin_family = AF_INET;
   server.sin_port = htons(8888);

   // connect to remote server
   if(connect(socket_desc,(struct sockaddr*)&server,sizeof(server)) < 0)
   {
      puts("Error connestion");
      return 1;
   }

   puts("Connected :)\n");

   // send data to remote server
   message = "connect";
   if(send(socket_desc,message,strlen(message),0) < 0)
   {
      puts("Sending failed");
      return 1;
   }

   puts("Sending successfull\n");

   // receive a reply from server
   if(recv(socket_desc,server_reply,2000,0) < 0)
   {
      puts("Receiving failed");
   }

   puts("Receive successfull");
   puts(server_reply);

   // close socket
   close(socket_desc);

   return 0;
}

