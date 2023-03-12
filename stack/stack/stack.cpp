#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <cstring>

#define SIZE 5

using namespace std;

class String {
	char* buffer = NULL;
	unsigned int size = 0;
public:
	String() = default;

	String(const char* str) {
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

	int length() {
		return this->size;
	}

	char& operator[](int i) {
		if ((i >= 0) && (i < size)) return buffer[i];
		else cout << "Invalid index" << endl;
	}

	const char& operator[](int i) const {
		if ((i >= 0) && (i < size)) return buffer[i];
		else cout << "Invalid index" << endl;
	}

	String& operator=(const String& str) {
		if (this != &str) {
			delete[] this->buffer;
			this->buffer = new char[str.size + 1];
			strcpy(this->buffer, str.buffer);
			this->size = str.size;

		}
		return *this;
	}

	String& operator=(const char* str) {
		if (this->buffer != str) {
			delete[] this->buffer;
			this->buffer = new char[strlen(str) + 1];
			strcpy(this->buffer, str);
			this->size = strlen(str);
		}
		return *this;
	}

	String& operator+=(const String& str) {
		String string;
		string.size = this->size + str.size;
		string.buffer = new char[string.size + 1];
		strcpy(string.buffer, this->buffer);
		strcat(string.buffer, str.buffer);
		*this = string;
		return *this;
	}

	String& operator+=(const char* str) {
		String string;
		string.size = this->size + strlen(str);
		string.buffer = new char[string.size + 1];
		strcpy(string.buffer, this->buffer);
		strcat(string.buffer, str);
		*this = string;
		return *this;
	}

	String operator+(const String& str) const {
		String string;
		string.size = this->size + str.size;
		string.buffer = new char[string.size + 1];
		strcpy(string.buffer, this->buffer);
		strcat(string.buffer, str.buffer);
		return string;
	}

	String operator+(const char* str) const {
		String string;
		string.size = this->size + strlen(str);
		string.buffer = new char[string.size + 1];
		strcpy(string.buffer, this->buffer);
		strcat(string.buffer, str);
		return string;
	}

	friend ostream& operator<<(ostream&, const String&);
};

template<typename type>
class Stack {
	int top = -1, size = SIZE;
	type* buffer = new type[size];
public:
	Stack() = default;
	Stack(const Stack& st) : top(st.top), size(st.size), buffer(new type[size]) {
		for (int i = 0; i <= top; i++)
			buffer[i] = st.buffer[i];
	}

	bool empty() const {
		return (true ? top == -1 : false);
	}

	bool full() const {
		return (top == size - 1);
	}

	void push(type elem) {
		if (full()) {
			type* new_buffer = new type[size * 2];
			for (int i = 0; i <= top; i++)
				new_buffer[i] = buffer[i];
			size *= 2;
			delete[] buffer;
			buffer = new_buffer;
		}
		buffer[++top] = elem;
	}

	void pop() {
		if (empty()) cout << "Error" << endl;
		else {
			top--;
		}
	}

	int fsize() const {
		return (top + 1);
	}

	type ftop() const {
		if (empty()) cout << "Error" << endl;
		else {
			return buffer[top];
		}
	}

	Stack& operator=(const Stack& st) {
		if (this != &st) {
			if (size >= st.size) {
				for (int i = 0; i < st.top; i++)
					buffer[i] = st.buffer[i];
				this->top = st.top;
			}
			else {
				delete[] buffer;
				type* new_buffer = new type[st.size];
				for (int i = 0; i <= st.top; i++)
					new_buffer[i] = st.buffer[i];
				this->top = st.top;
				this->size = st.size;
			}
		}
		return *this;
	}

	type& operator[](int index) const {
		if (empty() || index < size || index > -1) cout << "Error" << endl;
		return buffer[index];
	}
};

ostream& operator<<(ostream& stream, const String& str) {
	if (str.buffer) stream << str.buffer;
	else cout << "None" << endl;
	return stream;
}

//double get_result(string & str) {
//	stack<double> st = stack<double>();
//	double temp = 0, first, second;
//	bool point = false;
//	int a = 10;
//	for (int i = 0; i < str.size(); i++) {
//		if (str[i] >= '0' && str[i] <= '9') {
//			while (str[i] != ' ') {
//				if (str[i] == '.') {
//					point = true;
//					i++;
//					continue;
//				}
//				if (point) {
//					temp = temp + (1.0 / a) * (str[i] - '0');
//					a *= 10;
//				} else temp = temp * 10 + (str[i] - '0');
//				i++;
//			}
//			st.push(temp);
//			cout << st.top() << endl;
//			temp = 0;
//			point = false;
//			a = 10;
//		}
//		else {
//			switch (str[i]) {
//				first = st.top();
//				st.pop();
//				second = st.top();
//				st.pop();
//			case '+' :
//				st.push(first + second);
//				break;
//			case '-' :
//				st.push(second - first);
//				break;
//			case '*' :
//				st.push(first * second);
//				break;
//			case '/' :
//				st.push(second / first);
//				break;
//			case '~':
//				st.push(second);
//				st.push(-first);
//				break;
//			}
//			i++;
//		}
//	}
//	return st.top();
//}

int main() {
	Stack<int> s;
	for (int i = 0; i < 5; i++) {
		s.push(i);
	}
	while (!s.empty()) {
		cout << s.ftop(), s.pop();
	}
	return 0;
}