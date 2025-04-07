#pragma once

#ifdef _WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

#ifndef XEGERCPP_H
#define XEGERCPP_H

#include<string>

EXPORT std::string xeger(std::string regexp);

#endif
