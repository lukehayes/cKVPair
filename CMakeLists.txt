cmake_minimum_required(VERSION 3.2)
project(cKVPair)

# -----------------------------------------------------------------------------
# Set Variables
# 
set(CMAKE_C_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(INCLUDE_DIRS "include")
set(BIN_NAME "KVPair")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(CMAKE_C_FLAGS  "-Wall -fno-strict-aliasing")
 

# -----------------------------------------------------------------------------
# Set the project include directories.
# 
include_directories(${INCLUDE_DIRS})


# -----------------------------------------------------------------------------
# Create the final binary
# 
add_executable(${BIN_NAME} main.c)


# -----------------------------------------------------------------------------
# Build the Toml Parser Library
# 
set(cKVPairLib "cKVPair")

add_library(${cKVPairLib} STATIC
  "${SRC_DIR}/kvmap.c"
)

# -----------------------------------------------------------------------------
# Link the libraries
# 
target_link_libraries(${BIN_NAME} ${cKVPairLib})
target_link_libraries(${BIN_NAME} ${PROJECT_SOURCE_DIR}/lib/libCIO.a)
target_link_libraries(${BIN_NAME} ${PROJECT_SOURCE_DIR}/lib/libcStr.a)

