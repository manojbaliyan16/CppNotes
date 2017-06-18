#include <stdio.h>
#include <pthread.h>
static volatile int balance =0;
pthread_mutex_t myMutex;
void *Deposit(void * arg)
{
  char* who=arg;
  int i;
  printf("%s, Begin \n", who  );
  for(i=0;i<1000000;i++)
  {
    // critical section
    pthread_mutex_lock(&myMutex);
    balance+=1;
    pthread_mutex_unlock(&myMutex);
  }
  printf("%s done\n",who);
  return NULL;
}

int main()
{
  pthread_t p1,p2;
  printf("main() starts depositing the balance\n");
  pthread_mutex_init(&myMutex,0);
  pthread_create(&p1, NULL, Deposit, "A");
  pthread_create(&p2, NULL, Deposit, "B");
  pthread_join(p1, NULL);
  pthread_join(p2, NULL);
  pthread_mutex_destroy(&myMutex);

  printf("Thread A and B Finished and Balance is =%d\n",balance);

}
//output coming is =1672014 so we need to make balance updating code as critical section 