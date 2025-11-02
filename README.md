![keenoardCaseV3](images/keenoardCaseV3.jpg)

# KeeNoard

**KeeNoard**(name intended typo between B and N) is 38-key split keyboard with rotary encoder and multiple center key, with only one rp2040 zero board.

Inspired and learned many thing from the former great [Cheapino](https://github.com/tompi/cheapino), KeeNoard uses only one board and [Japanese duplex matrix](https://kbd.news/The-Japanese-duplex-matrix-1391.html), and controlled ghosting with three PNP transistor and active-high matrix.

Default keymap uses customized [Miryoku](https://github.com/manna-harbour/miryoku) - with slight different mouse and navigator keys. Two center keys are mapped to left Y and right B, which are originally intended.



## Preparation

- 1x rp2040 zero (boards formly created by waveshare)

- 2x KeeNoard PCB Boards

- 1x printed case sets, which you want to make it

- 6x TO-18 PNP transistors, or 6x SOT-23 PNP transistors.

- 50x diodes

- 2x EC11 encoders and cap

- 14x M2x6 screws, flathead

- 1x RJ45 cable

- 2x RJ45 connector, in 18mm



## Build Guides

work in progress. sorry!

You can see the images in the folder, which uploaded for build guides. Especially you may see how to solder the controller board, because this uses surface mounting by castelated pins.

Images are captured with prototype version PCB, which is different from the current gerber. current gerber has SMD transistor soldering pads on the protype's label position, and is more easy to solder controller board with larger soldering pads.

This uses [qmk](https://qmk.fm/) to build the firmware. Copy "keenoard" folder which is in "firmware" directory to "qmk_firmware\keyboards" folder, and build it via qmk msys.

Or, simply flash uf2 in "uf2Examples" folder by changing rp2040 zero in dfu mode, which can be executed by holding boot button while plugging in usb c.

Also, I'm working on the vial version.



## Licenses

matrix.c and other qmk-related things follows GNU GPL license.

other codes follows MIT license.

all designs and the hardware board follows CC BY-SA 4.0 license.

If you want to make a commercial product, it would be appreciated [if you sponsor some bucks for me.](https://github.com/sponsors/yuburoll)
