#include"Base_Data.h"
Base_Data::Base_Data(){}
Base_Data::Base_Data(float value):data(value){}
void Base_Data::set_data(float dst){data=dst;}
float Base_Data:: get_data(){return data;}

void Base_Data::set_ptr(Base_Data* left,Base_Data* right)
{
    ptr[0]=left;
    ptr[1]=right;
}
float Base_Data::calc()
{
    if(ptr[0]==nullptr&&ptr[1]==nullptr)
        return data;
    return ptr[0]->calc()+ptr[1]->calc();
}