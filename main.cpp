//Dr_T Unit 2 COSC-1437 Starter 
/* Task -

Top level solution folder: C_STL_Library_KC

create a single main.cpp that contains code samples and implementations of each of the following topics */

#include <iostream>
#include <vector>
#include <algorithm> 
#include <cassert>
#include <stack>
#include <set>
#include <utility>
#include <map>
#include <string>
using namespace std; 

typedef map<string, int> MapT;
typedef MapT::const_iterator MapIterT;

//Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/ clarifications added
class MyClassVector1 
{ 
  private:  
      vector<int> vec; 
  public: 
      MyClassVector1 (vector<int> v)  //parameterized constructor
      { 
        vec = v; 
      } 
      void print() 
      { 
          /// print the value of vector 
          for (int i = 0; i < vec.size(); i++) 
          {
              cout << vec[i] << " "; 
          }    
      } 
};
//std::count_if and predicate object
//declaring a predicate object before its used
bool less_than_7( int value )
{
  return value < 7;
}


int main(int argc, char* argv[]) 
{
    /****Section_Name***Vectors*/ 
    //Write the base code for: 5. std::vector example
    vector<double> vd; //vd elments are floating point numbers
    vector<int> vi; //vi elements are integer numbers 
    vector<string> vs; //vs elements are string objects 

    //Expand this code to:

    //add 3 elements to the vd vector
    vd.push_back(1);
    vd.push_back(2);
    vd.push_back(3);
    vd.push_back(55.4); 
    vd.push_back(100.5);
    vd.push_back(69.4);
    vd.push_back(420.69);

    //add 3 elements to the vi vector

    vi.push_back(1);
    vi.push_back(7);
    vi.push_back(3);

   // add 3 elements to the vs vector
    vs.push_back("Kaizoku");
    vs.push_back("Oo ni");
    vs.push_back("Ore Wa Naru!");

   // display the 3 elements in the vd vector
   cout << "\nValues in vd: \n"; 
   for(double vals : vd)
   {
     cout << vals << endl; 
   }
   cout << "\nAnother way to print vector: " << endl; 
   for(int i = 0; i < vd.size(); i++)
   {
     cout << vd[i] << endl; 
   }

    //display the 3 elements in the vi vector
    cout << "\nValues in vi: \n";
    for(int vals : vi)
      {
        cout << vals << endl;
      }
    cout << "\nAnother way to print vector: " << endl;
    for(int i = 0; i < vi.size(); i++)
      {
        cout << vi[i] << endl;
      }

   // display the 3 elements in the vs vector
  cout << "\nValues in vs: \n";
  for(string vals : vs)
    {
      cout << vals << endl;
    }
  cout << "\nAnother way to print vector: " << endl;
  for(int i = 0; i < vs.size(); i++)
    {
      cout << vs[i] << endl;
    }

    /****Section_Name***Vector_as_Class_Member*/ 
    //Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/

   cout << "\nVector_as_Class_Member" << endl; 
    vector<int> vec; 
        for (int i = 1; i <= 5; i++) 
            vec.push_back(i); 
        MyClassVector1 obj(vec); 
        obj.print(); 
      
      //Continue with MyClassVector2 and MyClassVector3

    /****Section_Name***STL_Iterators*/ 
  vector< int > vint(10); //vector with 10 integers
  vint[0] = 10;
  vint[1] = 20;
  vint[2] = 30;
  vint[3] = 40;
  vint[4] = 50;
  vint[5] = 60;
  vint[6] = 70;
  vint[7] = 80;
  vint[8] = 90;
  vint[9] = 100;

  //Display elements of the vector:
  vector< int >::iterator it;
  for( it = vint.begin(); it != vint.end(); it++)
    {
      //Like pointer, iterator is dereferenced to access the value of the element pointed by it:
      cout << " " << *it << endl;
    }
    

    /****Section_Name*** Stack*/

  stack< int > st;

  st.push( 100 ); //push number on the stack
  assert( st.size() == 1 ); //verify one element is on the stack
  assert( st.top() == 100 ); //verify element value

  st.top() = 456; // assign a new top
  assert( st.top() == 456 );

  st.pop(); // remove top
  assert( st.empty() == true );
  

    /****Section_Name**** Set*/
    //Write the code as presented in: 3. std::set

  set<int> iset; // set of unique integer numbers

  iset.insert( 11 ); // populate set with some values
  iset.insert( -11 );
  iset.insert( 55 );
  iset.insert( 22 );
  iset.insert( 22 );
  if( iset.find( 55 ) != iset.end() ) // is value already stored?
  {
    iset.insert( 55 );
  }
  assert( iset.size() == 4 ); // sanity check
  set<int>::iterator it2;
  for( it2 = iset.begin(); it2 != iset.end(); it2++)
    {
      cout << " " << *it2 << endl;
    }
  

    //Write comments that help one better understand what the code is doing.

    /****Section_Name****Pair_Structure*/
    //Write the code as presented in: 4. std::pair structure

  pair< string, string > strstr;
  strstr.first = "Hello";
  strstr.second = "World";

  pair< int, string > intstr;
  intstr.first = 1;
  intstr.second = "one";

  pair< string, int > strint( "two", 2 );
  assert( strint.first == "two" );
  assert( strint.second == 2 );

    /****Section_Name**** Map_Insert*/
    //Write the code as presented in: 14. std::map::insert
  MapT amap;
  pair< MapIterT, bool > result = amap.insert( make_pair( "Fred", 45 ) );

  assert( result.second == true );
  assert( result.first->second == 45 );

  result = amap.insert( make_pair( "Fred", 54 ) );
  //fred was already in the map, and result.first simply points there now:
  assert( result.second == false );
  assert( result.first->second == 45 );


    /****Section_Name****Map_Summary*/
    //Write the code as presented in: 16. Map summary

    map< string, string > phone_book;
  phone_book[ "411" ] = "Directory"; //adds a new element
  phone_book[ "911" ] = "Emergency"; //adds another element called Emergency
  phone_book[ "508-678-2811" ] = "BCC";
  if( phone_book.find("411") != phone_book.end() ){
    phone_book.insert( make_pair(string("411"), string("Directory")) );
  }
  assert( phone_book.size() == 3 );
  map< string, string >::const_iterator it3;
  for( it3 = phone_book.begin(); it3 != phone_book.end(); ++it3 ){
    cout 
      << " " << it3->first 
      << " " << it3->second 
      << endl;
  }

    /****Section_Name**** Sort_Algorithm*/
    //Write the code as presented in: 23. sort example

  int arr[ 100 ];
  sort( arr, arr + 100 );
  vector< int > v1; //instanciate an empty vector
  sort( v1.begin(), v1.end() );

    /****Section_Name****Predicate_Algorithm*/
    //Write the code as presented in: 25. count_if and predicate function

  vector< int > v2; //Fill v2 with some values
  int count_less = count_if( v2.begin(), v2.end(), less_than_7);

      return 0; 
 }