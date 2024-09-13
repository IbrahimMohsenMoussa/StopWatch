
# Stopwatch Simulation using AVR Microcontroller

This project is a **stopwatch** implemented on an AVR microcontroller, simulated in **Proteus**. It allows the user to control the stopwatch's functionality, including **counting up**, **counting down**, **pausing/resuming**, and adjusting time. The display is handled using a **seven-segment display**, and pushbuttons provide user interaction.

## Features
- **Count Up/Down Mode**: Allows the user to switch between counting up or down.
- **Pause/Resume Functionality**: The stopwatch can be paused and resumed.
- **Time Adjustment**: Users can manually increment/decrement hours, minutes, and seconds.
- **End Countdown Alarm**: A buzzer signals the end of the countdown timer.
- **Real-Time Display**: Hours, minutes, and seconds are displayed on a 6-digit, multi 7-segment display.

## Technical Highlights
- **Timers and Interrupts**: Utilizes **Timer1** for counting and **Timer0** for debouncing and accurate timing.
- **Pushbutton Interface**: External buttons for incrementing/decrementing and mode selection.
- **AVR Registers**: Direct manipulation of AVR registers to control GPIO and interrupts.
- **Modular Code Design**: Separated code into various modules for timers, pushbuttons, and the seven-segment display.

## Tools & Technologies
- **Proteus**: For simulation of the entire project, including the microcontroller and external components.
- **AVR (Atmega32)**: Microcontroller used for the core stopwatch functionality.
- **C Programming**: Code developed in C using AVR-GCC.
- **Hardware Interaction**: GPIO manipulation, timer configuration, and interrupt handling.
  
## Installation & Simulation

1. Open the **Proteus** simulation file (`.pdsprj`) to visualize the project and interact with the components.
2. get the .elf file from debug folder then upload the firmware to the proteus simulation .

## Project Structure
- `src/`: Contains the source code for the stopwatch, including GPIO, timers, and display modules.
- `proteus/`: Includes the Proteus project file for simulation.
- `README.md`: Documentation about the project.

## Acknowledgments
This project was developed as part of the **Embedded Systems Diploma** at **Edges for Training**. Special thanks to **Mohamed Tarek**, our instructor, for his invaluable guidance and support throughout the course.

---

Feel free to explore the code, run the simulation, and improve upon it! 👩‍💻👨‍💻
