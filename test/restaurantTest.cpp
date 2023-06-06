#include <catch2/catch.hpp>
#include "../include/restaurant.h"
#define maxTables 10

struct Restaurant
      {
        float length;
        float width;
        struct Table tables[maxTables];
        int numTables;
      };
struct Table 
  {
    int tableNumber;
    float length;
    float width;
  };
SCENARIO("CreatingRestaurantWithPositiveParameter")
{
    GIVEN("A User sets the size of the restaurant")
    {
      struct Restaurant restaurant;
      restaurant.length=2;
      restaurant.width=3;
      displayRestaurantSize(restaurant)
    }    
    WHEN("The parameters are correct")
    {

    }
    THEN("The size of the restaurant is created")
    {
      REQUIRE()
    }
}
SCENARIO("CreatingRestaurantWithNegativeCoordinates")
{
   GIVEN("A User sets the size of the restaurant")
    {
      
      restaurant.length=2;
      restaurant.width=-3;
    }
    WHEN("The parameters are negative.")
    {
      

    }
    THEN("A Errorwarning will be sent.")
    {
      
    }
}
SCENARIO("CreateATableInTheRestaurant")
{
  GIVEN("User wants create a Table")
  {
    struct Restaurant restaurant;
    
  }
  WHEN("Table is in the restaurant")
  {

  }
  THEN("A table is created in the restaurant")
  {

  }
}
SCENARIO("CreateTableOutsideOfTheRestaurantWithNegativeParamter")
{
 GIVEN("User wants create a Table")
  {

  }
  WHEN("Table is outside of the restaurant")
  {

  }
  THEN("User gets an Error-Message")
  {

  } 
}

SCENARIO("CreateTableOnAnExistingTable")
{
  GIVEN("User wants create a Table")
  {

  }
  WHEN("There is already a table")
  {

  }
  THEN("User gets an Error-Message")
  {

  } 
}
SCENARIO("CreateTableOutsideOfTheRestaurantWithPostiveParamter")
{
 GIVEN("User wants create a Table")
  {

  }
  WHEN("Table is outside of the restaurant")
  {

  }
  THEN("User gets an Error-Message")
  {

  } 
}