#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_WEBSITE_LENGTH 100
#define PASSWORD_FILE "passwords.dat"

void addPassword();
void retrievePassword();
void deletePassword();
void modifyPassword();
void listPasswords();

void addPassword() {
    FILE *file = fopen(PASSWORD_FILE, "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    char website[MAX_WEBSITE_LENGTH], password[MAX_PASSWORD_LENGTH];
    printf("Enter website: ");
    scanf("%s", website);
    printf("Enter password: ");
    scanf("%s", password);

    fprintf(file, "%s %s\n", website, password);
    fclose(file);
    printf("Password added successfully!\n");
}

void retrievePassword() {
    FILE *file = fopen(PASSWORD_FILE, "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    char website[MAX_WEBSITE_LENGTH], password[MAX_PASSWORD_LENGTH];
    char searchWebsite[MAX_WEBSITE_LENGTH];
    printf("Enter website to retrieve password: ");
    scanf("%s", searchWebsite);

    int found = 0;
    while (fscanf(file, "%s %s", website, password) != EOF) {
        if (strcmp(website, searchWebsite) == 0) {
            printf("Password for %s: %s\n", website, password);
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("No password found for %s\n", searchWebsite);
    }
}

void deletePassword() {
    FILE *file = fopen(PASSWORD_FILE, "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    char website[MAX_WEBSITE_LENGTH], password[MAX_PASSWORD_LENGTH];
    char searchWebsite[MAX_WEBSITE_LENGTH];
    printf("Enter website to delete password: ");
    scanf("%s", searchWebsite);

    FILE *tempFile = fopen("temp.dat", "w");
    int found = 0;
    while (fscanf(file, "%s %s", website, password) != EOF) {
        if (strcmp(website, searchWebsite) != 0) {
            fprintf(tempFile, "%s %s\n", website, password);
        } else {
            found = 1;
        }
    }
    fclose(file);
    fclose(tempFile);

    remove(PASSWORD_FILE);
    rename("temp.dat", PASSWORD_FILE);

    if (found) {
        printf("Password for %s deleted successfully!\n", searchWebsite);
    } else {
        printf("No password found for %s\n", searchWebsite);
    }
}

void modifyPassword() {
    FILE *file = fopen(PASSWORD_FILE, "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    char website[MAX_WEBSITE_LENGTH], password[MAX_PASSWORD_LENGTH];
    char searchWebsite[MAX_WEBSITE_LENGTH], newPassword[MAX_PASSWORD_LENGTH];
    printf("Enter website to modify password: ");
    scanf("%s", searchWebsite);
    printf("Enter new password: ");
    scanf("%s", newPassword);

    FILE *tempFile = fopen("temp.dat", "w");
    int found = 0;
    while (fscanf(file, "%s %s", website, password) != EOF) {
        if (strcmp(website, searchWebsite) == 0) {
            fprintf(tempFile, "%s %s\n", website, newPassword);
            found = 1;
        } else {
            fprintf(tempFile, "%s %s\n", website, password);
        }
    }
    fclose(file);
    fclose(tempFile);

    remove(PASSWORD_FILE);
    rename("temp.dat", PASSWORD_FILE);

    if (found) {
        printf("Password for %s modified successfully!\n", searchWebsite);
    } else {
        printf("No password found for %s\n", searchWebsite);
    }
}

void listPasswords() {
    FILE *file = fopen(PASSWORD_FILE, "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    char website[MAX_WEBSITE_LENGTH], password[MAX_PASSWORD_LENGTH];
    printf("Stored passwords:\n");
    while (fscanf(file, "%s %s", website, password) != EOF) {
        printf("%s\n", website);
    }
    fclose(file);
}

int main() {
    int choice;
    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. Retrieve Password\n");
        printf("3. Delete Password\n");
        printf("4. Modify Password\n");
        printf("5. List Stored Passwords\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                retrievePassword();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                modifyPassword();
                break;
            case 5:
                listPasswords();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
