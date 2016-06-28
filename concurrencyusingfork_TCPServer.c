/****************** SERVER CODE ****************/
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
int main(){
int neerajaserverSocket, newSocket;
char buffer[16384];
struct sockaddr_in serverAddr;
struct sockaddr_storage serverStorage;
socklen_t addr_size;
/*---- Create the socket. The three arguments are: ----*/
/* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
neerajaserverSocket = socket(PF_INET, SOCK_STREAM, 0);
/*---- Configure settings of the server address struct ----*/
/* Address family = Internet */
serverAddr.sin_family = AF_INET;
/* Set port number, using htons function to use proper byte order */
serverAddr.sin_port = htons(7891);
/* Set IP address to localhost */
serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
/* Set all bits of the padding field to 0 */
memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
/*---- Bind the address struct to the socket ----*/
bind(neerajaserverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
/*---- Listen on the socket, with 5 max connection requests queued ----*/
if(listen(neerajaserverSocket,5)==0)
printf("Listening\n");
else
printf("Error\n");/*---- Accept call creates a new socket for the incoming connection ----*/
addr_size = sizeof serverStorage;
newSocket = accept(neerajaserverSocket, (struct sockaddr *) &serverStorage, &addr_size);
/*---- Send message to the socket of the incoming connection ----*/
strcpy(buffer,"This is Neeraja's server\n");
send(newSocket,buffer,16384,0);
}
return 0;
