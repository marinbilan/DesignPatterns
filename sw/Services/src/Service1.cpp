#include "Service1.h"


const std::string ServiceNameSpace::Service1::objectID= "ServiceNameSpace::Service1"; 


ServiceNameSpace::Service1::Service1(const std::string& name) : m_name(name)
{
    std::cout << "[Service1][Service1(const std::string& name)] Constructor called" << std::endl;
    
} 


ServiceNameSpace::Service1::~Service1()
{
    std::cout << "[Service1][~Service1] Destructor called" << std::endl;
}


void ServiceNameSpace::Service1::preInit()
{
    std::cout << "[Service1][preInit] get some database entries" << std::endl;
}


void ServiceNameSpace::Service1::postInit()
{
    std::cout << "[Service1][postInit] get ptrs on other services" << std::endl;
}


std::string ServiceNameSpace::Service1::getObjectId()
{
    std::cout << "[Service1][getObjectId] OK" << std::endl;
    return objectID;
}


std::string ServiceNameSpace::Service1::getObjectName()
{
    std::cout << "[Service1][getObjectName] OK" << std::endl;
    return m_name;
}


std::vector<std::string> ServiceNameSpace::Service1::getList()
{
    std::cout << "[Service1][getList] OK" << std::endl;
    std::string str0("str0");
    std::vector<std::string> vec;
    vec.push_back(str0);
        
    return vec;
}  


std::vector<std::string>& ServiceNameSpace::Service1::getListRef()
{
    std::cout << "[Service1][getListRef] OK" << std::endl;
        
    std::string str0("str0");
    std::vector<std::string> vec;
    vec.push_back(str0);
        
    return vec;
}  


void ServiceNameSpace::Service1::getFileStatistics(std::vector<std::string> vec, FileStat& stat)
{
    std::cout << "[Service1][getFileStatistics] OK" << std::endl;
}  


void ServiceNameSpace::Service1::getFileStatistics2(std::vector<std::string>& filePath,     FileStat* fileStat)
{
    std::cout << "[Service1][getFileStatistics2] OK" << std::endl;
} 

//
// unit Test
//
int ServiceNameSpace::Service1::returnInt()
{
    std::cout << "[Service1][returnInt] OK" << std::endl;
    return 0;
} 


int ServiceNameSpace::Service1::returnInt0(int i, std::string& str)
{
    std::cout << "[Service1][returnInt0] OK" << std::endl;
    return 0;
} 