#pragma once
#include "Weather.h"

class Car {
protected:
	unsigned int m_fuelCapacity; //liters
	unsigned int m_fuelConsumption; //liters/KM
	unsigned int m_maxSpeed; //KM/h
	Car(int fuelCapacity, int fuelConsumption, int maxSpeed) : m_fuelCapacity(fuelCapacity), m_fuelConsumption(fuelConsumption), m_maxSpeed(maxSpeed) {};
public:
	//basic getters
	virtual const char* Name() const = 0;
	virtual unsigned int FuelCapacity() const = 0;
	virtual unsigned int FuelConsumption() const = 0;
	virtual unsigned int Speed(Weather weather) const = 0;
};