/*
本文件来自于：https://wiki.openstreetmap.org/wiki/Mercator
*/
#include"mercator.h"
#include<iostream>
using namespace std;
int test_mercator()
{
    cout << "输出横坐标：" << merc_x(120) << endl;
    cout << "输出纵坐标：" << merc_y(60) << endl;
    cout << "输出经度：" << merc_lon(654321) << endl;
    cout << "输出纬度：" << merc_lat(123456) << endl;
    system("pause");
    return 0;
}