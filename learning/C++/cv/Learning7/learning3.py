from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

# 1. 假设这是我们的文档库
docs = [
    "Ubuntu 26.04 安装 GitLab 教程",
    "GitLab 本地部署和内存瘦身",
    "Ubuntu 系统如何清理磁盘空间"
]

# 2. 初始化 TF-IDF 转换器并转换文本
vectorizer = TfidfVectorizer()
tfidf_matrix = vectorizer.fit_transform(docs)

# 3. 用户输入查询词，并用同样的规则向量化
query = ["GitLab 安装"]
query_vector = vectorizer.transform(query)

# 4. 计算余弦相似度（距离函数）
# 这行代码会算出查询词与三篇文章的相似度打分
similarities = cosine_similarity(query_vector, tfidf_matrix)

print(similarities)
# 输出结果类似：[[0.57, 0.28, 0.0]]
# 显然第一个文档（Ubuntu 26.04 安装 GitLab 教程）得分最高，应该被推荐。