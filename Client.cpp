#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unisted.h>
#include<netdb.h>
#include<sys/time.h>
#include<sys/wait.h>
#include<bits/stdc.h>
using namespace.std;

int main(int argc, char *argv[])
{
    if(argc !=3)
       {
        cout<<"Missing Host name and port no."<<endl;
        exit(0);
       }
char *serverName = argv[1];
int port = atoi(argv[2]);

char message[1500];

struct hostent* host = gethostbyname(serverName);

sockaddr_in clientSocket;
clientSocket.sin_family = AF_INET;
clientSocket.sin_port = htons(port);

clientSocket.sin_addr = **(struct in_addr **)host->h_addr_list;


int clientSocketID = socket(AF_INET, SOCK_STREAM,0);

int status = connect(clientSocketID ,(sockaddr *)&clientSocket, sizeof(clientSocket));
if(status<0)
{
    cout<<"Error in connecting";
    exit(0);
}
cout<<"successfully connected..."<<endl;

while(1)
{

    string data;
    cout<<"Client: ";
    cin>>data;
    strcpy(message, data.c_str());
    if(sata=="exit")
    {
        cout<<"Connection Terminated";
        break;
    }
}
send(clientSocketID, message, sizeof(message),0);
cout<<"Server: ";
recv(clientSocketID,message,sizeof(message),0);

if(!strcmp(message,"exit))
{
    cout<<"connection terminated";
    break;
}
cout<<message<<endl;

close(clientSocketID);
}
