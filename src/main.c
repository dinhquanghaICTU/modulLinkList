#include "modulLinkList.h"
#include <string.h>

typedef enum
{
    SV_THUONG,
    SV_TRAODOI,
    SV_THUCTAP
} LoaiSinhVien;

typedef struct
{
    char country[30];
} traodoi_t;

typedef struct
{
    char company[20];
    char ngHuongDan[20];
} thuctap_t;

typedef union
{
    traodoi_t trade;
    thuctap_t intern;
} thongtin_t;

typedef struct
{
    float diem;
    thongtin_t u_info;
    int id;
    char name[30];
    LoaiSinhVien loai;
} SinhVien;


void printSinhVien(void *data)
{
    SinhVien *sv = (SinhVien *)data;
    printf("ID %d,  Ten %s , Diem: %.2f ", sv->id, sv->name, sv->diem);

    switch (sv->loai)
    {
    case SV_THUONG:
        printf("Thuong\n");
        break;
    case SV_TRAODOI:
        printf(" trao doi, quoc gia: %s\n", sv->u_info.trade.country);
        break;
    case SV_THUCTAP:
        printf("thuc tap, Cong ty: %s, Huong dan: %s\n",
               sv->u_info.intern.company,
               sv->u_info.intern.ngHuongDan);
        break;
    }
}

int main()
{
    /*LinkedList list;
    initList(&list);

    SinhVien sv1 = {8.5, .u_info = {0}, 1, "A", SV_THUONG};
    SinhVien sv2 = {7.8, .u_info.trade = 
        {"Viet Nam"}, 2, "B", SV_TRAODOI};
    SinhVien sv3 = {9.1, .u_info.intern = 
        {"Hunonic", "Anh Dung"}, 3, "Ha", SV_THUCTAP};
    SinhVien sv4 = {9.0, .u_info.intern = 
        {"Hunonic", "Anh Dung"}, 3, "Bdang", SV_THUCTAP};

    addTail(&list, &sv1, sizeof(SinhVien));
    addTail(&list, &sv2, sizeof(SinhVien));
    addTail(&list, &sv3, sizeof(SinhVien));

    
    printList(&list, printSinhVien);

    freeList(&list);
    */



    Queue q;
    initQueue(&q);

    SinhVien sv5 = {1, "Ha", 8.5, SV_THUONG};
    SinhVien sv6 = {2, "a", 7.9, SV_THUCTAP};
    SinhVien sv7 = {3, "bdang", 9.2, SV_TRAODOI};

    enqueue(&q, &sv5, sizeof(SinhVien));
    enqueue(&q, &sv6, sizeof(SinhVien));
    enqueue(&q, &sv7, sizeof(SinhVien));

    
    printList(&q, printSinhVien);


    SinhVien *svOut = (SinhVien *)dequeue(&q);
    if (svOut != NULL) {
        printSinhVien(svOut);
        free(svOut); 
    }


    printList(&q, printSinhVien);

    freeQueue(&q);


    return 0;




}
