#include <iostream>

#define SIZE 5

using namespace std;

template <typename type>
class Queue {
	int start = -1, end = -1, size = SIZE;
	type * buffer = new type[size];
public:
	Queue() = default;
	Queue(const Queue & q) : start(q.start), end(q.end), size(q.size) {
		this->buffer = new type[this->size];
		if (!q.empty())
			for (int i = 0; i < this->size; i++)
				this->buffer[i] = q.buffer[i];
	}
	~Queue() {
		delete[] buffer;
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
			if (end == start) cout << buffer[start] << endl;
			int tmp = start;
			while (tmp != end) {
				cout << buffer[tmp] << " ";
				tmp = (tmp + 1) % size;
			}
			cout << buffer[tmp] << endl;
		}
	}
	void pop() {
		if (empty()) exit(1);
		if (start == end) reset();
		else start = (start + 1) % size;
	}
	void put(type elem) {
		if (empty()) start = end = 0;
		else {
			if (full()) {
				size *= 2;
				type* new_buffer = new type[size];
				int tmp = start, j = 0;
				while (j < counter()) {
					new_buffer[j] = buffer[tmp];
					tmp = (tmp + 1) % size;
					j++;
				}
				buffer = new_buffer;
			}
			end = (end + 1) % size;
		}
		buffer[end] = elem;
	}
	Queue & operator=(const Queue & q) {
		if (this != &q) {
			delete[] this->buffer;
			this->size = q.size;
			this->start = q.start;
			this->end = q.end;
			this->buffer = new type[this->size];
			for (int i = 0; i < this->size; i++)
				this->buffer[i] = q.buffer[i];
		}
		return *this;
	}
};

int main() {
	Queue<int> queue_1 = Queue<int>();
	Queue<int> queue_2 = Queue<int>();
	for (int i = 0; i < SIZE; i++)
		queue_1.put(i + 1);
	queue_1.print();
	queue_2.print();
	queue_2 = queue_1;
	queue_2.print();

	queue_1.pop();
	queue_1.put(8);
	queue_1.print();
	queue_2.print();

	return 0;
}
