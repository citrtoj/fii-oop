#pragma once
#include "Car.h"

class Ford final : public Car {
public:
	Ford() : Car(42, 4.6, 194) {};
private:
	virtual const char* Name() const override;
	virtual unsigned int FuelCapacity() const override;
	virtual double FuelConsumption() const override;
	virtual unsigned int Speed(Weather weather) const override;
};