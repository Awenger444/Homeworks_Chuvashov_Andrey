#include <iostream>

using namespace std;

class Deque {
private:
    class Node {
        int n;
        Node* next = NULL;
        Node* previous = NULL;
    public:
        Node(int _n) : n(_n) {}
        ~Node() = default;
        int getElem() const {
            return n;
        }
        Node* getNext() const {
            return next;
        }
        Node* getPrevious() {
            return previous;
        }
        void setElem(int x) {
            this->n = x;
        }
        void setNext(Node* new_next) {
            this->next = new_next;
        }
        void setPrevious(Node* new_prev) {
            this->previous = new_prev;
        }
    };
    Node* head;
    Node* tail;
    int counter;
    Node* finder(int x) const {
        Node* current = head;
        if (empty()) { return nullptr; }
        else {
            while (current) {
                if (current->getElem() == x) return current;
                else current = current->getNext();
            }
        }
        return nullptr;
    }
protected:
    int operator[](int index) const {
        if (index >= counter || index < 0) { cout << index << " " << "Element not found."; exit(1); }
        else if (empty()) { cout << "Deque is empty."; exit(1); }
        else {
            Node* current = head;
            int c = 0;
            while (c < index) { current = current->getNext(); c++; }
            return current->getElem();
        }
    }
public:
    Deque() : counter(0), head(NULL), tail(NULL) {}
    Deque(const Deque& d) {
        if (d.counter == 0) {
            head = tail = NULL;
            counter = 0;
        }
        else {
            Node* current = d.head;
            this->pushFront(current->getElem());
            current = current->getNext();
            while (current) {
                this->pushBack(current->getElem());
                current = current->getNext();
            }
        }
    }
    ~Deque() {
        Node* current;
        while (head) {
            current = head->getNext();
            delete head;
            head = current;
        }
        tail = NULL;
    }
    int Length() {
        return counter;
    }
    bool empty() const {
        return (counter == 0);
    }
    void pushBack(int k) {
        Node* current = new Node(k);
        if (empty()) head = tail = current;
        else {
            tail->setNext(current);
            current->setPrevious(tail);
            tail = current;
        }
        counter++;
    }
    void pushFront(int k) {
        Node* current = new Node(k);
        if (empty()) head = tail = current;
        else {
            head->setPrevious(current);
            current->setNext(head);
            head = current;
        }
        counter++;
    }
    void popBack() {
        if (counter == 1) {
            delete tail;
            head = tail = NULL;
            counter = 0;
        }
        else if (!empty()) {
            Node* current = tail->getPrevious();
            delete tail;
            tail = current;
            counter--;
        }
        else return;
    }
    void popFront() {
        if (counter == 1) {
            delete head;
            head = tail = NULL;
            counter = 0;
        }
        else if (!empty()) {
            Node* current = head->getNext();
            delete head;
            head = current;
            counter--;
        }
        else return;
    }
    void print() const {
        if (empty()) {
            cout << "Deque is empty." << endl;
        }
        else {
            Node* current = head;
            while (current) {
                cout << current->getElem() << " ";
                current = current->getNext();
            }
            cout << endl;
        }
    }
    // дописать оператор сложения
    Deque& operator+(Deque& second) {
        if (empty()) return second;
        else if (second.empty()) return *this;
        else {
            Deque new_d;
            Node* current = head;
            while (current) {
                new_d.pushBack(current->getElem());
                current = current->getNext();
                if (new_d.counter == counter)
                    current = second.head;
            }
            return new_d;
        }
    }
    void operator=(Deque& second) {
        if (second.empty()) this->reset();
        else {
            Node* current = second.head;
            while (current) {
                pushBack(current->getElem());
                current = current->getNext();
            }
        }
    }
    // дописать удаление элемента (со второго раза не работает)
    void remove(int x) {
        if (empty()) return;
        else if (finder(x) == head) popFront();
        else if (finder(x) == tail) popBack();
        else {
            Node* current_right = finder(x)->getNext();
            Node* current_left = finder(x)->getPrevious();
            current_right->setPrevious(current_left);
            current_left->setNext(current_right);
            delete finder(x);
            counter--;
        }
    }
    void reset() {
        Node* current;
        while (head) {
            current = head->getNext();
            delete head;
            head = current;
        }
        tail = NULL;
        counter = 0;
    }
    friend ostream& operator<<(ostream&, Deque&);
};

ostream& operator<<(ostream& output, Deque& list) {
    int c = 0;
    if (list.counter == 0)
        output << "List is empty.";
    else {
        while (c != list.counter) {
            output << list[c] << " ";
            c++;
        }
    }
    return output;
}

int main()
{
    Deque d1;
    for (int i = 0; i < 5; i++)
        d1.pushFront(i + 4);
    d1.pushBack(99);
    cout << d1 << endl;
    d1.remove(7);
    cout << d1 << endl;
    d1.remove(8);
    cout << d1 << endl;
    d1.remove(5);
    cout << d1 << endl;
    d1.remove(6);
    cout << d1 << endl;
    d1.remove(99);
    cout << d1 << endl;

    return 0;
}
