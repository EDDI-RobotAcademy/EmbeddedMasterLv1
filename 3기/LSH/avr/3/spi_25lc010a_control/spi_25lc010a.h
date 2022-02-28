#ifndef __SPI_25LC010A_H__
#define __SPI_25LC010A_H__

#include <avr/io.h>

#define SPI_SS      PB2
#define SPI_MOSI    PB3
#define SPI_MISO    PB4
#define SPI_SCK     PB5

#define EEPROM_SELECT()     PORTB &= ~(1 << SPI_SS)
#define EEPROM_DESELECT()   PORTB |= (1 << SPI_SS)

#define EEPROM_READ     0b00000011
#define EEPROM_WRITE    0b00000010
#define EEPROM_WREN     0b00000110
#define EEPROM_RDSR     0b00000101

#define EEPROM_WRITE_IN_PROGRESS        0

#define EEPROM_PAGE_SIZE            16
#define EEPROM_TOTAL_BYTE           128

void spi_init (void);
void eeprom_change_byte (uint8_t);
void eeprom_send_address (uint8_t);
uint8_t eeprom_read_status (void);
void eeprom_write_enable (void);
uint8_t eeprom_read_byte (uint8_t);
void eeprom_write_byte(uint8_t, uint8_t);

#endif // __SPI_25LC010A_H__
