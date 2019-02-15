#include "Container.h"


const std::string ContainerNameSpace::Container::objectID= "Container"; 

ContainerNameSpace::Container::Container()
{
    std::cout << "[Container][Container()]" << std::endl;
} 


ContainerNameSpace::Container::~Container()
{
    std::cout << "[Container][~Container()]" << std::endl;
}


void ContainerNameSpace::Container::init()
{
    std::cout << "[Container][init]" << std::endl;
}


std::string ContainerNameSpace::Container::getName()
{
    return objectID;
}


void ContainerNameSpace::Container::registerService(const std::string& serviceType, ServiceNameSpace::ServiceBaseIf* service)
{
    std::cout << "[Container][registerService]" << std::endl;
    m_servicesMap.insert(std::make_pair(serviceType, service));
}

void ContainerNameSpace::Container::showAllServicesInContainer()
{
    std::cout << "[Container][showAllServicesInContainer]" << std::endl;
    std::map<std::string, ServiceNameSpace::ServiceBaseIf*>::iterator it;
        
    for(it = m_servicesMap.begin(); it != m_servicesMap.end(); ++it)
    {
        std::cout << "  objectId: " << it->second->getObjectId() << std::endl;
        std::cout << "  objectName: " << (it->second)->getObjectName() << std::endl;
    }
}


ServiceNameSpace::ServiceBaseIf* ContainerNameSpace::Container::getServiceFromContainer(const std::string& serviceName)
{
    std::cout << "[Container][getServiceFromContainer]" << std::endl;
    std::map<std::string, ServiceNameSpace::ServiceBaseIf*>::iterator it;
        
    for(it = m_servicesMap.begin(); it != m_servicesMap.end(); ++it)
    {        
        if(!serviceName.compare( it->second->getObjectName() ))
        {
            std::cout << "  service found getObjectName: " << (it->second)->getObjectName() << std::endl; 
            return it->second;
        }
    }
    
    return nullptr;
}