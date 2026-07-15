💊 User-Configurable Medicine Reminder System using LPC2148 (ARM7)
_______________________________________________________________________________________________
⭐ Overview
A User-Configurable Medicine Reminder System developed using the LPC2148 ARM7 Microcontroller to help users take medicines on time. The system allows users to configure medicine schedules through a 4×4 Matrix Keypad while the Real-Time Clock (RTC) continuously monitors the current date and time. Whenever a configured medicine time is reached, the system automatically alerts the user using a buzzer and displays a reminder message on the 16×2 LCD.

The system performs the following operations:

⏰ Real-Time Clock Monitoring

⌨️ Medicine Time Configuration

💾 Medicine Schedule Storage

📟 Real-Time LCD Display

🔔 Automatic Medicine Reminder

✅ User Acknowledgement

The LPC2148 continuously compares the RTC time with the stored medicine schedules. When the scheduled time matches, the buzzer generates an alert and the LCD displays "Take Medicine Now". The reminder stops when the user acknowledges it using Switch-2 or automatically after the timeout period. 
________________________________________
📷 Complete System Architecture
<img width="953" height="673" alt="image" src="https://github.com/user-attachments/assets/a3bb7457-5d66-4606-aa1d-3441212ddf82" />



________________________________________
🎯 Project Objectives


•	Display real-time date and time on LCD 

•	Allow users to configure medicine schedules

•	Monitor medicine timings continuously 

•	Generate automatic reminder alerts 

•	Improve medication adherence 

•	Reduce chances of missed medicine doses 

•	Provide an easy-to-use embedded healthcare solution 

•	Support configurable reminder schedules 

These objectives correspond to the project objective described in the PDF. 
________________________________________
🔧 Hardware Components and Their Purpose

Component	Purpose

LPC2148 (ARM7 Microcontroller)	--->Main controller that manages the complete medicine reminder system

RTC (Real-Time Clock)	--->Maintains accurate current date and time

4×4 Matrix Keypad	---->Used to configure medicine reminder timings

16×2 LCD Display	-->Displays current time, date, and reminder messages

Buzzer	-->Generates an audible reminder when medicine time arrives

Switch-1	--->Enters RTC edit mode or medicine schedule configuration

Switch-2	---->Acknowledges medicine reminder and stops buzzer

USB-UART Converter / DB-9 Cable	--->Used for programming and serial communication

Power Supply	--->Provides regulated power to the complete system

Hardware requirements are taken from the uploaded project document. 
________________________________________
💊 System Working Flow

•	System powers ON. 

•	LPC2148 initializes RTC, LCD, keypad, buzzer, timer, and interrupts.

•	LCD continuously displays the current date and time. 

•	User presses Switch-1 to enter configuration mode. 

•	User edits RTC time or configures medicine timings using the keypad.

•	Medicine schedules are stored in controller memory. 

•	Controller continuously compares RTC time with stored schedules. 

•	If a medicine time matches: 

o	LCD displays "Take Medicine Now" 

o	Buzzer starts ON/OFF alert. 

o	One-minute acknowledgement timer starts. 

•	User presses Switch-2 to acknowledge medicine intake.

•	Buzzer stops and reminder clears. 

•	If no acknowledgement is received within one minute, the buzzer stops automatically and the system resumes monitoring. 

<img width="986" height="1481" alt="image" src="https://github.com/user-attachments/assets/62a12344-1760-4453-926f-432663510e52" />


This workflow follows the working principle and software flow provided in the PDF. 
________________________________________
⌨️ Medicine Schedule Configuration

When Switch-1 is pressed:

•	Enter Configuration Mode 

•	Choose RTC Edit or Medicine Configuration

•	Enter Medicine Hour 

•	Enter Medicine Minute 

•	Save Medicine Schedule 

•	Store Configuration in Memory 

•	Return to Normal Monitoring Mode 
________________________________________
🔔 Medicine Reminder Operation

When a scheduled medicine time is reached:

•	Read Current RTC Time 

•	Compare with Stored Medicine Timings 

•	Detect Matching Schedule 

•	Display "Take Medicine Now" 

•	Activate Buzzer 

•	Start One-Minute Timer 

•	Wait for User Acknowledgement 

•	Stop Buzzer 

•	Clear Reminder 

•	Continue Monitoring 
________________________________________
💾 Schedule Management

The controller maintains medicine reminder information such as:

Field	Description

Medicine Number	Identifier of the medicine

Reminder Hour	Scheduled hour

Reminder Minute	Scheduled minute

Reminder Status	Pending / Completed

The medicine schedule is stored in the controller memory and continuously compared with the RTC time to generate reminders. 
________________________________________
🔧 Communication Interfaces

Device	Interface

RTC	Internal RTC Module

LCD	GPIO

4×4 Matrix Keypad	GPIO

Buzzer	GPIO

Switch-1	External Interrupt (EINT0)

Switch-2	External Interrupt (EINT1)

LPC2148	ARM7 Architecture

The block diagram and software flow indicate the use of GPIO and external interrupts EINT0/EINT1. 
________________________________________
🔒 System Features

•	RTC-Based Time Monitoring 

•	User Configurable Medicine Schedule 

•	Automatic Medicine Reminder 

•	LCD Time and Date Display

•	Audible Buzzer Alert 

•	User Acknowledgement Support 

•	External Interrupt-Based Operation

•	Continuous Schedule Monitoring 

•	ARM7 Embedded Design 

•	Low Power Embedded Healthcare System 
________________________________________
🚀 Features

•	Real-Time Clock Monitoring 

•	Medicine Schedule Configuration 

•	Automatic Reminder Generation 

•	LCD User Interface 

•	Buzzer Notification 

•	Keypad-Based User Input 

•	RTC Time Editing 

•	Embedded C Firmware 

•	ARM7-Based Embedded System 

•	Continuous Monitoring 
________________________________________
📸 Project Gallery

Project Screenshot | Block Diagram | Circuit Diagram | LCD Display | Hardware Prototype
________________________________________
⚙️ Working Principle

•	RTC continuously maintains the current date and time. 

•	LPC2148 reads the RTC periodically. 

•	User-configured medicine schedules are stored in memory. 

•	Controller compares RTC time with stored reminder timings.

•	When both values match: 

o	LCD displays "Take Medicine Now". 

o	Buzzer starts periodic ON/OFF alert. 

•	User acknowledges the reminder using Switch-2. 

•	If acknowledged, the buzzer stops immediately. 

•	Otherwise, the buzzer automatically stops after one minute. 

•	The system resumes monitoring for the next reminder. 

This sequence is directly based on the project's working principle. 
________________________________________
📚 Applications

•	Home Healthcare 

•	Hospitals

•	Clinics 

•	Elderly Patient Care 

•	Patient Monitoring Systems 

•	Smart Healthcare Devices 

•	Personal Medicine Reminder Systems 

•	Embedded Medical Applications 
________________________________________
🎯 Advantages

•	Helps Prevent Missed Medicine Doses 

•	Improves Patient Medication Compliance

•	Automatic Reminder Generation 

•	Easy Schedule Configuration 

•	Real-Time Clock Accuracy 

•	Simple User Interface 

•	Low Power Consumption 

•	Cost-Effective Embedded Solution 
________________________________________
💻 Software Used

•	Embedded C 

•	Keil μVision

•	Flash Magic 

The software tools listed match the uploaded document. 
________________________________________
🔌 Hardware Used

•	LPC2148 ARM7 Development Board '

•	16×2 LCD Display 

•	4×4 Matrix Keypad 

•	RTC (Internal LPC2148 RTC) 

•	Buzzer 

•	Switch-1 

•	Switch-2 

•	USB-UART Converter / DB-9 Cable 

•	Power Supply 
________________________________________
👨‍💻 Author

Ratnam Goriparthi

Bachelor of Technology (Electronics and Communication Engineering)

Embedded Systems Enthusiast

2025 Graduate
________________________________________
📜 License

This project is intended for educational and academic purposes.

Feel free to use, modify, and improve the project for learning and research.

⭐ If you found this project helpful, consider giving it a Star on GitHub.
________________________________________
🙏 Thank You
Happy Coding! 🚀
