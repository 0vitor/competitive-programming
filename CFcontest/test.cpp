
#include <cmath> // Para sqrt()
#include <iostream>
#include <map>
using namespace std;

#define dbg(x) cout << #x << " " << x << endl;
map<long long, int> listarDivisoresEmMap(long long n) {
  map<long long, int> divisores;

  // Iteramos até a raiz quadrada de n
  for (long long i = 1; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      // Incrementa o contador para o divisor i
      divisores[i]++;

      // Incrementa o contador para o divisor correspondente n / i (se
      // diferente)
      if (i != n / i) {
        divisores[n / i]++;
      }
    }
  }

  return divisores;
}

int main() {
  long long numero;
  cout << "Digite um número: ";
  cin >> numero;

  map<long long, int> divisores = listarDivisoresEmMap(numero);

  cout << "Divisores de " << numero << ":\n";
  for (const auto &entry : divisores) {
    cout << "Divisor: " << entry.first << ", Valor: " << entry.second << endl;
  }

  return 0;
}
