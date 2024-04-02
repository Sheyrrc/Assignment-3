#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>

template <typename T>
class Queue {
private:
    std::vector<T> elements;

public:
    void push(T const& value) {
        elements.push_back(value);
    }

    void pop() {
        if (!elements.empty()) {
            elements.erase(elements.begin());
        }
    }

    T front() const {
        if (!elements.empty()) {
            return elements.front();
        }
        throw std::runtime_error("Queue is empty");
    }

    bool empty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }

    void move_to_rear() {
        if (!elements.empty()) {
            T frontElement = elements.front();
            elements.erase(elements.begin());
            elements.push_back(frontElement);
        }
    }
};

#endif // QUEUE_H
