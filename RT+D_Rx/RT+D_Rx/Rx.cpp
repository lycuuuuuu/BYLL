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
        throw std::invalid_argument("��Ч�����ַ���: " + str + "��Ŀ�����ͣ�" + typeid(T).name());
    }
    return value;
}


int main() {
    std::ifstream infile("params.txt");
    if (!infile.is_open()) {
        std::cerr << "�޷����ļ����ж�ȡ��\n";
        return 1;
    }

    int calSize;
    if (!(infile >> calSize)) {
        std::cerr << "��ȡCal��С����\n";
        return 1;
    }
    infile.ignore(); // ���Ķ�ȡcalSize��Ļ��з�

    std::vector<std::string> Cal(calSize);
    for (int i = 0; i < calSize; ++i) {
        if (!std::getline(infile, Cal[i])) {
            std::cerr << "��ȡCalԪ��" << i << "����\n";
            return 1;
        }
    }


    int queueSize;
    if (!(infile >> queueSize)) {
        std::cerr << "��ȡConstID1��С����\n";
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
            std::cerr << "ת��ConstID1Ԫ��" << i << "����: " << e.what() << "\n";
            return 1;
        }
    }
    infile.ignore();


    if (!(infile >> queueSize)) {
        std::cerr << "��ȡConstID2��С����\n";
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
            std::cerr << "ת��ConstID2Ԫ��" << i << "����: " << e.what() << "\n";
            return 1;
        }
    }
    infile.ignore();


    Point origin[5], rot[5], scale[5];
    for (int i = 0;i < 5;i++) {
        if (!(infile >> origin[i].x >> origin[i].y)) {
            std::cerr << "��ȡorigin����\n";
            return 1;
        }
        infile.ignore();

        if (!(infile >> rot[i].x >> rot[i].y)) {
            std::cerr << "��ȡrot����\n";
            return 1;
        }
        infile.ignore();

        if (!(infile >> scale[i].x >> scale[i].y)) {
            std::cerr << "��ȡscale����\n";
            return 1;
        }
        infile.ignore();
    }

    int vecSize;
    if (!(infile >> vecSize)) {
        std::cerr << "��ȡstart��С����\n";
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
            std::cerr << "ת��startԪ��" << i << "����: " << e.what() << "\n";
            return 1;
        }
    }
    infile.ignore();


    if (!(infile >> vecSize)) {
        std::cerr << "��ȡendPlace��С����\n";
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
            std::cerr << "ת��endPlaceԪ��" << i << "����: " << e.what() << "\n";
            return 1;
        }
    }
    infile.ignore();


    if (!(infile >> vecSize)) {
        std::cerr << "��ȡstep��С����\n";
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
            std::cerr << "ת��stepԪ��" << i << "����: " << e.what() << "\n";
            return 1;
        }
    }
    infile.ignore();



    // ��ӡ���յ������� (����������Ϣ) -  ����˴�����
    std::cout << "���յ�������:\n";
    std::cout << "Cal: "; for (const auto& s : Cal) std::cout << s << " "; std::cout << "\n";
    //std::cout << "ConstID1 (type: " << typeid(ConstID1).name() << "): "; while (!ConstID1.empty()) { std::cout << ConstID1.front() << " "; ConstID1.pop(); } std::cout << "\n";
    //std::cout << "ConstID2 (type: " << typeid(ConstID2).name() << "): "; while (!ConstID2.empty()) { std::cout << ConstID2.front() << " "; ConstID2.pop(); } std::cout << "\n";
    for (int i = 0;i < 5;i++) {
        std::cout << "origin"<<i<<": (" << origin[i].x << ", " << origin[i].y << ")\n";
        std::cout << "rot" << i << ": (" << rot[i].x << ", " << rot[i].y << ")\n";
        std::cout << "scale" << i << ": (" << scale[i].x << ", " << scale[i].y << ")\n";
    }
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




    //�õ�������ʽ�ĺ�׺���ʽ�����Cal��ÿ��Ԫ����
//�õ��ĳ������� ConstID ����
//���Ը����������ÿ��x��y��Ӧ������
    sf::RenderWindow window(sf::VideoMode(800, 600), "draw"); //����һ��800x600���صĴ��ڣ�����Ϊ"draw"
    window.setFramerateLimit(60); //��֡������Ϊ60֡ÿ�룬ʹ����������


    
    std::vector<sf::Vector2f>points1;
    std::vector<sf::Vector2f>points2;

    Queue<float> tempID1 = ConstID1;
    Queue<float> tempID2 = ConstID2;

    if (Cal[0] != "") {
        for (float i = start[0]; i < endPlace[0]; i = i + step[0]) {
            float tempx = scale[0].x * calValue(Cal[0], ConstID1, i);
            float tempy = scale[0].y * calValue(Cal[1], ConstID2, i);
            ConstID1 = tempID1;
            ConstID2 = tempID2;
            float x = tempx * cos(rot[0].x) + tempy * sin(rot[0].x) + origin[0].x;          // x�����0��400
            float y = tempy * cos(rot[0].x) - tempx * sin(rot[0].x) + origin[0].y;          // ����y = 2x����y����
            points1.push_back(sf::Vector2f(x, y));
        }
        calValue(Cal[0], ConstID1, 0);
        calValue(Cal[1], ConstID2, 0);
    }
    

    Queue<float> tempID1_1 = ConstID1;
    Queue<float> tempID2_1 = ConstID2;
    
    if (Cal[2] != "") {
        for (float i = start[1]; i < endPlace[1]; i = i + step[1]) {
            float tempx = scale[1].x * calValue(Cal[2], ConstID1, i);
            float tempy = scale[1].y * calValue(Cal[3], ConstID2, i);
            ConstID1 = tempID1_1;
            ConstID2 = tempID2_1;
            float x = tempx * cos(rot[1].x) + tempy * sin(rot[1].x) + origin[1].x;
            float y = tempy * cos(rot[1].x) - tempx * sin(rot[1].x) + origin[1].y;
            points1.push_back(sf::Vector2f(x, y));
        }
        calValue(Cal[2], ConstID1, 0);
        calValue(Cal[3], ConstID2, 0);
    }

    
    Queue<float> tempID1_2 = ConstID1;
    Queue<float> tempID2_2 = ConstID2;
    if (Cal[4] != "") {
        for (float i = start[2]; i < endPlace[2]; i = i + step[2]) {
            float tempx = scale[2].x * calValue(Cal[4], ConstID1, i);
            float tempy = scale[2].y * calValue(Cal[5], ConstID2, i);
            ConstID1 = tempID1_2;
            ConstID2 = tempID2_2;
            float x = tempx * cos(rot[2].x) + tempy * sin(rot[2].x) + origin[2].x;
            float y = tempy * cos(rot[2].x) - tempx * sin(rot[2].x) + origin[2].y;
            points1.push_back(sf::Vector2f(x, y));

        }
        calValue(Cal[4], ConstID1, 0);
        calValue(Cal[5], ConstID2, 0);
    }


    Queue<float> tempID1_3 = ConstID1;
    Queue<float> tempID2_3 = ConstID2;
    if (Cal[6] != "") {
        for (float i = start[3]; i < endPlace[3]; i = i + step[3]) {
            float tempx = scale[3].x * calValue(Cal[6], ConstID1, i);
            float tempy = scale[3].y * calValue(Cal[7], ConstID2, i);
            ConstID1 = tempID1_3;
            ConstID2 = tempID2_3;
            float x = tempx * cos(rot[3].x) + tempy * sin(rot[3].x) + origin[3].x;
            float y = tempy * cos(rot[3].x) - tempx * sin(rot[3].x) + origin[3].y;
            points1.push_back(sf::Vector2f(x, y));
        }
        calValue(Cal[6], ConstID1, 0);
        calValue(Cal[7], ConstID2, 0);
    }


    Queue<float> tempID1_4 = ConstID1;
    Queue<float> tempID2_4 = ConstID2;
    if (Cal[8] != "") {
        for (float i = start[4]; i < endPlace[4]; i = i + step[4]) {
            float tempx = scale[4].x * calValue(Cal[8], ConstID1, i);
            float tempy = scale[4].y * calValue(Cal[9], ConstID2, i);
            ConstID1 = tempID1_4;
            ConstID2 = tempID2_4;
            float x = tempx * cos(rot[4].x) + tempy * sin(rot[4].x) + origin[4].x;
            float y = tempy * cos(rot[4].x) - tempx * sin(rot[4].x) + origin[4].y;
            points1.push_back(sf::Vector2f(x, y));
        }
        calValue(Cal[8], ConstID1, 0);
        calValue(Cal[9], ConstID2, 0);
    }
    


    // ��ѭ�������ڴ����¼�����Ⱦ
    while (window.isOpen()) {
        sf::Event event; // ����һ���¼�����
        while (window.pollEvent(event)) { // ����Ƿ����¼�����
            if (event.type == sf::Event::Closed) // ����¼������ǹرմ���
                window.close(); // �رմ���
        }

        // ���õ����״��Բ�Σ�
        sf::CircleShape pointShape(3.f); // ����һ���뾶Ϊ3���ص�Բ��
        pointShape.setFillColor(sf::Color::Blue); // ���õ�һ��ɢ��ͼ�ĵ����ɫΪ��ɫ
        window.clear(); // �����������

        for (const auto& point : points1) { // ������һ��ɢ��ͼ�ĵ�����
            pointShape.setPosition(point); // ����Բ�ε�λ��
            window.draw(pointShape);       // ����Բ��
        }

        window.display(); // ���´�����ʾ

    }




    infile.close();
    return 0;
}