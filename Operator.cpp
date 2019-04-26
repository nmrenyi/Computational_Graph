#include"STL.h"
#include"Operator.h"
#include"namespace.h"
using namespace mystd;
// 二目运算符
Plus::Plus(Base_Data* left, Base_Data* right) {
    set_ptr(left, right);
    set_data(left->get_data() + right->get_data());
}
pair<bool, float> Plus::calc() {
    if(!caled) { // 判断是否计算过了
        if(ptr[0] != nullptr && ptr[1] != nullptr) { // 可以相加
            pair<bool, float> left = ptr[0]->calc();
            pair<bool, float> right = ptr[1]->calc();
            if(!left.first && !right.first) {
                caled = 1;
                return std::make_pair(0, set_data(left.second + right.second));
            }
            else // 前面的步骤有错误，无法相加
                return std::make_pair(1, 0.0);
        }
        else { // 加法错误
            my_error_set.insert(1);
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data); 
}
Minus::Minus(Base_Data* left, Base_Data* right) {
    set_ptr(left, right);
    set_data(left->get_data() - right->get_data());
}
pair<bool, float> Minus::calc() {
    if(!caled) {
        if(ptr[0] != nullptr && ptr[1] != nullptr) { // 可以相减
            pair<bool, float> left = ptr[0]->calc();
            pair<bool, float> right = ptr[1]->calc();
            if(!left.first && !right.first) {
                caled = 1;
                return std::make_pair(0, set_data(left.second - right.second));
            }
            else // 前面的步骤有错误，无法相加
                return std::make_pair(1, 0.0);
        }
        else { // 加法错误
            my_error_set.insert(2);
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data);
}
Multiply::Multiply(Base_Data* left, Base_Data* right) {
    set_ptr(left, right);
    set_data(left->get_data() * right->get_data());
}
pair<bool, float> Multiply::calc() {
    if(!caled) {
        if(ptr[0] != nullptr && ptr[1] != nullptr) { // 可以相乘
            pair<bool, float> left = ptr[0]->calc();
            pair<bool, float> right = ptr[1]->calc();
            if(!left.first && !right.first) {
                caled = 1;
                return std::make_pair(0, set_data(left.second * right.second));
            }
            else // 前面的步骤有错误，无法相加
                return std::make_pair(1, 0.0);
        }
        else { // 加法错误
            my_error_set.insert(3);
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data);
}
Divide::Divide(Base_Data* left, Base_Data* right) {
    set_ptr(left, right);
    if(right->get_data() == 0)
        set_data(0.0);
    else 
        set_data(left->get_data() / right->get_data());
}
pair<bool, float> Divide::calc() {
    if(!caled) {
        if(ptr[0] != nullptr && ptr[1] != nullptr) { // 可以相加
            pair<bool, float> left = ptr[0]->calc();
            pair<bool, float> right = ptr[1]->calc();
            if(!left.first && !right.first) {
                if(right.second == 0) {
                    my_error_set.insert(5);
                    return std::make_pair(1, 0.0);
                }                
                else {
                    caled = 1;
                    return std::make_pair(0, set_data(left.second * right.second));
                }
            }
            else // 前面的步骤有错误，无法相加
                return std::make_pair(1, 0.0);
        }
        else { // 加法错误
            my_error_set.insert(4);
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data);
}
// 单目运算符
Sin::Sin(Base_Data* src) {
    set_ptr(src);
    set_data(sin(src->get_data()));
}
pair<bool, float> Sin::calc() {
    if(!caled) {
        if(ptr[0] != nullptr) {
            pair<bool, float> src = ptr[0]->calc();
            if(!src.first) {
                caled = 1;
                return std::make_pair(0, sin(src.second));
            }
            else 
                return std::make_pair(1, 0.0);
        }
        else {
            my_error_set.insert(10);
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data);
}
Log::Log(Base_Data* src) {
    set_ptr(src);
    if(src->get_data() >= 1e-5)
        set_data(log(src->get_data()));
    else 
        set_data(0.0);
}
pair<bool, float> Log::calc() {
    if(!caled) {
        if(ptr[0] != nullptr) {
            pair<bool, float> src = ptr[0]->calc();
            if(!src.first) {
                if(src.second >= 1e-5) {
                    caled  = 1;
                    return std::make_pair(0, set_data(sin(src.second)));
                }
                else {
                    my_error_set.insert(12);
                    return std::make_pair(1, 0.0);
                }
            }
            else 
                return std::make_pair(1, 0.0);
        }
        else {
            my_error_set.insert(11);
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data);
}
Exp::Exp(Base_Data* src) {
    set_ptr(src);
    set_data(exp(src->get_data()));
}
pair<bool, float> Exp::calc() {
    if(!caled) {
        if(ptr[0] != nullptr) {
            pair<bool, float> src = ptr[0]->calc();
            if(!src.first) {
                caled = 1;
                return std::make_pair(0, set_data(exp(src.second)));
            }
            else 
                return std::make_pair(1, 0.0);
        }
        else {
            my_error_set.insert(13);
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data);
}
Tanh::Tanh(Base_Data* src) {
    set_ptr(src);
    float tmp = exp(src->get_data());
    set_data((tmp - 1 / tmp) / (tmp + 1 / tmp));
}
pair<bool, float> Tanh::calc() {
    if(!caled) {
        if(ptr[0] != nullptr) {
            pair<bool, float> src = ptr[0]->calc();
            if(!src.first) {
                caled = 1;
                float tmp = exp(src.second);
                return std::make_pair(0, set_data((tmp - 1 / tmp) / (tmp + 1 / tmp)));
            }
            else 
                return std::make_pair(1, 0.0);
        }
        else {
            my_error_set.insert(14);
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data);
}
Sigmoid::Sigmoid(Base_Data* src) {
    set_ptr(src);
    set_data(1.0 / (1.0 + exp( - src->get_data())));
}
pair<bool, float> Sigmoid::calc() {
    if(!caled) {
        if(ptr[0] != nullptr) {
            pair<bool, float> src = ptr[0]->calc();
            if(!src.first) {
                caled = 1;
                return std::make_pair(0, set_data(1.0 / (1.0 + exp( - src.second))));
            }
            else 
                return std::make_pair(1, 0.0);
        }
        else {
            my_error_set.insert(15);
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data);
}
Print::Print(Base_Data* src) {
    set_ptr(src);
    set_data(src->get_data());
    // cout << "Print Operator: " << name << "=" << data << endl;
}
pair<bool, float> Print::calc() {
    if(!caled) {
        pair<bool, float> src = ptr[0]->calc();
        if(!src.first) {
            caled = 1;
            return std::make_pair(0, set_data(src.second));
            cout << "Print Opertor: " << name << "=" << data << endl;
        }
        else 
            return std::make_pair(1, 0.0);
    }
    else {
        return std::make_pair(0, data);
        cout << "Print Opertor: " << name << "=" << data << endl;
    }
}
// 二目比较运算符
More::More(Base_Data* left, Base_Data* right) {
    set_ptr(left, right);
    if(left->get_data() - right->get_data() >= 1e-5) 
        set_data(1.0);
    else set_data(0.0);
}
pair<bool, float> More::calc() {
    if(!caled) { // 判断是否计算过了
        if(ptr[0] != nullptr && ptr[1] != nullptr) {
            pair<bool, float> left = ptr[0]->calc();
            pair<bool, float> right = ptr[1]->calc();
            if(!left.first && !right.first) {
                caled = 1;
                if(left.second - right.second >= 1e-5)
                    return std::make_pair(0, set_data(1.0));
                else return std::make_pair(0, set_data(0.0));
            }
            else // 前面的步骤有错误，无法相加
                return std::make_pair(1, 0.0);
        }
        else { // 错误
            my_error_set.insert(20);
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data); 
}
Less::Less(Base_Data* left, Base_Data* right) {
    set_ptr(left, right);
    if(left->get_data() - right->get_data() <= -1e-5) 
        set_data(1.0);
    else set_data(0.0);
}
pair<bool, float> Less::calc() {
    if(!caled) { // 判断是否计算过了
        if(ptr[0] != nullptr && ptr[1] != nullptr) {
            pair<bool, float> left = ptr[0]->calc();
            pair<bool, float> right = ptr[1]->calc();
            if(!left.first && !right.first) {
                caled = 1;
                if(left.second - right.second <= -1e-5)
                    return std::make_pair(0, set_data(1.0));
                else return std::make_pair(0, set_data(0.0));
            }
            else // 前面的步骤有错误，无法相加
                return std::make_pair(1, 0.0);
        }
        else { // 错误
            my_error_set.insert(21);
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data); 
}
More_eq::More_eq(Base_Data* left, Base_Data* right) {
    set_ptr(left, right);
    if(left->get_data() - right->get_data() >= -1e-5) 
        set_data(1.0);
    else set_data(0.0);
}
pair<bool, float> More_eq::calc() {
    if(!caled) { // 判断是否计算过了
        if(ptr[0] != nullptr && ptr[1] != nullptr) {
            pair<bool, float> left = ptr[0]->calc();
            pair<bool, float> right = ptr[1]->calc();
            if(!left.first && !right.first) {
                caled = 1;
                if(left.second - right.second >= -1e-5)
                    return std::make_pair(0, set_data(1.0));
                else return std::make_pair(0, set_data(0.0));
            }
            else // 前面的步骤有错误，无法相加
                return std::make_pair(1, 0.0);
        }
        else { // 错误
            my_error_set.insert(22);
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data); 
}
Less_eq::Less_eq(Base_Data* left, Base_Data* right) {
    set_ptr(left, right);
    if(left->get_data() - right->get_data() <= 1e-5) 
        set_data(1.0);
    else set_data(0.0);
}
pair<bool, float> Less_eq::calc() {
    if(!caled) { // 判断是否计算过了
        if(ptr[0] != nullptr && ptr[1] != nullptr) {
            pair<bool, float> left = ptr[0]->calc();
            pair<bool, float> right = ptr[1]->calc();
            if(!left.first && !right.first) {
                caled = 1;
                if(left.second - right.second <= 1e-5)
                    return std::make_pair(0, set_data(1.0));
                else return std::make_pair(0, set_data(0.0));
            }
            else // 前面的步骤有错误，无法相加
                return std::make_pair(1, 0.0);
        }
        else { // 错误
            my_error_set.insert(23);
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data); 
}
Equal::Equal(Base_Data* left, Base_Data* right) {
    set_ptr(left, right);
    if(fabs(left->get_data() - right->get_data()) <= 1e-5) 
        set_data(1.0);
    else set_data(0.0);
}
pair<bool, float> Equal::calc() {
    if(!caled) { // 判断是否计算过了
        if(ptr[0] != nullptr && ptr[1] != nullptr) {
            pair<bool, float> left = ptr[0]->calc();
            pair<bool, float> right = ptr[1]->calc();
            if(!left.first && !right.first) {
                caled = 1;
                if(fabs(left.second - right.second) <= 1e-5)
                    return std::make_pair(0, set_data(1.0));
                else return std::make_pair(0, set_data(0.0));
            }
            else // 前面的步骤有错误，无法
                return std::make_pair(1, 0.0);
        }
        else { // 错误
            my_error_set.insert(20);
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data);
}
// 三目运算符
COND::COND(Base_Data* condition, Base_Data* left, Base_Data* right) {
    cond = condition;
    set_ptr(left, right);
    if(cond->get_data() >= 1e-5) set_data(left->get_data());
    else set_data(right->get_data());
}
pair<bool, float> COND::calc() {
    if(!caled) {
        pair<bool, float> tmp = cond->calc();
        pair<bool, float> left = ptr[0]->calc();
        pair<bool, float> right = ptr[1]->calc();
        if(!tmp.first && !left.first && !right.first) {
            caled = 1;
            if(tmp.second <= -1e-5) {
                return std::make_pair(0, set_data(right.second));
            }
            else return std::make_pair(0, set_data(left.second));
        }
        else {
            return std::make_pair(1, 0.0);
        }
    }
    else return std::make_pair(0, data);
}