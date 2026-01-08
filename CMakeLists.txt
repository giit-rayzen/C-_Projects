# ============================================
# CMake Version Requirement
# ============================================
# Specifies minimum CMake version needed
# Why 3.10? Good balance of features and compatibility
# Interview Point: Different versions have different features
# Use 'cmake --version' to check your version

cmake_minimum_required(VERSION 3.10)

# ============================================
# Project Declaration
# ============================================
# Defines project name, version, and languages
# PROJECT_NAME variable automatically set to "HelloBuildSystem"
# Why C++? Tells CMake to find a C++ compiler

project(HelloBuildSystem VERSION 1.0 LANGUAGES CXX)

# ============================================
# C++ Standard Setting
# ============================================
# Set C++ standard to C++17
# CMAKE_CXX_STANDARD: Which C++ version to use
# CMAKE_CXX_STANDARD_REQUIRED: Fail if compiler doesn't support it
# CMAKE_CXX_EXTENSIONS: OFF means no compiler-specific extensions (portable)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Interview Point: Why C++17?
# - Modern features (auto, lambdas, constexpr)
# - Widely supported by compilers
# - Good balance of features and compatibility
# Tradeoff: C++20/23 have more features but less compiler support

# ============================================
# Include Directories
# ============================================
# Tell CMake where to find header files
# Now all source files can do: #include "utils.h"
# ${CMAKE_SOURCE_DIR}: Root directory of project (where this file is)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Interview Point: Why include_directories()?
# - All targets automatically get this include path
# - Alternative: target_include_directories() (more modern, target-specific)
# Tradeoff: Global vs per-target includes

# ============================================
# Executable Target Definition
# ============================================
# Creates an executable named "program"
# Lists all source files needed

add_executable(program
    src/main.cpp
    src/utils.cpp
)

# What happens behind the scenes:
# 1. CMake generates commands to compile each .cpp file
# 2. Automatically scans for #include dependencies
# 3. Links all object files into final executable
# 4. Output location: build/program (or build/Debug/program.exe on Windows)

# Interview Point: Why list all source files?
# - CMake needs to know what to compile
# - Alternative: file(GLOB ...) to auto-find files
# - Tradeoff: Explicit listing (manual) vs GLOB (risky - CMake won't detect new files)

# ============================================
# OPTIONAL: Compiler Warnings (Best Practice)
# ============================================
# Uncomment to enable strict warnings

# target_compile_options(program PRIVATE
#     $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
#     $<$<CXX_COMPILER_ID:MSVC>:/W4>
# )

# Explanation:
# -Wall -Wextra: Enable most warnings (GCC/Clang)
# /W4: High warning level (MSVC/Windows)
# Generator expressions: $<...> work at build time
# PRIVATE: Only applies to this target, not consumers

# Interview Point: Why warnings?
# - Catch bugs early
# - Enforce good practices
# - Industry standard: "warnings as errors" (-Werror)

# ============================================
# OPTIONAL: Build Type Messages
# ============================================
# Show what build type is being used

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Project source dir: ${CMAKE_SOURCE_DIR}")
message(STATUS "Project binary dir: ${CMAKE_BINARY_DIR}")

# Explanation:
# CMAKE_BUILD_TYPE: Debug, Release, RelWithDebInfo, MinSizeRel
# CMAKE_BINARY_DIR: Where build files go (build/)
# message(STATUS ...): Prints during configuration step

# ============================================
# COMPARISON: What CMake Replaces
# ============================================
# 
# This CMakeLists.txt replaces this Makefile:
#
# CXX = g++
# CXXFLAGS = -std=c++17 -Wall -Wextra -I include
# OBJS = build/main.o build/utils.o
# TARGET = build/program
# 
# all: $(TARGET)
# 
# $(TARGET): $(OBJS)
#     $(CXX) $^ -o $@
# 
# build/main.o: src/main.cpp include/utils.h
#     $(CXX) $(CXXFLAGS) -c $< -o $@
# 
# build/utils.o: src/utils.cpp include/utils.h
#     $(CXX) $(CXXFLAGS) -c $< -o $@
#
# CMake advantages:
# ✅ Automatic dependency detection (#include scanning)
# ✅ Cross-platform (Windows, Linux, Mac)
# ✅ Less error-prone (no manual dependency lists)
# ✅ Better IDE integration

# ============================================
# COMMON COMMANDS YOU'LL USE
# ============================================
#
# add_executable(name sources...)
#   - Creates an executable target
#
# add_library(name [STATIC|SHARED] sources...)
#   - Creates a library target
#
# target_include_directories(target PUBLIC include/)
#   - Adds include paths to a specific target
#
# target_link_libraries(target library1 library2...)
#   - Links libraries to a target
#
# find_package(LibraryName REQUIRED)
#   - Finds and imports external libraries
#
# set(VAR value)
#   - Sets a CMake variable
#
# message(STATUS "text")
#   - Prints a message during configuration

# ============================================
# INTERVIEW TALKING POINTS
# ============================================
#
# Q: What's the difference between cmake and make?
# A: - CMake is a build system GENERATOR
#    - It creates Makefiles (or Ninja/VS files)
#    - Then you use make/ninja to actually build
#    - Analogy: CMake is the architect, Make is the builder
#
# Q: Why use CMake instead of Makefile?
# A: - Cross-platform (one file for all OSes)
#    - Automatic dependency detection
#    - Better IDE integration
#    - Industry standard for C++ projects
#
# Q: What's the build/ directory?
# A: - Out-of-source build directory
#    - Keeps source tree clean
#    - Can have multiple build dirs (build-debug, build-release)
#    - Safe to delete and regenerate anytime
#
# Q: How does incremental build work?
# A: - CMake tracks file timestamps
#    - Only recompiles changed .cpp files
#    - Automatically handles header dependencies
#    - Much faster than rebuilding everything
