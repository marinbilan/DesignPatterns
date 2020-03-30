#pragma once
#include <string.h>
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <vector>

#include <unistd.h> 

#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h>
 
#include <arpa/inet.h> 

#include <errno.h> 
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros  

#define TRUE   1  
#define FALSE  0  

#define PORT 8080

/*
Event Types as string
---------------------
    ACCEPT_EVENT
    READ_EVENT
    WRITE_EVENT
    TIMEOUT_EVENT
    SIGNAL_EVENT
    CLOSE_EVENT
*/

// TODO: Remove this
class EventHandler
{
public:
    EventHandler(int clientId) : m_clientId(clientId)
    {
        std::cout << "EventHandler created. clientId: " << m_clientId << '\n';
    }

    ~EventHandler()
    {
        std::cout << "EventHandler removed. clientId: " << m_clientId << '\n';
    }

    int getClientId() const
    {
        return m_clientId;
    }
    
private:
int m_clientId;
};


namespace Reactor
{
class Initiation_Dispatcher
{
public:
	static Initiation_Dispatcher& getInstance()
	{
		static Initiation_Dispatcher instance;
		return instance;
	}

	~Initiation_Dispatcher() {};

	Initiation_Dispatcher(Initiation_Dispatcher const&) = delete;
	void operator=(Initiation_Dispatcher const&) = delete;

    // Init everything related to server
    void init()
    {
        std::cout << "[Initiation_Dispatcher] init everything" << std::endl;
    
        //initialise all client_socket[] to 0 so not checked  
        for (int i = 0; i < max_clients; i++)   
        {   
            client_socket[i] = 0;   
        }   
            
        //create a master socket  
        if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0)   
        {   
            perror("socket failed");   
            exit(EXIT_FAILURE);   
        }   
        
        //set master socket to allow multiple connections ,  
        //this is just a good habit, it will work without this  
        if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 )   
        {   
            perror("setsockopt");   
            exit(EXIT_FAILURE);   
        }   
        
        //type of socket created  
        address.sin_family = AF_INET;   
        address.sin_addr.s_addr = INADDR_ANY;   
        address.sin_port = htons(PORT);   

        //bind the socket to localhost port 8080  
        if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0)   
        {   
            perror("bind failed");   
            exit(EXIT_FAILURE);   
        }   
        printf("Listener on port %d \n", PORT);   
            
        //try to specify maximum of 3 pending connections for the master socket  
        if (listen(master_socket, 3) < 0)   
        {   
            perror("listen");   
            exit(EXIT_FAILURE);   
        }   
            
        //accept the incoming connection  
        addrlen = sizeof(address); 
    }


    // Entry point into the reactive event loop
    int handle_events()
    {         
    puts("Waiting for connections ...");
         
    while(TRUE)   
    {   
        // [1] clear the socket set  
        FD_ZERO(&readfds);   
     
        // [2] add master socket to set  
        FD_SET(master_socket, &readfds);   
        max_sd = master_socket;   
             
        // [3] add child sockets to set  
        for (int i = 0; i < max_clients; i++)   
        {   
            // [3.1] socket descriptor  
            sd = client_socket[i];   
                 
            // if valid socket descriptor then add to read list  
            if(sd > 0)   
                FD_SET( sd , &readfds);   
                 
            // highest file descriptor number, need it for the select function  
            if(sd > max_sd)   
                max_sd = sd;   
        }   
     
        // [4] wait for an activity on one of the sockets, timeout is NULL, so wait indefinitely
        std::cout << "Waiting for activity ... max_sd: " <<  max_sd << '\n';
        activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);   
       
        if ((activity < 0) && (errno!=EINTR))   
        {   
            printf("select error");   
        }   
             
        // [5] If something happened on the master socket, then its an incoming connection  
        if (FD_ISSET(master_socket, &readfds))   
        {   
            std::cout << "EVENT: ACCEPT_EVENT" << '\n';
            if ((new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)   
            {   
                perror("accept");   
                exit(EXIT_FAILURE);   
            }   
             
            //inform user of socket number - used in send and receive commands  
            printf("New connection , socket fd is %d , ip is : %s , port : %d\n", new_socket, inet_ntoa(address.sin_addr) , ntohs(address.sin_port));
           
            //send new connection greeting message  
            if(send(new_socket, message, strlen(message), 0) != strlen(message) )   
            {   
                perror("send");   
            }   
                 
            // puts("Welcome message sent successfully");   
                 
            //add new socket to array of sockets  
            for (i = 0; i < max_clients; i++)   
            {   
                //if position is empty  
                if( client_socket[i] == 0 )   
                {   
                    client_socket[i] = new_socket;   
                    printf("Adding to list of sockets as %d\n" , i);   
                         
                    break;   
                }   
            }   
        }   
             
        //else its some IO operation on some other socket 
        for (i = 0; i < max_clients; i++)   
        {   
            sd = client_socket[i];   
                 
            if (FD_ISSET( sd , &readfds))   
            {   
                //Check if it was for closing , and also read the  
                //incoming message  
                if ((valread = read( sd , buffer, 1024)) <= 0)   
                {   
                    std::cout << "EVENT: CLOSE_EVENT" << '\n';
                    //Somebody disconnected , get his details and print  
                    getpeername(sd , (struct sockaddr*)&address, (socklen_t*)&addrlen);   
                    printf("Host disconnected , ip %s , port %d \n" ,  
                          inet_ntoa(address.sin_addr) , ntohs(address.sin_port));   
                         
                    //Close the socket and mark as 0 in list for reuse  
                    close( sd );   
                    client_socket[i] = 0;   
                }                    
                //Echo back the message that came in  
                else 
                {  
                    std::cout << "EVENT: READ_EVENT" << '\n'; 
                    //set the string terminating NULL byte on the end  
                    //of the data read  
                    buffer[valread] = '\0';
                    std::string defaultMessage("This is default message from server!");
                    send(sd , defaultMessage.c_str() , strlen(defaultMessage.c_str()) , 0 );
                    // send(sd , buffer , strlen(buffer) , 0 );   
                }   
            }   
        }   
    }	
    }

private:	
	// Singleton Factory - Private Constructor
	Initiation_Dispatcher() 
	{
	};

    int opt = TRUE; 

    int master_socket;
    int addrlen; 
    int new_socket;
    int client_socket[30];
    int max_clients = 30;

    int activity;
    int i; 
    int valread;
    int sd;
    int max_sd;   
    struct sockaddr_in address;   
         
    char buffer[1025];  //data buffer of 1K 

    //set of socket descriptors  
    fd_set readfds;   
         
    //a message  
    char* message = "ECHO from multi server";  

    // TODO: remove this
    std::vector<EventHandler*> m_vecOfEventHandler;
};
} // End of namespace