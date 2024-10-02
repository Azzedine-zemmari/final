#include <stdio.h>
#include <string.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    char nom[20];
    char prenom[20];
    char telephone[20];
    int age;
    int status;
    Date date;
} reservation;

reservation arr[100];
int count = 0;

void ajouter(); 
void afficher();
void modifier(); 

void ajouter() {
    if (count >= 100) {
        printf("Liste plein impossible d ajouter \n");
        return;
    }

    printf("Entrer nom: ");
    fgets(arr[count].nom, sizeof(arr[count].nom), stdin);
    arr[count].nom[strcspn(arr[count].nom, "\n")] = 0;

    printf("Entrer prenom: ");
    fgets(arr[count].prenom, sizeof(arr[count].prenom), stdin);
    arr[count].prenom[strcspn(arr[count].prenom, "\n")] = 0;

    printf("Entrer telephone: ");
    fgets(arr[count].telephone, sizeof(arr[count].telephone), stdin);
    arr[count].telephone[strcspn(arr[count].telephone, "\n")] = 0;

    printf("Entrer age: ");
    scanf("%d", &arr[count].age);
    getchar();  

    
    do {
        printf("Choisir le status:\n");
        printf("1. Valide\n");
        printf("2. Reporté\n");
        printf("3. Annuler\n");
        printf("4. Traité\n");
        printf("5. Quitter\n");
        printf("Veuillez choisir (1-5): ");
        scanf("%d", &arr[count].status);
        getchar();  

        if (arr[count].status < 1 || arr[count].status > 5) {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (arr[count].status < 1 || arr[count].status > 5);
    
    printf("Entrer date (jour mois annee): ");
    scanf("%d %d %d", &arr[count].date.jour, &arr[count].date.mois, &arr[count].date.annee);
    getchar();  

    count++;
    printf("--- Contact ajouté avec succès ---\n");
}

void afficher() {
    for (int i = 0; i < count; i++) {
        printf("Nom: %s, Prénom: %s, Téléphone: %s, Age: %d, Status: %d, Date: %02d/%02d/%04d\n",
               arr[i].nom, arr[i].prenom, arr[i].telephone, arr[i].age, arr[i].status,
               arr[i].date.jour, arr[i].date.mois, arr[i].date.annee);
    }
}

void modifier() {
    int id;
    printf("Entrer l'ID (0 à %d): ", count - 1);
    scanf("%d", &id);
    getchar();

    // Validate ID range
    if (id < 0 || id >= count) {
        printf("ID invalide. Veuillez réessayer.\n");
        return;
    }

    printf("Modification pour l'ID %d:\n", id);
    printf("Entrer nouveau nom: ");
    fgets(arr[id].nom, sizeof(arr[id].nom), stdin);
    arr[id].nom[strcspn(arr[id].nom, "\n")] = 0;

    printf("Entrer nouveau prénom: ");
    fgets(arr[id].prenom, sizeof(arr[id].prenom), stdin);
    arr[id].prenom[strcspn(arr[id].prenom, "\n")] = 0;

    printf("Entrer nouveau téléphone: ");
    fgets(arr[id].telephone, sizeof(arr[id].telephone), stdin);
    arr[id].telephone[strcspn(arr[id].telephone, "\n")] = 0;

    printf("Entrer nouvel âge: ");
    scanf("%d", &arr[id].age);
    getchar();  

    printf("Entrer nouveau status (1-5): ");
    scanf("%d", &arr[id].status);
    getchar();  

    printf("Entrer nouvelle date (jour mois année): ");
    scanf("%d %d %d", &arr[id].date.jour, &arr[id].date.mois, &arr[id].date.annee);
    getchar();  

    printf("Modification réussie pour l'ID %d.\n", id);
}


int main() {
    int choix;
    do {
        printf("--- Menu ---\n");
        printf("1. Ajouter\n");
        printf("2. Afficher\n");
        printf("3. Quitter\n");
        printf("Veuillez entrer un choix: ");
        scanf("%d", &choix);
        getchar();  

        switch (choix) {
            case 1:
                ajouter();
                break;
            case 2:
                afficher();
                break;
            case 3:
                modifier();
                break;
            case 4:
                printf("Quitter.\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    } while (choix != 4);

    return 0;
}
