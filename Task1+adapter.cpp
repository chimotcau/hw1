template<typename K>
class Stack {
private:
    Deque<K> deque;
public:
    void push(const K& value) {       // Push element onto the stack
        deque.push_back(value);
    }
    void pop() {                     // Pop element from the stack
        deque.pop_back();
    }
    K& top() {                      // Get top element of the stack
        return deque.back();
    }
    bool empty() const {           // Check if the stack is none
        return deque.size() == 0;
    }  
    size_t size() const {         // Get size of the stack
        return deque.size();
    }
};