#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc,char *message)
{
   char *hostname = "www.google.com";
   char ip[100];
   struct hostent *he;
   struct in_addr **addr_list;
   int i;

   if ( (he = gethostbyname(hostname)) == NULL )
   {
      // gethostbyname failed
      herror("gethostbyname");
      return 1;
   }

   /* cast the h_addr_list to in_addr, since h_addr_list also
      has the IP address in long format only */
   addr_list = (struct in_addr **)he->h_addr_list;
   for(i=0;addr_list[i] != NULL; i++)
   {
      // return the first one
      strcpy(ip,inet_ntoa(*addr_list[i]));
   }

   printf("%s resolve to : %s\n",hostname,ip);

   return 0;
}
