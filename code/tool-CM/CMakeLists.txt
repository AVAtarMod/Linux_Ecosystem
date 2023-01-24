cmake_minimum_required(VERSION 3.0) # setting this is required
project("Component Storage")            # this sets the project name

set(sources main.cpp storage/orm.h storage/secrets.h storage/storage.cpp storage/storage.h)

add_executable(component.app)

target_sources(component.app PRIVATE ${sources})
target_compile_options(component.app PUBLIC -std=c++11 -Wall -Wfloat-conversion)
target_include_directories(component.app PUBLIC ../lib)
target_link_libraries(component.app PUBLIC pq)

install(TARGETS component.app)

configure_file(example.json . COPYONLY)
