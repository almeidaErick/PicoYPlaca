#include "unity/src/unity.h"
#include "picoyplaca.h"

vehicle new_car; //Start a new object

void test_CorrectDate(void) {
    TEST_ASSERT_EQUAL_HEX8(1, get_day_index("01-12-2018", &new_car)); //PASS
    TEST_ASSERT_EQUAL_HEX8(1, get_day_index("01-12/2018", &new_car)); //FAIL FORMAT DD-MM-YYYY
    TEST_ASSERT_EQUAL_HEX8(0, get_day_index("01-13-2018", &new_car)); //PASS, format of the date is incorrect no month number 13
    TEST_ASSERT_EQUAL_HEX8(0, get_day_index("32-12-2018", &new_car)); //PASS, format of the date is incorrect no day number can be greater than 31
    TEST_ASSERT_EQUAL_HEX8(1, get_day_index("31-12-201", &new_car)); //FAIL, year number must be greater than 1900.
    TEST_ASSERT_EQUAL_HEX8(1, get_day_index("1-1-2017", &new_car)); //PASS, is not neccesary to add presceding 0
}

void test_CorrectHour(void) {
    TEST_ASSERT_EQUAL_HEX8(1, check_time("12:45", &new_car)); //PASS
    TEST_ASSERT_EQUAL_HEX8(1, check_time("12:85", &new_car)); //FAIL, minutes can be between 0 and 59
    TEST_ASSERT_EQUAL_HEX8(1, check_time("25:45", &new_car)); //FAIL, hours can be between 0 and 23
    TEST_ASSERT_EQUAL_HEX8(0, check_time("12/45", &new_car)); //PASS, format is incorrect, should be HH:MM.
}

void test_CorrectPlateNumber(void) {
    TEST_ASSERT_EQUAL_HEX8(1, check_licence_plate("PCB2534", &new_car)); //PASS
    TEST_ASSERT_EQUAL_HEX8(1, check_licence_plate("pcB2534", &new_car)); //PASS, uper and lower case are permitted in the program
    TEST_ASSERT_EQUAL_HEX8(1, check_licence_plate("PCB253", &new_car)); //PASS, number plates can have 6 or 7 characters long.
    TEST_ASSERT_EQUAL_HEX8(1, check_licence_plate("P1B2534", &new_car)); //FAIL, the first 3 character of the plate must be upper or lower case letters.
    TEST_ASSERT_EQUAL_HEX8(0, check_licence_plate("PCB25342", &new_car)); //PASS, the length of the number plate can be only 6 or 7 characters long.
    TEST_ASSERT_EQUAL_HEX8(1, check_licence_plate("PCB253l", &new_car)); //FAIL, the last 3 or 4 characters of the number plate must be numbers.
    TEST_ASSERT_EQUAL_HEX8(1, check_licence_plate("PCB25", &new_car)); //FAIL, the length of the number plate can be only 6 or 7 characters long.
}

int main (void) {
    start_vehicle(&new_car); //Start parameters for the new object.
    
    UNITY_BEGIN();
    RUN_TEST(test_CorrectDate);
    RUN_TEST(test_CorrectHour);
    RUN_TEST(test_CorrectPlateNumber);
    return UNITY_END();
}
