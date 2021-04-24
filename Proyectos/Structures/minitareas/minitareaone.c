#include <stdio.h>
typedef struct account {
  char* username;
  double balance;
} acc; // short of account 
void transfer(acc* from, acc* to, double amount) { ////pointer of from which account the money is comming, el destino y la cantidad
  if (from->balance > amount) { //si el dinero del destino es mayor que lo que se quiere tra transferir 
    to->balance += amount; ///le sumas al que le llego el dinero 
    from->balance -= amount; /// le restas al que le dio el dinero 
    }
}
void display(acc x) {
  printf("%s, balance %.2f\n", x.username, x.balance);
}
int main() {
  acc a = {"foo", 299.0};
  acc b = {"bar", 264.0};
  acc* high = (a.balance > b.balance) ? &a : &b;
  acc* low = (a.balance < b.balance) ? &a : &b;
  double dif = high->balance - low->balance;
  transfer(high, low, dif/2);
  display(a);
  display(b);
}
