cmake_minimum_required(VERSION 3.23)
project(sample_1)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS thread REQUIRED)

#### Begin - OpenMP config for Apple M1 and Intel.
if( CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin" AND CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "arm64" )
    execute_process(
            COMMAND brew --prefix libomp
            RESULT_VARIABLE BREW_LIBOMP
            OUTPUT_VARIABLE BREW_LIBOMP_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_LIBOMP EQUAL 0 AND EXISTS "${BREW_LIBOMP_PREFIX}")
        message(STATUS "Found OpenMP keg installed by Homebrew at ${BREW_LIBOMP_PREFIX}")
        set(OPENMP_PATH "${BREW_LIBOMP_PREFIX}")
    endif()

    find_library(OpenMP REQUIRED NAMES "omp" PATHS "${OPENMP_PATH}/lib" NO_DEFAULT_PATH)

else()
    find_package(OpenMP REQUIRED PATHS OPENMP_PATH )
endif()
#### End - OpenMP

if(Threads)
    find_package_message(Threads "Found Threads: ${Threads}")
endif()

# Targets
set(SOURCES
        main.cpp
        )
add_executable(main.cpp ${SOURCES} )
