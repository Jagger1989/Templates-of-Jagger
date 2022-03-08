#pragma once


// Add this line before including math.h:
#define _USE_MATH_DEFINES
// Additions for MS Windows compilation:
#ifndef M_PI
#define M_PI acos(-1.0)
#endif
#ifndef M_PI_2
#define M_PI_2 1.57079632679489661922
#endif



#include <math.h>

/*
* Mercator transformation
* accounts for the fact that the earth is not a sphere, but a spheroid
*/
#define D_R (M_PI / 180.0)
#define R_D (180.0 / M_PI)
#define R_MAJOR 6378137.0
#define R_MINOR 6356752.3142
#define RATIO (R_MINOR/R_MAJOR)
#define ECCENT (sqrt(1.0 - (RATIO * RATIO)))
#define COM (0.5 * ECCENT)

inline double fmin(double x, double y) { return(x < y ? x : y); }
inline double fmax(double x, double y) { return(x > y ? x : y); }

static double deg_rad(double ang) {
    return ang * D_R;
}

double merc_x(double lon) {
    return R_MAJOR * deg_rad(lon);//墨卡托投影到平面的横坐标
}

double merc_y(double lat) {
    lat = fmin(89.5, fmax(lat, -89.5));
    double phi = deg_rad(lat);
    double sinphi = sin(phi);
    double con = ECCENT * sinphi;
    con = pow((1.0 - con) / (1.0 + con), COM);
    double ts = tan(0.5 * (M_PI * 0.5 - phi)) / con;
    return 0 - R_MAJOR * log(ts);
}

static double rad_deg(double ang) {
    return ang * R_D;
}

double merc_lon(double x) {
    return rad_deg(x) / R_MAJOR;//返回经度
}

double merc_lat(double y) {
    double ts = exp(-y / R_MAJOR);
    double phi = M_PI_2 - 2 * atan(ts);
    double dphi = 1.0;
    int i;
    for (i = 0; fabs(dphi) > 0.000000001 && i < 15; i++) {
        double con = ECCENT * sin(phi);
        dphi = M_PI_2 - 2 * atan(ts * pow((1.0 - con) / (1.0 + con), COM)) - phi;
        phi += dphi;
    }
    return rad_deg(phi);//返回纬度
}