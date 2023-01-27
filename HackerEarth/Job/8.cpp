#include <bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;

string str;

void* hack_func(void*) {
	sleep(1);
	cout << "Created hild" << str << endl;
}


int main() {
	pthread_t t[4];
	
	for(int i=0; i<4; i++) {
		cout << "Create_>"<<i<<' '<<endl;
		pthread_create(&t[i], NULL, &hack_func, NULL);
		pthread_detach(t[i]);
	}
	exit(EXIT_SUCCESS);
	return 0;
}



