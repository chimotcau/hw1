#include <iostream>
#include <stdexcept>
template<typename K>
class Deque {
private:
    K* array;
    size_t capacity;
    size_t head;
    size_t tail;
    size_t current_size;
public:
    Deque(size_t capacity = 18) : array(new K[capacity]), capacity(capacity), head(0), tail(0), current_size(0) {}// Constructors
    ~Deque() {    // Destructor
        delete[] array;
    }
    Deque(const Deque& other) : capacity(other.capacity), head(other.head), tail(other.tail), current_size(other.current_size) {// Copy Constructor
        array = new K[capacity];
        for (size_t i = 0; i < capacity; ++i) {
            array[i] = other.array[i];
        }
    }
    Deque(Deque&& other) noexcept : array(other.array), capacity(other.capacity), head(other.head), tail(other.tail), current_size(other.current_size) {// Move Constructor
        other.array = nullptr;
        other.capacity = 0;
        other.head = 0;
        other.tail = 0;
        other.current_size = 0;
    }
    Deque& operator=(const Deque& other) {// Copy Assignment Operator
        if (this != &other) {
            delete[] array;
            capacity = other.capacity;
            head = other.head;
            tail = other.tail;
            current_size = other.current_size;
            array = new K[capacity];
            for (size_t i = 0; i < capacity; ++i) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }
    Deque& operator=(Deque&& other) noexcept {// Move Assignment Operator
        if (this != &other) {
            delete[] array;
            array = other.array;
            capacity = other.capacity;
            head = other.head;
            tail = other.tail;
            current_size = other.current_size;
            other.array = nullptr;
            other.capacity = 0;
            other.head = 0;
            other.tail = 0;
            other.current_size = 0;
        }
        return *this;
    }   
    void push_front(const K& value) {// Push element to the front
        if (current_size == capacity) {
            throw std::overflow_error("Full");
        }
        head = (head == 0) ? capacity - 1 : head - 1;
        array[head] = value;
        ++current_size;
    }   
    void push_back(const K& value) {// Push element to the back
        if (current_size == capacity) {
            throw std::overflow_error("Full");
        }
        array[tail] = value;
        tail = (tail + 1) % capacity;
        ++current_size;
    }    
    void pop_front() {// Pop element from the front
        if (current_size == 0) {
            throw std::underflow_error("None");
        }
        head = (head + 1) % capacity;
        --current_size;
    }
    void pop_back() {// Pop element from the back
        if (current_size == 0) {
            throw std::underflow_error("None");
        }
        tail = (tail == 0) ? capacity - 1 : tail - 1;
        --current_size;
    }
    size_t size() const {    // Get current size of the deque
        return current_size;
    }    
    size_t get_capacity() const {// Get current capacity of the deque
        return capacity;
    }
};
int main() {
    Deque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.push_front(0);
    deque.pop_front();
    deque.pop_back();
    std::cout << "Size: " << deque.size() << std::endl;
    std::cout << "Capacity: " << deque.get_capacity() << std::endl;
    return 0;
}
