# < ---- VARIABLES ---->
CXXFLAGS = -std=c++14

gmock = -lgmock
gmock_main = -lgmock_main

# < ---- FOLDER INCLUDEs ---->
libs = /home/marin/libs
googlemock = /home/marin/libs/googletest/googlemock/include
googletest = /home/marin/libs/googletest/googletest/include


# < ---- BUILD INFO ---->
# Build: make all           // all - build common_sources 
# Execute: ./App01      // Vazno [ ./ ] - Pokreni iz trenutnog foldera 

# sources 
common_sources = main.cpp \
                 sw/StartUp/src/StartUp.cpp \
                 sw/Container/src/Container.cpp \
                 sw/DesignPatterns/src/ServiceFactory.cpp \
                 sw/Services/src/Service0.cpp \
                 sw/Services/src/Service1.cpp \
                 sw/Services/src/ServiceCar.cpp \
                 sw/Services/src/ServiceCarParts.cpp \
                 sw/DesignPatterns/src/DriverFactory.cpp \
                 sw/DesignPatterns/src/BuilderPattern.cpp \
                 sw/DesignPatterns/src/AbstractFactory.cpp \
                 sw/Drivers/src/Driver0.cpp \

all:
	g++ $(CXXFLAGS) \
	$(common_sources) \
	$(gmock) \
	$(gmock_main) \
	-L $(libs)  \
	-I $(googlemock) \
	-I $(googletest) \
	-I sw/StartUp/if \
	-I sw/StartUp/inc \
	-I sw/Container/if \
	-I sw/Container/inc \
	-I sw/DesignPatterns/if \
	-I sw/DesignPatterns/inc \
	-I sw/Services/if \
	-I sw/Services/inc \
	-I sw/Drivers/if \
	-I sw/Drivers/inc \
	-o  App01 \


# < ---- BUILD INFO---->
# Build: make test        // all - build test_sources 
# Execute: ./gmockTest 

# test sources
test_sources = sw/Services/src/Service0.cpp \
               sw/Services/src/Service1.cpp \
               sw/Services/unitTest/testService0.cpp \

test:
	g++ $(CXXFLAGS) \
	$(test_sources) \
	$(gmock) \
	$(gmock_main) \
	-L $(libs)  \
	-I $(googlemock) \
	-I $(googletest) \
	-I sw/Services/if \
	-I sw/Services/inc \
	-I sw/Services/unitTest \
	-pthread  \
	-o gmockTest \
