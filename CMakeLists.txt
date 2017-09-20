cmake_minimum_required(VERSION 3.6)
project(Hw01)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
if (MSVC)
    # Force to always compile with W4
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else ()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif ()
elseif (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif ()


set(CMAKE_CXX_STANDARD 14)

set(SRC_MAIN_FILES src/main/cpp/Main.cpp)
set(SRC_DEMO_FILES src/main/cpp/Demo.cpp)
set(SRC_TEST_FILES src/test/cpp/UnitTestRunner.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)

add_executable(Hw01 ${SRC_MAIN_FILES})
add_executable(Hw01Demo ${SRC_DEMO_FILES})
add_executable(Hw01Test ${SRC_TEST_FILES})

if (APPLE)
    include_directories(Hw01Test PUBLIC /usr/local/include)
endif (APPLE)

target_link_libraries(Hw01Test PUBLIC ${CPPUNIT_LIBRARY})
