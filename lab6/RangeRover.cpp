#include "RangeRover.h"

const char* RangeRover::Name() const {
	return "RangeRover";
}

unsigned int RangeRover::FuelCapacity() const {
	return m_fuelCapacity;
}

double RangeRover::FuelConsumption() const {
	return m_fuelConsumption;
}

unsigned int RangeRover::Speed(Weather weather) const {
	switch (weather) {
	case Weather::Sunny:
		return m_maxSpeed;
		break;
	case Weather::Rain:
		return 90 * m_maxSpeed / 100;
		break;
	case Weather::Snow:
		return 80 * m_maxSpeed / 100;
		break;
	default:
		return m_maxSpeed;
	}
}