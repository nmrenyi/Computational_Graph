#pragma once
#include<map>
#include<string>
class Base_Data
{
    // Base_Data* ptr[2]={nullptr,nullptr};//方便储存依赖关系与判断
    Base_Data* ptr[2]={nullptr,nullptr};//方便储存依赖关系与判断
    float data;
public:
    Base_Data()=default;
    Base_Data(float value):data(value){}
    void set_ptr(Base_Data* left,Base_Data* right=nullptr)
    {
        ptr[0]=left;
        ptr[1]=right;
    }
    void set_data(float dst){data=dst;}
    float get_data(){return data;}
    float calc()
    {
        if(ptr[0]==nullptr&&ptr[1]==nullptr)
            return data;
        return ptr[0]->calc()+ptr[1]->calc();
    }
};