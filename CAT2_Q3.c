/*
Name:MARK MBUGUA
REG NO:CT101/G/26193/25
DESCRIPTION:CAT 2 Q3
*/
 #include <stdio.h>
#include <stdlib.h>

// 
void writeInputFile() {
    FILE *file = fopen("input.txt", "w");
    int num;
    
    if (file == NULL) {
        printf("Error: Could not create input.txt file!\n");
        return;
    }
    
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        fprintf(file, "%d\n", num);
    }
    
    fclose(file);
    printf("10 numbers successfully written to input.txt\n\n");
}

// 
void processNumbers() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");
    int num, sum = 0, count = 0;
    float average;
    
    if (inputFile == NULL) {
        printf("Error: Could not open input.txt for reading!\n");
        return;
    }
    
    if (outputFile == NULL) {
        printf("Error: Could not create output.txt file!\n");
        fclose(inputFile);
        return;
    }
    
    
    while (fscanf(inputFile, "%d", &num) != EOF) {
        sum += num;
        count++;
    }
    
    
    if (count > 0) {
        average = (float)sum / count;
    } else {
        average = 0;
    }
    
    fprintf(outputFile, "Sum: %d\n", sum);
    fprintf(outputFile, "Average: %.2f\n", average);
    
    fclose(inputFile);
    fclose(outputFile);
    
    printf("Sum and average calculated and written to output.txt\n\n");
}


void displayFiles() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "r");
    int num;
    char line[100];
    
    printf("=== FILE CONTENTS ===\n");
    
    
    printf("input.txt contents:\n");
    printf("--------------------\n");
    if (inputFile == NULL) {
        printf("Error: Could not open input.txt!\n");
    } else {
        while (fscanf(inputFile, "%d", &num) != EOF) {
            printf("%d\n", num);
        }
        fclose(inputFile);
    }
    
    printf("\n");
    
    
    printf("output.txt contents:\n");
    printf("--------------------\n");
    if (outputFile == NULL) {
        printf("Error: Could not open output.txt!\n");
    } else {
        while (fgets(line, sizeof(line), outputFile) != NULL) {
            printf("%s", line);
        }
        fclose(outputFile);
    }
    printf("\n");
}


int main() {
    int choice;
    
    printf("NUMBER PROCESSING PROGRAM \n");
    
    do {
        printf("Menu:\n");
        printf("1. Enter 10 numbers and save to input.txt\n");
        printf("2. Process numbers and save results to output.txt\n");
        printf("3. Display file contents\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                writeInputFile();
                break;
            case 2:
                processNumbers();
                break;
            case 3:
                displayFiles();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    } while(choice != 4);
    
    return 0;
}
