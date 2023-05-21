# Intellibin

![Image of testing Intellibin](https://github.com/Gitmaster511/Intellibin/blob/main/testingimage.png)

Sorry for the mess, we needed to use it for testing

## What is it?

Intellibin is a smart trashcan. It detects trash and automatically opens the flap for which type of trash it is(trash, recycling or Biodegradeble)

### How it works

1. Our Laptop running our AI model picks up the type of trash
2. Then it sends that data to the Arduino through Serial
3. The Arduino runs the motor corresponding to the right type of flap

### What we used

AI: We used a fraemwork called Yolov5(You only look once) for realtime object detection. It opens a OpenCV instance and also boxes around the object.

Arduino: This data is then sent back to the Arduino UNO which uses the motor driver to activate a motor.

### How to use

Clone the repo

```
git clone https://github.com/Gitmaster511/Intellibin
```

Go into the AI repository

```
cd Intellibin/model/yolov5
```

Install the requirements

```
pip3 -r requirements.txt
```

If this doesn't work try this

```
pip -r requirements.txt
```

### How to hook up the arduino

This would take along time to explain so here is a overview

Connect the motor stepper to the motor, the 5V and GND rails and the 4 ports(EN1,EN2,EN3,EN4) to pins 9,10,11,12 on the Arduino UNO

### I can't really help you build the enclosure since it is kind of complicated

(License: Attribution 4.0 International)

[![License: CC BY 4.0](https://img.shields.io/badge/License-CC_BY_4.0-lightgrey.svg)](https://creativecommons.org/licenses/by/4.0/)
