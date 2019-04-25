#pragma once
#include"Base_Data.h"
// class Elementary_Value
// {
//     float data;
// public:
//     virtual ~Elementary_Value()=0;

// };

class Placeholder : public Base_Data
{
    using Base_Data::Base_Data;
    Placeholder(float)=delete;
};

//开始时就已经赋值，不能改动
class Constant : public Base_Data
{
public:
    using Base_Data::Base_Data;
    // Constant(float value):data(value){}
};


//可提前赋初值，也可截获中间计算结果，中间赋初值
class Variable : public Base_Data
{
public:
    using Base_Data::Base_Data;

};