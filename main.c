#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct cidade{ //Noh com nome descrição e um ponteiro para a próxima cidade;
  char* nome;
  char* descricao;
  struct cidade* prox;
}Cidade;
Cidade *ini, *fim;
typedef struct horario{ //Noh com hora de partida, de chegada e quantidade de horas que a viagem tem;
    char* partidaT;
    char* chegadaT;
    int horas;
    struct rota* cid;
}Horario;
typedef struct rota{
  struct horario*testehorario;
  struct cidade *APcidade;
  struct rota* prox, *ant;
}Rota;
void inicio(){ini = NULL;} 
Cidade *adicionarCidades(char* nome, char *descricao){ //Essa função vai adicionar a cidade na lista;
  Cidade *nova = (Cidade*) malloc(sizeof(Cidade));
  nova->nome = nome;
  nova->descricao = descricao;
  nova->prox = NULL;
  if(ini == NULL) ini = fim = nova;
  else{fim->prox = nova; fim = nova;}
  return nova;
}
Rota* rotas[10];
Rota *inicializarRota(int i, char* nome){ //cria a tabela com as listas de rotas, já faz a "união" da tabela com a lista que contém as cidades;
  Rota *nova = (Rota*) malloc(sizeof(Rota));
  Cidade *auxC = (Cidade*) malloc(sizeof(Cidade));
  auxC = ini;
  nova->prox = NULL;
  if(rotas[i] == NULL){
    rotas[i] = nova;
    nova->ant= NULL;
    nova->APcidade = auxC;
  }else{
    Rota *aux;
    aux = rotas[i];
    while(aux->prox != NULL){
      aux = aux->prox;
    }
    while(auxC->nome != nome){
      auxC = auxC->prox;
    }
    nova->APcidade = auxC;
    nova->ant = aux;
    aux->prox  = nova;
  }
  return nova;
}
Horario *criahorario(Rota *rotateste, int i, char* partida, char* chegada){
    Horario *novo = (Horario*) malloc(sizeof(Horario));
    novo->partidaT = partida;
    novo->chegadaT = chegada;
    novo->horas = i;
    novo->cid = rotateste;
    rotateste->testehorario = novo;
}
int main(){
  //TESTANDO A LISTA DE CIDADES
  inicio();
  adicionarCidades("Fortaleza", "Terra do sol");
  adicionarCidades("Juazeiro do Norte", "Terra do padre cícero");
  adicionarCidades("Várzea Alegre", "Terra do arroz");
  adicionarCidades("Crato", "Oásis do Sertão");
  adicionarCidades("Pedra Branca", "Terra das altas serras");
  adicionarCidades("Quixadá", "Terra da galinha choca");
  adicionarCidades("Iguatu", "Terra de natureza e boas águas");
  adicionarCidades("Senador Pompeu", "O Senador");
  adicionarCidades("Boa viagem", "A Joia do Sertão Central");
  adicionarCidades("Russas", "Capital do Vale do Jaguaribe");
  adicionarCidades("Limoeiro do Norte", "Princesinha do Vale");
  adicionarCidades("Banabuiú", "Cidade Carinho");
  adicionarCidades("Acopiara", "Terra dos cultivos");
  adicionarCidades("Quixeramobim", "Terra de Antônio Conselheiro");
  adicionarCidades("Maracanaú", "Maior cidade-dormitório do Ceará.");
  adicionarCidades("Horizonte", "Lugar onde a vista não alcança.");
  adicionarCidades("Pacajus", "Terra do Caju.");
  adicionarCidades("Barbalha", "Terra dos verdes canaviais.");
  adicionarCidades("Trairi", "Rio das Traíras.");
  adicionarCidades("São Gonçalo do Amarante", "Smart city.");
  adicionarCidades("Caucaia", "Cidade Queimada.");
  adicionarCidades("Paraipaba", "A Terra do Coco.");
  adicionarCidades("Lavras da Mangabeira", "Sétima Maravilha do Ceará.");
  adicionarCidades("Canindé", "Cidade da fé.");
  adicionarCidades("Ipueiras", "Altiva, forte e magestosa! Soberana e gloriosa!.");
   //ROTA 1
    inicializarRota(0, "Fortaleza");
    criahorario(rotas[0], 9, "10:00", "19:00");
    inicializarRota(0, "Quixadá");
    inicializarRota(0, "Acopiara");
    inicializarRota(0, "Iguatu");
    inicializarRota(0, "Várzea Alegre");
   //ROTA 2
     inicializarRota(1, "Fortaleza");
     criahorario(rotas[1], 4, "12:00", "16:00");
     inicializarRota(1, "Quixadá");
    inicializarRota(1, "Quixeramobim");
    inicializarRota(1, "Senador Pompeu");
    inicializarRota(1, "Pedra Branca");
   //ROTA 3
    inicializarRota(2, "Fortaleza");
    criahorario(rotas[2], 3, "10:30", "13:30");
    inicializarRota(2, "Horizonte");
    inicializarRota(2, "Pacajus");
    inicializarRota(2, "Quixadá");
    inicializarRota(2, "Quixeramobim");
    //ROTA 4
    inicializarRota(3, "Fortaleza");
    criahorario(rotas[3], 7, "13:00", "20:00");
    inicializarRota(3, "Horizonte");
    inicializarRota(3, "Banabuiú");
    inicializarRota(3, "Iguatu");
    inicializarRota(3, "Crato");
    //ROTA 5
    inicializarRota(4, "Fortaleza");
    criahorario(rotas[4], 7, "09:45", "16:45");
    inicializarRota(4, "Pacajus");
    inicializarRota(4, "Banabuiú");
    inicializarRota(4, "Juazeiro do Norte");
    inicializarRota(4, "Barbalha");
    //ROTA 6
    inicializarRota(5, "Fortaleza");
    criahorario(rotas[5], 7, "16:00", "23:00");
    inicializarRota(5, "Pacajus");
    inicializarRota(5, "Quixadá");
    inicializarRota(5, "Lavras da Mangabeira");
    inicializarRota(5, "Juazeiro do Norte");
     //ROTA 7
    inicializarRota(6, "Fortaleza");
    criahorario(rotas[6], 1, "10:00", "11:00");
    inicializarRota(6, "Caucaia");
    inicializarRota(6, "São Gonçalo do Amarante");
    inicializarRota(6, "Paraipaba");
    inicializarRota(6, "Trairi");
     //ROTA 8
    inicializarRota(7, "Fortaleza");
    criahorario(rotas[7], 5, "13:00", "18:00");
    inicializarRota(7, "Caucaia");
    inicializarRota(7, "Canindé");
    inicializarRota(7, "Boa viagem");
    inicializarRota(7, "Iguatu");
    //ROTA 9
    inicializarRota(8, "Fortaleza");
    criahorario(rotas[8], 5, "11:30", "16:30");
    inicializarRota(8, "Horizonte");
    inicializarRota(8, "Canindé");
    inicializarRota(8, "Quixadá");
    inicializarRota(8, "Ipueiras");
     //ROTA 10
    inicializarRota(9, "Fortaleza");
    criahorario(rotas[9], 6, "12:00", "18:00");
    inicializarRota(9, "Horizonte");
    inicializarRota(9, "Quixadá");
    inicializarRota(9, "Quixeramobim");
    inicializarRota(9, "Acopiara");
    printf("===================================== \n");
    printf("            Lista de Rotas \n");
    printf("===================================== \n");
    printf("0 = Várzea Alegre | 9hrs de viagem \n1 = Pedra Branca   | 9hrs de viagem \n2 = Quixeramobim  | 3hrs de viagem \n3 = Crato  | 7hrs de viagem \n4 = Barbalha  | 7hrs de viagem \n5 = Juazeiro do Norte  | 7hrs de viagem \n6 = Trairi  | 1hrs de viagem \n7 = Iguatu  | 5hrs de viagem \n8 = Ipueiras  | 5hrs de viagem \n9 = Acopiara  | 6hrs de viagem \n") ; 
    int i;//indice da rota 
    printf("\nDIGITE O NÚMERO DA ROTA DESEJADA: ");
    scanf("%d",&i);
    Rota *teste = rotas[i];
    int auxP;
    Rota*teste2 = teste;
    do{
        printf("\nO que você deseja fazer agora?\n");
        printf("------------------------------------");
        printf("\n1 = Imprimir toda a rota.\n2 = Percorrer rota.\n3 = Exit.\n");

        scanf("%d",&auxP);
        int s;
        printf("------------------------------------\n");
        switch(auxP){
        case 1 :
        printf("                 ROTA                    \n");
        printf("\nHORÁRIO DE PARTIDA: %s\t HORÁRIO DE CHEGADA %s \n",rotas[i]->testehorario->partidaT, rotas[i]->testehorario->chegadaT);
        while(teste2 != NULL){
        printf("------------------------------------- \n");
        printf("NOME: %s \n",teste2->APcidade->nome);
        printf("\n");
        teste2 = teste2->prox;
        }  
        break; 
        case 2 :
        printf("\nHORÁRIO DE PARTIDA: %s\t HORÁRIO DE CHEGADA %s \n\n",rotas[i]->testehorario->partidaT, rotas[i]->testehorario->chegadaT);
        do{
            printf("Digite o número relativo ao que deseja fazer:\n\n|1 = Cidade anterior|\t|2 = Próxima cidade|\t|3 = Sair|\n");
            scanf("%d",&s);
            if(s == 1){
            if(teste->ant == NULL){
                printf("-------------------RESULTADO------------------ \n");
                printf("Desculpe, você já está na cidade de partida!\n");
                printf("---------------------------------------------- \n\n");
            }else{
                teste = teste->ant;
                printf("-------------------RESULTADO------------------ \n");
                printf("Você está em %s que é: %s\n",teste->APcidade->nome,teste->APcidade->descricao);
                printf("---------------------------------------------- \n\n");
            }
            }
            if(s == 2){
            if(teste->prox == NULL){
                printf(" \n");
                printf("-------------------RESULTADO------------------ \n");
                printf("Você já está no seu destino que é  %s, %s\n",teste->APcidade->nome,teste->APcidade->descricao);
                printf("\nHORÁRIO DE CHEGADA %s \n",rotas[i]->testehorario->chegadaT);
                printf("---------------------------------------------- \n\n");
            }else{
                printf("-------------------RESULTADO------------------ \n");
                teste = teste->prox;
                printf("Você está em %s que é %s\n\n",teste->APcidade->nome,teste->APcidade->descricao);
                printf("---------------------------------------------- \n\n");
            }
            }
        }while(s!=3);
        break;
        case 3 : 
        break;
        }
    }while(auxP!=3);  
}