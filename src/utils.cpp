// ============================================
// CONCEPT: Implementation File
// ============================================
// This file DEFINES the functions declared in utils.h

#include "utils.h"  // Include our own header
// Why? To ensure declarations match definitions
// Compiler will error if signatures don't match

#include <sstream>  // For string concatenation

// ============================================
// Function Definitions
// ============================================

int add(const int a, const int b) {
    // Simple addition
    // Interview point: For such simple operations, compiler likely
    // inlines this if optimization is enabled (-O2, -O3)
    // Tradeoff: Separate function (clear) vs inline (faster)
    
    return a + b;
}

std::string greet(const std::string& name) {
    // Why ostringstream instead of string concatenation?
    // - More efficient for multiple concatenations
    // - Type-safe
    // - Tradeoff: Slight overhead for simple cases
    
    std::ostringstream oss;
    oss << "Hello, " << name << "! Welcome to C++ build systems.";
    
    // Alternative (simpler but less efficient for complex cases):
    // return "Hello, " + name + "! Welcome to C++ build systems.";
    
    return oss.str();
}

// Interview Point: Why not define functions in header?
// 1. If defined in header, every file including it gets a copy
//    → Multiple definitions → Linker error (ODR violation)
// 2. Exception: inline functions (compiler merges them)
// 3. Templates are defined in headers (need to be visible for instantiation)