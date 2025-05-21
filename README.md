# NN-01
IR bridge based on attiny-85
</br>
</br>
<img style="width: 500px;" src="./3Drender.png">
</br>

## Description 
Imagine having different IR devices (e.g. a TV and an Home theater hoked to it) each of them controlled by its own remote. This device allows you to control both of them with the same remote.
It can be field programmed (according to the flow diagram below) to emit a specific IR commad whenever a source IR command is recived, this can be useful to automate some scenarios (like turnig on the home theatre whenever the tv is turned on or controlling the volume from the TV remote).
This is expecially usefull when a generic universal remote cannot be used (modern smart TVs come with remotes which have oddly specific buttons for menus and so on...)
<img style="width: 500px;" src="./manual.png">
</br>
Repo provides the firmware (compatible with attiny 84, to be compiled with attinyCore), schematic and PCB layouts
</br>

### Partlist
1x 100uF - 16v electrolitic capacitor <a>> </br>
2x 0.1uF - ceramic capacitor </br>
1x GTC usb-c recepticle  <a href="https://www.digikey.it/it/products/detail/gct/USB4085-GF-A/9859662">available here </a> </br>
1x Atmel attiny 84 <a href="https://www.digikey.it/it/products/detail/microchip-technology/ATTINY85-20PU/735469">available here </a> </br> 
1x 1838 ir receiver </br>
1x 940/850 nm ir LED (at least 60°) <a href="https://www.digikey.it/it/products/detail/vishay-semiconductor-opto-division/TSAL7600/1681341">available here </a> </br>
1x red or visible LED  </br>
1x 330 ohm Resistor   </br>
1x 10k ohm Resistor   </br>
1x 220 ohm Resistor   </br>
