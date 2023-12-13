#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }

    towerOfHanoi(n - 1, source, target, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, target);
    towerOfHanoi(n - 1, auxiliary, source, target);
}

int main() {
    int numDisks;
    
    // Input
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Function call
    towerOfHanoi(numDisks, 'A', 'B', 'C');

    return 0;
}
