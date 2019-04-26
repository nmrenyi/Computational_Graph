//如文件名，本文件为Base_Data类
#pragma once
#include"STL.h"
#include"namespace.h"
using namespace mystd;

class Base_Data {
protected:
    Base_Data* ptr[2] = {nullptr, nullptr};//方便储存依赖关系与判断
    float data = 0;
    bool caled = 0; // 默认没有计算过
public:
    static set<int> my_error_set;
    Base_Data();
    Base_Data(float);
    virtual ~Base_Data();
    void set_ptr(Base_Data*, Base_Data* default_ptr = nullptr);
    float set_data(float);
    float get_data();
    void rm_errors();
    virtual std::pair<bool, float> calc() ;
};
