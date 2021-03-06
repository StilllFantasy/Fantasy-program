# QLU_ACM 浅谈分治思想
## [by StilllFantasy]()

## 分治思想为何物？
> 分治法可以通俗的解释为：把一片领土分解，分解为若干块小部分，然后一块块地占领征服，被分解的可以是不同的政治派别或是其他什么，然后让他们彼此异化。
## 分治法的精髓：
>- 分：将问题分解为规模更小的子问题；
>- 治：将这些规模更小的子问题逐个击破；
>- 合：将已解决的子问题合并，最终得出“母”问题的解；
## 什么意思？
>- 分治就是“分”而“治”之
>- 分支思想一般适用的 方向：
>>- 该问题的规模缩小到一定的程度就可以容易地解决
>>- 该问题可以分解为若干个规模较小的相同问题，即该问题具有最优子结构性质。
>>- 利用该问题分解出的子问题的解可以合并为该问题的解；
>>- 该问题所分解出的各个子问题是相互独立的，即子问题之间不包含公共的子问题。
## 特性解读：
>- 最优子结构是啥？
>- 子问题之间互相独立什么意思？
## 举个栗子：
```cpp
        int a[20] = {6,1,3,2,9,4,8,5,7,0};
        int maxNum1 = max(a[0]~a[5]);
        int maxNum2 = max(a[6]~a[9]);
        int maxNum3 = max(maxNum1,maxNum2);
            maxNum3 = ?
```
## 分治经典方法：
>- 归并排序
>- 快速排序
## 例题：
>- [逆序对](https://www.luogu.org/problemnew/show/P1908)
>- [幂次方](https://www.luogu.org/problemnew/show/P1010)