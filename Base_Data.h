//如文件名，本文件为Base_Data类
#pragma once
#include<map>
#include<string>
class Base_Data
{
    // Base_Data* ptr[2]={nullptr,nullptr};//方便储存依赖关系与判断
    Base_Data* ptr[2]={nullptr,nullptr};//方便储存依赖关系与判断
    float data;
public:
    Base_Data();
    Base_Data(float);
    void set_ptr(Base_Data*,Base_Data* default_ptr=nullptr);
    void set_data(float);
    float get_data();
    float calc();
};
