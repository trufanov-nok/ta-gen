#include "prints.h"


void print_string(const char* str, void*)
{
    printf( "%s\n", str);
}

template <class T>
inline void getFlagText(string& s, T flag, T value, const char * text)
{
    if (flag & value)
    {
        if(!s.empty()) s.append(" & ");
        s.append(text);
    }
}

inline string print_func_flags(const TA_FuncFlags f)
{
    string res;
    getFlagText<TA_FuncFlags>(res, f, TA_FUNC_FLG_OVERLAP, "TA_FUNC_FLG_OVERLAP");
    getFlagText<TA_FuncFlags>(res, f, TA_FUNC_FLG_VOLUME, "TA_FUNC_FLG_VOLUME");
    getFlagText<TA_FuncFlags>(res, f, TA_FUNC_FLG_UNST_PER, "TA_FUNC_FLG_UNST_PER");
    getFlagText<TA_FuncFlags>(res, f, TA_FUNC_FLG_CANDLESTICK, "TA_FUNC_FLG_CANDLESTICK");
    if (res.empty()) res = "NONE";
    return res;
}


inline string printInputFlags(const TA_InputFlags f)
{
    string res;
    getFlagText<TA_InputFlags>(res, f, TA_IN_PRICE_OPEN, "TA_IN_PRICE_OPEN");
    getFlagText<TA_InputFlags>(res, f, TA_IN_PRICE_HIGH, "TA_IN_PRICE_HIGH");
    getFlagText<TA_InputFlags>(res, f, TA_IN_PRICE_LOW, "TA_IN_PRICE_LOW");
    getFlagText<TA_InputFlags>(res, f, TA_IN_PRICE_CLOSE, "TA_IN_PRICE_CLOSE");
    getFlagText<TA_InputFlags>(res, f, TA_IN_PRICE_VOLUME, "TA_IN_PRICE_VOLUME");
    getFlagText<TA_InputFlags>(res, f, TA_IN_PRICE_OPENINTEREST, "TA_IN_PRICE_OPENINTEREST");
    getFlagText<TA_InputFlags>(res, f, TA_IN_PRICE_TIMESTAMP, "TA_IN_PRICE_TIMESTAMP");
    if (res.empty()) res = "NONE";
    return res;
}

inline void displayInputType( const TA_FuncInfo *funcInfo )
{
    const TA_InputParameterInfo *paramInfo;
    for( unsigned int i = 0; i < funcInfo->nbInput; ++i )
    {
        TA_GetInputParameterInfo( funcInfo->handle, i, &paramInfo );
        string type;
        if (paramInfo->type == TA_Input_Price)
            type = "TA_Input_Price";
        else
            if (paramInfo->type == TA_Input_Real)
                type = "TA_Input_Real";
            else
                if (paramInfo->type == TA_Input_Integer)
                    type = "TA_Input_Integer";
                else
                    type = "Unknown";

        printf("input param #%d\nparam name: %s\ntype: %s\nflags: %s\n", i, paramInfo->paramName, type.c_str(), printInputFlags(paramInfo->flags).c_str());
    }
}


inline string printOptInputFlags(const TA_OptInputFlags f)
{
    string res;
    getFlagText<TA_OptInputFlags>(res, f, TA_OPTIN_IS_PERCENT, "TA_OPTIN_IS_PERCENT");
    getFlagText<TA_OptInputFlags>(res, f, TA_OPTIN_IS_DEGREE, "TA_OPTIN_IS_DEGREE");
    getFlagText<TA_OptInputFlags>(res, f, TA_OPTIN_IS_CURRENCY, "TA_OPTIN_IS_CURRENCY");
    getFlagText<TA_OptInputFlags>(res, f, TA_OPTIN_ADVANCED, "TA_OPTIN_ADVANCED");
    if (res.empty()) res = "NONE";
    return res;
}

inline void displayOptInputType( const TA_FuncInfo *funcInfo )
{
    const TA_OptInputParameterInfo *paramInfo;
    for( unsigned int i = 0; i < funcInfo->nbOptInput; ++i )
    {
        TA_GetOptInputParameterInfo( funcInfo->handle, i, &paramInfo );
        string type;
        if (paramInfo->type == TA_OptInput_RealRange)
            type = "TA_OptInput_RealRange";
        else
            if (paramInfo->type == TA_OptInput_RealList)
                type = "TA_OptInput_RealList";
            else
                if (paramInfo->type == TA_OptInput_IntegerRange)
                    type = "TA_OptInput_IntegerRange";
                else
                    if (paramInfo->type == TA_OptInput_IntegerList)
                        type = "TA_OptInput_IntegerList";
                    else type = "Unknown";


        printf("opt input param #%d\nparam name: %s\ntype: %s\nflags: %s\ndisplay name: %s\nhint: %s\nhelp file: %s\ndefault value: %f\n",
               i, paramInfo->paramName, type.c_str(), printOptInputFlags(paramInfo->flags).c_str(), paramInfo->displayName, paramInfo->hint, paramInfo->helpFile, paramInfo->defaultValue );
    }
}


inline string printOutputFlags(const TA_OutputFlags f)
{
    string res;
    getFlagText<TA_OutputFlags>(res, f, TA_OUT_LINE, "TA_OUT_LINE");
    getFlagText<TA_OutputFlags>(res, f, TA_OUT_DOT_LINE, "TA_OUT_DOT_LINE");
    getFlagText<TA_OutputFlags>(res, f, TA_OUT_DASH_LINE, "TA_OUT_DASH_LINE");
    getFlagText<TA_OutputFlags>(res, f, TA_OUT_DOT, "TA_OUT_DOT");
    getFlagText<TA_OutputFlags>(res, f, TA_OUT_HISTO, "TA_OUT_HISTO");
    getFlagText<TA_OutputFlags>(res, f, TA_OUT_PATTERN_BOOL, "TA_OUT_PATTERN_BOOL");
    getFlagText<TA_OutputFlags>(res, f, TA_OUT_PATTERN_BULL_BEAR, "TA_OUT_PATTERN_BULL_BEAR");
    getFlagText<TA_OutputFlags>(res, f, TA_OUT_PATTERN_STRENGTH, "TA_OUT_PATTERN_STRENGTH");
    getFlagText<TA_OutputFlags>(res, f, TA_OUT_POSITIVE, "TA_OUT_POSITIVE");
    getFlagText<TA_OutputFlags>(res, f, TA_OUT_NEGATIVE, "TA_OUT_NEGATIVE");
    getFlagText<TA_OutputFlags>(res, f, TA_OUT_ZERO, "TA_OUT_ZERO");
    getFlagText<TA_OutputFlags>(res, f, TA_OUT_UPPER_LIMIT, "TA_OUT_UPPER_LIMIT");
    getFlagText<TA_OutputFlags>(res, f, TA_OUT_LOWER_LIMIT, "TA_OUT_LOWER_LIMIT");

    if (res.empty()) res = "NONE";
    return res;
}

inline void displayOutputType( const TA_FuncInfo *funcInfo )
{
    const TA_OutputParameterInfo *paramInfo;
    for( unsigned int i = 0; i < funcInfo->nbOutput; ++i )
    {
        TA_GetOutputParameterInfo( funcInfo->handle, i, &paramInfo );
        string type;
        if (paramInfo->type == TA_Output_Real)
            type = "TA_Output_Real";
        else
            if (paramInfo->type == TA_Output_Integer)
                type = "TA_Output_Integer";
            else type = "Unknown";

        printf("output param #%d\nparam name: %s\ntype: %s\nflags: %s\n", i, paramInfo->paramName, type.c_str(), printOutputFlags(paramInfo->flags).c_str());
    }
}

void print_func_info(const TA_FuncInfo* fi, void*)
{

    string flags = print_func_flags(fi->flags);
    printf( "name: %s\ngroup: %s\nhint: %s\ncamelCaseName: %s\nflags: %s\nnbInput: %d\nnbOptInput: %d\nnbOutput: %d\n",
            fi->name, fi->group, fi->hint, fi->camelCaseName, flags.c_str(), fi->nbInput, fi->nbOptInput, fi->nbOutput);

    displayInputType(fi);
    displayOptInputType(fi);
    displayOutputType(fi);

    printf( "\n" );
}

