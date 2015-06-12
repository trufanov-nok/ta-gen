# TA-Gen

Version 0.0.1

A C++ console tool wrapped around [TA-Lib](http://ta-lib.org). Intended to be used from terminal / shell scripts.
Supposed to be crossplatform: Linux, Windows, Mac OS. License: LGPL v3
Currently supported features:
* Listing TA functions implemented in current TA-lib: their groups, details, arguments.

Planned features:   
* TA signals generation

Command line:

```
  -v [ --version ]                    Get version.   
  -h [ --help ]                       This help.   
  -g [ --list_groups ]                List groups of functions available in    
                                      TA-Lib.   
  -l [ --list_functions ] arg         List functions in the group. May be used 
                                      multiple times to list content of several
                                      groups. Don't forget that group names 
                                      with space characters must be passed in 
                                      quotes. May accept 'all' value to list 
                                      all functions.
  -f [ --print_function_details ] arg Print function's' description. May be 
                                      used multiple times or with 'all' 
                                      keyword.
  -x [ --xml ]                        Print XML representation of ALL the 
                                      TA-Lib functions. The returned array is 
                                      the same as the ta_func_api.xml file.
```
