#include "Chapter5.h"


const std::string Chapter5NameSpace::Chapter5::objectID= "ServiceNameSpace::EffectiveModernCpp_Chapter5"; 


Chapter5NameSpace::Chapter5::Chapter5(const std::string& name) : m_name(name)
{
    std::cout << "[Chapter5][Chapter5(const std::string& name)] Constructor called" << std::endl;
} 


Chapter5NameSpace::Chapter5::~Chapter5()
{
    std::cout << "[Chapter5][~Chapter5] Destructor called" << std::endl;
}


void Chapter5NameSpace::Chapter5::preInit()
{
    std::cout << "[Chapter5][preInit] get some database entries" << std::endl;
}


void Chapter5NameSpace::Chapter5::postInit()
{
    std::cout << "[Chapter5][postInit] get ptrs on other services" << std::endl;
}


std::string Chapter5NameSpace::Chapter5::getObjectId()
{
    std::cout << "[Chapter5][getObjectId] called ... " << std::endl;
    return objectID;
}


std::string Chapter5NameSpace::Chapter5::getObjectName()
{
    std::cout << "[Chapter5][getObjectName] OK" << std::endl;
    return m_name;
}


// ITEM 29
void Chapter5NameSpace::Chapter5::Chapter5_Item29() 
{ 
    std::cout << " ... Chapter5_Item29 ..." << std::endl;        
} 


// ITEM 30 
// Ex 2
void Chapter5NameSpace::Chapter5::f(int&& i) 
{ 
    std::cout << "calling int&&" << std::endl;        
} 

void Chapter5NameSpace::Chapter5::f(int& i) 
{ 
    std::cout << "calling int&" << std::endl;       
} 

// Ne radi [ Ne moze se forward prema samo int ]  
/* 
void f(int i) 
{ 
    std::cout << "calling int" << std::endl;       
} 
*/ 

void Chapter5NameSpace::Chapter5::f(const std::vector<int>& v) 
{ 
    std::cout << "calling const std::vector<int>&" << std::endl; 
} 

void Chapter5NameSpace::Chapter5::f(const std::vector<int>&& v) 
{ 
    std::cout << "calling const std::vector<int>&&" << std::endl; 
} 

