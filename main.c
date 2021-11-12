#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int hora;
    int minutos;
}Time;

typedef struct {
    char* descricao;
    Time inicio;
    Time final;
    int codigo;
} Compromisso;


typedef struct {
    Compromisso* eventos;
}Calendar;

void ordena_agenda(Compromisso* eventos, int tamanho);

Compromisso* carrega_agenda(int* tamanho);

void salvar_agenda(Compromisso* eventos, int tamanho);

void lista_compromissos(Compromisso* eventos, int hora_inicio, int minutos_inicio, int hora_fim, int minutos_fim);

void cadastrar_compromissos(Compromisso* eventos, int tamanho);

void editar_compromisso(Compromisso* _compromisso);

void remover_compromisso(Compromisso* eventos, int tamanho, int codigo);


Compromisso* carrega_agenda(int* tamanho){
    Calendar calendar;
    FILE* arquivo = fopen("database.txt", "rt");
    if (arquivo == NULL){
        printf("Problemas na leitura do arquivo\n");
        return 0;
    }
    else{
        //printf("teste\n");
        fscanf(arquivo, "%d", tamanho);
        //printf("%d", *tamanho);
        calendar.eventos = calloc(*tamanho, sizeof(Calendar));       
        //printf("teste\n");
        for(int i=0; i < *tamanho; i++){            
            Compromisso tmp;             
            int cod = 0;
            char* desc;             
            fscanf(arquivo, "%d", &cod);
            tmp.codigo = cod;            
            //printf("teste\n");
            fscanf(arquivo, " %[^\n]", desc);
            printf("%s\n", desc);
            printf("teste\n");
            tmp.descricao = calloc(strlen(desc) +1, sizeof(char));
            printf("teste\n");
            strcpy(tmp.descricao, desc);
            printf("teste\n");
            char* hora;
            char* minutos;
            fscanf(arquivo, " %[^:]",  hora);
            tmp.inicio.hora = atoi(hora);
            fscanf(arquivo, " %[^ ]",  minutos);
            tmp.inicio.minutos = atoi(minutos);
            fscanf(arquivo, " %[^:]",  hora);
            tmp.final.hora = atoi(hora);
            fscanf(arquivo, " %[^ ]",  minutos);
            tmp.final.minutos = atoi(minutos);
            calendar.eventos[i] = tmp;            
        }

    }
    

    return calendar.eventos;
}

int main(){

    Calendar calendar;
    int tamanho=0;

    carrega_agenda(&tamanho);


    printf("Test\n");

    return 0;
}

