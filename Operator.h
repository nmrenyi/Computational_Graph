//如文件名，本文件为单目运算符和双目运算符的类
#pragma once
#include<string>
#include<iostream>
#include"Base_Data.h"
#include"namespace.h"
using namespace mystd;
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


//three parametre
// class Ternary_Operator:public Base_Data
// {

// };

class Plus:public Base_Data
{
public:
    Plus(Base_Data*,Base_Data*);
};


class Print:public Base_Data
{
    string name;
public:
    Print(Base_Data*);
};