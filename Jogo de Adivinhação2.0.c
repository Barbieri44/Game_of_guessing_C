#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int numero = 1000 + rand() % 9000;
    int codigo;
    int senha;
    int tent;
    int opcao;
    int s1, s2, s3, s4; // usuario
    int c1, c2, c3, c4; // codigo
    int continuar = 1;
    int ganhou = 0;
    codigo = numero;

    while (continuar)
    {
        printf("\n\t\t\t ====================================");
        printf("\n\t\t\t => BEM-VINDO AO JOGO SECRETO!!!  <=");
        printf("\n\t\t\t ====================================");
        printf("\n\n\t\tDigite (1) para as Regras");
        printf("\n\t\tDigite (2) para Jogar");
        printf("\n\t\tDigite (3) para Sair");
        printf("\t\tOpção: ");
        scanf("%d", &opcao);
        system("cls");

        switch (opcao)
        {
        case 1:
            printf("\n\n\t\t~============~");
            printf("\n\t\tREGRAS DO JOGO\n");
            printf("\t\t~============~");

            printf("\n\n\t\tVoce tem 10 tentativas para acertar o numero secreto");
            printf("\n\t\tentre [1000 e 9999].\n");
            printf("\n\t\tA partir da 5° tentativa o jogo ira te ajudar,");
            printf("\n\t\tdando dicas sobre os digitos corretos nas posicoes.\n\n");
            system("pause");
            system("cls");
            break;

        case 2:
            c1 = codigo / 1000;
            c2 = (codigo % 1000) / 100;
            c3 = (codigo % 100) / 10;
            c4 = codigo % 10;
            ganhou = 0;

            for (tent = 0; tent < 10; tent++)
            {
                int acerto = 0;
                printf("\n\t\tDigite a tentativa %d: ", tent + 1);
                scanf("%d", &senha);

                if (senha < 1000 || senha > 9999)
                {
                    system("cls");
                    printf("\n\tATENÇAO!! Por favor digite apenas numeros maiores que 1000 e menores que 9999");
                    printf("\n\tTentativa %d \n", tent + 1);
                    continue;
                }

                s1 = senha / 1000;
                s2 = (senha % 1000) / 100;
                s3 = (senha % 100) / 10;
                s4 = senha % 10;

                if (s1 == c1 && s2 == c2 && s3 == c3 && s4 == c4)
                {
                    printf("\n\t\tSenha Secreta = %d %d %d %d\n", c1, c2, c3, c4);
                    printf("\n\t\t\t =====================================");
                    printf("\n\t\t\t     => PARABENS VOCE GANHOU!!! <=");
                    printf("\n\t\t\t =====================================");
                    printf("\n\t    ");
                    system("pause");
                    system("cls");
                    ganhou = 1;
                    break;
                }
                else
                {
                    printf("\n\t\tSenha Secreta = ");
                    if (s1 == c1)
                    {
                        printf("%d ", c1); acerto++;
                    }
                    else
                    {
                      printf("_ ");
                    }

                    if (s2 == c2)
                    {
                        printf("%d ", c2);
                        acerto++;
                    }
                    else
                    {
                        printf("_ ");
                    }
                    if (s3 == c3)
                    { printf("%d ", c3); acerto++; } else printf("_ ");
                    if (s4 == c4) { printf("%d", c4); acerto++; } else printf("_");

                    printf("\n\n\t\tVoce acertou %d numeros na posicao correta", acerto);
                    printf("\n\n\t\tvoce tem %d tentativas restantes.\n\t\t", 9 - tent);
                    system("pause");
                    system("cls");

                    if (tent == 5)
                    {
                        printf("\n\t\t----- DICAS -----");
                        if (c1 != s1)
                        {
                            if (c1%2==0)
                            {
                                printf("\n\t\tO digito do Milhar eh Par");
                            }
                            else
                            {
                                printf("\n\t\tO digito do Milhar eh Impar");

                            }
                            if (c1>5)
                            {
                                printf("\n\t\tO digito do Milhar eh maior que 5");
                            }
                            else
                            {
                                printf("\n\t\tO digito do Milhar eh menor que 5");
                            }
                        }
                        if (c2 != s2)
                        {
                            if (c2%2==0)
                            {
                                printf("\n\t\tO digito da Centena eh Par");
                            }
                            else
                            {
                                printf("\n\t\tO digito da Centena eh Impar");

                            }
                            if (c2>5)
                            {
                                printf("\n\t\tO digito da Centena eh maior que 5");
                            }
                            else
                            {
                                printf("\n\t\tO digito da Centena eh menor que 5");
                            }
                        }
                        if (c3 != s3)
                        {
                            if (c3%2==0)
                            {
                                printf("\n\t\tO digito da Dezena eh Par");
                            }
                            else
                            {
                                printf("\n\t\tO digito da Dezena eh Impar");

                            }
                            if (c3>5)
                            {
                                printf("\n\t\tO digito da Dezena eh maior que 5");
                            }
                            else
                            {
                                printf("\n\t\tO digito da Dezena eh menor que 5");
                            }
                        }
                        if (c4 != s4)
                        {
                            if (c4%2==0)
                            {
                                printf("\n\t\tO digito da Unidade eh Par");
                            }
                            else
                            {
                                printf("\n\t\tO digito da Unidade eh Impar");

                            }
                            if (c4>5)
                            {
                                printf("\n\t\tO digito da Unidade eh maior que 5");
                            }
                            else
                            {
                                printf("\n\t\tO digito da Unidade eh menor que 5");
                            }
                        }
                        printf("\n\t\t---------------");
                        printf("\n\t   ");
                        system("pause");
                        system("cls");
                    }
                }
            }

            if (ganhou==0)
            {
                printf("\n\t\t\t ====================================");
                printf("\n\t\t\t      => QUE PENA VOCÊ PERDEU! <=");
                printf("\n\t\t\t ====================================");
                printf("\n\n\t\t\tO codigo era %d\n", codigo);
                system("pause");
                system("cls");
            }
            break;

        case 3:
            printf("\n\t\tObrigado por jogar! Ate a proxima!\n");
            continuar = 0;
            break;

        default:
            printf("\n\t\tOpção inválida. Por favor, digite 1, 2, 3 ou 4.\n");
            break;
        }
    }
    return 0;
}
