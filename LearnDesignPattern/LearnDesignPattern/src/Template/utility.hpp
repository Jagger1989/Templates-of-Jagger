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
        strcat_s(dirNew, "\\*.*");  // ��Ŀ¼�������"\\*.*"���е�һ������.

        intptr_t handle;
        _finddata_t findData; // _finddata_t�Ǵ洢�ļ�������Ϣ�Ľṹ��

        handle = _findfirst(dirNew, &findData);
        if (handle == -1) // ����Ƿ�ɹ�
            return list;
        do
        {
            if (findData.attrib & _A_SUBDIR) // Ŀ¼
            {
                list.push_back(findData.name);
            }

        } while (_findnext(handle, &findData) == 0);


        _findclose(handle);    // �ر��������
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
        strcat_s(dirNew, "\\*.*");  // ��Ŀ¼�������"\\*.*"���е�һ������.

        intptr_t handle;
        _finddata_t findData; // _finddata_t�Ǵ洢�ļ�������Ϣ�Ľṹ��

        handle = _findfirst(dirNew, &findData);
        if (handle == -1) // ����Ƿ�ɹ�
            return fileList;
        do
        {
            if (findData.attrib & _A_SUBDIR) // Ŀ¼
            {

            }
            else // �ļ�
            {
                fileList.push_back(findData.name); // ��ӡ�ļ������ƣ����Һ�����Դ�ӡ�ļ�����Ŀ
            }

        } while (_findnext(handle, &findData) == 0);

        _findclose(handle);    // �ر��������
        return fileList;
    }
};



#endif // !UTILITY_HPP