/*
���ļ������ڣ�https://wiki.openstreetmap.org/wiki/Mercator
*/
#include"mercator.h"
#include<iostream>
using namespace std;
int test_mercator()
{
    cout << "��������꣺" << merc_x(120) << endl;
    cout << "��������꣺" << merc_y(60) << endl;
    cout << "������ȣ�" << merc_lon(654321) << endl;
    cout << "���γ�ȣ�" << merc_lat(123456) << endl;
    system("pause");
    return 0;
}