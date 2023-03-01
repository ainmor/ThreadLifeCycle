#include <iostream>
#include <thread>
#include <chrono>

void chef_olivia() {
    printf("Olivia started & waiting for sausage to thaw...\n");
    std::this_thread::sleep_for(std::chrono::seconds (3));
    printf("Olivia is done cutting sausage. \n");
}

int main() {
    std::cout << "Barron requests olivia's help." << std::endl;
    std::thread olivia(chef_olivia);
    printf("Olivia is joinable? %s\n", olivia.joinable() ? "true" : "false");

    std::cout << "Barron continues cooking soup" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds (1));
    printf("Olivia is joinable? %s\n", olivia.joinable() ? "true" : "false");

    std::cout << "Barron patiently waits for olivia to finish and join..." << std::endl;
    olivia.join();
    printf("Olivia is joinable? %s\n", olivia.joinable() ? "true" : "false");

    std::cout << "Barron and Olivia are both done!" << std::endl;

    return 0;
}
