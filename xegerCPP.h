#pragma once
#include<string>
#include<string_view>

#ifdef _WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

EXPORT std::string xeger(std::string_view regexp);
