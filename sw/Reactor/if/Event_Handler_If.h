#pragma once
#include <string.h>
#include <iostream>


namespace Reactor
{
class Event_Handler_If
// = TITLE
// Abstract base class that serves as the
// target of the Initiation_Dispatcher.
{
public:
    virtual ~Event_Handler_If() 
    {
        std::cout << "[Event_Handler_If][~Event_Handler_If]" << std::endl;
    }

    // Hook method that is called back by the
    // Initiation_Dispatcher to handle events.
    virtual int handle_event (const std::string& eventType) = 0;
    // Hook method that returns the underlying
    // I/O Handle.
    // virtual Handle get_handle (void) const = 0;
};
} // End of Namespace