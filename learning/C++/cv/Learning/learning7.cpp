/*
program1 > out.log 2>&1
> out.log：把 stdout (1) 重定向到 out.log。此时，文件只被打开了一次。
2>&1：意思是“把 stderr (2) 重定向到 stdout (1) 当前指向的位置”。
2 -> stderr。
> -> 重定向。
& -> 复制。
1 -> stdout。
*/