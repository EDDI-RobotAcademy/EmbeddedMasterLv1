#include "spi_25LC010A.h"

void spi_init (void)
{
    // CS(Chipt Select) 출력 설정
    DDRB |= ( 1 << SPI_SS );
    // CS를 HIGH 로 띄워서 아무 선택이 발생하지 않게 함
    PORTB |= (1 << SPI_SS);
    // MOSI
    DDRB |= (1 << SPI_MOSI);
    // MISO
    DDRB &= ~(1 << SPI_MISO);
    // SCK
    DDRB |= (1 << SPI_SCK);
    // Master Mode
    SPCR |= (1 << MSTR);
    // SPI 활성화
    SPCR |= (1 << SPE);
}

void eeprom_change_byte (uint8_t byte)
{
    SPDR = byte;
    // 위의 데이터가 전송 완료되기까지 기다린다.
    loop_until_bit_is_set(SPSR, SPIF);
}

void eeprom_send_address (uint8_t address)
{
    eeprom_change_byte(address);
}

uint8_t eeprom_read_status (void)
{
    // EEPROM 선택
    EEPROM_SELECT();
    // 상태 읽기
    eeprom_change_byte(EEPROM_RDSR);
    // 읽기
    eeprom_change_byte(0);
    // EEPROM 선택 해제
    EEPROM_DSELECT();

    return SPDR;
}

void eeprom_write_enable (void)
{
    // EEPROM 선택
    EEPROM_SELECT();
    // 쓰기 명령
    eeprom_change_byte(EEPROM_WREN);
    // EEPROM 선택 해제
    EEPROM_DSELECT();
}

uint8_t eeprom_read_byte (uint8_t address)
{
    // EEPROM 선택
    EEPROM_SELECT();
    // 읽기 명령
    eeprom_change_byte(EEPROM_READ);
    //주소 전송
    eeprom_send_address(address);
    //더미 전송
    eeprom_change_byte(0);

    // EEPROM 선택 해제
    EEPROM_DSELECT();

    return SPDR;
}
void eeprom_write_byte (uint8_t address, uint8_t data)
{
    // 쓰기 락 해제(쓰기 허용)
    eeprom_write_enable();
    // EEPROM 선택
    EEPROM_SELECT();
    // 쓰기 명령
    eeprom_change_byte(EEPROM_WRITE);
    //주소 전송
    eeprom_send_address(address);
    // 데이터 전송
    eeprom_change_byte(data);

    // EEPROM 선택 해제
    EEPROM_DSELECT();

    while (eeprom_read_status() & _BV(EEPROM_WRITE_IN_PROGRESS))
    {
        ;
    }
}
