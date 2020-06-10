// put comments describing the program here
//Sabrina Xiao 
//Partner: None
//Lab Section: 031
//Date submitted: 3/22/20
#include <iostream>
using namespace std;

int main() {
  // your code here to implement Project 4
  //prompt for user input 
  double v0, c_d, runwayLength;
  cout << "v0 (m/s): ";
  //saving the input for v0
  cin >> v0;
  cout << "c_d (1/m): ";
  //saving the input for c_d
  cin >> c_d;
  cout << "runwayLength (m): ";
  //saving the input for runwayLength
  cin >> runwayLength;
  double bMin, bMax,bMid;
  //finding the first range from 0 to bNoDrag
  bMin = 0;
  bMax = (v0 * v0)/ (2* runwayLength);
  //initializing bMid
  bMid = (bMax + bMin)/2;
  while (bMax - bMin > 0.000001){
      //updating bMid as midpoint
      bMid = (bMax + bMin)/2;
      //initializing distance and velocity
      double distance = 0;
      double velocity = v0;
      double t = 0.00001;
      while(velocity > 0){
          //updating equations
          double vOld = velocity;
          double xOld = distance;
          double aOld = -bMid - c_d * (vOld * vOld);
          double vNew = vOld + aOld * t;
          double xNew = xOld + vOld * t;
          //updating velocity and distance variables
          velocity = vNew;
          distance = xNew;
      }
      //comparing simDist to runwayLength and changing ranges
      if(distance < runwayLength){
          bMax = bMid;
      }
      else{
          bMin = bMid;
      }
  }
  cout << "b_optimal = " << (bMax + bMin)/2. << endl;
  return 0;
}