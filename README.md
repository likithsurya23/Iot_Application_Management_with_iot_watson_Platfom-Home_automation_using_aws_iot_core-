# Iot_Application_Management_with_iot_watson_Platfom (Ultimate Home Automation with ESP32 and AWS IoT Core)

## Overview

This project is based on **IoT Application Development** using **IBM Watson IoT Platform**. However, due to issues encountered during the IBM Cloud account creation process, and the lack of resolution from the company's support platform, we were unable to proceed with IBM Cloud. As a result, based on the recommendation of one of our internship trainers, we opted to use **AWS IoT Core** as an alternative for IoT device management.

This project demonstrates how to control a light bulb remotely using an **ESP32 board** and **AWS IoT Core**. By setting up a secure connection between the ESP32 and AWS, users can send MQTT messages to turn the light on and off from anywhere.

## Components Required

- ESP32 Board
- Relay Module
- Light Bulb
- Connecting Wires
- Power Supply

## Circuit Connection

1. Connect one end of the bulb to a two-pin connector.
2. Connect the other end of the bulb and the other end of the two-pin connector to the relay.
3. Complete the relay connections as per the circuit diagram.

## AWS IoT Core Setup

1. **Login to AWS:**
   - Search for **AWS IoT Core** on Google and sign in to the AWS console.
   - Select **Root User**, enter credentials, and sign in.
2. **Create an IoT Thing:**
   - Navigate to **AWS IoT Core > All Devices > Things**.
   - Click **Create Thing** and enter a name (e.g., `Home Automation`).
   - Select **No Shadow** and proceed.
3. **Generate Security Certificates:**
   - Select **Auto-generate certificates** (Recommended).
   - Download the following files:
     - Device Certificate
     - Public Key
     - Private Key
     - Amazon Root CA Certificate

## Creating a Policy

1. Click **Create Policy** and enter a name (e.g., `Automation Uncore Policy`).
2. Set permissions:
   - Allow **iot**\*\*:connect\*\*
   - Allow **iot**\*\*:receive\*\*
   - Allow **iot**\*\*:subscribe\*\*
3. Save and attach the policy to the IoT Thing.

## Programming the ESP32

1. **Install Required Libraries:**
   - Wi-Fi Client Secure Library
   - Publish Subscribe Client Library
   - Download and extract them into the `Arduino/libraries` folder.
2. **Configure Secrets File:**
   - Enter **Wi-Fi credentials**, **AWS endpoint**, and **security certificates**.
3. **Upload Code to ESP32:**
   - Open Arduino IDE.
   - Select **ESP32 Dev Module** as the board.
   - Choose the correct port and upload the code.

## Testing the System

1. Open **AWS IoT Core > MQTT Test Client**.
2. Publish a message to the topic (e.g., `esp32/light1`):
   - Send `1` to turn the light **ON**.
   - Send `0` to turn the light **OFF**.
3. Verify the output using the **Serial Monitor** in Arduino IDE.

## Expected Output

- When `1` is published, the light turns **ON**.
- When `0` is published, the light turns **OFF**.
- Status updates can be viewed in the **AWS MQTT test client** and **Serial Monitor**.

## Conclusion

This project successfully demonstrates the integration of **ESP32** with **AWS IoT Core** to enable remote control of household appliances. By leveraging **MQTT protocol** and cloud-based IoT management, users can efficiently automate and monitor devices from anywhere in the world.
This implementation showcases the potential of **home automation**, where smart appliances can be controlled securely and efficiently using cloud platforms. Future improvements could include **integration with voice assistants**, **real-time energy monitoring**, and **mobile app control** to enhance user experience and expand automation capabilities.
By adopting **cloud-based IoT solutions**, this project highlights how **smart homes** can become more accessible, energy-efficient, and secure, paving the way for future advancements in IoT and automation technology.



