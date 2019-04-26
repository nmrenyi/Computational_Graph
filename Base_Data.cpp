#include"Base_Data.h"

set<int> Base_Data::my_error_set {0}; // 类外定义静态变量
Base_Data::Base_Data() {}
Base_Data::Base_Data(float value):data(value) {}
Base_Data::~Base_Data() {
    delete ptr[0];
    delete ptr[1];
}
float Base_Data::set_data(float dst) {
    data = dst;
    return data;
}
float Base_Data:: get_data() {
    return data;
}
void Base_Data::rm_errors() {
    my_error_set.clear();
}
void Base_Data::set_ptr(Base_Data* left,Base_Data* right) {
    ptr[0]=left;
    ptr[1]=right;
}

std::pair<bool, float> Base_Data::calc() {
    return std::make_pair(0, 0.0);
}