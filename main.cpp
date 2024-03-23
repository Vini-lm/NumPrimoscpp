#include <iostream>
#include <Windows.h>

using namespace std;

#define fim cout << endl;

void vPrint(string msg, unsigned int temp)
{
    for (char a : msg)
    {
        cout << a;
        Sleep(temp);
    }
    fim
}

int CheckPrimo(unsigned int &n)
{

    // int cont = 0;    nao me lembro do porque coloquei esse contador então preferi desativa-lo até o momento
    for (unsigned int i = 2; i < n; i++)
    {

        if (n % i == 0)
        {
            // cont++;
            return i;
        }
    }

    return false;
}

void ContaPrimo(unsigned int &n)
{
    unsigned int resp = CheckPrimo(n);
    if (resp)
        cout << "Nao eh primo "
             << "Divisor " << resp << endl;
    else
        cout << "Eh primo" << endl;
}

void Gerador(unsigned int &n)
{
    n = (n * n) + n + 41;
    unsigned int resp = CheckPrimo(n);
    cout << "O numero gerado foi: " << n << " ";
    if (resp)
        cout << "Nao eh primo "
             << "Divisivel por " << resp << endl;
    else
        cout << "Eh primo" << endl;
}

int main()
{
    int n2;
    unsigned int n;

    vPrint(" Ola, este programa gera e testa numeros primos", 30);
    vPrint("Escolha uma opcao entre 1 e 2", 10);
    vPrint(" 1 -> Voce digita um numero qualquer e o programa retorna para voce o divisor dele", 10);
    vPrint("note que se o numero for primo o resultado sera (0)", 10);
    vPrint(" 2 -> Voce digita um numero qualquer e o programa aplica ele na formula que gera numeros primos", 10);
    vPrint("e ele verifica se o numero eh primo.", 10);
    vPrint("Formula (n) = (n * n) + n + 41", 10);

    cin >> n2;

    switch (n2)
    {
    case 1:
        cin >> n;
        while (n > 0)
        {
            ContaPrimo(n);
            cin >> n;
        }
        break;
    case 2:
        cin >> n;
        while (n > 0)
        {
            Gerador(n);
            cin >> n;
        }
        break;

    default:
        cout << "Opcao invalida" << endl;
        break;
    }

    return 0;
}
