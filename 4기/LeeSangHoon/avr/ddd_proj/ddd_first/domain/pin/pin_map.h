#ifndef __PIN_MAP_H__
#define __PIN_MAP_H__

typedef enum _PIN_MAP PIN_MAP;
enum _PIN_MAP
{
    // PORTD
    PIN_PORT0 = 0,
    PIN_PORT1 = 1,
    PIN_PORT2 = 2,
    PIN_PORT3 = 3,
    PIN_PORT4 = 4,
    PIN_PORT5 = 5,
    PIN_PORT6 = 6,
    PIN_PORT7 = 7,

    // PORTB
    PIN_PORT8 = 8,
    PIN_PORT9 = 9,
    PIN_PORT10 = 10,
    PIN_PORT11 = 11,
    PIN_PORT12 = 12,
    PIN_PORT13 = 13,

    // PORTC
    PIN_A0 = 16,
    PIN_A1,
    PIN_A2,
    PIN_A3,
    PIN_A4,
    PIN_A5
};

typedef enum _PIN_OPS_MODE PIN_OPS_MODE;
enum _PIN_OPS_MODE
{
    INPUT_MODE = 0,
    OUTPUT_MODE = 1
};

typedef struct _pin_vo pin_vo;
struct _pin_vo
{
    enum _PIN_MAP pin_map;
    enum _PIN_OPS_MODE io_pin_mode;
};

//#define DDRA (*(volatile unsigned char*) 0x3A)
//#define DDRB (*(volatile unsigned char*) 0x37)
//#define DDRC (*(volatile unsigned char*) 0x34)
//#define DDRD (*(volatile unsigned char*) 0x31)
//#define DDRE (*(volatile unsigned char*) 0x22)
//#define DDRF (*(volatile unsigned char*) 0x61)
//#define DDRG (*(volatile unsigned char*) 0x64)

//#define PORTA (*(volatile unsigned char*) 0x3B)
//#define PORTB (*(volatile unsigned char*) 0x38)
//#define PORTC (*(volatile unsigned char*) 0x35)
//#define PORTD (*(volatile unsigned char*) 0x32)
//#define PORTE (*(volatile unsigned char*) 0x23)
//#define PORTF (*(volatile unsigned char*) 0x62)
//#define PORTG (*(volatile unsigned char*) 0x65)

//#define PINA (*(volatile unsigned char*) 0x39)
//#define PINB (*(volatile unsigned char*) 0x36)
//#define PINC (*(volatile unsigned char*) 0x33)
//#define PIND (*(volatile unsigned char*) 0x3B)
//#define PINE (*(volatile unsigned char*) 0x21)
//#define PINF (*(volatile unsigned char*) 0x20)
//#define PING (*(volatile unsigned char*) 0x63)

#endif
