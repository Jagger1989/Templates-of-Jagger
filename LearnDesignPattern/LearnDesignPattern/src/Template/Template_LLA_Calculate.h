#ifndef TEMPLATE_LLA_CALCULATE_H
#define TEMPLATE_LLA_CALCULATE_H
#include <math.h>
#include "../Utility/common.h"


#define PI 3.141592657
#define EARTH_RADIUS  6378137
static inline double  rad(double degree)
{
    return  PI * degree / 180.0;
}
static inline double haverSin(double x)
{
    double v = sin(x / 2.0);
    return v * v;
}
//º∆À„æ‡¿Î(µ•Œª : m)
static double getDistance(double lon1, double lat1, double lon2, double lat2)
{
    double radlon1 = rad(lon1);
    double radlat1 = rad(lat1);
    double radlon2 = rad(lon2);
    double radlat2 = rad(lat2);

    double a = fabs(radlat1 - radlat2);
    double b = fabs(radlon1 - radlon2);

    double h = haverSin(b) + cos(lat1)*cos(lat2)*haverSin(a);
    double distance = 2 * EARTH_RADIUS * asin(sqrt(h));
    return  distance;
}

void testLLACalculate()
{
    double distance1 = getDistance(116.53577916323175, 40.07020158372633, 116.535629127165, 40.07000016659313);
    std::cout << "distance1 = " << distance1 << std::endl;

    double distance2 = getDistance(116.5356048196458, 40.06996445968563, 116.53558185323111, 40.069929590968435);
    std::cout << "distance2 = " << distance2 << std::endl;
}


#endif // !TEMPLATE_LLA_CALCULATE_H