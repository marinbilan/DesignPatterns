#include "StartUp.h"

// Services
#include "Service0.h"
#include "Service1.h"
#include "ServiceCarIf.h"
#include "ServiceCar.h"
// Drivers
#include "Driver0.h"
// DesignPatterns
#include "BuilderPatternIf.h"
#include "BuilderPattern.h"
#include "AbstractFactoryIf.h"
#include "AbstractFactory.h"


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
    
    // 3] TODO preInit
    
    // 4] TODO postInit
    
    sandBox();

}


void StartUpNameSpace::StartUp::registerAllServices()
{
    std::cout << "[StartUp][registerServices]" << std::endl;
    
    // Can create template prototype for any class (nosntructor) in the same map!
    // NameSpace::ConstructorName
    REGISTER_CLASS(ServiceNameSpace::Service0); 
    REGISTER_CLASS(ServiceNameSpace::Service1); 
}


void StartUpNameSpace::StartUp::createAllServiceInstances()
{
    std::cout << "[StartUp][createAllServiceInstances]" << std::endl;

    // CREATE OBJECTs using already registered class
    // 1st param - objectId (/type) (constructor name), 2nd param - objectName (constructor param) (unique for each object)
    std::string serviceType1("ServiceNameSpace::Service0");  // [FIND] /type in map and [CONSTRUCT] object with std::string param (call function/constructor)
    // Create two instance of 1 registered class (ServiceNameSpace::Service0)
    ServiceNameSpace::ServiceBaseIf* service00 = (ServiceNameSpace::ServiceBaseIf*)DesignPatternsNamespace::HighFactory::getInstance().construct(serviceType1, "1234");
    ServiceNameSpace::ServiceBaseIf* service01 = (ServiceNameSpace::ServiceBaseIf*)DesignPatternsNamespace::HighFactory::getInstance().construct(serviceType1, "4321");
    
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




    std::cout<< " <---- BUILDER PATTERN START ----> " << std::endl;
    // Product is BuilderPattern built by Builed object inside class BuilderPattern
    // Ex 1
    std::cout<< " <---- Ex 1 ----> " << std::endl;
    DesignPatternsNamespace::BuilderPattern p1 = DesignPatternsNamespace::BuilderPattern::Builder().setI(2).setF(0.5f).build(); 
    p1.print();
    
    // Ex 2
    std::cout<< " <---- Ex 2 ----> " << std::endl;
    // Advanced usage 
    // Default values 
    DesignPatternsNamespace::BuilderPattern::Builder b;        // Uciti da se builder kreira bez zagrada! ...::Builder()
    
    b.setProductA(); 
    DesignPatternsNamespace::BuilderPattern p2 = b.build(); // get Product P object 

    b.setI(1113);                   // customize Product P 
    DesignPatternsNamespace::BuilderPattern p3 = b.build(); 

    p2.print();                       // test p2 
    p3.print();                       // test p3    
    std::cout<< " <---- BUILDER PATTERN END----> " << std::endl;
    
    


    std::cout<< " <---- ABSTRACT FACTORY PATTERN START ----> " << std::endl;
    // Create Factory
    DesignPatternsNamespace::AbstractFactoryIf* af0 = new DesignPatternsNamespace::AbstractFactorySaharaCar;
    std::cout << "Factory in StartUp created: " << af0->getName() << std::endl;
    
    ServiceNameSpace::CarIf* carSahara = new ServiceNameSpace::CarSahara("CarSahara");
    carSahara->setEngine(af0->getEngine());
    carSahara->setWheel(af0->getWheel());

    // Create Factory
    DesignPatternsNamespace::AbstractFactoryIf* af1 = new DesignPatternsNamespace::AbstractFactorySibirCar;
    std::cout << "Factory in StartUp created: " << af1->getName() << std::endl;
    
    ServiceNameSpace::CarIf* carSibir = new ServiceNameSpace::CarSibir("CarSibir");
    carSibir->setEngine(af1->getEngine());
    carSibir->setWheel(af1->getWheel()); 

    std::cout<< " <---- ABSTRACT FACTORY PATTERN END ----> " << std::endl; 
}