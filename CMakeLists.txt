###########################################################################
# CMakeLists.txt generated for component myadd
# Product type: STATIC library
###########################################################################
cmake_minimum_required(VERSION 3.18)

project("matlab-codegen-playground")

# Propagate the CMAKE_EXPORT_COMPILE_COMMANDS variable from the 
# environment if it is defined as an environment variable, but not as a 
# CMake variable. This is to work around a bug in CMake 3.19 when the 
# "NMake Makefiles" generator is selected.
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


# ###########################################################################
# ## Path variables
# ###########################################################################
# # Derive an absolute path to the code generation anchor folder.
# get_filename_component(START_DIR . ABSOLUTE)

# # Special directories defined by using CACHE variables can be overridden 
# # by setting the variable from the command line, e.g.,
# # 
# # 	cmake . -DMATLAB_ROOT=/path/to/another/matlab/root
# set(MATLAB_ROOT /MATLAB CACHE PATH "")

# # Additional variables that are defined conditionally.
# if("${CMAKE_CURRENT_BINARY_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
#     set(BINARY_START_DIR "${START_DIR}")
# else()
#     set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
# endif()

###########################################################################
## System Libraries
###########################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES} ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

###########################################################################
## Target definition and commands
###########################################################################

# Definition of target "myadd".
add_library(myadd STATIC 
    "src/myadd/myadd_initialize.cpp"
    "src/myadd/myadd_terminate.cpp"
    "src/myadd/myadd.cpp"
    "src/myadd/conv.cpp"
)

# Set properties for target "myadd".
set_target_properties(myadd PROPERTIES PREFIX ""
    POSITION_INDEPENDENT_CODE ON
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/./$<0:>"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/./$<0:>"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/./$<0:>"
)

# Specify language features required for target "myadd".
target_compile_features(myadd PUBLIC cxx_std_11)

# Specify compiler preprocessor definitions for target "myadd".
# target_compile_definitions(myadd PRIVATE -DMODEL=myadd)

# Specify include directories for target "myadd".
target_include_directories(myadd PUBLIC    
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/myadd>
    $<INSTALL_INTERFACE:/myadd>
)

# Specify library link dependencies for target "myadd". CMake generator 
# expressions are used to create a CMakeLists.txt file that supports 
# multiple platforms with differently named system library dependencies.
target_link_libraries(myadd PUBLIC $<$<BOOL:${FOUND_LIBM}>:m>)


###########################################################################
## Build success message
###########################################################################
add_custom_command(TARGET myadd POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created STATIC library: $<TARGET_FILE:myadd>")

# ###########################################################################
# ## Call toolchain hook function if defined
# ###########################################################################
# if(COMMAND toolchain_target_hook)
#     toolchain_target_hook(myadd)
# endif()





# find_package(portaudio 19 EXACT REQUIRED) # PATHS "P:\\Downloads\\cpp-libraries\\portaudio\\build\\cmake\\portaudio")

# if(portaudio_FOUND)
#     message(STATUS "YES")
# else()
#     message(STATUS "NO")
# endif()

add_executable(${PROJECT_NAME}
    "src/main.cpp"
    "src/main.h"
    "src/rtwtypes.h"
)

target_link_libraries(${PROJECT_NAME} myadd)
target_link_options(${PROJECT_NAME} PRIVATE "-static")
