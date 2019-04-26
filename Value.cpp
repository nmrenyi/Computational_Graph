#include"STL.h"
#include"Value.h"
#include"namespace.h"
using namespace mystd;

pair<bool, float> Placeholder::calc() {
    return std::make_pair(0, data);
}

Constant::Constant(float value) : data(value) {}
pair<bool, float>  Constant::calc() {
    return std::make_pair(0, data);

}
pair<bool, float>  Variable::calc() {
    return std::make_pair(0, data);
}