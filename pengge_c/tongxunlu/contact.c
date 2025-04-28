#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

// memset
// void * memset ( void * ptr, int value, size_t num );
//初始化函数 静态版本
//void Initcon(Contact* con) {
//    assert(con);
//    con->count = 0;
//    memset(con->data, 0, sizeof(con->data));
//}

//初始化函数 动态版本
int Initcon(Contact* con) {
    assert(con);
    con->count = 0;
    con->data = (PeoInfo*)calloc(DEFAULT_SZ,sizeof(PeoInfo));
    //con->data 是个指针（PeoInfo* 类型的指针）
    //con->data 指向了一块动态分配的内存区域（数组或者列表）
    //可以通过下标访问每一个 PeoInfo 元素
    //堆内存
    //    ------------------------------------ -
    //    | PeoInfo[0] | PeoInfo[1] | PeoInfo[2] |
    //    ------------------------------------ -
    //    ^ ^^
    //    |            |            |
    //    data[0]      data[1]       data[2]

    //    con->data 指向这里

    if (con->data == NULL) {
        printf("Initcon::%s\n", strerror(errno));
        return 1;
    }
    con->capacity = DEFAULT_SZ;
    return 0;
}

//销毁通讯录
void Destroy_contact(Contact* con) {
    assert(con);
    free(con->data);
    con->data = NULL;
}


////添加联系人函数   静态版本
//void Addcontact(Contact* con) {
//    assert(con);
//    //联系人满了的情况
//    if (con->count == MAX_PEO) {
//        printf("联系人已满\n");
//        return;
//    }
//    //联系人未满
//    //因为数组名name代表了地址,所以不需要& 而年龄就需要了
//    printf("请输入联系人的名字>");
//    scanf("%s", con->data[con->count].name);
//
//    printf("请输入联系人的年龄>");
//    scanf("%d", &(con->data[con->count].age));
//
//    printf("请输入联系人的性别>");
//    scanf("%s", con->data[con->count].sex);
//
//    printf("请输入联系人的电话>");
//    scanf("%s", con->data[con->count].tele);
//
//    printf("请输入联系人的地址>");
//    scanf("%s", con->data[con->count].addr);
//
//    con->count++;
//    printf("增加信息成功\n");
//}

void Check_capacity(Contact* con) {
    if (con->count == con->capacity) {
        PeoInfo* ptr = (PeoInfo*)realloc(con->data, (con->capacity + INC_SZ) * sizeof(PeoInfo));
        if (ptr == NULL) {
            printf("Addcontact::%s\n", strerror(errno));
            return;
        }
        else {
            con->data = ptr;
            con->capacity += INC_SZ;
            printf("增容成功\n");
        }
    }
}

//添加联系人函数   动态版本
void Addcontact(Contact* con) {
    assert(con);
    //联系人满了的情况  增加容量
    Check_capacity(con);

    //联系人未满
    //因为数组名name代表了地址,所以不需要& 而年龄就需要了
    printf("请输入联系人的名字>");
    scanf("%s", con->data[con->count].name);

    printf("请输入联系人的年龄>");
    scanf("%d", &(con->data[con->count].age));

    printf("请输入联系人的性别>");
    scanf("%s", con->data[con->count].sex);

    printf("请输入联系人的电话>");
    scanf("%s", con->data[con->count].tele);

    printf("请输入联系人的地址>");
    scanf("%s", con->data[con->count].addr);

    con->count++;
    printf("增加信息成功\n");
}

//展示联系人信息函数
void Showcontact(const Contact* con) {
    assert(con);
    int i = 0;
    for (i = 0; i < con->count; i++) {
        printf("第%d个联系人\n", i + 1);
        printf("姓名:%s\n", con->data[i].name);
        printf("年龄:%d\n", con->data[i].age);
        printf("性别:%s\n", con->data[i].sex);
        printf("电话:%s\n", con->data[i].tele);
        printf("住址:%s\n", con->data[i].addr);
        printf("\n");
    }

}

//static修饰函数    只能在此文件被看到
static int Find_by_name(const Contact* con, char name[]) {
    assert(con);
    int i = 0;
    for (i = 0; i < con->count; i++) {
        if (strcmp(name, con->data[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

//删除指定联系人
void Delcontact(Contact* con) {
    assert(con);
    char name[MAX_NAME] = { 0 };
    if (con->count == 0) {
        printf("通讯录没有联系人可以删除\n");
        return;
    }
    printf("请输入要删除的联系人的名字\n");
    scanf("%s", name);

    //删除
    //1.查找
    int pos = Find_by_name(con, name);
    if (pos == -1) {
        printf("查找的人不存在\n");
        return;
    }
    //2.删除
    int i = 0;
    for (i = pos; i < con->count - 1; i++) {
        con->data[i] = con->data[i + 1];
    }
    con->count--;
    printf("删除成功\n");
}

//查找联系人
void Searchcontact(const Contact* con) {
    assert(con);
    char name[MAX_NAME] = { 0 };
    printf("请输入要查找的联系人>\n");
    scanf("%s", name);

    //查找
    int pos = Find_by_name(con, name);
    if (pos == -1) {
        printf("要查找的联系人不存在\n");
        return;
    }
    //找到并且打印
    printf("第%d个联系人\n", pos + 1);
    printf("姓名:%s\n", con->data[pos].name);
    printf("年龄:%d\n", con->data[pos].age);
    printf("性别:%s\n", con->data[pos].sex);
    printf("电话:%s\n", con->data[pos].tele);
    printf("住址:%s\n", con->data[pos].addr);
    printf("\n");
    
}


//修改联系人信息
void Modifycontact(Contact* con) {
    assert(con);
    char name[MAX_NAME] = { 0 };
    printf("请输入要修改的联系人>\n");
    scanf("%s", name);

    //查找
    int pos = Find_by_name(con, name);
    if (pos == -1) {
        printf("要查找的联系人不存在\n");
        return;
    }
    //找到了修改
    printf("请输入联系人的名字>");
    scanf("%s", con->data[pos].name);

    printf("请输入联系人的年龄>");
    scanf("%d", &(con->data[pos].age));

    printf("请输入联系人的性别>");
    scanf("%s", con->data[pos].sex);

    printf("请输入联系人的电话>");
    scanf("%s", con->data[pos].tele);

    printf("请输入联系人的地址>");
    scanf("%s", con->data[pos].addr);

    printf("修改信息成功\n");

}


//qsort比较函数
static int int_cmp(const void* e1, const void* e2) {
    return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
//排序联系人的信息
void Sortcontact(Contact* con) {
    assert(con);
    qsort(con->data, con->count, sizeof(PeoInfo), int_cmp);
    printf("排序成功\n");
}

