#include "data_base.h"

int main(){

    DataBase* data_base = nullptr;
    
    data_base = DataBase::get_instance("products");
    std::cout << "This is the " << data_base->get_name() << " database." << std::endl;
    
    data_base = DataBase::get_instance("employees");
    std::cout << "This is the " << data_base->get_name() << " database." << std::endl;
    
    return 0;
}