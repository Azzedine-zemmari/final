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

    if (id <= 0 || id > count) {
    printf("ID invalide.\n");
    return;
}

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
    if (id <= 0 || id > count) {
    printf("ID invalide.\n");
    return;
}
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

void details(){
    int id , found = 0;
    printf("enter l id : ");
    scanf("%d",&id);
    getchar();

    if (id <= 0 || id > count) {
    printf("ID invalide.\n");
    return;
}

    id--;
    for(int i = 0;i<count;i++){
        if(i == id){
            found = 1;
            printf("Nom: %s\n",arr[i].nom);
            printf("Prenom: %s\n",arr[i].prenom);
            printf("Téléphone: %s\n",arr[i].telephone);
            printf("Âge: %d\n",arr[i].age);
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
            printf("Date de réservation : %d/%d/%d\n",arr[i].date.jour,arr[i].date.mois,arr[i].date.annee);
        }
    }
}

void triParNom(){
    reservation tmp;
    for(int i = 0;i<count-1;i++){
        for(int j = i+1;j<count;j++){
            if(strcmp(arr[i].nom,arr[j].nom)>0){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
        afficher(); 
}

void triParStatus() {
    reservation tmp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (arr[i].status > arr[j].status) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    afficher();  
}

void reservNom(){
    char name[20];
    int found = 0;
    printf("entrer le nom : ");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")] = 0;
    for(int i = 0;i<count;i++){
        if(strcmp(name,arr[i].nom) == 0){
            found = 1;
            printf("Nom: %s\n",arr[i].nom);
            printf("Prenom: %s\n",arr[i].prenom);
            printf("Téléphone: %s\n",arr[i].telephone);
            printf("Âge: %d\n",arr[i].age);
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
            printf("Date de réservation : %d/%d/%d\n",arr[i].date.jour,arr[i].date.mois,arr[i].date.annee);
        }
    }
}

void rechercheId(){
    int id , found = 0;
    printf("enter recherche id : ");
    scanf("%d",&id);
    getchar();

    if (id <= 0 || id > count) {
    printf("ID invalide.\n");
    return;
}
    id--;
    for(int i = 0;i<count;i++){
        if(id == i){
            found = 1;
            printf("Nom: %s\n",arr[i].nom);
            printf("Prenom: %s\n",arr[i].prenom);
            printf("Téléphone: %s\n",arr[i].telephone);
            printf("Âge: %d\n",arr[i].age);
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
            printf("Date de réservation : %d/%d/%d\n",arr[i].date.jour,arr[i].date.mois,arr[i].date.annee);
        }
    }
}

void moyeneAge(){
    int somme = 0 , moyenne , i;
    for(i = 0;i<count;i++){
        somme = somme + arr[i].age;
    }
    printf("moyenne d age et : %d ",somme/count);
}

void agetranch(){
    int ag1=0 , ag2=0 , ag3=0;
    for(int i = 0 ; i<count;i++){
        if(arr[i].age >= 1 && arr[i].age <=18){
            ag1++;
        }
        else if(arr[i].age >=19 && arr[i].age <=35)
            ag2++;
        else{
            ag3++;
        }
    }
    printf("le nombre des patient d age enter 1 et 18 sont %d  ",ag1);
    printf("le nombre des patient d age enter 19 et 35 sont %d  ",ag2);
    printf("le nombre des patient d age 36+ sont %d  ",ag3);
    
}

void nbS(){
    int s1=0 , s2=0 , s3=0 , s4 = 0;
    for(int i = 0 ; i<count;i++){
        if(arr[i].status == 1){
            s1++;
        }
        else if(arr[i].status == 2 )
            s2++;
        else if(arr[i].status == 3){
            s3++;
        }
        else{
            s4++;
        }
    }
    printf("le nombre des status valide sont %d  ",s1);
    printf("le nombre des status report sont %d  ",s2);
    printf("le nombre des status annuller sont %d  ",s3);
    printf("le nombre des status traiter sont %d  ",s4);
}

int main()
{
    int choix , choixtri , choixRech , moyenne , choixSt;
    do
    {
        printf("--- Menu ---\n");
        printf("1. Ajouter\n");
        printf("2. Afficher\n");
        printf("3. modifier\n");
        printf("4. supprimer\n");
        printf("5. details\n");
        printf("6. le tri\n");
        printf("7. rechercher\n");
        printf("8. statistique\n");
        printf("8. quiter\n");
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
            details();
            break;
        case 6:
            do{
                printf("---- le tri ----\n");
                printf("1.tri par nom \n");
                printf("2.tri par status \n");
                printf("3.return \n");
                scanf("%d",&choixtri);
                getchar();
                switch (choixtri)
                {
                case 1:
                    triParNom();
                    break;
                case 2:
                    triParStatus();
                    break;
                case 3:
                    break;
                default:
                    printf("veuillez entrez un choix exists ");
                    break;
                }
            }while(choixtri != 3);
            break;
        case 7:
            do{
                printf("---rechercher---\n");
                printf("1.recherche par nom \n");
                printf("2.recherche par id \n");
                printf("3.retour\n");
                printf("enter le choix : ");
                scanf("%d",&choixRech);
                getchar();
                switch (choixRech)
                {
                case 1:
                    reservNom();
                    break;
                case 2:
                    rechercheId();
                    break;
                case 3:
                    break;
                default:
                    printf("choix invalid \n");
                    break;
                }
            }while(choixRech != 3);
            break;
        case 8:
            do{
                printf("---statistique---\n");
                printf("1.moyenne d age des patient \n");
                printf("2.le nombre des tranche d age \n");
                printf("3.le nombre total de chaque status \n");
                printf("4.retourn\n");
                printf("entrer votre choix ");
                scanf("%d",&choixSt);
                switch (choixSt)
                {
                case 1:
                    moyeneAge();
                    break;
                case 2:
                    agetranch();
                    break;
                case 3:
                    nbS();
                    break;
                case 4:
                    break;
                default:
                    printf("choix invalid \n");
                    break;
                }
            } while(choixSt != 4);
            break;
        case 9:
            printf("Quitter.\n");
            break;
        default:
            printf("Choix invalide.\n");
            break;
        }
    } while (choix != 9);
    return 0;
}

//debug the function of tri par status (note)
//what if the user try to insert 0 (test) and (debug)
