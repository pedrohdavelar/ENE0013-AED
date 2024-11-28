#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <chrono>

#include "Student_info.h"
#include "grade.h"

//driver program for grade partitioning examples

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;
using std::max;

vector<Student_info> extract_fails(vector<Student_info>& v);

int main()
{
        vector<Student_info> vs;
        Student_info s;
        string::size_type maxlen = 0;
        while (read(cin, s)) {
                maxlen = max(maxlen, s.name.size());
                vs.push_back(s);
        }

        sort(vs.begin(), vs.end(), compare);

        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();//contagem de tempo
	      vector<Student_info> fails = extract_fails(vs);
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now(); //conta tempo de novo

        for (int i = 0; i < fails.size(); ++i)
      		cout << fails[i].name << " " << grade(fails[i]) << endl;

        std::cout << "Processamento levou "
                    << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
                    << " milisegundos\n";


      	return 0;
}
