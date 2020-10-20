This code allows to use the TCA9548A multiplexer on the Raspberry Pi board.
It is written in c++ using the wiringPi library.

# Example
main.cpp:
```
#include "rpi_tca9548a.h"

int main(void){
	rpi_tca9548a tca;
	tca.init(0x70);
	tca.set_channel(1);
}
```
To compile: g++ main.cpp rpi_tca9548a.h rpi_tca9548a.cpp -o main -lwiringPi   
The previous code changes the channel to the number 2 (of 8), so while the main function is running you can use the device connected to the 1st channel of the multiplexer (for example initializing it with the wiringPi library using the expected I2C address of the device).

# Available functions
The user can access to the following functions:

### int init(int id)
Initialize the multiplexer.
- id: I2C address.

Return -1 if an error occurs, otherwise return 0.

### void set_channel(uint8_t channel)
Set the channel.
- channel: channel from 0 to 7.

### void no_channel()
Set no channel.

