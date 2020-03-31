#pragma once
#include "Event_Handler_If.h"


// TODO: Remove this
class EventHandler
{
public:
    EventHandler(int clientId) : m_clientId(clientId)
    {
        std::cout << "EventHandler created. clientId: " << m_clientId << '\n';
    }

    ~EventHandler()
    {
        std::cout << "EventHandler removed. clientId: " << m_clientId << '\n';
    }

    int getClientId() const
    {
        return m_clientId;
    }

    std::string send()
    {
        std::string msg("Sending msg from handler: ");
        std::string retMsg = msg + std::to_string(m_clientId);

        return retMsg;
    }

    void toString()
    {
        std::cout << "EventHandler clientId: " << m_clientId << '\n';
    }

private:
int m_clientId;
};


namespace Reactor
{
class Logging_Acceptor : public  Event_Handler_If
{
public:
	Logging_Acceptor(int id);

    ~Logging_Acceptor();

    int handle_event(const std::string& eventType);

    // TODO: Add Event Handler in separate class
    void register_EventHandler(int clientId);

    std::vector<EventHandler*>& get_EventHandlerVec();

    void get_EventHandler(int clientId);

private:	
int m_id;

std::vector<EventHandler*> m_vecOfEventHandler;
};
} // End of namespace