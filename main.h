/*
Requirements for compiling:
C++20
Windows API
Default char is unsigned
Increased stack reserve size (e.g. 10MB)
*/

#include <bit>
#include <cmath>
#include <cstdint>
#include <string>
#include <vector>

#include <windows.h>
#include <fileapi.h>
#include <shlwapi.h>

#define DEBUG_INFO __FUNCTION__, __FILE__, __LINE__

constexpr char PROGRAM_NAME[] = "LuaJIT Decompiler v2";
constexpr uint64_t DOUBLE_SIGN = 0x8000000000000000;
constexpr uint64_t DOUBLE_EXPONENT = 0x7FF0000000000000;
constexpr uint64_t DOUBLE_FRACTION = 0x000FFFFFFFFFFFFF;
constexpr uint64_t DOUBLE_SPECIAL = DOUBLE_EXPONENT;
constexpr uint64_t DOUBLE_NEGATIVE_ZERO = DOUBLE_SIGN;

struct {
	bool showHelp = false;
	bool silentAssertions = false;
	bool ignoreDebugInfo = false;
	std::string inputPath;
	std::string outputPath;
	std::string extensionFilter;
} arguments;

void print(const std::string& message);
std::string input();
void print_progress_bar(const double& progress = 0, const double& total = 100);
void erase_progress_bar();
void assert(const bool& assertion, const std::string& message, const std::string& filePath, const std::string& function, const std::string& source, const uint32_t& line);
std::string byte_to_string(const uint8_t& byte);

class Bytecode;
class Ast;
class Lua;

#include "bytecode\bytecode.h"
#include "ast\ast.h"
#include "lua\lua.h"
