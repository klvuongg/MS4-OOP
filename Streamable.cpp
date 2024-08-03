#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Streamable.h"
using namespace std;
namespace seneca {
	std::ostream& operator<<(std::ostream& os, const Streamable& str) {
		return str.write(os);
	}

	std::istream& operator>>(std::istream& istr, Streamable& str) {
		return str.read(istr);
	}
}