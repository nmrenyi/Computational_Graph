#pragma once
#include<string>
#include<iostream>
#include"Base_Data.h"
using std::endl;
using std::string;
using std::cout;
//one parametre
class Unary_Operator:public Base_Data
{
    // Base_Data* ptr[1];

};

//Binary operator with two parametres
// class Binary_Operator:public Base_Data
// {
//     // Base_Data* ptr[2];
// public:
//     void set();
// };


//three parametre
class Ternary_Operator:public Base_Data
{

};

class Plus:public Base_Data
{
public:
    Plus(Base_Data* left,Base_Data* right)
    {
        set_ptr(left,right);
        set_data(left->get_data()+right->get_data());
    }
};


class Print:public Base_Data
{
    string name;
public:
    Print(Base_Data* src)
    {
        set_ptr(src);
        set_data(src->get_data());
        cout<<"Print Operator: "<<name<<"="<<get_data()<<endl;

    }
    void print()
    {

    }
};