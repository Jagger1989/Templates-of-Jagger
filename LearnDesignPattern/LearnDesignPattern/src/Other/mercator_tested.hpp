#include "my_math.hpp"

#if 0

static constexpr double WebMercatorSize = 2 * math::PI * 6378137; // circumference of spherical earth in web mercator meters
static constexpr double WebMercatorInvSize = 1.0 / WebMercatorSize;

namespace
{
    double toRad(double deg)
    {
        return deg * math::ToRad;
    }

    double toDeg(double rad)
    {
        return rad * math::ToDeg;
    }
}

/// implementation for web mercator projection
namespace WebMercator
{
    /// convert WGS84 latitude longitude to world coordinates in Web Mercator meters
    inline Vector2<double>(LatLon<double> coord)
    {
        Vector2<double> world{
            coord.getLon() * WebMercatorSize / 360.0,
            log(tan(0.5 * toRad(90 + coord.getLat()))) * math::InvPI * WebMercatorSize * 0.5
        };

        return world;
    }

    /// convert web mercator world coordinates to WGS84 coordinates
    inline LatLon<double> toLatLon(Vector2<double> world)
    {
        LatLon<double> latLon{
            toDeg(2.0 * atan(exp(world.getY() * math::PI * WebMercatorInvSize * 2.0))) - 90.0,
            world.getX() * WebMercatorInvSize * 360.0
        };

        return latLon;
    }

    /// Get the bottom left coordinate of the web mercator world in web mercator meters
    inline double getBottomLeft()
    {
        return -WebMercatorSize / 2.0;
    }
};

/// Web mercator implementation normalized to such that world is in -0.5 to 0.5 range
namespace WebMercatorNorm
{
    inline Vector2<double> toWorld(LatLon<double> coord)
    {
        Vector2<double> world{
            coord.getLon() / 360.0,
            log(tan(0.5 * toRad(90 + coord.getLat()))) * math::InvPI * 0.5
        };

        return world;
    }

    inline LatLon<double> toLatLon(Vector2<double> world)
    {
        LatLon<double> latLon{
            toDeg(2.0 * atan(exp(world.getY() * math::PI * 2.0))) - 90.0,
            world.getX() * 360.0
        };

        return latLon;
    }

    inline double getBottomLeft()
    {
        return -0.5;
    }
}

#endif