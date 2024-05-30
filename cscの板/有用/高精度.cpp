#include <cstdio>
#include <cstring>
#include <algorithm>
//#define int long long
using namespace std;

const int power = 1;      //ÿ�������λ��Ϊ10��power�η��������ﶨ��Ϊ�˷������ʵ��
const int base = 10;      //10��power�η���

//Ҫѹλ��ʱ��ֻ���power �� base���ɣ���ѹ��λ�߾�����ôpower = 4, base = 10000

const int MAXL = 100001;    //����ĳ��ȡ�

char a[MAXL], b[MAXL];
struct num
{
    int a[MAXL];
    num() { memset(a, 0, sizeof(a)); }                      //��ʼ��
    num(char *s)                                            //��һ���ַ�����ʼ��Ϊ�߾�����
    {
        memset(a, 0, sizeof(a));
        int len = strlen(s);
        a[0] = (len+power-1) / power;                       //���ĳ���
        for (int i=0, t=0, w; i < len ;w *= 10, ++i)
        {
            if (i % power == 0) { w = 1, ++t; }
            a[t] += w * (s[i]-'0');
        }
        //��ʼ�����飬�����Լ�ģ��һ�£�Ӧ�ú����׶���~
    }
    void add(int k) { if (k || a[0]) a[ ++a[0] ] = k; }     //��ĩβ���һ������������ʱ��Ҫ�õ�
    void re() { reverse(a+1, a+a[0]+1); }                   //������������������ʱ��Ҫ�õ�
    void print()                                            //��ӡ�˸߾�����
    {
        printf("%d", a[ a[0] ]);
        //�ȴ�ӡ���λ��Ϊ��ѹλ ���� �ø߾�����Ϊ0 ����
        for (int i = a[0]-1;i > 0;--i)
        printf("%0*d", power, a[i]);
        //����"%0*d", power����˼�ǣ��������powerλ��������ǰ����0����
        putchar('\n');
    }
} p,q,ans;

bool operator < (const num &p, const num &q)              //�ж�С�ڹ�ϵ��������ʱ������
{
    if (p.a[0] < q.a[0]) return true;
    if (p.a[0] > q.a[0]) return false;
    for (int i = p.a[0];i > 0;--i)
    {
        if (p.a[i] != q.a[i]) return p.a[i] < q.a[i];
    }
    return false;
}

num operator + (const num &p, const num &q)               //�ӷ������ö�˵�˰ɣ�ģ��һ�飬�����׶�
{
    num c;
    c.a[0] = max(p.a[0], q.a[0]);
    for (int i = 1;i <= c.a[0];++i)
    {
        c.a[i] += p.a[i] + q.a[i];
        c.a[i+1] += c.a[i] / base;
        c.a[i] %= base;
    }
    if (c.a[ c.a[0]+1 ]) ++c.a[0];
    return c;
}

num operator - (const num &p, const num &q)               //������Ҳ���ö�˵��ģ��һ�飬�����׶�
{
    num c = p;
    for (int i = 1;i <= c.a[0];++i)
    {
        c.a[i] -= q.a[i];
        if (c.a[i] < 0) { c.a[i] += base; --c.a[i+1]; }
    }
    while (c.a[0] > 0 && !c.a[ c.a[0] ]) --c.a[0];
    //�ҵ�ϰ�����������Ϊ0����ô���ĳ���Ҳ��0������Ƚϴ�С����ĩβ�����ʱ���жϡ�
    return c;
}

num operator * (const num &p, const num &q)
//�˷�������ģ��һ�顣����ʵ�߾��Ⱦ���ģ���˹��������㣡
{
    num c;
    c.a[0] = p.a[0]+q.a[0]-1;
    for (int i = 1;i <= p.a[0];++i)
    for (int j = 1;j <= q.a[0];++j)
    {
        c.a[i+j-1] += p.a[i]*q.a[j];
        c.a[i+j] += c.a[i+j-1] / base;
        c.a[i+j-1] %= base;
    }
    if (c.a[ c.a[0]+1 ]) ++c.a[0];
    return c;
}

num operator / (const num &p, const num &q)               //��������������΢����һ��
{
    num x, y;
    for (int i = p.a[0];i >= 1;--i)                       //�����λ��ʼȡ��
    {
        y.add(p.a[i]);             //������ĩβ�����λ������ʱ���Ǹ�λ��ǰ����λ�ں�
        y.re();                    //��������������Ϊͳһ�Ĵ洢��ʽ����λ��ǰ����λ�ں�
        while ( !(y < q) )         //���ڵ��ڳ�����ʱ�����С�ڵĻ�����ʵ���ϵĸ�Ϊ���ǳ�ʼ�ġ�0��
            y = y - q, ++x.a[i];   //���ܼ����������������Σ����ϸ�Ϊ�ͼӼ��Ρ�
        y.re();                    //������������Ϊ��һ��������׼��
    }
    x.a[0] = p.a[0];
    while (x.a[0] > 0 && !x.a[x.a[0]]) --x.a[0];
    return x;
}

signed main()
{
    scanf("%s", a);
    scanf("%s", b);
    reverse(a, a+strlen(a));
    reverse(b, b+strlen(b));

    p = num(a), q = num(b);

    ans = p + q;
    printf("�ӷ������");
    ans.print();

    ans = p - q;
    printf("\n���������");
    ans.print();

    ans = p * q;
    printf("\n�˷������");
    ans.print();

    ans = p / q;
    printf("\n���������");
    ans.print();
}
