#pragma once
#include "Car.h"

class Fiat final : public Car {
public:
	Fiat() : Car(55, 4.8, 225) {};
private:
	virtual const char* Name() const override;
	virtual unsigned int FuelCapacity() const override;
	virtual double FuelConsumption() const override;
	virtual unsigned int Speed(Weather weather) const override;
};