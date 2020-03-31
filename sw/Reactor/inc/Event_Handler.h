#pragma once
#include "Event_Handler_If.h"


namespace Reactor
{
class Event_Handler : public  Event_Handler_If
{
public:
	Event_Handler(int id);

    ~Event_Handler();

    int handle_event(const std::string& eventType);

    int getClientId() const;

    std::string send();

    void toString();

private:	
int m_id;
};
} // End of namespace