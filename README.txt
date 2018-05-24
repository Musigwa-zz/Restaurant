 KeyPad buttons' functions assignment

 1. umugati     200 Rwf
 2. Icyayi      200 Rwf
 3. umureti     1500 Rwf
 4. special     2000 Rwf
 5. ibishyimo   500 Rwf
 6. ifiriti     1000 Rwf
 7. inyama      1500 Rwf
 8. umuceri     500 Rwf
 9. isosi       200 Rwf
 D. cancel the request
 C. confirm / send

 KeyPad connection schema

 KeyPad ====> Arduino
    R1  ====> 5  
    R2  ====> 4
    R3  ====> 3
    R4  ====> A0
    C1  ====> A1
    C2  ====> A2
    C3  ====> A3
    C4  ====> A4

Lcd Dis ====> Arduino
    RS  ====> 13  
    E   ====> 12
    D4  ====> 9
    D5  ====> 8
    D6  ====> 7
    D7  ====> 6

GSM MODULE      Arduino
    RX              10
    TX              11
++++++++++++++++++++++++++++++++++++++++
+                                      +
+   Please read the notes carefully!   +
+                                      +
++++++++++++++++++++++++++++++++++++++++

Please Note that the memory statuses are the following":

The Sketch uses 9540 bytes (29%) of program storage space. Maximum is 32256 bytes.
The Global variables use 1191 bytes (58%) of dynamic memory, 
leaving 857 bytes for local variables. Maximum is 2048 bytes.

So, adding many other things may result the memory leak!.