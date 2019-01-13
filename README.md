# Sensor Library

# Work in Progress...

This will be a common library for sensors like
- accelerometers
- temperature sensor
- light sensor, etc


### Implemented so far:
- generic temperature sensor class
- generic light sensor class
- tests


#### temperature sensor class:

`class temperature_t` inherits from `class sensor_t`

usage:

define an object: `temperature_t *my_temp = new temperature_t("Temperature Sensor", platform_read, platform_write);`

To read temperature value:
```
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
```

#### light sensor class:

`class lux_t` inherits from `class sensor_t`

usage:

define an object: `lux_t *my_sensor = new lux_t("Light Sensor", platform_read, platform_write);`

To read lux value:
```
float lux_val = my_light_sensor->read();
if (my_light_sensor->error_code == SE_OK)
{
  cout << "Lux: " << std::fixed << std::setw( 6 ) << std::setprecision( 0 ) << lux_val << " lumens" << endl;
}
else
{
  cout << "Error:: %s" << my_light_sensor->errcode_to_str(my_light_sensor->error_code);
}
```
