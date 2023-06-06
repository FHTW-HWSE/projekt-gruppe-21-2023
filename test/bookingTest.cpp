#include <catch2/catch.hpp>

SCENARIO("AddBooikngEnttryWithValidParameter")
{
    GIVEN("A User wants to add a Booking-Entry ")
    {

    }    
    WHEN("The parameters are correct")
    {
    
    }
    THEN("The booking will be added to the struct")
    {

    }
}
SCENARIO("AddBookingEnttryWithAnIncorrectDate")
{
    GIVEN("A User wants to add a Booking-Entry on this date")
    {

    }    
    WHEN("The year of the booking under 2020 or the month is bigger than 12 or the day is bigger than 31 or the hour is bigger than 24 or the minute is bigger 60 ")
    {
    
    }
    THEN("The user will get an Error-Warning")
    {

    }
}
SCENARIO("AddBooikngEnttryWithonTheSameTableAtTheSameDate")
{
    GIVEN("A User wants to add a Booking-Entry ")
    {

    }    
    WHEN("The same table is booked on the same date")
    {
    
    }
    THEN("The User gets an ErrorWarning")
    {

    }
}
SCENARIO("AddBookingWithAnNonExistingEntry")
{
    GIVEN("A User wants to add a Booking-Entry ")
    {

    }    
    WHEN("The table doesn't exists")
    {
    
    }
    THEN("The user gets an Error-Warning")
    {

    }
}

