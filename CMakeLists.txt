cmake_minimum_required(VERSION 3.10)
project(SharedCLib C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add executable
add_executable(sharedclib
    main.c
    common.c
    string.c
    stack.c
    queue.c
    list.c
    dictionary.c
    tests.c
)

# Include directories
target_include_directories(sharedclib PRIVATE .)