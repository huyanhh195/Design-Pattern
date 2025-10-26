#include <iostream>
#include <memory>

#define LOG(str)                       \
    do {                               \
        std::cout << str << std::endl; \
    } while (0);

enum class AnimalType { DOG, CAT, BIRD };

class AnimalFactory {
   public:
    virtual void speak() = 0;

    virtual ~AnimalFactory() = default;
};

class Dog : public AnimalFactory {
   public:
    void speak() override { LOG("Woof") }
};

class Cat : public AnimalFactory {
   public:
    void speak() override { LOG("Meow"); }
};

class Bird : public AnimalFactory {
   public:
    void speak() override { LOG("Chirp"); }
};

std::unique_ptr<AnimalFactory> MakeAnimal(const AnimalType &animal_type) {
    switch (animal_type) {
        case AnimalType::DOG:
            return std::make_unique<Dog>();

        case AnimalType::CAT:
            return std::make_unique<Cat>();

        case AnimalType::BIRD:
            return std::make_unique<Bird>();

        default:
            LOG("Unknown animal type");
            return nullptr;
    }
}

int main() {
    auto dog = MakeAnimal(AnimalType::DOG);
    if (dog) dog->speak();

    auto cat = MakeAnimal(AnimalType::CAT);
    if (cat) cat->speak();

    auto bird = MakeAnimal(AnimalType::BIRD);
    if (bird) bird->speak();

    return 0;
}