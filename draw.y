%{
    #include "calValue.cpp"
    #include <fstream>
    #include <vector>
    #include <cstdlib> // for system()
    #include <sstream>

    using namespace std;
    extern int yylex();
    void yyerror(const char *s) {
        printf("Error: %s\n", s);
    }
    string Cal[10];

    int count1=0;

    float start[5],endPlace[5],step[5];
    int count_ses = 0; //作为上面三个数组的索引

    Queue<float>ConstID1;//常数队列
    Queue<float>ConstID2;//常数队列

    typedef struct{
        float x;
        float y;
    }Point;

    Point origin;
    Point rot;
    Point scale={1,1};
    string test;//检测:绘图语句中，前后的ID是否相同。test用来存放第一个ID
    string calculator;//用于存放运算顺序，每一次运算都用一位数字表示，通过查表获取其含义

    int flag_xOry = 0;//用来判断当前应该入x的常数队列还是y的常数队列

    int ID_flag = 0;
%}

%union{
    int int_val;
    float float_val;
}
%token <float_val>CONST_ID
%token ID PI
%token ORIGIN SCALE ROT IS FOR FROM TO STEP DRAW
%token PLUS MINUS MUL DIV POWER
%token L_BRACKET R_BRACKET COMMA COMMENT FENHAO
%token EOL
%token SIN COS TAN SQRT EXP LN

%left PLUS MINUS
%left DIV MUL POWER

%%
program:
    statements
    ;

statements:
    statement FENHAO EOL{

    }
    |statements statement FENHAO EOL{
        //printf("成功识别");
    }
    ;

statement:
    /*
    ROT IS CONST_ID{
        //旋转(逆时针CONST_ID)
        rot.x = $3;
        printf("rot is set to %.2f\n",rot.x);
    }
    |ORIGIN IS L_BRACKET CONST_ID COMMA CONST_ID R_BRACKET{
        //设置原点(默认左上角顶点)
        origin.x = $4;
        origin.y = $6;
        printf("origin is set to(%.2f,%.2f)\n",origin.x,origin.y);
    }
    |SCALE IS L_BRACKET CONST_ID COMMA CONST_ID R_BRACKET{
        //设置x,y轴比例
        scale.x = $4;
        scale.y = $6;
        printf("scale is set to (%.2f,%.2f)\n",scale.x,scale.y);
    }
    |FOR ID FROM CONST_ID TO CONST_ID STEP CONST_ID DRAW L_BRACKET expressions COMMA expressions R_BRACKET{
        //绘制图像
        start[count_ses] = $4;
        endPlace[count_ses] = $6;
        step[count_ses] = $8;
        //test = $2;
        count_ses++;
    }
    */

    ROT IS expressions{
        //旋转(逆时针CONST_ID)
        rot.x = $3;
        printf("rot is set to %.2f\n",rot.x);
    }
    |ORIGIN IS L_BRACKET expressions COMMA expressions R_BRACKET{
        //设置原点(默认左上角顶点)
        origin.x = $4;
        origin.y = $6;
        printf("origin is set to(%.2f,%.2f)\n",origin.x,origin.y);
    }
    |SCALE IS L_BRACKET expressions COMMA expressions R_BRACKET{
        //设置x,y轴比例
        scale.x = $4;
        scale.y = $6;
        printf("scale is set to (%.2f,%.2f)\n",scale.x,scale.y);
    }
    |FOR ID FROM expressions TO expressions STEP expressions DRAW L_BRACKET expressions COMMA expressions R_BRACKET{
        //绘制图像
        start[count_ses] = $4;
        endPlace[count_ses] = $6;
        step[count_ses] = $8;
        //test = $2;
        count_ses++;
    }
    ;

expressions:
    expression{
        //expression是加减乘除乘方后的结果
        Cal[count1] = calculator;
        calculator = "";
        count1++;
    }
    ;

expression:
    factor{
    //factor:乘方乘除后结果
    }
    |expression PLUS expression{
        //$$ = $1 + $3;
        calculator += "6";
    }
    |expression MINUS expression{
        //$$ =$1 - $3;
        calculator += "7";
    }
    ;

factor:
    exp1{
        //一元加减结果
    }
    |factor MUL factor{
        //$$ = $1 * $3;
        calculator += "4";
    }
    |factor DIV factor{
        //$$ = $1 / $3;
        //if($3==0){yyerror("除数为0");}
        calculator += "5";
    }
    ;

exp1:
    exp2{
        //乘方结果
    }
    |PLUS exp2{
        //一元加
        calculator += "2";

    }
    |MINUS exp2{
        //一元减
        calculator += "3";
    }

exp2:
    CONST_ID{//常量
        calculator += "Y";
        float constid = $1;
        if(count1%2==0){
            ConstID1.enqueue(constid);
            flag_xOry++;
        }
        else if(count1%2==1){
            ConstID2.enqueue(constid);
            flag_xOry = 0;
        }
        else{
            yyerror("x/y 队列异常");
        }

    }
    |ID{//需要检测此ID和绘图处的ID是否匹配
        //if(test!=$1){yyerror("前后ID不匹配");}
        calculator += "Z";
    }
    |L_BRACKET expression R_BRACKET{
        //带括号的式子:递归到expression
        //不需要其它动作，能识别并递归就行
    }
    |exp2 POWER exp2{//乘方
        calculator += "1";
    }
    |SIN L_BRACKET expression R_BRACKET{
            //sin
        calculator += "8";
    }
    |COS L_BRACKET expression R_BRACKET{
            //cos
        calculator += "9";
    }
    |TAN L_BRACKET expression R_BRACKET{
            //tan
        calculator += "A";
    }
    |SQRT L_BRACKET expression R_BRACKET{
            //sqrt
        calculator += "B";
    }
    |EXP L_BRACKET expression R_BRACKET{
            //exp
        calculator += "C";
    }
    |LN L_BRACKET expression R_BRACKET{
            //ln
        calculator += "D";
    }
    ;

%%


int main(int argc, char **argv)
{
    yyparse();

    for(int i=0;i<10;i++){
        cout<<Cal[i]<<endl;
    }

    //Cal[0] = "Z9";
    //Cal[1] = "ZA";

    std::ofstream outfile("params.txt");
    if (!outfile.is_open()) {
        std::cerr << "无法打开文件进行写入。\n";
        return 1;
    }

    outfile << "10" << "\n";
    for (const auto& s : Cal) outfile << s << "\n";

    outfile << ConstID1.size() << "\n";
    Queue<float> temp1 = ConstID1;
    while (!temp1.empty()) { outfile << temp1.dequeue() << " "; } outfile << "\n";

    outfile << ConstID2.size() << "\n";
    Queue<float> temp2 = ConstID2;
    while (!temp2.empty()) { outfile << temp2.dequeue() << " "; } outfile << "\n";

    outfile << origin.x << " " << origin.y << "\n";
    outfile << rot.x << " " << rot.y << "\n";
    outfile << scale.x << " " << scale.y << "\n";

    outfile << "5" << " ";
    for (float f : start) outfile << f << " ";
    outfile << "\n";

    outfile << 5 << " ";
    for (float f : endPlace) outfile << f << " ";
    outfile << "\n";

    outfile << "5" << " ";
    for (float f : step) outfile << f << " ";
    outfile << "\n";


    outfile.close();

        int result = system("C:\\Users\\lyc\\Desktop\\3\\3.1\\BYYL\\RT+D_Rx\\x64\\Debug\\RT+D_Rx.exe");
        if (result != 0) {
            std::cerr << "执行B出错: " << result << std::endl;
            return 1;
        }
    string input;
    while(1){
        getline(cin, input); // Read a line of input

        if (input == "exit") {
            break; // Exit the loop if the input is "exit"
        }
    }
    return 0;
}