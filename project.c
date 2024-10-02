#include <stdio.h>
#include <string.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct
{
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

void ajouter()
{
    if (count >= 100)
    {
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

    do
    {
        printf("Choisir le status:\n");
        printf("1. Valide\n");
        printf("2. Reporté\n");
        printf("3. Annuler\n");
        printf("4. Traité\n");
        printf("Veuillez choisir (1-4): ");
        scanf("%d", &arr[count].status);
        getchar();

        if (arr[count].status < 1 || arr[count].status > 4)
        {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (arr[count].status < 1 || arr[count].status > 4);

    printf("Entrer date (jour mois annee): ");
    scanf("%d %d %d", &arr[count].date.jour, &arr[count].date.mois, &arr[count].date.annee);
    getchar();

    count++;
    printf("--- Contact ajouté avec succès ---\n");
    printf("count %d ", count);
}

void afficher()
{
    for (int i = 0; i < count; i++)
    {
        printf("ID : %d ,Nom: %s, Prénom: %s, Téléphone: %s, Age: %d, Date: %02d/%02d/%04d \n",
            i + 1,
            arr[i].nom, 
            arr[i].prenom, 
            arr[i].telephone, 
            arr[i].age, 
            arr[i].date.jour, arr[i].date.mois, arr[i].date.annee);
            switch (arr[i].status)
            {
            case 1:
                printf("Statut: validé\n");
                break;
            case 2:
                printf("Statut: reporté\n");
                break;
            case 3 :
                printf("Statut: annulé \n");
                break;
            case 4:
                printf("Statut: traité\n");
                break;
            default:
                break;
            }
            
    }
}

void modifier()
{
    int id, found = 0;
    char reponse;

    printf("Entrer l'ID ");
    scanf("%d", &id);
    getchar();

    id--; // c est decrementation parceque l utilsateur doit chercher avec 1 mais l indice du tableau debut avec 0

    for (int i = 0; i < count; i++)
    {
        if (id == i)
        {

            found = 1;
            printf("--- Avant modification ---\n");
            printf("Nom: %s, Prénom: %s, Téléphone: %s, Age: %d, Status: %d, Date: %02d/%02d/%04d\n",arr[i].nom, 
            arr[i].prenom, 
            arr[i].telephone, 
            arr[i].age, 
            arr[i].date.jour, arr[i].date.mois, arr[i].date.annee);
            switch (arr[i].status)
            {
            case 1:
                printf("Statut: validé\n");
                break;
            case 2:
                printf("Statut: reporté\n");
                break;
            case 3 :
                printf("Statut: annulé \n");
                break;
            case 4:
                printf("Statut: traité\n");
                break;
            default:
                break;
            }
            printf("--------------------------\n");

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

            do
            {
                printf("les status se sont : ['validé','reporté','annulé','traité']\n");
                printf("Entrer nouveau status (1-4): ");
                scanf("%d", &arr[id].status);
                getchar();

                if (arr[id].status < 1 || arr[id].status > 4)
                {
                    printf("Statut invalide, veuillez réessayer.\n");
                }
            } while (arr[id].status < 1 || arr[id].status > 4);

            printf("Entrer nouvelle date (jour mois année): ");
            scanf("%d %d %d", &arr[id].date.jour, &arr[id].date.mois, &arr[id].date.annee);
            getchar();
            printf("Modification réussie pour l'ID %d.\n", id + 1);

            printf("Voulez-vous voir la modification (y/n): ");
            scanf(" %c", &reponse);
            if (reponse == 'y' || reponse == 'Y')
            {
                afficher();
            }
        }
    }
    if (!found)
    {
        printf("id no");
    }
}

void supprimer(){
    int id , found = 0;
    char rep;
    printf("entrer l id : ");
    scanf("%d",&id);
    getchar();
    id--;
    for(int i = 0;i<count;i++){
        if(id == i){
            found = 1;
            printf("voulez vous vraiment supprimer cette reservation (y/n)");
            scanf(" %c",&rep);
            if(rep == 'y' || rep == 'Y'){
                for(int j = i;j<count-1;j++){
                    arr[j] = arr[j+1];
                }
                count--;
                printf("reservation et supprimer avec success \n");
            }
            else{
                printf("reservation non supprimer \n");
                return ;

            }
        }
    }
    if(!found){
        printf("id non reconu \n");
    }
}

int main()
{
    int choix;
    do
    {
        printf("--- Menu ---\n");
        printf("1. Ajouter\n");
        printf("2. Afficher\n");
        printf("3. modifier\n");
        printf("4. supprimer\n");
        printf("5. quiter\n");
        printf("Veuillez entrer un choix: ");
        scanf("%d", &choix);
        getchar();

        switch (choix)
        {
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
            supprimer();
            break;
        case 5:
            printf("Quitter.\n");
            break;
        default:
            printf("Choix invalide.\n");
            break;
        }
    } while (choix != 5);

    return 0;
}
