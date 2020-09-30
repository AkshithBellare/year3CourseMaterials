#include <iostream>
class Box {
    private: 
        int volume;
    public:
        Box operator+(const Box& b) {
            Box box;
            box.volume = this->volume + b.volume;
            return box;
        }
        Box() {}
        Box(int v): volume{v} {}

        int getVolume() {
            return this->volume;
        }
};

int main() {
    Box b = Box(2);
    Box c = Box(3);
    Box d = b + c;
    std::cout << d.getVolume();
}