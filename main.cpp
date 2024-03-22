#include <iostream>
#include <chrono>
#include <Windows.h>

using namespace std;



void vPrint(string msg, unsigned int temp)
{
    for (char a : msg)
    {
        cout << a;
        Sleep(temp);
    }
}

int CheckPrimo( unsigned int n)
{

    int cont = 0;
    for (unsigned int i = 2; i < n; i++)
    {

        if (n % i == 0)
        {
            cont++;
            return i;
        }
    }

    return false;
}

void ContaPrimo(int n)
{
    cout << CheckPrimo(n) << endl;
}

void Gerador(int n)
{
    n = (n * n) + n + 41;
    unsigned int teste = CheckPrimo(n);
    cout << "O numero gerado foi: " << n << " ";
    if (teste)
        cout << "Nao eh primo " << "Divisivel por " << teste <<endl;
    else
        cout << "Eh primo" << endl;
}

int main()
{
    int n, n2;
    vPrint(" Ola, este programa gera e testa numeros primos",70);
    cout << endl;
    vPrint("Escolha uma opcao entre 1 e 2",30);
    cout << endl;
    vPrint(" 1 -> Voce digita um numero qualquer e o programa retorna para voce o divisor dele",30);
    cout << endl;
    vPrint("note que se o numero for primo o resultado sera (0)",30);
    cout << endl;
    vPrint(" 2 -> Voce digita um numero qualquer e o programa aplica ele na formula que gera numeros primos",3); 
    cout << endl;
    vPrint("e ele verifica se o numero eh primo.",30);
    cout << "Formula (n) = (n * n) + n + 41" << endl;
   

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
        cout << "Opcao invalida, digite um numero entre 1 e 2" << endl;
        cin >> n2;
    }
    return 0;
}
