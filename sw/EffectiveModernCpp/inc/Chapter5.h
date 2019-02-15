#pragma once
#include "Chapter5If.h"


namespace Chapter5NameSpace
{

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
    
    // Item 30
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
