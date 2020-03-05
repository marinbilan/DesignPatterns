#include "Logging_Acceptor.h"


Reactor::Logging_Acceptor::Logging_Acceptor(int id) : m_id(id)
{
    std::cout << "[Logging_Acceptor] Constructor called" << '\n';
};


Reactor::Logging_Acceptor::~Logging_Acceptor()
{
    std::cout << "[Logging_Acceptor] Destructor called" << std::endl;
}


int Reactor::Logging_Acceptor::handle_event(const std::string& eventType)
{
    std::cout << "[Logging_Acceptor] handle_event called ..." << '\n';
};