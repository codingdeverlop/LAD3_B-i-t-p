#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_func(void* arg) {
    printf("Tieu trinh dang chay o trang thai DETACHED...\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_attr_t attr; // Khai bao bien thuoc tinh

    // 1. Khoi tao thuoc tinh mac dinh
    pthread_attr_init(&attr);

    // 2. Thay doi trang thai thuoc tinh sang DETACHED (khong can join)
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    // 3. Tao thread voi tap thuoc tinh da thay doi
    if (pthread_create(&thread, &attr, thread_func, NULL) != 0) {
        printf("Loi tao tieu trinh!\n");
        return 1;
    }

    // 4. Huy bien thuoc tinh sau khi su dung xong de tranh ro ri bo nho
    pthread_attr_destroy(&attr);

    printf("Main thread khong can goi pthread_join(). ngu 1 giay cho thread con in xong.\n");
    sleep(1); 

    return 0;
}