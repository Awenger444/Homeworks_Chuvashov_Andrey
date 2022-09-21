#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>

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

	String & operator+=(const String & str) {
		String string;
		string.size = this->size + str.size;
		string.buffer = new char[string.size + 1];
		strcpy(string.buffer, this->buffer);
		strcat(string.buffer, str.buffer);
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

	bool operator==(const String & str) const {
		return strcmp(this->buffer, str.buffer) == 0;
	}

	bool operator!=(const String & str) const {
		return strcmp(this->buffer, str.buffer) != 0;
	}

	bool operator<(const String & str) const {
		return strcmp(this->buffer, str.buffer) == 1;
	}

	bool operator>(const String & str) const {
		return strcmp(this->buffer, str.buffer) == -1;
	}

	bool operator<=(const String& str) const {
		return strcmp(this->buffer, str.buffer) != 1;
	}

	bool operator>=(const String& str) const {
		return strcmp(this->buffer, str.buffer) != -1;
	}

	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);
};

ostream& operator<<(ostream& stream, const String & str) {
	if (str.buffer) stream << str.buffer;
	else cout << "None" << endl;
	return stream;
}

istream& operator>>(istream& stream, String& str) {
	delete[] str.buffer;
	int size = 20, top = 0;
	char* new_buffer = new char[size];
	char* time_buffer = NULL;
	char ch;
	while ((ch = getc(stdin)) != '\n') {
		if (top == size - 1) {
			time_buffer = new char[size * 2];
			strcpy(time_buffer, new_buffer);
			delete[] new_buffer;
			new_buffer = time_buffer;
			size *= 2;
		}
		new_buffer[top] = ch;
		new_buffer[++top] = '\0';
	}
	new_buffer[++top] = '\0';
	str.buffer = new_buffer;
	return stream;
}

int main() {
	String string;
	cin >> string;
	cout << string << endl;

	return 0;
}
