#include <math.h>

using namespace std;

const double PI = 3.1415926535897932;
const double METER = 20037508.34;

//�ѵ�����Ϊ����ʵ�־�γ�Ⱥ�ī����ͶӰ�ĺ���
typedef struct Point
{
    double x;
    double y;
}WayPoint;

//��γ��תī����
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

//ī����ת��γ��
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
