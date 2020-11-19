#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include "ta-lib-rt/ta_libc.h"
#include "ta-lib-rt/ta_abstract.h"

using namespace std;

inline void check_ret_code(const TA_RetCode& ret)
{
    if (ret != TA_SUCCESS)
        throw ret;
}

typedef void (*string_callback)(const char* str, void* arg);
typedef void (*func_info_callback)(const TA_FuncInfo* str, void* arg);

void list_groups(string_callback func, void* arg);
void list_functions(const vector<string>& groups, string_callback func);
void print_functions(const vector<string>& groups, func_info_callback func);


#endif // UTILS_H

