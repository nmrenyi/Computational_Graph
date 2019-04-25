//本文件中是函数声明
#pragma once
#include"STL.h"
#include"Base_Data.h"
#include"Operator.h"
#include"Value.h"
#include"namespace.h"
using namespace mystd;

void input_description(map<string,Base_Data*>&);
void input_node(map<string,Base_Data*>&);
void input_operation(map<string,Base_Data*>&);
vector<string> input();