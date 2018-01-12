#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "picoyplaca.h"


//Tables
char days[7][10] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};



int main (int argc, char *argv[]) {
    vehicle new_car; //Start a new object
    start_vehicle(&new_car); //Start parameters for the new object.
    if((check_licence_plate(argv[1], &new_car) == 1) &&
       (get_day_index(argv[2], &new_car) == 1) &&
       (check_time(argv[3], &new_car) == 1)) {
        car_allowed(&new_car); //Check if the car is allowed to be on the road.
    }
    
}


/*
 This function starts a new object (vehicle struct).
 
 Input:
    - newCar: car struct that contains the neccesary information of the car.
 Output:
    - No output in void function type.
 
 Error:
    - No error detected here, just initialize the object.
 
 Note:
    - This function was made if more features of the object need to be added. In here
      the proper amount of memory for each parameter of the object can be given.
 */
void start_vehicle(vehicle* newCar) {
    struct tm get_date;
    memset((void *) &get_date, 0, sizeof(get_date));
    newCar->date_time = get_date;
}


/*
 This function checks when the vehicle can be on the road according to the day,
 the last character of the plate's number and the time specified by the user.
 This function prints the plate number, the date, day and hour according to the
 information provided by the user.
 
 Input:
    - newCar: car struct that contains the neccesary information of the car.
 Output:
    - No output in void function type.
 
 Error:
    - The errors for the specific parameters have been checked on the previous
      functions.
 */
void car_allowed(vehicle* newCar) {
    switch(newCar->plate_number[strlen(newCar->plate_number) - 1]) {
        case '1':
        case '2':
            // Check plate number for Monday
            if((newCar->day_index == 1) && (newCar->car_time == 0)) {
                printf("----SORRY YOUR CAR CAN NOT BE ON THE ROAD----\n");
            } else {
                printf("----YOUR CAR CAN BE ON THE ROAD, ENJOY----\n\r");
            }
            break;
        
        case '3':
        case '4':
            // Check plate number for Tuesday
            if((newCar->day_index == 2) && (newCar->car_time == 0)) {
                printf("----SORRY YOUR CAR CAN NOT BE ON THE ROAD----\n");
            } else {
                printf("----YOUR CAR CAN BE ON THE ROAD, ENJOY----\n\r");
            }
            break;
        
        case '5':
        case '6':
            // Check plate number for Wednesday
            if((newCar->day_index == 3) && (newCar->car_time == 0)) {
                printf("----SORRY YOUR CAR CAN NOT BE ON THE ROAD----\n");
            } else {
                printf("----YOUR CAR CAN BE ON THE ROAD, ENJOY----\n\r");
            }
            break;
        
        case '7':
        case '8':
            // Check plate number for Thursday
            if((newCar->day_index == 4) && (newCar->car_time == 0)) {
                printf("----SORRY YOUR CAR CAN NOT BE ON THE ROAD----\n");
            } else {
                printf("----YOUR CAR CAN BE ON THE ROAD, ENJOY----\n\r");
            }
            break;
        
        case '9':
        case '0':
            // Check plate number for Friday
            if((newCar->day_index == 5) && (newCar->car_time == 0)) {
                printf("----SORRY YOUR CAR CAN NOT BE ON THE ROAD----\n");
            } else {
                printf("----YOUR CAR CAN BE ON THE ROAD, ENJOY----\n\r");
            }
            break;
    }
    //Print the parameters provided by the user.
    printf("Plate Number: %s\n\r", newCar->plate_number);
    printf("Date: %d-%d-%d\n", newCar->date_time.tm_mday, newCar->date_time.tm_mon+1,
           newCar->date_time.tm_year+1900);
    printf("Day: %s\n", days[newCar->day_index]);
    printf("Hour: %d:%d\n", newCar->date_time.tm_hour, newCar->date_time.tm_min);
}

/*
 This function takes a date as string and set a number from 0 to 6 that respresents
 the day of the week (this number represents the index from table provided
 called "days") to the object newCar. The function exit the program if an error is
 detected, and the proper message is displayed. Format for the date is DD-MM-YYYY.
 
 Input:
    - date_str: date as string provided as input argv to the program.
    - newCar: car struct that contains the neccesary information of the car.
 Output:
    - 1 if succesful time operation, 0 otherwise.
 
 Error:
    - If the format of the date is not dd-mm-yyy, the function will show a message
      and will exit the program. Not neccesary to check for more errors and rise
      exceptions since the function mktime will return a -1 for every error encountered,
      and the proper format is specified on the displayed message.
 */
int get_day_index(char * date_str, vehicle* newCar) {
    if(strptime(date_str, "%d-%m-%Y", &newCar->date_time) != NULL) {
        time_t t = mktime(&newCar->date_time);
        if (t >= 0) {
            newCar->day_index = localtime(&t)->tm_wday; // Sunday=0, Monday=1, etc.
            return 1;
        }
    }
    printf("Bad format date: %s, should be in the format dd-mm-yyyy\n\r", date_str);
    //exit(0);// exit the program at this point}
    return 0;
}


/*
 This function checks if the time is correct, if so add the proper parameters to the
 object newCar. Format for the time is HH:MM.
 
 Input:
    - time_str: time as string provided as input argv to the program.
    - newCar: car struct that contains the neccesary information of the car.
 
 Output:
    - 1 if succesful time operation, 0 otherwise.
 
 Error:
    - if the function strptime detects an error in time, the program stops. The function
      strptime checks if the correct format is given, and the correct limits for hour
      and minutes are in the proper range (hours: 0-23, minutes: 0-59).
 */
int check_time(char* time_str, vehicle* newCar) {
    if (strptime(time_str, "%H:%M", &newCar->date_time) != NULL) {
        // Check morning restriction for PICO Y PLACA
        if((newCar->date_time.tm_hour <= 9) &&
           (newCar->date_time.tm_hour >= 7)) {
            if((newCar->date_time.tm_min > 30) &&
               (newCar->date_time.tm_hour == 9)){
                newCar->car_time = 1;
            } else {
                newCar->car_time = 0;
            }
        // Check afternoon restrictions for PICO y PLACA
        } else if ((newCar->date_time.tm_hour <= 19) &&
                   (newCar->date_time.tm_hour >= 16)) {
            if((newCar->date_time.tm_min > 30) &&
               (newCar->date_time.tm_hour == 19)){
                newCar->car_time = 1;
            } else {
                newCar->car_time = 0;
            }
        } else {
            newCar->car_time = 1;
        }
        return 1;
    }
    printf("Incorrect hour (HH:MM), please check: %s\n\r", time_str);
    //exit(0); // exit the program at this point
    return 0;
}



/*
 This function check the plate number of the vehicle. It checks for the correct number
 of characters on the plate which are 6 or 7 characters, additionally it checks if
 the 3 first characters are letters, and the next 3 or 4 characters are numbers.
 
 Input:
    - plate: the plate number specified by the user.
    - newCar: car struct that contains the neccesary information of the car.
 
 Output:
    - 1 if succesful number plate operation, 0 otherwise.
 
 Error:
    - If the number of characters are incorrect, the function send the proper message
      and exit the program.
    - If the 3 first characters are not letters (UPPER or LOWER CASE), the proper
      message is displayed, the same happens with the next 3 or 4 characters that must
      be numbers.
 */
int check_licence_plate(char* plate, vehicle* newCar) {
    int plate_length = strlen(plate);
    // Check length of the plate number, if not correct send proper message
    if((plate_length >= 6) && (plate_length <= 7)) {
        for(int i = 0; i < 3; i++) {
            //Check if the first 3 characters are letters.
            if(!(((plate[i] >= 'A') && (plate[i] <= 'Z')) || ((plate[i] >= 'a') && (plate[i] <= 'z')))) {
                printf("The first 3 characters of the plate must be letters, bad format of the vehicle's plate number: %s\n\r", plate);
                //exit(0);
                return 0;
            }
        }
        for(int i = 3; i < plate_length; i++) {
            // Check fot the last characters of the plate to be only numbers.
            if((plate[i] < '0') || (plate[i] > '9')) {
                printf("The last 3 or 4 characters of the plate must be numbers, bad format of the vehicle's plate number: %s\n\r", plate);
                //exit(0);
                return 0;
            }
        }
        newCar->plate_number = plate;
        return 1;
    }
    else {
        printf("Incorrect number of characters in the plate: %s\n\r", plate);
        //exit(0); // exit the program at this point
        return 0;
    }
}



