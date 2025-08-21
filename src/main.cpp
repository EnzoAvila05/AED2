#include <iostream>
#include <string>
#include <list>
#include <locale>

int main() {

    std::list<std::string> robots = {"Wall-e", "Jarvis", "Blitzcranck"};

    std::cout << "Pódio da Corrida de Robôs" << std::endl;
    int position = 1;
    for (const auto& robot : robots) {
        std::cout << position++ << "°: " << robot << std::endl;
    }

    auto new_robot = robots.begin();
    ++new_robot;
    robots.insert(new_robot, "Robô");

    std::cout << "\nNovo pódio: " << std::endl;

    int position2 = 1;
    for (const auto& robot : robots) {
        std::cout << position2++ << "°: " << robot << std::endl;
    }

}