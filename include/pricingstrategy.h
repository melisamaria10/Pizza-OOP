
#ifndef OOP_PRICINGSTRATEGY_H
#define OOP_PRICINGSTRATEGY_H

class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    [[nodiscard]] virtual double calculatePrice(double basePrice) const = 0;
};

class NormalPricing : public PricingStrategy {
public:
    [[nodiscard]] double calculatePrice(double basePrice) const override;
};

class WeekendPricing : public PricingStrategy {
public:
    [[nodiscard]] double calculatePrice(double basePrice) const override;
};

#endif //OOP_PRICINGSTRATEGY_H
