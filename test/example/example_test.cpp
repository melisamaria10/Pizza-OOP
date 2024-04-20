#include <gtest/gtest.h>
#include "example.h"

TEST(PizzaClasicaTest, ConstructorTest) {
    PizzaClasica pizza("Capriciosa", 33.98, "subtire");
    EXPECT_EQ(pizza.getnume(),"Capriciosa");
    EXPECT_EQ(pizza.getTipCrusta(),"subtire");
    // Other assertions: https://google.github.io/googletest/reference/assertions.html#boolean
}
TEST(PizzaDesertTest, ConstructorTest) {
    PizzaDesert  pizza("cu Nutella",23.75,"ciocolata");
    EXPECT_EQ(pizza.getIngredientSpecial(),"ciocolata");
    EXPECT_DOUBLE_EQ(pizza.getpret(),23.75);
}