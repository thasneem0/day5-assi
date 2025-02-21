#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for patient node
typedef struct Patient {
    int id;
    char name[50];
    struct Patient *prev, *next;
} Patient;

Patient *head = NULL, *tail = NULL;
int patientID = 201;  // Starting ID

// Function to add a new patient
void addPatient(char name[]) {
    Patient *newPatient = (Patient*)malloc(sizeof(Patient));
    newPatient->id = patientID++;
    strcpy(newPatient->name, name);
    newPatient->next = NULL;
    
    if (head == NULL) {
        newPatient->prev = NULL;
        head = tail = newPatient;
    } else {
        tail->next = newPatient;
        newPatient->prev = tail;
        tail = newPatient;
    }
    
    printf("New Patient Admitted: %s (ID %d)\n", name, newPatient->id);
}

// Function to display patients in forward direction
void displayPatients() {
    Patient *temp = head;
    if (temp == NULL) {
        printf("No patients in the hospital.\n");
        return;
    }

    printf("Patients List: ");
    while (temp != NULL) {
        printf("%s (ID %d)", temp->name, temp->id);
        if (temp->next != NULL) printf(" ↔ ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to discharge a patient
void dischargePatient(char name[]) {
    Patient *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Discharging: %s\n", name);
            if (temp == head) {  // Removing first node
                head = temp->next;
                if (head) head->prev = NULL;
            } else if (temp == tail) {  // Removing last node
                tail = temp->prev;
                tail->next = NULL;
            } else {  // Removing from middle
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
            displayPatients();
            return;
        }
        temp = temp->next;
    }
    printf("Patient %s not found!\n", name);
}

int main() {
    addPatient("John");
    addPatient("Mary");
    addPatient("David");
    
    printf("\n");
    displayPatients();

    printf("\n");
    dischargePatient("Mary");

    return 0;
}
