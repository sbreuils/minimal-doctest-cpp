cmake_minimum_required(VERSION 3.9)

project(minimalBinomial CXX)
set(CMAKE_BUILD_TYPE Release)

# files to compile
set(source_files src/misc.cpp)
file(GLOB_RECURSE header_files src/*.hpp)

# display info
message(STATUS "  sources")
foreach(src_file ${source_files})
    message("          " ${source_files})
endforeach()
message(STATUS "  headers")
foreach(src_file ${header_files})
    message("          " ${src_file})
endforeach()

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    option(MINIMAL_ENABLE_TESTS "Enable compilation of tests" ON)
else()
    option(MINIMAL_ENABLE_TESTS "Disable compilation of tests" OFF)
endif()


# generate a library
if (MSVC)
	add_library(minimalBinomial ${source_files} ${header_files})
else()
	add_library(minimalBinomial ${source_files} ${header_files})
endif()


if (MSVC)   
    target_compile_features(minimalBinomial PRIVATE cxx_std_17) 
    target_compile_options(minimalBinomial PRIVATE -Wall -O2) 
else()
    target_compile_features(minimalBinomial PRIVATE cxx_std_17) 
    target_compile_options(minimalBinomial PRIVATE -Wall -O2 -Wno-return-local-addr)
endif()
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftime-report ") # comilation profiling:  -Q -ftime-report
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors") # force the compilor to use our move 'copy constructor'

# include directory path
include_directories(src)

if(MINIMAL_ENABLE_TESTS)
    message("test enabled")
    enable_testing()
    add_subdirectory(test)
endif()

# 
# install lib
install(FILES ${header_files} ${source_files} DESTINATION /usr/local/include/minimalBinomial)
install(TARGETS minimalBinomial
        RUNTIME DESTINATION /usr/local/bin
        LIBRARY DESTINATION /usr/local/lib
        ARCHIVE DESTINATION /usr/local/lib)