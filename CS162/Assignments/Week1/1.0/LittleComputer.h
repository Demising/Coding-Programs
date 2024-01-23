#ifndef LITTLECOMPUTER_H
#define LITTLECOMPUTER_H
class LittleComputer {
    private:
        int memory[20];
        int accumulator;
        int programCounter;

    public:
        LittleComputer();
        LittleComputer(int instructions[], int numberOfInstructions);
        int getProgramCounter();
        int getAccumulator();
        int getMemoryAt(int location);
        int getCurrentInstruction();
        void step();
        bool isHalted();
        void restart();
};
#endif