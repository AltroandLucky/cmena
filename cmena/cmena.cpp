#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;       // ������������ ������ ��� �������� ���������
    int capacity;   // ������ �������
    int front;      // ������ ������ �������
    int rear;       // ������ ����� �������
    int size;       // ������� ���������� ��������� � �������

    // ����� ��� ��������� ������� �������
    void resize() {
        int newCapacity = capacity * 2; // ����������� ������ �����
        int* newArr = new int[newCapacity];

        // �������� ������ �������� � ����� ������
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[(front + i) % capacity];
        }

        // ����������� ������ ������
        delete[] arr;

        // ��������� ��������� � ���������
        arr = newArr;
        capacity = newCapacity;
        front = 0;
        rear = size - 1;
    }

public:
    // �����������
    Queue(int initialCapacity = 4)
        : capacity(initialCapacity), front(0), rear(-1), size(0) {
        arr = new int[capacity];
    }

    // ����������
    ~Queue() {
        delete[] arr;
    }

    // ���������� �������� � �������
    void enqueue(int value) {
        if (size == capacity) {
            resize(); // ����������� ������ ��� �������������
        }
        rear = (rear + 1) % capacity; // ������� rear �� ������
        arr[rear] = value;
        size++;
    }

    // �������� �������� �� �������
    int dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty!");
        }
        int value = arr[front];
        front = (front + 1) % capacity; // ������� front �� ������
        size--;
        return value;
    }

    // ��������, ����� �� �������
    bool isEmpty() const {
        return size == 0;
    }

    // ��������� �������� ������� �������
    int getSize() const {
        return size;
    }

    // ����� ��������� �������
    void display() const {
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    // ���������� ��������� � �������
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Queue after enqueuing 4 elements: ";
    q.display();

    // �������� ���������
    q.dequeue();
    q.dequeue();

    cout << "Queue after dequeuing 2 elements: ";
    q.display();

    // ���������� ������ ���������
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);

    cout << "Queue after enqueuing more elements: ";
    q.display();

    return 0;
}
