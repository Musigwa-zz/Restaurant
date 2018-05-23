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
    R1  ====> A0  
    R2  ====> A1
    R3  ====> A2
    R4  ====> A3
    C1  ====> A4
    C2  ====> A5
    C3  ====> 02
    C4  ====> 03

Lcd Dis ====> Arduino
    RS  ====> 11  
    E   ====> 08
    D4  ====> 04
    D5  ====> 05
    D6  ====> 06
    D7  ====> 07

GSM MODULE      Arduino
    RX              10
    TX              12
    RST             13
++++++++++++++++++++++++++++++++++++++++
+                                      +
+   Please read the notes carefully!   +
+                                      +
++++++++++++++++++++++++++++++++++++++++

Note that this GSM library that we are using supports (Sim800L and Sim800H only)!.
I have modified some codes in the Library and attached its folder containing the 
changes, make sure to use the library attached to this project instead of installing
it externally.

Please Note that the memory statuses are the following":

Sketch uses 10062 bytes (31%) of program storage space. Maximum is 32256 bytes.
Global variables use 1364 bytes (66%) of dynamic memory, 
leaving 684 bytes for local variables. Maximum is 2048 bytes.

So, adding many other things may result the memory leak!. Thanks and waiting for your feedbacks.