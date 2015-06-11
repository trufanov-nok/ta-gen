#include "utils.h"

void list_groups(string_callback func, void* arg)
{
    TA_StringTable *table;
    check_ret_code( TA_GroupTableAlloc( &table ) );
    for ( unsigned int i = 0; i < table->size; ++i )
        func( table->string[i], arg );

    check_ret_code( TA_GroupTableFree( table ) );
}

void list_functions(const char* group, string_callback func)
{
    TA_StringTable *table;
    check_ret_code( TA_FuncTableAlloc( group , &table ) );

    for (unsigned int i = 0; i < table->size; ++i )
        func( table->string[i], NULL );

    check_ret_code( TA_FuncTableFree( table ) );
}

void list_functions_callback(const char* group, void* arg)
{
    if (arg != NULL)
        list_functions(group, (string_callback) arg);
    else throw(-2);
}

inline bool contains_all(const vector<string> & vec)
{
    for ( vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
        if (*i == "all") return true;
    return false;
}

void list_functions(const vector<string> &groups, string_callback func)
{

    if (groups.size() > 1 && contains_all(groups))
    {
        printf( "%s\n", "'ERROR: --list_functions all' can't be used together with other --list_functions params.");
        return;
    }

    if (groups[0] != "all")
    {
        for ( vector<string>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
            list_functions(i->c_str(), func);
        }
    } else
        list_groups(list_functions_callback, (void*)func);
}


void print_functions(const char* f, func_info_callback func)
{
    const TA_FuncHandle *handle;
    const TA_FuncInfo *theInfo;
    check_ret_code( TA_GetFuncHandle(f, &handle) );
    check_ret_code( TA_GetFuncInfo(handle, &theInfo) );

    func(theInfo, NULL);
}

void print_functions(const vector<string>& functions, func_info_callback func)
{
    if (functions.size() > 1 && contains_all(functions))
    {
        printf( "%s\n", "'ERROR: --print_function_details all' can't be used together with other --print_function_details params.");
        return;
    }

    if (functions[0] != "all")
    {
        for ( vector<string>::const_iterator i = functions.begin(); i != functions.end(); ++i)
        {
            print_functions(i->c_str(), func);
        }
    } else
        TA_ForEachFunc(func, NULL);
}
