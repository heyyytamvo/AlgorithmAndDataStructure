#include <iostream>
#include <set>
using namespace std;

int main() {
   int n;
   set<unsigned> prices;
   set<unsigned>::iterator best_buy_idx;
   unsigned sell_price, minimum_loss = 1e9;

   cin >> n;

   for (int i = 0; i < n; i++) {
      cin >> sell_price;
      best_buy_idx = prices.upper_bound(sell_price);
      if (best_buy_idx != prices.end()) {
         unsigned loss = *best_buy_idx - sell_price;
         minimum_loss = min(loss, minimum_loss);
      }
      prices.insert(sell_price);
   }

   cout << minimum_loss;
   return 0;
}
