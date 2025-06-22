
#pragma once
#include <iostream>
#include <string>

class DataBase {
private:
    std::string m_name;
    int m_record;
    static DataBase* m_intance_ptr;  

    DataBase(std::string name){
        m_name = name;
        m_record = 0;
    }

public:
    std::string get_name(){
        return m_name;
    }

    int get_record(){
        return m_record;
    }

    void editRecord(std::string operation)
    {
        std::cout << "Performing a " << operation <<
                "operation on record " << m_record <<
                " in database " << m_name << std::endl;
    }

    static DataBase* get_instance(std::string name){
        if (m_intance_ptr == nullptr){
            m_intance_ptr = new DataBase(name);
        }

        return m_intance_ptr;
    }
}