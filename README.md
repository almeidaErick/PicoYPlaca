# PicoYPlaca

This repository have a simple program that predicts "pico y placa" according with the information the user is providing. 
The user will be giving the following data:
  * Car's number plate.
  * The date the user wants to know if the car can be on the road.
  * The time the user wants to know if the car can be on the road according with the last digit of the number plate and the       date.
  
This program can simply be checked on the terminal (MAC or LINUX). 
In order to use the program, the next steps must be followed.

RUNNING THE PROGRAM:
  * First compile the program as followed, "gcc -Wall -o picoyplaca picoyplaca.c".
  * Next, test the program, "./picoyplaca pcb2345 12-12-2018 12:35".
  * The first element (pcb2345) is the number plate, the next element (12-12-2018) is the date the user specifies and the last     parameter (12:35) is the hour. 
  * The date format is: DD-MM-YYYY. The hour format is: HH:MM.
  
Example 1.
  ./picoyplaca pcb2345 12-12-2018 12:35
  
  OUTPUT
  
  ----YOUR CAR CAN BE ON THE ROAD, ENJOY----
  Plate Number: pcb2345
  Date: 12-12-2018
  Day: Wednesday
  Hour: 12:35
  
Example 2.

  ./picoyplaca pcb2341 10-12-2018 9:20
  
  OUTPUT
  
  ----SORRY YOUR CAR CAN NOT BE ON THE ROAD----
  Plate Number: pcb2341
  Date: 10-12-2018
  Day: Monday
  Hour: 9:20
  
  
  
TESTING THE PROGRAM:
  * Download Unity from the link http://www.throwtheswitch.org/unity/, and put the unity directory in the same folder as the       files "picoyplaca.c", "picoyplaca.h" and "programTesting.c" (easiest method).
  * The easiest way to do this is, write "gcc programTesting.c picoyplaca.c ./unity/src/unity.c -o TestExample".
  * If an error is shwon in the terminal (duplicate symbol for architecture x86_64), then simply comment the entire main           function from the file "picoyplaca.c" from the line 20 to 29. Other form to solve this problem is to play with the             compiling flags of the program (which I did not try since I choose the fastest way).
  * Write "./TestExample" and see the output of the tests. 
  * The file "programTesting.c" contains a number of testing situations for the data provided by the user, such as plate           number, date and hour. Many test were failed on purpose just to observe were the error could be and the proper explanation     why is that error presented. 
  
Example 3.

  gcc programTesting.c picoyplaca.c ./unity/src/unity.c -o TestExample
  
  ./TestExample
  
  OUTPUT
  
  Bad format date: 01-12/2018, should be in the format dd-mm-yyyy
  programTesting.c:8:test_CorrectDate:FAIL: Expected 0x01 Was 0x00
  Incorrect hour (HH:MM), please check: 12:85
  programTesting.c:17:test_CorrectHour:FAIL: Expected 0x01 Was 0x00
  The first 3 characters of the plate must be letters, bad format of the vehicle's plate number: P1B2534
  programTesting.c:26:test_CorrectPlateNumber:FAIL: Expected 0x01 Was 0x00

  -----------------------
  3 Tests 3 Failures 0 Ignored 
  FAIL



