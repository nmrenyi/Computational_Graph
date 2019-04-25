#include"STL.h"
#include"declarations.h"
#include"Base_Data.h"
#include"Operator.h"
#include"Value.h"

//split input line into vector units
vector<string> input()
{
    string line;
    getline(cin,line);
    std::stringstream ss;
    ss<<line;
    string tmp;
    vector<string>info;
    while(ss>>tmp)
        info.push_back(tmp);
    return info;
}


//input the first part:the descriptions of placeholders, constants, variables
void input_description(map<string,Base_Data*>& store)
{
    int description=0;

    cin>>description;
    cin.get();
    //array/map of placeholders, variables, constants
    //Base_Data* Elementary_Value=new Base_Data[description];

    for(int i=0;i<description;i++)
    {
        vector<string>info=input();
        if(info[1]=="P")
            store[info[0]]=new Placeholder;
        else if(info[1]=="C")
            store[info[0]]=new Constant(std::stof(info[2]));
        else if(info[1]=="V")
            store[info[0]]=new Variable(std::stof(info[2]));
        else
            cout<<"Invalid input type"<<endl;
    }

}

//input the second part:define the nodes
void input_node(map<string,Base_Data*>& store)
{
    int node=0;
    cin>>node;
    cin.get();
    for(int i=0;i<node;i++)
    {
        vector<string>info=input();
        string name=info[0];
        
        if(info.size()==5)//binary operator only Plus is available
        {
            string left_name=info[2];
            string operator_name=info[3];
            string right_name=info[4];
            store[name]=new Plus(store[left_name],store[right_name]);
        }

        else if(info.size()==4)
        {
            string operator_name=info[2];
            string value_name=info[3];
            //only for Print
            if(store.find(name)==store.end())
                store[name]=new Print(store[value_name]);
        }
    }

}

//input the third part: make the operations
void input_operation(map<string,Base_Data*>& store)
{
    int operation=0;
    cin>>operation;
    cin.get();
    for(int i=0;i<operation;i++)
    {
        vector<string>info=input();
        int give_value_num=std::stoi(info[2]);
        string target_name=info[1];
        for(int j=0;j<give_value_num;j++)
        {
            string name=info[3+2*j];
            float value=std::stof(info[4+2*j]);
            store[name]->set_data(value);
        }
        store[target_name]->set_data(store[target_name]->calc());
    }
}