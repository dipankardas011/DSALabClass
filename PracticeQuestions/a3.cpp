/*
find the largest rectangular are possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. for simplicity assume that all bars have same width and the width is 1 unit for eg. consider the following histogram with 7 bars of height {6, 2, 5, 4, 5, 1, 6} the largest possibe rectangle is 12

  |6           6
  |*   5   5   *
  |*   * 4 *   *
  |*   $ $ $   *
  |* 2 $ * $   *
  |* * $ * $ 1 *
  |* * $ $ $ * *
  +------------+
*/

// using O(N*N)
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
  vector<int> BuldingsH = {6, 2, 5, 4, 5, 1, 6};

  int Maxarea = 0;
  // we are going to use the min maths function
  for (int i = 0; i < BuldingsH.size(); i++)
  {
    int max = 0;
    int NoOfBuildings = 0,
        NoOfHeightMAX = 0;
    int curr = BuldingsH.at(i);
    for (int j = i + 1; j < BuldingsH.size(); j++)
    {
      curr = std::min(curr, BuldingsH.at(j));
      if (curr > max)
      {
        NoOfBuildings = 1;
        max = curr;
        NoOfHeightMAX = max;
        // count = 1;
      }
      if (curr == max)
        NoOfBuildings++;
    }
    // cout << "No of Buildings: " << NoOfBuildings << " | "
    //      << "Max Height: " << NoOfHeightMAX << endl;
    if(Maxarea < NoOfBuildings*NoOfHeightMAX)
      Maxarea = NoOfBuildings*NoOfHeightMAX;
  }
  cout<<"Max Area: "<<Maxarea<<endl;
  return 0;
}
