#include <unordered_map>
#include <cstdio>
#include <utility>
#include <string>
using namespace std;

typedef pair<string, int> si;

int main(){
	unordered_map<string, int> um;
	um.insert(si("holi", 2));
	um["adios"] = 1;

	auto val = um.find("wena"); //iterador al elemento, da um.end() si no existe

	if (val == um.end()) printf("no wena :(\n");

	for (auto &x : um){
		printf("%s -> %d\n", x.first.c_str(), x.second);
	}

	return 0;
}