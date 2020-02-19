#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include <math.h>
#include <Eigen/Dense>

using namespace std;
typedef Eigen::Vector2f Vec2f;
typedef Eigen::Hyperplane<float, 2> Line;

// For accurate comparison between floats
// bool cmpf(float A, float B, float epsilon = 0.005f)
// {
//     return (fabs(A - B) < epsilon);
// }

struct Segment
{
    Segment(Vec2f p1, Vec2f p2);
    Vec2f start;                // start point vector
    Vec2f end;                  // end point vector
    Vec2f segment;              // segment(line) vector = end - start
    Vec2f segment_unit;         // unit vector of segment
    Vec2f segment_unit_norm;    // unit & normal vector of segment
    
    float t;                    // t in the parametric equation: a_vector = a_start + (a_direction) * t
    float x_diff;
    float y_diff;
    float angle;
    float angle_degree;
    float length;

    void calculate_members();
    Vec2f intersection_point(Segment &seg2);
    bool ifIntersect(const Segment &seg2);

    friend std::ostream& operator<<(std::ostream& os, const Segment &sg)
    {
        float x = sg.end.x()-sg.start.x();
        float x2 = pow(x,2.0);
        float y = sg.end.y()-sg.start.y();
        float y2 = pow(y,2.0);
        float z = sqrt(x2+y2);
        os << "[" << to_string(sg.start.x()) << "," << to_string(sg.start.y()) << "]";
        os << "->";
        os << "[" << to_string(sg.end.x()) << "," << to_string(sg.end.y()) << "]";
        os << "\tlength:" << sg.length << "\tangle:" << sg.angle << "\tangle_degree:" << sg.angle_degree;
        return os;
    }
};

#endif