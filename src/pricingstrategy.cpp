#include "pricingstrategy.h"

double NormalPricing::calculatePrice(double basePrice) const {
    return basePrice;
}

double WeekendPricing::calculatePrice(double basePrice) const {
    return basePrice * 0.75;
}