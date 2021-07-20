cmake_minimum_required(VERSION 3.4)


project(biblioteka)


#Source files go here
set(SOURCE_FILES

        src/Ball.cpp include/Ball.hpp
        src/Mike.cpp include/Mike.hpp
        src/Abibas.cpp include/Abibas.hpp
        src/Client.cpp include/Client.hpp
        src/Rents.cpp include/Rents.hpp
        src/ClientType.cpp include/ClientType.hpp
        include/Respository.hpp
        src/RentsRespository.cpp include/RentsRespository.hpp
        src/ClientRespository.cpp include/ClientRespository.hpp
        src/OrlikManager.cpp include/OrlikManager.hpp
        src/Orlik.cpp include/Orlik.hpp
        src/NewClient.cpp include/NewClient.hpp
        src/RegularClient.cpp include/RegularClient.hpp
        src/NormalClient.cpp include/NormalClient.hpp
        src/RentsException.cpp include/RentsException.hpp
        src/ClientException.cpp include/ClientException.hpp
        src/BallException.cpp include/BallException.hpp)

#utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(biblioteka ${SOURCE_FILES})


target_include_directories(biblioteka PUBLIC include)

#BOOST
enable_testing() 

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
 ${CMAKE_CURRENT_SOURCE_DIR}/include
 ${Boost_INCLUDE_DIRS}
)

#Test source files here
set(SOURCE_TEST_FILES
        test/master.cpp
        test/BasicTest.cpp
        test/ModelTest.cpp
        src/Ball.cpp include/Ball.hpp
        src/Mike.cpp include/Mike.hpp
        src/Abibas.cpp include/Abibas.hpp
        src/Client.cpp include/Client.hpp
        src/Rents.cpp include/Rents.hpp
        src/ClientType.cpp include/ClientType.hpp
        include/Respository.hpp
        src/RentsRespository.cpp include/RentsRespository.hpp
        src/ClientRespository.cpp include/ClientRespository.hpp
        src/OrlikManager.cpp include/OrlikManager.hpp
        src/Orlik.cpp include/Orlik.hpp
        src/NewClient.cpp include/NewClient.hpp
        src/RegularClient.cpp include/RegularClient.hpp
        src/NormalClient.cpp include/NormalClient.hpp
        src/RentsException.cpp include/RentsException.hpp
        src/ClientException.cpp include/ClientException.hpp
        src/BallException.cpp include/BallException.hpp)

add_executable (TestBibl ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami do programu testów
target_link_libraries (TestBibl
 biblioteka
 ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
 )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele. 
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(TestBiblioteki1 TestBibl
 --report_level=detailed
 --log_level=all
 --color_output=yes
 )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})


