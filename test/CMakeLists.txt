cmake_minimum_required(VERSION 3.13)

include(CTest)

add_executable(Tests testsForATPElement.cpp 
                     testsForATPTreeGenerator.cpp 
                     testsForCommands.cpp
                     testForRunner.cpp)
                
target_link_libraries(Tests atp)
