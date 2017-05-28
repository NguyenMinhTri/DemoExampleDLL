#include "PrintableInt.h"
#include <sstream>



PrintableInt::PrintableInt(int value)
{
	m_value = value;
}

std::string PrintableInt::toString() const {
	std::ostringstream builder;
	builder << m_value;
	return builder.str();
}
