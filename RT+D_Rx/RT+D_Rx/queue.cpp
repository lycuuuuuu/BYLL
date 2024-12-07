//
// Created by lyc on 2024/11/23.
//
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
    // ���
    void enqueue(const T& item) {
        data.push_back(item);
    }

    // ����
    T dequeue() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        T frontItem = data.front();
        data.pop_front();
        return frontItem;
    }

    // �ж϶����Ƿ�Ϊ��
    bool empty() const {
        return data.empty();
    }

    // ��ȡ����Ԫ��
    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data.front();
    }

    // ��ȡ��βԪ��
    const T& back() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data.back();
    }

    // ��ȡ���еĴ�С
    size_t size() const {
        return data.size();
    }

    // ��ӡ���е����� (�����ڵ���)
    void printQueue() const {
        std::cout << "Queue: ";
        for (const auto& item : data) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

