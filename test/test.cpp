/**
 *  @file test.cpp
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
#include <math.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <src/lux/lux.h>
#include <src/temperature/temperature.h>

using namespace::std;
using namespace SensorLib;

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
static int platform_read_lux(void *p_buffer, size_t len);
static int platform_read_temp(void *p_buffer, size_t len);
static int platform_write(void *p_buffer, size_t len);

/*
*----------------------------------------------------------------------
*   Exported Functions Definitions
*----------------------------------------------------------------------
*/

int main(void)
{
  lux_t *my_light_sensor = new lux_t("Light_Sensor", platform_read_lux, platform_write);
  temperature_t *my_temp = new temperature_t("Temperature Sensor", platform_read_temp, platform_write);

  // Use current time as seed for random generator
  srand(time(0));

  cout << endl << "Light Sensor Readings:" << endl;

  for(int i = 0; i < 5; i++)
  {
    float lux_val = my_light_sensor->read();
    if (my_light_sensor->error_code == SE_OK)
    {
      cout << "Lux: " << std::fixed << std::setw( 6 ) << std::setprecision( 0 ) << lux_val << " lumens" << endl;
    }
    else
    {
      cout << "Error:: %s" << my_light_sensor->errcode_to_str(my_light_sensor->error_code);
    }
  }

  cout << endl << "Temperature Sensor Readings:" << endl;

  for(int i = 0; i < 5; i++)
  {
    float temp = my_temp->read_celsius();
    if (my_temp->error_code == SE_OK)
    {
      cout << "Celsius   : " << std::fixed << std::setw(6) << std::setprecision(1) << temp << " \370C" << endl;
      cout << "Fahrenheit: " << std::fixed << std::setw(6) << std::setprecision(1) << my_temp->to_fahrenheit(temp)
           << " \370F" << endl;
    }
    else
    {
      cout << "Error:: %s" << my_temp->errcode_to_str(my_temp->error_code);
    }
  }
  return 0;
}


static int platform_read_lux(void *p_buffer, size_t len)
{
  // dummy
  if (!p_buffer) return -1;

  float *ptr = (float *)p_buffer;
  *ptr = 32000.0f + (pow(-1, rand()) * (0.1f*rand()));

  return 0;
}


static int platform_read_temp(void *p_buffer, size_t len)
{
  // dummy
  if (!p_buffer) return -1;

  float *ptr = (float *)p_buffer;
  *ptr = 120.0f + (pow(-1, rand()) * (rand()/10000));

  return 0;
}


static int platform_write(void *p_buffer, size_t len)
{
  // dummy
  return 0;
}