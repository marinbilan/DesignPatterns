#include <iostream>

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <unistd.h> 

#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h>
 
#include <arpa/inet.h> 

#include "StartUp.h"

#include "Initiation_Dispatcher.h"
#include "Event_Handler_If.h"
#include "Logging_Acceptor.h"


#include <errno.h> 
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros  
     
#define TRUE   1  
#define FALSE  0  

#define PORT 8080 
// GIT
// git remote add origin https://github.com/marinbilan/DesignPatterns.git
// git push -u origin master

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		std::cout << "Wrong number of input params. Exit! " << '\n';
		return 0;
	}
	
    // -------- SOCKET PROGRAMMING --------
    if(!strcmp(argv[1], "client"))
    { 
	    int sock = 0;		
	    struct sockaddr_in serv_addr;
	    char buffer[1024] = {0}; // Max received msg length 1024 bytes
		// TODO: Add this to enter before connection
		std::string ipAddress("127.0.0.1");
		int port = 8080;

	    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	    { 
		    printf("\n Socket creation error \n"); 
		    return -1; 
	    } 
	   
	    serv_addr.sin_family = AF_INET; 
	    serv_addr.sin_port = htons(port); 

	    // Convert IPv4 and IPv6 addresses from text to binary form 
	    if(inet_pton(AF_INET, ipAddress.c_str(), &serv_addr.sin_addr) <= 0)  
	    { 
		    printf("\n Invalid address/ Address not supported \n"); 
		    return -1; 
	    } 
	   
	    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	    { 
			printf("\n Connection failed \n"); 
			return -1; 
	    }

		// After connection, read server welcome message
		int numOfReceivedBytes = 0;
		numOfReceivedBytes = read(sock , buffer, 1024);
		if(numOfReceivedBytes <= 0)
		{
			std::cout << "Error: Nothing received from server!" << '\n';
		} else 
		{
		    std::cout << "From server: " << buffer << '\n' << "received #Bytes: " << numOfReceivedBytes << '\n';
		}

        // Command line terminal
		std::string commandLineString;
        do
	    {
	        std::cout << "$ ";
            // Waiting for command 
            std::getline(std::cin, commandLineString);

			// Send message from terminal to server
	        send(sock, commandLineString.c_str(), strlen(commandLineString.c_str()), 0);

            // Read (as from file) from sock what server send to clinet
			if( commandLineString.size() != 0) // If ENTER is not pressed
			{
	            numOfReceivedBytes = read( sock , buffer, 1024);
				std::cout << "From server: " << buffer << '\n' << "#Bytes: " << numOfReceivedBytes << '\n';
			}			
        } while (commandLineString != "exit");
    }
    else if (!strcmp(argv[1], "server")) 
    {
        Reactor::Event_Handler_If* loggingAcceptor = new Reactor::Logging_Acceptor(0);
        std::string event("ACCEPT_EVENT");
        loggingAcceptor->handle_event(event);

        Reactor::Initiation_Dispatcher::getInstance().init();
        Reactor::Initiation_Dispatcher::getInstance().handle_events();
    }
    else
    {
         std::cout << "Wrong input param!" <<  '\n';
    }

    return 0;
}