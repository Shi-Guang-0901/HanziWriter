//
// Created by 姚康 on 2021/10/14.
//
#include "sstring.h"

int create_string(SString *string, const char *chars, const int offset, const int length)
{
    if (offset + length > strlen(chars))
    {
        return STR_ERROR;
    }
    string->length = length;
    string->values = (char *)malloc(length + 1);
    memset(string->values, 0, length + 1);

    if (string->values == NULL)
    {
        return STR_ERROR;
    }

    for (int i = 0; i < string->length; ++i)
    {
        string->values[i] = chars[i + offset];
    }

    return STR_OK;
}

int create_string(SString *string, const char *chars)
{
    return create_string(string, chars, 0, strlen(chars));
}

int create_string(SString *dest, const SString src)
{
    return create_string(dest, src.values);
}

int delete_string(SString *S, const int pos, const int len)
{
    if (pos < 0 || pos + len > S->length || len < 0)
    {
        return STR_ERROR;
    }
    for (int i = pos; i < S->length - len; i++)
    {
        S->values[i] = S->values[i + len];
    }
    S->length -= len;
    S->values = (char *)realloc(S->values, S->length);
    return STR_OK;
}

int delete_string(SString *S, const char *chars)
{
    SString temp;
    int status = create_string(&temp, chars);
    if (status == STR_ERROR)
    {
        return STR_ERROR;
    }
    status = delete_string(S, temp);
    clear_string(&temp);
    return status;
}

int delete_string(SString *S, const char *chars, const int pos)
{
    SString temp;
    int status = create_string(&temp, chars);
    if (status == STR_ERROR)
    {
        return STR_ERROR;
    }
    status = delete_string(S, temp, pos);
    clear_string(&temp);
    return status;
}

int delete_string(SString *S, const SString T, const int pos)
{
    if (pos > S->length || pos + T.length > S->length)
    {
        return STR_ERROR;
    }

    int ind = index(*S, T, pos);

    return delete_string(S, ind, T.length);
}

int delete_string(SString *S, const SString T)
{
    if (T.length > S->length)
    {
        return STR_ERROR;
    }
    int ind = index(*S, T);
    return delete_string(S, ind, T.length);
}

int delete_string_all(SString *S, const SString T)
{
    if (T.length > S->length)
    {
        return STR_ERROR;
    }
    int ind = 0;
    while ((ind = index(*S, T)) != -1)
    {
        delete_string(S, ind, T.length);
    }
    return STR_OK;
}

int string_empty(const SString S)
{
    return S.length == 0;
}

int compare_string(const SString S, const SString T)
{
    int max = S.length > T.length ? S.length : T.length;
    int min = S.length < T.length ? S.length : T.length;
    for (int i = 0; i < min; i++)
    {
        if (S.values[i] != T.values[i])
        {
            return S.values[i] - T.values[i];
        }
    }
    if (max == min)
    {
        return 0;
    }
    else
    {
        return max - min;
    }
}

int string_length(const SString S)
{
    return S.length;
}

void clear_string(SString *S)
{
    free(S->values);
    S->length = 0;
}

void concat_string(SString *T, const SString S1, const SString S2)
{
    T->length = S1.length + S2.length;
    if (T->values == NULL)
    {
        T->values = (char *)malloc(T->length + 1);
        memset(T->values, 0, T->length + 1);
    }
    else
    {
        T->values = (char *)realloc(T->values, T->length + 1);
        memset(T->values, 0, T->length + 1);
    }

    int index = 0;
    for (int j = 0; j < S1.length; j++, index++)
    {
        T->values[index] = S1.values[j];
    }
    for (int j = 0; j < S2.length; j++, index++)
    {
        T->values[index] = S2.values[j];
    }
}

int sub_string(SString *sub, const SString S, const int pos, const int len)
{
    if ((pos + len > S.length))
    {
        return STR_ERROR;
    }

    sub->length = len;
    sub->values = (char *)malloc(len + 1);
    memset(sub->values, 0, sub->length + 1);

    int index = 0;
    for (int i = pos; i < S.length; i++)
    {
        sub->values[index++] = S.values[i];
    }

    return STR_OK;
}

static int *getNext(SString ps)
{

    char *p = ps.values;
    int *next = (int *)malloc(sizeof(int) * ps.length);
    next[0] = -1;
    int j = 0;
    int k = -1;
    while (j < ps.length - 1)
    {
        if (k == -1 || p[j] == p[k])
        {
            if (p[++j] == p[++k])
            {
                next[j] = next[k];
            }
            else
            {
                next[j] = k;
            }
        }
        else
        {
            k = next[k];
        }
    }
    return next;
}

int index(const SString S, const SString sub)
{
    char *t = S.values;
    char *p = sub.values;
    int i = 0;
    int j = 0;
    int *next = getNext(sub);
    while (i < S.length && j < sub.length)
    {
        if (j == -1 || t[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    free(next);
    if (j == sub.length)
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}

int index(const SString string, const char *chars)
{
    SString temp;
    int status = create_string(&temp, chars);
    if (status == STR_ERROR)
    {
        return STR_ERROR;
    }
    int ind = index(string, temp);
    clear_string(&temp);
    return ind;
}

int index(const SString S, const char *chars, const int pos)
{
    SString temp;
    int status = create_string(&temp, chars);
    if (status == STR_ERROR)
    {
        return STR_ERROR;
    }
    int ind = index(S, temp, pos);
    clear_string(&temp);
    return ind;
}

int index(const SString S, const SString sub, const int pos)
{
    if (pos > S.length || pos + sub.length > S.length)
    {
        return STR_ERROR;
    }
    char *t = S.values;
    char *p = sub.values;
    int i = pos;
    int j = 0;
    int *next = getNext(sub);
    while (i < S.length && j < sub.length)
    {
        if (j == -1 || t[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    free(next);
    if (j == sub.length)
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}

int start(const SString S, const SString sub)
{
    if (sub.length > S.length)
    {
        return 0;
    }

    for (int i = 0; i < sub.length; ++i)
    {
        if (S.values[i] != sub.values[i])
        {
            return 0;
        }
    }
    return 1;
}

int ends(const SString S, const SString sub)
{
    if (sub.length > S.length)
    {
        return 0;
    }
    int len = S.length - sub.length;
    for (int i = 0; i < sub.length; ++i)
    {
        if (sub.values[i] != S.values[i + len])
        {
            return 0;
        }
    }
    return 1;
}

int contains(const SString S, const SString T)
{
    return index(S, T) > 0 ? 1 : 0;
}

int insert_string(SString *S, const int pos, const SString T)
{
    if (pos > S->length)
    {
        return STR_ERROR;
    }
    int src_length = S->length;
    S->values = (char *)realloc(S->values, S->length + T.length);
    S->length = S->length + T.length;
    for (int i = src_length; i >= pos; i--)
    {
        S->values[i + T.length] = S->values[i];
    }

    for (int i = 0; i < T.length; i++)
    {
        S->values[pos + i] = T.values[i];
    }

    return STR_OK;
}

int replace(SString *S, const SString T, const SString V)
{
    int status = 0;
    if (S->length < T.length)
    {
        return STR_ERROR;
    }
    while ((status = index(*S, T, status)) >= 0)
    {
        delete_string(S, T, status);
        insert_string(S, status, V);
        status = status + V.length;
    }
    return STR_OK;
}

void print_string(const SString T)
{
    for (int i = 0; i < T.length; i++)
    {
        printf("%c", T.values[i]);
    }
    printf("\n");
}

int convert(SString *dest, const SString src, const char *from, const char *to)
{
    int ret = 0;
    size_t charInPutLen = src.length;
    if (charInPutLen == 0)
        return -1;
    char *pSource = (char *)src.values;
    size_t charOutPutLen = 2 * charInPutLen;
    size_t afterOutPutLen = charOutPutLen;
    char *pTemp = (char *)malloc(charOutPutLen);
    memset(pTemp, 0, 2 * charInPutLen);

    iconv_t cd;
    pSource = (char *)src.values;
    char *pOut = pTemp;

    // iconv_t iconv_open(const char *tocode, const char *fromcode);
    cd = iconv_open(to, from);
    iconv(cd, NULL, NULL, NULL, NULL);
    ret = iconv(cd, &pSource, &charInPutLen, &pTemp, &afterOutPutLen);
    iconv_close(cd);

    int len = pTemp - pOut;
    create_string(dest, pOut, 0, len);

    free(pOut); //注意这里，不能使用delete []pTemp, iconv函数会改变指针pTemp的值
    return ret;
}
