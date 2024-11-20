#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;       // Динамический массив для хранения элементов
    int capacity;   // Размер массива
    int front;      // Индекс начала очереди
    int rear;       // Индекс конца очереди
    int size;       // Текущее количество элементов в очереди

    // Метод для изменения размера массива
    void resize() {
        int newCapacity = capacity * 2; // Увеличиваем размер вдвое
        int* newArr = new int[newCapacity];

        // Копируем старые элементы в новый массив
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[(front + i) % capacity];
        }

        // Освобождаем старую память
        delete[] arr;

        // Обновляем указатели и параметры
        arr = newArr;
        capacity = newCapacity;
        front = 0;
        rear = size - 1;
    }

public:
    // Конструктор
    Queue(int initialCapacity = 4)
        : capacity(initialCapacity), front(0), rear(-1), size(0) {
        arr = new int[capacity];
    }

    // Деструктор
    ~Queue() {
        delete[] arr;
    }

    // Добавление элемента в очередь
    void enqueue(int value) {
        if (size == capacity) {
            resize(); // Увеличиваем размер при необходимости
        }
        rear = (rear + 1) % capacity; // Двигаем rear по кольцу
        arr[rear] = value;
        size++;
    }

    // Удаление элемента из очереди
    int dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty!");
        }
        int value = arr[front];
        front = (front + 1) % capacity; // Двигаем front по кольцу
        size--;
        return value;
    }

    // Проверка, пуста ли очередь
    bool isEmpty() const {
        return size == 0;
    }

    // Получение текущего размера очереди
    int getSize() const {
        return size;
    }

    // Вывод элементов очереди
    void display() const {
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    // Добавление элементов в очередь
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Queue after enqueuing 4 elements: ";
    q.display();

    // Удаление элементов
    q.dequeue();
    q.dequeue();

    cout << "Queue after dequeuing 2 elements: ";
    q.display();

    // Добавление больше элементов
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);

    cout << "Queue after enqueuing more elements: ";
    q.display();

    return 0;
}
