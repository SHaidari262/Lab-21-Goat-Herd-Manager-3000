
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_LS = 5;
const int MAX_LS = 20;
const int SIZE = 15;

// Goat class
class Goat {
private:
    int age;
    string name;
    string color;

    string names[SIZE] = {
        "Billy", "Daisy", "Luna", "Max", "Bella",
        "Charlie", "Rosie", "Oliver", "Coco", "Milo",
        "Ruby", "Rocky", "Sunny", "Willow", "Buddy"
    };

    string colors[SIZE] = {
        "White", "Black", "Brown", "Gray", "Gold",
        "Yellow", "Red", "Cream", "Tan", "Beige",
        "Silver", "Mauve", "Orange", "Spotted", "Blue"
    };

public:
    // Default constructor
    Goat() {
        age = rand() % 20 + 1;
        name = names[rand() % SIZE];
        color = colors[rand() % SIZE];
    }

    // Parameterized constructor
    Goat(int a, string n, string c) {
        age = a;
        name = n;
        color = c;
    }

    void print() const {
        cout << "    " << name << " (" << color
             << ", " << age << ")" << endl;
    }
};

// Doubly linked list class
class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;

        Node(const Goat& val, Node* p = nullptr,
             Node* n = nullptr)
            : data(val), prev(p), next(n) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Add goat to end
    void push_back(const Goat& value) {
        Node* newNode = new Node(value);

        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Add goat to front
    void push_front(const Goat& value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Print forward
    void print() const {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;

        while (current) {
            current->data.print();
            current = current->next;
        }
    }

    // Print backward
    void print_reverse() const {
        if (!tail) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = tail;

        while (current) {
            current->data.print();
            current = current->prev;
        }
    }

    // Destructor
    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
    }
};

// Driver program
int main() {
    srand(time(0));

    DoublyLinkedList herd;

    // Random number of goats between 5 and 20
    int numberOfGoats =
        rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;

    for (int i = 0; i < numberOfGoats; i++) {
        Goat newGoat;
        herd.push_back(newGoat);
    }

    cout << "GOAT HERD MANAGER 3000" << endl;
    cout << "Number of goats: " << numberOfGoats << endl;

    cout << "\nForward:" << endl;
    herd.print();

    cout << "\nBackward:" << endl;
    herd.print_reverse();

    // Test parameterized constructor and push_front
    Goat specialGoat(5, "Special", "White");
    herd.push_front(specialGoat);

    cout << "\nAfter adding special goat to front:"
         << endl;
    herd.print();

    // Test empty list
    DoublyLinkedList emptyHerd;

    cout << "\nTesting empty list:" << endl;
    emptyHerd.print();
    emptyHerd.print_reverse();

    return 0;
}
