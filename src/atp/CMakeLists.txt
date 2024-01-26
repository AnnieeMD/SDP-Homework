add_library(atp)

target_include_directories(
    atp
    PUBLIC
    include/
)

target_sources(
    atp
    PUBLIC
    ATPElement.cpp
    ATPTreeGenerator.cpp
    Commands.cpp
    Runner.cpp
)