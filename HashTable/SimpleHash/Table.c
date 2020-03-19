#include "Table.h"

void TBLInit(Table *pt, HashFunc *f)
{
    int i;
    
    // 모든 슬롯 초기화
    for(i = 0; i < MAX_TBL; i++)
        (pt->tml[i]).status = EMPTY;
    
    pt->hf = f; // 해쉬 함수 등록
}

void TBLInsert(Table *pt, Key k, Value v)
{
    int hv = pt->hf(k);
    pt->tml[hv].val = v;
    pt->tml[hv].key = k;
    pt->tml[hv].status = INUSE;
}

Value TBLDelete(Table *pt, Key k)
{
    int hv = pt->hf(k);
    if(pt->tml[hv].status != INUSE)
        return NULL;
    else
    {
        (pt->tml[hv]).status = DELETED; // 주의 : 실제 삭제하진 않고 상태만 바꾼다
        return (pt->tml[hv]).val;
    }
}

Value TBLSearch(Table *pt, Key k)
{
    int hv = pt->hf(k);
    if((pt->tml[hv]).status != INUSE)
        return NULL;
    else
        return (pt->tml[hv]).val;
}

