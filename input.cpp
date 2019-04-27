#include"STL.h"
#include"declarations.h"
#include"Base_Data.h"
#include"Operator.h"
#include"Value.h"
using namespace mystd;
//split input line into vector units
vector<string> input() {
    string line;
    getline(cin, line);
    std::stringstream ss;
    ss << line;
    string tmp;
    vector<string> info;
    while(ss >> tmp)
        info.push_back(tmp);
    return info;
}
// input the first part:the descriptions of placeholders, constants, variables
void input_description(map<string, Base_Data*>& store) {
    int description = 0;
    cin >> description;
    cin.get();
    for(int i = 0; i < description; i++) {
        vector<string> info = input();
        if(info[1].compare("P") == 0)
            store[info[0]] = new Placeholder;
        else if(info[1].compare("C") == 0)
            store[info[0]] = new Constant(std::stof(info[2]));
        else if(info[1].compare("V") == 0)
            store[info[0]] = new Variable(std::stof(info[2]));
        else
            cout << "Invalid input type" << endl;
    }
}

// input the second part:define the nodes
void input_node(map<string,Base_Data*>& store) {
    int node;
    cin >> node;
    cin.get();
    for(int i = 0; i < node; i++) {
        vector<string> info = input();
        string name = info[0];
        if(info.size() == 5) { // 这里是双目运算符
            string left_name = info[2];
            string operator_name = info[3];
            string right_name = info[4];
            if(operator_name.compare("+") == 0)
                store[name] = new Plus(store[left_name], store[right_name]);
            else if(operator_name.compare("-") == 0)
                store[name] = new Minus(store[left_name], store[right_name]);
            else if(operator_name.compare("*") == 0)
                store[name] = new Multiply(store[left_name], store[right_name]);
            else if(operator_name.compare("/") == 0)
                store[name] = new Divide(store[left_name], store[right_name]);
            else if(operator_name.compare(">") == 0)
                store[name] = new More(store[left_name], store[right_name]);
            else if(operator_name.compare("<") == 0)
                store[name] = new Less(store[left_name], store[right_name]);
            else if(operator_name.compare(">=") == 0)
                store[name] = new More_eq(store[left_name], store[right_name]);
            else if(operator_name.compare("<=") == 0)
                store[name] = new Less_eq(store[left_name], store[right_name]);
            else if(operator_name.compare("==") == 0)
                store[name] = new Equal(store[left_name], store[right_name]);
            else 
                cout << "Wrong operator name" << endl;
        }
        else if(info.size() == 4) { //单目运算符
            string operator_name = info[2];
            string value_name = info[3];
            if(operator_name.compare("sin") == 0)
                store[name] = new Sin(store[value_name]);
            else if(operator_name.compare("log") == 0)
                store[name] = new Log(store[value_name]);
            else if(operator_name.compare("exp") == 0)
                store[name] = new Exp(store[value_name]);
            else if(operator_name.compare("tanh") == 0)
                store[name] = new Tanh(store[value_name]);
            else if(operator_name.compare("sigmoid") == 0)
                store[name] = new Sigmoid(store[value_name]);
            else if(operator_name.compare("print") == 0) {
                if(store.find(name) == store.end())
                    store[name] = new Print(store[value_name]);
                else cout << "Invalid print reference" << endl;
            }
            else cout << "Invalid operator name" << endl;
        }
        else if(info.size() == 6) { // COND 运算符,还没有写!**********
            store[name] = new COND(store[info[3]],store[info[4]],store[info[5]]);
        }

        else 
            cout<<"Invalid input in node defining"<<endl;
    }
}

// input the third part: make the operations
// 本部分有待完善，尤其是variable的功能
// 每一行的语句循环前应该对caled进行重新初始化
void input_operation(map<string,Base_Data*>& store) {
    int operation = 0;
    cin >> operation;
    cin.get();
    for(int i = 0; i < operation; i++) {
        vector<string> info = input();
        int given_value_num = std::stoi(info[2]);
        string target_name = info[1];
        for(int j = 0; j < given_value_num; j++) {
            string name = info[3 + 2 * j];
            float value = std::stof(info[4 + 2 * j]);
            store[name]->set_data(value); 
        }
        // **************next is not right
        cout << store[target_name]->set_data(store[target_name]->calc().second) << endl;
    }
}