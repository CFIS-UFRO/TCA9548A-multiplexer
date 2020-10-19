/*
Based on the TCA9548A datasheet.
Author: Bryan Casanelli - bryancasanelli@gmail.com
*/

#include "rpi_tca9548a.h"
#include <wiringPiI2C.h>
#include <wiringPi.h>

rpi_tca9548a::rpi_tca9548a(){
  wiringPiSetup();
}

rpi_tca9548a::~rpi_tca9548a(){
  no_channel();
}

int rpi_tca9548a::init(int id){
  this->fd = wiringPiI2CSetup(id);
  if (this->fd == -1){return -1;} // Error
  return 0;                       // Ok
}

void rpi_tca9548a::set_channel(uint8_t channel){
  wiringPiI2CWrite(this->fd,1<<channel);
}

void rpi_tca9548a::no_channel(){
  wiringPiI2CWrite(this->fd,0);
}
