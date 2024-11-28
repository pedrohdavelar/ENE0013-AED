#include <algorithm>
#include <list>
#include <string>
#include <chrono>

#include "grade.h"
#include "Student_info.h"

using std::max;
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

list<Student_info> extract_fails(list<Student_info>& v);

int main()
{
        list<Student_info> vs;
        Student_info s;
        string::size_type maxlen = 0;
        while (read(cin, s)) {
								cout << s.name << endl;
                maxlen = max(maxlen, s.name.size());
                vs.push_back(s);
        }

        vs.sort(compare);

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();//contagem de tempo
	list<Student_info> fails = extract_fails(vs);
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now(); //conta tempo de novo

	list<Student_info>::iterator i;


	for (i = fails.begin(); i != fails.end(); ++i)
		cout << i->name << " " << grade(*i) << endl;

		std::cout << "Processamento levou "
							<< std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
							<< " ms\n";


	return 0;
}
