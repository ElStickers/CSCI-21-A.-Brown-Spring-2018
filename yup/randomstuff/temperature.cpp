/*
 * Name        : temperature.cpp
 * Author      : Juan Palos
 * Description : Implementation File for the Temperature Class
 */

// Include the .h file
#include "temperature.h"

// Member Function Definitions
/*
    Consturctor #1
    Sets kelvin_ to 0
*/
    Temperature::Temperature(){
        kelvin_ = 0;
    }

/*
    Consturctor #2
    Sets kelvin_ to supplied value
*/
    Temperature::Temperature(double kelvin){
        set_kelvin(kelvin);
    }
    
/*
    Constructor #3
    Convers the supplied temperature to kelvin and internally stores it.
    The temperature's unit will be provided in the second parameter.
    If the second parameter is not valid (i.e. not 'F' or 'C') assume the
    temperature is in kelvin.
*/
    Temperature::Temperature(double temp, char unit){
        if (unit == 'F'|| unit == 'f'){
            SetTempFromFahrenheit(temp);
        }else if (unit == 'C'|| unit == 'c'){
            SetTempFromCelsius(temp);
        }else{
            set_kelvin(temp);
        }
    }
    
/*
    Mutuator
    The temperature will come in as kelvin and this function will set the
    internal temp to this value.
*/
    void Temperature::set_kelvin(double kelvin){
        kelvin_ = kelvin;
    }
    
/*
    The temperature will come in as Celsius and this function will set the
    internal temp to this value, once converted to kelvin.
*/
    void Temperature::SetTempFromCelsius(double celsius){
        kelvin__ = (celsius + 273.15)
    }
    
/*
    The temperature will come in as Fahrenheit and this function will set the
    internal temp to this value, once converted to kelvin.
*/
    void Temperature::SetTempFromFahrenheit(double fahrenheit){
        kelvin_ = ((5.0 * ((fahrenheit) - 32) / 9) + 273.15);
    }
    
/*
    Accessor
    Gets the internal temperature in Kelvin.
*/
    double Temperature::kelvin(){
        cout.setf(std::ios::showpoint|std::ios::fixed);
        cout.precision(2);
        
        return double (kelvin_);
    }
    
/*
    Returns the internal temp converted to celsius
    Formula: c = k - 273.15
*/
  double Temperature::GetTempAsCelsius(){
        return double (kelvin_ - 273.15);
  }

/*
    Returns the internal temp converted to fahrenheit
    Formula: f = ((c * 9.0) / 5) + 32;
*/
  double Temperature::GetTempAsFahrenheit(){

    return double ((((kelvin_ - 273.15) * 9.0) / 5) + 32);
  }

/*
    Outputs a representation of the temperature.
    The output will be formatted as:
    "TEMP UNIT"
    Where TEMP is the temperature to 2 decimal places and UNIT is either
    "Kelvin", "Celsius", or "Fahrenheit".
    The conversion to perform is denoted by the parameter.
    If the unit given through the argument is invalid, outputs: "Invalid Unit"
    @param char unit - The conversion to perform, either 'K', 'C' or 'F',
                       defaults to 'K' and is case-insensitive
*/
  void Temperature::Output(char unit ){
      if (unit == 'C' || unit =='c'){
        cout << GetTempAsCelsius() << " Celsius";
      }else if (unit == 'K' || unit =='k'){
        cout << kelvin() << " Kelvin";
      }else if (unit == 'F' || unit =='f'){
        cout << GetTempAsFahrenheit() << " Fahrenheit";
      }else
        cout << "Invalid Unit";
  }
