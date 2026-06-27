#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // a. In dong chu chao mung
    printf("Welcome to IT007, I am 2352xxxx!\n"); // Hãy thay 2352xxxx bằng MSSV của bạn
    fflush(stdout); // Xóa bộ đệm để đảm bảo dòng chữ được in ra ngay lập tức

    // b. Mo tep abcd.txt bang cach tao tien trinh con chay vim
    pid_t pid = fork();

    if (pid < 0) {
        // Truong hop fork that bai
        perror("Loi khi tao tien trinh con (fork failed)");
        return 1;
    } 
    else if (pid == 0) {
        // Trong tien trinh con: Su dung execl de nap va thuc thi trinh soan thao vim
        printf("Dang khoi dong trinh soan thao vim cho tep abcd.txt...\n");
        execl("/usr/bin/vim", "vim", "abcd.txt", NULL);
        
        // Neu execl chay thanh cong, no se khong bao gio chay xuong dong duoi nay
        perror("Loi thuc thi execl!");
        exit(1);
    } 
    else {
        // Trong tien trinh cha: Cho tien trinh con (vim) thuc hien va dong lai
        wait(NULL);
        printf("\nTien trinh con (vim) da ket thuc. Tien trinh cha thoat!\n");
    }

    return 0;
}