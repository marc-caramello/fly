#ifndef PROJECTFOLDERPATH_H
#define PROJECTFOLDERPATH_H
#include <string>
#include <Windows.h>

namespace ProjectFolderPath
{
    static std::string str;

    static std::string getStr()
    {
        char buffer[MAX_PATH];
        GetModuleFileName(NULL, buffer, MAX_PATH);
        std::string executablePath(buffer);
        return executablePath.substr(0, executablePath.find("\\build"));
    }
}
#endif // PROJECTFOLDERPATH_H