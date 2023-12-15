#include "../include/Neuron.hpp"

Neuron::Neuron(double value) {
	this -> setValue(value);
}

Neuron::Neuron(double value, int activationFunction) {
	this -> setValue(value);
	this -> activationFunction = activationFunction;
}

void Neuron::activateNeuron() {
    switch (activationFunction) {
        case RELU:
            this -> activatedValue = this -> value > 0 ? this -> value : 0;
            break;

        case SIGMOID:
            this -> activatedValue = 1 / (1 + std::exp(-this -> value));
            break;

        case TANH:
            this -> activatedValue = std::tanh(this -> value);
            break;    

        default:
            this -> activatedValue = 1 / (1 + std::exp(-this -> value));
            break;
    }
}

void Neuron::differentiate() {
	switch (activationFunction) {
		case RELU:
			this -> differentiatedValue = this -> value ? 1 : 0;
			break;

		case SIGMOID:
			this -> differentiatedValue = (this -> activatedValue * (1 - this ->  activatedValue));
			break;

		case TANH:
			this -> differentiatedValue = (1 - this -> activatedValue * this -> activatedValue);
			break;

		default:
			this -> differentiatedValue = (this -> activatedValue * (1 - this ->  activatedValue));
			break;
	}
}

void Neuron::setValue(double value) {
	this -> value = value;
	activateNeuron();
	differentiate();
}
