#include "Event_Handler.h"
// #include "Initiation_Dispatcher.h"


Reactor::Event_Handler::Event_Handler(int clientId) : m_clientId(clientId)
{
    std::cout << "[Event_Handler] Constructor called" << '\n';

};


Reactor::Event_Handler::~Event_Handler()
{
    std::cout << "[Event_Handler] Destructor called" << std::endl;
}


int Reactor::Event_Handler::handle_event(const std::string& eventType)
{
    std::cout << "[Event_Handler] handle_event called ..." << '\n';
};


int Reactor::Event_Handler::getClientId() const
{
    return m_clientId;
}


std::string Reactor::Event_Handler::send()
{
    std::string msg("Sending msg from handler: ");
    std::string retMsg = msg + std::to_string(m_clientId);

    return retMsg;
}


void Reactor::Event_Handler::toString()
{

}