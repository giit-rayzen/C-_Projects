#include <iostream>
#include "utils.h"  // Our custom header
// Note: Use quotes for local headers, <> for system headers

// ============================================
// CONCEPT: Main Entry Point
// ============================================

int main() {
    // ============================================
    // Testing our utility functions
    // ============================================
    
    // Test 1: Integer addition
    int result = add(5, 7);
    std::cout << "5 + 7 = " << result << std::endl;
    
    // Test 2: String greeting
    std::string s;
    std::cin>>s;
    std::string message = greet(s);
    std::cout << message << std::endl;
    
    // Interview Point: Return value of main()
    // - 0 means success (convention in Unix/Linux)
    // - Non-zero means error
    // - OS uses this for error handling in scripts
    return 0;
}

// ============================================
// COMPILATION WALKTHROUGH
// ============================================
// 
// Step 1: Preprocessing
// g++ -E main.cpp -I include > main.i
// - Expands #include directives
// - Handles macros
// - Result: Pure C++ code (no preprocessor directives)
//
// Step 2: Compilation
// g++ -S main.cpp -I include
// - Converts C++ to assembly (main.s)
// - Performs optimization
// - Does syntax checking
//
// Step 3: Assembly
// g++ -c main.cpp -I include -o build/main.o
// - Converts assembly to machine code
// - Creates object file (.o)
// - Not yet executable (has unresolved references)
//
// Step 4: Linking
// g++ build/main.o build/utils.o -o build/program
// - Resolves external references (add, greet)
// - Combines object files
// - Adds standard library code
// - Creates final executable