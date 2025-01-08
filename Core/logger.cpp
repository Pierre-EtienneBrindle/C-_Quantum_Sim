#ifndef LOGGER_CPP
#define LOGGER_CPP

#include <iostream>
#include <chrono>
#include "Headers/logger.hpp"

namespace core
{
    std::string logger::current_time_to_string()
    {
        auto curr_time = std::chrono::system_clock::now().time_since_epoch();
        long long curr_time_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(curr_time).count();
        return "[" + std::to_string(curr_time_in_ms) + " ] - ";
    }

    void logger::log(std::string info)
    {
        std::string result = current_time_to_string() + info + "\r\n";

        if (m_curr_type == console)
            std::cout << result;
        else
        {
            // Check if path is valide

            // Write to file
        }
    }

    void logger::set_log_type(log_type type) { m_curr_type = type; }

    void logger::set_file_path(std::string path)
    {
        // Check if path valide

        // return
        // save path
        m_file_path = path;
    }

    void logger::log_operation(const std::string &input1, const std::string &operation, const std::string &input2, const std::string &result)
    {
        log(input1 + " " + operation + " " + input2 + " = " + result);
    }
}

#endif