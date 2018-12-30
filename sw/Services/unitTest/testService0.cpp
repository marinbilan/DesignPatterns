//#include "Service0If.h"
#include "Service0.h"
#include "Service1.h"

#include <gmock/gmock.h>
#include "gtest/gtest.h"

// Vazno!
using ::testing::_;
using ::testing::An;
using ::testing::AtLeast;





// ---- TEST FIXTURE ----
class Service0Test : public testing::Test
{
public:
    ServiceNameSpace::Service0If* service0;
    
    Service0Test()
    {}

    ~Service0Test()
    {}
    
    // Before Each Test
    void SetUp()
    {
        // ScanRef scanRef(0);
        service0 = new ServiceNameSpace::Service0("service0_Name");
    }
    // After Each Test
    void TearDown()
    {
        delete(service0);
    }
};




TEST_F(Service0Test, test_getObjectId) 
{ 
    std::string objectId("ServiceNameSpace::Service0");
    EXPECT_EQ(objectId, service0->getObjectId()); 
}


TEST_F(Service0Test, test_getObjectName) 
{ 
    std::string objectName("service0_Name");
    EXPECT_EQ(objectName, service0->getObjectName()); 
}


TEST_F(Service0Test, test_sampleInsertElement) 
{ 
    // Declaration input method parameters
    std::vector<std::string> vec0;
    std::string str0("1111");
    int position_begin = 0;
    // Method execution
    vec0 = service0->sampleInsertElement(str0, position_begin);
    // Test result
    EXPECT_EQ(str0, vec0.at(position_begin));
    EXPECT_EQ(vec0.size(), 4);
    
    std::vector<std::string>::iterator it;
    for(it = vec0.begin(); it != vec0.end(); ++it)
    {
        std::cout << *it << std::endl;
    }


    std::string str1("3333");
    int position_end = 3;
    vec0 = service0->sampleInsertElement(str1, position_end);   
    EXPECT_EQ(str1, vec0.at(position_end));
    
    for(it = vec0.begin(); it != vec0.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}


TEST_F(Service0Test, test_getVectorOfDummyStrings) 
{ 
    std::vector<std::string> vec0 = service0->getVectorOfDummyStrings();
    std::string str0("/home/Downloads");
    
    EXPECT_EQ(vec0.at(0), str0);
    
    EXPECT_THAT(vec0.at(0), ::testing::HasSubstr("/home/Downl"));
    EXPECT_THAT(vec0.at(0), ::testing::ContainsRegex("Downloads"));
    EXPECT_THAT(vec0.at(0), ::testing::StrNe("something"));

    std::vector<std::string> testVec;
    testVec.push_back("/home/Downloads");
    testVec.push_back("string 1");
    testVec.push_back("string 2");

    EXPECT_THAT(testVec, ::testing::ContainerEq(vec0));
    EXPECT_THAT(testVec, ::testing::Contains("string 1"));
    EXPECT_THAT(testVec, ::testing::ElementsAre("/home/Downloads", "string 1", "string 2"));
    EXPECT_THAT(testVec, ::testing::SizeIs(3));

    std::vector<std::string> testEmptyVec;
    EXPECT_THAT(testEmptyVec, ::testing::IsEmpty());
}


TEST_F(Service0Test, test_getDummyString) 
{ 
    // tesString = "this is dummy string"
    std::string tesString = service0->getDummyString();
    
    EXPECT_THAT(tesString, ::testing::ContainsRegex("is dummy")); // This should be some regex
    EXPECT_THAT(tesString, ::testing::EndsWith("dummy string"));
    EXPECT_THAT(tesString, ::testing::HasSubstr("this is dummy"));
    EXPECT_THAT(tesString, ::testing::StartsWith("this is dummy"));   
    EXPECT_THAT(tesString, ::testing::StrEq("this is dummy string"));
    EXPECT_THAT(tesString, ::testing::StrNe("this is not dummy string"));
}


TEST_F(Service0Test, test_FindDuplicates) 
{ 
    // Declaration input method parameters
    // std::vector<int> vecInt = { 1, 3, 3, 2, 4, 7};   // Ex 1
    std::vector<int> vecInt = { 1, 3, 2, 4, 7, 7};  // Ex 2
    int result = 0;
    // Method (template) execution
    service0->FindDuplicates<int, int>(vecInt, result); // Ex 1
    // Test result
    // EXPECT_EQ(result, 3); // Ex 1
    EXPECT_EQ(result, 7);   // Ex 2
}


// VAZNO: Ovo je TEST a ne TEST_F (fixture)
TEST(Test, test_findFileStatTest) 
{ 
    // Real data
    FileStat testData;  // Function param in service1 (m_ScanRef)
    testData.fileSize = 10010;    // Set some value
    
    // Mock data (service1) - Invokacija metoda unutar testne metode
    Service1Mock scanMock;  // Service1 mock
    
    // Real data  (service0)
    ServiceNameSpace::Service0 finderObj("service0_Name");
    finderObj.setService1If(&scanMock);
    
    std::vector<std::string> arg0;   
    arg0.push_back("OK");
    
    // EXPECT_CALL(scanMock, getList()).WillOnce(::testing::Return(arg0));
    // Ako vracamo referencu
    EXPECT_CALL( scanMock, getListRef()).WillOnce(::testing::ReturnRef(arg0));
 
    //EXPECT_CALL( scanMock, getFileStatistics(_,_)).WillOnce(::testing::SetArgReferee<1>(testData));
    EXPECT_CALL( scanMock, getFileStatistics2(_,_)).WillOnce(::testing::SetArgPointee<1>(testData));

    std::cout << "MOCK aSample.fileSize = " << testData.fileSize << std::endl;
    std::cout << "MOCK sampleVector.size() = " << arg0.size() << std::endl;
    
    std::string str = finderObj.findFileStatTest();

    EXPECT_EQ(str, "OK");   
}


// VAZNO: Ovo je TEST a ne TEST_F (fixture)
TEST(TestName_0, test_unitTest0) 
{ 
    // 1] Pogledamo imamo li  vanjske objekte (ako da, kreiramo mock)
    Service1Mock scanMock;
    
    // 2] Kreiranje testnog objekta
    ServiceNameSpace::Service0 finderObj("service0_Name");
    
    // 3] Moramo biti sigurni da smo predali pointer/referencu mock objekta
    // incae segmentation fault (core dump)
    // Real data  (service0)
    finderObj.setService1If(&scanMock);

    // 4] Pogledamo  koje parametre prima / sto mock objekt vraca
    // 5] Kreiramo EXPECT_CALL preko mock objekta i recemo sto da vrati mock
    int testInt = 17;
    EXPECT_CALL( scanMock, returnInt()).WillOnce(::testing::Return(testInt));
    
    int testInt0 = 19;
    std::string str0("expectedString");
    std::string str1("expectedString22");
    // Ocekujemo da ce se u testnoj funkciji returnInt0 poyvati s argumentima 7 i str0
    // EXPECT_CALL( scanMock, returnInt0(7, str0)).WillOnce(::testing::Return(testInt0) );
    EXPECT_CALL( scanMock, returnInt0(7, str0)).WillOnce( DoAll( ::testing::SetArgReferee<1>(str1), ::testing::Return(testInt0)) );
    // EXPECT_CALL( scanMock, returnInt0(_, str0)).WillOnce(::testing::SetArgReferee<1>(str1)).WillOnce(::testing::Return(testInt0));
    
    
    // 5] Provjerimo da li imamo jos poziva (mock) Ako da - EXPECT_CALL
    // 6] Pozivamo funkciju
    std::string str("Some_string_0");
    int returnInt = finderObj.unitTest0(str);
    std::cout << " > str from test_unitTest0: " << str << std::endl;

    EXPECT_EQ(returnInt, 0); 
    EXPECT_EQ(str, "fString"); 
}







