#include <iostream>

using namespace std;

int CheckPrimo(int n)
{

    int cont = 0;
    for (int i = 2; i < n; i++)
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
    cout << "O numero gerado foi: " << n << " ";
    if (CheckPrimo(n))
        cout << "N�o eh primo" << endl;
    else
        cout << "Eh primo" << endl;
}

int main()
{
    int n, n2;
    cout << "Escolha uma opcao entre 1 e 2" << endl;
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
