#include "spi_25lc010a.h"

void spi_init (void)
{
    // CS(Chip Select) 출력 설정
    DDRB |= (1 << SPI_SS);
    // CS를 HIGH 로 띄워서 아무 선택이 발생하지 않게 함
    PORTB |= (1 << SPI_SS);
    // MOSI
    DDRB |= (1 << SPI_MOSI);
    // MISO
    DDRB &= ~(1 << SPI_MISO);
    // SCK
    DDRB |= (1 << SPI_SCK);
    // Master Mode
    // MSTR: Master/Slave Select 비트가 1 설정되면 Master
    SPCR |= (1 << MSTR);
    // SPI 활성화
    // SPE: SPI Enable 비트가 설정됨으로써 SPI 모듈이 활성화됨
    SPCR |= (1 << SPE);
}

void eeprom_change_byte (uint8_t byte)
{
    // 전송 관점에서는 내가 전송할 데이터를 기록한다.
    // 수신 관점에서는 수신된 정보가 SPDR에 존재함을 의미하기도 한다.
    SPDR = byte;
    // 위의 데이터 전송 완료까지 대기한다.
    // SPI Status Register 의 SPIF 비트 설정을 확인
    // SPIF: SPI Interrupt Flag
    // 전송이 완료되면 알아서 설정되므로
    // 이것이 설정되는 것을 기다리는 것을 의미함
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
    EEPROM_DESELECT();

    return SPDR;
}

void eeprom_write_enable (void)
{
    // Chip Select(CS) 핀은 항상 NOT 게이트가 함께함
    // 그러므로 PORTB &= ~(1 << SPI_SS)
    // 위와 같이 비트 클리어를 시켜줘야함
    EEPROM_SELECT();

    eeprom_change_byte(EEPROM_WREN);

    // EEPROM_DESELECT()   PORTB |= (1 << SPI_SS)
    // 앞서 Chip Select 한 부분을 다시 Chip Deselect 하는 부분
    EEPROM_DESELECT();
}

uint8_t eeprom_read_byte (uint8_t address)
{
    EEPROM_SELECT();

    eeprom_change_byte(EEPROM_READ);

    eeprom_send_address(address);

    eeprom_change_byte(0);

    EEPROM_DESELECT();

    return SPDR;
}

void eeprom_write_byte(uint8_t address, uint8_t data)
{
    // 쓰기 락 해제(쓰기 허용)
    eeprom_write_enable();

    EEPROM_SELECT();

    eeprom_change_byte(EEPROM_WRITE);

    eeprom_send_address(address);

    eeprom_change_byte(data);

    EEPROM_DESELECT();
    // 쓰기가 완료될 때까지 대기
    // _BV 는 해당 비트를 1로 만듬
    while (eeprom_read_status() & _BV(EEPROM_WRITE_IN_PROGRESS))
    {
        ;
    }
}
