#include <iostream>

#define SIZE 5

using namespace std;

template <typename type>
class TWQueue {
	int start = -1, end = -1, size = SIZE;
	type buffer[SIZE];
public:
	TWQueue() = default;
	~TWQueue() {
		start = end = -1;
	}
	bool empty() const {
		return (start == -1 && end == -1);
	}
	bool full() const {
		return ((end + 1) % size == start);
	}
	int counter() const {
		if (empty()) return 0;
		else if (full()) return size;
		return (end >= start ? end - start + 1 : size - (start - end - 1));
	}
	type first() const {
		if (empty()) exit(1);
		return buffer[start];
	}
	type last() {
		if (empty()) exit(1);
		return buffer[end];
	}
	void reset() {
		start = end = -1;
	}
	void print() const {
		if (empty()) cout << "Queue is empty." << endl;
		else {
			int tmp = start;
			while (tmp != end) {
				cout << buffer[tmp] << " ";
				tmp = (tmp + 1) % size;
			}
			cout << buffer[tmp] << endl;
		}
	}
	void pop_front() {
		if (empty()) exit(1);
		if (start == end) reset();
		else start = (start + 1) % size;
	}
	void pop_back() {
		if (empty()) exit(1);
		if (start == end) reset();
		else end = (end - 1 + size) % size;
	}
	void put_front(type elem) {
		if (empty()) start = end = size - 1;
		else {
			if (full()) {
				cout << "Queue is full." << endl;
				return;
			}
			else {
				start = (start - 1 + size) % size;
			}
		}
		buffer[start] = elem;
	}
	void put_back(type elem) {
		if (empty()) start = end = 0;
		else {
			if (full()) {
				cout << "Queue is full." << endl;
				return;
			}
			else {
				end = (end + 1) % size;
			}
		}
		buffer[end] = elem;
	}
};

int main() {
	TWQueue<int> q = TWQueue<int>();
	q.put_front(1);
	q.put_front(2);
	q.put_back(3);
	q.put_back(4);
	q.print();
	q.put_front(5);
	q.print();

	return 0;
}
