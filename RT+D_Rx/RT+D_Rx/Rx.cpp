#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <sstream> // for stringstream
#include <stdexcept> // for std::invalid_argument, std::out_of_range
#include <typeinfo> // for typeid
#include <SFML/Graphics.hpp>
#include "calValue.cpp"

typedef struct {
    float x;
    float y;
} Point;


template <typename T>
T fromString(const std::string& str) {
    T value;
    std::stringstream ss(str);
    if (!(ss >> value)) {
        throw std::invalid_argument("无效输入字符串: " + str + "，目标类型：" + typeid(T).name());
    }
    return value;
}


int main() {
    std::ifstream infile("params.txt");
    if (!infile.is_open()) {
        std::cerr << "无法打开文件进行读取。\n";
        return 1;
    }

    int calSize;
    if (!(infile >> calSize)) {
        std::cerr << "读取Cal大小出错。\n";
        return 1;
    }
    infile.ignore(); // 消耗读取calSize后的换行符

    std::vector<std::string> Cal(calSize);
    for (int i = 0; i < calSize; ++i) {
        if (!std::getline(infile, Cal[i])) {
            std::cerr << "读取Cal元素" << i << "出错。\n";
            return 1;
        }
    }


    int queueSize;
    if (!(infile >> queueSize)) {
        std::cerr << "读取ConstID1大小出错。\n";
        return 1;
    }
    infile.ignore();

    Queue<float> ConstID1;
    for (int i = 0; i < queueSize; ++i) {
        std::string valStr;
        infile >> valStr;
        try {
            ConstID1.enqueue(fromString<float>(valStr));
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "转换ConstID1元素" << i << "出错: " << e.what() << "\n";
            return 1;
        }
    }
    infile.ignore();


    if (!(infile >> queueSize)) {
        std::cerr << "读取ConstID2大小出错。\n";
        return 1;
    }
    infile.ignore();

    Queue<float> ConstID2;
    for (int i = 0; i < queueSize; ++i) {
        std::string valStr;
        infile >> valStr;
        try {
            ConstID2.enqueue(fromString<float>(valStr));
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "转换ConstID2元素" << i << "出错: " << e.what() << "\n";
            return 1;
        }
    }
    infile.ignore();


    Point origin, rot, scale;
    if (!(infile >> origin.x >> origin.y)) {
        std::cerr << "读取origin出错。\n";
        return 1;
    }
    infile.ignore();

    if (!(infile >> rot.x >> rot.y)) {
        std::cerr << "读取rot出错。\n";
        return 1;
    }
    infile.ignore();

    if (!(infile >> scale.x >> scale.y)) {
        std::cerr << "读取scale出错。\n";
        return 1;
    }
    infile.ignore();


    int vecSize;
    if (!(infile >> vecSize)) {
        std::cerr << "读取start大小出错。\n";
        return 1;
    }
    infile.ignore();

    std::vector<float> start(vecSize);
    for (int i = 0; i < vecSize; ++i) {
        std::string valStr;
        infile >> valStr;
        try {
            start[i] = fromString<float>(valStr);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "转换start元素" << i << "出错: " << e.what() << "\n";
            return 1;
        }
    }
    infile.ignore();


    if (!(infile >> vecSize)) {
        std::cerr << "读取endPlace大小出错。\n";
        return 1;
    }
    infile.ignore();

    std::vector<float> endPlace(vecSize);
    for (int i = 0; i < vecSize; ++i) {
        std::string valStr;
        infile >> valStr;
        try {
            endPlace[i] = fromString<float>(valStr);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "转换endPlace元素" << i << "出错: " << e.what() << "\n";
            return 1;
        }
    }
    infile.ignore();


    if (!(infile >> vecSize)) {
        std::cerr << "读取step大小出错。\n";
        return 1;
    }
    infile.ignore();

    std::vector<float> step(vecSize);
    for (int i = 0; i < vecSize; ++i) {
        std::string valStr;
        infile >> valStr;
        try {
            step[i] = fromString<float>(valStr);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "转换step元素" << i << "出错: " << e.what() << "\n";
            return 1;
        }
    }
    infile.ignore();



    // 打印接收到的数据 (包括类型信息) -  添加了错误处理
    std::cout << "接收到的数据:\n";
    std::cout << "Cal: "; for (const auto& s : Cal) std::cout << s << " "; std::cout << "\n";
    //std::cout << "ConstID1 (type: " << typeid(ConstID1).name() << "): "; while (!ConstID1.empty()) { std::cout << ConstID1.front() << " "; ConstID1.pop(); } std::cout << "\n";
    //std::cout << "ConstID2 (type: " << typeid(ConstID2).name() << "): "; while (!ConstID2.empty()) { std::cout << ConstID2.front() << " "; ConstID2.pop(); } std::cout << "\n";
    std::cout << "origin: (" << origin.x << ", " << origin.y << ")\n";
    std::cout << "rot: (" << rot.x << ", " << rot.y << ")\n";
    std::cout << "scale: (" << scale.x << ", " << scale.y << ")\n";
    std::cout << "start: "; for (float f : start) std::cout << f << " "; std::cout << "\n";
    std::cout << "endPlace: "; for (float f : endPlace) std::cout << f << " "; std::cout << "\n";
    std::cout << "step: "; for (float f : step) std::cout << f << " "; std::cout << "\n";
    std::cout << "CONST_ID1(first):";
    ConstID1.printQueue();
    std::cout << "CONST_ID2(first):";
    ConstID2.printQueue();
    for (int i = 0;i < 10;i++) {
        if (Cal[i] != "") { cout << "Cal" << i << "isn't null" << endl; }
    }




    //得到的算术式的后缀表达式存放在Cal的每个元素中
//得到的常量表是 ConstID 队列
//可以根据这俩求出每个x、y对应的坐标
    sf::RenderWindow window(sf::VideoMode(800, 600), "draw"); //创建一个800x600像素的窗口，标题为"draw"
    window.setFramerateLimit(60); //将帧率限制为60帧每秒，使动画更流畅


    
    std::vector<sf::Vector2f>points1;
    std::vector<sf::Vector2f>points2;

    Queue<float> tempID1 = ConstID1;
    Queue<float> tempID2 = ConstID2;

    if (Cal[0] != "") {
        for (float i = start[0]; i < endPlace[0]; i = i + step[0]) {
            float tempx = scale.x * calValue(Cal[0], ConstID1, i);
            float tempy = scale.y * calValue(Cal[1], ConstID2, i);
            ConstID1 = tempID1;
            ConstID2 = tempID2;
            float x = tempx * cos(rot.x) + tempy * sin(rot.x) + origin.x;          // x坐标从0到400
            float y = tempy * cos(rot.x) - tempx * sin(rot.x) + origin.y;          // 根据y = 2x计算y坐标
            points1.push_back(sf::Vector2f(x, y));
        }
    }
    

    Queue<float> tempID1_1 = ConstID1;
    Queue<float> tempID2_1 = ConstID2;
    
    if (Cal[2] != "") {
        for (float i = start[1]; i < endPlace[1]; i = i + step[1]) {
            float tempx = scale.x * calValue(Cal[2], ConstID1, i);
            float tempy = scale.y * calValue(Cal[3], ConstID2, i);
            ConstID1 = tempID1_1;
            ConstID2 = tempID2_1;
            float x = tempx * cos(rot.x) + tempy * sin(rot.x) + origin.x;          
            float y = tempy * cos(rot.x) - tempx * sin(rot.x) + origin.y;         
            points1.push_back(sf::Vector2f(x, y));
        }
    }

    
    Queue<float> tempID1_2 = ConstID1;
    Queue<float> tempID2_2 = ConstID2;
    if (Cal[4] != "") {
        for (float i = start[2]; i < endPlace[2]; i = i + step[2]) {
            float tempx = scale.x * calValue(Cal[4], ConstID1, i);
            float tempy = scale.y * calValue(Cal[5], ConstID2, i);
            ConstID1 = tempID1_2;
            ConstID2 = tempID2_2;
            float x = tempx * cos(rot.x) + tempy * sin(rot.x) + origin.x;          
            float y = tempy * cos(rot.x) - tempx * sin(rot.x) + origin.y;         
            points1.push_back(sf::Vector2f(x, y));

        }
    }


    Queue<float> tempID1_3 = ConstID1;
    Queue<float> tempID2_3 = ConstID2;
    if (Cal[6] != "") {
        for (float i = start[3]; i < endPlace[3]; i = i + step[3]) {
            float tempx = scale.x * calValue(Cal[6], ConstID1, i);
            float tempy = scale.y * calValue(Cal[7], ConstID2, i);
            ConstID1 = tempID1_3;
            ConstID2 = tempID2_3;
            float x = tempx * cos(rot.x) + tempy * sin(rot.x) + origin.x;          
            float y = tempy * cos(rot.x) - tempx * sin(rot.x) + origin.y;        
            points1.push_back(sf::Vector2f(x, y));
        }
    }


    Queue<float> tempID1_4 = ConstID1;
    Queue<float> tempID2_4 = ConstID2;
    if (Cal[8] != "") {
        for (float i = start[4]; i < endPlace[4]; i = i + step[4]) {
            float tempx = scale.x * calValue(Cal[8], ConstID1, i);
            float tempy = scale.y * calValue(Cal[9], ConstID2, i);
            ConstID1 = tempID1_4;
            ConstID2 = tempID2_4;
            float x = tempx * cos(rot.x) + tempy * sin(rot.x) + origin.x;         
            float y = tempy * cos(rot.x) - tempx * sin(rot.x) + origin.y;       
            points1.push_back(sf::Vector2f(x, y));
        }
    }
    


    // 主循环，用于处理事件和渲染
    while (window.isOpen()) {
        sf::Event event; // 创建一个事件对象
        while (window.pollEvent(event)) { // 检查是否有事件发生
            if (event.type == sf::Event::Closed) // 如果事件类型是关闭窗口
                window.close(); // 关闭窗口
        }

        // 设置点的形状（圆形）
        sf::CircleShape pointShape(3.f); // 创建一个半径为3像素的圆形
        pointShape.setFillColor(sf::Color::Blue); // 设置第一个散点图的点的颜色为蓝色
        window.clear(); // 清除窗口内容

        for (const auto& point : points1) { // 遍历第一个散点图的点坐标
            pointShape.setPosition(point); // 设置圆形的位置
            window.draw(pointShape);       // 绘制圆形
        }

        window.display(); // 更新窗口显示

    }




    infile.close();
    return 0;
}