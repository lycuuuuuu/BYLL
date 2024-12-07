//
// Created by lyc on 2024/11/21.
//
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // for std::out_of_range

template <typename T>
class Stack {
private:
    std::vector<T> data;

public:
    // 压栈
    void push(const T& item) {
        data.push_back(item);
    }

    // 出栈
    T pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        T topItem = data.back();
        data.pop_back();
        return topItem;
    }

    // 判断栈是否为空
    bool empty() const {
        return data.empty();
    }

    // 获取栈顶元素
    const T& top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return data.back();
    }

    // 获取栈的大小
    size_t size() const {
        return data.size();
    }

    // 打印栈的内容 (仅用于调试)
    void printStack() const {
        std::cout << "Stack: ";
        for (const auto& item : data) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};
