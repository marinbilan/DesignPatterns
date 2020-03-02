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


#include <errno.h> 
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros  
     
#define TRUE   1  
#define FALSE  0  
// #define PORTSERVER 8888  

#define PORT 8080 
// GIT
// git remote add origin https://github.com/marinbilan/DesignPatterns.git
// git push -u origin master

/*
void test1()
{
    const int NUM_HEIGHTS = 3;
    int* heights = (int*)malloc(NUM_HEIGHTS * sizeof(* heights));
    for(int i = 0; i < NUM_HEIGHTS; i++)
    {
        heights[i] = i*i;
        std::cout << " test1() i= " << heights[i] << std::endl;
    }
    
    free(heights);
} 
*/

int main(int argc, char *argv[])
{
    // std::cout << "argc = " << argc << " argv[0] = " << argv[0] << " argv[1] = " << argv[1]  << " argv[2] = " << argv[2]  << std::endl;

    // test1();
    
/*    std::string line;
    std:: ifstream myfile ("sw/db/db.txt");
    std::vector<std::string> createDbClasses;
  
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            std::cout << line << '\n';
            
            std::istringstream iss(line);
            std::vector<std::string> results((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
            
            std::vector<std::string>::iterator it = std::find(results.begin(), results.end(), "Create");
            if (it != results.end())
            {
                std::cout << "Element in vector: " << *it << std::endl;
                results.erase(it);
                createDbClasses = results; // Assume only one Create line is there
            }
        }
        
        myfile.close();
    }
    else std::cout << "Unable to open file"; 
  
  
  
  
  
    for(auto it = createDbClasses.begin(); it != createDbClasses.end(); ++it)
    {
        std::cout << "x: " << *it << std::endl;
    }
  */
  
    // Init everything
/*
    StartUpNameSpace::StartUp startUp;
    startUp.init(); 
    
    std::cout << "Enter something ..." << std::endl;
    std::cin.get();
*/

    // -------- SOCKET PROGRAMMING --------
    if(!strcmp(argv[1], "client")) 
    { 
        std::cout << "This is client!" << std::endl; 
        std::string commandLineString;

	    int sock = 0, valread; 
	    struct sockaddr_in serv_addr; 
	    char *hello = "Hello from client"; 
	    char buffer[1024] = {0}; 
	    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	    { 
		printf("\n Socket creation error \n"); 
		return -1; 
	    } 
	   
	    serv_addr.sin_family = AF_INET; 
	    serv_addr.sin_port = htons(PORT); 
	       
	    // Convert IPv4 and IPv6 addresses from text to binary form 
	    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
	    { 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	    } 
	   
	    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	    { 
		printf("\nConnection Failed \n"); 
		return -1; 
	    } 

            // NEW code 
            do
	    {
	    std::cout << "$ ";
            // Waiting for command 
            std::getline(std::cin, commandLineString);
            const char* msg = commandLineString.c_str();

	        send(sock , msg , strlen(msg) , 0 ); 
	        printf("Hello message sent\n"); 

                // Read (as from file) from sock what server send to me
	        valread = read( sock , buffer, 1024); 
	        printf("%s\n",buffer ); 
            } while (commandLineString != "exit");
            
            // OLD code  
	    //send(sock , hello , strlen(hello) , 0 ); 
	    //printf("Hello message sent\n"); 
	    // valread = read( sock , buffer, 1024); 
	    // printf("%s\n",buffer ); 

    } 
    else if (!strcmp(argv[1], "server")) 
    {
        std::cout << " ---- This is server ----" << std::endl;
	    int server_fd, new_socket, valread; 
	    struct sockaddr_in address; 
	    int opt = 1; 
	    int addrlen = sizeof(address); 
	    char buffer[1024] = {0}; 
	    char *hello = "Hello from server"; 
	       
	    // Creating socket file descriptor 
	    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
	    { 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	    } 
	       
	    // Forcefully attaching socket to the port 8080 
	    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
		                                          &opt, sizeof(opt))) 
	    { 
		perror("setsockopt"); 
		exit(EXIT_FAILURE); 
	    } 
	    address.sin_family = AF_INET; 
	    address.sin_addr.s_addr = INADDR_ANY; 
	    address.sin_port = htons( PORT ); 
	       
	    // Forcefully attaching socket to the port 8080 
	    if (bind(server_fd, (struct sockaddr *)&address,  
		                         sizeof(address))<0) 
	    { 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	    } 
	    if (listen(server_fd, 3) < 0) 
	    { 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	    } 
            printf("Waiting for accept client ...\n"); 
	    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
		               (socklen_t*)&addrlen))<0) 
	    { 
		perror("accept"); 
		exit(EXIT_FAILURE); 
	    } 
	    valread = read( new_socket , buffer, 1024); 
	    printf("%s\n",buffer ); 
	    send(new_socket , hello , strlen(hello) , 0 ); 
	    printf("Hello message sent\n"); 

    }
    else if (!strcmp(argv[1], "servermulti")) 
    {
    int opt = TRUE;   
    int master_socket , addrlen , new_socket , client_socket[30] ,  
          max_clients = 30 , activity, i , valread , sd;   
    int max_sd;   
    struct sockaddr_in address;   
         
    char buffer[1025];  //data buffer of 1K  
         
    //set of socket descriptors  
    fd_set readfds;   
         
    //a message  
    char *message = "ECHO Daemon v1.0 \r\n";   
     
    //initialise all client_socket[] to 0 so not checked  
    for (i = 0; i < max_clients; i++)   
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
    if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,  
          sizeof(opt)) < 0 )   
    {   
        perror("setsockopt");   
        exit(EXIT_FAILURE);   
    }   
     
    //type of socket created  
    address.sin_family = AF_INET;   
    address.sin_addr.s_addr = INADDR_ANY;   
    address.sin_port = htons( PORT );   
         
    //bind the socket to localhost port 8888  
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
    puts("Waiting for connections ...");   
         
    while(TRUE)   
    {   
        //clear the socket set  
        FD_ZERO(&readfds);   
     
        //add master socket to set  
        FD_SET(master_socket, &readfds);   
        max_sd = master_socket;   
             
        //add child sockets to set  
        for ( i = 0 ; i < max_clients ; i++)   
        {   
            //socket descriptor  
            sd = client_socket[i];   
                 
            //if valid socket descriptor then add to read list  
            if(sd > 0)   
                FD_SET( sd , &readfds);   
                 
            //highest file descriptor number, need it for the select function  
            if(sd > max_sd)   
                max_sd = sd;   
        }   
     
        //wait for an activity on one of the sockets , timeout is NULL ,  
        //so wait indefinitely
        // puts("Waiting for activity ... max_sd: %d\n", max_sd);
        std::cout << "Waiting for activity ... max_sd: " <<  max_sd << '\n';
        activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);   
       
        if ((activity < 0) && (errno!=EINTR))   
        {   
            printf("select error");   
        }   
             
        //If something happened on the master socket ,  
        //then its an incoming connection  
        if (FD_ISSET(master_socket, &readfds))   
        {   
            if ((new_socket = accept(master_socket,  
                    (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)   
            {   
                perror("accept");   
                exit(EXIT_FAILURE);   
            }   
             
            //inform user of socket number - used in send and receive commands  
            printf("New connection , socket fd is %d , ip is : %s , port : %d\n", new_socket, inet_ntoa(address.sin_addr) , ntohs(address.sin_port));
           
            //send new connection greeting message  
            if( send(new_socket, message, strlen(message), 0) != strlen(message) )   
            {   
                perror("send");   
            }   
                 
            puts("Welcome message sent successfully");   
                 
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
                    //Somebody disconnected , get his details and print  
                    getpeername(sd , (struct sockaddr*)&address , \ 
                        (socklen_t*)&addrlen);   
                    printf("Host disconnected , ip %s , port %d \n" ,  
                          inet_ntoa(address.sin_addr) , ntohs(address.sin_port));   
                         
                    //Close the socket and mark as 0 in list for reuse  
                    close( sd );   
                    client_socket[i] = 0;   
                }   
                     
                //Echo back the message that came in  
                else 
                {   
                    //set the string terminating NULL byte on the end  
                    //of the data read  
                    buffer[valread] = '\0';   
                    send(sd , buffer , strlen(buffer) , 0 );   
                }   
            }   
        }   
    }	
    }
    else 
    {
         std::cout << " ---- Wrong param ----" << std::endl;
    }

    return 0;
}





































