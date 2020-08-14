//
//      _
//  ___/_)
// (, /      ,_   _
//   /   (_(_/ (_(_(_
// CX________________
//                   )
//
// Luna
// A web application and API framework in modern C++
//
// Copyright © 2016–2018 D.E. Goodman-Wilson
//

#pragma once

#include <string>
#include <functional>
#include <luna/types.h>

namespace luna
{

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__))
    // enum constant that is already a defined pre-processor macro will result in C2143 and C2059 
    // c.f. https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/compiler-error-c2059?view=vs-2019
#undef ERROR
#endif
enum class log_level
{
    FATAL = 0,
    ERROR,
    WARNING,
    INFO,
    DEBUG,
};


using access_logger_cb = std::function<void(const request &request, const response &response)>;
using error_logger_cb = std::function<void(log_level level, const std::string &string)>;

void set_access_logger(access_logger_cb logger);
void reset_access_logger();

void set_error_logger(error_logger_cb logger);
void reset_error_logger();

void access_log(const request& request, const response &response);
void error_log(log_level level, const std::string &string);

} //namespace luna

std::string to_string(luna::log_level value);
