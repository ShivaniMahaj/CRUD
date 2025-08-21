cmake_minimum_required(VERSION 3.16)
project(EmployeeMongoCRUD)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# MongoDB C++ driver
find_package(mongocxx CONFIG REQUIRED)
find_package(bsoncxx CONFIG REQUIRED)

add_executable(EmployeeMongoCRUD
    CRUD.cpp
    Menu.cpp
    Employee.cpp
    Menu.hpp
    Employee.hpp
)

# Force output to match Visual Studio's default path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/x64/$<CONFIG>")
set_target_properties(EmployeeMongoCRUD PROPERTIES
    OUTPUT_NAME "CRUD"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/x64/$<CONFIG>"
)
# Link using vcpkg-exported targets
if (TARGET mongo::mongocxx_shared AND TARGET mongo::bsoncxx_shared)
    target_link_libraries(EmployeeMongoCRUD
        PRIVATE
        mongo::mongocxx_shared
        mongo::bsoncxx_shared
    )
elseif (TARGET mongo::mongocxx_static AND TARGET mongo::bsoncxx_static)
    target_link_libraries(EmployeeMongoCRUD
        PRIVATE
        mongo::mongocxx_static
        mongo::bsoncxx_static
    )
else()
    message(FATAL_ERROR "No suitable mongocxx/bsoncxx targets found.")
endif()
