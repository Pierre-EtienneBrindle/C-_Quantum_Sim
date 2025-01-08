#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

namespace core
{
    // Class enumerating the different behaviour for the logger
    enum log_type
    {
        console,
        file,
    };

    //Class used to log data
    //TO DO : Stop using a class to log
    class logger
    {
    private:
        static inline std::string m_file_path = "";
        static inline log_type m_curr_type = log_type::console;
        static std::string current_time_to_string();

    public:
        static void log(std::string info);
        static void set_log_type(log_type type);
        // Sets the path used to write the log informations
        static void set_file_path(std::string path);
        static void log_operation(const std::string &input1, const std::string &operation, const std::string &input2, const std::string &result); // Will need to be changed when operation will take more inputs
    };
}

#endif