#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>
#include <vector>
#include <iostream>
#include <cstring> 
#include <io.h>
#include <fstream>

class Utility
{
public:
    static std::vector< std::vector<std::string>> getList(const char* dir)
    {
        std::vector<std::string> dirList = getDirList(dir);
        std::vector< std::vector<std::string>> list = getFileList(dirList);
        return list;
    }

    static std::vector<std::string> getDirList(const char* dir)
    {
        std::vector<std::string> list;
        char dirNew[200];
        strcpy_s(dirNew, dir);
        strcat_s(dirNew, "\\*.*");  // 在目录后面加上"\\*.*"进行第一次搜索.

        intptr_t handle;
        _finddata_t findData; // _finddata_t是存储文件各种信息的结构体

        handle = _findfirst(dirNew, &findData);
        if (handle == -1) // 检查是否成功
            return list;
        do
        {
            if (findData.attrib & _A_SUBDIR) // 目录
            {
                list.push_back(findData.name);
            }

        } while (_findnext(handle, &findData) == 0);


        _findclose(handle);    // 关闭搜索句柄
        return list;
    }

    static std::vector< std::vector<std::string>> getFileList(std::vector<std::string> dirList)
    {
        std::vector< std::vector<std::string>> list;
        for (auto it = dirList.begin(); it != dirList.end(); it++)
        {
            const std::string dir = *it;
            std::vector<std::string> listEachDir = getFileNameList(dir);
            list.push_back(listEachDir);
        }
        return list;
    }

    static std::vector<std::string> getFileNameList(const std::string& dir)
    {
        std::vector<std::string> fileList;
        char dirNew[200];
        strcpy_s(dirNew, dir.c_str());
        strcat_s(dirNew, "\\*.*");  // 在目录后面加上"\\*.*"进行第一次搜索.

        intptr_t handle;
        _finddata_t findData; // _finddata_t是存储文件各种信息的结构体

        handle = _findfirst(dirNew, &findData);
        if (handle == -1) // 检查是否成功
            return fileList;
        do
        {
            if (findData.attrib & _A_SUBDIR) // 目录
            {

            }
            else // 文件
            {
                fileList.push_back(findData.name); // 打印文件的名称，并且后面可以打印文件的数目
            }

        } while (_findnext(handle, &findData) == 0);

        _findclose(handle);    // 关闭搜索句柄
        return fileList;
    }
};



#endif // !UTILITY_HPP