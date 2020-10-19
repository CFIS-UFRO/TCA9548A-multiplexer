#ifndef RPI_TCA9548A_H
#define RPI_TCA9548A_H

#include <stdint.h>

class rpi_tca9548a {
  public:
    rpi_tca9548a();
    ~rpi_tca9548a();
    int init(int id);
    void set_channel(uint8_t channel);
    void no_channel();
  private:
    int fd;
};

#endif
