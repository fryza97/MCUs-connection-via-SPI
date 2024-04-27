Soft for STM32L476RG (SPI master) and ATMEGA328P (SPI slave) to represent SPI connection between two microcontrollers.

Graphic 1: Connection graph

![image](https://github.com/fryza97/MCUs-connection-via-SPI/assets/157904512/4b8a9b4c-9bc9-41db-9bd8-5530a7e7ca4f)

When both microcontrollers are connected to terminals you can check SPI connections. There are 3 posibilites:
1) Duplex transmission: Send a byte to the ATmega. The ATmega will provide information about the reception to the PC and write the byte to the SPDR register. Next, send the byte to the STM32. The STM32 will send back information to the PC via UART and transmit the byte via SPI to the ATmega. Afterward, the STM32 will receive a byte from the ATmega and send another message to the PC. Finally, the ATmega will send a message about the SPI reception to the PC. This process is represented in Graphic 2.

Graphic 2: The terminal after a few duplex transmissions.

![image](https://github.com/fryza97/MCUs-connection-via-SPI/assets/157904512/598c84bc-9d0c-4890-ba09-00c268bf7e5d)
   
2) If the STM32 sends a few bytes, the ATmega sends back the byte written in SPDR and an 'a' in subsequent SPI transmissions. The ATmega only sends information about SPI reception via USART, as shown in Graphic 3.

Graphic 3: The terminal after a few COM PORT 6 - STM32 transmissions.

![image](https://github.com/fryza97/MCUs-connection-via-SPI/assets/157904512/646c1ba4-0a50-401e-a2b7-4aec07bc4178)

3) If the ATmega receives several bytes consecutively from the COM port, it sends back each byte via USART and overwrites the SPDR register. When the master (STM32) initiates transmission via USART, the last byte from the COM port will be sent, as shown in Graphic 4.

Graphic 4: The terminal after a few COM PORT 7 - ATmega transmissions.

![image](https://github.com/fryza97/MCUs-connection-via-SPI/assets/157904512/5e5bf122-722b-4bf1-bfe8-a2c373f50878)
