# < ---- VARIABLES ---->
# -Wall -Werror 
CXXFLAGS = -g -std=c++14

gmock = -lgmock
gmock_main = -lgmock_main

# < ---- FOLDER INCLUDEs ---->
# libgmock.a and libgmock_main.a
libs = GTestLibs
# gMock
googlemock = GTestLibs/googletest/googlemock/include
# gTest
googletest = GTestLibs/googletest/googletest/include


# < ---- BUILD INFO ---->
# Build: make all       // all - build common_sources 
# Execute: ./App01      // Vazno [ ./ ] - Pokreni iz trenutnog foldera 

# sources 
common_sources = main.cpp \
                 sw/StartUp/src/StartUp.cpp \
                 sw/Container/src/Container.cpp \
                 sw/DesignPatterns/src/HighFactory.cpp \
                 sw/Highs/src/Service0.cpp \
                 sw/Highs/src/Service1.cpp \
                 sw/DesignPatterns/PatternsServices/src/ServiceCar.cpp \
                 sw/DesignPatterns/PatternsServices/src/ServiceCarParts.cpp \
                 sw/DesignPatterns/src/DriverFactory.cpp \
                 sw/DesignPatterns/src/BuilderPattern.cpp \
                 sw/DesignPatterns/src/AbstractFactory.cpp \
                 sw/Lows/src/Driver0.cpp \
                 sw/EffectiveModernCpp/src/Chapter5.cc \

all:
	g++ $(CXXFLAGS) \
	$(common_sources) \
	$(-lgmock) \
	$(-lgmock_main) \
	-L $(libs)  \
	-I $(googlemock) \
	-I $(googletest) \
	-I sw/StartUp/if \
	-I sw/StartUp/inc \
	-I sw/Container/if \
	-I sw/Container/inc \
	-I sw/Highs/if \
	-I sw/Highs/inc \
	-I sw/DesignPatterns/if \
	-I sw/DesignPatterns/inc \
	-I sw/DesignPatterns/PatternsServices/if \
	-I sw/DesignPatterns/PatternsServices/inc \
	-I sw/EffectiveModernCpp/if \
	-I sw/EffectiveModernCpp/inc \
	-I sw/Lows/if \
	-I sw/Lows/inc \
	-o  App01 \


# < ---- BUILD INFO---->
# Build: make test        // all - build test_sources 
# Execute: ./gmockTest 

# test sources
test_sources = sw/Highs/src/Service0.cpp \
               sw/Highs/src/Service1.cpp \
               sw/Highs/unitTest/testService0.cpp \

test:
	g++ $(CXXFLAGS) \
	$(test_sources) \
	$(gmock) \
	$(gmock_main) \
	-L $(libs)  \
	-I $(googlemock) \
	-I $(googletest) \
	-I sw/Highs/if \
	-I sw/Highs/inc \
	-I sw/Highs/unitTest \
	-pthread  \
	-o gmockTest \
