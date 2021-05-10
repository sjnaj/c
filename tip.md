佛曰:

* 写字楼里写字间，写字间里程序员；

  * 程序人员写程序，又拿程序换酒钱。

    * 酒醒只在网上坐，酒醉还来网下眠；

      * 酒醉酒醒日复日，网上网下年复年。

        * 但愿老死电脑间，不愿鞠躬老板前；

          * 奔驰宝马贵者趣，公交自行程序员。
* 别人笑我忒疯癫，我笑自己命太贱；

  # TIPS

  ### 阶乘容易超出int范围，可以改成double

  ### while有时比for好用


  ```cpp

  *while(s[i])
  {
  if(s[i]>64 && s[i]<91 || s[i]>96 && s[i]<123)
  letter++;
  else if(s[i] == ' ' || s[i] == '\n')         //将这一句改为else if ( s[i] == 32  ||  s[i] == 13 )答案会出错
  blank++;
  else if(s[i]>47 && s[i]<58)
  digit++;
  else
  other++;
  i++;
  }
  {    while(m--)
  {  int temp = a[n - 1];
  for (int i = n - 1; i >= 1; i--)//注意正序会覆盖
  a[i] = a[i - 1];
  a[0] = temp;}*
  ```

  ### 要善用flag

  ```cpp

  {int flag = 0;
  for (int i = 1;fib(i)<=n ; i++) {
  if(fib(i)>=m && fib(i)<=n) {
  if(!flag) printf("%d", fib(i));
  else printf(" %d", fib(i));
  flag = 1;
  }
  }
  { if(!flag) printf("No Fibonacci number\n");
  int rev=0,temp=0,flag=1;
  if(number<0)
  {  number=-number,flag=-1;}
  for(int i=0;number!=0;i++)
  {
  temp=number%10;
  number/=10;
  rev*=10;
  rev+=temp;
  }
  return rev*flag;}
  {    int l=strlen(s),flag=1;
  for(int i=0;i<l/2;i++)
  {
  if(s[i]!=s[l-i-1])
  flag =0;}
  return flag;}*
  ```

  ### 报数：（模拟报数的过程）

  ```cpp

  {   int a[MAXN],i,k=0,count=n,j=0;
  for(i=0;i<n;i++)    //给每个位置赋初值
  {
  a[i]= i;
  }
  for(;count!=0;i++)
  {
  if(a[i%n]!=-1)//-1表示已经退出，
  {
  k++;//报数+1
  if(k==m)//报数满足条件m
  {
  out[i%n]=n-count+1;//给对应的位置告诉他是第几个退出的
  a[i%n]=-1;//用-1赋值，在后面的报数中被屏蔽
  count--;//退出一个
  k=0;//重新报数
  }
  }
  }

  }
  my answer：{
  int a[n];
  for (int i = 0; i < n; i++)
  {
  a[i] = i ;
  }
  for (int k = 0, count; k < n; k++)
  {
  count = m - 1;
  while (count--) //判断后立即--
  {
  int temp = a[0];
  for (int j = 0; j < n - k - 1; j++)
  {
  a[j] = a[j + 1];
  }
  a[n - k - 1] = temp;
  }
  out[a[0]] = k + 1;
  for (int l = 0; l < n - k - 1; l++)
  {
  a[l] = a[l + 1];
  }
  ```

  ### 输出字串时一定记得加'\0'，除非已被（部分）赋值，字串定义后赋值只能（通过循环）单个赋值；gets会将\n丢弃，再加\0（pta中如果没有输入\n则会将最后一个字符变为\0,给测试用例打个换行即可)，fgets不会丢弃\n；

  ### typedef enum {false, true} bool（定义bool枚举变量）

  typedef enum bool {false, true}

  ### 递归简单例子，不要死板的使用return，要注重本质（逐层进入，逐层退出）

  ```cpp

  void dectobin( int n )
  {
  if (n<2)//最内层，最高位
  printf("%d",n);
  else
  {
  dectobin(n/2);
  printf("%d", n%2);//每层的n为相应的商，再由内向外得到相应商的余数；
  }
  }
  ```

  ### ==只能比较字符串指针，一般用strcmp及其衍生函数

  ### 许多函数（strlen,size of)的返回值不能与负数比较

  a和b进行比较的时候，编译器将有符号数a看成了无符号数，然后再和b进行比较，在内存中（32位）

  注意补码；
  a （-1->2^32-1）: 11111111 11111111 11111111 11111111
  b （16）: 00000000 00000000 00000000 00010000

  ### 三角形面积：

  $$
  sqrt(p*(p-l1)*(p-l2)*(p-l3)),p=(l1+l2+l3)/2;

  $$

  ```cpp
  int prime(int n)
  {
  if(n==1)
  return 0;
  for(int i=2;i<=n/2;i++)
  {
  if(n%i==0)
  return 0;
  }
  return 1;
  }
  double pow(int x,int n)
  {
  double sum=1;
  for(int i=1;i<=n;i++)
  sum*=x;
  nikeyireturn sum;
  }
  ```

  ### 如果调用（math）库函数会超时，可以将该函数写出来，例如pow;

  for(i=0;i<m;i++){	//找出数组b在在数组a中不存在的
  for(j=0;j<n;j++)
  if(b[i]==a[j])
  break;
  if (j==n)//关键
  c[num++]=b[i];
  }

  for(i=0;i<num;i++){	//排除相同的数值
  for(j=0;j<i;j++)
  if(c[i]==c[j]) break;
  if(j==i){//关键
  if(f!=0) printf(" ");//末尾不带空格技巧
  printf("%d",c[i]);
  f++;

  ### public static int fib2(int n) {//斐波那契数列非递归算法

  if(n<=1) return n;
  int first = 0;
  int second = 1;
  for (int i = 0; i < n-1; i++) {
  int sum = first + second;
  first = second;
  second = sum;
  }
  return second;
  }

  ### while(n--):--发生在内层代码执行之前，而for的在后边

  #查看可能改变变量的值，例如i--；

  ### 字符串选择排序：

  ##for(int j=0;j<4;j++)
  {
  int index=j,k=j+1;char min[80],temp[80];
  strcpy(min,s[j]);
  for(;k<5;k++)
  {
  if(strcmp(min,s[k])>0)
  {strcpy(min,s[k]);
  index=k;}
  }
  strcpy(temp,s[index]);
  strcpy(s[index],s[j]);
  strcpy(s[j],temp);
  }

  * 不见满街漂亮妹，哪个归得程序员？
  * ### %0d,前面补零
  * ###大数运算

    数据过大就用字符数组存储再转换
    大数阶乘

    int a[10000],carry,digit=0,temp;//存储数组，进位，位数（实际位数减一）
    a[0]=1;
    for(int i=2;i<=N;i++)
    {carry=0;
    for(int j=0;j<=digit;j++)
    {
    temp=a[j]*i+carry;
    a[j]=temp%10;//每一位的数字
    carry=temp/10;//进位，不断累积，暂不分配；
    }
    while(carry)//进位最后解决，使位数增加
    {
    a[++digit]=carry%10;
    carry/=10;
    }
    }
    for(int i=digit;i>=0;i--)
    printf("%d",a[i]);

    ---

    大数加法
  * 数组法
  * ```cpp
    int Addition(char num1[], char num2[], int sum[])
    16 {
    17     int i, j, len;
    18     int n2[MAX] = {0};
    19     int len1 = strlen (num1); // 计算数组num1的长度，即大数的位数 
    20     int len2 = strlen (num2); // 计算数组num2的长度，即大数的位数 
    21 
    22     len = len1>len2 ? len1 : len2; // 获取较大的位数
    23     //将num1字符数组的数字字符转换为整型数字，且逆向保存在整型数组sum中，即低位在前，高位在后
    24     for (i = len1-1, j = 0; i >= 0; i--, j++) 
    25         sum[j] = num1[i] - '0';
    26     // 转换第二个数 
    27     for (i = len2-1, j = 0; i >= 0; i--, j++)
    28         n2[j] = num2[i] - '0';
    29     // 将两个大数相加 
    30     for (i = 0; i <= len; i++)
    31     {
    32         sum[i] += n2[i];  // 两个数从低位开始相加 
    33         if (sum[i] > 9)   // 判断是否有进位 
    34         {   // 进位 
    35             sum[i] -= 10;
    36             sum[i+1]++;
    37         }
    38     }
    39     if(sum[len] != 0)  // 判断最高位是否有进位 
    40         len++;
    41     return len;   // 返回和的位数 
    42 }
    ```

  ```

  ```


  ```

  ```


  ```
  * 链表法

  ```


  ```


  ```


  ```

  ```
*

```cpp
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)

{
    int count1 = 0, count2 = 0, sum = 0, up = 0;
    struct ListNode *head = NULL;
    struct ListNode *prev = NULL;
    while (l1 || l2 || up)//!关键点，当两个链表读取完且没有进位时退出
    {
        if (!l2)
        {
            l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
            l2->next = NULL;
            l2->val = 0;
        }
        if (!l1)
        {
            l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
            l1->next = NULL;
            l1->val = 0;
        }
        sum = l1->val + l2->val + up;
        struct ListNode *cur = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (!head)
            head = cur;
        else
            prev->next = cur;
        cur->val = sum % 10;
        cur->next = NULL;
        prev = cur;
        up = sum / 10;
        sum = 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    return head;
}
```

大数减法

相减算法也是从低位开始减的。先要判断被减数和减数哪一个位数长，若被减数位数长是正常的减法；若减数位数长，则用被减数减去减数，最后还要加上负号；当两数位数长度相等时，最好比较哪一个数字大，否则负号处理会很繁琐；处理每一项时要，如果前一位相减有借位，就先减去上一位的借位，无则不减，再去判断是否能够减开被减数，如果减不开，就要借位后再去减，同时置借位为1，否则置借位为0。

```cpp
for (i = 0; i <= len; i++)
 68     {
 69         sum[i] = sum[i] - n2[i]; // 两个数从低位开始相减 
 70         if (sum[i] < 0)   // 判断是否有借位 
 71         {    // 借位 
 72             sum[i] += 10;//先借或先减都可以
 73             sum[i+1]--;
 74         }
 75     }
```

大数乘法

总结一个规律: 即一个数的第i 位和另一个数的第j 位相乘所得的数，一定是要累加到结果的第i+j 位上。这里i, j 都是从右往左，从0 开始数。
ans[i+j] = a[i]*b[j];

```cpp
 for(i = 0; i < len2; i++)//用第二个数乘以第一个数,每次一位 
30     {
31         for(j = 0; j < len1; j++)
32         {
33             c[i+j] += b[i] * a[j]; //先乘起来,后面统一进位
34         }
35     }
36   
37     for(i=0; i<MAX*2; i++) //循环统一处理进位问题
38     {
39         if(c[i]>=10)
40         {
41             c[i+1]+=c[i]/10;
42             c[i]%=10;
43         }
44     }
45 
46     for(i = MAX*2; c[i]==0 && i>=0; i--); //跳过高位的0
47     len = i+1; // 记录结果的长度 
48     for(; i>=0; i--)
49         sum[i]=c[i];
50     return len; 
51 }
52 
```
