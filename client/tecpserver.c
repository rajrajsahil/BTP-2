#include <stdio.h>

#include <stdlib.h>

#include<sys/socket.h>

#include<sys/types.h>
#include<unistd.h>
#include<arpa/inet.h>

#include<netinet/in.h>

int main()
{

char server_message[256]="you have reached the server";

//create the server socket
int server_soc=socket(AF_INET,SOCK_STREAM,0);

//define the server address

struct sockaddr_in server_address;
server_address.sin_family=AF_INET;
server_address.sin_port=htons(8234);
server_address.sin_addr.s_addr=INADDR_ANY;

//bind the socket to our specified IP an port
bind(server_soc,(struct sockaddr*) &server_address,sizeof(server_address));

listen(server_soc,3);
int client_soc=accept(server_soc,NULL,NULL);
send(client_soc,server_message,sizeof(server_message),0);

//close the socket

close(server_soc);

return 0;
}
