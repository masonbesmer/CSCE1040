#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int SCORES_SIZE = 4;
   vector<int> oldScores(SCORES_SIZE);
   vector<int> newScores(SCORES_SIZE);
   unsigned int i;

   for (i = 0; i < oldScores.size(); ++i) {
      cin >> oldScores.at(i);
   }

   //check if two vectors have same values without if statements
    if (oldScores == newScores) {
        cout << "The two vectors are the same." << endl;
   
    
    
    for (i = 0; i < oldScores.size() - 1; ++i) {
        newScores.at(i) = oldScores.at(i + 1);
    }

   for (i = 0; i < newScores.size(); ++i) {
      cout << newScores.at(i) << " ";
   }
   cout << endl;

   return 0;
}