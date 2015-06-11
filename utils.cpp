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

void list_functions(const vector<string> &groups, string_callback func)
{

    if (groups.size() > 1)
        for ( vector<string>::const_iterator i = groups.begin(); i != groups.end(); ++i)
            if (*i == "all")
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
