#include <stdio.h>
#include <stdlib.h>

int info_int;
int choix;

typedef struct{
    int idClient;
    char nom[30];
    char prenom[30];
    char email[50];
    float solde;
}client;

typedef struct{
    int idProduit ;
    char nom[40];
    char categorie[30];
    float prix;
    int stock;
    char description[100];
}produit;

produit Prod[5];
client cli[5];
int idClient=0;
//gesion du profile client
void creerPro(client cli[]){
    printf("=== Creatiation du profile ===\n");
    cli[idClient].idClient = idClient + 1;
    printf("\ndonner votre Prenom:");
    scanf("%s",cli[idClient].prenom);
    printf("\ndonner votre nom:");
    scanf("%s",cli[idClient].nom);
    sprintf(cli[idClient].email, "%s.%s@gmail.com", cli[idClient].prenom, cli[idClient].nom);
    cli[idClient].solde = 0.0;
    printf("!!!Profil creer avec succes!!!!!\n");
    idClient++;
}

void affichagPro(){
    if(idClient ==0){
          printf(" Aucun profil n'est encore cree !!\n");
    }
    else{
    int i = idClient - 1;
     printf(" === Consultation du profile ===\n");
     printf(" Votre id est: %d\n",cli[i].idClient);
     printf(" Votre Nom est: %s\n",cli[i].nom);
     printf(" Votre Prenom est: %s\n",cli[i].prenom);
     printf(" Votre nom est: %s\n",cli[i].email);
     }
}

void ModifierPro(client cli[]){
     printf("=== Modification  du profile ===\n");
     int i = idClient - 1;
    printf(" Ancien Prenom: %s\n", cli[i].prenom);
    printf(" Ancien Nom   : %s\n", cli[i].nom);
    printf(" Nouveau Prenom: ");
    scanf("%s", cli[i].prenom);
    printf(" Nouveau Nom: ");
    scanf("%s", cli[i].nom);
    sprintf(cli[i].email, "%s%s@gmail.com", cli[i].prenom, cli[i].nom);
    printf("\n !!! Profil modifie avec succes !!! \n");
}
//gestion solde virtuel
void ConsulterSolde(client cli[]){
     printf("\n=== Consultation du Solde ===\n");
     if (idClient == 0) {
        printf(" Aucun profil n'est encore cree !!\n");
    } else {
        int i = idClient - 1;
        printf("Client: %s %s\n", cli[i].prenom, cli[i].nom);
        printf("Votre solde actuel est: %.2f MAD\n\n", cli[i].solde);
    }

}
void DepotArgent(int i){
    printf("=== Depot d'argent === \n");
    printf("donner moi votre solde:");
    float amount;
    scanf("%f", &amount);
    if (i>=0 && i<5){
    cli[i-1].solde = cli[i-1].solde + amount;
    printf("Depot avec succes !! Votre Nouvoe sold est: %2.f \n\n",cli[i-1].solde);
    }
    else{
     printf("client invalide!");
    }
}
//gestion produit
int nbProduits=0;
void initProduits() {
    strcpy(Prod[0].nom, "pc portabl");
    Prod[0].idProduit = 1;
    Prod[0].prix = 7500.0;
    Prod[0].stock = 10;

    strcpy(Prod[1].nom, "iphone");
    Prod[1].idProduit = 2;
    Prod[1].prix = 3500.0;
    Prod[1].stock = 25;

    strcpy(Prod[2].nom, "Casque");
    Prod[2].idProduit = 3;
    Prod[2].prix = 499.0;
    Prod[2].stock = 15;

    nbProduits = 3;
}
void affichageProduits() {
    printf("\n=== Catalogue Produits ===\n");

    if (nbProduits == 0) {
        printf("Aucun produit disponible pour le moment.\n");
        return;
    }

    for (int i = 0; i < nbProduits; i++) {
        printf("=== Produit N:%d === \n ID: %d \n Nom: %s \n Prix: %.2f DH \n Stock: %d\n",i+1,
               Prod[i].idProduit,
               Prod[i].nom,
               Prod[i].prix,
               Prod[i].stock);
    }
    printf("\n");
}
void rechercheProduit() {
    if(nbProduits == 0){
        printf("Aucun produit n'est disponible.\n");
        return;
    }

    char input[30];
    printf("Entr le nom ou la categorie du produit a rechercher: ");
    scanf("%s", input);

    int trouve = 0;
    for(int i = 0; i < nbProduits; i++){
        if(strcmp(Prod[i].nom, input) == 0 || strcmp(Prod[i].categorie, input) == 0){
            printf("Produit trouve:\n");
            printf("%d. %s - %.2f MAD - Stock: %d - Categorie: %s\n",
                   Prod[i].idProduit, Prod[i].nom, Prod[i].prix, Prod[i].stock, Prod[i].categorie);
            trouve = 1;
        }
    }

    if(trouve == 0){
        printf("Aucun produit correspondant trouve.\n");
    }
}


void menuPrinsipal(){
    printf("\n === SYSTEME D'ACHAT CLIENT === \n");
    printf(" 1. Gestion du profil client\n");
    printf(" 2. Gestion du solde virtuel\n");
    printf(" 3. Consultation des produits\n");
    printf(" 4. Effectuer un achat\n");
    printf(" 5. Mes statistiques\n");
    printf(" 0. Quitter l'application\n");
    printf("Entre un choix: ");
}

void menu1(){
    do {

        printf("\n=== 1. Gestion du Profil Client === \n");
        printf(" 1. Creation de profil\n");
        printf(" 2. Affichage du profil\n");
        printf(" 3. Modification du profil\n");
        printf(" 0. Retour\n");
        printf("Entre un choix: ");
        scanf("%d",&choix);

        switch(choix){
            case 1:creerPro(cli);
            break;
            case 2:affichagPro();
            break;
            case 3: ModifierPro(cli);
            break;
            case 0: return;
            default: printf("Choix invalide!\n");
        }
    } while(choix != 0);
}

void menu2(){
    do {
        printf(" === 2. Gestion du Solde Virtuel === \n");
        printf(" 1. Consultation du solde\n");
        printf(" 2. Depot d'argent \n");
        printf(" 3. Verification automatique\n");
        printf(" 0. Roteur\n");
        printf("Entre un choix:");
        scanf("%d",&choix);

        switch(choix){
            case 1:ConsulterSolde(cli);
            break;
            case 2:DepotArgent(idClient);
            break;
            case 3: printf("=== Verification automatique === \n");
            break;
            case 0: return;
            default: printf("Choix invalide!\n");
        }
    } while(choix != 0);
}
void menu3(){
    do {
        printf(" === 3. Catalogue des Produits === \n");
        printf(" 1. Affichage catalogue\n");
        printf(" 2. Recherche produits \n");
        printf(" 3. Tri des produits\n");
        printf(" 4. Détails produit \n");
        printf(" 5. Produits predefinis\n");
        printf(" 0. Roteur\n");
        printf("Entre un choix:");
        scanf("%d",&choix);

        switch(choix){
            case 1:  initProduits();
                    affichageProduits();
            break;
            case 2: printf("=== Recherche produits === \n");
            rechercheProduit();
            break;
            case 3: printf("=== Tri des produits === \n");
            break;
            case 4: printf("=== Details produit === \n");
            break;
            case 5: printf("=== Produits predefinis === \n");
            break;
            case 0: return;
            default: printf("Choix invalide!\n");
        }
    } while(choix != 0);
}


int main(){
    do {
        menuPrinsipal();
        scanf("%d",&info_int);

        switch(info_int){
            case 1: system("cls");
                    menu1();
            break;
            case 2: system("cls");
                menu2();
            break;
            case 3: system("cls");
                menu3(); break;
            case 4: //menu4();
             break;
            case 5: //menu5();
             break;
            case 0: printf("Quitter l'application\n");
                return 0;
            default: printf("Choix invalide!\n");
        }
    } while(info_int != 0);


    return 0;
}
