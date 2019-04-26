//For Adora Lauren
#include"Base_Data.h"
#include"STL.h"
#include"Value.h"
#include"Operator.h"
#include"declarations.h"
#include"namespace.h"
using namespace mystd;

int main() {
    map<string,Base_Data*> store;
    //first part
    input_description(store);
    //second part
    input_node(store);
    //third part
    input_operation(store);
    return 0;
}