#include <iostream>

class Singleton {
    private static Singleton instance = NULL;

    private Singleton() {}

    public static Singleton getInstance() {
        if (instance == NULL) {
            instance = Singleton();
        }
        return instance;
    }
}

int main() {
    Singleton S = Singleton::getInstance();
}