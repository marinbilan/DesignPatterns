#include "Service0If.h"
#include "Service0.h"

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
