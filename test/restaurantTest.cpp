#define CATCH_CONFIG_MAIN 
#include <catch2/catch.hpp>
#include "../include/restaurant.h"
#include "../include/structhandeling.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxTables 10

SCENARIO("addTable")
{
  GIVEN("AddTable")
  {

    struct Restaurant restaurant;
    restaurant.length=2;
    restaurant.width=4;
    WHEN("length and width =>0 ")
    {
    int checker=addTable(&restaurant,2,2);
    THEN("checker==1")
     {
      REQUIRE(checker == 1);
     }
    }
  }
  
  
}
SCENARIO("addTableWithNegatives")
{
 GIVEN("addTable")
  {
    struct Restaurant restaurant;
    restaurant.length=2;
    restaurant.width=4;
   WHEN("table X || Y < 0 ")
   {
    int checker=addTable(&restaurant,3,-5); 
     THEN("checker==1")
     {
       REQUIRE(checker==1);
     }
   }
  }
  
  
}

SCENARIO("TableOnTheSamePostion")
{
  GIVEN("AddsATable")
  {
    struct Restaurant restaurant;
    restaurant.length=2;
    restaurant.width=4;
       
   WHEN("CoordinatesOfTableAreSame")
   {
    int checker=addTable(&restaurant,2,3);
     THEN("checker==1")
     {
      REQUIRE(checker==1);
     } 
   }
  }
}
SCENARIO("TableOutsideRestaurant")
{
 GIVEN("addTable")
  {
    struct Restaurant restaurant;
    restaurant.length=2;
    restaurant.width=4;
    WHEN("table.x>restaurant.length || table.y >restaurant.width")
    {
     int checker=addTable(&restaurant,10,34);
     THEN("User gets an Error-Message")
      {
        REQUIRE(checker==0);
      } 
    }
  } 
}