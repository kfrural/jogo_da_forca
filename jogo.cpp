#include<iostream>
#include <cstring>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
using namespace std;

void desenhaForca(int vidas){
    if(vidas==5){
        cout<<"Vai errar tudo"<<endl;
    }else if(vidas==4){
        cout<<"Começou errando, vai só ladeira a baixo"<<endl;
    }else if(vidas==3){
        cout<<"Vai errar de novo"<<endl;
    }else if(vidas==2){
        cout<<"Quase morrendo em"<<endl;
    }else if(vidas==1){
        cout<<"Vai perder Jaja"<<endl;
    }else if(vidas==0){
        cout<<"Nem pra isso serve"<<endl;
    }
}

int main(){
    char palavras[][15] = 
    { "c", "python", "html", "css", "javascript", "php", "java", "swift", "go",
"c#", "c++", "sql", "ruby"};
    char d1[][15] =
{ "d1p1", "d1p2", "d1p3", "d1p4", "d1p5", "d1p6", "d1p7", "d1p8", "d1p9",
"d1p10", "d1p11", "d1p12", "d1p13", "d1p14", "d1p15"};

    char d2[][15] =
{ "d2p1", "d2p2", "d2p3", "d2p4", "d2p5", "d2p6", "d2p7", "d2p8", "d2p9",
"d2p10", "d2p11", "d2p12", "d2p13", "d2p14", "d2p15"};

    char d3[][15] =
{ "d3p1", "d3p2", "d3p3", "d3p4", "d3p5", "d3p6", "d3p7", "d3p8", "d3p9",
"d3p10", "d3p11", "d3p12", "d3p13", "d3p14", "d3p15"};

    char d4[][15] =
{ "d4p1", "d4p2", "d4p3", "d4p4", "d4p5", "d4p6", "d4p7", "d4p8", "d4p9",
"d4p10", "d4p11", "d4p12", "d4p13", "d4p14", "d4p15"};
srand (time (NULL));

int i=0;
int n= rand () % 20;
int vidas=5;
int acertos=0;
char letra;
char resp[15];
int erro=0;
int palavrasadivinhadas[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    cout<<"\tJOGOZINHO DA FORCAZINHA\n\n"<<endl;
    cout<<"Aperta qualquer coisa ai sô"<<endl;
    system("clear");
    while (acertos < strlen (palavras[n])){
        erro=0;
        desenhaForca(vidas);
        for (int y = 0; y < strlen (palavras[n]); y++){
            if (palavrasadivinhadas[y] == 1){
                cout<<palavras[n][y];
            }else{
                cout<<"- ";
            }
        }
        cout<<"\nJa acertou: "<<acertos<<endl;
        cout<<"Vidas ate agora: "<<vidas<<endl;
        cout<<"Tenta ae, digita'tentar'"<<endl;
        
        switch (vidas){
            case 5:
            cout<<"Nem comecou ja! quer dica uai!!"<<endl;
            break;
            case 4:
            cout<<"Dica pra ver se ce acerta: "<<d1[n]<<endl;
            break;
            case 3:
            cout<<"Quer mais uma dica: "<<d2[n]<<endl;
            break;
            case 2:
            cout<<"Uai, ce num ta sabendo mermo em: "<<d3[n]<<endl;
            break;
            case 1:
            cout<<"Se num acertou ate agora ta no talo: "<<d4[n]<<endl;
            break;
        }
        cout<<"Digite uma letra: ";
        gets (resp);
        if (strcasecmp (resp, "sair") == 0){
            cout<<"Correu kkk"<<endl;
            exit (0);
        }else if (strcasecmp (resp, "tentar") == 0){
            cout<<"Digite a palavra: ";
            gets (resp);
            if (strcasecmp (resp, palavras[n]) == 0){
                cout<<"Pelo menos serve pra alguma coisa!"<<endl;
                exit (0);
            }else{
                cout<<"Burro demais!!"<<endl;
                vidas = 0;
                desenhaForca (vidas);
                exit (0);
            }
        }
        letra = resp[0];
        system ("clear");
        for (i=0; i<strlen(palavras[n]);i++){
            if (palavrasadivinhadas[i] == 1){
                continue;
            }else if (letra == palavras[n][i]){
                acertos++;
                erro++;
                palavrasadivinhadas[i] = 1;
            }
        }
        if (erro == 0){
            vidas--;
        }
        if (vidas == 0){
            cout<<"Burro demais 'ACEFALO'!"<<endl;
            desenhaForca (vidas);
            exit (0);
        }
        
    }
    cout<<"Pelo menos serve pra alguma coisa!"<<endl;

    
    return 0;
}





