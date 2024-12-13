#include <stdio.h>
#include <windows.h> // For high-resolution timing

#define MAX_ITERATIONS 1000

int main() {
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency); // Get the frequency of the high-resolution counter

    // Start the timer to measure total execution time
    LARGE_INTEGER startTime, endTime;
    QueryPerformanceCounter(&startTime);

    // Create a buffer to hold all the print statements
    char buffer[MAX_ITERATIONS * 100];  // Adjust size based on average string length
    char tempBuffer[100];

    // Perform the operation 1000 times, and buffer the output
    for (int i = 1; i <= MAX_ITERATIONS; i++) {
        // Format the string and append to the buffer
        snprintf(tempBuffer, sizeof(tempBuffer), "Jay Shree Ram - %d\n", i);
        strcat(buffer, tempBuffer);
    }

    // Print the buffered output all at once
    printf("%s", buffer);

    // End the timer
    QueryPerformanceCounter(&endTime);

    // Calculate elapsed time in ticks
    double elapsedTicks = (double)(endTime.QuadPart - startTime.QuadPart);
    double elapsedSeconds = elapsedTicks / frequency.QuadPart;

    // Convert the elapsed time to other units
    double elapsedMilliseconds = elapsedSeconds * 1000;
    double elapsedMicroseconds = elapsedMilliseconds * 1000;
    double elapsedNanoseconds = elapsedMicroseconds * 1000;

    // Print the total time taken for 1000 prints
    printf("\nTime taken to complete 1000 iterations:\n");
    printf("Seconds: %.6f s\n", elapsedSeconds);
    printf("Milliseconds: %.6f ms\n", elapsedMilliseconds);
    printf("Microseconds: %.6f µs\n", elapsedMicroseconds);
    printf("Nanoseconds: %.6f ns\n", elapsedNanoseconds);

    return 0;
}