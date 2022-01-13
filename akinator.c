#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define num_personagens 10
#define num_perguntas 19
#define grupos 2
struct cadastro
{
    char respostas[2], perguntas[grupos][100];
};
void compativel(int *pontuacao, int *aux);
int main()
{
    struct cadastro cad[num_perguntas];
    int i=0, j=0, k=0, tipo=0, aux=-1, pontuacao[num_personagens], cont=0;
    char gabarito[grupos][num_personagens][num_perguntas], personagens[grupos][num_personagens][20];
    char nome[num_personagens][30];
    strcpy(gabarito[0][0], "snsnsnsnnsnnnnsssss");
    strcpy(gabarito[0][1], "snsnsnsnnssnnssssnn");
    strcpy(gabarito[0][2], "nsnssnsnnnssssnssns");
    strcpy(gabarito[0][3], "snnssnsnnsssssnsnsn");
    strcpy(gabarito[0][4], "nssnsnsnnsnnssnssns");
    strcpy(gabarito[1][5], "nssnsnnssnnssnsnnss");
    strcpy(gabarito[1][6], "snsnsnsnssnsnsssnsn");
    strcpy(gabarito[1][7], "snsnnssnssnnsnnnsns");
    strcpy(gabarito[1][8], "snnsnssnsssnsnnnnnn");
    strcpy(gabarito[1][9], "nssnsnnssnnssssnnnn");
    strcpy(nome[0], "Batman");
    strcpy(nome[1], "Questao");
    strcpy(nome[2], "Arlequina");
    strcpy(nome[3], "Lex Luthor");
    strcpy(nome[4], "Cacadora");
    strcpy(nome[5], "Zatanna");
    strcpy(nome[6], "Shazam");
    strcpy(nome[7], "Cacador de marte");
    strcpy(nome[8], "Lobo");
    strcpy(nome[9], "Ravena");
    strcpy(cad[0].perguntas[0], "Seu personagem e do sexo masculino?                                   ");
    strcpy(cad[1].perguntas[0], "Seu personagem e do sexo feminino?                                    ");
    strcpy(cad[2].perguntas[0], "Seu personagem e um heroi?                                            ");
    strcpy(cad[3].perguntas[0], "Seu personagem e um vilao?                                            ");
    strcpy(cad[4].perguntas[0], "Seu personagem e humano?                                              ");
    strcpy(cad[5].perguntas[0], "Seu personagem e um alienigena?                                       ");
    strcpy(cad[6].perguntas[0], "Seu personagem e adulto?                                              ");
    strcpy(cad[7].perguntas[0], "Seu personagem e jovem?                                               ");
    strcpy(cad[8].perguntas[0], "Seu personagem possui poderes?                                        ");
    strcpy(cad[9].perguntas[0], "Seu personagem tem inteligencia fora do comum?                        ");
    strcpy(cad[10].perguntas[0], "Seu personagem e considerado maluco?                                 ");
    strcpy(cad[11].perguntas[0], "Seu personagem utiliza armas de fogo?                                ");
    strcpy(cad[12].perguntas[0], "Seu personagem utiliza armas brancas?                                ");
    strcpy(cad[13].perguntas[0], "Seu personagem mata se for preciso?                                  ");
    strcpy(cad[14].perguntas[0], "Seu personagem e aliado a liga da justica?                           ");
    strcpy(cad[15].perguntas[0], "Seu personagem interroga as pessoas?                                 ");
    strcpy(cad[16].perguntas[0], "Seu personagem possui identidade secreta?                            ");
    strcpy(cad[17].perguntas[0], "Seu personagem e rico?                                               ");
    strcpy(cad[18].perguntas[0], "Seu personagem e aparece em Gotham?                                  ");
    strcpy(cad[9].perguntas[1], "Seu personagem possui super-forca?                                    ");
    strcpy(cad[10].perguntas[1], "Seu personagem possui regeneracao?                                   ");
    strcpy(cad[11].perguntas[1], "Seu personagem utiliza magia?                                        ");
    strcpy(cad[12].perguntas[1], "Seu personagem nasceu com os poderes?                                ");
    strcpy(cad[13].perguntas[1], "Seu personagem nao gosta da origem de seus poderes?                  ");
    strcpy(cad[14].perguntas[1], "Seu personagem precisa falar para usar os poderes?                   ");
    strcpy(cad[15].perguntas[1], "Seu personagem possui os poderes de deuses?                          ");
    strcpy(cad[16].perguntas[1], "Seu personagem possui telepatia?                                     ");
    strcpy(cad[17].perguntas[1], "Seu personagem possui identidade secreta?                            ");
    strcpy(cad[18].perguntas[1], "Seu personagem e faz parte da liga da justica?                       ");
    printf("\t\t\t\tAkinator\n\n");
    printf("Os personagens presente nesse Akitor pertecem a DC comics.\n\n");
    printf("Os personagens existentes sao:\n");
    for(i = 0; i < num_personagens; i++)
    {
        printf("\t%d - %s\n", i+1, nome[i]);//apresenta personagens
        pontuacao[i]=0;
    }
    printf("\nResponda as perguntas com apenas s[sim] e n[nao].\n\n");
    printf("\t\tPerguntas\t\t\t\t\t\t    Respostas\n");
    for(i = 0; i < num_perguntas; i++)//leitura de dados
    {
        printf("%d- %s\t", k+1, cad[i].perguntas[tipo]);
        setbuf(stdin, NULL);
        gets(cad[i].respostas);
        if(cad[i].respostas[0] != 'n' && cad[i].respostas[0]!= 's')//garante que a resposta seja aceitavel
        {
            i--;
            k--;
            printf("\a\tResposta invalida!\n\tDigite novamente.\n");
        }
        if(i == 8)//muda o tipo de personagem, segundo a divisao de inicial
        {
            if(cad[i].respostas[0] == 's')
            {
                tipo++;
            }
        }
        if(i%2 == 0 && i < 8)//evita perguntas desnecessarias
        {
            if(cad[i].respostas[0] == 's')
            {
                i++;
            }
        }
        k++;
    }
    for(i = 0; i < num_personagens; i++)
    {
        for(j = 0; j < num_perguntas; j++)
        {
           if(cad[j].respostas[0] == gabarito[tipo][i][j])//compara resposta e pontua cada personagem
            {
                pontuacao[i]++;
            }
        }
        if(pontuacao[i] == k)// mostra o personagem se todas as perguntas foram feitas corretamente e encerra o processo de pontuaçao
        {
            aux = i;
            break;
        }
    }
    if(aux == -1)
    {
        printf("\t\tAlguma resposta foi digitada errada!\a\n");
        compativel(pontuacao, &aux);
        printf("O personagem mais compativel com as suas respostas e %s.\n" , nome[aux]);
    }
    else
    {
        printf("O seu personagem e %s!\n" , nome[aux]);//finaliza o jogo
    }
    printf("\n\n\t\t\t\tFIM DE JOGO!\n\n");
    return 0;
}
void compativel(int *pontuacao, int *aux)
{
    int i=0, max=0;
    for(i = 0; i < num_personagens; i++)
    {
        if(pontuacao[i] > max)
        {
            max = pontuacao[i];
            *aux = i;
        }
    }
}
