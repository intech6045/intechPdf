/* Copyright 2013 the SumatraPDF project authors (see AUTHORS file).
   License: Simplified BSD (see COPYING.BSD) */

#include "BaseUtil.h"
#include "CmdLineParser.h"

/* returns the next character in '*txt' that isn't a backslash */
static const WCHAR SkipBackslashs(const WCHAR *txt)
{
    AssertCrash(txt && '\\' == *txt);
    while ('\\' == *++txt);
    return *txt;
}

/* appends the next quoted argument and returns the position after it */
static const WCHAR *ParseQuoted(const WCHAR *arg, WStrVec& out)
{
    AssertCrash(arg && '"' == *arg);
    arg++;

    str::Str<WCHAR> txt(str::Len(arg) / 2);
    const WCHAR *next;
    for (next = arg; *next && *next != '"'; next++) {
        // skip escaped quotation marks according to
        // http://msdn.microsoft.com/en-us/library/17w5ykft.aspx
        if ('\\' == *next && '"' == SkipBackslashs(next))
            next++;
        txt.Append(*next);
    }
    out.Append(txt.StealData());

    if ('"' == *next)
        next++;
    return next;
}

/* appends the next unquoted argument and returns the position after it */
static const WCHAR *ParseUnquoted(const WCHAR *arg, WStrVec& out)
{
    AssertCrash(arg && *arg && ('"' != *arg) && !str::IsWs(*arg));

    const WCHAR *next;
    // contrary to http://msdn.microsoft.com/en-us/library/17w5ykft.aspx
    // we don't treat quotation marks or backslashes in non-quoted
    // arguments in any special way
    for (next = arg; *next && !str::IsWs(*next); next++);
    out.Append(str::DupN(arg, next - arg));
    return next;
}

/* 'cmdLine' contains one or several arguments. Each argument can be:
 - quoted, in which case it starts with '"', ends with '"' (or '\0') and
   each '"' that is part of the argument must be escaped with '\\'
 - unquoted, in which case it doesn't start with '"' and ends with
   white space (usually ' ') or '\0'
*/
void ParseCmdLine(const WCHAR *cmdLine, WStrVec& out, int maxParts)
{
    while (cmdLine && --maxParts != 0) {
        while (str::IsWs(*cmdLine))
            cmdLine++;
        if ('"' == *cmdLine)
            cmdLine = ParseQuoted(cmdLine, out);
        else if ('\0' != *cmdLine)
            cmdLine = ParseUnquoted(cmdLine, out);
        else
            cmdLine = NULL;
    }
    if (cmdLine) {
        while (str::IsWs(*cmdLine))
            cmdLine++;
        if ('\0' != *cmdLine)
            out.Append(str::Dup(cmdLine));
    }
}
