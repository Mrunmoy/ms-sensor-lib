/**
 *  @file sensor.h
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

#ifndef MS_SENSOR_LIB_SENSOR_H
#define MS_SENSOR_LIB_SENSOR_H


namespace SensorLib
{

/*
*----------------------------------------------------------------------
*   Include Files
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Public Data Types
*----------------------------------------------------------------------
*/

  typedef enum sensor_error_t
  {
    SE_OK = 0,
    SE_INIT_FAILED,
    SE_PLATFORM_READ_FAILED,
    SE_PLATFORM_WRITE_FAILED,
    SE_MAX
  } sensor_error_t;

/// Function Pointers for platform communication channel
  typedef int (*platform_read_t)(void *p_buffer, size_t len);

  typedef int (*platform_write_t)(void *p_buffer, size_t len);

  class sensor_t
  {
  protected:
    const char *name;
    platform_read_t read_func;
    platform_write_t write_func;

  public:
    sensor_t(const char *name, platform_read_t rd_func, platform_write_t wr_func);

    ~sensor_t();

    const char *errcode_to_str(sensor_error_t err);

    virtual sensor_error_t init(void *p_init_params) = 0;

    virtual sensor_error_t deinit(void) = 0;


public:
    sensor_error_t error_code;
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

#endif //MS_SENSOR_LIB_SENSOR_H
