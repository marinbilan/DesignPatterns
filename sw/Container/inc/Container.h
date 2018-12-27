#pragma once
#include "ContainerIf.h"


namespace ContainerNameSpace
{

class Container : public ContainerNameSpace::ContainerIf
{
public:
    ~Container();
    
    std::string getName();
    
    // Singleton Stuff
    static Container& getInstance()
    {
        static Container instance;
        return instance;
    } 

    Container(Container const&) = delete;
    void operator=(Container const&) = delete;
    //
 
    void init();
   
    void registerService(const std::string& serviceType, ServiceNameSpace::ServiceBaseIf* service);

   ServiceNameSpace::ServiceBaseIf* getServiceFromContainer(const std::string& serviceName);

    void showAllServicesInContainer();
private:
    Container();
    
static const std::string objectID;
std::multimap<std::string, ServiceNameSpace::ServiceBaseIf*> m_servicesMap;
};

} // End of namespace