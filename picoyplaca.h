#ifndef PICOYPLACA_H_
#define PICOYPLACA_H_

#include <time.h>

//Struct
typedef struct Vehicle_id {
    struct tm date_time;
    char* plate_number;
    int day_index;
    char car_time;
}vehicle;


//Functions
int get_day_index(char * date_str, vehicle* newCar);
int check_licence_plate(char* plate, vehicle* newCar);
int check_time(char* time_str, vehicle* newCar);
void start_vehicle(vehicle* newCar);
void car_allowed(vehicle* newCar);


#endif /* PICOYPLACA_H */
