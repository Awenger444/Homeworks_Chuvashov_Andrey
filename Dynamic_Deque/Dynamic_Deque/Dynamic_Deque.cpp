#include <iostream>
#define SIZE 5

using namespace std;

template<typename type>
class Deque {
	int start = -1, end = -1, size = SIZE;
	type* buffer = new type[size];
	bool OneElement() const {
		return (start == end && start != 1);
	}
public:
	Deque() = default;
	Deque(const Deque & dq) : start(dq.start), end(dq.end), size(dq.size), buffer(new type[size]) {
		for (int i = 0; i < this.size; i++)
			buffer[i] = dq.buffer[i];
	}
	~Deque() {
		delete[] buffer;
	}
	bool empty() const {
		return (start == end && start == -1);
	}
	bool full() const {
		return ((end + 1) % size) == start;
	}
	Deque& operator=(const Deque& dq) {
		
	}
	int count() const {
		return (end >= start) ? (end - start + 1) : size - (start - end - 1);
	}
	void print() const {
		if (empty()) return;
		int tmp = start;
		while (tmp != end) {
			cout << buffer[tmp] << " ";
			tmp = (tmp + 1) % size;
		}
		cout << buffer[tmp] << endl;
	}
	void pop_front() {
		if (empty()) exit(1);
		if (OneElement()) start = end = -1;
		else start = (start + 1) % size;
	}
	void pop_back() {
		if (empty()) exit(1);
		if (OneElement()) start = end = -1;
		else end = (end - 1 + size) % size;
	}
	void push_front(type elem) {
		if (full()) {
			type* new_buffer = new type[size*2];
			int tmp = start, j = 0;
			while (tmp != end) {
				new_buffer[j] = buffer[tmp];
				j++;
				tmp = (start + 1) % size;
			}
			new_buffer[j] = buffer[tmp];
			delete[] this->buffer;
			this->buffer = new_buffer;
			start = 0; end = j; size *= 2;
		}
		else {
			if (empty()) start = end = size - 1;
			start = (start - 1 + size) % size;
		}
		buffer[start] = elem;
	}
	void push_back(type elem) {
		if (full()) {
			type* new_buffer = new type[size * 2];
			int tmp = start, j = 0;
			while (tmp != end) {
				new_buffer[j] = buffer[tmp];
				j++;
				tmp = (start + 1) % size;
			}
			new_buffer[j] = buffer[tmp];
			delete[] this->buffer;
			this->buffer = new_buffer;
			start = 0; end = j; size *= 2;
		}
		else {
			if (empty()) start = end = 0;
			end = (end + 1) % size;
		}
		buffer[end] = elem;
	}
};

int main() {
	Deque<int> dq = Deque<int>();
	cout << dq.full() << " " << dq.empty() << endl;
	dq.push_front(1);
	dq.push_back(2);
	dq.print();

	return 0;
}