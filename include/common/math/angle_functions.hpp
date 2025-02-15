#ifndef MATH_ANGLE_FUNCTIONS_H
#define MATH_ANGLE_FUNCTIONS_H

#include <cmath>

/**
 * @brief EECS 467 Angle Functions Library (only modified to make everything a double)
 */

namespace eecs467
{
/**
* wrap_to_pi takes an angle of arbitrary size and reduces it to the range [-PI, PI].
*
* \param    angle           Angle to wrap
* \return   Equivalent angle in range [-PI, PI].
*/
inline double wrap_to_pi(double angle)
{
    if (angle < -M_PI)
        for (; angle < -M_PI; angle += (2.0 * M_PI))
            ;
    else if (angle > M_PI)
        for (; angle > M_PI; angle -= (2.0 * M_PI))
            ;

    return angle;
}

/**
* wrap_to_2pi takes an angle of arbitrary sizes and reduces it to the range [0, 2PI].
*
* \param    angle           Angle to wrap
* \return   Equivalent angle in range [0, 2PI].
*/
inline double wrap_to_2pi(double angle)
{
    if (angle < 0)
        for (; angle < 0; angle += (2.0 * M_PI))
            ;
    else if (angle > (2.0 * M_PI))
        for (; angle > (2.0 * M_PI); angle -= (2.0 * M_PI))
            ;

    return angle;
}

/**
* wrap_to_pi_2 takes an arbitrary angle and wraps it to the range [-pi/2,pi/2]. This function is
* intended
* for use with lines where the direction doesn't matter, e.g. where something like 3pi/4 == -pi/4
* like the
* slope of a line.
*
* \param    angle           Angle to wrap
* \return   Angle in the range [-pi/2,pi/2].
*/
inline double wrap_to_pi_2(double angle)
{
    double wrapped = wrap_to_pi(angle);

    if (wrapped < -M_PI_2)
        wrapped += M_PI;
    else if (wrapped > M_PI_2)
        wrapped -= M_PI;

    return wrapped;
}

/**
* angle_diff finds the difference in radians between two angles and ensures that the differences
* falls in the range of [-PI, PI].
*
* \param    leftAngle           Angle on the left-handside of the '-'
* \param    rightAngle          Angle on the right-handside of the '-'
* \return   The difference between the angles, leftAngle - rightAngle, in the range [-PI, PI].
*/
inline double angle_diff(double leftAngle, double rightAngle)
{
    double diff = leftAngle - rightAngle;

    if (std::abs(diff) > M_PI) diff -= (diff > 0) ? M_PI * 2.0 : M_PI * -2.0;

    return diff;
}

/**
* angle_diff_abs finds the absolute value of the difference in radians between two angles and
* ensures that the differences
* falls in the range of [0, PI].
*
* \param    leftAngle           Angle on the left-handside of the '-'
* \param    rightAngle          Angle on the right-handside of the '-'
* \return   The difference between the angles, leftAngle - rightAngle, in the range [-PI, PI].
*/
inline double angle_diff_abs(double leftAngle, double rightAngle)
{
    return std::abs(angle_diff(leftAngle, rightAngle));
}

/**
* angle_diff_abs_pi_2 finds the difference in radians between two angles where the range is [0,
* PI/2].
* The calculation is the angle_diff. If the abs(diff) > M_PI/2, then the result is PI - abs(diff).
* This
* function is intended for cases where the angles represent line slopes rather than vectors. The
* slope
* only can differ by at most PI/2.
*
* \param    lhs         Angle on left of '-'
* \param    rhs         Angle on right of '-'
* \return   lhs - rhs, in the range [0, PI/2].
*/
inline double angle_diff_abs_pi_2(double lhs, double rhs)
{
    double diff = std::abs(angle_diff(lhs, rhs));

    return (diff < (M_PI / 2.0)) ? diff : M_PI - diff;
}

/**
* angle_sum finds the sum in radians of two angles and ensures the value is in the range [-PI, PI].
*
* \param    angleA              First angle in the sum
* \param    angleB              Second angle in the sum
* \return   The sum of the two angles, angleA + angleB, in the range [-PI, PI].
*/
inline double angle_sum(double angleA, double angleB)
{
    double sum = angleA + angleB;

    if (std::abs(sum) > M_PI) sum -= (sum > 0) ? M_PI * 2.0 : M_PI * -2.0;

    return sum;
}

}  // namespace eecs467

#endif  // MATH_ANGLE_FUNCTIONS_H
