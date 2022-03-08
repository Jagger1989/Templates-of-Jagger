#include <math.h>

using namespace std;

const double PI = 3.1415926535897932;
const double METER = 20037508.34;

//把地球视为球体实现经纬度和墨卡托投影的函数
typedef struct Point
{
    double x;
    double y;
}WayPoint;

//经纬度转墨卡托
WayPoint lonLat2Mercator(WayPoint lonLat)
{
    WayPoint mercator;
    double x = lonLat.x * 20037508.34 / 180;
    double y = log(tan((90 + lonLat.y) * PI / 360)) / (PI / 180);
    y = y * 20037508.34 / 180;
    mercator.x = x;
    mercator.y = y;
    return mercator;
}

//墨卡托转经纬度
WayPoint Mercator2lonLat(WayPoint mercator)
{
    WayPoint lonLat;
    double x = mercator.x / 20037508.34 * 180;
    double y = mercator.y / 20037508.34 * 180;
    y = 180 / PI * (2 * atan(exp(y * PI / 180)) - PI / 2);
    lonLat.x = x;
    lonLat.y = y;
    return lonLat;
}
