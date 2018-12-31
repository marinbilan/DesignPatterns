#include "Service0.h"
#include "Service1.h"


const std::string ServiceNameSpace::Service0::objectID= "ServiceNameSpace::Service0"; 


ServiceNameSpace::Service0::Service0(const std::string& name) : m_name(name)
{
    std::cout << "[Service0][Service0(const std::string& name)] Constructor called" << std::endl;
} 


ServiceNameSpace::Service0::~Service0()
{
    std::cout << "[Service0][~Service0] Destructor called" << std::endl;
}


void ServiceNameSpace::Service0::preInit()
{
    std::cout << "[Service0][preInit] get some database entries" << std::endl;
}


void ServiceNameSpace::Service0::postInit()
{
    std::cout << "[Service0][postInit] get ptrs on other services" << std::endl;
    m_ScanRef = new  Service1("ScanRef");
}


std::string ServiceNameSpace::Service0::getObjectId()
{
    std::cout << "[Service0][getObjectId] OK" << std::endl;
    return objectID;
}


std::string ServiceNameSpace::Service0::getObjectName()
{
    std::cout << "[Service0][getObjectName] OK" << std::endl;
    return m_name;
}


void ServiceNameSpace::Service0::setService1If(Service1If* service1IfPrt)
{
    std::cout << "[Service0][setService1If] OK" << std::endl;
    m_ScanRef = service1IfPrt;
}


std::vector<std::string> ServiceNameSpace::Service0::sampleInsertElement(std::string inputString, int position)
{
    std::cout << "[Service0][sampleInsertElement] OK" << std::endl;
    
    std::vector<std::string> vSample;

    // TEST_1
    vSample.push_back("2345");
    vSample.push_back("6789");
    vSample.push_back("7890");
    vSample.push_back("1254");

    try
    {
        if(!inputString.empty())
        {
            vSample.at(position) = inputString;
        }
    }
    catch(std::exception& e)
    {
        std::cout << "standard exception: " << e.what() << std::endl;
    }

    // TEST_2    
    /*    vSample.insert(vSample.begin(), inputString);*/

    return vSample;
}    


void ServiceNameSpace::Service0::findFilesInHomeDrive(ScanIF& scanObject)
{
    std::cout << "[Service0][findFilesInHomeDrive] OK" << std::endl;
        
    std::vector<std::string> listDirectories;

    listDirectories.push_back("/home/Music");
    listDirectories.push_back("/home/Pictures");
    listDirectories.push_back("/home/Videos");
    listDirectories.push_back("/home/Downloads");
    
     for(std::vector<std::string>::iterator it = listDirectories.begin(); it != listDirectories.end(); ++it)
     {
         scanObject.f(*it);
     }
}


std::vector<std::string> ServiceNameSpace::Service0::getVectorOfDummyStrings()
{
    std::cout << "[Service0][getVectorOfDummyStrings] OK" << std::endl;
    
    std::vector<std::string> vec;
    vec.push_back("/home/Downloads");
    vec.push_back("string 1");
    vec.push_back("string 2");
    
    return vec;
} 


std::string ServiceNameSpace::Service0::getDummyString()
{
    std::cout << "[Service0][getDummyString] OK" << std::endl;
    
    std::string str("this is dummy string");
    return str;
} 


std::string ServiceNameSpace::Service0::findFileStat()
{        
    FileStat aSample;
    aSample.fileSize = 0;
    
    // sampleVector is hidden - How to get control over that in UT
    std::vector<std::string> sampleVector = m_ScanRef->getList();
    // sampleVector.push_back("adding1");    

    //m_ScanRef->getFileStatistics(sampleVector, aSample);
    m_ScanRef->getFileStatistics2(sampleVector, &aSample);
                
    std::cout << "aSample.fileSize = " << aSample.fileSize << std::endl;
        
    if( aSample.fileSize <= 0 )
    {
        return "error_in_stats";
    }
    else if (aSample.fileSize > 0)
    {
       return "success_in_stats";
    } 

} 


std::string ServiceNameSpace::Service0::findFileStatTest()
{        
    FileStat aSample;
    aSample.fileSize = 0;
    
    // sampleVector is hidden - How to get control over that in UT
    // std::vector<std::string> sampleVector = m_ScanRef->getList();
    std::vector<std::string> sampleVector = m_ScanRef->getListRef();
    
    //m_ScanRef->getFileStatistics(sampleVector, aSample);
    m_ScanRef->getFileStatistics2(sampleVector, &aSample);
                
    std::cout << "REAL aSample.fileSize = " << aSample.fileSize << std::endl;
    std::cout << "REAL sampleVector.size() = " << sampleVector.size() << std::endl; 
        
/*    if( aSample.fileSize <= 0 )
    {
        return "error_in_stats";
    }
    else if (aSample.fileSize > 0)
    {
       return "success_in_stats";
    } */

    if(sampleVector.size() != 0)
    {
        std::cout << "OK" << std::endl;
        return "OK";
    } else
    {
        std::cout << "NOK" << std::endl;
        return "NOK";
    }
    return "OK";
} 

//
// unit Test
//
int ServiceNameSpace::Service0::unitTest0(std::string& str)
{ 
    // Test 1
    std::string fString("fString");
    str = fString;
    std::cout << "[Service0][unitTest0] > str: " << str << std::endl;
    // MOCK (Service1)
    int testInt = m_ScanRef->returnInt();
    //
    std::cout << "[Service0][unitTest0] > testInt: " << testInt << std::endl;
    
    
    // Test 2
    int i = 7;
    std::string str0("expectedString");
    //
    int testInt0 = m_ScanRef->returnInt0(i, str0);
    // MOCK (Service1)
    std::cout << "[Service0][unitTest0] > testInt0: " << testInt0 << std::endl;
    std::cout << "[Service0][unitTest0] > str0: " << str0 << std::endl;
    
    // 
    
    if(testInt == 17)
    {
        return 0;
    } 
    else 
    {
        return 1;
    }
} 