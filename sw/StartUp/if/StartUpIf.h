#pragma once
#include "StartUpBaseIf.h"


namespace StartUpNameSpace
{

class StartUpIf  : public StartUpBaseIf
{
public:
    virtual ~StartUpIf() {}
  
    virtual std::string getName() = 0;

};

}