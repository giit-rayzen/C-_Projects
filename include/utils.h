// Header guard - prevents multiple inclusion
// Problem: If this header is included twice in same translation unit,
// we get "redefinition" errors
// Solution: Include guards ensure content is processed only once

#ifndef UTILS_H  // If UTILS_H is not defined
#define UTILS_H  // Define it now

#include <string>

// ============================================
// CONCEPT: Function Declaration (Prototype)
// ============================================
// Why declare in header?
// - Tells compiler function exists (will be defined elsewhere)
// - Other files can use this function by including this header
// - Linker connects calls to actual implementation in utils.o

// Interview Point: Declaration vs Definition
// Declaration: "This function exists" (in .h)
// Definition: "Here's what it does" (in .cpp)

/**
 * Adds two integers
 * 
 * Why const parameters? 
 * - Signals intent: we won't modify inputs
 * - Compiler can optimize better
 * - Tradeoff: None for primitives, but matters for objects
 */
int add(const int a, const int b);

/**
 * Greets a user by name
 * 
 * Why const std::string&?
 * - Pass by reference: Avoids copying entire string (performance)
 * - const: We don't modify the string (safety)
 * - Tradeoff: References require indirection (minor overhead)
 *   but saves copying potentially large strings
 */
std::string greet(const std::string& name);

// Alternative approach using #pragma once:
// #pragma once
// 
// Pros: Cleaner, less typing
// Cons: Not in C++ standard (though widely supported)
// Tradeoff: Use #ifndef for maximum portability

#endif // UTILS_H - End of header guard