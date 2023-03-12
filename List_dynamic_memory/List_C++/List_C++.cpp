#include <iostream>

using namespace std;

class List {
	static int counter;
	static List* head;
	static List* tail;
private:
	int a;
	double d;
	List* next;
	List(int _a = 0, double _d = 0.0) : a(_a), d(_d), next(NULL) {
		counter++;
	}
	~List() {
		counter--;
	}
public:
	static void push_front(int a, double d) {
		List * list_pointer = new List(a, d);
		if (!list_pointer) return;
		if (isEmpty()) head = tail = list_pointer;
		else {
			list_pointer->next = head;
			head = list_pointer;
		}
	}
	static void push_back(int a, double d) {
		List * list_pointer = new List(a, d);
		if (!list_pointer) return;
		if (isEmpty()) head = tail = list_pointer;
		else {
			tail->next = list_pointer;
			tail = list_pointer;
		}
	}
	static void pop_front() {
		if (isEmpty()) return;
		else if (head == tail) {
			delete head;
			head = tail = NULL;
		}
		else {
			List* list = head->next;
			delete head;
			head = list;
		}
	}
	static void pop_back() {
		if (isEmpty()) return;
		else if (head == tail) {
			delete head;
			head = tail = NULL;
		}
		else {
			List* list = head;
			while (list->next != tail) list = list->next;
			delete tail;
			list->next = NULL;
			tail = list;
		}
	}
	static void del() {
		if (isEmpty()) return;
		List* list;
		while (head) { list = head->next; delete head; head = list; }
		head = tail = NULL;
	}
	static void print() {
		if (isEmpty()) cout << "Empty" << endl;
		List* list = head;
		while (list != NULL) {
			cout << list->a << " " << list->d << endl;
			list = list->next;
		}
		cout << endl;
	}
	static bool isEmpty() { return head == tail && head == NULL; }
};

int List::counter = 0;
List* List::head = NULL;
List* List::tail = NULL;

int main() {
	for(int i = 0; i < 5; i++)
		List::push_back(i, i);
	List::print();
	List::pop_back();
	List::print();
	List::del();
	List::print();

	return 0;
}