#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class String {
	char* buffer = NULL;
	unsigned int size = 0;
public:
	String() = default;

	String(const char * str) {
		if (str) {
			size = strlen(str);
			buffer = new char[size + 1];
			strcpy(buffer, str);
		}
	}

	String(const String& str) {
		if (str.size) {
			size = str.size;
			buffer = new char[size + 1];
			strcpy(buffer, str.buffer);
		}
	}

	~String() {
		delete[] buffer;
	}

	char & operator[](int i) {
		if ((i >= 0) && (i < size)) return buffer[i];
		else cout << "Invalid index" << endl;
	}

	const char & operator[](int i) const {
		if ((i >= 0) && (i < size)) return buffer[i];
		else cout << "Invalid index" << endl;
	}

	String & operator=(const String & str) {
		if (this != &str) {
			delete[] this->buffer;
			this->buffer = new char[str.size + 1];
			strcpy(this->buffer, str.buffer);
			this->size = str.size;

		}
		return *this;
	}

	String & operator=(const char * str) {
		if (this->buffer != str) {
			delete[] this->buffer;
			this->buffer = new char[strlen(str) + 1];
			strcpy(this->buffer, str);
			this->size = strlen(str);
		}
		return *this;
	}

	String & operator+=(const String & str) {
		String string;
		string.size = this->size + str.size;
		string.buffer = new char[string.size + 1];
		strcpy(string.buffer, this->buffer);
		strcat(string.buffer, str.buffer);
		*this = string;
		return *this;
	}

	String & operator+=(const char * str) {
		String string;
		string.size = this->size + strlen(str);
		string.buffer = new char[string.size + 1];
		strcpy(string.buffer, this->buffer);
		strcat(string.buffer, str);
		*this = string;
		return *this;
	}

	String operator+(const String & str) const {
		String string;
		string.size = this->size + str.size;
		string.buffer = new char[string.size + 1];
		strcpy(string.buffer, this->buffer);
		strcat(string.buffer, str.buffer);
		return string;
	}

	String operator+(const char * str) const {
		String string;
		string.size = this->size + strlen(str);
		string.buffer = new char[string.size + 1];
		strcpy(string.buffer, this->buffer);
		strcat(string.buffer, str);
		return string;
	}

	friend ostream& operator<<(ostream&, const String&);
};

ostream& operator<<(ostream& stream, const String & str) {
	if (str.buffer) stream << str.buffer;
	else cout << "None" << endl;
	return stream;
}

int main() {

	return 0;
}
