# 5/1/2026 - Designing PCB

**Time spent: 4.5h**

# PCB Design

![Screenshot 2026-05-01 at 11.12.21 am](https://stasis.hackclub-assets.com/images/1777597944279-vqcco8.png)

## Schematic

I first started with the schematic, for the schamitic i decided to follow the Hackpad guide for the switches and the microcontroller but i decided to add my own twist which was the screen. The screenis an adafruit oled display with screw mounting holes for mounting onto the pcb. The schamtic also included the seeeduino board used in the hackpad guide.

I had to do the schematic twice because for the first time i didnt properly connect the parts together in the schema so in the PCB editor when i was routing the routes werent conecting.

![Screenshot 2026-05-01 at 11.17.40 am](https://stasis.hackclub-assets.com/images/1777598264319-7dh9fj.png)

*The wiring of the schematic was a bit messy because of the layout i used*

## PCB editor

Within the PCB editor is where i designed the main PCB, it took me a while to figure out that i had to assign footprints to the components in the schematic editor. I then placed all of the components in a desirable layout for the macropad making it simple and good looking fr the macropad. I realised the gap was quite significant when designing in fusion however I was able to fix this after the fact.

The routing was the most significantly difficult part in my opinion it took me multiple attemps and a bunch of tries after deleting multiple routes because the pthers didnt fit and then, i finally found a layout that would work, but in the DRC it said that my components werent connected so i check back and realised all my routes were in the top layer of my PCB and not connecting to the microcontroller on the bottom layer, so i had to undo everything and restart from the bottom layer. I realised i could interconnect the ground pins to simplify the layout and reduce the overall wires going to the microcontroller.

![Screenshot 2026-05-01 at 11.19.10 am](https://stasis.hackclub-assets.com/images/1777598357447-p5otyy.png)

After a while of trial and error i eventually figured it out and was able to properly route everything and the DRC showed a fully working PCB, i also learnt about the layers which instructed me to build the pcb frame on the edge cuts layer.

---

# 5/1/2026 - CAD design

**Time spent: 2.25h**

I designed the PCb case in fsion 360

My inspiration for this macro pad was the printed pad by prota design but i wanted to make something smaller and cheaper than both of their offering the printed pad and glyff.

## Step 1

I first exported the step file of my PC into fusion by exporting out of KIcad, here i encountered some errors explained in the previous journal entry where my routing want correct and the DRC wasnt approving my project to be exported due to those errors. Eventually i figured it out and exported it as a step file into fusion 360 where i opened a hybrid design file.

## Step 2

![Screenshot 2026-05-01 at 11.39.16 am](https://stasis.hackclub-assets.com/images/1777599562161-lb75ji.png)

After importing everything into fusion i started the creation of my case for the macro pad pcb. So far i have the PCb layed in the frame with switches layed on top. The switches are cherry mx red switches which provide a satisfying clicking experience had smooth travel. I placed the switches onto the PCB and they fit perfectly.

## Whats left

I still have to make a cutout for the microcontroller mounted on the bottom and another cutout for the USB-C cord which provides power and signal to the macro pad.

I also have to design the top shell of the case similar to the prota design case.

---

# 5/1/2026 - More fusion - Designing lid and adding keycaps

**Time spent: 1.166666666666667h**

In the previous journal entry i said that i would complete the Lid and add the USb charging port and thats what i did.

I designed the lid simply by just creating a sketch on top of the base and creating a 2mm offset for a sturdy but light feel. The holes for the keyswitches have decent clearance for the kycaps to go beneath the top layer for full travel. Cherry mx switches can detect travel amount so i plan to use this in firmware.

![Screenshot 2026-05-01 at 12.41.59 pm](https://stasis.hackclub-assets.com/images/1777608657028-bmfeo3.png)

---

# 5/1/2026 - I developed the code and editing software for the macropad

**Time spent: 3.5h**

I coded the app for editing the macro pad there are multiple otptions for holding, double clicking and single pressing, there are also sliders to update these settings.

## OLED screen modes

- Laptop battery percentage
- Volume level
- WiFi strength
- CPU temperature
- Custom text
- Uploaded images
- A virtual pet

## Web configurater coding

I used CSS for the styles, JS and HTML.

The configurator includes a live preview of the OLED inside the SVG macropad.

![Screenshot 2026-05-01 at 2.20.29 pm](https://stasis.hackclub-assets.com/images/1777609231818-z7pnq7.png)
