#ifndef NEURON_HPP
#define NEURON_HPP

#include <iostream>
#include <cmath>

#define RELU 1
#define SIGMOID 2
#define TANH 3

class Neuron {
public:
	Neuron(double value, double bias=0);
	Neuron(double value, int activationFunction, double bias=0);

	void setValue(double value);
	void setBias(double bias);
	void activateNeuron();
	void differentiate();

	double getValue() {
		return this->value;
	}

	double getBias() {
		return this -> bias;
	}

	double getActivatedValue() {
		return this->activatedValue;
	}

	double getDifferentiatedValue() {
		return this->differentiatedValue; 
	}

private:
	double value;
	double activatedValue;
	double bias;
	double differentiatedValue;
	int activationFunction;
};

#endif