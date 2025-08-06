#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

// Create a student data structure
struct sinhvien {
    char studentcode[200];
    char fullname[200];
    float coursescore;
};

int main() {
    // Create a dynamic array and enter a list of students
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar(); // xoa bo nho dem

    struct sinhvien* sv = (struct sinhvien*)malloc(n * sizeof(struct sinhvien));

    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);

        printf("Ma sinh vien: ");
        fgets(sv[i].studentcode, sizeof(sv[i].studentcode), stdin);
        sv[i].studentcode[strcspn(sv[i].studentcode, "\n")] = '\0'; // xoa \n

        printf("Ho ten: ");
        fgets(sv[i].fullname, sizeof(sv[i].fullname), stdin);
        sv[i].fullname[strcspn(sv[i].fullname, "\n")] = '\0';

        printf("Diem hoc phan: ");
        scanf("%f", &sv[i].coursescore);
        getchar(); // xoa \n sau scanf
    }

    // Print a list of students with the highest course score
    float maxscore = sv[0].coursescore;
    for (int i = 1; i < n; i++) {
        if (sv[i].coursescore > maxscore) {
            maxscore = sv[i].coursescore;
        }
    }

    printf("\nDanh sach sinh vien co diem cao nhat (%.2f):\n", maxscore);
    for (int i = 0; i < n; i++) {
        if (sv[i].coursescore == maxscore) {
            printf("Ma SV: %s, Ho ten: %s, Diem: %.2f\n", sv[i].studentcode, sv[i].fullname, sv[i].coursescore);
        }
    }

    // Print the largest deviation of the component score
    float chenhLechmax = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            float chenh = fabs(sv[i].coursescore - sv[j].coursescore);
            if (chenh > chenhLechmax) {
                chenhLechmax = chenh;
            }
        }
    }

    printf("\nDo lech diem lon nhat giua cac sinh vien la: %.2f\n", chenhLechmax);

    free(sv);
    return 0;
}

