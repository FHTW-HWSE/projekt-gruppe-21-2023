#include <catch2/catch.hpp>
#include "../include/restaurant.h"
#define maxTables 10

struct Restaurant restaurant;
SCENARIO("CreatingRestaurantWithPositiveParameter")
{
    GIVEN("A User sets the size of the restaurant")
    {
      restaurant.length=2;
      restaurant.width=3;      
    }    
    WHEN("The parameters are correct")
    {
      if()
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
    struct Table table;
    struct Restaurant restaurant;
    restaurant.length=2;
    restaurant.width=4;
    WHEN("Table is in the restaurant")
    {
    int checker=addTable(*restaurant,2,2);
    THEN("A table is created in the restaurant")
     {
      REQUIRE(checker == 1);
     }
    }
  }
  
  
}
SCENARIO("CreateTableOutsideOfTheRestaurantWithNegativeParamter")
{
 GIVEN("User wants create a Table")
  {
    struct Table table;
    struct Restaurant restaurant;
    restaurant.length=2;
    restaurant.width=4;
   WHEN("Table is outside of the restaurant")
   {
    int checker=addTable(*restaurant,3,-5); 
     THEN("User gets an Error-Message")
     {
       REQUIRE(checker==0);
     }
   }
  }
  
  
}

SCENARIO("CreateTableOnAnExistingTable")
{
  GIVEN("User wants create a Table")
  {
    struct Table table;
    struct Restaurant restaurant;
    restaurant.length=2;
    restaurant.width=4;
       
   WHEN("There is already a table")
   {
    int checker=addTable(*restaurant,2,3);
     THEN("User gets an Error-Message")
     {
      REQUIRE(checker==1);
     } 
   }
  }
}
SCENARIO("CreateTableOutsideOfTheRestaurantWithPostiveParamter")
{
 GIVEN("User wants create a Table")
  {
    struct Table table;
    struct Restaurant restaurant;
    restaurant.length=2;
    restaurant.width=4;
    WHEN("Table is outside of the restaurant")
    {
     int checker=addTable(*restaurant,10,34);
     THEN("User gets an Error-Message")
      {
        REQUIRE(checker==0);
      } 
    }
  }
  
  
}