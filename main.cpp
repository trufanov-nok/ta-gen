#include <boost/program_options.hpp>
#include "utils.h"

#define VERSION "0.0.1"

#define eol '\n'

using namespace std;
namespace po = boost::program_options;



void add_to_args(int argc, char* argv[], vector<string>& res)
{
    for (int i = 1; i < argc; i++)
        res.push_back(string(argv[i]));
}

void add_options(po::options_description& opts, vector<string>& args, po::variables_map& vm)
{
    po::parsed_options parsed = po::command_line_parser(args).
            style(po::command_line_style::default_style ^ po::command_line_style::allow_guessing).
            options(opts).allow_unregistered().run();
    po::store(parsed, vm);
    po::notify(vm);
}

void print_string(const char* str, void*)
{
    printf( "%s\n", str);
}

int main(int argc, char *argv[])
{    
    po::variables_map vm;
    vector<string> args;
    add_to_args(argc, argv, args);
    po::options_description opts = po::options_description("main params");
    opts.add_options()
            ("version,v", "Get version.")
            ("help,h",    "This help.")
            ("list_groups", "List groups of functions available in TA-Lib.")
            ("list_functions", po::value< vector<string> > (), "List functions in the group. May be used multiple times to list content of several groups. Don't forget that group names with space characters must be passed in quotes. May accept 'all' value to list all functions.")
            ("xml", "Print XML representation of ALL the TA-Lib functions. The returned array is the same as the ta_func_api.xml file.");
    add_options(opts, args, vm);



    if (vm.count("help") || vm.size() == 0) {
        /* upon direct query for help -- spit it out to stdout */
        cout << opts << eol;
        exit(0);
    }

    if (vm.count("version"))
    {
        printf( "%s%s\n", "Version: ", VERSION);
        exit(0);
    }


    check_ret_code( TA_Initialize() );

    if (vm.count("list_groups"))
    {
        list_groups(print_string, NULL);
        exit(0);
    }

    if (vm.count("list_functions"))
    {
        list_functions(vm["list_functions"].as< vector<string> >(), print_string);
        exit(0);
    }


    if (vm.count("xml"))
    {
        printf(TA_FunctionDescriptionXML(), NULL);
        exit(0);
    }


    check_ret_code( TA_Shutdown() );
    return 0;
}