#pragma once
#include "Event_Handler_If.h"


namespace Reactor
{
class Logging_Acceptor : public  Event_Handler_If
{
public:
	Logging_Acceptor(int id);

    ~Logging_Acceptor();

    int handle_event (const std::string& eventType);

private:	
int m_id;
};
} // End of namespace