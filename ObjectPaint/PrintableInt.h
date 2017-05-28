#pragma once
#include <iostream>
#ifdef COMPILE_MYLIBRARY
#define MYLIBRARY_EXPORT __declspec(dllexport)
#else
#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

class MYLIBRARY_EXPORT PrintableInt 
{
public:
	PrintableInt(int value);
	std::string toString() const;
private:
	int m_value;
};