# Line-following-robot
It is an autonomous robot that follows a path made with black line on white surface
The robot uses an ESP32, a QTR-8RC sensor array, a TB6612FNG motor driver, and two geared DC motors.
<img width="729" height="631" alt="Screenshot 2026-11-09 at 11 38 56 PM" src="https://github.com/user-attachments/assets/5f4830cc-84c2-4d76-a548-9f7dfbde6190" />

Features:
Follows a black line
Uses the QTR-8A sensor array to detect the line and determine its position.
Uses the NodeMCU-38 ESP32 as the main controller to process sensor data and control movement.
Uses two N20 geared DC motors to move forward and turn by adjusting the speed of each wheel.
Provides independent control of the left and right motors.
Uses two 18650 lithium-ion cells housed in a dual-cell battery case.

Hardware:
NodeMCU-38 (ESP32)
QTR-8A IR Sensor Array
TB6612FNG Motor Driver
N20 12GA DC Geared Motors (×2)
18650 Battery Case (2-cell)
18650 Lithium-ion Battery Cells (×2)
Custom T-Shaped Chassis
Robot Wheels (×2)
Custom Motor Mounting Brackets (×2)
Mounting Screws and Nuts
Jumper Wires

Circuit Diagram:
<img width="1333" height="662" alt="Screenshot 2026-11-09 at 11 47 06 PM" src="https://github.com/user-attachments/assets/f53e34eb-592d-41b7-8924-90e6dba5acee" />

CAD modelling:
Main chassis:
<img width="1470" height="956" alt="Screenshot 2026-11-09 at 10 11 13 PM" src="https://github.com/user-attachments/assets/719d6560-d82a-4eac-ac4b-cc1147934bb0" />

Bracket for motor:
<img width="1470" height="956" alt="Screenshot 2026-11-09 at 10 11 02 PM" src="https://github.com/user-attachments/assets/fc484d4f-27aa-4f51-b1d2-505109a8b42b" />

Assembly:
<img width="1470" height="956" alt="Screenshot 2026-11-09 at 9 54 35 PM" src="https://github.com/user-attachments/assets/bea1823c-84af-41ae-a1d0-e2fd81bf1c2a" />



