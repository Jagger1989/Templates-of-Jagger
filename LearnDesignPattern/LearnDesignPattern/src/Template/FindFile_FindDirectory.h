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


// �ݹ���������ļ�
void listFiles(const char * dir, std::vector<const std::string> &fileList)
{
    char dirNew[200];
    strcpy_s(dirNew, dir);
    strcat_s(dirNew, "\\*.*");  // ��Ŀ¼�������"\\*.*"���е�һ������.

    intptr_t handle;
    _finddata_t findData; // _finddata_t�Ǵ洢�ļ�������Ϣ�Ľṹ��

    handle = _findfirst(dirNew, &findData);
    if (handle == -1) // ����Ƿ�ɹ�
        return;
    do
    {
        if (findData.attrib & _A_SUBDIR) // Ŀ¼
        {
            if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
                continue;

            cout << findData.name << "\t<dir>\n"; // ��ӡ�ļ��е�����
            //fileList.push_back(findData.name); // ��ӡ�ļ��е�����

            // ��Ŀ¼�������"\\"����������Ŀ¼��������һ������
            strcpy_s(dirNew, dir);
            strcat_s(dirNew, "\\");
            strcat_s(dirNew, findData.name);

            listFiles(dirNew, fileList);
        }
        else // �ļ�
        {
            fileList.push_back(findData.name); // ��ӡ�ļ������ƣ����Һ�����Դ�ӡ�ļ�����Ŀ
        }

    } while (_findnext(handle, &findData) == 0);

    _findclose(handle);    // �ر��������

}

// _finddata_t attrib
//_A_ARCH���浵��
//
//_A_HIDDEN�����أ�
//
//_A_NORMAL��������
//
//_A_RDONLY��ֻ����
//
//_A_SUBDIR���ļ��У�
//
//_A_SYSTEM��ϵͳ��


#endif // !TEMPLATE_FINDFILE_FIND_DIR_H