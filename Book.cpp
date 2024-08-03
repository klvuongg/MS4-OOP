#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Lib.h"
#include "Book.h"
#include "Utils.h"
using namespace std;
namespace seneca {
	Book::Book() : Publication() {
		author_name = nullptr;
	}

	Book::Book(const Book& b) : Publication(b) {
		author_name = nullptr;
		if (b.author_name) {
			author_name = new char[strlen(b.author_name) + 1];
			strcpy(author_name, b.author_name);
		}
	}

	Book& Book::operator=(const Book& b) {
		if (this != &b) {
			(Publication&)*this = b;
			if (author_name) {
				delete[] author_name;
				author_name = new char[strlen(b.author_name) + 1];
				strcpy(author_name, b.author_name);
			}
		}
		return *this;
	}

	Book::~Book() {
		delete[] author_name;
	}

	char Book::type() const {
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const {
		Publication::write(os);
		if (conIO(os)) {
			if (author_name) {
				os << " ";
				if (strlen(author_name) > SENECA_AUTHOR_WIDTH) {
					os.write(author_name, SENECA_AUTHOR_WIDTH);
				}
				else {
					os << setw(SENECA_AUTHOR_WIDTH) << author_name;
				}
				os << " |";
			}
		}
		else {
			os << "\t" << author_name;
		}
		return os;
	}

	std::istream& Book::read(std::istream& istr) {
		char aName[256];
		Publication::read(istr);
		delete[] author_name;
		author_name = nullptr;
		if (conIO(istr)) {
			istr.ignore();
			cout << "Author: ";
			istr.getline(aName, 256);
			istr.ignore();
		}
		else {
			istr.ignore();
			istr.getline(aName, 256);
			istr.ignore();
		}

		if (istr) {
			author_name = new char[strlen(aName) + 1];
			strcpy(author_name, aName);
		}
		else {
			delete[] author_name;
			author_name = nullptr;
		}
		return istr;
	}

	void Book::set(int member_id) {
		Publication::set(member_id);
		resetDate();
	}

	Book::operator bool() const {
		return author_name && Publication::operator bool();
	}
}
