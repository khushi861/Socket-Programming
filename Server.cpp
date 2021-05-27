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

int main(int argc, char*argv[])
{
if(argc!=2)
{
cerr<<"Missing port no.\n";
}
int port= atoi(argv[1]);
char message[1500];

sockaddr_in serverSocket;
serverSocket.sin_family = AF_NET;
serverSocket.sin_port = htons(port);
serverSocket.sin_addr.s_addr = htons(INADDR_ANY);

int serverSocketID = socket(AF_IFNET, SOCK_STREAM,0);
if(serverSocketID<0)
{
    cerr<<"Not successful\n";
    exit(0);
}

int bindStatus = bind(serverSocketID, (struct sockaddr *)&serverSocket, sizeof(serverSocket));
if(bindStatus<0)
{
    cerr<<"Not Successfuly bind\n";
    exit(0);
}

cot<<"Waiting for client to connect\n";

listen(serverSocketID, 1);

sockaddr_in newSocket;
socklen_t newSocketLen = sizeof(newSocket);

int newSocketID = accept(serverSocketID, (sockaddr *)&newSocket, &newSocketLen);

int(newSocketID<0)
{
    cerr<<"Not successfully accepted()\n";
    exit(0);
}
cout<<"Not connected successfully \n";

while(1)
{
    cout<<"Waiting for message from client\n";
    rec(newSocketID, (char *)&message, sizeof(message),0);
    if(!strcmp(message,"exit"))
    {
        cout<<"Session Terminated\n";
        break;
    }

    cout<<message<<endl;
    string data;
    cin>>data;

    strcpy(message,data.c_str());

    if(data =="exit")
    {
        cout<<"Session terminated\n";
        break;
    }
    send(newSocketID, (char *)&message, sizeof(message),0);
}
 close(newSocketID);
 close(serverSocketID);
}
