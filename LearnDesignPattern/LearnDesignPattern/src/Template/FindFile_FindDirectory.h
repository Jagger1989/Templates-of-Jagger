#ifndef TEMPLATE_FINDFILE_FIND_DIR_H
#define TEMPLATE_FINDFILE_FIND_DIR_H

//#include "stdafx.h"  
#include <iostream>
#include <cstring>        // for strcpy_s(), strcat_s()
#include <io.h>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


// 递归查找所有文件
void listFiles(const char * dir, std::vector<const std::string> &fileList)
{
    char dirNew[200];
    strcpy_s(dirNew, dir);
    strcat_s(dirNew, "\\*.*");  // 在目录后面加上"\\*.*"进行第一次搜索.

    intptr_t handle;
    _finddata_t findData; // _finddata_t是存储文件各种信息的结构体

    handle = _findfirst(dirNew, &findData);
    if (handle == -1) // 检查是否成功
        return;
    do
    {
        if (findData.attrib & _A_SUBDIR) // 目录
        {
            if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
                continue;

            cout << findData.name << "\t<dir>\n"; // 打印文件夹的名称
            //fileList.push_back(findData.name); // 打印文件夹的名称

            // 在目录后面加上"\\"和搜索到的目录名进行下一次搜索
            strcpy_s(dirNew, dir);
            strcat_s(dirNew, "\\");
            strcat_s(dirNew, findData.name);

            listFiles(dirNew, fileList);
        }
        else // 文件
        {
            fileList.push_back(findData.name); // 打印文件的名称，并且后面可以打印文件的数目
        }

    } while (_findnext(handle, &findData) == 0);

    _findclose(handle);    // 关闭搜索句柄

}

// _finddata_t attrib
//_A_ARCH（存档）
//
//_A_HIDDEN（隐藏）
//
//_A_NORMAL（正常）
//
//_A_RDONLY（只读）
//
//_A_SUBDIR（文件夹）
//
//_A_SYSTEM（系统）


#endif // !TEMPLATE_FINDFILE_FIND_DIR_H