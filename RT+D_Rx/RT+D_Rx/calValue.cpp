//
// Created by lyc on 2024/11/23.
//
//
// Created by lyc on 2024/11/22.
//
#include "iostream"
#include "stdio.h"
#include "math.h"
#include "string"
#include "stack.cpp"
#include "queue.cpp"
using namespace std;

//根据后缀式和常量表得出计算结果
static float calValue(string calculator, Queue<float>& ConstID, float x) {
    Stack<float>result;
    for (int i = 0;i < calculator.length();i++) {
        switch (calculator[i]) {
            case 'Y': {
                result.push(ConstID.dequeue());
                break;
            }
            case 'Z': {
                result.push(x);
                break;
            }
            case '1': {
                float num1 = result.pop();
                float num2 = result.pop();
                float num3 = pow(num2, num1);
                result.push(num3);
                break;
            }
        
            case '2': {
                float num1 = result.pop();
                result.push(num1);
                break;
            }
            case '3':{
                float num1 = result.pop();
                float num2 = -num1;
                result.push(num2);
                break;
            }
            case '4': {
                float num1 = result.pop();
                float num2 = result.pop();
                float num3 = num1 * num2;
                result.push(num3);
                break;
            }
            case '5': {
                float num1 = result.pop();
                float num2 = result.pop();
                float num3 = num2 / num1;
                result.push(num3);
                break;
            }
            case '6': {
                float num1 = result.pop();
                float num2 = result.pop();
                float num3 = num1 + num2;
                result.push(num3);
                break;
            }
            case '7': {
                float num1 = result.pop();
                float num2 = result.pop();
                float num3 = num2 - num1;
                result.push(num3);
                break;
            }
            case '8': {
                float num1 = result.pop();
                float num3 = sin(num1);
                result.push(num3);
                break;
            }
            case '9': {
                float num1 = result.pop();
                float num3 = cos(num1);
                result.push(num3);
                break;
            }
            case 'A': {
                float num1 = result.pop();
                float num3 = tan(num1);
                result.push(num3);
                break;
            }
            case 'B': {
                float num1 = result.pop();
                float num3 = sqrt(num1);
                result.push(num3);
                break;
            }
            case 'C': {
                float num1 = result.pop();
                float num3 = exp(num1);
                result.push(num3);
                break;
            }
            case 'D': {
                float num1 = result.pop();
                float num3 = log(num1);
                result.push(num3);
                break;
            }
        }

    }
    float finalResult = result.pop();
    return finalResult;

}