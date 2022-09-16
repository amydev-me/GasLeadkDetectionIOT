# Gas Leak Detection IOT


Gas is a petroleum-derived chemical that can be dangerous in industrial areas or related places and it can explode and fire. If the gas leak is not detected early, such incidents can have dangerous consequences. A gas leak detection system is based on a wireless network that detects environmental leakage and sends information to the cloud via the nodemcu. In this project nodemcu ESP8266 and MQ2 sensor is mainly used to detect the gas leakage. The MQ2 gas sensor will detect the gas and nodemcu esp8266 will send the data to the Blynk IOT web and mobile application and the buzzer will alarm.


### System Design

<img src="https://user-images.githubusercontent.com/11514651/190640162-5e605a86-35aa-4413-8fda-97e790ced5b0.png" width="500">

### Methodology

When the gas leak detection is turned on, the ESP8266 connects to the interface created in the Blynk cloud. By connecting the blue led to the nodemcu port D7 it will turn on light. The gas sensor will send the amount of gas level synchronously via the Wi-Fi module of nodemcu board. 
As shown in Fig-2, when the MQ-2 sensor detects the gas leakage it will send the data to the nodemcu controller through the (A0) port. The nodemcu will send a notification message of a gas leak to the Blynk mobile application and the amount of the gas  level to the Blynk cloud system through the internet. The Blynk application works on IOS and Android operating systems. At the same time, the buzzer will be turned on for an alarm by connecting the digital port (D5) and blue led will be turned on for the signal by connecting the digital port D7. A 9v rechargeable battery to feed the power to the board and other components, a slide switch to turn power on/off and LCD to show the gas level. The flow chart of the system is shown in Figure-3.

<img src="https://user-images.githubusercontent.com/11514651/190642231-355f4119-749f-4210-a5b0-dca11974203c.png" width="500">


<img src="https://user-images.githubusercontent.com/11514651/190641693-626c1089-1064-4f40-bfce-2d26dfdc3e4a.png" width="300"> 
