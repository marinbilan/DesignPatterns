#pragma once
#include "Chapter5If.h"


namespace Chapter5NameSpace
{

// TODO: Move this in resource class or namespace ...
class Holder 
{ 
public: 

    Holder(int size) : m_size(size) 
    { 
        std::cout << "Holder constructor called! Size: " << m_size << std::endl; 
    } 

    // RULE OF THREE: Destructor, Copy constructor, Assignment operator 
    ~Holder() 
    { 
    } 

    Holder(const Holder& other) 
    { 
        std::cout << "Holder copy constructor called!" << std::endl; 
        // ... add real implementation ....
    } 

    // Copy constructor + check and return 
    Holder& operator=(const Holder& other) 
    { 
        std::cout << "Holder Assignment operator called!\n" << std::endl; 

        if(this == &other) return *this; 
        // ... add real implementation ...
    
        return *this; 

    } 

    // < ---- RULE OF FIVE: move constructor, move operator=  ---- >
    
    // VAZNO!!! Kod rvalue move i assign operatora BRISE SE VARIJABLA s desne strane 
    // (za razliku od obicnih operatora move I assign kod kojih se ne brise vrijednost varijabli s desne strane) 

    Holder(Holder&& other)     // <-- rvalue reference in input 
    { 
        std::cout << "Holder Move Constructor operator called!\n" << std::endl; 
    } 

    Holder& operator=(Holder&& other)     // <-- rvalue reference in input   
    {  
        std::cout << "Holder Move Assignment operator called!\n" << std::endl; 

        return *this; 

    } 
    
private: 

int m_size; 
}; 




class Chapter5 : public Chapter5NameSpace::Chapter5If
{
public:
    Chapter5(const std::string& name);
    
    ~Chapter5();
    
    // Mandatory
    void preInit();
    
    void postInit();
    
    std::string getObjectId();  // Constructor
    
    std::string getObjectName();    // Token
    //

    // Item 29 - Assume that move operations are not present, not cheap, and not used
    // ----- ----
    void Chapter5_Item29();
    // ----- ----
    
    
    // Item 30 - Familiarize yourself with perfect forwarding failure cases
    // ----- ----
    // Ex 1 - Not related to this Item 30 but this is how print args ...
    // Template functions must be  defined in .h files
    template <typename T> 
    void print(T t) 
    { 
        std::cout << t << std::endl; 
    } 

    // Base case, no args 
    void f0() {} 

    // Split the parameter pack.
    // We want the first argument, so we can print it.
    // And the rest so we can forward it to the next call to f 
    template <typename T, typename...Ts> 
    void f0(T&& first, Ts&&... rest) 
    { 
        // print it 
        print(std::forward<T>(first)); 
        // Forward the rest.
        f0(std::forward<Ts>(rest)...); 
    } 

    // ----- ----
    
    // Ex 1.1 - Not related to this Item 30 but this is how print args (First 2 args) ...
    // Base case, no args 
    void f1() {} 
    
    template <typename T0, typename T1, typename...Ts> 
    void f1(T0&& first, T1&& second, Ts&&... rest) 
    { 
        // print it [Printaj po dva!] 
        print(std::forward<T0>(first)); 
        print(std::forward<T1>(second)); 
        std::cout << " ---- " << std::endl; 
    
        // Forward the rest. 
        f1(std::forward<Ts>(rest)...); 
    }
    // ----- ---- 
    
    // Ex 2
    void f(int&& i);

    void f(int& i);

    // Ne radi [ Ne moze se forward prema samo int ]  
    // void f(int i)  // Isto i za vector

    void f(const std::vector<int>& v); 

    void f(const std::vector<int>&& v);
    
    template<typename T> 
    void fwd(T&& param) // accept any argument 
    { 
        f(std::forward<T>(param)); // forward it to f 
    } 


private:
static const std::string objectID;
std::string m_name;
};

} // End of namespace
