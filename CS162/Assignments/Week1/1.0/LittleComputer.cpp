#include "LittleComputer.h"

LittleComputer::LittleComputer() {
    accumulator = 0;
    programCounter = 0;
    for (int i = 0; i < 20; i++) {
        memory[i] = 0;
    }
}