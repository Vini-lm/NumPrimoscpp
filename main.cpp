#include <iostream>
#include <Windows.h>
#include <cmath>

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

const bool CheckNumPerfeitov1(int &n)
{

    int *Divisores = new int[n];
    int Cont = 1;
    int Soma = 0;

    for (int i = 0; i < n; i++)
    {
        Divisores[i] = 0;
    }

    Divisores[0] = 1;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            Divisores[Cont++] = i;
    }

    for (int i = 0; i < Cont; i++)
        Soma += Divisores[i];

    if (Soma == n)
        return true;

    delete[] Divisores;

    return false;
}

void CheckNumPerfeitov2(unsigned int &n)
{

    int soma = 0;
    bool resp = false;

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            soma += i;
    }
    if (soma == n)
        resp = true;

    if (resp == true)
        cout << "Eh um numero perfeito" << endl;
    else
        cout << "Nao eh um numero perfeito" << endl;
}

bool CheckNPerfeito(unsigned int &n)
{
    int soma = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            soma += i;
        if (soma > n)
            return false;
    }

    if (soma == n)
        return true;

    return false;
}

void GeradorNumPerfeito(unsigned int &n)
{
    n = pow(2, n - 1) * (pow(2, n) - 1);
    bool resp = CheckNPerfeito(n);
    cout << "Numero perfeito gerado -> " << n << endl;

    if (resp)
        cout << "Eh perfeito" << endl;
    else
        cout << "Nao eh perfeito" << endl;
}

int main()
{
    int n2;
    unsigned int n;
    int n3;

    vPrint(" Ola, este programa gera e testa numeros primos", 10);
    vPrint("Escolha uma opcao entre 1 e 2", 1);
    vPrint(" 1 -> Voce digita um numero qualquer e o programa retorna para voce o divisor dele", 5);
    vPrint("note que se o numero for primo o resultado sera (0)", 5);
    vPrint(" 2 -> Voce digita um numero qualquer e o programa aplica ele na formula que gera numeros primos", 5);
    vPrint("e ele verifica se o numero eh primo.", 5);
    vPrint("Formula (n) = (n * n) + n + 41", 5);
    vPrint("Para fechar o programa apenas digite algum numero menor ou igual a 0", 5);

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

    case 3:
        cin >> n;
        while (n > 0)
        {
            CheckNumPerfeitov2(n);
            cin >> n;
        }
        break;

    case 4:
        cin >> n;
        while (n > 0)
        {
            GeradorNumPerfeito(n);
            cin >> n;
        }

    default:
        cout << "Opcao invalida" << endl;
        break;
    }

    return 0;
}
