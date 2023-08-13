# PowerBoard
Bosch 18V Battery-based Power supply for KUKA YouBots

## Folder Overview

- mechanic: Everything related to mounting of batteries and boards -> FreeCAD
- pcb     : all schematics for the PCBs -> KICAD
- software: Software for the teensy 3.2 on the main PCB

## Parts list

Not yet complete!

### Main Power board
- 3x p channel mosfets: 942-IRF5210PBF; https://www.mouser.de/ProductDetail/Infineon-Technologies/IRF5210PBF?qs=9%252BKlkBgLFf3S3YiL4ijtLg%3D%3D (3x2,87€)
- 4x hall sensor: 630-ACHS-7124-000E; https://www.mouser.de/ProductDetail/Broadcom-Avago/ACHS-7124-000E?qs=gZXFycFWdAOkIb94nIF9uA%3D%3D (4x4,73€)
- 3x protection diode: 771-BAT54S-T/R; https://www.mouser.de/ProductDetail/Nexperia/BAT54S215?qs=me8TqzrmIYVOaf3j7zH0Wg%3D%3D (3x0,20€)
- 1x 5V regulator: 511-L7805CV; https://www.mouser.de/ProductDetail/STMicroelectronics/L7805CV?qs=9NrABl3fj%2FqplZAHiYUxWg%3D%3D (1x0,69€)
- 7x XT60: 426-FIT0587; https://www.mouser.de/ProductDetail/DFRobot/FIT0587?qs=w%2Fv1CP2dgqpRvlGrUpUtJQ%3D%3D (7x1,50€)
- 6x 4k7: 603-RC0805JR-134K7L; https://www.mouser.de/ProductDetail/YAGEO/RC0805JR-134K7L?qs=sGAEpiMZZMvdGkrng054t8AJgcdMkx7xyxYshA%252B2bQ0%3D (6x0,10€)
- 4x 680R: 603-RC0805JR-10680RL; https://www.mouser.de/ProductDetail/YAGEO/RC0805JR-10680RL?qs=sGAEpiMZZMvdGkrng054tx7%2F6%252BNA3LAJMcA63kMxTMQ%3D (6x0,11€)
- 4x 1uF: 710-885012107015; https://www.mouser.de/ProductDetail/Wurth-Elektronik/885012107015?qs=sGAEpiMZZMsh%252B1woXyUXj4jKQI6sNRw6g5cI5ATh0rw%3D (4x0,10€)
- 4x 1nF: 80-C0805C102K3RAUTO; https://www.mouser.de/ProductDetail/KEMET/C0805C102K3RACAUTO?qs=MyNHzdoqoQKWoDSELmF8XQ%3D%3D (4x0,09€)
- 3x diode: 637-P2500J; https://www.mouser.de/ProductDetail/Diotec-Semiconductor/P2500J?qs=OlC7AqGiEDnhOnRO%252BjStSw%3D%3D (3x2,45€)
- 4x 2 pole terminal block plug: 490-TBP01P1-508-02BE; https://www.mouser.de/ProductDetail/CUI-Devices/TBP01P1-508-02BE?qs=PzGy0jfpSMuRa64vjc7Npw%3D%3D (4x0,86€)
- 4x 2 pole terminal block PCB socket: 490-TBP01R2-508-02BE; https://www.mouser.de/ProductDetail/CUI-Devices/TBP01R2-508-02BE?qs=PzGy0jfpSMtI214KtO%2FmIg%3D%3D (4x0,51€)
- 1x 7 pole terminal block socket: 490-TBP01R2-508-07BE; https://www.mouser.de/ProductDetail/CUI-Devices/TBP01R2-508-07BE?qs=PzGy0jfpSMv8M4EGbXc3CQ%3D%3D (1x1,00€)
- 1x 7 pole terminal block plug: 490-TBP01P1-508-07BE; https://www.mouser.de/ProductDetail/CUI-Devices/TBP01P1-508-07BE?qs=PzGy0jfpSMv0m1paAwlB0Q%3D%3D (1x1,94€)


- price: 45€ / PCB

### 24V Board Emergency Off
- 2x p channel mosfets: 942-IRF5210PBF; https://www.mouser.de/ProductDetail/Infineon-Technologies/IRF5210PBF?qs=9%252BKlkBgLFf3S3YiL4ijtLg%3D%3D (2x2,87€)
- 3x XT60: 426-FIT0587; https://www.mouser.de/ProductDetail/DFRobot/FIT0587?qs=w%2Fv1CP2dgqpRvlGrUpUtJQ%3D%3D (3x1,50€)
- 3x 4k7: 603-RC0805JR-134K7L; https://www.mouser.de/ProductDetail/YAGEO/RC0805JR-134K7L?qs=sGAEpiMZZMvdGkrng054t8AJgcdMkx7xyxYshA%252B2bQ0%3D (3x0,10€)
- 1x terminal block plug: 490-TBP01P1-508-02BE; https://www.mouser.de/ProductDetail/CUI-Devices/TBP01P1-508-02BE?qs=PzGy0jfpSMuRa64vjc7Npw%3D%3D (1x0,86€)
- 1x terminal block PCB socket: 490-TBP01R2-508-02BE; https://www.mouser.de/ProductDetail/CUI-Devices/TBP01R2-508-02BE?qs=PzGy0jfpSMtI214KtO%2FmIg%3D%3D (1x0,51€)

- price: 7,41€ / PCB

## 15V Power Supply for NUC

- see exported BOM
- 1x 3 pole terminal socket: https://www.mouser.de/ProductDetail/CUI-Devices/TBP01R2-508-03BE?qs=PzGy0jfpSMvsLipzvwxOIA%3D%3D (1x0,60€)
- 1x 3 pole terminal plug: https://www.mouser.de/ProductDetail/CUI-Devices/TBP01P1-508-03BE?qs=PzGy0jfpSMsyMkSLNya%2Fkw%3D%3D (1x1,06€)
