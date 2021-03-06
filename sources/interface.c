#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "../headers/interface.h"

void MSG_MENU() {
    printf("\n\n\tMENU");
    printf("\n\n\t1. M�DULO 1 - GERENCIAMENTO DE USUARIOS");
    printf("\n\t2. M�DULO 2 - GERENCIAMENTO DE AMIZADES");
    printf("\n\t3. M�DULO 3 - DEBUG");
    printf("\n\t4. SAIR");
}

void MSG_SUBMENU_0(int module_number) {
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    printf("\n\n\tM�DULO %d", module_number);
    printf("\n\n\t1. CADASTRAR");
    printf("\n\t2. PESQUISAR");
    printf("\n\t3. ALTERAR");
    printf("\n\t4. EXCLUIR");
    printf("\n\t5. IMPRIMIR");
    printf("\n\t6. SAIR");
}

void MSG_SUBMENU_1(int module_number) {
    setlocale(LC_ALL, "Portuguese");

    system("cls");

    printf("\n\n\tM�DULO %d", module_number);
    printf("\n\n\t1. FAZER AMIZADE");
    printf("\n\t2. PROCURAR USU�RIO MAIS POPULAR");
    printf("\n\t3. VERIFICAR AMIZADE");
    printf("\n\t4. DELETAR AMIZADE");
    printf("\n\t5. IMPRIMIR AMIGOS");
    printf("\n\t6. CONTAR AMIGOS EM COMUM");
    printf("\n\t7. PROCURAR USU�RIOS SOLIT�RIOS");
    printf("\n\t8. PROCURAR AMIGO EM COMUM");
    printf("\n\t9. PROCURAR AMIGOS EM COMUM");
}

void MSG_DEBUG_MENU(int module_number) {
    setlocale(LC_ALL, "Portuguese");

    system("cls");

    printf("\n\n\tM�DULO %d", module_number);
    printf("\n\n\t1. Procurar e Imprimir");
    printf("\n\t2. Mostrar Matriz de Relacionamentos");
    printf("\n\t3. Mostrar IDs no Array de Usu�rios");
    printf("\n\t4. Gerar usu�rios aleat�rios");
    printf("\n\t5. Gerar Matriz de Relacionamentos");
    printf("\n\t6. Gerar Matriz de Amizades em Comum");
    printf("\n\t7. Imprimir Matriz de Amizades em Comum");
}

void main_menu(tsocmed *net, tuser user) {
    setlocale(LC_ALL, "Portuguese");

    int option = 0;

    do {
        system("cls");
        MSG_MENU();
        printf("\n\nDigite uma op��o: ");
        fflush(stdin);
        scanf("%d", &option);

        switch (option) {
            case 1:
                MSG_SUBMENU_0(option);
                submenu_0(net, user);
                break;
            case 2:
                MSG_SUBMENU_1(option);
                submenu_1(net, user);
                break;
            case 3:
                MSG_DEBUG_MENU(option);
                debug_menu(net, user);
                break;
            default:
                system("cls");
                printf("\n\n\n\tMSG: DIGITE UMA OP��O V�LIDA.\n");
                fflush(stdin);
                system("PAUSE");
        }
    } while (option != 4);
}

void submenu_0(tsocmed *net, tuser user) {
    setlocale(LC_ALL, "Portuguese");

    int option;

    printf("\n\nDigite uma op��o: ");
    fflush(stdin);
    scanf("%d", &option);

    switch (option) {
        case 1:
            system("cls");
            reg(net, user);
            break;
        case 2:
            system("cls");
            printf("\nDigite o nome do usu�rio: ");
            fflush(stdin);
            fgets(user.name, 100, stdin);
            findone(*net, user);
            system("PAUSE");
            break;
        case 3:
            system("cls");
            printf("\nDigite o ID do usu�rio que deseja alterar: ");
            int update_id;
            scanf("%d", &update_id);
            read(&user);
            update(net, user, update_id);
            break;
        case 4:
            system("cls");
            printf("\nDigite o ID do usu�rio que deseja excluir: ");
            int delete_id;
            scanf("%d", &delete_id);
            delete(net, delete_id);
            break;
        case 5:
            system("cls");
            printf("\nDigite o ID do usu�rio que deseja imprimir: ");
            int id_print;
            scanf("%d", &id_print);
            prtuser(finduser(*net, id_print));
            system("PAUSE");
            break;
        case 6:
            system("cls");
            printf("Exiting program...\n");
            system("PAUSE");
            break;
        default:
            system("cls");
            printf("\n\n\n\t MSG: DIGITE UMA OP��O V�LIDA.\n");
            fflush(stdin);
            system("PAUSE");
    }
}

void submenu_1(tsocmed *net, tuser user) {
    setlocale(LC_ALL, "Portuguese");

    int option;
    int user_id_0, user_id_1;

    printf("\n\nDigite uma op��o: ");
    fflush(stdin);
    scanf("%d", &option);

    switch (option) {
        case 1:
            system("cls");
            printf("\nDigite o ID do primeiro usu�rio: ");
            scanf("%d", &user_id_0);
            printf("\nDigite o ID do primeiro usu�rio: ");
            scanf("%d", &user_id_1);
            make_friendship(net, user_id_0, user_id_1);
            printf("\nAMIZADE CONCLU�DA COM SUCESSO\n");
            system("PAUSE");
            break;
        case 2:
            system("cls");
            printf("\nO usu�rio mais popular � o de ID: %d\n", find_popular(*net));
            system("PAUSE");
            break;
        case 3:
            system("cls");
            char name_0[100], name_1[100];

            printf("\nDigite o primeiro nome: ");
            fflush(stdin);
            fgets(name_0, 100, stdin);

            printf("\nDigite o segundo nome: ");
            fflush(stdin);
            fgets(name_1, 100, stdin);
            if (verfrdshp(*net, name_0, name_1)) {
                printf("\nOs usu�rios s�o amigos\n");
            } else {
                printf("\nos usu�rios n�o s�o amigos\n");
            }
            system("PAUSE");
            break;
        case 4:
            system("cls");
            printf("\nDigite o ID do primeiro usu�rio: ");
            scanf("%d", &user_id_0);
            printf("\nDigite o ID do primeiro usu�rio: ");
            scanf("%d", &user_id_1);
            delfrd(net, user_id_0, user_id_1);
            printf("\nAMIZADE DELETADA COM SUCESSO\n");
            system("PAUSE");
            break;
        case 5:
            system("cls");
            int prtfrds_id;
            printf("\nDigite o ID do usu�rio: ");
            fflush(stdin);
            scanf("%d", &prtfrds_id);
            prtfrds(*net, finduser(*net, prtfrds_id));
            system("PAUSE");
            break;
        case 6:
            system("cls");
            printf("\nDigite o ID do primeiro usu�rio: ");
            scanf("%d", &user_id_0);
            printf("\nDigite o ID do primeiro usu�rio: ");
            scanf("%d", &user_id_1);
            printf("\nOs usu�rios com ID de %d e %d tem %d amigos em comum.\n",
                   user_id_0,
                   user_id_1,
                   find_mutual_friends(*net, user_id_0, user_id_1)
            );
            system("PAUSE");
            break;
        case 7:
            system("cls");
            fndsol(net);
            system("PAUSE");
            break;
        case 8:
            system("cls");
            printf("\nDigite o ID do primeiro usu�rio: ");
            scanf("%d", &user_id_0);
            printf("\nDigite o ID do primeiro usu�rio: ");
            scanf("%d", &user_id_1);
            printf("\nOs usu�rios com ID de %d e %d tem o usu�rio com ID %d como amigo em comum.\n",
                   user_id_0,
                   user_id_1,
                   fndrel(*net, user_id_0, user_id_1)
            );
            system("PAUSE");
            break;
        case 9:
            system("cls");
            printf("\nO ID dos usu�rios tem que ter 3 unidades de dist�ncia, ex: 1 e 4.\n");
            printf("\nDigite o ID do primeiro usu�rio: ");
            scanf("%d", &user_id_0);
            printf("\nDigite o ID do primeiro usu�rio: ");
            scanf("%d", &user_id_1);
            int *relp = fndrelp(*net, user_id_0, user_id_1);

            if(relp == NULL) {
                printf("\nOcorreu um erro, tente novamente\n");
                system("PAUSE");
                break;
            }

            printf("\nOs usu�rios com ID de %d e %d t�m os usu�rios com ID %d e %d como amigos em comum.\n",
                   user_id_0,
                   user_id_1,
                   relp[0],
                   relp[1]
            );
            system("PAUSE");
            break;
        default:
            system("cls");
            printf("\n\n\n\t MSG: DIGITE UMA OP��O V�LIDA.\n");
            fflush(stdin);
            system("PAUSE");
    }
}

void debug_menu(tsocmed *net, tuser user) {
    setlocale(LC_ALL, "Portuguese");

    int option;

    printf("\n\nDigite uma op��o: ");
    fflush(stdin);
    scanf("%d", &option);

    switch (option) {
        case 1:
            system("cls");
            printf("\nDigite um ID: ");
            int ID;
            fflush(stdin);
            scanf("%d", &ID);
            debug_fndprt(*net, ID);
            system("PAUSE");
            break;
        case 2:
            system("cls");
            debug_matver(*net);
            system("PAUSE");
            break;
        case 3:
            system("cls");
            debug_shwarr(*net);
            system("PAUSE");
            break;
        case 4:
            system("cls");
            debug_regrandom(net);
            printf("\nUsu�rios gerados aleatoriamente\n");
            system("PAUSE");
            break;
        case 5:
            system("cls");
            debug_matrandom(net);
            printf("\nMatriz de Relacionamentos inicializada com valores aleat�rios\n");
            system("PAUSE");
            break;
        case 6:
            system("cls");
            fill_gntdmat(net);
            system("PAUSE");
            break;
        case 7:
            system("cls");
            debug_prt_gntdmat(*net);
            system("PAUSE");
            break;
        default:
            system("cls");
            printf("\n\n\n\t MSG: DIGITE UMA OP��O V�LIDA.\n");
            fflush(stdin);
            system("PAUSE");
    }
}