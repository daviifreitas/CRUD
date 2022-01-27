#include "func.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
// QUALQUER DÚVIDA DISQUE 0800 ZAP !!

typedef struct data{
    char id [100];
    char name[100];
    char description[100];
}Data; //Estrutura com os tipos de dados que a compõem !!!!

Data account[4];

void menu(){
    int select; // para escolher o que o usuário poderá fazer dentro do sistema !!!!
    int a = 0 ; // VARIÁVEL PARA A ESTRUTURA DE REPETIÇÃO WHILE

    do {
        printf("------------WELCOME-------------\n\nlist of command\n\n1 - create the products\n2 - update a product\n3 - delete a product \n4 - consult the products\n5 - create a txt file\n6 - exit\n\nType here:");
        scanf("%d",&select); //A ideia aqui foi fazer algo mais "simples" como um chama função e executa e priu

        if(select==1){   //CHAMADA DAS FUNÇÕES DE ACORDO COM QUE O O USUÁRIO DIGITA !!!
            create();
        }
        else if(select==2){
            update();
        }
        else if(select==3){
            delete();
        }
        else if(select==4){
            consult();
        }
        else if(select == 5){
            createFile();
        }
        else if (select ==6){// SIMPLISMENTE PARA FECHAR O PROGRAMA JÁ QUE A TELA DE MENU SEMPRE VAI FICAR EM LOOPING E APARECENDO 24/48
            break;
        }
    }while(a ==0); // Para manter o sistema funcionando em looping !!!!


}

void delete(){
    __fpurge(stdin); // ONDE TIVER ESSE TIPO DE FUNÇÃO É PARA SIMPLISMENTE LIMPAR O BUFFER DO TECLADO PARA NÃO TERMOS PROBELMAS COM STRESS KKKKKK

    int orderOfID;
    printf("What product you want delete ? type the order of same\nType here:");
    scanf("%d", &orderOfID); // LER A ORDEM DO PRODUTO QUE O USUÁRIO DESEJA DELETAR

    strcpy(account[orderOfID -1].id ," ");// SUBSTITUIR O ID DO PRODUTO POR ZERO
    strcpy(account[orderOfID -1].name ," "); // LIMPAR A QUESTÃO DO NOME
    strcpy(account[orderOfID -1].description," "); // DA MESMA FORMA A DESCRIÇÃO

    printf("Type any key for continue......");
    getchar(); // COLOQUEI ISSO PARA TER UM TEMPO DE O USUÁRIO VER DE MANEIRA CLARA O QUE ACABOU DE ACONTECER DE MANEIRA GERAL
    __fpurge(stdin);
}

void update(){
    __fpurge(stdin); // LIMPAR BUFFER

    int orderOfID; // saber a ordem do cadastro que ele deseja fazer a alteração ,se é o 1° , 2° ou 4° por exemplo ;

    char auxID[100];   // Variáveis de auxilio para conseguir fazr a atuailização dos atributos (segue na outra linha)
    char auxName[30] ;  //de um determinado cadastro. Assim fica mais facíl de fazer o update !!(OBS : NOMES AUTOEXPLICATIVOS KKKK)
    char auxDescription[100];

    printf("What product you want delete ? type the order of same\nType here:");
    scanf("%d", &orderOfID);

    printf("Type the new id for {%d} product ", orderOfID);
    gets(auxID);
    __fpurge(stdin);

    printf("Enter with the new name of product of order {%d}:",orderOfID);
    gets(auxName);
    __fpurge(stdin);

    printf("Type a description for the new product :");
    gets(auxDescription);

    strcpy(account[orderOfID - 1].name ,auxName); //ATUALIZAR O NOME DO PRODUTO
    strcpy(account[orderOfID - 1].description, auxDescription); // ATUALIZAR A DESCRIÇÃO DO PRODUTO
    strcpy(account[orderOfID - 1].id, auxID); //ATUALIZAR O ID

    printf("Update with success \n\nCongratulations !!!!!");

    printf("Type any key for continue......");
    getchar();
    __fpurge(stdin); // LIMPAR BUFFER

}

void create(){
    __fpurge(stdin); // CANSEI JÁ

    for(int i = 0 ; i < 4 ; i++){ // UM CICLO FOR PARA LER OS DADOS DOS PRODUTOS NAME ,ID AND DESCRIPTION
        __fpurge(stdin);
        printf("Type the product {%d} name : ", i+1);
        gets(account[i].name);

        printf("Type the product {%d} id :", i+1);
        gets(account[i].id);

        __fpurge(stdin);

        printf("Type the product {%d} description :", i+1);
        gets(account[i].description);

        printf("\n\n\n\n\n\n");

    }
    bbsort(); //CHAMA A FUNÇÃO BBSORT -> ESSA FUNÇÃO VOU EXPLICAR NELA FICA MAIS FACIL

    printf("Type any key for continue......");
    getchar();
    __fpurge(stdin);

}

void consult(){ //CONSULTAR OS ARQUIVOS
    __fpurge(stdin);
    printf("\n\nThe order of ids \n");
    for(int a = 0 ; a < 4 ; a++){//PARA IMPRIMIR NA TELA A QUESTÃO DOS DADOS
        if(account[a].id==0){
            continue ;
        }
        printf(" %s ->    %s\n", account[a].id, account[a].name);
    }

    printf("Type any key for continue......");
    getchar();
}

void bbsort(){ //FUNÇÃO PARA ORDERNAR OS DADOS !!!!
    for(int i = 0 ; i < 4 ; i ++){
        for (int j = i ; j < 4 ; j++){
            if(account[i].id > account[j].id){
                char aux[50] ;  // VARIÁVEIS AUXILIARES !!!!!
                char auxName[30];
                char auxDescricao[100];

                strcpy(aux, account[j].id); //AQUELA LÓGICA DO SUCESSOR SER MAIOR QUE O ANTECESSOR !
                strcpy(account[j].id ,account[i].id);
                strcpy(account[i].id,aux);

                strcpy(auxName ,account[j].name); //AQUI NÃO FICA PARA TRAZ NA MESMA LÓGICA , O QUE MUDA É QUE ESTÁ CHAMANDO BILL DE SEVERINO KKKK
                strcpy(account[j].name ,account[i].name); // QUE SIGNIFICA QUE ESTAMOS TRATANDO DE STRINGS (VETOR DE CHAR) E NÃO MAIS DE NUMEROS INTEIROS (INT)
                strcpy(account[i].name ,auxName); // POR CONTA DISTO TEMOS QUE UTILIZAR A FUNÇÃO STRING COPY STRCPY (PARA OS ÍNTIMOS) DOCUMENTAÇÃO : https://www.unicamp.br/fea/ortega/info/aula09.htm

                strcpy(auxDescricao ,account[j].description);
                strcpy(account[j].description,account[i].description);
                strcpy(account[i].description, auxDescricao);
            }
        }
    }
}

void createFile(){
    FILE *file ;


    for(int i = 0 ; i <4; i++){
        file = fopen("Cadastros.txt", "a");
        fputs(account[i].id, file);
        fputs(" ;",file);
        fputs(account[i].name, file);
        fputs(" ;", file);
        fputs(account[i].description, file);
        fprintf(file,"\n\n");
        fclose(file);
    }


    __fpurge(stdin);

    printf("Do you want see the file ? Type 1 for yes or 2 for not ");
    int see ;
    scanf("%d",&see);

    __fpurge(stdin);

    char frase[100];
    file = fopen("Cadastros.txt", "r");

    if(see == 1){
        if (file == NULL){

            printf("Impossível abrir o arquivo");
            getchar();
        }
        else {

            while(fgets(frase ,100 ,file) != NULL){
                printf("%s", frase);
            }
        }
    }
}
