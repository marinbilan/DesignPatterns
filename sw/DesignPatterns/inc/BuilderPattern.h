#pragma once
#include "BuilderPatternIf.h"


namespace DesignPatternsNamespace
{

// U ovom slucaju Product je DesignPattern koji se builda Builderom u njemu
class BuilderPattern : public DesignPatternsNamespace::BuilderPatternIf
{
public:
    BuilderPattern();
    
    BuilderPattern(int i, float f);
    
    ~BuilderPattern();
    
    std::string getName();
    
    void printProductInfo();
    
    void print();


    // <---- Builder START ---->
    /* Moze se kreirati class Builder van Producta 
    // Ali se mora deklarirati unutar kao class Builder; 
    // Pogledati wikipediju
    BuilderPattern::Builder 
    { 
        // ... 
    } 
    */

    class Builder 
    { 
    public: 
        Builder() : i(defaultI), f(defaultF) 
        { 
            std::cout << "Builder constructor called " << this << std::endl; 
        } 
        
        // Set partial variable 
        Builder& setI(int i) 
        { 
            this->i = i; 
            return *this; 
        } 

        // Set partial variable 
        Builder& setF(float f) 
        { 
            this->f = f; 
            return *this; 
        } 

        // Set particular product A 
        Builder& setProductA(){ 
            i = 42; 
            f = -1.0f/12.0f; 

            return *this; 
        } 

        // Set particular product B 
        Builder& setProductB(){ 
            i = 423; 
            f = -1.0f/122.0f; 
            return *this; 
        } 

        // Produce desired BuilderPattern 
        BuilderPattern build() 
        { 
            // Here, optionaly check variable consistency 
            // and also if BuilderPattern is buildable from given information 

            return BuilderPattern( i, f ); 
        } 

    private: 
    // Variable values - Same as outside (BuilderPattern) object! 
    int i; 
    float f; 
    // Default constructor values (Default Constructor) 
    static constexpr int defaultI = 1; 
    static constexpr float defaultF = 3.1415f; 
    }; 
    // <---- Builder STOP ---->


private:
static const std::string objectID;

// Varijable iste kao I u Builder objektu! (Za setiranje) 

int m_i; 
float m_f;
};

} // End of namespace