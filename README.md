# Arkanoid Game with Accelerometer-Based Paddle Control (STM32 + Qt)

## Project Overview

This project is a modern interpretation of the classic **Arkanoid** game. The game is developed using **C++ and the Qt framework**, and is enhanced with an interactive control method using an **STM32L476 microcontroller board** equipped with an **accelerometer**. The game paddle is moved not by a keyboard or mouse, but by tilting the STM32 board. This approach improves immersion and creates a unique connection between the player and the game.

---

## Key Features

- **Paddle control via accelerometer**: Tilting the STM32 board left or right moves the paddle accordingly. Greater tilt results in faster paddle movement.
- **Graphical interface in Qt**: Includes multiple views such as:
  - Main menu (language and difficulty selection)
  - Gameplay window
  - Pause screen
  - Chart view for accelerometer data
- **Realistic physics**: Ball bouncing and interactions follow basic physics rules.
- **Menu system**: Allows selection of language and difficulty level.
- **Multi-language support**: Full dynamic translation into **English**, **Polish**, and **Russian**.
- **Live accelerometer data visualization**: Dedicated chart window to view and switch between X, Y, Z axes in real time.
- **Custom communication protocol**: Data from STM32 is sent via UART to the PC and validated using a checksum (CRC16).

---

## How It Works

1. The STM32 board reads real-time accelerometer data (X, Y, Z axes).
2. Data is sent to the Qt application over UART, using a custom communication protocol.
3. The Qt application uses this data to move the game paddle horizontally (and vertically in defined ranges).
4. The game logic handles ball movement, collisions, and level progression.
5. Charts visualize accelerometer data live.
6. The menu enables selecting the serial port, difficulty level, and language.

---

## Hardware Requirements

- STM32L476 Nucleo or Discovery Board
- Accelerometer module (e.g., built-in LSM6DS3 or external like MPU6050)
- USB cable for power and serial communication

---

## Software Requirements

- **Qt 6** or later (Widgets module)
- **QSerialPort / QSerialPortInfo** for serial communication
- **STM32CubeIDE** or **PlatformIO** for STM32 firmware development

---
