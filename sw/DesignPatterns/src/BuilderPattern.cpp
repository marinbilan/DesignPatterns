#include "BuilderPattern.h"


const std::string DesignPatternsNamespace::BuilderPattern::objectID= "BuilderPattern"; 

DesignPatternsNamespace::BuilderPattern::BuilderPattern()
{
    std::cout << "[BuilderPattern][BuilderPattern()] Constructor called" << std::endl;
}


DesignPatternsNamespace::BuilderPattern::BuilderPattern(int i, float f) : m_i(i), m_f(f)
{
    std::cout << "[BuilderPattern][BuilderPattern(int i, float f)] Constructor called" << std::endl;
}


DesignPatternsNamespace::BuilderPattern::~BuilderPattern()
{
    std::cout << "[BuilderPattern] Destructor called" << std::endl;
}


std::string DesignPatternsNamespace::BuilderPattern::getName()
{
    return objectID;
}


void DesignPatternsNamespace::BuilderPattern::printProductInfo()
{
    std::cout << "[BuilderPattern][printProductInfo]" << std::endl;
    std::cout << "Product this = " << this << std::endl;
}


void DesignPatternsNamespace::BuilderPattern::print()
{
    std::cout << "[BuilderPattern][print]" << std::endl;
    std::cout << "Product internals info:" << std::endl; 
    std::cout << "i: " << m_i << std::endl; 
    std::cout << "f: " << m_f << std::endl;
}