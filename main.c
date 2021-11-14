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

void imprimir_calendar(Compromisso* eventos, int tamanho);


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
            char* desc = calloc(20, sizeof(char));
            fscanf(arquivo, "%d", &cod);
            tmp.codigo = cod;                        
            fscanf(arquivo, " %[^\n]", desc);
            //printf("%s\n", desc);            
            tmp.descricao = calloc(strlen(desc) +1, sizeof(char));            
            strcpy(tmp.descricao, desc);            
            char* hora = calloc(4, sizeof(char));
            char* minutos = calloc(4, sizeof(char));
            fscanf(arquivo, " %[^:]",  hora);
            tmp.inicio.hora = atoi(hora);
            hora = calloc(4, sizeof(char));
            fscanf(arquivo, " %[^ \n]",  minutos);
            tmp.inicio.minutos = atoi(minutos);
            minutos = calloc(4, sizeof(char));
            fscanf(arquivo, " %[^:]",  hora);
            tmp.final.hora = atoi(hora);
            fscanf(arquivo, " %[^ \n]",  minutos);
            tmp.final.minutos = atoi(minutos);
            //printf("Compromisso tmp ------------------\n");
            //imprimir_calendar(&tmp, 1);
            //printf("Compromisso tmp ------------------\n");
            calendar.eventos[i] = tmp;            
        }

    }
    
    return calendar.eventos;
}

void imprimir_calendar(Compromisso* eventos, int tamanho){
    printf("Lista de eventos:\n");
    for(int i =0; i< tamanho; i++){
        printf("Evento %d \n Descrição: %s\n Horario Inicio: %d:%d \n Horario Fim: %d:%d\n\n", 
        eventos->codigo, eventos->descricao, eventos->inicio.hora, eventos->inicio.minutos, eventos->final.hora, eventos->final.minutos);
        eventos++;
    }
}

void salvar_agenda(Compromisso* eventos, int tamanho){
    FILE* arq;
    if((arq = fopen("calendar.txt", "w")) != NULL){
        fprintf(arq, "Calendário:\n\n");
        for (int i = 0; i < tamanho; i++)
        {
            fprintf(arq,"Evento %d \n Descrição: %s\n Horario Inicio: %d:%d \n Horario Fim: %d:%d\n\n", 
            eventos->codigo, eventos->descricao, eventos->inicio.hora, eventos->inicio.minutos, eventos->final.hora, eventos->final.minutos);
            eventos++;
        }        
    }
}


void cadastra_compromisso(Compromisso* eventos, int tamanho){
    Compromisso tmp;
    char* descricao = calloc(20, sizeof(char));
    scanf("Digite a descrição do envento: %s", descricao);
    strcpy(tmp.descricao, desc);
    int horaInicio =0;
    scanf("Digite a hora inicial: %d", horaInicio);
    tmp.inicio.hora = horaInicio;
    int minuitosInicio =0;
    scanf("Digite a minutos inicial: %d", minutosInicio);
    tmp.inicio.minutos = minuitosInicio;
    int horaFim =0;
    scanf("Digite a hora final: %d", horaFim);    
    tmp.final.hora = horaFim
    int minutosFim =0;
    scanf("Digite a minutos final: %d", minutosFim);
    tmp.final.minutos = minutosFim;

    eventos[tamanho+1] = tmp;
}

int main(){

    Calendar calendar;
    int tamanho=0;

    calendar.eventos = carrega_agenda(&tamanho);
    imprimir_calendar(calendar.eventos, tamanho);
    salvar_agenda(calendar.eventos, tamanho);
    
    return 0;
}

