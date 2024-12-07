//
// Created by lyc on 2024/11/21.
//
#include <iostream>
#include <deque>
#include <stdexcept> // for std::out_of_range


template <typename T>
class Queue {
private:
    std::deque<T> data;

public:
    // 入队
    void enqueue(const T& item) {
        data.push_back(item);
    }

    // 出队
    T dequeue() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        T frontItem = data.front();
        data.pop_front();
        return frontItem;
    }

    // 判断队列是否为空
    bool empty() const {
        return data.empty();
    }

    // 获取队首元素
    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data.front();
    }

    // 获取队尾元素
    const T& back() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data.back();
    }

    // 获取队列的大小
    size_t size() const {
        return data.size();
    }

    // 打印队列的内容 (仅用于调试)
    void printQueue() const {
        std::cout << "Queue: ";
        for (const auto& item : data) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};
