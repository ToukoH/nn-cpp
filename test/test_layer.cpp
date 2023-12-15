#include "../include/Layer.hpp"
#include <iostream>

int main() {
    int layerSize = 5;
    Layer layer(layerSize, 3);

    for (int i = 0; i < layerSize; ++i) {
        layer.setValue(i, static_cast<double>(i));
    }
    std::cout << "Activated Values:" << std::endl;
    std::vector<double> activatedValues = layer.getActivatedValues();
    for (double val : activatedValues) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Values to Matrix:" << std::endl;
    Eigen::MatrixXd valuesMatrix = layer.valuesToMatrix();
    std::cout << valuesMatrix << std::endl;

    std::cout << "Activated Values to Matrix:" << std::endl;
    Eigen::MatrixXd activatedValsMatrix = layer.actValsToMatrix();
    std::cout << activatedValsMatrix << std::endl;

    std::cout << "Differentiated Values to Matrix:" << std::endl;
    Eigen::MatrixXd diffValsMatrix = layer.diffValsToMatrix();
    std::cout << diffValsMatrix << std::endl;

    return 0;
}
