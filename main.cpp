//Lateefah Camacho 
//COMSC 210
#include <iostream>
#include <chrono>
#include <list>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;
using namespace std::chrono;

const int RUNS = 15;
const int RACES = 4;
const int STRUCTURES = 3;

// indicies
const int READING = 0;
const int SORTING = 1;
const int INSERTING = 2;
const int DELETING = 3;

// structure 
const int VECTOR = 0;
const int LIST =1;
const int SET = 2;


int main() {
  cout<< "Number of simulations: " << RUNS <<endl;
//created 3D array 
long long results[RUNS][RACES][STRUCTURES] ={0};
  // loop to run races
for (int run = 0; run < RUNS; run++) {
 // Data structures for the races
   
   vector<string> vec;
    list<string> lst;
    set<string> st;

   ifstream file ("codes.txt");
   string line;

   if (!file.is_open()) {
    cout<< "Error cannot open codes.txt\n";
      return 1;
   }
   
    
    // RACE 1: READING
    cout << "=== RACE 1: READING 20,000 ELEMENTS ===\n";
    
    // Vector reading
    auto start = high_resolution_clock::now();
   
    auto end = high_resolution_clock::now();
    results[run][READING][SET]= duration_cast<microseconds>(end - start).count();
    
    // List reading  
    file.clear();
    file.seekg(0);
    start = high_resolution_clock::now();
    while (getline(file, line)) {
        lst.push_back(line);
    }
    end = high_resolution_clock::now();
    results[run][READING][SET] = duration_cast<microseconds>(end - start).count();
    
    // Set reading
    file.clear();
    file.seekg(0);
    start = high_resolution_clock::now();
    while (getline(file, line)) {
        st.insert(line);
    }
    end = high_resolution_clock::now();
    results[run][READING][SET] = duration_cast<microseconds>(end - start).count();
    file.close();
    
    cout << "Vector: " << results[run][READING][VECTOR] << " microseconds\n";
    cout << "List: " << results[run][READING][LIST] << " microseconds\n";
    cout << "Set: " << results[run][READING][SET]<< " microseconds\n\n";
    
    // RACE 2: SORTING
    cout << "=== RACE 2: SORTING ===\n";
    // Vector sorting
    start = high_resolution_clock::now();
    sort(vec.begin(), vec.end());
    end = high_resolution_clock::now();
    results[run][SORTING][VECTOR]= duration_cast<microseconds>(end - start).count();// changing race to use array
    
    // List sorting
    start = high_resolution_clock::now();
    lst.sort();
    end = high_resolution_clock::now();
    results[run][SORTING][LIST]= duration_cast<microseconds>(end - start).count();
    
    cout << "Vector: " << results[run][SORTING][VECTOR]<< " microseconds\n";
    cout << "List: " <<  results[run][SORTING][LIST]<< " microseconds\n";
    cout <<  "Set:" <<results[run][SORTING][SET]<<"(already sorted)\n\n";
    
    // RACE 3: INSERTING
    cout << "=== RACE 3: INSERTING 'TESTCODE' ===\n";
    
    // Vector inserting in middle
    start = high_resolution_clock::now();
    auto vecIt = vec.begin();
    advance(vecIt, vec.size() / 2);
    vec.insert(vecIt, "TESTCODE");
    end = high_resolution_clock::now();
    results[run][INSERTING][VECTOR]= duration_cast<microseconds>(end - start).count();
    
    // List inserting in middle
    start = high_resolution_clock::now();
    auto lstIt = lst.begin();
    advance(lstIt, lst.size() / 2);
    lst.insert(lstIt, "TESTCODE");
    end = high_resolution_clock::now();
    results[run][INSERTING][LIST] = duration_cast<microseconds>(end - start).count();
    
    // Set inserting
    start = high_resolution_clock::now();
    st.insert("TESTCODE");
    end = high_resolution_clock::now();
    results[run][INSERTING][SET] = duration_cast<microseconds>(end - start).count();//
    
    cout << "Vector: " << results[run][INSERTING][VECTOR] << " microseconds\n";
    cout << "List: " << results[run][INSERTING][LIST]<< " microseconds\n";
    cout << "Set: " << results[run][INSERTING][SET] << " microseconds\n\n";
    
    // RACE 4: DELETING
    cout << "=== RACE 4: DELETING MIDDLE ELEMENT ===\n";
    
    // Vector deleting from middle
    start = high_resolution_clock::now();
    vecIt = vec.begin();
    advance(vecIt, vec.size() / 2);
    vec.erase(vecIt);
    end = high_resolution_clock::now();
   results[run][DELETING][VECTOR] = duration_cast<microseconds>(end - start).count();
    
    // List deleting from middle
    start = high_resolution_clock::now();
    lstIt = lst.begin();
    advance(lstIt, lst.size() / 2);
    lst.erase(lstIt);
    end = high_resolution_clock::now();
    results[run][DELETING][LIST] = duration_cast<microseconds>(end - start).count();
    
    // Set deleting (remove "TESTCODE")
    start = high_resolution_clock::now();
    st.erase("TESTCODE");
    end = high_resolution_clock::now();
    results[run][DELETING][SET] = duration_cast<microseconds>(end - start).count();
    
    cout << "Vector: " <<results[run][DELETING][VECTOR] << " microseconds\n";
    cout << "List: " << results[run][DELETING][LIST] << " microseconds\n";
    cout << "Set: " << results[run][DELETING][SET] << " microseconds\n";
    
    return 0;
   }
}
/* syntax examples:

auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/