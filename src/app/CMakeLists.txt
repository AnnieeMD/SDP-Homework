add_executable(
    app
)

target_link_libraries(
    app
    PUBLIC
    atp
)

target_sources(
    app
    PUBLIC
    main.cpp
)