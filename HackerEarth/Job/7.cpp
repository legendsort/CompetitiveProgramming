#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define hack 3

pthread_mutex_t lock;

struct data {
	int thread_id;
	char *msg;	
};

void *Disp(void *th) {
	struct data *val;
	val = (struct data *) th;
	
	pthread_mutex_lock(&lock);
	cout << "Message: "<<val->msg<<endl;
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);	
}


int main() {
	pthread_t threads[hack];
	data td[hack];
	int rc;
	pthread_mutex_init(&lock, NULL);
	
	for(int i=0; i<hack; i++) {
		td[i].thread_id = i;
		td[i].msg = "Just !";
		rc = pthread_create(&threads[i], NULL, Disp, (void *)&td[i]);
		if(rc) {
			cout << "Error:unable to create thread," << rc << endl;
			exit(0);
		}
	}
	for(int i=0; i<hack; i++) {
		pthread_join(threads[i], NULL);
	}
	pthread_mutex_destroy(&lock);
	
}



