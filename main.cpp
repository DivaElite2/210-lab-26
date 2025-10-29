#include <iostream>
#include <chrono>
#include <list>
#include <set>
#include <fstream>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int main() {
    // Data structures for the races
    vector<string> vec;
    list<string> lst;
    set<string> st;
    
    // RACE 1: READING
    cout << "=== RACE 1: READING 20,000 ELEMENTS ===\n";
    
    // Vector reading
    auto start = high_resolution_clock::now();
    ifstream file("data.txt");
    string line;
    while (getline(file, line)) {
        vec.push_back(line);
    }
    auto end = high_resolution_clock::now();
    auto vecReadTime = duration_cast<microseconds>(end - start);
    
    // List reading  
    file.clear();
    file.seekg(0);
    start = high_resolution_clock::now();
    while (getline(file, line)) {
        lst.push_back(line);
    }
    end = high_resolution_clock::now();
    auto lstReadTime = duration_cast<microseconds>(end - start);
    
    // Set reading
    file.clear();
    file.seekg(0);
    start = high_resolution_clock::now();
    while (getline(file, line)) {
        st.insert(line);
    }
    end = high_resolution_clock::now();
    auto setReadTime = duration_cast<microseconds>(end - start);
    file.close();
    
    cout << "Vector: " << vecReadTime.count() << " microseconds\n";
    cout << "List: " << lstReadTime.count() << " microseconds\n";
    cout << "Set: " << setReadTime.count() << " microseconds\n\n";
    
    // RACE 2: SORTING
    cout << "=== RACE 2: SORTING ===\n";
    
    // Vector sorting
    start = high_resolution_clock::now();
    sort(vec.begin(), vec.end());
    end = high_resolution_clock::now();
    auto vecSortTime = duration_cast<microseconds>(end - start);
    
    // List sorting
    start = high_resolution_clock::now();
    lst.sort();
    end = high_resolution_clock::now();
    auto lstSortTime = duration_cast<microseconds>(end - start);
    
    cout << "Vector: " << vecSortTime.count() << " microseconds\n";
    cout << "List: " << lstSortTime.count() << " microseconds\n";
    cout << "Set: -1 (already sorted)\n\n";
    
    // RACE 3: INSERTING
    cout << "=== RACE 3: INSERTING 'TESTCODE' ===\n";
    
    // Vector inserting in middle
    start = high_resolution_clock::now();
    auto vecIt = vec.begin();
    advance(vecIt, vec.size() / 2);
    vec.insert(vecIt, "TESTCODE");
    end = high_resolution_clock::now();
    auto vecInsertTime = duration_cast<microseconds>(end - start);
    
    // List inserting in middle
    start = high_resolution_clock::now();
    auto lstIt = lst.begin();
    advance(lstIt, lst.size() / 2);
    lst.insert(lstIt, "TESTCODE");
    end = high_resolution_clock::now();
    auto lstInsertTime = duration_cast<microseconds>(end - start);
    
    // Set inserting
    start = high_resolution_clock::now();
    st.insert("TESTCODE");
    end = high_resolution_clock::now();
    auto setInsertTime = duration_cast<microseconds>(end - start);
    
    cout << "Vector: " << vecInsertTime.count() << " microseconds\n";
    cout << "List: " << lstInsertTime.count() << " microseconds\n";
    cout << "Set: " << setInsertTime.count() << " microseconds\n\n";
    
    // RACE 4: DELETING
    cout << "=== RACE 4: DELETING MIDDLE ELEMENT ===\n";
    
    // Vector deleting from middle
    start = high_resolution_clock::now();
    vecIt = vec.begin();
    advance(vecIt, vec.size() / 2);
    vec.erase(vecIt);
    end = high_resolution_clock::now();
    auto vecDeleteTime = duration_cast<microseconds>(end - start);
    
    // List deleting from middle
    start = high_resolution_clock::now();
    lstIt = lst.begin();
    advance(lstIt, lst.size() / 2);
    lst.erase(lstIt);
    end = high_resolution_clock::now();
    auto lstDeleteTime = duration_cast<microseconds>(end - start);
    
    // Set deleting (remove "TESTCODE")
    start = high_resolution_clock::now();
    st.erase("TESTCODE");
    end = high_resolution_clock::now();
    auto setDeleteTime = duration_cast<microseconds>(end - start);
    
    cout << "Vector: " << vecDeleteTime.count() << " microseconds\n";
    cout << "List: " << lstDeleteTime.count() << " microseconds\n";
    cout << "Set: " << setDeleteTime.count() << " microseconds\n";
    
    return 0;
}
/* syntax examples:

auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/