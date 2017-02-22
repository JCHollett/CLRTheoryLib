// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once
#include <math.h>
#ifdef CLI_EXT
#define CLI_EXT
#define ARRAY(TYPE) cliext::ArrayContainer<TYPE>
#include <cliext/algorithm>
#include <cliext/adapter>
#else
#define ARRAY(TYPE) array<TYPE>
#endif
#ifndef KEYWORDS
#define KEYWORDS
#define NEW gcnew
#define double System::Double
#define float System::Single
#define int System::Int32
#define Int int
#endif
#include "Stdafx.cpp"