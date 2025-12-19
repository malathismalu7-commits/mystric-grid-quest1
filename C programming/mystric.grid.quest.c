#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int main() {
    int playerX = 0, playerY = 0;
    int treasureX, treasureY;
    int oldDistance, newDistance;
    char move;

    // Initialize random treasure position
    srand(time(0));
    treasureX = rand() % SIZE;
    treasureY = rand() % SIZE;

    // Initial distance
    oldDistance = abs(playerX - treasureX) + abs(playerY - treasureY);

    printf("Welcome to Mystic Grid Quest!\n");
    printf("Find the hidden treasure on a %dx%d grid.\n", SIZE, SIZE);

    while (1) {
        // Print grid
        for (int y = 0; y < SIZE; y++) {
            for (int x = 0; x < SIZE; x++) {
                if (x == playerX && y == playerY)
                    printf("P "); // Player
                else
                    printf(". "); // Empty space
            }
            printf("\n");
        }

        // Take input
        printf("\nMove (W=up, S=down, A=left, D=right): ");
        scanf(" %c", &move);

        // Update player position
        if (move == 'W' || move == 'w') playerY--;
        else if (move == 'S' || move == 's') playerY++;
        else if (move == 'A' || move == 'a') playerX--;
        else if (move == 'D' || move == 'd') playerX++;

        // Keep player inside the grid
        if (playerX < 0) playerX = 0;
        if (playerX >= SIZE) playerX = SIZE - 1;
        if (playerY < 0) playerY = 0;
        if (playerY >= SIZE) playerY = SIZE - 1;

        // Calculate new distance
        newDistance = abs(playerX - treasureX) + abs(playerY - treasureY);

        // Check for treasure
        if (playerX == treasureX && playerY == treasureY) {
            printf("\n🎉 Congratulations! You found the treasure at (%d,%d)!\n", treasureX, treasureY);
            break;
        }

        // Give hint
        if (newDistance < oldDistance)
            printf("Warmer!\n");
        else if (newDistance > oldDistance)
            printf("Colder!\n");
        else
            printf("Same distance.\n");

        oldDistance = newDistance;
    }

    return 0;
}