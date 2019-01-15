#include "DriverFactory.h"
#include "Driver0.h"


REGISTER_DRIVER_IN_DRV_FACTORY(DriverNameSpace::Driver0)


void DriverNameSpace::Driver0::init()
{
	std::cout << "Calling init() from class Driver0" << std::endl;
}

DriverNameSpace::DefaultDriver* DriverNameSpace::Driver0::creator()
{
	std::cout << "Driver0 creator called" << std::endl;
	return new Driver0();
}