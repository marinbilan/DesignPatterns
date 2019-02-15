#include <iostream>

#include "StartUp.h"

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
    StartUpNameSpace::StartUp startUp;
    startUp.init(); 
    
    std::cout << "Enter something ..." << std::endl;
    std::cin.get();
}





































