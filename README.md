Chapter 1
INTRODUCTION
In recent years, the automotive industry has witnessed a paradigm shift with the 
integration of advanced technologies aimed at enhancing vehicle safety, efficiency, and user 
experience. One of the most significant advancements in this domain is the development of 
Vehicle Automation Systems (VAS), which leverage cutting-edge technologies to automate 
various driving tasks. These systems hold immense potential to revolutionize transportation by 
making vehicles safer, more efficient, and capable of offering enhanced functionalities.
This project aims to design and implement a vehicle automation system that uses the 
STM32G431MBT6 based INDUS microcontroller. The system comes with advanced features, 
such as CAN Bus communication enabled by the ATA6561-GAQW-N module, real-time 
multitasking through a Real-Time Operating System (RTOS), and sensor integration for engine 
temperature monitoring and smoke gas detection using MQ2 and LM35 sensors. Consistent 
real-time multitasking is achieved through the implementation of an RTOS, allowing for 
efficient task management and timely response to critical events. The integration of sensors, 
including MQ2 for smoke gas detection and LM35 for engine temperature monitoring, 
contributes to the system's ability to monitor and react to environmental changes. The proposed 
vehicle automation system not only ensures enhanced safety by detecting potential hazards but 
also improves overall performance by providing real-time data insights. The proactive 
maintenance feature enables preventive measures based on continuous monitoring, ultimately 
leading to increased reliability and longevity of the vehicle. 
In conclusion, this project showcases the successful development of a vehicle 
automation system that leverages the STM32G431 microcontroller, CAN Bus communication, 
RTOS, and sensor integration. The system's multifaceted capabilities contribute to a safer and 
more efficient driving experience while paving the way for future advancements in intelligent 
transportation systems.
2

Chapter 3
SOFTWARE REQUIREMENT SPECIFICATION
3.1 Hardware Component Specification 
3.1.1 INDUS board Microcontroller
The INDUS Development Board features the STM32G431MBT6 processor, a powerful and 
versatile device suitable for a wide range of applications.
Fig 3.1: INDUS board Microcontroller
The device is powered by a 32-bit Arm Cortex-M4 core that can run up to 170 MHz. It has 128 
KB Flash memory and 32 KB SRAM. The device includes a comprehensive set of peripherals 
such as GPIO, UART, SPI, I2C, ADC, DAC, and more. Additionally, it has an integrated USB 
controller for connectivity. With low-power operation and multiple power-saving modes, it is 
a great choice for efficient energy consumption. It is compatible with STM32 CubeIDE for 
development purposes.
4
3.1.2. MQ2 Module
The MQ2 sensor can detect a range of gases, includingvLPG (liquefied petroleum gas), 
Propane, Methane, Butane, Alcohol, Hydrogen, Smoke, Carbon monoxide (CO).
Fig 3.2: MQ2 Module
The MQ2 sensor has several basic uses, including Gas leak detection, Smoke detection, Air 
quality monitoring, Environmental monitoring.
3.1.3. LM35 
LM35 is a temperature sensor that outputs an analog signal which is proportional to the 
instantaneous temperature. The output voltage can easily be interpreted to obtain a temperature 
reading in Celsius.
5
Fig 3.3: LM35 Temperature sensor
3.1.4. RG1602A 16 x 2 LCD Display with I2C module
16×2 Liquid Crystal Display iis 16 character by 2-line display having a very clear and high 
contrast. I2C module helps to save the resources as it takes only 4 pins.
Fig. 3.4: RG1602A 16 x 2 LCD Display with I2C module
3.2 Communication Protocols 
6
3.2.1 I2C (Inter-Integrated Circuit) 
I2C is a communication protocol that uses a two-wire serial interface. The two wires 
are the clock line (SCL) and the data line (SDA). The master device, usually a microcontroller, 
controls the communication by generating clock pulses and transmitting data to the slave 
devices connected to the bus. The slave devices respond by sending data back to the master. 
One key feature of I2C is its acknowledgement mechanism. After transmitting a byte 
of data, the master waits for an acknowledgement from the slave device. If the slave receives 
the data correctly, it sends an acknowledgement bit back to the master. This ensures that data 
is transmitted and received accurately, minimizing the risk of data corruption. I2C offers 
several advantages over other communication protocols. It requires only two wires (SCL and 
SDA), significantly simplifying the hardware setup and reducing potential signal interference 
compared to protocols that require multiple wires. I2C allows for the integration of multiple 
sensors or devices on the same bus, each with its unique address. This enables the creation of 
complex systems with various sensors and actuators communicating seamlessly. 
I2C is designed with energy efficiency in mind, making it suitable for applications 
where power consumption is a critical factor. It operates at low voltages and minimizes power 
consumption during idle periods. The ability to support multiple devices on the same bus makes 
I2C highly scalable, allowing for the easy addition or removal of sensors or devices as needed. 
Overall, I2C is a versatile and reliable communication protocol that simplifies the development 
of embedded systems and real-time applications, providing an efficient and low-power solution 
for inter-device communication.
3.2.2 CAN FD Protocol 
CAN FD, which stands for Controller Area Network Flexible Data-rate, is a widely 
used communication protocol in automotive and industrial applications. It is an upgraded 
version of the classic CAN protocol, providing higher data rates and larger data payload sizes 
while maintaining compatibility with existing CAN networks. 
CAN FD uses a differential two-wire interface (CANH and CANL) and supports both 
standard and extended frame formats. It is a critical component of the INDUS Board project, 
enabling communication between the master device and peripheral devices. Each device
connected to the CAN FD bus can act as a node, transmitting and receiving messages based on 
a predefined protocol. 
CAN FD has significantly higher data rates than traditional CAN protocols, reaching 
7
up to 8 Mbps. This faster data exchange enables real-time communication and high-speed data 
transfer, making it ideal for applications that require quick and efficient data transfer. 
CAN FD is renowned for its robustness and reliability. It employs a priority-based 
message arbitration scheme to ensure timely and deterministic message delivery, even in 
congested network conditions. Additionally, CAN FD incorporates error detection and 
correction mechanisms, such as cyclic redundancy checks (CRCs), to detect and mitigate data 
errors, ensuring reliable communication in noisy environments. 
CAN FD's scalability and flexibility make it a highly adaptable communication 
protocol. It allows for seamless expansion or reconfiguration of existing networks, making it 
suitable for changing system requirements. Its versatility and reliability make it an ideal 
communication protocol for safety-critical systems where fast and reliable communication is 
crucial.
3.3 Software Specification 
3.3.1 Development Environment: STM32 CubeIDE: 
STM32 CubeIDE is an Eclipse-based Integrated Development Environment (IDE) that 
is specifically designed for STM32 microcontrollers. It offers a comprehensive suite of tools 
for developing, debugging, and managing STM32-based projects. 
Features: 
• User-Friendly Interface: 
• Intuitive graphical user interface for easy navigation and code editing. 
• Built-in editor with syntax highlighting, code completion, and error checking. 
• Project templates for quick and easy project setup. 
• Support for multiple projects and workspaces.
• Version control integration with Git. 
3.3.2. Debugging: -
• On-chip debugging using ST-Link or Seggar J-Link debug probes. 
• Comprehensive features such as breakpoints, watchpoints, and variable inspection. 
• Integrated terminal for console output and command execution.
• includes GDB-based debugger with command-line interface. 
8
• Supports debugging of both C and assembly code. 
• Breakpoint setting, variable inspection, and call stack navigation.
3.3.3 Toolchain: 
• STM32 CubeIDE includes the GCC compiler toolchain for compiling, linking, and 
debugging STM32 projects. 
• The toolchain provides the necessary compiler, linker, and debugger tools for 
developing embedded applications. 
3.3.4 GCC Compiler: -
• Supports all major C and C++ language features. 
• Optimizations for code size and execution speed. 
• Built-in libraries for peripheral access and standard C functions. 
3.3.5 Linker: 
• Generates executable files (.elf) and downloadable images (.hex, .bin). 
• Supports linker scripts for memory mapping and section placement. 
3.4 FreeRTOS (CMSIS V1):
FreeRTOS is an open-source, portable, and robust Real-Time Operating System 
(RTOS) designed for embedded systems. It provides a preemptive, priority-based scheduler for 
managing multiple tasks efficiently. CMSIS V1 is a standardized hardware abstraction layer 
for ARM Cortex-M processors. It defines standardized APIs for accessing hardware 
peripherals, making it easier to port applications across different STM32 devices. 
Task Management: 
• Supports multiple tasks running concurrently. 
• Each task has a unique priority level, determining its scheduling order. 
• Tasks can be created, deleted, and suspended dynamically. 
• Reduces power consumption by entering a low-power sleep mode when no tasks are 
ready to run. 
• Wakes up when a task becomes ready or an interrupt occurs.
RTOS Configuration: 
The STM32 CubeIDE's RTOS configuration allows for efficient management of tasks, 
9
queues, and interrupts. The task configuration feature allows you to define task names and 
priorities, as well as set stack sizes. In multi-core STM32 devices, tasks can also be assigned 
to specific cores and task affinities can be set for optimal scheduling. The queue configuration 
feature allows you to create queues for inter-task communication and specify queue sizes and 
message types. The interrupt configuration feature enables the configuration of interrupts for 
peripherals and external events and the association of interrupt handlers with tasks for efficient 
handling. 
STM32 CubeIDE offers a comprehensive task management system for creating, 
scheduling, and managing multiple tasks in an RTOS-based application. The task creation 
feature allows you to create tasks with unique names, priorities, and stack sizes, as well as 
specify task entry points and arguments. The RTOS scheduler assigns CPU time to tasks based 
on their priorities in the task scheduling feature. When higher-priority tasks become ready to 
run, they pre-empt lower-priority tasks.
10
Chapter 4
ARCHITECTURE
4.1. System Architectures for Vehicle Automation:
 Research in this area explores different architectures for integrating automation 
functionalities within vehicles. Studies compare centralized versus distributed architectures, 
discussing their advantages and drawbacks in terms of scalability, reliability, and performance. 
Additionally, modular architectures that facilitate seamless integration of new functionalities 
and components are investigated to accommodate future advancements in VAS technology.
Fig 4.1: System Bock diagram
The block diagram depicts the architecture of a temperature & gas detection system that utilizes
sensors and microcontrollers for functionality.
4.2 Components and their Roles
4.2.1 Indus Development Board
The INDUS Development Board features the STM32G431MBT6 processor, a powerful 
and versatile device suitable for a wide range of applications. The device is powered by a 32-
bit Arm Cortex-M4 core that can run up to 170 MHz. It has 128 KB Flash memory and 32 KB 
SRAM. It includes a comprehensive set of peripherals such as GPIO, UART, SPI, I2C, ADC, 
DAC, and more. Additionally, it has an integrated USB controller for connectivity. With lowpower operation and multiple power-saving modes, it is a great choice for efficient energy 
11
consumption. It is compatible with STM32 CubeIDE for development purposes.
4.2.2 LM35 Temperature Sensor
The LM35 is a popular analog temperature sensor that provides an accurate and linear 
voltage output directly proportional to the Celsius temperature, based on the temperaturedependent voltage across its terminals. It has a linear temperature coefficient of 10 mV/°C and 
produces an output voltage of 10 mV per degree Celsius, making it easy to interface with 
microcontrollers. It typically operates in a temperature range from -55°C to 150°C.
4.2.3 MQ2 Smoke Sensor
The MQ2 sensor can detect a range of gases, including LPG (liquefied petroleum gas), 
Propane, Methane, Butane, Alcohol, Hydrogen, Smoke, Carbon monoxide (CO). It is based on 
the principle of resistance change in response to the presence of different gases. It contains a 
tin dioxide (SnO2) sensing layer that exhibits changes in resistance when exposed to specific 
gases. It provides an analog voltage output proportional to the gas concentration. The 
sensitivity of the sensor can often be adjusted using a potentiometer.
4.2.4 RG1602A 16 x 2 LCD Display I2c Module
A 16x2 LCD (Liquid Crystal Display) is used for displaying alphanumeric characters. 
It consists of 16 columns and 2 rows of characters. Each character is typically a 5x8 pixel 
matrix, allowing for the display of standard ASCII characters. This I2C-enabled display is
convenient for projects as it simplifies the wiring. I2C is a serial communication protocol that 
requires only two wires (SDA for data and SCL for the clock).
4.2.5 ATA6561-gaqw-N CAN Bus Module
The ATA6560/1 is a high-speed CAN transceiver that provides an interface between a 
Controller Area Network (CAN) protocol controller and the physical two-wire CAN bus. The 
transceiver is designed for high-speed (up to 5 Mbps) CAN applications in the automotive 
industry. CAN is a robust and reliable serial communication protocol used for real-time 
applications in various industries.
12
Chapter 5
SYSTEM DESIGN
5.1 System Design 
The block diagram below represents the system design and control flow for the project.
Fig 5.1: System Design
The INDUS Microcontroller is based on STM32G431MBT6 and serves as the central 
processing unit for controlling the entire system. It interfaces with different peripherals and 
modules to acquire data and actuate various functions. The CAN Bus Module ATA6561-
GAQW-N enables communication with other electronic control units (ECUs) in the vehicle 
through the Controller Area Network (CAN) protocol. It facilitates real-time data exchange, 
thus ensuring coordinated control.
The system includes two types of sensors: the MQ2 sensor that monitors smoke and gas 
levels, and the LM35 temperature sensor that monitors engine temperature. The MQ2 sensor 
provides input for early detection of potential hazards, while the LM35 temperature sensor 
helps prevent overheating and ensures optimal performance of the engine.
Real-Time Operating System (RTOS) Manages multitasking to ensure timely execution 
of tasks. The system has three tasks: CAN Communication Task, Sensor Data Processing Task, 
13
and Safety and Control Task. The CAN Communication Task sends and receives messages via 
the CAN bus and allows real-time communication between the microcontrollers using the 
ATA6561-GAQW-N module. The Sensor Data Processing Task collects data from MQ2 and 
LM35 sensors and analyzes it for smoke detection and engine temperature monitoring. The 
Safety and Control Task is responsible for implementing safety algorithms and control 
strategies, as well as executing proactive maintenance routines based on sensor inputs.
The system initiates maintenance actions based on sensor inputs to prevent potential 
issues. This includes engine cooling strategies based on temperature data and alerting 
mechanisms for detected smoke or gas. The system has built-in mechanisms that can detect 
and handle faults in the sensors or communication modules. This ensures that the system 
remains reliable and can continue to function even if there are any issues.
The user interface provides a convenient way for users to monitor the system 
parameters and receive alerts. It displays real-time data such as the engine temperature and gas 
levels, giving users an accurate picture of how the system is performing at any given time.
14
Chapter 6
IMPLEMENTATION
The project utilizes an STM32G431MBT6-based INDUS microcontroller for a vehicle 
automation system, featuring CAN Bus communication via ATA6561-GAQW-N module, 
Real-time multitasking with RTOS, Sensor integration (MQ2, LM35) for engine temperature 
monitoring and smoke gas detection. This system aims to enhance safety and performance 
through proactive maintenance and real-time data exchange.
Fig 6.1: Implementation
During normal operation, the green LEDs are turned on, the MQ2 gas sensor module 
continuously samples data for LPG, CO and smoke and the LM35 temperature sensor for 
temperature monitoring. Each sensor reading is processed within the FreeRTOS scheduler, 
ensuring that tasks related to smoke and temperature monitoring are all active and running 
15
concurrently. These tasks are of equal priority, allowing the system to respond promptly to any 
hazardous conditions that may arise. Meanwhile, the display node remains in ready to receive 
and display any relevant information transmitted from the sensor node.
When any of the sensors on the sensor node detect a condition exceeding predefined 
thresholds, the corresponding task is triggered. For instance, if high levels of CO, LPG or 
smoke are detected, or if the temperature sensor detects an abrupt change in engine temperature, 
the alert task is activated. This task immediately executes, first performing necessary physical 
responses, such as activating the cooling fan to reduce engine temperature, alarming via buzzer
and turning on red LED. Subsequently, the alert task sends a message via the CAN FD protocol 
to the display node, specifying the type of hazard detected. This message transmission ensures 
that the display node receives immediate notification of the hazard. Simultaneously, the alert 
task triggers the buzzer on the sensor node to sound an alarm, providing localized warning. 
Reception and Display on Display Node: Upon receiving the hazard detection message from 
the sensor node, the display node interprets the message and initiates corresponding actions. It 
activates its own buzzer to provide additional audible notification and updates the LED display 
to visually represent the type of hazard detected. This real-time display of hazard information 
ensures that users are promptly informed and can take appropriate action to address the 
situation. 
Once the alert task has completed its assigned duties, which may include transmitting 
a message and activating local alarms, it is removed from the system to free up resources. This 
removal ensures that other sensing tasks can resume their execution without any delay, 
maintaining continuous monitoring of environmental conditions. Meanwhile, the system 
returns to a normal operational state, with sensors continuing to monitor for any further hazards.
