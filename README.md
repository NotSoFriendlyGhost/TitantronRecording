# 🎮 VEX Robotics 38535A — Controller Replay System (Over Under)

This repository contains the **controller recording and replay system** developed by **Team 38535A** during the **2023–2024 VEX Robotics Competition: “Over Under.”**  
Built in **PROS**, this system allows autonomous routines to be generated directly from **real driver inputs**, simplifying autonomous development and tuning.

---

## 🏆 About the Game: *“Over Under”*

The **2023–2024 VEX Robotics Competition**, *“Over Under,”* was a **2v2 game** where robots scored **Triballs** (acorn-shaped objects) into goals and could **elevate** at the end of the match.  

This system was developed to make autonomous programming **faster, easier, and more accurate** by leveraging **driver-controlled recordings** instead of manually programming every movement.

---

## ⚙️ Key Features

### 🎥 Input Recording
- Captures **joystick and button inputs** from the VEX V5 Controller in real-time  
- Stores data in structured files for easy retrieval and analysis  

### 🔁 Autonomous Replay
- Replays the exact sequence of recorded inputs during the autonomous period  
- Enables rapid testing and iteration on real match driving paths  

### 🧩 Seamless Integration
- Designed to work with **PROS** and **EZ-Template** frameworks  
- Easily incorporated into existing autonomous selection systems  

### ⚡ Performance Benefits
- Reduces autonomous development time  
- Produces realistic and reliable movement sequences  
- Ideal for recording “driver-inspired” autonomous runs

---

## 🛠️ Tech Stack

| Component | Details |
|------------|----------|
| **Language** | C / C++ |
| **Framework** | [PROS](https://pros.cs.purdue.edu/) |
| **Libraries** | EZ-Template (optional integration) |
| **Hardware** | VEX V5 Controller & Brain |

---

## 🧠 How It Works

1. **Record Mode:**  
   - Activate recording mode through a button on the controller.  
   - The program logs joystick and button values over time.  

2. **Save Data:**  
   - The recorded data is saved to the robot’s SD card or internal storage.  

3. **Replay Mode:**  
   - The robot replays the exact recorded sequence autonomously — no manual coding required!  

