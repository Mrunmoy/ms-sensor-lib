/**
 *  @file lux.cpp
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


/*
*----------------------------------------------------------------------
*   Include Files
*----------------------------------------------------------------------
*/
#include <iostream>
#include "lux.h"

namespace SensorLib
{

/*
*----------------------------------------------------------------------
*   Private Defines
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Macros
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Data Types
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Public Variables
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Variables (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Public Constants (const)
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Private Constants (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Function Prototypes (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Externs
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Functions Definitions
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Exported Functions Definitions
*----------------------------------------------------------------------
*/


  lux_t::lux_t(const char *assign_name, platform_read_t rd_func, platform_write_t wr_func)
          : sensor_t(assign_name, rd_func, wr_func)
  {
    this->lux = 0;
  }

  lux_t::~lux_t()
  {
  }

  sensor_error_t lux_t::init(void *p_init_params)
  {
    // do init of input parameter here
    (void) p_init_params;
    int result = 0;
    do
    {
      this->error_code = SE_OK;

      // write stuff to the registers to read chip version/mfg etc
      if (0 != (result = this->write_func(&this->lux, sizeof(this->lux))))
      {
        this->error_code = SE_PLATFORM_WRITE_FAILED;
        std::cout << "Error writing lux registers to platform. [result = %d]" << result << std::endl;
        break;
      }

      // read stuffs from registers
      if (0 != (result = this->read_func(&this->lux, sizeof(this->lux))))
      {
        this->error_code = SE_PLATFORM_READ_FAILED;
        std::cout << "Error reading lux registers from platform. [result = %d]" << result << std::endl;
        break;
      }
    }
    while (0);

    return this->error_code;
  }

  sensor_error_t lux_t::deinit(void)
  {
    // required uninitialization should be done here
    do
    {
      this->error_code = SE_OK;

    }
    while (0);

    return this->error_code;
  }

  float lux_t::read(void)
  {
    int result = 0;

    do
    {
      this->lux = 0;

      this->error_code = SE_OK;

      // write stuff to the registers
      if (0 != (result = this->write_func(&this->lux, sizeof(this->lux))))
      {
        this->error_code = SE_PLATFORM_WRITE_FAILED;
        std::cout << "Error writing lux registers to platform. [result = %d]" << result << std::endl;
        break;
      }

      // read stuffs from registers
      if (0 != (result = this->read_func(&this->lux, sizeof(this->lux))))
      {
        this->error_code = SE_PLATFORM_READ_FAILED;
        std::cout << "Error reading lux registers from platform. [result = %d]" << result << std::endl;
        break;
      }

      // do required conversion

    }
    while (0);

    return this->lux;
  }

}