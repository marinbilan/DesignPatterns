#include "Driver0If.h"


namespace DriverNameSpace
{

class Driver0 : public DriverNameSpace::Driver0If
{
public:
	void init();

	static DefaultDriver* creator();

	static bool registeredInDrvFactory;
    
private:
std::string m_name;
};

}   // End of  namespace