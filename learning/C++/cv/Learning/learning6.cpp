/*
器大小和下标默认用 size_t。for (size_t i = 0; i < v.size(); ++i) 是课程作业里最稳的写法。
需要表示“可能为负的差值”时，不要用 size_t。用 std::ptrdiff_t（<cstddef> 里的有符号对应类型）或 int/long long，并确认范围。
*/