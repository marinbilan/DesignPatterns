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
    
    // Services
    // 1] Register service
    // 2] Create service instances (invoke constructor via second param of map (template function ptr))
    // 3] Register service in container
    // preinit service
    // postInit service
    
    // Drivers
    // 1] Drivers are already registered in .cpp files
    // 2] Create driver instance
    
    //  REGISTER_CLASS(Constructor name)  - hardcoded constructor with std::string param
    // All classes have the constructor with one param - std::string
    REGISTER_CLASS(Test); 
    REGISTER_CLASS(ServiceNameSpace::Service0); 


    // CREATE OBJECTs using already registered class
    // 1st param - objectId (/type) (constructor name), 2nd param - objectName (constructor param) (unique for each object)
    std::string serviceType0("Test");
    Test* test0 = (Test*)DesignPatternsNamespace::ServiceFactory::getInstance().construct(serviceType0, "1234");
    Test* test1 = (Test*)DesignPatternsNamespace::ServiceFactory::getInstance().construct(serviceType0, "Object 4321");

    std::string serviceType1("ServiceNameSpace::Service0");  // [FIND] /type in map and [CONSTRUCT] object with std::string param (call function/constructor)
    ServiceNameSpace::ServiceBaseIf* service00 = (ServiceNameSpace::ServiceBaseIf*)DesignPatternsNamespace::ServiceFactory::getInstance().construct(serviceType1, "1234");
    ServiceNameSpace::ServiceBaseIf* service01 = (ServiceNameSpace::ServiceBaseIf*)DesignPatternsNamespace::ServiceFactory::getInstance().construct(serviceType1, "4321");


    // REGISTER SERVICEs in container
    ContainerNameSpace::Container::getInstance().registerService(serviceType1, service00);
    ContainerNameSpace::Container::getInstance().registerService(serviceType1, service01);
    


    // Other stuff
    // ContainerNameSpace::Container::getInstance().showAllServicesInContainer();

    ServiceNameSpace::ServiceBaseIf* temp = ContainerNameSpace::Container::getInstance().getServiceFromContainer("1234");
    ServiceNameSpace::Service0If* service0If = dynamic_cast<ServiceNameSpace::Service0If*>(temp);
    
    std::cout<< " <---- SERVICEs ----> " << std::endl;
    
    std::cout<< temp->getObjectName() << std::endl;
    
    service0If->preInit();
    service0If->postInit();
    
    std::string str("dummy");
    service0If->sampleInsertElement(str, 2);
    
    ScanIF sIf;
    service0If->findFilesInHomeDrive(sIf);
    service0If->getVectorOfDummyStrings();
    std::string str0 = service0If->getDummyString();
    str0 = service0If->findFileStat();
    str0 = service0If->findFileStatTest();
    
    std::cout<< " <----          ----> " << std::endl;
    
    
    
    
    // Driver Factory
    std::string Driver0Type = "DriverNameSpace::Driver0";
    // Driver first need to be regisetred
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
    
    std::cout<< " <----     Service1     ----> " << std::endl;

    ServiceNameSpace::Service1If* srv = new ServiceNameSpace::Service1("Service1_Name");
    srv->getList();

    
}