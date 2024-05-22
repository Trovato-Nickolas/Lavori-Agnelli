#include <stdio.h>
#include <stdlib.h>
char *add(int *argc, char *argv,int num)
{
    //
    (*argc) = (*argc) +num;
    char *newarray = (char *)realloc(argv,(*argc)+num);
    return newarray;
}
void min(char *argv)
{
    if (*argv > 64 && *argv <= 85)
    {
        *argv = *argv + 32;
    }
}
void getvocali(char *argv,int *argcvocali,int *argconsonanti,char** vocali,char** consonati)
{
    for (*argv = *argv; *argv != '\0'; argv++)
    {
        min(argv);
        
        if (*argv == 97 || *argv == 101 || *argv == 105 || *argv == 111 || *argv == 117)
        {
            *((*vocali) + (*argcvocali) - 1) = *argv;
            (*vocali) = add(argcvocali, *vocali,1);
        }else{
            *((*consonati) + (*argconsonanti) - 1) = *argv;
            (*consonati) = add(argconsonanti, *consonati,1);
        }
        
    }
    *((*vocali) + (*argcvocali) - 1) = '\0';
    *((*consonati) + (*argconsonanti) - 1) = '\0';
}

void cort(int *argc,char *argv, char *nomevocali, char *nomeconsonati, int n)
{
    int c = 0;
    int s = 0;
    for (int i = (*argc); i < (*argc)+3; i++)
    {
        if (*(argv+i) != 'x')
        {
            if (i >= ((*argc)+n))
            {
                *(argv+i) = *(nomevocali + s);
                s++;
            }
            else
            {
                *(argv+i) = *(nomeconsonati + c);
                c++;
            }
        }
    }
    
}

void getrcognome(int *argc,char *argv,char* cognome)
{
    int i = 1;
    int c = 1;
    char *nomevocali = (char*)malloc(sizeof(char));
    char *nomeconsonati = (char*)malloc(sizeof(char));
    cognome = add(argc,cognome,3);
    *argc = *argc-3;
    getvocali(argv,&i,&c,&nomevocali,&nomeconsonati);
    if (c-1 >= 3)
    {
        cort(argc,cognome, nomevocali, nomeconsonati, 3);
    }
    else if (c-1 == 2)
    {
        cort(argc,cognome, nomevocali, nomeconsonati, 2);
    }
    else if (c-1 == 1 && i-1 == 2)
    {
        cort(argc,cognome, nomevocali, nomeconsonati, 1);
    }
    else if (i-1 == 1)
    {
        *(cognome + 2) = 'x';
        cort(argc,cognome, nomevocali, nomeconsonati, 1);
    }
    else if (i == 2)
    {
        *(cognome + 2) = 'x';
        cort(argc,cognome, nomevocali, nomeconsonati, 0);
    }
    else
    {
        for (int i = 0; i < 0; i++)
        {
            *(cognome + i) = 'x';
        }
    }
    *argc = *argc+3;
    free(nomevocali);
    free(nomeconsonati);
}

void getrnome(int *argc,char *argv,char* nome)
{
    int i = 1;
    int c = 1;
    char *nomevocali = (char*)malloc(sizeof(char));
    char *nomeconsonati = (char*)malloc(sizeof(char));
    nome = add(argc,nome,3);
    *argc = *argc-3;
    
    getvocali(argv,&i,&c,&nomevocali,&nomeconsonati);
    if (c-1 >= 4)
    {
        *(nome+(*argc)) = 'x';
        cort(argc,nome, nomevocali, nomeconsonati + 2, 3);
        *(nome+(*argc)) = *(nomeconsonati);
    }
    else if (c-1 == 3)
    {
        printf("%s ",nomeconsonati);
        cort(argc,nome, nomevocali, nomeconsonati, 3);
    }
    else if (c-1 == 2)
    {
        cort(argc,nome, nomevocali, nomeconsonati, 2);
    }
    else if (c-1 == 1 && i-1 == 2)
    {
        cort(argc,nome, nomevocali, nomeconsonati, 1);
    }
    else if (i-1 == 1 && c-1 == 1)
    {
        *(nome + 2) = 'x';
        cort(argc,nome, nomevocali, nomeconsonati, 1);
    }
    else if (i-1 == 2)
    {
        *(nome + 2) = 'x';
        cort(argc,nome, nomevocali, nomeconsonati, 0);
    }
    else
    {
        for (int i = 0; i < 0; i++)
        {
            *(nome + i) = 'x';
        }
        }
    *argc = *argc+3;
    
    free(nomevocali);
    free(nomeconsonati);
}

int toints(char *argv){
    int i = 0;
    for(argv = argv ; *argv != '\0';argv++){
        i = i*10 +((*argv)-48);

    }
    return i;
}
char* tochars(int *c,int num,char * arrnum){
    
    for(num = num ; num != 0;num = num / 10){

         *(arrnum+(*c)) = (num%10)+48;
         arrnum = add(c, arrnum,1);

    }
     *(arrnum+(*c)) = '\0';
     for(int i = 0; i < (*c)/2 ;i++){
        char cc = *(arrnum+i);
        *(arrnum+i) = *(arrnum+(((*c)-1)-i));
        *(arrnum+(((*c)-1)-i)) = cc;
        
     }
    return arrnum;
}
void getmese(int *argc,char *argv,char * day){
    int c = 0;
    char *nom = (char*)malloc(sizeof(char));
    char *ko[1] = {"abcdelhmprst"};
    *nom = *(ko[0]+toints(argv)-1);
    nom = add(&c,nom,1);
    *(nom+1) = '\0';
    for(nom = nom ; *nom != '\0';nom++){ *(day+(*argc)) = *nom;day = add(argc,day,1);}
}
void getday(int *argc,char *argv,char* genere,char * day){
    int num = toints(argv);
    min(genere);
    int c = 0;
    char *nom = (char*)malloc(sizeof(char));
    if((*genere) == 'f'){
        num  = num + 40;
    }
    tochars(&c,num,nom);
    if(num < 10){
        nom = add(&c,nom,1);
        for(int i = c; i > 0;i--){
            *(nom+i) = *(nom+i-1);
        }
        *nom = '0';
    }
    for(nom = nom ; *nom != '\0';nom++){ *(day+(*argc)) = *nom;day = add(argc,day,1);}
}
void getanno(int *argc,char *argv,char * day){
    int c = *argc;
    day =  add(argc,day,2);
    for(argv =argv+2; *argv != '\0';argv++){
        *(day+c)  = *argv;
        c++;
    }
}
int iscompared(char *num,char* nom){
    int c = 0;
    for(num = num; *num != '\0';num++){
        min(nom+c);
        min(num);
        if((*num) != (*(nom+c)) || (*(nom+c)) == '\0'){
            return 0;
            
        }
        c++;
    }
    return 1;
}
void getcodicecatastale(int *argc,char* comune, char* provincia,char * day){
    FILE * fp;
    if((fp = fopen("data.txt","r"))  == NULL){
        printf("Errore");
    }
    char *code = (char*)malloc(sizeof(char));
    char *comu = (char*)malloc(sizeof(char));
    char *prov = (char*)malloc(sizeof(char));
    while (fscanf(fp,"%s %s %s",code,comu,prov) != EOF)
    {
        if(iscompared(comu,comune) && iscompared(prov,provincia)){
            for(code = code; *code != '\0' ;code++){ *(day+(*argc)) = *(code);day = add(argc,day,1);}
        }
    }
    
}
char * getcomune(char * codes,int day){
    FILE * fp;
    if((fp = fopen("data.txt","r"))  == NULL){
        printf("Errore");
    }
    char *code = (char*)malloc(sizeof(char));
    char *comu = (char*)malloc(sizeof(char));
    char *prov = (char*)malloc(sizeof(char));
    while (fscanf(fp,"%s %s %s",code,comu,prov) != EOF)
    {
        if(iscompared(code,codes)){
            if(day){
                return comu;
        
           }else{
            return prov;

           }
        }
    }
    
}
char getcontrol(int *argc,char* argv){
    int c = 1;int num = 0;
    int mo[] = {1,0,5,7,9,13,15,17,19,21,2,4,18,20,11,3,6,8,12,14,16,10,22,25,24,23};
    for(char * i = argv; *i != '\0';i++){
        min(i);char v = *i;
        if(v > 47 && v < 58){
            v = v + 49;
        }
        if(c%2 == 0){
            num = num + (v - 'a');
        }else{
            num = num + mo[(v - 'a')];
        }
        c++;
    }
    return num%26+'a';
}
int main(int argc, char **argv)
{
    if(*argv[1] == '0'){
    int c = 0;
    char *  codicefiscale = (char*)malloc(sizeof(char));
    getrcognome(&c,argv[3],codicefiscale);
    getrnome(&c,argv[2],codicefiscale);
    getanno(&c,argv[6],codicefiscale);
    getmese(&c,argv[5],codicefiscale);
    getday(&c,argv[4],argv[7],codicefiscale);
    getcodicecatastale(&c,argv[8],argv[9],codicefiscale);
    codicefiscale = add(&c,codicefiscale,1);
    *(codicefiscale+(c-1)) = getcontrol(&c,codicefiscale);
    printf("%s ", codicefiscale);
    }
    else
    {
        char * ks[7] ={"nome:","cognome:","anno:","mese:","giorono:","comune:","provincia:"};
        char * mesi[] ={"gennaio","febbraio","marzo","aprile","maggio","giugno","luglio","agosto","setembre","ottobre","novebre","dicembre"};  
        
     int ko[] = {0,3,6,8,9,11,12,13};
     char *kl =  (char*)malloc(sizeof(char)*5);
     for(int i = 0; i < 7;i++){
        printf("%s",ks[i]);
        for(int c  = ko[i]; c < ko[i+1];c++){
            char *nm = (argv[2]+c); 
            if(i == 3){
                char *kd[1] = {"abcdelhmprst"};
                int h;
                for(int l = 0;*(kd[0]+l) != *nm;l++){h++;}
                printf("%s",mesi[h]);
            }else if(i == 5){
                nm = argv[2]+ko[5];
                *(nm+4) = '\0';
                printf("%s", getcomune(nm,1));
            }else if(i == 6){
                nm = argv[2]+ko[5];
                *(nm+4) = '\0';
                printf("%s",getcomune(nm,0));
            }else{
                printf("%c",*nm);
            }
            
        }
        printf("\n");
     }
    }
    
}