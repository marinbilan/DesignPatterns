#include "StartUp.h"

#include "Service0.h"
#include "Service1.h"

#include "Driver0.h"


const std::string StartUpNameSpace::StartUp::objectID= "StartUp"; 

StartUpNameSpace::StartUp::StartUp()
{
    std::cout << "[StartUp][StartUp()] Constructor called" << std::endl;
}


StartUpNameSpace::StartUp::~StartUp()
{
    std::cout << "[StartUp] Destructor called" << std::endl;
}

std::string StartUpNameSpace::StartUp::getName()
{
    return objectID;
}


void StartUpNameSpace::StartUp::init()
{
    std::cout << "[StartUp][init]" << std::endl;
    //
    // Services
    //
    // 
    // 1] Register service 
    // REGISTER_CLASS(Constructor name)  - hardcoded constructor with std::string param (get from db)
    // All classes have the constructor with one param - std::string
    registerAllServices();
    
    // 2] Create all service instances (invoke constructor via second param of map (template function ptr))
    createAllServiceInstances();
    
    sandBox();

}


void StartUpNameSpace::StartUp::registerAllServices()
{
    std::cout << "[StartUp][registerServices]" << std::endl;
    
    // Can create template prototype for any class (nosntructor) in the same map!
    REGISTER_CLASS(ServiceNameSpace::Service0); 
}


void StartUpNameSpace::StartUp::createAllServiceInstances()
{
    std::cout << "[StartUp][createAllServiceInstances]" << std::endl;

    // CREATE OBJECTs using already registered class
    // 1st param - objectId (/type) (constructor name), 2nd param - objectName (constructor param) (unique for each object)
    std::string serviceType1("ServiceNameSpace::Service0");  // [FIND] /type in map and [CONSTRUCT] object with std::string param (call function/constructor)
    ServiceNameSpace::ServiceBaseIf* service00 = (ServiceNameSpace::ServiceBaseIf*)DesignPatternsNamespace::ServiceFactory::getInstance().construct(serviceType1, "1234");
    ServiceNameSpace::ServiceBaseIf* service01 = (ServiceNameSpace::ServiceBaseIf*)DesignPatternsNamespace::ServiceFactory::getInstance().construct(serviceType1, "4321");

    // REGISTER SERVICEs in container
    // 3] Register service in container
    registerServiceInContainer(serviceType1, service00);
    registerServiceInContainer(serviceType1, service01);
}


void StartUpNameSpace::StartUp::registerServiceInContainer(const std::string& serviceType, ServiceNameSpace::ServiceBaseIf* serviceBaseIf)

{
    std::cout << "[StartUp][registerServiceInContainer]" << std::endl;

    ContainerNameSpace::Container::getInstance().registerService(serviceType, serviceBaseIf);
}


void StartUpNameSpace::StartUp::sandBox()

{
    std::cout << " <---- [StartUp][sandBox] ---->" << std::endl;

    //
    // Services Test
    //
    ServiceNameSpace::ServiceBaseIf* temp = ContainerNameSpace::Container::getInstance().getServiceFromContainer("1234");
    ServiceNameSpace::Service0If* service0If = dynamic_cast<ServiceNameSpace::Service0If*>(temp);   
    
    std::cout<< " <---- SERVICEs ----> " << std::endl;
    
    std::cout<< temp->getObjectName() << std::endl;   
    // preinit service
    service0If->preInit();

    // postInit service
    service0If->postInit();
    
    std::string str("dummy");
    service0If->sampleInsertElement(str, 2);
    
    ScanIF sIf;
    service0If->findFilesInHomeDrive(sIf);
    service0If->getVectorOfDummyStrings();
    std::string str0 = service0If->getDummyString();
    // str0 = service0If->findFileStat();
    // str0 = service0If->findFileStatTest();    
    
    // Other stuff
    // ContainerNameSpace::Container::getInstance().showAllServicesInContainer();

    
    //
    //
    // Drivers
    //
    //
    
    // 1] Drivers are already registered in .cpp files
    // 2] Create driver instance
    std::string Driver0Type = "DriverNameSpace::Driver0";
    DesignPatternsNamespace::DriverFactory::create().createInstance(Driver0Type);
    
    auto driver = DesignPatternsNamespace::DriverFactory::create().getInstance(Driver0Type);
    
 	if(driver)
	{
		driver->init();
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	} 
    std::cout<< " <------------------------> " << std::endl;        
}