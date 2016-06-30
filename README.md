# ACM-POJ-1064
二分法搜索解

题意：
给出N条线段，要你将些线段裁剪成K条等长的线段，线段长度以厘米为单位，求最长能裁到多长M。
如果筹不够K条，输出0.00。

思路：
裁剪后的线段最多只能到N条线段的最长那条的长度，假设为max；
如果能裁剪成M长，那么小于M的所有长度都能裁剪出来；
所以，在区间[0,max]上二分搜索就能找到解。
必须要注意输入输出的精度问题。
