#pragma once
#include "Car.h"

class Ford final : public Car {
public:
	Ford() : Car(2100, 30, 200) {};
private:
	virtual const char* Name() const override;
	virtual unsigned int FuelCapacity() const override;
	virtual unsigned int FuelConsumption() const override;
	virtual unsigned int Speed(Weather weather) const override;
};