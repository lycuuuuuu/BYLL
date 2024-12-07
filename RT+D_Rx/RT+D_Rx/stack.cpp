//
// Created by lyc on 2024/11/23.
//

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
    // ѹջ
    void push(const T& item) {
        data.push_back(item);
    }

    // ��ջ
    T pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        T topItem = data.back();
        data.pop_back();
        return topItem;
    }

    // �ж�ջ�Ƿ�Ϊ��
    bool empty() const {
        return data.empty();
    }

    // ��ȡջ��Ԫ��
    const T& top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return data.back();
    }

    // ��ȡջ�Ĵ�С
    size_t size() const {
        return data.size();
    }

    // ��ӡջ������ (�����ڵ���)
    void printStack() const {
        std::cout << "Stack: ";
        for (const auto& item : data) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

