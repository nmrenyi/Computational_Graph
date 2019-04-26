//如文件名，本文件为单目运算符和双目运算符的类
#pragma once
#include"STL.h"
#include"Base_Data.h"
#include"namespace.h"
using namespace mystd;
// 二目运算符
class Plus : public Base_Data { // + 二目运算符
public:
    Plus(Base_Data*, Base_Data*);
    // ~Plus() {};
    pair<bool, float> calc();
};
class Minus : public Base_Data { // - 二目运算符
public:
    Minus(Base_Data*, Base_Data*);
    // ~Minus() {};
    pair<bool, float> calc();
};
class Multiply : public Base_Data { // * 二目运算符
public:
    Multiply(Base_Data*, Base_Data*);
    // ~Multiply();
    pair<bool, float> calc();
};
class Divide : public Base_Data { // / 二目运算符
public:
    Divide(Base_Data*, Base_Data*);
    // ~Divide();
    pair<bool, float> calc();
};
// 单目运算符
class Sin : public Base_Data { // sin 单目运算符
public:
    Sin(Base_Data*);
    pair<bool, float> calc();
};
class Log : public Base_Data { // log 单目运算符
public:
    Log(Base_Data*);
    pair<bool, float> calc();
};
class Exp : public Base_Data { // exp 单目运算符
public:
    Exp(Base_Data*);
    pair<bool, float> calc();
};
class Tanh : public Base_Data { // tanh 单目运算符
public:
    Tanh(Base_Data*);
    pair<bool, float> calc();
};
class Sigmoid : public Base_Data { // simoid 单目运算符
public:
    Sigmoid(Base_Data*);
    pair<bool, float> calc();
};
class Print : public Base_Data { // print 单目运算符
private:
    string name;
public:
    Print(Base_Data*);
    pair<bool, float> calc();
};
// 二目比较运算符
class More : public Base_Data { // 实现大于号 >
public:
    More(Base_Data*, Base_Data*);
    pair<bool, float> calc();
};
class Less : public Base_Data { // 实现小于号 <
public:
    Less(Base_Data*, Base_Data*);
    pair<bool, float> calc();
};
class More_eq : public Base_Data { // 实现大于等于号 >=
public:
    More_eq(Base_Data*, Base_Data*);
    pair<bool, float> calc();
};
class Less_eq : public Base_Data { // 实现小于等于号 <=
public:
    Less_eq(Base_Data*, Base_Data*);
    pair<bool, float> calc();
};
class Equal : public Base_Data { // 实现等于等于号 ==
public:
    Equal(Base_Data*, Base_Data*);
    pair<bool, float> calc();
};
// 三目运算符
class COND : public Base_Data {
private:
    Base_Data* cond;
public:
    COND(Base_Data*, Base_Data*, Base_Data*);
    pair<bool, float> calc();
};
//目前没有发现需要写operator2 和operator1 基类的需要
//one parametre
// class Unary_Operator:public Base_Data
// {
//     // Base_Data* ptr[1];
// };

//Binary operator with two parametres
// class Binary_Operator:public Base_Data
// {
//     // Base_Data* ptr[2];
// public:
//     void set();
// };