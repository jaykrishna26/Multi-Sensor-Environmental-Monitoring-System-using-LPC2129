# Multi-Sensor-Environmental-Monitoring-System-using-LPC2129

## 📌 Project Overview
The **Multi-Sensor Environmental Monitoring System using LPC2129** is an embedded systems project designed to monitor environmental conditions using multiple sensors.

The system uses the **LPC2129 ARM7 microcontroller** to collect sensor data, process the readings, and display the measured values. It uses the Analog-to-Digital Converter (ADC) to read analog sensor signals and UART for serial communication.

## 🎯 Objectives

* To interface multiple sensors with the LPC2129 microcontroller.
* To collect and process environmental data.
* To understand ADC configuration and analog sensor interfacing.
* To display sensor readings using an LCD.
* To implement UART communication.
* To gain practical experience in embedded C programming.

## 🛠️ Hardware Requirements

* LPC2129 ARM7 Microcontroller
* Environmental Sensors
* 16×2 LCD Display
* Power Supply
* Connecting Wires
* Required Interface Components

## 💻 Software Requirements

* Embedded C
* Keil µVision IDE
* ARMCC Compiler
* LPC2129 Microcontroller Support Files

## ⚙️ Technologies Used

* Embedded C Programming
* ARM7TDMI-S Architecture
* ADC (Analog-to-Digital Converter)
* GPIO (General-Purpose Input/Output)
* UART (Universal Asynchronous Receiver/Transmitter)
* LCD Interfacing

## 🔄 Working Principle

1. The environmental sensors measure the corresponding physical parameters.
2. The sensor outputs are connected to the LPC2129 microcontroller.
3. The ADC converts analog sensor signals into digital values.
4. The microcontroller processes the collected sensor data.
5. The processed readings are displayed on the LCD.
6. UART can be used to transmit sensor readings to a computer or another serial device.

## 📂 Project Structure

```text
Multi-Sensor-Environmental-Monitoring-System/
│
├── project_main.c
├── UART_driver.c
├── LCD_4bit.c
├── adc_driver.c
├── delay.c
├── Startup.s
└── README.md
```

## 📚 Learning Outcomes

* Understanding the LPC2129 microcontroller.
* Developing embedded C programs.
* Interfacing sensors with a microcontroller.
* Configuring and using the ADC.
* Implementing UART communication.
* Interfacing a 16×2 LCD.
* Understanding embedded system hardware and software integration.

## 🚀 Future Improvements

* Add additional environmental sensors.
* Store sensor readings for further analysis.
* Implement wireless data transmission.
* Develop a real-time environmental monitoring dashboard.
* Add alerts when sensor readings exceed predefined limits.

## 👨‍💻 Project Domain

**Embedded Systems | ARM7 | Embedded C | Microcontroller Interfacing**

## 📄 License

This project is intended for educational and learning purposes.
