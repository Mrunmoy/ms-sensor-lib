/**
 *  @file temperature.h
 *  @author championsurfer3044
 *  @date 13 Jan 2019 
 *  @brief 
 *
 *  LICENSE:-
 *  The MIT License (MIT)
 *  Copyright (c) 2019 Mrunmoy Samal
 *
 *  Permission is hereby granted, free of charge, to any person
 *  obtaining a copy of this software and associated documentation
 *  files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use,
 *  copy, modify, merge, publish, distribute, sublicense, and/or
 *  sell copies of the Software, and to permit persons to whom
 *  the Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall
 *  be included in all copies or substantial portions of the
 *  Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 *  OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef MS_SENSOR_LIB_TEMPERATURE_H
#define MS_SENSOR_LIB_TEMPERATURE_H

/*
*----------------------------------------------------------------------
*   Include Files
*----------------------------------------------------------------------
*/

#include "sensor.h"

/*
*----------------------------------------------------------------------
*   Public Data Types
*----------------------------------------------------------------------
*/

namespace SensorLib
{


  class temperature_t : public sensor_t
  {
    float temperature;

  public:
    temperature_t(const char *assign_name, platform_read_t rd_func, platform_write_t wr_func);

    ~temperature_t();

    sensor_error_t init(void *p_init_params);

    sensor_error_t deinit(void);

    float read_raw(void);

    float read_celsius(void);

    float read_fahrenheit(void);

    float to_fahrenheit(float celcius);
  };



/*
*----------------------------------------------------------------------
*   Public Constants (const)
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Public Function Prototypes
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Externs
*----------------------------------------------------------------------
*/


}

#endif //MS_SENSOR_LIB_TEMPERATURE_H
