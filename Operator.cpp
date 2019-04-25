#include"Operator.h"
#include"namespace.h"
using namespace mystd;

Plus::Plus(Base_Data* left,Base_Data* right)
{
    set_ptr(left,right);
    set_data(left->get_data()+right->get_data());
}

Print::Print(Base_Data* src)
{
    set_ptr(src);
    set_data(src->get_data());
    cout<<"Print Operator: "<<name<<"="<<get_data()<<endl;

}