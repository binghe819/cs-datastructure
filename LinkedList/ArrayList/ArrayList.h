#ifndef ArrayList_h
#define ArrayList_h

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef int LData; // LData에 대한 typedef 선언

typedef struct __ArrayList
{
    LData arr[LIST_LEN];
    int numOfData;
    int curPosition;
} ArrayList;

typedef ArrayList List;

void ListInit(List *plist); // 초기화
void LInsert(List *plist, LData data); // 데이터 저장

int LFirst(List *plist, LData *pdata); // 첫 데이터 참조
int LNext(List *plist, LData *pdata); // 다음 데이터 참조

LData LRemove(List *plist); // 참조된 데이터 삭제
int LCount(List *plist); // 데이터 개수 반환

#endif
