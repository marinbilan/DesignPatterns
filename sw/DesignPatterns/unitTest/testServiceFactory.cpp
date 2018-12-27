#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include <gmock/gmock.h>
#include "gtest/gtest.h"

#include "BaseIf.h"
#include "FactoryIf.h"
#include "ServiceFactory.h"

// Vazno!
using ::testing::_;
using ::testing::An;
using ::testing::AtLeast;


// ---- TEST FIXTURE ----
class TestFactory : public testing::Test
{
public:
    BaseIf* factory0;
    
    TestFactory()
    {}

    ~TestFactory()
    {}
    
    // Before Each Test
    void SetUp()
    {
        factory0 = new DesignPatterns::ServiceFactory(11);
    }
    // After Each Test
    void TearDown()
    {
        delete factory0;
    }
};


// TEST_F Only when object is created in FIXTURE
TEST_F(TestFactory, testFactorySetUpTearDown)
{   
    std::string str0("ServiceFactory");
 
    EXPECT_EQ(factory0->getName(), str0);
}