# Project report



## Objective 

The objective of the assignment 3 is to take the knowledge gained from assignment 1 & 2 and apply that knowledge to specific problem. My objective is to create a native weather for the indoor plants. Since most of the indoor plants are from tropical region, providing their native weather stimulates the healthy growth. 

## Motivation

I wanted to create an automatic garden after I almost killed some plants when I was away from home for few weeks. I looked up few automatic water gardening system online. But i could not find any system that creates the whole weather pattern in the market. So I decided to build one myself.

## Requirements
1. raspberry pi 4b
2. Bread board
3. MCP3008 analog to digital converter
4. moisture sensor 
5. DHT22 temperature and humditiy sensor
6. DC motor
7. vinly tubes for watering
8. smart plug
9. Humidifier
10. Grow light
11. male to female, female to male, male to male jumper wires



## Characterization

### DHT22 sensor
The DHT22 is the temperature and humidity sensor. Few details about DHT22 are 
1.Low cost
2.3V to 5V power and I/O
3.2.5mA max current use during conversion (while requesting data)
4.Good for 0-100% humidity readings with 2-5% accuracy
5.Good for -40 to 80°C temperature readings ±0.5°C accuracy
6.No more than 0.5 Hz sampling rate (once every 2 seconds)
7.Body size 15.1mm x 25mm x 7.7mm
8.3 pins with 0.1" spacing

DHT22 has more accuracy rate with only ±0.5% error rate so I chose this over DHT11 sensor. It is a 3 pin sensor with VCC,GND and Data pin. I have used board library to get the data from DHT22 sensor. For that I had to install adafruit_dht python library. 


### WebAPI 

### Moisture sensor 

The moisture sensor used is KY70. It has both analog and digital output. For reading the analog output I have used MCP3008 analog to digital converter. The pin configuration of the MCP3008 is shown below.
![MCP3008 pin layout](./images/mcp3008.png)  <br/><br/>
The connections from MCP3008 to Raspberry pi as follows

MCP3008 Pin 16(VDD) to Raspberry pi Pin 1(3.3V)
MCP3008 Pin 15(VREF) to Raspberry pi Pin 1(3.3V) 
MCP3008 Pin 14(AGND) to Raspberry pi Pin 6(GND) 
MCP3008 Pin 13(CLK) to Raspberry pi Pin 23(SCLK) 
MCP3008 Pin 12(DOUT) to Raspberry pi Pin 21(MISO) 
MCP3008 Pin 11(DIN) to Raspberry pi Pin 19(MOSI) 
MCP3008 Pin 10(CS/SHDN) to Raspberry pi Pin 24(CE0) 
MCP3008 Pin 9(DGND) to Raspberry pi Pin 6(GND) 
SoilMoisture GND to GND
SoilMoisture VCC to +3.3V (connected to bread board)
SoilMoisture A0 to MCP3008 CH0


### Pump


### smart plug






# References

1. https://gist.github.com/benrules2/6f490f3a0e082ae6592a630bd7abe588 
2. https://pimylifeup.com/using-ifttt-with-the-raspberry-pi/
3. https://www.instructables.com/Raspberry-Pi-Tutorial-How-to-Use-the-DHT-22/
4. https://gist.github.com/benrules2/6f490f3a0e082ae6592a630bd7abe588
5. https://pimylifeup.com/raspberry-pi-humidity-sensor-dht22/
6. https://community.dfrobot.com/makelog-311806.html 
7. https://www.instructables.com/Measuring-Soil-Moisture-Using-Raspberry-Pi/
8. https://tutorials-raspberrypi.com/measuring-soil-moisture-with-raspberry-pi
9. https://github.com/WayinTop  