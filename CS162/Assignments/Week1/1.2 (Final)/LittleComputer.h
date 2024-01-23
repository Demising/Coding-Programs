#ifndef LITTLECOMPUTER_H
#define LITTLECOMPUTER_H
class LittleComputer {
    private:
        int memory[20];
        int accumulator;
        int programCounter;
        int littleInstruction;
        int littleInstructionInfo;

    public:

        /**
         * @brief Basic no-argument construction of a LittleComputer object
         * @param accumulator Value is set to "0".
         * @param programCounter Value is set to "0".
         * @param memory[] Array that has all 20 locations set to "0".
         */
        LittleComputer();

        /**
         * @brief Create a new LittleComputer object with arguments
         * @param instructions[] Array of jobs and values
         * @param numberOfInstructions The number of jobs and values inside the array
         * @param programCounter Initial value of "0". Used to find the information in the memory at a certain address.
         * @param accumulator Initial value of "0". Number interacts with the memory and is set to different values based on the job.
         * @param littleInstruction Used to store which job is being used. Initial value of "0".
         * @param littleInstructionInfo Used to store the memory address that the job is targeting. Initial value of "0".
         * @param memory[] Array of information that takes the different jobs and values from the instructions array. Any remaining addresses with no values get a value of "0".
         */
        LittleComputer(int instructions[], int numberOfInstructions);

        /**
         * @brief basic function used to get the current programCounter.
         * @return programCounter. 
         */
        int getProgramCounter();

        /**
         * @brief basic function used to get the accumulator number.
         * @return accumulator. 
         */
        int getAccumulator();

        /**
         * @brief basic function used to get the current memory value.
         * @param location Number used to get the value at the memory address.
         * @return memory[location]. 
         */
        int getMemoryAt(int location);

        /**
         * @brief basic function used to get the memory address with programCounter.
         * @return memory[programCounter]. 
         */
        int getCurrentInstruction();

        /**
         * @brief Function used to decide which job is being used at the current step.
         * @param instruType The hundredth's number a part of the value (Example: 7 from 7XX).
         * @param instruInfo The values in the memory address pointer in the value (Example: 83 from 683, or XX from 5XX).
         */
        void instructionCalculation(int& instruType, int& instruInfo);

        /**
         * @brief Function used if the current job is addition.
         * @param instruInfo The memory address pointer from the instructionCalculation function.
         * @param accumulator instruInfo is added into the accumulator.
         */
        void accumulatorAdd(int& instruInfo);

        /**
         * @brief Function used if the current job is subtraction.
         * @param instruInfo The memory address pointer from the instructionCalculation function.
         * @param accumulator instruInfo is subtracted from the accumulator. 
         */
        void accumulatorSub(int& instruInfo);

        /**
         * @brief Function used if the current job is storing the accumulator.
         * @param instruInfo The memory address pointer from the instructionCalculation function.
         * @param memory[] The array of memory that has the jobs and values.
         * @param accumulator Stored into the address that instruInfo points to. 
         */
        void storeInfo(int& instruInfo);

        /**
         * @brief Function used if the current job is loading a number from the memory.
         * @param instruInfo The memory address pointer from the instructionCalculation function.
         * @param memory[] The array of memory that has the jobs and values.
         * @param accumulator Number is the value that instruInfo is pointing to in the memory array. 
         */
        void loadInfo(int& instruInfo);

        /**
         * @brief Function used if the current job is branching to a different address.
         * @param instruInfo The memory address pointer from the instructionCalculation function.
         * @param programCounter Value is the same as instruInfo, meaning the address jumped to that new location. 
         */
        void alwaysBranch(int& instruInfo);

        /**
         * @brief Function used if the current job is branching to a different address, if the condition is met.
         * @param instruInfo The memory address pointer from the instructionCalculation function.
         * @param programCounter If the condition is met, the value of programCounter is the same as instruInfo, meaning the address jumped to that new location. 
         */
        void branchIf(int& instruInfo);

        /**
         * @brief Function used to step the program forward, if the value at the current step is not "0".
         * @param memory[] The array of memory that has the jobs and values.
         * @param programCounter The current step in the job, or memory. If the value at the step is not "0", then the code proceeds and programCounter will be incremented.
         * @param littleInstruction The value is determined by the value in memory at the current step, divided by 100. Due to int datatype, the value returned will be from the hundred's place.
         * @param littleInstructionInfo The value is determined by the remainder from the value in memory at the current step, divided by 100. This is the memory address.
         */
        void step();

        /**
         * @brief Determines if the program steps due to the value at the current step.
         * @param memory[] The array of memory that has the jobs and values.
         * @param programCounter The current step in the memory, used to determine if LittleComputer continues.
         * @return true If memory[programCounter] == "0".
         * @return false If otherwise
         */
        bool isHalted();

        /**
         * @brief Function used to reset the values of the accumulator and programCounter
         * @param accumulator Value is reset back to "0".
         * @param programCounter Value is reset back to "0".
         * 
         */
        void restart();
};
#endif