#include <stdio.h>
#include <pthread.h>

int hack;
pthread_mutex_t hack_lock;
pthread_t hack_id[3];

void* hack_method(void *arg) {

	pthread_mutex_lock(&hack_lock);

	hack = hack + 1;
	
	printf("hello %d \n", hack);
	
	printf("hackearth %d \n", hack);
	
	pthread_mutex_unlock(&hack_lock);
	
	return NULL;
	
}

int main() {
	int h  = 0;
	int hack_error;
	
	if (pthread_mutex_init(&hack_lock, NULL) != 0) return 1;
	while(h < 3) {
		hack_error = pthread_create(&(hack_id[h]), NULL, &hack_method, NULL);
		if (hack_error != 0) printf("hack_error occured");
		h ++;
		
	}
	
	pthread_join(hack_id[0], NULL);
	pthread_join(hack_id[1], NULL);
	pthread_join(hack_id[2], NULL);
	pthread_mutex_destroy(&hack_lock);
	
	return 0;
}
