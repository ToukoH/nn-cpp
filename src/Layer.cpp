#include "../include/Layer.hpp"

Layer::Layer(int size) {
	this -> size = size

	for (uint i = 0; i < size; i++) {
		Neuron *neuron = new Neuron(0.0);
		this -> neurons.push_back(neuron)
	}
}