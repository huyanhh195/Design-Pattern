#pragma once

#include <iostream>
#include <string>
#include <mutex>

class DataBase {
private:
    std::string m_name;
    int m_record;
    static DataBase* m_instance_ptr;  
    static std::mutex m_mutex;

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
        m_mutex.lock();

        if (m_instance_ptr == nullptr){
            m_instance_ptr = new DataBase(name);
        }

        m_mutex.unlock();

        return m_instance_ptr;
    }
};

DataBase* DataBase::m_instance_ptr = nullptr;
std::mutex DataBase::m_mutex;