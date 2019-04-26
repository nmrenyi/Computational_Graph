#pragma once
#include"STL.h"
#include"Base_Data.h"
#include"namespace.h"
using namespace mystd;

class Placeholder : public Base_Data {
public:
    using Base_Data::Base_Data;
    Placeholder(float) = delete;
    pair<bool, float> calc();
};
//开始时就已经赋值，不能改动
class Constant : public Base_Data {
private:
    const float data; // 把基类的data重写隐藏
public:
    // using Base_Data::Base_Data;
    Constant(float value);
    pair<bool, float> calc();
};
//可提前赋初值，也可截获中间计算结果，中间赋初值
class Variable : public Base_Data {
public:
    using Base_Data::Base_Data;
    pair<bool, float> calc();
};

// class Elementary_Value {
//     float data;
// public:
//     virtual ~Elementary_Value()=0;
// };