# Hello Build System

## 📦 Repository Structure
```
hello-build-system/
├── CMakeLists.txt    ← Build configuration (committed)
├── README.md         ← Documentation (committed)
├── .gitignore        ← Git ignore rules (committed)
├── include/
│   └── utils.h       ← Headers (committed)
├── src/
│   ├── main.cpp      ← Source files (committed)
│   └── utils.cpp     ← Source files (committed)
└── build/            ← Generated files (NOT committed)
```

## 🎯 Project Goal
Understanding C++ compilation process, build systems(CMake), and project organization fundamentals.

## 🧠 Concepts Covered
1. **Separate Compilation**: Breaking code into multiple translation units
2. **Header Guards**: Preventing multiple inclusion
3. **Makefiles**: Automating build process
4. **Linking**: Combining object files into executable
5. **Out-of-source Builds**: Keeping build artifacts separate from source

## 📚 What I Learned

### 1. Compilation Stages
```
Source (.cpp) → Preprocessor → Compiler → Assembler → Object (.o) → Linker → Executable
```
```
### 1. What is CMake?
CMake is NOT a build system - it's a **build system generator**

CMakeLists.txt → CMake → Makefile/Visual Studio/Ninja → Executable
                  (generates)       (actual build system)
```

**Why separate compilation?**
- ✅ Faster rebuilds (only changed files recompile)
- ✅ Better code organization
- ✅ Reusable components
- ❌ Tradeoff: More complex build process

### 2. Header Guards
**Problem**: Without guards, including same header twice causes redefinition errors
**Solutions**:
- `#ifndef` / `#define` / `#endif` (traditional, portable)
- `#pragma once` (modern, compiler-specific)

**Tradeoff**: 
- Traditional guards: More verbose but standard-compliant
- `#pragma once`: Cleaner but not in C++ standard (though widely supported)

### 3. Makefile Automation
**Manual compilation** (tedious for large projects):
```bash
g++ -c src/main.cpp -I include -o build/main.o
g++ -c src/utils.cpp -I include -o build/utils.o
g++ build/main.o build/utils.o -o build/program
```

**Makefile benefits**:
- Automatic dependency tracking
- Incremental builds
- Single command compilation

## 🏗️ Build Instructions

### First Time Setup
```bash
# Step 1: Configure - Generate build files
cmake -B build

# What happens:
# - CMake reads CMakeLists.txt
# - Detects compiler (g++, clang++, MSVC)
# - Generates Makefile (or Ninja/VS project)
# - Creates build/ directory
```

### Building
```bash
# Step 2: Build - Compile everything
cmake --build build

# What happens:
# - Runs the generated build system
# - Compiles changed files only (incremental build)
# - Links object files into executable
```

### Running
```bash
# Run the program
./build/program

# On Windows:
# .\build\Debug\program.exe
```

### Cleaning
```bash
# Clean build artifacts (keeps CMake cache)
cmake --build build --target clean

# Complete clean (delete entire build folder)
rm -rf build
```

### Rebuilding
```bash
# Clean and rebuild
rm -rf build
cmake -B build
cmake --build build
```
###  CMake Build Types
```bash
# Debug: No optimization, includes debug symbols
cmake -B build -DCMAKE_BUILD_TYPE=Debug

# Release: Full optimization, no debug symbols
cmake -B build -DCMAKE_BUILD_TYPE=Release
```

## 📂 File Explanations

### `include/utils.h`
- **Purpose**: Function declarations (interface)
- **Key concept**: Separation of interface and implementation
- **Interview point**: Headers should contain declarations, not definitions (to avoid ODR violations)

### `src/utils.cpp`
- **Purpose**: Function implementations
- **Key concept**: Implementation hiding
- **Interview point**: Changing implementation doesn't require recompiling other files

### `CMakeLists.txt`
- **Purpose**: Build configuration (like a recipe)
- **Key concept**: Declarative build specification
- **Interview point**: CMake is platform-agnostic; same file works on Windows/Linux/Mac
